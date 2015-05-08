//
//  YHGameBasicInfo-iOS.h
//  MGBX
//
//  Created by Zhenyu Yao on 14-3-17.
//  Copyright (c) 2014年 Mog Gen. All rights reserved.
//

#ifndef __MGBX__YHGameBasicInfo_iOS__
#define __MGBX__YHGameBasicInfo_iOS__

#include "YHGameBasicInfo.h"

/**
 * iOS 平台实现
 * @author Zhenyu Yao
 */
class YHGameBasicInfo_iOS : public YHGameBasicInfo
{
public:
    
    virtual bool init() override;
    virtual std::string version() override;
    virtual std::string name() override;
    
private:
    
    std::string m_version;
    std::string m_name;
};

#endif /* defined(__MGBX__YHGameBasicInfo_iOS__) */














































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


