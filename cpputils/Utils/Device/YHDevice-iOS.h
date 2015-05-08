//
//  YHDevice-iOS.h
//  MonsterHunter
//
//  Created by Zhenyu Yao on 14-1-9.
//
//

#ifndef __MonsterHunter__YHDevice_iOS__
#define __MonsterHunter__YHDevice_iOS__

#include "YHDevice.h"

/**
 * iOS 平台设备
 * @author Zhenyu Yao
 */
class YHDevice_iOS : public YHDevice
{
public:
	
	YHDevice_iOS() {}
	virtual ~YHDevice_iOS() {}
	
	virtual std::string deviceIdentifier() override;
	virtual std::string osVersion() override;
	virtual std::string platform() override;
    virtual bool isJailBrokeDevice() override;
};

#endif /* defined(__MonsterHunter__YHDevice_iOS__) */














































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


