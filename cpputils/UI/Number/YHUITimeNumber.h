
#ifndef YHUITimeNumber_h__
#define YHUITimeNumber_h__

#include "YHUISpriteNumber.h"

/**
 * 时间格式的数字显示, 显示的格式为 hh:mm:ss
 * @author Zhenyu Yao
 */
class YHUITimeNumber : public cocos2d::Sprite
{
public:
	YHUITimeNumber(void);
	virtual ~YHUITimeNumber(void);
	
	float contentWidth();
	
	/// 以秒数设置显示时间
	void setTimeWithSecond(uint32 second, bool zerofill = false);
	
	/// 以毫秒数显示时间
	void setTimeWithMilliSecond(uint32 milliSecond, bool zerofill = false);
    
    /// 设置 Icon
    void setIcon(cocos2d::CCSprite * icon);
    
    /// 设置 Icon 与数据的间距
    void setIconInterval(float32 interval);
    
    /// 设置 Icon 和 IconInterval
    void setIconAndInterval(cocos2d::CCSprite * icon, float32 interval);
    
    /// 布局格式
    void setAlignType(YHSpriteNumber_AlignType alignType);
	
    /// 设置 时 的可见
    void setHourVisible(bool visible);
    
    /// 设置 分 的可见
    void setMinVisible(bool visible);
    
	/**
	 * 初始化
	 * @param iconHour 小时的分隔符
	 * @param hourInterval 与小时分隔符之间的间隔
	 * @param iconMin 分钟的分隔符
	 * @param minInterval 与分钟分隔符之间的间隔
	 * @param fontName 数字的显示文件
	 * @param fontSize 数字的大小
	 * @param fontInterval 数字之间的间距
	 * @author Zhenyu Yao
	 */
	bool init(cocos2d::CCSprite * iconHour, float hourInterval,
			  cocos2d::CCSprite * iconMin, float minInterval,
			  const std::string & fontName, const cocos2d::CCSize & fontSize,
			  float fontInterval);
	
	/**
	 * 生成 TimeNumber 对象
	 * @param iconHour 小时的分隔符
	 * @param hourInterval 与小时分隔符之间的间隔
	 * @param iconMin 分钟的分隔符
	 * @param minInterval 与分钟分隔符之间的间隔
	 * @param fontName 数字的显示文件
	 * @param fontSize 数字的大小
	 * @param fontInterval 数字之间的间距
	 * @return TimeNumber 对象
	 * @author Zhenyu Yao
	 */
	static YHUITimeNumber* create(cocos2d::CCSprite * iconHour, float hourInterval,
                                  cocos2d::CCSprite * iconMin, float minInterval,
                                  const std::string & fontName, const cocos2d::CCSize & fontSize,
                                  float fontInterval);
	
private:
    
    /// 重新排列布局
    void layout();
	
private:
    
    cocos2d::CCSize m_fontSize;
    YHSpriteNumber_AlignType m_alignType = YHSpriteNumber_AlignType::kAlignType_Center;
    
    cocos2d::CCSprite * m_icon = nullptr;
    float32 m_iconInterval = 0.0f;
    
	cocos2d::CCSprite * m_iconHour;
	cocos2d::CCSprite * m_iconMin;
	
	float m_hourSeparatorInterval;
	float m_minSeparatorInterval;
	
	YHUISpriteNumber * m_hourNumber;
	YHUISpriteNumber * m_minNumber;
	YHUISpriteNumber * m_secNumber;
};

#endif // YHUITimeNumber_h__

