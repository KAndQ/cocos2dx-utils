//
//  YHCCActionHelper.cpp
//  AndroidaBooM
//
//  Created by Zhenyu Yao on 13-4-29.
//
//

#include "YHCCActionHelper.h"
#include "AnimationHelper/Animation/YHAnimationHelper.h"

using namespace cocos2d;

void YHCCActionHelper::runNormalForeverScale(float initScale, float finishScale, float duration, CCNode * pNode)
{
	pNode->setScale(initScale);
	CCScaleTo * scaleTo1 = CCScaleTo::create(duration * 0.5f, finishScale);
	CCScaleTo * scaleTo2 = CCScaleTo::create(duration * 0.5f, initScale);
	CCSequence * seq = CCSequence::create(scaleTo1, scaleTo2, NULL);
	CCRepeatForever * forever = CCRepeatForever::create(seq);
	pNode->runAction(forever);
}

void YHCCActionHelper::runIntervalForeverAnimation(float interval, CCAnimation * animation, CCSprite * pSprite)
{
	CCAnimate * animate = CCAnimate::create(animation);
	CCDelayTime * delay = CCDelayTime::create(interval);
	CCSequence * sequence = CCSequence::create(animate, delay, NULL);
	CCRepeatForever * forever = CCRepeatForever::create(sequence);
	CCAnimationFrame * animationFrame = static_cast<CCAnimationFrame *>(animate->getAnimation()->getFrames().at(0));
	pSprite->setDisplayFrame(animationFrame->getSpriteFrame());
	pSprite->runAction(forever);
}

void YHCCActionHelper::runIntervalForeverAnimation2(float interval, cocos2d::CCAnimation * animation,
                                                    cocos2d::CCSprite * pSprite,
                                                    const std::function<void ()> & begin_callback,
                                                    const std::function<void ()> & end_callback)
{
    Vector<FiniteTimeAction *> actions;
    Animate * animate = Animate::create(animation);
    Hide * hide = Hide::create();
    DelayTime * delay = DelayTime::create(interval);
    Show * show = Show::create();
    
    if (begin_callback != nullptr)
    {
        CallFunc * callfunc = CallFunc::create(begin_callback);
        actions.pushBack(callfunc);
    }
    actions.pushBack(animate);
    actions.pushBack(hide);
    actions.pushBack(delay);
    actions.pushBack(show);
    if (end_callback != nullptr)
    {
        CallFunc * callfunc = CallFunc::create(end_callback);
        actions.pushBack(callfunc);
    }
    
    Sequence * sequence = Sequence::create(actions);
    RepeatForever * repeatForever = RepeatForever::create(sequence);
    AnimationFrame * frame = animate->getAnimation()->getFrames().at(0);
    pSprite->setDisplayFrame(frame->getSpriteFrame());
    pSprite->runAction(repeatForever);
}

void YHCCActionHelper::runNormalForeverMove(const cocos2d::Point & delta, float duration, cocos2d::CCNode * pNode)
{
    CCMoveBy * moveBy1 = CCMoveBy::create(duration * 0.5f, delta);
    CCMoveBy * moveBy2 = CCMoveBy::create(duration * 0.5f, Point(-delta.x, -delta.y));
    CCSequence * sequence = CCSequence::create(moveBy1, moveBy2, nullptr);
    pNode->runAction(CCRepeatForever::create(sequence));
}

void YHCCActionHelper::runForeverFadeInOut(cocos2d::Node * node, float duration)
{
    node->setOpacity(255);
    FadeIn * fadeIn = FadeIn::create(duration * 0.5f);
    FadeOut * fadeOut = FadeOut::create(duration * 0.5f);
    Sequence * sequence = Sequence::create(fadeOut, fadeIn, nullptr);
    node->runAction(RepeatForever::create(sequence));
}













































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


