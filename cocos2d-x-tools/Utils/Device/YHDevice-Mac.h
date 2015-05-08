//
//  YHDevice-Mac.h
//  mgbx-client
//
//  Created by Zhenyu Yao on 14-9-22.
//
//

#ifndef __mgbx_client__YHDevice_Mac__
#define __mgbx_client__YHDevice_Mac__

#include "YHDevice.h"

/**
 * Mac 平台设备
 * @author Zhenyu Yao
 */
class YHDevice_Mac : public YHDevice
{
public:
    
    YHDevice_Mac() {}
    virtual ~YHDevice_Mac() {}
    
    virtual std::string deviceIdentifier() override;
    virtual std::string osVersion() override;
    virtual std::string platform() override;
    virtual bool isJailBrokeDevice() override;
};

#endif /* defined(__mgbx_client__YHDevice_Mac__) */
