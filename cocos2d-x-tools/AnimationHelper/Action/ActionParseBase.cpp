//
//  ActionParseBase.cpp
//  cocos2d-x-Utils
//
//  Created by mac on 13-6-18.
//
//

#include "ActionParseBase.h"
#include "ActionContext.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
// Public Functions
////////////////////////////////////////////////////////////////////////////////////////////////////

CCPoint ActionParseBase::pointWithContentScale(const CCPoint & point, float scale)
{
    if (scale == 0.0f)
    {
        float contentScale = Director::getInstance()->getContentScaleFactor();
        return ccp(point.x / contentScale, point.y / contentScale);
    }
    else
    {
        return ccp(point.x * scale, point.y * scale);
    }
}

float ActionParseBase::floatWithContentScale(float value, float scale)
{
    if (scale == 0.0f)
    {
        return value / Director::getInstance()->getContentScaleFactor();
    }
    else
    {
        return value * scale;
    }
}

