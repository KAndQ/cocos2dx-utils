
#include "CCSpecialSprite.h"
#include "AnimationHelper/Action/AnimationTypes.h"

void CCSpecialSprite::draw(Renderer *renderer, const kmMat4 &transform, bool transformUpdated)
{
}

void CCSpecialSprite::setColor(const ccColor3B & color3)
{
	CCSprite::setColor(color3);
    
    Vector<CCNode *>::const_iterator beg = _children.begin();
    Vector<CCNode *>::const_iterator end = _children.end();
    for (; beg != end; ++beg)
    {
        CCRGBAProtocol * rgba = dynamic_cast<CCRGBAProtocol *>(*beg);
        if (rgba != NULL)
            rgba->setColor(color3);
    }
}

void CCSpecialSprite::setOpacity(GLubyte opacity)
{
	CCSprite::setOpacity(opacity);
    
    Vector<CCNode *>::const_iterator beg = _children.begin();
    Vector<CCNode *>::const_iterator end = _children.end();
    for (; beg != end; ++beg)
    {
        CCRGBAProtocol * rgba = dynamic_cast<CCRGBAProtocol *>(*beg);
        if (rgba != NULL)
            rgba->setOpacity(opacity);
    }
}

void CCSpecialSprite::addChild(cocos2d::Node * child)
{
    Sprite::addChild(child);
    forChildDoSth(child);
}

void CCSpecialSprite::addChild(cocos2d::Node * child, int localZOrder)
{
    Sprite::addChild(child, localZOrder);
    forChildDoSth(child);
}

void CCSpecialSprite::addChild(CCNode *pChild, int zOrder, int tag)
{
	Sprite::addChild(pChild, zOrder, tag);
	forChildDoSth(pChild);
}

void CCSpecialSprite::addChild(cocos2d::Node * child, int localZOrder, const std::string & name)
{
    Sprite::addChild(child, localZOrder, name);
    forChildDoSth(child);
}

bool CCSpecialSprite::init()
{
    return Sprite::init();
}

bool CCSpecialSprite::initWithTexture(Texture2D * texture)
{
    return Sprite::initWithTexture(texture);
}

bool CCSpecialSprite::initWithTexture(Texture2D * texture, const Rect & rect)
{
    return Sprite::initWithTexture(texture, rect);
}

bool CCSpecialSprite::initWithTexture(Texture2D * texture, const Rect & rect, bool rotated)
{
    return Sprite::initWithTexture(texture, rect, rotated);
}

bool CCSpecialSprite::initWithSpriteFrame(SpriteFrame * pSpriteFrame)
{
    return Sprite::initWithSpriteFrame(pSpriteFrame);
}

bool CCSpecialSprite::initWithSpriteFrameName(const std::string & spriteFrameName)
{
    return Sprite::initWithSpriteFrameName(spriteFrameName);
}

bool CCSpecialSprite::initWithFile(const std::string & filename)
{
    return Sprite::initWithFile(filename);
}

bool CCSpecialSprite::initWithFile(const std::string & filename, const Rect & rect)
{
    return Sprite::initWithFile(filename, rect);
}

bool CCSpecialSprite::init(cocos2d::CCDictionary * moduleDict)
{
	assert(moduleDict);
	
	bool bRet = false;
	
	do {
		AnimatorModuleData * moduleData = AnimatorModuleData::data(moduleDict);
		CC_BREAK_IF(!init(moduleData));
		
		bRet = true;
	} while (0);
	
	return bRet;
}

bool CCSpecialSprite::init(AnimatorModuleData * moduleData)
{
	bool bRet = false;
	
	do {
		CC_BREAK_IF(!CCSprite::init());
        moduleData->assignToNode(this);
		bRet = true;
	} while (0);
	
	return bRet;
}

CCSpecialSprite* CCSpecialSprite::create(cocos2d::CCDictionary * moduleDict)
{
	CCSpecialSprite* sp = new CCSpecialSprite();
	if (sp && sp->init(moduleDict))
	{
		sp->autorelease();
		return sp;
	}
	CC_SAFE_DELETE(sp);
	return NULL;
}

CCSpecialSprite* CCSpecialSprite::create(AnimatorModuleData * moduleData)
{
	CCSpecialSprite* sp = new CCSpecialSprite();
	if (sp && sp->init(moduleData))
	{
		sp->autorelease();
		return sp;
	}
	CC_SAFE_DELETE(sp);
	return NULL;
}

void CCSpecialSprite::forChildDoSth(cocos2d::Node * node)
{
    if (dynamic_cast<CCSprite *>(node) != nullptr)
        setTexture(((CCSprite *)node)->getTexture());
    
    /*
	CCRGBAProtocol * rgba = dynamic_cast<CCRGBAProtocol *>(node);
	if (rgba != NULL)
	{
		rgba->setColor(this->getColor());
		rgba->setOpacity(this->getOpacity());
	}
     */
}
