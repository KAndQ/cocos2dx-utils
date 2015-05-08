//
//  YHGameBasicInfo-iOS.mm
//  MGBX
//
//  Created by Zhenyu Yao on 14-3-17.
//  Copyright (c) 2014年 Mog Gen. All rights reserved.
//

#include "YHGameBasicInfo-iOS.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
// Override Functions
////////////////////////////////////////////////////////////////////////////////////////////////////

bool YHGameBasicInfo_iOS::init()
{
    NSDictionary * infoDict =[[NSBundle mainBundle] infoDictionary];
    m_version = [[infoDict objectForKey:@"CFBundleVersion"] cStringUsingEncoding:NSUTF8StringEncoding];
    m_name = [[infoDict objectForKey:@"CFBundleDisplayName"] cStringUsingEncoding:NSUTF8StringEncoding];
    return true;
}

std::string YHGameBasicInfo_iOS::version()
{
    return m_version;
}

std::string YHGameBasicInfo_iOS::name()
{
    return m_name;
}












































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


