//
//  YHDevice.cpp
//  MonsterHunter
//
//  Created by Zhenyu Yao on 14-1-9.
//
//

#include "YHDevice.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "YHDevice-Android.h"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "YHDevice-iOS.h"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
#include "YHDevice-Mac.h"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include "YHDevice-Windows.h"
#endif

static YHDevice * s_instance = NULL;

YHDevice * YHDevice::sharedInstance()
{
	if (s_instance == NULL)
    {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        s_instance = new YHDevice_Android();
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        s_instance = new YHDevice_iOS();
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
        s_instance = new YHDevice_Mac();
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
		s_instance = new YHDevice_Windows();
#endif
    }
		
	return s_instance;
}










































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


