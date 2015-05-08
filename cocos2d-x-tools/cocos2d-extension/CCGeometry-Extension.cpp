//
//  CCGeometry-Extension.cpp
//  MGBX
//
//  Created by Zhenyu Yao on 14-3-27.
//  Copyright (c) 2014年 Mog Gen. All rights reserved.
//

#include "CCGeometry-Extension.h"

USING_NS_CC;

bool containsRect(const cocos2d::Rect & rect1, const cocos2d::Rect & rect2)
{
    return rect1.containsPoint(Point(rect2.getMinX(), rect2.getMinY()))
        && rect1.containsPoint(Point(rect2.getMaxX(), rect2.getMinY()))
        && rect1.containsPoint(Point(rect2.getMaxX(), rect2.getMaxY()))
        && rect1.containsPoint(Point(rect2.getMinX(), rect2.getMaxY()));
}












































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


