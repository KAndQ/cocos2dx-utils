//
//  YHAnimationKeyEvents.h
//  Demo
//
//  Created by Zhenyu Yao on 14-1-2.
//
//

#ifndef __Demo__YHAnimationKeyEvents__
#define __Demo__YHAnimationKeyEvents__

#include "YHTypes.h"

/**
 * YHAnimationKeyEvents 当触发动画关键事件时, 会触发
 * @author Zhenyu Yao
 */
class YHAnimationKeyEventsDelegate
{
public:
	
	/**
	 * 处理动画的关键事件, 对应使用 init(cocos2d::CCAnimation * animation, bool loop = false) 执行的回调
	 * @param node 运行动画的显示对象
	 * @param frame 当前显示的 CCAnimationFrame 对象
	 */
	virtual void handleKeyEvent(cocos2d::CCNode * node, cocos2d::CCAnimationFrame * frame) = 0;
    
    /**
     * 处理动画的关键事件, 对应使用 init(cocos2d::CCDictionary * dataDict) 执行的回调
     * @param node 运行动画的显示对象
     * @param userInfo 一些携带数据
     */
    virtual void handleKeyEvent(cocos2d::CCNode * node, cocos2d::CCDictionary * userInfo) = 0;
};

class YHAnimationKeyEvents;

/**
 * 一个 YHAnimationKeyEvents 内部引用的类
 * @author Zhenyu Yao
 */
class YHAnimationKeyEventsInternalObject : public YHObject
{
public:
	
	YHAnimationKeyEventsInternalObject();
	virtual ~YHAnimationKeyEventsInternalObject();
	
	CC_SYNTHESIZE(YHAnimationKeyEvents *, m_keyEvents, KeyEvents);
	
private:
	
	/// CCCallFunO 的回调函数
	void onCallFuncOHandle(cocos2d::CCObject * object);
	
	friend class YHAnimationKeyEvents;
};

/**
 * 动画的关键事件
 * @author Zhenyu Yao
 */
class YHAnimationKeyEvents : public YHObject
{
public:
	
	YHAnimationKeyEvents();
	virtual ~YHAnimationKeyEvents();
	
	/**
	 * 初始化
	 * @param animation 需要运行的动画
	 * @param loop 是否循环播放动画
	 * @return 成功返回 true, 否则返回 false
	 */
	virtual bool init(cocos2d::CCAnimation * animation, float32 offset = 0.0f, bool loop = false);
    
    /**
     * 初始化
     * @param dataDict 数据定义的字典对象
     * @return 成功返回 true, 否则返回 false
     * @code dataDict 数据格式
     * <Sum/>                       <!-- 总时间 -->
     * <Loops/>                     <!-- 循环次数, 0 表示无限循环, 1 表示播放一次, 后面以此类推 -->
     * <Steps/>                     <!-- 各个时段的定义 -->
     *      <Delay/>                <!-- 延时, 每个子步骤的延时是相对的 -->
     *      <UserInfo/>             <!-- 一些数据定义 -->
     */
    virtual bool init(cocos2d::CCDictionary * dataDict, float32 offset = 0.0f);
	
	/**
	 * 创建 YHAnimationKeyEvents 对象
	 * @param animation 需要运行的动画
	 * @param loop 是否循环播放动画
	 * @return 成功返回 YHAnimationKeyEvents 对象, 否则返回 NULL
	 */
	static YHAnimationKeyEvents * create(cocos2d::CCAnimation * animation, float32 offset = 0.0f, bool loop = false)
	{
		YHAnimationKeyEvents * instance = new YHAnimationKeyEvents();
		if (instance != NULL && instance->init(animation, offset, loop))
		{
			instance->autorelease();
			return instance;
		}
		
		CC_SAFE_DELETE(instance);
		return NULL;
	}
    
    /**
     * 创建 YHAnimationKeyEvents 对象
     * @param dataDict 数据定义的字典对象
     * @return 成功返回 YHAnimationKeyEvents 对象, 否则返回 NULL
     */
    static YHAnimationKeyEvents * create(cocos2d::CCDictionary * dataDict, float32 offset = 0.0f)
    {
        YHAnimationKeyEvents * instance = new YHAnimationKeyEvents();
        if (instance != NULL && instance->init(dataDict, offset))
        {
            instance->autorelease();
            return instance;
        }
        
        CC_SAFE_DELETE(instance);
        return NULL;
    }
	
	/// 委托
	CC_SYNTHESIZE(YHAnimationKeyEventsDelegate *, m_delegate, Delegate);
	
	/// 关联的 CCSprite 对象
	CC_SYNTHESIZE(cocos2d::CCNode *, m_node, Node);
    
#if CC_ENABLE_SCRIPT_BINDING
    /// lua 注册函数的句柄保留
    CC_SYNTHESIZE(int, m_handler, Handler);
#endif
	
	/// 关键事件 Action
	cocos2d::CCAction * getAction()
	{
		return m_action;
	}
	
private:
	
	/// CCCallFunO 的回调函数
	void onCallFuncOHandle(cocos2d::CCObject * object);
	
private:
	
	cocos2d::CCAction * m_action;
	YHAnimationKeyEventsInternalObject * m_internalObject;
	
	friend class YHAnimationKeyEventsInternalObject;
};

typedef class YHAnimationKeyEvents YHKeyTimeCallback;
typedef class YHAnimationKeyEventsDelegate YHKeyTimeCallbackDelegate;

#endif /* defined(__Demo__YHAnimationKeyEvents__) */














































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


