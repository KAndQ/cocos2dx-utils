#ifndef YHUIVirguleNumber_h__
#define YHUIVirguleNumber_h__

#include "cocos2d-extension/CCSpecialSprite.h"
#include "YHISpriteNumber.h"

class YHUISpriteNumber;

/**
 * 中间有斜线分割数字的数字贴图
 * @author Zhenyu Yao
 */
class YHUIVirguleNumber : public CCSpecialSprite
{
public:
    
	virtual ~YHUIVirguleNumber(void);
	
    /// 总宽度
	float32 getNumberFontWidth();
	
    /// 设置分子显示
    virtual void setLNumber(uint32 number);
    
    /// 设置分子显示
    virtual void setLNumber(const std::string & number);
    
    /// 设置分母显示
    virtual void setRNumber(uint32 number);
    
    /// 设置分母显示
    virtual void setRNumber(const std::string & number);
    
    /// 设置 LR 数字显示
    virtual void setLRNumber(uint32 lNumber, uint32 rNumber);
    
    /// 设置 LR 数字显示
    virtual void setLRNumber(const std::string & lNumber, const std::string & rNumber);
    
    /// 设置 / 符号与分子分母的距离
    virtual void setVirguleInterval(float32 interval);
    
    /// 设置对齐布局方式
    virtual void setAlignType(YHSpriteNumber_AlignType alignType);
    
    /// 设置 Icon
    virtual void setIcon(cocos2d::Sprite * icon);
    
    /// 设置 Icon 与 分子 的间距
    virtual void setIconInterval(float32 iconInterval);
    
    /// 设置 Icon 与其间距
    virtual void setIconAndInterval(cocos2d::Sprite * icon, float32 iconInterval);
    
    /// 设置 virgule
    virtual void setVirgule(cocos2d::Sprite * virgule);
    
    /// 返回 分子数字 显示对象
    virtual cocos2d::Sprite * getLNumberSprite() const;
    
    /// 返回 分母数字 显示对象
    virtual cocos2d::Sprite * getRNumberSprite() const;
    
    /**
     * 初始化
     * @param fontName 数字字体名字
     * @param fontSize 字体的大小
     * @param fontInterval 字体的间距
     * @param virgule 斜线显示对象
     */
	virtual bool init(const std::string & fontName, const cocos2d::CCSize fontSize,
                      float32 fontInterval, cocos2d::Sprite * virgule);
    
    /// 创建 YHUIVirguleNumber 对象
    static YHUIVirguleNumber * create(const std::string & fontName, const cocos2d::Size & fontSize,
                                      float32 fontInterval, cocos2d::Sprite * virgule)
	{
		YHUIVirguleNumber * instance = new YHUIVirguleNumber();
		if (instance != NULL && instance->init(fontName, fontSize, fontInterval, virgule))
		{
			instance->autorelease();
			return instance;
		}
		CC_SAFE_DELETE(instance);
		return NULL;
	}
	
private:
	
	/// 重新排列
	void realign();
	
private:
    
    float32 m_virguleInterval = 0.0f;
    YHSpriteNumber_AlignType m_alignType = YHSpriteNumber_AlignType::kAlignType_Left;
    cocos2d::Sprite * m_icon = nullptr;
    float32 m_iconInterval = 0.0f;
	cocos2d::Sprite * m_virgule = nullptr;
    YHUISpriteNumber * m_lNumber = nullptr;
    YHUISpriteNumber * m_rNumber = nullptr;
};
#endif // YHUIVirguleNumber_h__














































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


