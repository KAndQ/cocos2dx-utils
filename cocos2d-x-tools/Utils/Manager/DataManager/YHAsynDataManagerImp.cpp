//
//  YHAsynDataManagerImp.cpp
//  MonsterHunter
//
//  Created by Zhenyu Yao on 14-2-14.
//
//

#include "YHAsynDataManagerImp.h"
#include "Utils/Buffer/YHByteArray.h"
#include "YHDataManager.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "platform/android/jni/JniHelper.h"
#include <jni.h>
#endif

#if CC_ENABLE_SCRIPT_BINDING
#include "CCLuaEngine.h"
#include "tolua_fix.h"
#endif // CC_ENABLE_SCRIPT_BINDING

USING_NS_CC;

void YHAsynDataManagerImp::addFile(const std::string & file)
{
    m_mutex.lock();
    
    CCObject * obj = NULL;
    bool exist = false;
    CCARRAY_FOREACH(m_waitingFiles, obj)
    {
        CCString * str = (CCString *)obj;
        if (strcmp(str->getCString(), file.c_str()) == 0)
        {
            exist = true;
            break;
        }
    }
    
    if (getDict()->objectForKey(file) != NULL)
        exist = true;
    
    if (!exist)
        m_waitingFiles->addObject(CCString::create(file));
    
    m_mutex.unlock();
}

void YHAsynDataManagerImp::addObject(const std::string & file, cocos2d::Ref * ref)
{
    m_mutex.lock();
    
    getDict()->setObject(ref, file);
    
    for (auto s : m_finishedFiles)
    {
        if (s == file)
            return;
    }
    m_finishedFiles.push_back(file);
    
    m_mutex.unlock();
}

void YHAsynDataManagerImp::removeFile(const std::string & file)
{
    m_mutex.lock();
    
    CCObject * obj = NULL;
    bool exist = false;
    CCARRAY_FOREACH(m_waitingFiles, obj)
    {
        CCString * str = (CCString *)obj;
        if (strcmp(str->getCString(), file.c_str()) == 0)
        {
            exist = true;
            break;
        }
    }
    
    if (exist)
    {
        m_waitingFiles->removeObject(obj);
        getDict()->removeObjectForKey(file);
    }
    
    m_mutex.unlock();
}

void YHAsynDataManagerImp::removeAllFiles()
{
    m_mutex.lock();
    
    m_waitingFiles->removeAllObjects();
    getDict()->removeAllObjects();
    
    m_mutex.unlock();
}

void YHAsynDataManagerImp::start()
{
    assert(!m_threadRunning);
    if (!m_threadRunning && m_waitingFiles->count() != 0)
    {
        m_threadRunning = true;
        std::thread t([this]{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
            JavaVM *vm;
            JNIEnv *env;
            vm = JniHelper::getJavaVM();
            
            JavaVMAttachArgs thread_args;
            
            thread_args.name = "YHAsynDataManagerImp";
            thread_args.version = JNI_VERSION_1_4;
            thread_args.group = NULL;
            
            vm->AttachCurrentThread(&env, &thread_args);
#endif
            
            while (this->m_waitingFiles->count() != 0 && this->m_threadRunning)
            {
                this->m_mutex.lock();
                
                std::string file, fullpath;
                if (this->m_waitingFiles->count() != 0)
                {
                    file = ((CCString *)this->m_waitingFiles->objectAtIndex(0))->getCString();
                    fullpath = CCFileUtils::sharedFileUtils()->fullPathForFilename(file.c_str());
                    
                    if (file.compare(fullpath) == 0 || fullpath.empty())
                        this->m_waitingFiles->removeObjectAtIndex(0);
                }
                this->m_mutex.unlock();
                
                if (fullpath.compare(file) == 0 || fullpath.length() == 0 || file.length() == 0)
                    continue;
                
                CCObject * obj = this->loadFile(fullpath);
                if (obj != NULL)
                {
                    this->m_mutex.lock();
                    this->getDict()->setObject(obj, file);
                    this->m_finishedFiles.push_back(file);
                    this->m_waitingFiles->removeObjectAtIndex(0);
                    
                    if (dynamic_cast<YHByteArray *>(obj) != nullptr)
                    {
                        YHByteArray * ba = (YHByteArray *)obj;
                        m_strCache[file] = std::string((char *)ba->getBuffer());
                    }
                    
                    this->m_mutex.unlock();
                    obj->release();
                }
            }
            
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
            vm->DetachCurrentThread();
#endif
            
            this->m_threadRunning = false;
        });
        t.detach();
        
        CCDirector::sharedDirector()->getScheduler()->scheduleUpdateForTarget(this, DataManagerPriority, false);
    }
}

void YHAsynDataManagerImp::stop()
{
    while (m_threadRunning);
    CCDirector::sharedDirector()->getScheduler()->unscheduleUpdateForTarget(this);
}

bool YHAsynDataManagerImp::completed()
{
    m_mutex.lock();
    bool c = m_waitingFiles->count() == 0 && !m_threadRunning;
    m_mutex.unlock();
    
    return c;
}

YHByteArray * YHAsynDataManagerImp::dataForFile(const std::string & file)
{
    m_mutex.lock();
    YHByteArray * bytes = dynamic_cast<YHByteArray *>(getDict()->objectForKey(file));
    m_mutex.unlock();
    
    return bytes;
}

CCTexture2D * YHAsynDataManagerImp::textureForFile(const std::string & file)
{
    m_mutex.lock();
    CCTexture2D * tex = dynamic_cast<CCTexture2D *>(getDict()->objectForKey(file));
    m_mutex.unlock();
 
    return tex;
}

CCDictionary * YHAsynDataManagerImp::dictionaryForFile(const std::string & file)
{
    m_mutex.lock();
    CCDictionary * dict = dynamic_cast<CCDictionary *>(getDict()->objectForKey(file));
    m_mutex.unlock();
    
    return dict;
}

CCArray * YHAsynDataManagerImp::arrayForFile(const std::string & file)
{
    m_mutex.lock();
    CCArray * arr = dynamic_cast<CCArray *>(getDict()->objectForKey(file));
    m_mutex.unlock();
    
    return arr;
}

const std::string & YHAsynDataManagerImp::stringForFile(const std::string & file)
{
    m_mutex.lock();
    const std::string & ret = m_strCache[file];
    m_mutex.unlock();
    return ret;
}

const char * YHAsynDataManagerImp::charsForFile(const std::string & file)
{
    m_mutex.lock();
    const std::string & ret = m_strCache[file];
    m_mutex.unlock();
    return ret.c_str();
}

std::vector<std::string> YHAsynDataManagerImp::allFiles()
{
    m_mutex.lock();
    std::vector<std::string> ret = m_finishedFiles;
    m_mutex.unlock();
    
    return ret;
}

void YHAsynDataManagerImp::update(float dt)
{
    if (m_waitingFiles->count() == 0 && !m_threadRunning)
    {
        // Image -> CCTexture2D
        for (auto f : m_finishedFiles)
        {
            Image * img = dynamic_cast<Image *>(getDict()->objectForKey(f));
            if (img != nullptr)
            {
                std::string fullpath = CCFileUtils::getInstance()->fullPathForFilename(f);
                CCTexture2D * tex = CCTextureCache::getInstance()->addImage(img, fullpath);
                getDict()->setObject(tex, f);
            }
        }
        
        if (m_callback != nullptr)
            m_callback();
        
#if CC_ENABLE_SCRIPT_BINDING
        if (m_handler != 0)
        {
            LuaStack * stack = LuaEngine::getInstance()->getLuaStack();
            stack->pushLuaValue(LuaValue::ccobjectValue(this->m_parent, "YHDataManager"));
            stack->executeFunctionByHandler(m_handler, 1);
            stack->clean();
        }
#endif
        
        CCLOG("%s", TextureCache::getInstance()->getCachedTextureInfo().c_str());
        
        CCDirector::sharedDirector()->getScheduler()->unscheduleUpdateForTarget(this);
    }
}













































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


