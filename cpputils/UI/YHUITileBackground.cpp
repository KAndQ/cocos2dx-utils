//
//  YHUITileBackground.cpp
//  AndroidaBooM
//
//  Created by Zhenyu Yao on 13-4-24.
//
//

#include "YHUITileBackground.h"

using namespace cocos2d;

bool YHUITileBackground::init(TileType tileType, const char * spriteFrameName)
{
	bool result = CCSprite::initWithSpriteFrameName(spriteFrameName);
	this->setTextureRect(Rect::ZERO);
	
	if (tileType == TileBackground_TileType::kTileType_2)
	{
		const CCSize contentSize = this->getContentSize();
		
		// left
		CCSprite * lBG = CCSprite::createWithSpriteFrameName(spriteFrameName);
		lBG->setAnchorPoint(ccp(1.0f, 0.5f));
        lBG->setPosition(Point(2, 0));
		this->addChild(lBG);
		
		// right
		CCSprite * rBG = CCSprite::createWithSpriteFrameName(spriteFrameName);
		rBG->setScaleX(-1.0f);
        rBG->setPosition(Point(-2, 0));
		rBG->setAnchorPoint(ccp(1.0f, 0.5f));
		this->addChild(rBG);
	}
	else if (tileType == TileBackground_TileType::kTileType_4)
	{
		// top left
		CCSprite * tlBG = CCSprite::createWithSpriteFrameName(spriteFrameName);
		tlBG->setAnchorPoint(ccp(1.0f, 0.0f));
        tlBG->setPosition(Point(2, -2));
		this->addChild(tlBG);
		
		// top right
		CCSprite * trBG = CCSprite::createWithSpriteFrameName(spriteFrameName);
		trBG->setScaleX(-1.0f);
		trBG->setAnchorPoint(ccp(1.0f, 0.0f));
        trBG->setPosition(Point(-2, -2));
		this->addChild(trBG);
		
		// bottom left
		CCSprite * blBG = CCSprite::createWithSpriteFrameName(spriteFrameName);
		blBG->setScaleY(-1.0f);
		blBG->setAnchorPoint(ccp(1.0f, 0.0f));
        blBG->setPosition(Point(2, 2));
		this->addChild(blBG);
		
		// bottom right
		CCSprite * brBG = CCSprite::createWithSpriteFrameName(spriteFrameName);
		brBG->setScale(-1.0f);
		brBG->setAnchorPoint(ccp(1.0f, 0.0f));
        brBG->setPosition(Point(-2, 2));
		this->addChild(brBG);
	}
	
	return result;
}

YHUITileBackground * YHUITileBackground::create(TileType tileType, const char * spriteFrameName)
{
	YHUITileBackground * bg = new YHUITileBackground();
	if (bg != NULL && bg->init(tileType, spriteFrameName))
	{
		bg->autorelease();
	}
	else
	{
		delete bg;
		bg = NULL;
	}
	
	return bg;
}



