//
//  YHDataManagerImp.h
//  MonsterHunter
//
//  Created by Zhenyu Yao on 14-1-10.
//
//

#ifndef __MonsterHunter__YHDataManagerImp__
#define __MonsterHunter__YHDataManagerImp__

#include "YHTypes.h"
#include "Utils/Common/YHAbstractDataSetting.h"

class YHByteArray;
class YHDataManager;

/// 优先级
#define DataManagerPriority     0

/**
 * YHDataManager 的实现基类
 * @author Zhenyu Yao
 */
class YHDataManagerImp : public YHAbstractDataSetting
{
public:
	
	YHDataManagerImp();
	virtual ~YHDataManagerImp();
	
	virtual bool init();
	
	virtual void addFile(const std::string & file) = 0;
    virtual void addObject(const std::string & file, cocos2d::Ref * ref) = 0;
	virtual void removeFile(const std::string & file) = 0;
	virtual void removeAllFiles() = 0;
    virtual void purgeImages();
	virtual void start() = 0;
	virtual void stop() = 0;
	virtual bool completed() = 0;
	virtual YHByteArray * dataForFile(const std::string & file) = 0;
	virtual cocos2d::CCTexture2D * textureForFile(const std::string & file) = 0;
	virtual cocos2d::CCDictionary * dictionaryForFile(const std::string & file) = 0;
	virtual cocos2d::CCArray * arrayForFile(const std::string & file) = 0;
    virtual const std::string & stringForFile(const std::string & file) = 0;
    virtual const char * charsForFile(const std::string & file) = 0;
    virtual std::vector<std::string> allFiles() = 0;
    virtual void setFinishedCallback(const std::function<void ()> & callback);
    virtual void update(float dt) = 0;
    
#if CC_ENABLE_SCRIPT_BINDING
    virtual void setHandler(int handler) { m_handler = handler; }
    
protected:
    int m_handler = 0;
#endif
    
protected:
	
    /// 装载文件, 返回装载文件生成的对象, 在使用完返回对象后, 必须手动调用 release
    virtual cocos2d::CCObject * loadFile(const std::string & fullpath);
    
	cocos2d::CCArray * m_waitingFiles = nullptr;
    std::vector<std::string> m_finishedFiles;
    std::function<void ()> m_callback = nullptr;
    std::map<const std::string, std::string> m_strCache;
    YHDataManager * m_parent = nullptr;
    
    friend class YHDataManager;
};

#endif /* defined(__MonsterHunter__YHDataManagerImp__) */














































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


