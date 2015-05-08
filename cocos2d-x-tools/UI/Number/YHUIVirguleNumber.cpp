
#include "YHUIVirguleNumber.h"
#include "YHUISpriteNumber.h"

USING_NS_CC;

YHUIVirguleNumber::~YHUIVirguleNumber()
{
    this->cleanup();
}

bool YHUIVirguleNumber::init(const std::string & fontName, const cocos2d::CCSize fontSize,
                             float32 fontInterval, cocos2d::Sprite * virgule)
{
    bool result = CCSpecialSprite::init();
    
    if (result)
    {
        m_lNumber = YHUISpriteNumber::create(fontName.c_str(), fontSize, fontInterval);
        m_rNumber = YHUISpriteNumber::create(fontName.c_str(), fontSize, fontInterval);
        this->addChild(m_lNumber);
        this->addChild(m_rNumber);
        
        assert(virgule != nullptr);
        m_virgule = virgule;
        this->addChild(m_virgule);
    }
    
    return result;
}

void YHUIVirguleNumber::setLNumber(uint32 number)
{
    m_lNumber->setNumber(number);
    realign();
}

void YHUIVirguleNumber::setLNumber(const std::string & number)
{
    m_lNumber->setNumber(number);
    realign();
}

void YHUIVirguleNumber::setRNumber(uint32 number)
{
    m_rNumber->setNumber(number);
    realign();
}

void YHUIVirguleNumber::setRNumber(const std::string & number)
{
    m_rNumber->setNumber(number);
    realign();
}

void YHUIVirguleNumber::setLRNumber(uint32 lNumber, uint32 rNumber)
{
    m_lNumber->setNumber(lNumber);
    m_rNumber->setNumber(rNumber);
    realign();
}

void YHUIVirguleNumber::setLRNumber(const std::string & lNumber, const std::string & rNumber)
{
    m_lNumber->setNumber(lNumber);
    m_rNumber->setNumber(rNumber);
    realign();
}

void YHUIVirguleNumber::setVirguleInterval(float32 interval)
{
    m_virguleInterval = interval;
    realign();
}

void YHUIVirguleNumber::setAlignType(YHSpriteNumber_AlignType alignType)
{
    m_alignType = alignType;
    realign();
}

void YHUIVirguleNumber::setIcon(cocos2d::Sprite * icon)
{
    if (m_icon != nullptr)
    {
        m_icon->removeFromParentAndCleanup(true);
        m_icon = nullptr;
    }
    
    m_icon = icon;
    
    if (m_icon != nullptr)
    {
        this->addChild(icon);
    }
    
    realign();
}

void YHUIVirguleNumber::setIconInterval(float32 iconInterval)
{
    m_iconInterval = iconInterval;
    realign();
}

void YHUIVirguleNumber::setIconAndInterval(cocos2d::Sprite * icon, float32 iconInterval)
{
    if (m_icon != nullptr)
    {
        m_icon->removeFromParentAndCleanup(true);
        m_icon = nullptr;
    }
    
    m_icon = icon;
    
    if (m_icon != nullptr)
    {
        this->addChild(icon);
    }
    
    m_iconInterval = iconInterval;
    
    realign();
}

void YHUIVirguleNumber::setVirgule(cocos2d::Sprite * virgule)
{
    assert(virgule != nullptr);
    
    if (m_virgule != nullptr)
    {
        m_virgule->removeFromParentAndCleanup(true);
        m_virgule = nullptr;
    }
    
    m_virgule = virgule;
    this->addChild(m_virgule);
    
    realign();
}

Sprite * YHUIVirguleNumber::getLNumberSprite() const
{
    return m_lNumber;
}

Sprite * YHUIVirguleNumber::getRNumberSprite() const
{
    return m_rNumber;
}

float32 YHUIVirguleNumber::getNumberFontWidth()
{
    /**
     * icon lNumber / rNumber -> icon + iconInterval + lNumber + virguleInterval + virguleInterval + rNumber
     */
    
    float32 width = m_lNumber->getNumberFontWidth();
    width += m_virguleInterval * 2.0f;
    width += m_rNumber->getNumberFontWidth();
    
    if (m_icon != nullptr)
    {
        width += m_icon->getContentSize().width * m_icon->getAnchorPoint().x;
        width += m_iconInterval;
    }
    
    return width;
}

void YHUIVirguleNumber::realign()
{
    float32 begin = 0.0f;
    float32 width = getNumberFontWidth();
    
    if (m_icon != nullptr)
    {
        begin += m_icon->getContentSize().width * m_icon->getAnchorPoint().x;
    }
    
    switch (m_alignType)
    {
        case YHSpriteNumber_AlignType::kAlignType_Left:
            break;
            
        case YHSpriteNumber_AlignType::kAlignType_Center:
            begin -= width * 0.5f;
            break;
            
        case YHSpriteNumber_AlignType::kAlignType_Right:
            begin -= width;
            break;
    }
    
    if (m_icon != nullptr)
    {
        m_icon->setPosition(begin, 0.0f);
        begin += m_iconInterval;
    }
    
    m_lNumber->setPosition(begin, 0.0f);
    begin += m_lNumber->getNumberFontWidth() + m_virguleInterval;
    m_virgule->setPosition(begin, 0.0f);
    begin += m_virguleInterval;
    m_rNumber->setPosition(begin, 0.0f);
}





















































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


