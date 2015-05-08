//
//  YHDevice-Windows.h
//  MGBX
//
//  Created by Zhenyu Yao on 14-7-5.
//
//

#ifndef __MGBX__YHDevice_Windows__
#define __MGBX__YHDevice_Windows__

#include "YHDevice.h"

/**
 * Windows 平台设备
 * @author Zhenyu Yao
 */
class YHDevice_Windows : public YHDevice
{
public:
	
	YHDevice_Windows() {}
	virtual ~YHDevice_Windows() {}
	
	virtual std::string deviceIdentifier() override;
	virtual std::string osVersion() override;
	virtual std::string platform() override;
    virtual bool isJailBrokeDevice() override;
};

#endif /* defined(__MGBX__YHDevice_Windows__) */














































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


