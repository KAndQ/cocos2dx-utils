//
//  YHDevice-Android.h
//  MGBX
//
//  Created by Zhenyu Yao on 14-7-5.
//
//

#ifndef __MGBX__YHDevice_Android__
#define __MGBX__YHDevice_Android__

#include "YHDevice.h"

/**
 * Android 平台设备
 * @author Zhenyu Yao
 */
class YHDevice_Android : public YHDevice
{
public:
	
	YHDevice_Android() {}
	virtual ~YHDevice_Android() {}
	
	virtual std::string deviceIdentifier() override;
	virtual std::string osVersion() override;
	virtual std::string platform() override;
    virtual bool isJailBrokeDevice() override;
};

#endif /* defined(__MGBX__YHDevice_Android__) */














































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


