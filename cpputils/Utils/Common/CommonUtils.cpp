//
//  CommonUtils.cpp
//  AndroidaBooM
//
//  Created by Zhenyu Yao on 13-4-12.
//
//

#include <stdio.h>
#include <sstream>
#include <math.h>
#include <ctype.h>
#include "CommonUtils.h"

using namespace std;

float PTM_RATIO = 32;

////////////////////////////////////////////////////////////////////////////////////////////////////
// 一些常用功能
////////////////////////////////////////////////////////////////////////////////////////////////////

float32 floatValueFromDictionary(CCDictionary * dict, const string & key)
{
	CCString * result = dynamic_cast<CCString *>(dict->objectForKey(key));
	if (result != NULL)
	{
		return result->floatValue();
	}
	else
	{
		return 0.0f;
	}
}

int32 intValueFromDictionary(CCDictionary * dict, const string & key)
{
	CCString * result = dynamic_cast<CCString *>(dict->objectForKey(key));
	if (result != NULL)
	{
		return result->intValue();
	}
	else
	{
		return 0;
	}
}

uint32 uintValueFromDictionary(CCDictionary * dict, const string & key)
{
	CCString * result = dynamic_cast<CCString *>(dict->objectForKey(key));
	if (result != NULL)
	{
		return result->uintValue();
	}
	else
	{
		return 0;
	}
}

bool boolValueFromDictionary(CCDictionary * dict, const string & key)
{
	CCString * result = dynamic_cast<CCString *>(dict->objectForKey(key));
	if (result != NULL)
	{
		return result->boolValue();
	}
	else
	{
		return false;
	}
}

string stringValueFromDictionary(CCDictionary * dict, const string & key)
{
	CCString * result = dynamic_cast<CCString *>(dict->objectForKey(key));
	if (result != NULL)
	{
		return string(result->getCString());
	}
	else
	{
		return string();
	}
}

void tintAllSprite(CCNode * root, const ccColor4B & color)
{
    Vector<CCNode *>::const_iterator beg = root->getChildren().begin();
    Vector<CCNode *>::const_iterator end = root->getChildren().end();
    for (; beg != end; ++beg)
    {
        CCNode * child = (CCNode *)*beg;
        tintAllSprite(child, color);
    }
	
	if (dynamic_cast<CCRGBAProtocol *>(root) != NULL)
	{
		CCRGBAProtocol * p = dynamic_cast<CCRGBAProtocol *>(root);
		p->setColor(ccc3(color.r, color.g, color.b));
		p->setOpacity(color.a);
	}
}

void pauseAll(cocos2d::CCNode* node)
{
    Vector<CCNode *>::const_iterator beg = node->getChildren().begin();
    Vector<CCNode *>::const_iterator end = node->getChildren().end();
    for (; beg != end; ++beg)
    {
        CCNode * child = (CCNode *)*beg;
        pauseAll(child);
    }
    
    node->pause();
}

void resumeAll(cocos2d::CCNode* node)
{
    Vector<CCNode *>::const_iterator beg = node->getChildren().begin();
    Vector<CCNode *>::const_iterator end = node->getChildren().end();
    for (; beg != end; ++beg)
    {
        CCNode * child = (CCNode *)*beg;
        resumeAll(child);
    }
	
    node->resume();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// 几何/数学
////////////////////////////////////////////////////////////////////////////////////////////////////

float convertRadianToDegree(float radian)
{
	return radian / M_PI * 180.0f;
}

float convertDegreeToRadian(float degree)
{
	return degree / 180.0f * M_PI;
}

#if (ENABLED_BOX2D)

CCPoint pointFromVec(const b2Vec2 & vec)
{
	return ccp(vec.x, vec.y);
}

b2Vec2 vecFromPoint(const CCPoint & point)
{
	return b2Vec2(point.x, point.y);
}

CCPoint pointFromVec_meter(const b2Vec2 & vec)
{
	return ccp(vec.x * PTM_RATIO, vec.y * PTM_RATIO);
}

b2Vec2 vecFromPoint_meter(const CCPoint & point)
{
	return b2Vec2(point.x / PTM_RATIO, point.y / PTM_RATIO);
}

#endif // ENABLED_BOX2D

float pointFromMeter(float meterUnit)
{
	return meterUnit * PTM_RATIO;
}

float meterFromPoint(float pointUnit)
{
	return pointUnit / PTM_RATIO;
}

bool CCRectContainsRect(cocos2d::CCRect& rect1, cocos2d::CCRect& rect2)
{
	if ((rect2.origin.x - rect1.origin.x <= rect1.size.width - rect2.size.width)
		&&rect2.origin.x >= rect1.origin.x
		&&rect2.origin.y >= rect1.origin.y
		&& (rect2.origin.y - rect1.origin.y <  rect1.size.height - rect2.size.height))
	{
		return true;
	}
	return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// 分辨率处理
////////////////////////////////////////////////////////////////////////////////////////////////////

void adapterLandscapeResolution(float contentScale)
{
	CCDirector * pDirector = CCDirector::sharedDirector();
	
	// 屏幕适配
	CCSize designSize = pDirector->getWinSize();
	if ((designSize.width == 960 && designSize.height == 640)			// iPhone4, 4S, iPod4
		|| (designSize.width == 1136 && designSize.height == 640)		// iPhone5, iPod5
		|| (designSize.width == 1024 && designSize.height == 768))		// iPad1,2, iPad mini
	{
//		designSize.width /= contentScale;
//		designSize.height /= contentScale;
        
        designSize.width = 960 / contentScale;
		designSize.height = 640 / contentScale;
	}
	else if (designSize.width == 2048 && designSize.height == 1536)		// iPad3
	{
//		designSize.width /= contentScale * 2.0f;
//		designSize.height /= contentScale * 2.0f;
        
        designSize.width = 960 / contentScale;
		designSize.height = 640 / contentScale;
	}
	else																// 其他分辨率 & iPhone3GS
	{
		designSize.width = 960 / contentScale;
		designSize.height = 640 / contentScale;
	}
	
	pDirector->setContentScaleFactor(contentScale);
//	pDirector->getOpenGLView()->setDesignResolutionSize(designSize.width, designSize.height, kResolutionFixedHeight);
    pDirector->getOpenGLView()->setDesignResolutionSize(designSize.width, designSize.height, ResolutionPolicy::SHOW_ALL);
}

void adapterPortraitResolution(float contentScale)
{
	CCDirector * pDirector = CCDirector::sharedDirector();
	
	CCSize designSize = pDirector->getWinSize();
	if ((designSize.width == 640 && designSize.height == 960)
		|| (designSize.width == 640 && designSize.height == 1136)
		|| (designSize.width == 768 && designSize.height == 1024))
	{
		designSize.width /= contentScale;
		designSize.height /= contentScale;
	}
	else if (designSize.width == 1536 && designSize.height == 2048)
	{
		designSize.width /= contentScale * 2.0f;
		designSize.height /= contentScale * 2.0f;
	}
	else
	{
		designSize.width = 640 / contentScale;
		designSize.height = 960 / contentScale;
	}
	
	pDirector->setContentScaleFactor(contentScale);
	pDirector->getOpenGLView()->setDesignResolutionSize(designSize.width, designSize.height, kResolutionFixedHeight);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// 字符串处理
////////////////////////////////////////////////////////////////////////////////////////////////////

string int32ToString(int32 value)
{
	char str[32] = {0};
	sprintf(str, "%d", value);
	return string(str);
}

string uint32ToString(uint32 value)
{
	char str[32] = {0};
	sprintf(str, "%u", value);
	return string(str);
}

string uint64ToString(uint64 value)
{
	char str[32] = {0};
	sprintf(str, "%llu", value);
	return string(str);
}

string float32ToString(float32 value)
{
	char str[32] = {0};
	sprintf(str, "%f", value);
	return string(str);
}

string boolToString(bool value)
{
    if (value)
        return string("true");
    else
        return string("false");
}

int32 int32FromString(const std::string & value)
{
    if (value.empty())
        return 0;
    
	istringstream iss(value);
	int32 number;
	iss >> number;
	return number;
}

uint32 uint32FromString(const std::string & value)
{
    if (value.empty())
        return 0;
    
	istringstream iss(value);
	uint32 number;
	iss >> number;
	return number;
}

uint64 uint64FromString(const std::string & value)
{
    if (value.empty())
        return 0;
    
	istringstream iss(value);
	uint64 number;
	iss >> number;
	return number;
}

float32 float32FromString(const std::string & value)
{
    if (value.empty())
        return 0.0f;
    
	istringstream iss(value);
	float32 number;
	iss >> number;
	return number;
}

bool boolFromString(const std::string & value)
{
    std::string tmp = value;
    asciiToLower(tmp);
    
    if (tmp == "false" || tmp == "no" || tmp == "0")
        return false;
    
    return true;
}

void asciiToLower(std::string & origin)
{
    for (size_t i = 0; i < origin.length(); ++i)
        origin[i] = tolower(origin[i]);
}

void asciiToUpper(std::string & origin)
{
    for (size_t i = 0; i < origin.length(); ++i)
        origin[i] = toupper(origin[i]);
}

void slitStringBySeperator(const string & origin, vector<string> & others, const string & seperator)
{
	size_t beg = 0;
	size_t end = 0;
	size_t originLen = origin.length();
	size_t seperatorLen = seperator.length();
	
	while (beg < originLen)
	{
		end = origin.find(seperator, beg);
		
		// 如果起始位置与终止位置在同一个地方, 那么将不记录字符串, 因为不存在截断的字符串.
		if (beg != end)
		{
			if (end == string::npos)
			{
				// 如果 (beg == 0 && end == string::npos), 那么表示的是没有搜索到分割符, 那么将不分离各个字符串.
				// 而下面的代码表示的是, 从当前位置切割字符串, 直到字符串末尾.
				if (beg != 0)
				{
					others.push_back(origin.substr(beg, end));
				}
				break;
			}
			else
			{
				others.push_back(origin.substr(beg, end - beg));
			}
		}
		
		beg = end + seperatorLen;
	}
}

string trimCharacterFromLast(const std::string & origin, char chTrim)
{
	for (size_t i = origin.length() - 1; i < 0xffffffff; --i)
	{
		if (origin[i] != chTrim)
		{
			return origin.substr(0, i + 1);
		}
	}
	
	static string s_reuslt("");
	return s_reuslt;
}

string subStringWithCharacterFromHead(const std::string& origin, char chSign)
{
	size_t pos = origin.rfind(chSign);
    
    if (pos == string::npos)
        return origin;
    
	return origin.substr(0,pos);
}

string subStringWithCharacterFromLast(const std::string& origin, char chSign)
{
	size_t pos = origin.rfind(chSign);
    
    if (pos == string::npos)
        return origin;
    
	return origin.substr(pos + 1);
}

string stringByDeletingPathExtension(const std::string & origin)
{
	size_t pos = origin.rfind(".");
	return origin.substr(0, pos);
}

string stringByAppendingPathExtension(const std::string & origin, const std::string & extension)
{
	return origin + "." + extension;
}

string pathExtensionWithString(const std::string & file)
{
	size_t pos = file.rfind(".");
	
	if (pos == string::npos)
		return "";
	
	if (pos == file.length() - 1)
		return "";
	
	return file.substr(pos + 1);
}













































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


