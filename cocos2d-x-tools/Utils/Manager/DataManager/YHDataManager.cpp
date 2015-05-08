//
//  YHDataManager.cpp
//  MonsterHunter
//
//  Created by Zhenyu Yao on 14-1-9.
//
//

#include "YHDataManager.h"
#include "YHDataManagerImp.h"
#include "YHSchedulerDataManagerImp.h"
#include "YHAsynDataManagerImp.h"

USING_NS_CC;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////
// Public Functions
////////////////////////////////////////////////////////////////////////////////////////////////////

const std::string YHDataManager::DEFAULT = "Default";
const std::string YHDataManager::ASYN = "Asyn";

YHDataManager * YHDataManager::create(const std::string & type)
{
	YHDataManagerImp * imp = NULL;
	if (type.compare(DEFAULT) == 0)
		imp = new YHSchedulerDataManagerImp();
    else if (type.compare(ASYN) == 0)
        imp = new YHAsynDataManagerImp();
    
    imp->init();
	imp->autorelease();

	YHDataManager * manager = new YHDataManager();
	manager->init(imp);
	manager->autorelease();
    imp->m_parent = manager;
	
	return manager;
}

YHDataManager::YHDataManager() : m_imp(NULL)
{
}

YHDataManager::~YHDataManager()
{
	CC_SAFE_RELEASE_NULL(m_imp);
}

bool YHDataManager::init(YHDataManagerImp * imp)
{
	m_imp = imp;
	CC_SAFE_RETAIN(m_imp);
	return true;
}

void YHDataManager::addFile(const std::string & file)
{
	m_imp->addFile(file);
}

void YHDataManager::addObject(const std::string & file, cocos2d::Ref * ref)
{
    m_imp->addObject(file, ref);
}

void YHDataManager::removeFile(const std::string & file)
{
	m_imp->removeFile(file);
}

void YHDataManager::removeAllFiles()
{
	m_imp->removeAllFiles();
}

void YHDataManager::purgeImages()
{
    m_imp->purgeImages();
}

void YHDataManager::start()
{
	m_imp->start();
}

void YHDataManager::stop()
{
	m_imp->stop();
}

bool YHDataManager::completed()
{
	return m_imp->completed();
}

YHByteArray * YHDataManager::bytesForFile(const std::string & file)
{
	return m_imp->dataForFile(file);
}

CCTexture2D * YHDataManager::textureForFile(const std::string & file)
{
	return m_imp->textureForFile(file);
}

CCDictionary * YHDataManager::dictionaryForFile(const std::string & file)
{
	return m_imp->dictionaryForFile(file);
}

CCArray * YHDataManager::arrayForFile(const std::string & file)
{
	return m_imp->arrayForFile(file);
}

const std::string & YHDataManager::stringForFile(const std::string & file)
{
    return m_imp->stringForFile(file);
}

const char * YHDataManager::charsForFile(const std::string & file)
{
    return m_imp->charsForFile(file);
}

std::vector<std::string> YHDataManager::allFiles()
{
    return m_imp->allFiles();
}

void YHDataManager::setFinishedCallback(const std::function<void ()> & callback)
{
    m_imp->setFinishedCallback(callback);
}

void YHDataManager::setHandler(int handler)
{
    m_imp->setHandler(handler);
}

void YHDataManager::helpLoadSpriteFrames(YHDataManager * manager)
{
    // 装载 CCSpriteFrame 资源
    CCSpriteFrameCache * cache = CCSpriteFrameCache::getInstance();
    for (std::string png : manager->allFiles())
    {
        size_t pos = png.find(".png");
        if (pos != string::npos)
        {
            std::string plist = png.substr(0, pos);
            plist.append(".plist");
            if (FileUtils::getInstance()->isFileExist(plist))
                cache->addSpriteFramesWithFile(plist);
        }
    }
}

void YHDataManager::update(float dt)
{
    m_imp->update(dt);
}


































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


