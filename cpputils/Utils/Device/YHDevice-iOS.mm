//
//  YHDevice-iOS.mm
//  MonsterHunter
//
//  Created by Zhenyu Yao on 14-1-9.
//
//

#include "YHDevice-iOS.h"

using namespace std;

string YHDevice_iOS::deviceIdentifier()
{
    static std::string s_identifier;
    
    if (s_identifier.empty())
    {
        /*
         * 如果满足这样的条件，那么获取到的这个属性值就不会变：相同的一个程序里面-相同的vendor-相同的设备。
         * 如果是这样的情况，那么这个值是不会相同的：相同的程序-相同的设备-不同的vendor，或者是相同的程序-不同的设备-无论是否相同的vendor。
         *
         * 在这里，还需要注意的一点就是：如果用户卸载了同一个vendor对应的所有程序，然后在重新安装同一个vendor提供的程序，此时identifierForVendor会被重置。
         * 
         * 此外，即使在同一台设备上，使用同一个开发者帐户开发的程序，如果设备用户将该开发者帐户开发的所有应用删除，然后再进行安装，之后获得的identifierForVendor和删除应用前获得的identifierForVendor也是不同的。
         *
         * 对于advertisingIdentifier来讲，如果用户重置了设备，advertisingIdentifier会发生变化，此外，用户也可以在“设置”里对advertisingIdentifier进行手动重置。
         */
        NSUUID * uuid = [[UIDevice currentDevice] identifierForVendor];
        s_identifier = [[uuid UUIDString] cStringUsingEncoding:NSUTF8StringEncoding];
    }
    
    return s_identifier;
}

string YHDevice_iOS::osVersion()
{
	NSString * result = [[UIDevice currentDevice] systemVersion];
	return [result cStringUsingEncoding:NSUTF8StringEncoding];
}

string YHDevice_iOS::platform()
{
    return [[[UIDevice currentDevice] model] cStringUsingEncoding:NSUTF8StringEncoding];
}

bool YHDevice_iOS::isJailBrokeDevice()
{
    static const char* jailbreak_apps[] =
    {
        "/Applications/Cydia.app",
        "/Applications/blackra1n.app",
        "/Applications/blacksn0w.app",
        "/Applications/greenpois0n.app",
        "/Applications/limera1n.app",
        "/Applications/redsn0w.app",
        NULL,
    };
    
    for (int i = 0; jailbreak_apps[i] != NULL; ++i)
    {
        if ([[NSFileManager defaultManager] fileExistsAtPath:
             [NSString stringWithCString:jailbreak_apps[i] encoding:NSUTF8StringEncoding]])
        {
            return true;
        }
    }
    
    return false;
}












































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


