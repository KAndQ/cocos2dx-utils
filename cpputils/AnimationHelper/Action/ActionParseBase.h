//
//  ActionParseBase.h
//  cocos2d-x-Utils
//
//  Created by mac on 13-6-18.
//
//

#ifndef __cocos2d_x_Utils__ActionParseBase__
#define __cocos2d_x_Utils__ActionParseBase__

#include <iostream>
#include "cocos2d.h"
#include "YHTypes.h"

using namespace cocos2d;

class ActionParseBase
{
public:
    
    /// 解析, 生成 CCAction 对象
    virtual CCAction* parseAction(CCDictionary* dict) = 0;
	
    /// 转换 CCPoint
    static CCPoint pointWithContentScale(const CCPoint & point, float scale = 0.0f);
    
    /// 转换 float
    static float floatWithContentScale(float value, float scale = 0.0f);
    
	virtual ~ActionParseBase(){}
};

#endif /* defined(__cocos2d_x_Utils__ActionParseBase__) */
