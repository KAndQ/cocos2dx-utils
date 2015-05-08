
#include "YHUITimeNumber.h"
#include "YHUISpriteNumber.h"

USING_NS_CC;

/// 图层定义
typedef enum
{
	kTimeNumberLayer_Separator,
	kTimeNumberLayer_Number,
	
}TimeNumberLayer;

YHUITimeNumber::YHUITimeNumber(void)
{
}

YHUITimeNumber::~YHUITimeNumber(void)
{
    this->cleanup();
}

float YHUITimeNumber::contentWidth()
{
    float32 width = 0.0f;
    
    if (m_icon != nullptr)
    {
        width += m_icon->getContentSize().width * m_icon->getAnchorPoint().x;
        width += m_iconInterval;
    }
    
    if (m_hourNumber->isVisible())
    {
        width += m_hourNumber->getNumberFontWidth();
        width += m_hourSeparatorInterval;
        width += m_hourSeparatorInterval;
    }
    
    if (m_minNumber->isVisible())
    {
        width += m_minNumber->getNumberFontWidth();
        width += m_minSeparatorInterval;
        width += m_minSeparatorInterval;
    }
    
    width += m_secNumber->getNumberFontWidth();
    
    return width;
}

YHUITimeNumber* YHUITimeNumber::create(cocos2d::CCSprite * iconHour, float hourInterval,
                                       cocos2d::CCSprite * iconMin, float minInterval,
                                       const std::string & fontName, const cocos2d::CCSize & fontSize,
                                       float fontInterval)
{
	YHUITimeNumber* instance = new YHUITimeNumber();
	if ( instance && instance->init(iconHour, hourInterval,
									iconMin, minInterval,
									fontName, fontSize,
									fontInterval))
	{
		instance->autorelease();
		return instance;
	}
	CC_SAFE_DELETE(instance);
	return NULL;
}

bool YHUITimeNumber::init(cocos2d::CCSprite * iconHour, float hourInterval,
                          cocos2d::CCSprite * iconMin, float minInterval,
                          const std::string & fontName, const cocos2d::CCSize & fontSize,
                          float fontInterval)
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!CCSprite::init());
		this->setTexture(iconHour->getTexture());
        
		m_iconHour = iconHour;
		m_iconMin = iconMin;
		addChild(m_iconHour, kTimeNumberLayer_Separator);
		addChild(m_iconMin, kTimeNumberLayer_Separator);
		
		m_hourSeparatorInterval = hourInterval;
		m_minSeparatorInterval = minInterval;
		
		m_hourNumber = YHUISpriteNumber::create(fontName.c_str(), fontSize, fontInterval);
		m_minNumber = YHUISpriteNumber::create(fontName.c_str(), fontSize, fontInterval);
		m_secNumber = YHUISpriteNumber::create(fontName.c_str(), fontSize, fontInterval);
		
        m_hourNumber->setAlignType(YHSpriteNumber_AlignType::kAlignType_Left);
        m_minNumber->setAlignType(YHSpriteNumber_AlignType::kAlignType_Left);
        m_secNumber->setAlignType(YHSpriteNumber_AlignType::kAlignType_Left);
        
		addChild(m_hourNumber, kTimeNumberLayer_Number);
		addChild(m_minNumber, kTimeNumberLayer_Number);
		addChild(m_secNumber, kTimeNumberLayer_Number);
		
        m_fontSize = fontSize;
        m_iconInterval = fontInterval;
        
		setTimeWithSecond(0);
		
		bRet = true;
	} while (0);
	
	return bRet;
}

void YHUITimeNumber::setTimeWithSecond(uint32 second, bool zerofill)
{
	int hour = second / 3600;
	int min = (second - hour * 3600) / 60;
	int sec = (second - hour * 3600 - min * 60);
	
    if (!zerofill)
    {
        m_hourNumber->setNumber(hour);
        m_minNumber->setNumber(min);
        m_secNumber->setNumber(sec);
    }
    else
    {
        char buf[8] = {0, };
        sprintf(buf, "%02d", hour);
        m_hourNumber->setNumber(buf);
        
        sprintf(buf, "%02d", min);
        m_minNumber->setNumber(buf);
        
        sprintf(buf, "%02d", sec);
        m_secNumber->setNumber(buf);
    }
	
    layout();
}

void YHUITimeNumber::setTimeWithMilliSecond(uint32 milliSecond, bool zerofill)
{
	uint32 second = milliSecond / 1000;
	setTimeWithSecond(second, zerofill);
}

void YHUITimeNumber::setIcon(cocos2d::CCSprite * icon)
{
    if (m_icon != nullptr)
    {
        m_icon->removeFromParentAndCleanup(true);
    }
    
    m_icon = icon;
    
    if (m_icon != nullptr)
    {
        this->addChild(m_icon, kTimeNumberLayer_Separator);
    }
    
    layout();
}

void YHUITimeNumber::setIconInterval(float32 interval)
{
    m_iconInterval = interval;
    layout();
}

void YHUITimeNumber::setIconAndInterval(cocos2d::CCSprite * icon, float32 interval)
{
    if (m_icon != nullptr)
    {
        m_icon->removeFromParentAndCleanup(true);
    }
    
    m_icon = icon;
    
    if (m_icon != nullptr)
    {
        this->addChild(m_icon, kTimeNumberLayer_Separator);
    }
    
    m_iconInterval = interval;
    
    layout();
}

void YHUITimeNumber::setAlignType(YHSpriteNumber_AlignType alignType)
{
    m_alignType = alignType;
    layout();
}

void YHUITimeNumber::setHourVisible(bool visible)
{
    m_hourNumber->setVisible(visible);
    m_iconHour->setVisible(visible);
    layout();
}

void YHUITimeNumber::setMinVisible(bool visible)
{
    m_hourNumber->setVisible(visible);
    m_iconHour->setVisible(visible);
    m_minNumber->setVisible(visible);
    m_iconMin->setVisible(visible);
    layout();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// Private Functions
////////////////////////////////////////////////////////////////////////////////////////////////////

void YHUITimeNumber::layout()
{
    float32 beginX = 0.0f;
    float32 width = contentWidth();
    
    if (m_icon != nullptr)
    {
        beginX += m_icon->getContentSize().width * m_icon->getAnchorPoint().x;
    }
    
    switch (m_alignType)
    {
        case YHSpriteNumber_AlignType::kAlignType_Left:
            break;
        case YHSpriteNumber_AlignType::kAlignType_Center:
            beginX -= width * 0.5f;
            break;
        case YHSpriteNumber_AlignType::kAlignType_Right:
            beginX -= width;
            break;
    }
    
    Point cursor(beginX, 0.0f);
    
    // Icon
    if (m_icon != nullptr)
    {
        m_icon->setPosition(cursor);
        cursor.x += m_iconInterval;
    }
    
    // Hour
    if (m_hourNumber->isVisible())
    {
        m_hourNumber->setPosition(cursor);
        cursor.x += m_hourNumber->getNumberFontWidth() + m_hourSeparatorInterval;
        
        m_iconHour->setPosition(cursor);
        cursor.x += m_hourSeparatorInterval;
    }
    
    // Min
    if (m_minNumber->isVisible())
    {
        m_minNumber->setPosition(cursor);
        cursor.x += m_minNumber->getNumberFontWidth() + m_minSeparatorInterval;
        
        m_iconMin->setPosition(cursor);
        cursor.x += m_minSeparatorInterval;
    }
    
    // Sec
    m_secNumber->setPosition(cursor);
}












































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


