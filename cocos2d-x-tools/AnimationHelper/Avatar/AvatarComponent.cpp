//
//  AvatarComponent.cpp
//  HelloWorld-3.0
//
//  Created by Zhenyu Yao on 14-4-12.
//
//

#include "AvatarComponent.h"
#include "AnimationHelper/Animation/YHAnimationHelper.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
// Public Functions
////////////////////////////////////////////////////////////////////////////////////////////////////

const int32 AvatarComponent::s_animationTag = 100;
const int32 AvatarComponent::s_ktCallbackTag = 101;

AvatarComponent::AvatarComponent() : m_delegate(nullptr)
{
    for (int32 i = 200; i < 207; ++i)
        m_animatorDataTags.push_back(i);
}

AvatarComponent::~AvatarComponent()
{
    CC_SAFE_RELEASE_NULL(m_animation);
    CC_SAFE_RELEASE_NULL(m_ktCallback);
    CC_SAFE_RELEASE_NULL(m_animatorData);
    this->cleanup();
}

bool AvatarComponent::init(CCAnimation * animation, YHKeyTimeCallback * ktCallback, AnimatorData * animatorData)
{
    bool ret = CCSprite::init();
    
    if (ret)
    {
        setAnimation(animation);
        setKeyTimeCallback(ktCallback);
        setAnimatorData(animatorData);
    }
    
    return ret;
}

void AvatarComponent::setAnimation(CCAnimation * animation)
{
    this->stopActionByTag(s_animationTag);
    CC_SAFE_RELEASE_NULL(m_animation);
    
    if (animation != nullptr)
    {
        m_animation = animation;
        m_animation->retain();
        
        this->setSpriteFrame(animation->getFrames().at(0)->getSpriteFrame());
        
        CCAnimate * animate = CCAnimate::create(animation);
        animate->setTag(s_animationTag);
        this->runAction(animate);
    }
}

void AvatarComponent::setKeyTimeCallback(YHKeyTimeCallback * callback)
{
    this->stopActionByTag(s_ktCallbackTag);
    CC_SAFE_RELEASE_NULL(m_ktCallback);
    
    if (callback != nullptr)
    {
        m_ktCallback = callback;
        m_ktCallback->retain();
        
        m_ktCallback->setNode(this);
        m_ktCallback->setDelegate(this);
        m_ktCallback->getAction()->setTag(s_ktCallbackTag);
        this->runAction(m_ktCallback->getAction());
    }
}

void AvatarComponent::setAnimatorData(AnimatorData * animatorData)
{
    for (auto i : m_animatorDataTags)
        this->stopActionByTag(i);
    CC_SAFE_RELEASE_NULL(m_animatorData);
    
    if (animatorData != nullptr)
    {
        m_animatorData = animatorData;
        m_animatorData->retain();
        
        resetActions();
    }
}

void AvatarComponent::tween(CCAnimation * animation, AnimatorData * animatorData, float32 duration)
{
    setAnimation(animation);
    
    for (auto i : m_animatorDataTags)
        this->stopActionByTag(i);
    CC_SAFE_RELEASE_NULL(m_animatorData);
    
    if (animatorData != nullptr)
    {
        m_animatorData = animatorData;
        m_animatorData->retain();
        
        // 移动到期望的位置
        m_animatorData->getInitData()->tweenToNow(this, duration);
        
        DelayTime * delay = DelayTime::create(duration);
        CallFunc * callfunc = CallFunc::create([this](){
            this->resetActions();
        });
        Sequence * sequence = Sequence::create(delay, callfunc, nullptr);
        sequence->setTag(205);
        this->runAction(sequence);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// Interface - YHKeyTimeCallbackDelegate
////////////////////////////////////////////////////////////////////////////////////////////////////

void AvatarComponent::handleKeyEvent(CCNode * node, CCAnimationFrame * frame)
{
    if (m_delegate != nullptr)
        m_delegate->handleKeyEvent(node, frame);
}

void AvatarComponent::handleKeyEvent(CCNode * node, CCDictionary * userInfo)
{
    if (m_delegate != nullptr)
        m_delegate->handleKeyEvent(node, userInfo);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// Private Functions
///////////////////////////////////////////////c/////////////////////////////////////////////////////

void AvatarComponent::resetActions()
{
    m_animatorData->getInitData()->initializeNode(this);
    m_animatorData->getAnimData()->runActions(this, m_animatorDataTags);
    
    // 针对 offset time 的处理
    CCDelayTime * delayTime = m_animatorData->getAnimData()->getDelayTimeAction();
    if (delayTime != nullptr)
    {
        this->setVisible(false);
        
        // 首先延迟 offset time 时间，然后显示动画（一定从第一帧开始）。
        Vector<FiniteTimeAction *> actions;
        actions.pushBack(delayTime);
        actions.pushBack(Show::create());
        actions.pushBack(CallFunc::create([this]{
            this->stopActionByTag(s_animationTag);
            this->setSpriteFrame(m_animation->getFrames().at(0)->getSpriteFrame());
            CCAnimate * animate = CCAnimate::create(m_animation);
            animate->setTag(s_animationTag);
            this->runAction(animate);
        }));
        // 动画播放结束后，继续延迟，直到时间结束后，设置不可见。
        actions.pushBack(DelayTime::create(m_animatorData->getAnimData()->getSumTime() - m_animatorData->getAnimData()->getOffsetTime()));
        actions.pushBack(Hide::create());
        
        Sequence * seq = Sequence::create(actions);
        Action * action = nullptr;
        if (m_animatorData->getAnimData()->isForever())
            action = RepeatForever::create(seq);
        else
            action = seq;
        action->setTag(206);
        this->runAction(action);
    }
}








































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


