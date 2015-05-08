//
//  YHAnimationHelper.h
//  AndroidaBooM
//
//  Created by Zhenyu Yao on 13-4-27.
//
//

#ifndef __AndroidaBooM__YHAnimationHelper__
#define __AndroidaBooM__YHAnimationHelper__

#include "YHTypes.h"
#include "YHAnimationKeyEvents.h"

using namespace std;
using namespace cocos2d;

class AnimatorData;
class AnimatorInitData;
class AnimatorAnimData;

/**
 * 动画定义器中的帧特别数据定义器
 * @code -------- NSDictionary 格式说明 --------
 * <Frames/>						<!-- 每帧的详细设置, 可以省略, 省略后, 都以缺省值配置每一帧数据 -->
 *		<Index/>					<!-- 设置帧的索引, 从 0 开始计数, 不能超过 Range 的范围 -->
 *		<DelayUnits/>				<!-- 设置帧的单位延迟, 每一帧的延迟 = Delay * DelayUnits, 默认值 1.0 -->
 *		<UserInfo/>					<!-- 设置帧保存的其他信息 -->
 */
class YHAnimationFrameDefiner : public YHObject
{
public:
    
    /// 创建 YHAnimationFrameDefiner 对象
    static YHAnimationFrameDefiner * create(CCDictionary * dict)
    {
        YHAnimationFrameDefiner * instance = new YHAnimationFrameDefiner(dict);
        if (instance != nullptr)
            instance->autorelease();
        return instance;
    }
    
	YHAnimationFrameDefiner(CCDictionary * dict);
	~YHAnimationFrameDefiner();
    
	/// 获得索引
	uint32					getIndex() const  { return m_index; }

	/// 单位延迟时间
	float					getDelayUnit() const { return m_delayUnit; }

	/// 其他信息
	const ValueMap &        getUserInfo() const { return m_userInfo; }

private:
	uint32					m_index;
	float					m_delayUnit;
	ValueMap				m_userInfo;
	
	friend class YHAnimationDefiner;
};

/**
 * 动画定义器, 保存从 CCDictionary 中解析出的数据
 * @author Zhenyu Yao
 */
class YHAnimationDefiner : public YHObject
{
public:
    
    /// 创建 YHAnimationDefiner 对象
    static YHAnimationDefiner * create()
    {
        YHAnimationDefiner * instance = new YHAnimationDefiner();
        if (instance != nullptr)
            instance->autorelease();
        return instance;
    }
    
	YHAnimationDefiner() : m_delay(0), m_loop(1), m_restoreOriginFrame(false) {};
	~YHAnimationDefiner() {};
    
	/** 
	 * 方式 1 解析
     * @code -------- NSDictionary 格式说明 --------
	 * <Delay/>							<!-- 每帧的之间的间隔时间 -->
	 * <Resources/>						<!-- 资源数组 -->
	 */
	void											parse_ver1(CCDictionary * dict);

	/** 
	 * 方式 2 解析
	 * @code -------- NSDictionary 格式说明 --------
	 * <FileName/>						<!-- 动画的文件名 -->
	 * <Range/>							<!-- 动画帧的范围 [min, max] -->
	 * <Extension/>						<!-- 文件的后缀名, 不要加 . -->
	 * <Delay/>							<!-- 每帧的延迟时间, 单位秒 -->
	 * <Loop/>							<!-- 动画循环的次数, 0 则表示不播放动画 -->
	 * <RestoreOriginFrame/>			<!-- 当动画播放结束后是否显示动画播放前的图像, 默认值 NO, 即不显示之前的图像 -->
	 * <Frames/>						<!-- 每帧的特别定义 -->
     * <Reverse/>                       <!-- true 表示反转序列帧，序列帧的播放顺序是［max, min]；false 表示正序播放序列帧，[min, max] -->
	 */
	void											parse_ver2(CCDictionary * dict);

	/// 每帧之间的延迟
	float											getDelay() const { return m_delay; }

	/// 循环次数
	uint32											getLoop() const { return m_loop; }

	/// 播放完动画之后是否显示原始帧
	bool											getRestoreOriginFrame() const { return m_restoreOriginFrame; }

	/// 所有的资源
	const vector<string> &							getResources() const { return m_resources; }

	/// 每一帧的特别定义
	const vector<YHAnimationFrameDefiner> &			getFrameDefines() const { return m_frameDefiners; }
    
    /// 每一帧的特别定义, 数组的指针
    const vector<YHAnimationFrameDefiner> *         getFrameDefinersPoint() const { return &m_frameDefiners; }

private:
	float											m_delay;
	uint32											m_loop;
	bool											m_restoreOriginFrame;
	vector<string>									m_resources;
	vector<YHAnimationFrameDefiner>					m_frameDefiners;
};

/**
 * 精灵的定义器, 从 CCDictionary 中解析出数据
 * @author Zhenyu Yao
 */
class YHSpriteDefiner : public YHObject
{
public:

    /// 创建 YHSpriteDefiner 对象
    static YHSpriteDefiner * create()
    {
        YHSpriteDefiner * instance = new YHSpriteDefiner();
        if (instance != nullptr)
            instance->autorelease();
        return instance;
    }
    
    /// 创建 YHSpriteDefiner 对象
    static YHSpriteDefiner * create(CCDictionary * dict)
    {
        YHSpriteDefiner * instance = new YHSpriteDefiner(dict);
        if (instance != nullptr)
            instance->autorelease();
        return instance;
    }
    
	YHSpriteDefiner() :
	m_anchorPoint(ccp(0.5f, 0.5f)),
	m_position(Point::ZERO),
	m_zOrder(0),
	m_randomRotate(false)
	{
		m_blendFunc = Default_BlendFunc;
	}
	
	YHSpriteDefiner(CCDictionary * dict);
	~YHSpriteDefiner() {}

	/// 锚点
	CCPoint				getAnchorPoint() const { return m_anchorPoint; }

	/// 位置
	CCPoint				getPosition() const { return m_position; }

	/// z 序列
	int					getZOrder() const { return m_zOrder; }

	/// BlendFunc
	CC_SYNTHESIZE(ccBlendFunc, m_blendFunc, BlendFunc);
	
	/// 是否随机旋转
	CC_SYNTHESIZE(bool, m_randomRotate, RandomRotate);
    
    /// 将值赋给指定的 CCSprite 对象
    void                assignToSprite(CCSprite * sp) const;
	
private:
	CCPoint				m_anchorPoint;
	CCPoint				m_position;
	int					m_zOrder;
};

/**
 * Action & YHAnimationKeyEvents
 * @author Zhenyu Yao
 */
class YHAnimationPair : public YHObject
{
public:
	
	YHAnimationPair() : m_action(NULL), m_keyEvents(NULL)
	{
	}
	
	virtual ~YHAnimationPair()
	{
		CC_SAFE_RELEASE_NULL(m_action);
		CC_SAFE_RELEASE_NULL(m_keyEvents);
	}
	
	/// 动画 Action
	CC_SYNTHESIZE_RETAIN(CCAction *, m_action, Action);
	
	/// YHAnimationKeyEvents;
	CC_SYNTHESIZE_RETAIN(YHAnimationKeyEvents *, m_keyEvents, KeyEvents);
	
};

/**
 * 主要负责从 CCDictionary 对象解析出 CCAnimation 对象, 并且针对 CCAnimation 对象的一些列操作
 * @author Zhenyu Yao
 */
class YHAnimationHelper : public YHObject
{
public:		/** Static Functions **/

	/// 使用版本 1 的解析方式, 根据 NSDictionary 对象创建 CCAnimation 对象
	static CCAnimation * createAnimation_Ver1(CCDictionary * dict);

	/// 使用版本 2 的解析方式, 根据 NSDictionary 对象创建 CCAnimation 对象
	static CCAnimation * createAnimation_Ver2(CCDictionary * dict);
	
	/// 使用版本 1 的解析方式创建 YHAnimationDefiner 对象
	static YHAnimationDefiner createAnimationDefiner_Ver1(CCDictionary * dict);

	/// 使用版本 2 的解析方式创建 YHAnimationDefiner 对象
	static YHAnimationDefiner createAnimationDefiner_Ver2(CCDictionary * dict);
    
    /// 使用版本 1 的解析方式创建 YHAnimationDefiner 对象, 返回 YHAnimationDefiner * 指针对象
    static YHAnimationDefiner * createAnimationDefinerPoint_Ver1(CCDictionary * dict);
    
    /// 使用版本 2 的解析方式创建 YHAnimationDefiner 对象, 返回 YHAnimationDefiner * 指针对象
    static YHAnimationDefiner * createAnimationDefinerPoint_Ver2(CCDictionary * dict);

	/// 根据 YHAnimationDefiner 对象创建 CCAnimation 对象
	static CCAnimation * createAnimation(const YHAnimationDefiner & definer);
    
    /// 根据 YHAnimationDefiner 指针对象创建 CCAnimation 对象
    static CCAnimation * createAnimationWithPoint(const YHAnimationDefiner * definer);

	/**
	 * 创建 CCAnimate 对象
	 * @param animation 创建 CCAnimate 对象需要的 CCAnimation 对象
	 * @return CCAnimate 对象
	 */
	static CCAnimate * createAnimate(CCAnimation * animation);

	/**
	 * 创建 CCRepeateForever 对象, 循环播放的动画
	 * @param animation 创建 CCAnimate 对象需要的 CCAnimation 对象
	 * @return CCRepeatForever 对象
	 */
	static CCRepeatForever * createForeverAnimate(CCAnimation * animation);

	/**
	 * 创建 YHAnimationPair 对象
     * @note 不建议直接使用, 建议使用 CCKeyTimeCallbackSprite
	 * @param animation 动画
     * @param loop 序列帧是否循环
	 * @return YHAnimationPair 对象
	 */
	static YHAnimationPair * createAnimationPair(CCAnimation * animation, bool loop);
    
    /**
     * 创建 YHAnimationPair 对象, 并且 sprite 运行动画
     * @note 不建议直接使用, 建议使用 CCKeyTimeCallbackSprite
     * @param animation 动画
     * @param sprite 运行动画的显示对象
     * @param loop 序列帧是否循环
     * @return YHAnimationPair 对象
     */
    static YHAnimationPair * createAnimationPairAndRun(CCAnimation * animation, CCSprite * sprite, bool loop);
	
	/**
	 * 让 sprite 播放动画
	 * @param animation 运行的动画
	 * @param sprite 呈现动画的 CCSprite 对象
	 */
	static void runAnimation(CCAnimation * animation, CCSprite * sprite);

	/**
	 * 让 sprite 循环播放动画
	 * @param animation 运行的动画
	 * @param sprite 呈现动画的 CCSprite 对象
	 */
	static void runForeverAnimation(CCAnimation * animation, CCSprite * sprite);
	
	/**
	 * CCSprite 播放动画, 调用此函数会 stopAllActions 之前所有的 Action
	 */
	static void runActionWithSprite(CCSprite * sprite, CCAnimation * animation, bool forever, AnimatorInitData * initData, AnimatorAnimData * animData);
	
	/**
	 * CCSprite 播放动画, 调用此函数会 stopAllActions 之前所有的 Action
	 */
	static void runActionWithSprite(CCSprite * sprite, CCAnimation * animation, bool forever, AnimatorData * animatorData);

};

#endif /* defined(__AndroidaBooM__YHAnimationHelper__) */


