﻿
#include "YHTypes.h"
#include "YHEffectGenerator.h"
#include "AnimationHelper/Animation/YHAnimationCache.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
// YHEffectDefiner
////////////////////////////////////////////////////////////////////////////////////////////////////

YHEffectDefiner::YHEffectDefiner(CCDictionary * dict) : m_spriteDefiner(nullptr)
{
	CCString * strPieces = dynamic_cast<CCString *>(dict->objectForKey("Pieces"));
	if (strPieces != NULL)
	{
		uint32 pieces = strPieces->uintValue();
		if (pieces == 2)
		{
			m_type = kEffectDefineType_Piece2;
		}
		else if (pieces == 4)
		{
			m_type = kEffectDefineType_Piece4;
		}
		else
		{
			m_type = kEffectDefineType_Piece1;
		}
	}
	else
	{
		m_type = kEffectDefineType_Piece1;
	}
	
	CCString * name = dynamic_cast<CCString *>(dict->objectForKey("PieceKey"));
	m_animationName = string(name->getCString());
	
    setSpriteDefiner(YHSpriteDefiner::create((CCDictionary *)dict->objectForKey("SpriteDefiner")));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// YHEffectFactory
////////////////////////////////////////////////////////////////////////////////////////////////////

YHEffectFactory::YHEffectFactory()
{
	m_definerCache = CCDictionary::create();
	CC_SAFE_RETAIN(m_definerCache);
	
	m_effectCache = CCSet::create();
	CC_SAFE_RETAIN(m_effectCache);
    
    m_animationCache = YHAnimationCache::create();
    CC_SAFE_RETAIN(m_animationCache);
}

YHEffectFactory::~YHEffectFactory()
{
	CC_SAFE_RELEASE_NULL(m_definerCache);
	CC_SAFE_RELEASE_NULL(m_effectCache);
    CC_SAFE_RELEASE_NULL(m_animationCache);
}

YHEffectDefiner * YHEffectFactory::effectDefinerForKey(const string & key)
{
	return static_cast<YHEffectDefiner *>(m_definerCache->objectForKey(key.c_str()));
}

void YHEffectFactory::addEffectDefiner(const string & key, YHEffectDefiner * definer)
{
	m_definerCache->setObject(definer, key.c_str());
}

void YHEffectFactory::addEffectDefiner(CCDictionary * dict)
{
	CCDictElement * e = NULL;
	CCDICT_FOREACH(dict, e)
	{
		YHEffectDefiner * definer = new YHEffectDefiner((CCDictionary *)e->getObject());
		definer->autorelease();
		addEffectDefiner(e->getStrKey(), definer);
	}
}

void YHEffectFactory::cleanAllEffectDefiners()
{
	m_definerCache->removeAllObjects();
}

void YHEffectFactory::cleanAllSprites()
{
	m_effectCache->removeAllObjects();
}

void YHEffectFactory::cleanAll()
{
	cleanAllEffectDefiners();
	cleanAllSprites();
}

YHDefaultFiniteEffect * YHEffectFactory::finiteEffectFromCache()
{
    return YHDefaultFiniteEffect::create();
}

void YHEffectFactory::adjustSprite(CCSprite * sp, const YHEffectDefiner * definer)
{
    definer->getSpriteDefiner()->assignToSprite(sp);
}

YHDefaultFiniteEffect * YHEffectFactory::effectSpriteForDefiner(const YHEffectDefiner * definer)
{
	if (definer->getType() == kEffectDefineType_Piece1)
	{
		YHDefaultFiniteEffect * effect = finiteEffectFromCache();
		CCAnimate * animate = m_animationCache->animateForKey(definer->getAnimationName());
		effect->reset(animate);
		adjustSprite(effect, definer);
		return effect;
	}
	else if (definer->getType() == kEffectDefineType_Piece2)
	{
		// right
		YHDefaultFiniteEffect * right = finiteEffectFromCache();
		CCAnimate * animate = m_animationCache->animateForKey(definer->getAnimationName());
		right->reset(animate);
		
		// left
		CCSize contentSize = right->getContentSize();
		YHDefaultFiniteEffect * left = finiteEffectFromCache();
		left->setPosition(ccp(contentSize.width * 0.5f, contentSize.height * 0.5f));
		animate = m_animationCache->animateForKey(definer->getAnimationName());
		left->reset(animate);
		left->setRotation(-180);
		right->addChild(left);
		
		adjustSprite(right, definer);
		
		return right;
	}
	else if (definer->getType() == kEffectDefineType_Piece4)
	{
		// right top
		YHDefaultFiniteEffect * rightTop = finiteEffectFromCache();
		CCAnimate * animate = m_animationCache->animateForKey(definer->getAnimationName());
		rightTop->reset(animate);
        
		CCSize contentSize = rightTop->getContentSize();
		CCPoint centerPoint = ccp(contentSize.width * 0.5f, contentSize.height * 0.5f);
		
		// right bottom
		YHDefaultFiniteEffect * rightBottom = finiteEffectFromCache();
		animate = m_animationCache->animateForKey(definer->getAnimationName());
		rightBottom->reset(animate);
		rightBottom->setPosition(centerPoint);
		rightBottom->setRotation(-90);
		rightTop->addChild(rightBottom);
		
		// left top
		YHDefaultFiniteEffect * leftTop = finiteEffectFromCache();
		animate = m_animationCache->animateForKey(definer->getAnimationName());
		leftTop->reset(animate);
		leftTop->setPosition(centerPoint);
		leftTop->setRotation(-180);
		rightTop->addChild(leftTop);
		
		// left bottom
		YHDefaultFiniteEffect * leftBottom = finiteEffectFromCache();
		animate = m_animationCache->animateForKey(definer->getAnimationName());
		leftBottom->reset(animate);
		leftBottom->setPosition(centerPoint);
		leftBottom->setRotation(-270);
		rightTop->addChild(leftBottom);
		
        adjustSprite(rightTop, definer);
        
		return rightTop;
	}
	else
	{
		// 不可能运行到这里
		assert(false);
	}
	
	return NULL;
}

YHDefaultFiniteEffect * YHEffectFactory::effectSpriteForKey(const string & key)
{
	YHEffectDefiner * definer = static_cast<YHEffectDefiner *>(m_definerCache->objectForKey(key));
	if (definer != NULL)
	{
		return effectSpriteForDefiner(definer);
	}
	
	return NULL;
}


