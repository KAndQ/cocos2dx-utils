//
//  YHJsonHelper.h
//  MonsterHunter
//
//  Created by Zhenyu Yao on 14-1-9.
//
//

#ifndef __MonsterHunter__YHDictionaryHelper__
#define __MonsterHunter__YHDictionaryHelper__

#include "YHTypes.h"

#if (ENABLED_JSONCPP)

#include "libs/jsoncpp/include/json/json.h"

/// Json -> CCDictionary
extern cocos2d::CCDictionary * dictionaryFromJson(const Json::Value & root);

/// Json -> CCArray
extern cocos2d::CCArray * arrayFromJson(const Json::Value & root);

/// CCDictionary -> Json
extern Json::Value jsonFromDictionary(cocos2d::CCDictionary * root);

/// CCArray -> Json
extern Json::Value jsonFromArray(cocos2d::CCArray * root);

/// json -> std::vector
extern std::vector<std::string> STDVectorFromJson(const Json::Value & root);

/// cocos2d::CCArray -> std::vector
extern std::vector<std::string> STDVectorFromArray(cocos2d::CCArray * root);

/// std::vector -> json
extern Json::Value jsonFromSTDVector(const std::vector<std::string> & root);

/// json -> cocos2d::Vector
extern cocos2d::Vector<cocos2d::CCObject *> cocos2dVectorFromJson(const Json::Value & root);

/// cocos2d::Vector -> json
extern Json::Value jsonFromCocos2dVector(const cocos2d::Vector<cocos2d::CCObject *> & root);

/// json -> cocos2d::Map
extern cocos2d::Map<std::string, cocos2d::CCObject *> cocos2dMapFromJson(const Json::Value & root);

/// cocos2d::Map -> json
extern Json::Value jsonFromCocos2dMap(const cocos2d::Map<std::string, cocos2d::CCObject *> & root);

/// Json 描述字符串中的双引号转换为单引号
extern void jsonReplaceQuotes(std::string & origin, char to, char from);

/// 双引号转单引号
extern void jsonDoubleToSingleQuotes(std::string & origin);

/// 单引号转双引号
extern void jsonSingleToDoubleQuotes(std::string & origin);

#endif // ENABLED_JSONCPP

/// cocos2d::CCDictionary -> cocos2d::ValueMap
extern cocos2d::ValueMap valueMapFromDictionary(cocos2d::CCDictionary * root);

/// cocos2d::CCArray -> cocos2d::ValueVector
extern cocos2d::ValueVector valueVectorFromArray(cocos2d::CCArray * root);

#endif /* defined(__MonsterHunter__YHJsonHelper__) */














































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


