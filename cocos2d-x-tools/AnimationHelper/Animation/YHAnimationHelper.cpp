//
//  YHAnimationHelper.cpp
//  AndroidaBooM
//
//  Created by Zhenyu Yao on 13-4-27.
//
//

#include "YHAnimationHelper.h"
#include "AnimationHelper/Action/AnimationTypes.h"
#include "Utils/Common/CommonUtils.h"
#include "Utils/Common/YHJsonHelper.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////
// YHAnimationFrameDefiner
////////////////////////////////////////////////////////////////////////////////////////////////////

YHAnimationFrameDefiner::YHAnimationFrameDefiner(CCDictionary * dict)
{
	// index
	CCString * strIndex = dynamic_cast<CCString *>(dict->objectForKey("Index"));
	m_index = strIndex->uintValue();
	
	// Delay units
	CCString * strDelayUnits = dynamic_cast<CCString *>(dict->objectForKey("DelayUnits"));
	m_delayUnit = strDelayUnits != NULL ? strDelayUnits->floatValue() : 1.0f;
	
	// UserData
    if (dynamic_cast<CCDictionary *>(dict->objectForKey("UserInfo")) != NULL)
        m_userInfo = valueMapFromDictionary((CCDictionary *)(dict->objectForKey("UserInfo")));
}

YHAnimationFrameDefiner::~YHAnimationFrameDefiner()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// YHAnimationDefiner
////////////////////////////////////////////////////////////////////////////////////////////////////

void YHAnimationDefiner::parse_ver1(CCDictionary * dict)
{
	m_delay = dict->valueForKey("Delay")->floatValue();

	CCArray * resources = dynamic_cast<CCArray *>(dict->objectForKey("Resources"));
	CCObject * pObj = NULL;
	CCARRAY_FOREACH(resources, pObj)
	{
		CCString * spriteFrameName = static_cast<CCString *>(pObj);
		m_resources.push_back(spriteFrameName->getCString());
	}
}

void YHAnimationDefiner::parse_ver2(CCDictionary * dict)
{
	// File name
	CCString * name = dynamic_cast<CCString *>(dict->objectForKey("FileName"));

	// Range
	CCString * strRange = dynamic_cast<CCString *>(dict->objectForKey("Range"));
	CCPoint point = PointFromString(strRange->getCString());
	
	// Extension
	CCString * extension = dynamic_cast<CCString *>(dict->objectForKey("Extension"));

	// Delay
	CCString * strDelay = dynamic_cast<CCString *>(dict->objectForKey("Delay"));
	m_delay = strDelay->floatValue();
	
	// Loop
	CCString * strLoop = dynamic_cast<CCString *>(dict->objectForKey("Loop"));
	m_loop = strLoop->uintValue();
	
	// RestoreOriginFrame
	CCString * strRestoreOriginFrame = dynamic_cast<CCString *>(dict->objectForKey("RestoreOriginFrame"));
	m_restoreOriginFrame = strRestoreOriginFrame != NULL ? strRestoreOriginFrame->boolValue() : false;
	
    // Reverse
    bool reverse = dict->valueForKey("Reverse")->boolValue();
    
	// resources
    if (!reverse)
    {
        for (int i = point.x; i <= point.y; ++i)
        {
            string spriteFrameName = name->getCString() + uint32ToString(i) + "." + extension->getCString();
            m_resources.push_back(spriteFrameName.c_str());
        }
    }
    else
    {
        for (int i = point.y; i >= point.x; --i)
        {
            string spriteFrameName = name->getCString() + uint32ToString(i) + "." + extension->getCString();
            m_resources.push_back(spriteFrameName.c_str());
        }
    }
	
	// 设置各个帧的参数
	CCArray * frames = dynamic_cast<CCArray *>(dict->objectForKey("Frames"));
	CCObject * pObj = NULL;
	CCARRAY_FOREACH(frames, pObj)
	{
		CCDictionary * frameDict = dynamic_cast<CCDictionary *>(pObj);
		YHAnimationFrameDefiner frameDefiner = YHAnimationFrameDefiner(frameDict);
		frameDefiner.m_index = frameDefiner.m_index - point.x;		// 计算出实际帧的 Index
		m_frameDefiners.push_back(frameDefiner);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// YHSpriteDefiner
////////////////////////////////////////////////////////////////////////////////////////////////////

YHSpriteDefiner::YHSpriteDefiner(CCDictionary * dict) :
m_anchorPoint(ccp(0.5f, 0.5f)),
m_position(Point::ZERO),
m_zOrder(0),
m_randomRotate(false)
{
    m_blendFunc = Default_BlendFunc;
	
	if (dict != NULL)
	{
		m_anchorPoint = PointFromString(dict->valueForKey("Anchor")->getCString());
		m_position = PointFromString(dict->valueForKey("Position")->getCString());
		m_zOrder = dict->valueForKey("ZOrder")->intValue();
		m_randomRotate = dict->valueForKey("RandomRotate")->boolValue();
		
		CCDictionary * blendFuncDict = (CCDictionary *)dict->objectForKey("BlendFunc");
		if (blendFuncDict != NULL)
		{
			m_blendFunc.src = blendFuncDict->valueForKey("Src")->uintValue();
			m_blendFunc.dst = blendFuncDict->valueForKey("Dst")->uintValue();
		}
	}
}

void YHSpriteDefiner::assignToSprite(CCSprite * sp) const
{
    sp->setAnchorPoint(m_anchorPoint);
    sp->setPosition(m_position);
    sp->setZOrder(m_zOrder);
    if (m_randomRotate)
        sp->setRotation(360.0f * CCRANDOM_0_1());
    sp->setBlendFunc(m_blendFunc);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// YHAnimationHelper
////////////////////////////////////////////////////////////////////////////////////////////////////

CCAnimation * YHAnimationHelper::createAnimation_Ver1(CCDictionary * dict)
{
	YHAnimationDefiner definer = createAnimationDefiner_Ver1(dict);
	return createAnimation(definer);
}

CCAnimation * YHAnimationHelper::createAnimation_Ver2(CCDictionary * dict)
{
	YHAnimationDefiner definer = createAnimationDefiner_Ver2(dict);
	return createAnimation(definer);
}

CCAnimation * YHAnimationHelper::createAnimation(const YHAnimationDefiner & definer)
{
	// 创建 CCAnimationFrame 对象数组
	vector<string>::const_iterator resBeg = definer.getResources().begin();
	vector<string>::const_iterator resEnd = definer.getResources().end();
    Vector<CCAnimationFrame *> animationFrames;
	CCSpriteFrameCache * cache = CCSpriteFrameCache::sharedSpriteFrameCache();
	for (; resBeg != resEnd; ++resBeg)
	{
		CCSpriteFrame * spriteFrame = cache->spriteFrameByName(resBeg->c_str());
		CCAnimationFrame * animationFrame = CCAnimationFrame::create(spriteFrame, 1.0f, ValueMap());
        animationFrames.pushBack(animationFrame);
	}
	
	// 设置各个帧的参数
	vector<YHAnimationFrameDefiner>::const_iterator frameBeg = definer.getFrameDefines().begin();
	vector<YHAnimationFrameDefiner>::const_iterator frameEnd = definer.getFrameDefines().end();
	for(; frameBeg != frameEnd; ++frameBeg)
	{
		const YHAnimationFrameDefiner & frameDefiner = *frameBeg;
		CCAnimationFrame * animationFrame = static_cast<CCAnimationFrame *>(animationFrames.at(frameDefiner.getIndex()));
		animationFrame->setDelayUnits(frameDefiner.getDelayUnit());
		animationFrame->setUserInfo(frameDefiner.getUserInfo());
	}
	
	CCAnimation * animation = CCAnimation::create(animationFrames, definer.getDelay(), definer.getLoop());
	animation->setRestoreOriginalFrame(definer.getRestoreOriginFrame());
	return animation;
}

CCAnimation * YHAnimationHelper::createAnimationWithPoint(const YHAnimationDefiner * definer)
{
    return createAnimation(*definer);
}

YHAnimationDefiner YHAnimationHelper::createAnimationDefiner_Ver1(CCDictionary * dict)
{
	YHAnimationDefiner definer;
	definer.parse_ver1(dict);
	return definer;
}

YHAnimationDefiner YHAnimationHelper::createAnimationDefiner_Ver2(CCDictionary * dict)
{
	YHAnimationDefiner definer;
	definer.parse_ver2(dict);
	return definer;
}

YHAnimationDefiner * YHAnimationHelper::createAnimationDefinerPoint_Ver1(CCDictionary * dict)
{
    YHAnimationDefiner * ad = YHAnimationDefiner::create();
    ad->parse_ver1(dict);
    return ad;
}

YHAnimationDefiner * YHAnimationHelper::createAnimationDefinerPoint_Ver2(CCDictionary * dict)
{
    YHAnimationDefiner * ad = YHAnimationDefiner::create();
    ad->parse_ver2(dict);
    return ad;
}

CCAnimate * YHAnimationHelper::createAnimate(CCAnimation * animation)
{
	return CCAnimate::create(animation);
}

CCRepeatForever * YHAnimationHelper::createForeverAnimate(CCAnimation * animation)
{
	return CCRepeatForever::create(createAnimate(animation));
}

YHAnimationPair * YHAnimationHelper::createAnimationPair(CCAnimation * animation, bool loop)
{
	CCAction * action = NULL;
	if (loop)
		action = createForeverAnimate(animation);
	else
		action = createAnimate(animation);
	
	YHAnimationKeyEvents * keyEvents = YHAnimationKeyEvents::create(animation, loop);
	YHAnimationPair * animPair = new YHAnimationPair();
	animPair->autorelease();
	animPair->setAction(action);
	animPair->setKeyEvents(keyEvents);
	return animPair;
}

YHAnimationPair * YHAnimationHelper::createAnimationPairAndRun(CCAnimation * animation, CCSprite * sprite, bool loop)
{
    YHAnimationPair * animationPair = createAnimationPair(animation, loop);
    sprite->setDisplayFrame(animation->getFrames().at(0)->getSpriteFrame());
    
    // 动画的 Action
    sprite->runAction(animationPair->getAction());
    
    // 关键帧的 Action
    if (animationPair->getKeyEvents()->getAction() != NULL)
    {
        animationPair->getKeyEvents()->setNode(sprite);
        sprite->runAction(animationPair->getKeyEvents()->getAction());
    }
    
    return animationPair;
}

void YHAnimationHelper::runAnimation(CCAnimation * animation, CCSprite * sprite)
{
	CCAnimationFrame * animationFrame = static_cast<CCAnimationFrame *>(animation->getFrames().at(0));
	sprite->setDisplayFrame(animationFrame->getSpriteFrame());

	CCAnimate * animate = CCAnimate::create(animation);
	sprite->runAction(animate);
}

void YHAnimationHelper::runForeverAnimation(CCAnimation * animation, CCSprite * sprite)
{
    CCAnimationFrame * animationFrame = animation->getFrames().at(0);
	sprite->setDisplayFrame(animationFrame->getSpriteFrame());
    
    if (animation->getFrames().size() > 1)
    {
        CCAnimate * animate = CCAnimate::create(animation);
        CCRepeatForever * forever = CCRepeatForever::create(animate);
        sprite->runAction(forever);
    }
}

void YHAnimationHelper::runActionWithSprite(cocos2d::CCSprite *sprite,
											cocos2d::CCAnimation *animation,
											bool forever,
											AnimatorInitData *initData,
											AnimatorAnimData *animData)
{
	assert(sprite);
	assert(animation);
	assert(initData);
	assert(animData);
	
	sprite->stopAllActions();
	if (forever)
		runForeverAnimation(animation, sprite);
	else
		runAnimation(animation, sprite);
	
	initData->initializeNode(sprite);
	animData->runActions(sprite);
}

void YHAnimationHelper::runActionWithSprite(cocos2d::CCSprite *sprite,
											cocos2d::CCAnimation *animation,
											bool forever,
											AnimatorData *animatorData)
{
	runActionWithSprite(sprite, animation, forever, animatorData->m_initData, animatorData->m_animData);
}
