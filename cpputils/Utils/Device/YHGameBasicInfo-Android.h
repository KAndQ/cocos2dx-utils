//
//  YHGameBasicInfo-Android.h
//  MGBX
//
//  Created by Zhenyu Yao on 14-7-5.
//
//

#ifndef __MGBX__YHGameBasicInfo_Android__
#define __MGBX__YHGameBasicInfo_Android__

#include "YHGameBasicInfo.h"

/**
 * Android 平台实现
 * @author Zhenyu Yao
 */
class YHGameBasicInfo_Android : public YHGameBasicInfo
{
public:
    
    YHGameBasicInfo_Android() {}
    virtual ~YHGameBasicInfo_Android() {}
    
    virtual bool init();
    virtual std::string version();
    virtual std::string name();
};

#endif /* defined(__MGBX__YHGameBasicInfo_Android__) */














































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


