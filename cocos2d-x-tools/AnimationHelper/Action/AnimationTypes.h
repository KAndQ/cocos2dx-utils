//
//  AnimationTypes.h
//  cocos2d-x-Utils
//
//  Created by mac on 13-7-15.
//
//

#ifndef __cocos2d_x_Utils__AnimationTypes__
#define __cocos2d_x_Utils__AnimationTypes__

#include "YHTypes.h"

USING_NS_CC;

class CCSpecialSprite;

/// 如果是是文件, 删除文件的后缀和之前的路径, 只返回文件名
extern std::string convertKeyFromFile(const std::string& file);

/**
 *  动画的初始化定义数据
 *  @author wangtiwei
 */
class AnimatorInitData : public YHObject
{
public:
	CCPoint				m_anchorPoint;
	CCPoint				m_position;
    CCPoint				m_scale;
    float				m_rotation = 0.0f;
    unsigned char		m_opacity = 255;
    int                 m_zOrder = 0;
    float               m_posScale = 1.0;
	
protected:

    /// 初始化
	void init(CCDictionary* dataDict);
	
public:
	
    /// 创建 AnimatorInitData 对象
	static AnimatorInitData* data(CCDictionary* dataDict);
	
	/// 初始化 CCNode 对象
	void initializeNode(CCNodeRGBA * node);
    
    /// 设置位置缩放的大小
    void setPosScale(float posScale);
    
    /**
     * 从 node 的当前参数补间到定义的数据位置
     * @param node 待补间的node
     * @param duration 补间时间
     */
    void tweenToNow(CCNodeRGBA * node, float32 duration = 0.03f);
};

// 动画种类
#define ANIMATION_TYPE_ANCHORPOINT		"AnchorPoint"
#define ANIMATION_TYPE_POSITION			"Position"
#define ANIMATION_TYPE_SCALE			"Scale"
#define ANIMATION_TYPE_ROTATION			"Rotation"
#define ANIMATION_TYPE_OPACITY			"Opacity"

/**
 *  动画的动画数据
 *  @author wangtiwei
 */
class AnimatorAnimData : public YHObject
{
private:
    CCDictionary*		m_dataDict = NULL;
    float               m_posScale = 1.0f;
	
protected:
	
    /// 初始化
	void init(CCDictionary* dataDict);
	
	void runAction(CCNodeRGBA* node, const std::string& type, int32 tag = 0);
	
public:
	~AnimatorAnimData();
	
	/// 创建 AnimatorAnimData 对象
	static AnimatorAnimData* data(CCDictionary* dataDict);
	
    /// 动画一次循环的总时间
    float32 getSumTime() const { return m_dataDict->valueForKey("SumTime")->floatValue(); }
    
    /// 获得偏移时间
    float32 getOffsetTime() const;
    
    /// 是否是循环播放
    bool isForever() const { return m_dataDict->valueForKey("Forever")->boolValue(); }
    
	/**
	 * 指定动画种类创建 CCAction 对象
	 * @param type 动画的种类
	 * @return CCAction 对象, 如果该种类没有动画, 返回nil
	 */
	CCAction* action(const std::string& type);
    
    /**
     * 获得对应的 DelayTime Action
     */
    CCDelayTime * getDelayTimeAction();
	
	// 让指定的节点运行动画
    void runActions(CCNodeRGBA* node, const std::vector<int32> & tags = {200, 201, 202, 203, 204});
    
    /// 设置位置缩放的大小
    void setPosScale(float posScale)
    {
        m_posScale = posScale;
    }
};

#define ANIMATION_DataType_InitData		"InitData"
#define ANIMATION_DataType_AnimData		"AnimData"

/**
 *  强引用 AnimatorInitData 和 AnimatorAnimData 对象
 *  @author wangtiwei
 */
class AnimatorData : public YHObject
{
public:
	AnimatorInitData* 		m_initData;
	AnimatorAnimData*		m_animData;
	
protected:
	//	使用 AnimatorInitData 和 AnimatorAnimData 对象初始化
	void init(AnimatorInitData* initData, AnimatorAnimData* animData);
	
	//	使用 CCDictionary 对象初始化
	void init(CCDictionary*	dataDict);
	
public:
    
	~AnimatorData();
	
	//	创建 AnimatorData 对象
	static AnimatorData* data(AnimatorInitData* initData, AnimatorAnimData* animData);
	
	//	创建 AnimatorData 对象
	static AnimatorData* data(CCDictionary* dataDict);
	
	//	得到AnimatorInitData 对象指针
	AnimatorInitData*	getInitData(){return m_initData;}
	
	//	得到AnimatorAnimData 对象指针
	AnimatorAnimData*	getAnimData(){return m_animData;}
	
    /// 设置位置缩放的大小
    void setPosScale(float posScale)
    {
        getInitData()->setPosScale(posScale);
        getAnimData()->setPosScale(posScale);
    }
};

/**
 *  动画的 Module 定义数据
 *  @author wangtiwei
 */
class AnimatorModuleData : public YHObject
{
public:
	CCPoint			m_anchorPoint;
	CCSize			m_contentSize;
	
protected:
	//	初始化
	void init(CCDictionary*	moduleDict);
	
public:
	//	创建 AnimatorModuleData 对象
	static AnimatorModuleData* data(CCDictionary* moduleDict);
	
	//	创建 SpecialSprite 对象
	CCSpecialSprite* createSpecialSprite();
    
    /// 赋值给 CCNode 对象
    void assignToNode(CCNode * node);
};

/**
 *  动画的配置文件对象
 *  @author wangtiwei
 */
class AnimatorSettingData : public YHObject
{
public:
	std::string			m_animatorFile;
	std::string			m_animatorDataFile;
	
protected:
	//	初始化
	void init(CCDictionary* settingDict);
	
public:
	//	创建 AnimatorSettingData 对象
	static AnimatorSettingData* data(CCDictionary* settingDict);
};

/**
 *  缓存 AnimatorData 对象的类
 *  @author wangtiwei
 */
class AnimatorDataCache : public YHObject
{
private:
	CCDictionary*		m_dict;
	
public:
	AnimatorDataCache();
	
	//	获得 AnimatorDataCache 实例
	static AnimatorDataCache* sharedCache();
	
	//	从缓存中获得 AnimatorData对象
	AnimatorData* getData(const std::string& key);
	
	//	添加 AnimatorData 对象到缓存中
	void addData(AnimatorData* data, const std::string& key);
	
	void retain();
	void release();
	CCObject* autorelease();
	
	//	清空缓存
	void clean();
};

/**
 *  存储动画 Module 定义数据的缓存类
 *  @author wangtiwei
 */
class AnimatorModuleDataCache : public YHObject
{
private:
	CCDictionary*		m_dict;
	
public:
	AnimatorModuleDataCache();
	
	//	获得 AnimatorModuleDataCache 实例
	static AnimatorModuleDataCache* sharedCache();
	
	//	从缓存中获得 AnimatorModuleData对象
	AnimatorModuleData* getData(const std::string& key);
	
	//	添加 AnimatorModuleData 对象到缓存中
	void addData(AnimatorModuleData* data, const std::string& key);
	
	//	清空缓存
	void clean();
	
	void retain();
	void release();
	CCObject* autorelease();
	
};

/**
 *  配置文件缓存类
 *  @author wangtiwei
 */
class AnimatorSettingDataCache : public YHObject
{
private:
	CCDictionary*		m_dict;
	
public:
	AnimatorSettingDataCache();
	
	//	获得 AnimatorSettingDataCache 实例
	static AnimatorSettingDataCache* sharedCache();
	
	//	从缓存中获得 AnimatorSettingData对象
	AnimatorSettingData* getData(const std::string& key);
	
	//	添加 AnimatorSettingData 对象到缓存中
	void addData(AnimatorSettingData* data, const std::string& key);
	
	//	清空缓存
	void clean();
	
	void retain();
	void release();
	CCObject* autorelease();
};
#endif /* defined(__cocos2d_x_Utils__AnimationTypes__) */
