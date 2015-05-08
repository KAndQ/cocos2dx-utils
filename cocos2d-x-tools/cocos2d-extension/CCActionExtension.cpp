//
//  CCActionExtension.cpp
//  cocos2d-x-Utils
//
//  Created by Zhenyu Yao on 13-7-15.
//
//

#include "CCActionExtension.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
// CCAnchorPointBy
////////////////////////////////////////////////////////////////////////////////////////////////////

bool CCAnchorPointBy::initWithDuration(float duration, const CCPoint & deltaPoint)
{
	bool result = CCActionInterval::initWithDuration(duration);
	m_deltaAnchorPoint = deltaPoint;
	return result;
}

CCAnchorPointBy * CCAnchorPointBy::clone() const
{
    CCAnchorPointBy * aClone = new CCAnchorPointBy();
    aClone->initWithDuration(_duration, m_deltaAnchorPoint);
    aClone->autorelease();
    return aClone;
}

void CCAnchorPointBy::startWithTarget(cocos2d::CCNode * pTarget)
{
	CCActionInterval::startWithTarget(pTarget);
	m_startAnchorPoint = pTarget->getAnchorPoint();
}

CCActionInterval * CCAnchorPointBy::reverse() const
{
    return CCAnchorPointBy::create(_duration, ccp(-m_deltaAnchorPoint.x, -m_deltaAnchorPoint.y));
}

void CCAnchorPointBy::update(float t)
{
	if (_target != NULL)
	{
		_target->setAnchorPoint(ccp(m_startAnchorPoint.x + m_deltaAnchorPoint.x * t,
                                    m_startAnchorPoint.y + m_deltaAnchorPoint.y * t));
	}
}

CCAnchorPointBy * CCAnchorPointBy::create(float duration, const CCPoint & deltaPoint)
{
	CCAnchorPointBy * instance = new CCAnchorPointBy();
	if (instance != NULL && instance->initWithDuration(duration, deltaPoint))
	{
		instance->autorelease();
		return instance;
	}
	
	CC_SAFE_DELETE(instance);
	return NULL;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// CCAnchorPointTo
////////////////////////////////////////////////////////////////////////////////////////////////////

bool CCAnchorPointTo::initWithDuration(float duration, const cocos2d::CCPoint & endPoint)
{
	bool result = CCAnchorPointBy::initWithDuration(duration, endPoint);
	m_endAnchorPoint = endPoint;
	return result;
}

CCAnchorPointTo * CCAnchorPointTo::clone() const
{
    CCAnchorPointTo * aClone = new CCAnchorPointTo();
    aClone->initWithDuration(_duration, m_endAnchorPoint);
    aClone->autorelease();
    return aClone;
}

void CCAnchorPointTo::startWithTarget(CCNode * pTarget)
{
	CCAnchorPointBy::startWithTarget(pTarget);
	m_deltaAnchorPoint = ccpSub(m_endAnchorPoint, pTarget->getAnchorPoint());
}

CCAnchorPointTo * CCAnchorPointTo::create(float duration, const cocos2d::CCPoint & endPoint)
{
	CCAnchorPointTo * instance = new CCAnchorPointTo();
	if (instance != NULL && instance->initWithDuration(duration, endPoint))
	{
		instance->autorelease();
		return instance;
	}
	
	CC_SAFE_DELETE(instance);
	return instance;
}














































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


