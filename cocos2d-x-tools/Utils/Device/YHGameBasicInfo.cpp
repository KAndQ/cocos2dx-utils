//
//  YHGameBasicInfo.cpp
//  MGBX
//
//  Created by Zhenyu Yao on 14-3-17.
//  Copyright (c) 2014年 Mog Gen. All rights reserved.
//

#include "YHGameBasicInfo.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include "YHGameBasicInfo-Android.h"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
#include "YHGameBasicInfo-iOS.h"
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
// Public Functions
////////////////////////////////////////////////////////////////////////////////////////////////////

YHGameBasicInfo * YHGameBasicInfo::sharedInstance()
{
    static YHGameBasicInfo * s_instance = nullptr;
    if (s_instance == nullptr)
    {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
        s_instance = new YHGameBasicInfo_Android();
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
        s_instance = new YHGameBasicInfo_iOS();
#endif
        s_instance->init();
    }
    
    return s_instance;
}












































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


