//
//  YHDevice-Android.cpp
//  MGBX
//
//  Created by Zhenyu Yao on 14-7-5.
//
//

#include "YHDevice-Android.h"

std::string YHDevice_Android::deviceIdentifier()
{
    return "MGBX-Android";
}

std::string YHDevice_Android::osVersion()
{
    return "1.0.0";
}

std::string YHDevice_Android::platform()
{
    return "Android";
}

bool YHDevice_Android::isJailBrokeDevice()
{
    return false;
}










































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


