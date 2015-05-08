
#include "YHLanguageManager.h"

using namespace cocos2d;

YHLanguageManager::YHLanguageManager()
{
    m_dict = new cocos2d::CCDictionary();
    m_dict->init();
}

YHLanguageManager::~YHLanguageManager()
{
    CC_SAFE_RELEASE_NULL(m_dict);
}

YHLanguageManager * YHLanguageManager::sharedManager()
{
	static YHLanguageManager s_instance;
	return &s_instance;
}

void YHLanguageManager::addTexts(cocos2d::CCDictionary * dict)
{
    CCDictElement * e = nullptr;
    CCDICT_FOREACH(dict, e)
    {
        m_dict->setObject(e->getObject(), e->getStrKey());
    }
}

std::string YHLanguageManager::textForKey(const char * key)
{
    return textForKey(std::string(key));
}

std::string YHLanguageManager::textForKey(const std::string & key)
{
    CCObject * str = m_dict->objectForKey(key);
    if (str != nullptr)
    {
        return ((CCString *)str)->getCString();
    }
    else
    {
        return key;
    }
}


