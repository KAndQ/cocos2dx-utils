//
//  YHDevice-Mac.mm
//  mgbx-client
//
//  Created by Zhenyu Yao on 14-9-22.
//
//

#include "YHDevice-Mac.h"

using namespace std;

string YHDevice_Mac::deviceIdentifier()
{
    static std::string s_identifier;
    
    if (s_identifier.empty())
    {
        io_service_t platformExpert = IOServiceGetMatchingService(kIOMasterPortDefault,IOServiceMatching("IOPlatformExpertDevice"));
        if (!platformExpert)
            return nil;
        
        CFTypeRef serialNumberAsCFString = IORegistryEntryCreateCFProperty(platformExpert,CFSTR(kIOPlatformUUIDKey),kCFAllocatorDefault, 0);
        IOObjectRelease(platformExpert);
        if (!serialNumberAsCFString)
            return nil;
        
        NSString * result = (NSString *)serialNumberAsCFString;
        s_identifier = [result cStringUsingEncoding:NSUTF8StringEncoding];
    }
    
    return s_identifier;
}

string YHDevice_Mac::osVersion()
{
    NSString * versionString = [[NSProcessInfo processInfo] operatingSystemVersionString];
    string version = [versionString cStringUsingEncoding:NSUTF8StringEncoding];
    return version;
}

string YHDevice_Mac::platform()
{
    return "iOS";
}

bool YHDevice_Mac::isJailBrokeDevice()
{
    return false;
}