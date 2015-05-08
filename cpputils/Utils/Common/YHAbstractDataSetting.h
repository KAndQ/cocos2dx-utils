//
//  YHAbstractDataSetting.h
//  MonsterHunter
//
//  Created by Zhenyu Yao on 14-1-9.
//
//

#ifndef __MonsterHunter__YHAbstractDataSetting__
#define __MonsterHunter__YHAbstractDataSetting__

#include "YHTypes.h"

/**
 * 配置数据的抽象类
 * @author Zhenyu Yao
 */
class YHAbstractDataSetting : public YHObject
{
public:
	
	YHAbstractDataSetting() : m_dict(NULL)
	{
	}
	
	virtual ~YHAbstractDataSetting()
	{
		CC_SAFE_RELEASE_NULL(m_dict);
	}
	
	virtual bool init(cocos2d::CCDictionary * dict)
	{
		m_dict = dict;
		CC_SAFE_RETAIN(m_dict);
		return true;
	}
	
	CC_SYNTHESIZE_RETAIN(cocos2d::CCDictionary *, m_dict, Dict);
	
};

#endif /* defined(__MonsterHunter__YHAbstractDataSetting__) */














































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


