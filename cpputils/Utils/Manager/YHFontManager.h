
#ifndef __YHFontManager_H__
#define __YHFontManager_H__

#include "YHTypes.h"

using namespace cocos2d;

/**
 * 字体管理类
 * @author Zhenyu Yao
 */
class YHFontManager : public YHObject
{
public:
	
    YHFontManager();
	virtual ~YHFontManager();
    
	/// 单例模式, 获得唯一的 YHFontManager 对象
	static YHFontManager *	defaultFontManager();
	
    /// 添加字典
	void                    addFonts(cocos2d::CCDictionary * dict);
	
	/// 获得字体的名字
    std::string             fontNameForKey(const char * key);
    
    /// 获得字体的名字
    std::string             fontNameForKey(const std::string & key);
	
private:
	CCDictionary *			m_dict = nullptr;
};

#endif // __YHFontManager_H__


