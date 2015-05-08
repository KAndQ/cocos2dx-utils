//
//  YHCCActionHelper.h
//  AndroidaBooM
//
//  Created by Zhenyu Yao on 13-4-29.
//
//

#ifndef __AndroidaBooM__YHCCActionHelper__
#define __AndroidaBooM__YHCCActionHelper__

#include "YHTypes.h"

/**
 * 创建 CCAction 对象的辅助类
 * @author Zhenyu Yao
 */
class YHCCActionHelper : public YHObject
{
public:
	
	/**
	 * 创建循环播放的缩放动画
	 * @param initScale 初始大小
	 * @param finishScale 结束大小
	 * @param duration 1次循环的持续时间
	 * @param pNode 运行动画的节点
	 */
	static void		runNormalForeverScale(float initScale, float finishScale, float duration, cocos2d::CCNode * pNode);
	
	/**
	 * 间隔一段时间运行一次动画
	 * @param interval 间隔时间
	 * @param animation 运行的动画
	 * @param pSprite 运行动画的 CCSprite 对象
	 */
	static void		runIntervalForeverAnimation(float interval, cocos2d::CCAnimation * animation, cocos2d::CCSprite * pSprite);
    
    /**
	 * 间隔一段时间运行一次动画, 和 runIntervalForeverAnimation 相比, 间隔的时候增加隐藏/显示
	 * @param interval 间隔时间
	 * @param animation 运行的动画
	 * @param pSprite 运行动画的 CCSprite 对象
     * @param begin_callback 每次启动动画的回调
     * @param end_callback 每次结束动画的回调
	 */
    static void     runIntervalForeverAnimation2(float interval, cocos2d::CCAnimation * animation, cocos2d::CCSprite * pSprite,
                                                 const std::function<void ()> & begin_callback = nullptr,
                                                 const std::function<void ()> & end_callback = nullptr);
    
    /**
     * 创建循环移动的动画
     * @param delta 移动的间隔距离
     * @param duration 1次循环的持续时间
     * @param pNode 运行动画的节点
     */
    static void     runNormalForeverMove(const cocos2d::Point & delta, float duration, cocos2d::CCNode * pNode);
    
    /**
     * 循环的淡入淡出动画
     * @param node 显示节点
     * @param duration 1次循环的持续时间
     */
    static void     runForeverFadeInOut(cocos2d::Node * node, float duration);
};

#endif /* defined(__AndroidaBooM__YHCCActionHelper__) */
















































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


