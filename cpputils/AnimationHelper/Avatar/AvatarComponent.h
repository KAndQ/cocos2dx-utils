//
//  AvatarComponent.h
//  HelloWorld-3.0
//
//  Created by Zhenyu Yao on 14-4-12.
//
//

#ifndef __HelloWorld_3_0__AvatarComponent__
#define __HelloWorld_3_0__AvatarComponent__

#include "AnimationHelper/Action/AnimationTypes.h"
#include "AnimationHelper/Animation/YHAnimationKeyEvents.h"

/**
 * 纸娃娃关节组件, 主要持有 3 个数据, CCAnimation, YHKeyTimeCallback, AnimatorData
 * 如果要同时替换 Animation 和 AnimatorData, 请先 setAnimation, 再 setAnimatorData, 这样可以保证动画如你所期望。
 * @author Zhenyu Yao
 */
class AvatarComponent : public cocos2d::Sprite, public YHKeyTimeCallbackDelegate
{
public:
    
    AvatarComponent();
    virtual ~AvatarComponent();
    
    /**
     * 创建 AvatarComponent 对象
     * @param animation 动画数据
     * @param ktCallback 关键帧数据
     * @param animatorData 骨骼动画数据
     */
    static AvatarComponent * create(CCAnimation * animation, YHKeyTimeCallback * ktCallback, AnimatorData * animatorData)
    {
        AvatarComponent * instance = new AvatarComponent();
        if (instance != nullptr && instance->init(animation, ktCallback, animatorData))
        {
            instance->autorelease();
            return instance;
        }
        
        CC_SAFE_DELETE(instance);
        return nullptr;
    }
    
    /**
     * 初始化
     * @param animation 动画数据
     * @param ktCallback 关键帧数据
     * @param animatorData 骨骼动画数据
     */
    virtual bool init(CCAnimation * animation, YHKeyTimeCallback * ktCallback, AnimatorData * animatorData);
    
    /// 设置动画数据
    virtual void setAnimation(CCAnimation * animation);
    virtual CCAnimation * getAnimation() const { return m_animation; }
    
    /// 设置关键帧数据
    virtual void setKeyTimeCallback(YHKeyTimeCallback * callback);
    
    /// 设置骨骼动画数据, 骨骼动画会重置, 并且从新的骨骼动画的起始位置开始播放
    virtual void setAnimatorData(AnimatorData * animatorData);
    virtual AnimatorData * getAnimatorData() const { return m_animatorData; }
    
    /// 补间到指定位置的动画
    virtual void tween(CCAnimation * animation, AnimatorData * animatorData, float32 duration = 0.1f);
    
    /// YHKeyTimeCallbackDelegate
    CC_SYNTHESIZE(YHKeyTimeCallbackDelegate *, m_delegate, Delegate);
    
#if CC_ENABLE_SCRIPT_BINDING
    void setHandler(int handler) { if (m_ktCallback) m_ktCallback->setHandler(handler); }
#endif
    
    virtual void handleKeyEvent(CCNode * node, CCAnimationFrame * frame) override;
    virtual void handleKeyEvent(CCNode * node, CCDictionary * userInfo) override;
    
protected:
    
    /// 运行 action
    virtual void resetActions();
    
    static const int32 s_animationTag;
    static const int32 s_ktCallbackTag;
    
    std::vector<int32> m_animatorDataTags;
    CCAnimation * m_animation = nullptr;
    YHKeyTimeCallback * m_ktCallback = nullptr;
    AnimatorData * m_animatorData = nullptr;
};

#endif /* defined(__HelloWorld_3_0__AvatarComponent__) */














































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


