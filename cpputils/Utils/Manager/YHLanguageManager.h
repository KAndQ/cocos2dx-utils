
#ifndef __YHLanguageManager_H__
#define __YHLanguageManager_H__

#include "YHTypes.h"

/**
 * 语言管理器. 类似字典的功能, 输入键, 查询到键对应的字符串信息. 在初始化的使用装载供查询的配置文件.
 * @author Zhenyu Yao
 */
class YHLanguageManager : public YHObject
{
public:
	
    YHLanguageManager();
	virtual ~YHLanguageManager();
    
    /// YHLanguageManager 对象
    static YHLanguageManager * sharedManager();
    
    /// 添加文本
    void addTexts(cocos2d::CCDictionary * dict);
	
	/// 查询 key 对应的字符串
    std::string	textForKey(const char * key);
    
    /// 查询 key 对应的字符串
    std::string textForKey(const std::string & key);
	
private:
	cocos2d::CCDictionary * m_dict = nullptr;
};

#endif // __YHLanguageManager_H__


