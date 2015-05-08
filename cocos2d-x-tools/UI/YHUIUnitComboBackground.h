#ifndef __AndroidaBoom_YHUIUnitComboBackground__
#define __AndroidaBoom_YHUIUnitComboBackground__

#include "cocos2d.h"

/**
 * 单元图形组成背景生成
 * @author wangtiwei
 */
class YHUIUnitComboBackground : public cocos2d::Sprite
{
public:
	YHUIUnitComboBackground(void);
	virtual ~YHUIUnitComboBackground(void);
	
	/**
	 * 初始化
	 * @param frameName 该单元图形的 spriteFrame 名字
	 * @param 背景的大小
	 * @return YHUIUnitComboBackground 对象
	 */
	bool initWithUnitFrameNameAndSize(const char* frameName, cocos2d::CCSize size);
	
	/**
	 * 创建 YHUIUnitComboBackground 对象
	 * @param frameName 该单元图形的 spriteFrame 名字
	 * @param 背景的大小
	 * @return YHUIUnitComboBackground 对象
	 */
	static YHUIUnitComboBackground* createWithUnitFrameNameAndSize(const char* frameName, cocos2d::CCSize size);
};

#endif /*__AndroidaBoom_YHUIUnitComboBackground__*/
