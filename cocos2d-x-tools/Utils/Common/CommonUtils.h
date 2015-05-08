//
//  CommonUtils.h
//  AndroidaBooM
//
//  Created by Zhenyu Yao on 13-4-12.
//
//

#ifndef __AndroidaBooM__CommonUtils__
#define __AndroidaBooM__CommonUtils__

#include <string>
#include <vector>
#include "YHTypes.h"

using namespace cocos2d;

////////////////////////////////////////////////////////////////////////////////////////////////////
// 常量
////////////////////////////////////////////////////////////////////////////////////////////////////

/// cocos2d 坐标与 Box2D坐标 转化的系数
extern float PTM_RATIO;

////////////////////////////////////////////////////////////////////////////////////////////////////
// 宏
////////////////////////////////////////////////////////////////////////////////////////////////////

#define CCSPRITE_CREATED_SUCCESS_RETURN			effect->autorelease(); return effect;
#define CCSPRITE_CREATED_FAILED_RETURN			CC_SAFE_DELETE(effect); return effect;
#define CCSPRITE_CREATE_FUNCTIONS(__CLASS__) \
			static __CLASS__ * create() { __CLASS__ * effect = new __CLASS__(); \
			if (effect != NULL && effect->init()) { CCSPRITE_CREATED_SUCCESS_RETURN } \
			CCSPRITE_CREATED_FAILED_RETURN } \
			static __CLASS__ * create(const char * pszFileName) { __CLASS__ * effect = new __CLASS__(); \
			if (effect != NULL && effect->initWithFile(pszFileName)) { CCSPRITE_CREATED_SUCCESS_RETURN } \
			CCSPRITE_CREATED_FAILED_RETURN } \
			static __CLASS__ * create(const char * pszFileName, const CCRect & rect) { __CLASS__ * effect = new __CLASS__(); \
			if (effect != NULL && effect->initWithFile(pszFileName, rect)) { CCSPRITE_CREATED_SUCCESS_RETURN } \
			CCSPRITE_CREATED_FAILED_RETURN } \
			static __CLASS__ * createWithSpriteFrame(CCSpriteFrame * pSpriteFrame) { __CLASS__ * effect = new __CLASS__(); \
			if (effect != NULL && effect->initWithSpriteFrame(pSpriteFrame)) { CCSPRITE_CREATED_SUCCESS_RETURN } \
			CCSPRITE_CREATED_FAILED_RETURN } \
			static __CLASS__ * createWithSpriteFrameName(const char * pszSpriteFrameName) { __CLASS__ * effect = new __CLASS__(); \
			if (effect != NULL && effect->initWithSpriteFrameName(pszSpriteFrameName)) { CCSPRITE_CREATED_SUCCESS_RETURN } \
			CCSPRITE_CREATED_FAILED_RETURN } \
			static __CLASS__ * createWithTexture(CCTexture2D * pTexture) { __CLASS__ * effect = new __CLASS__(); \
			if (effect != NULL && effect->initWithTexture(pTexture)) { CCSPRITE_CREATED_SUCCESS_RETURN } \
			CCSPRITE_CREATED_FAILED_RETURN } \
			static __CLASS__ * createWithTexture(CCTexture2D * pTexture, const CCRect & rect) { __CLASS__ * effect = new __CLASS__(); \
			if (effect != NULL && effect->initWithTexture(pTexture, rect)) { CCSPRITE_CREATED_SUCCESS_RETURN } \
			CCSPRITE_CREATED_FAILED_RETURN }

////////////////////////////////////////////////////////////////////////////////////////////////////
// 一些常用功能
////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * CCLabelTTF 的基本参数
 * @author Zhenyu Yao
 */
class CCLabelTTFConfig
{
public:
	CCLabelTTFConfig() 
	{
		m_hAlignment = TextHAlignment::CENTER;
		m_vAlignment = TextVAlignment::CENTER;
		m_dimensions = cocos2d::CCSizeZero;
		m_fontSize = 12;
		m_fontName = "Default";
	}

	CCLabelTTFConfig(cocos2d::CCDictionary * dict)
	{
		cocos2d::CCString * strHA = dynamic_cast<cocos2d::CCString *>(dict->objectForKey("HAlignment"));
		m_hAlignment = strHA != NULL ? (cocos2d::CCTextAlignment)strHA->intValue() : cocos2d::kCCTextAlignmentCenter;
		
		cocos2d::CCString * strVA = dynamic_cast<cocos2d::CCString *>(dict->objectForKey("VAlignment"));
		m_vAlignment = strVA != NULL ? (cocos2d::CCVerticalTextAlignment)strVA->intValue() : cocos2d::kCCVerticalTextAlignmentCenter;
		
		cocos2d::CCString * strDimensions = dynamic_cast<cocos2d::CCString *>(dict->objectForKey("Dimensions"));
		m_dimensions = strDimensions != NULL ? cocos2d::SizeFromString(strDimensions->getCString()) : cocos2d::CCSizeZero;

		cocos2d::CCString * strFontSize = dynamic_cast<cocos2d::CCString *>(dict->objectForKey("FontSize"));
		m_fontSize = strFontSize->floatValue();

		m_fontName = std::string((dynamic_cast<cocos2d::CCString *>(dict->objectForKey("FontName")))->getCString());
	}

	~CCLabelTTFConfig() {}

	cocos2d::CCTextAlignment			getHAlignment() const { return m_hAlignment; }
	void								setHAlignment(cocos2d::CCTextAlignment hAlignment) { m_hAlignment = hAlignment; }
	
	cocos2d::CCVerticalTextAlignment	getVAlignment() const { return m_vAlignment; }
	void								setVAlignment(cocos2d::CCVerticalTextAlignment vAlignment) { m_vAlignment = vAlignment; }

	cocos2d::CCSize						getDimensions() const { return m_dimensions; }
	void								setDimensions(cocos2d::CCSize value) { m_dimensions = value; }

	float32								getFontSize() const { return m_fontSize; }
	void								setFontSize(float32 fontSize) { m_fontSize = fontSize; }

	const char *						getFontName() const { return m_fontName.c_str(); }
	void								setFontName(const std::string & value) { m_fontName = value; }

private:
	cocos2d::CCTextAlignment			m_hAlignment;
	cocos2d::CCVerticalTextAlignment	m_vAlignment;
	cocos2d::CCSize						m_dimensions;
	float32								m_fontSize;
	std::string							m_fontName;
};

/// 返回 dict 对象中 key 键对应的 Float 数值, 如果 key 键不存在, 返回 0
extern float32 floatValueFromDictionary(cocos2d::CCDictionary * dict, const std::string & key);

/// 返回 dict 对象中 key 键对应的 Int 数值, 如果 key 键不存在, 返回 0
extern int32 intValueFromDictionary(cocos2d::CCDictionary * dict, const std::string & key);

/// 返回 dict 对象中 key 键对应的 Unsigned int 数值, 如果 key 键不存在, 返回 0
extern uint32 uintValueFromDictionary(cocos2d::CCDictionary * dict, const std::string & key);

/// 返回 dict 对象中 key 键对应的 bool 数值, 如果 key 键不存在, 返回 false
extern bool boolValueFromDictionary(cocos2d::CCDictionary * dict, const std::string & key);

/// 返回 dict 对象中 key 键对应的 string 数值, 如果 key 键不存在, 返回的 string 为空字符串
extern std::string stringValueFromDictionary(cocos2d::CCDictionary * dict, const std::string & key);

/// 将 root 以下的所有实现 CCRGBAProtocol 的对象着色
extern void tintAllSprite(CCNode * root, const ccColor4B & color);

/// 暂停节点和所有子节点
extern void pauseAll(cocos2d::CCNode* node);

/// 恢复节点所有子节点
extern void resumeAll(cocos2d::CCNode* node);

////////////////////////////////////////////////////////////////////////////////////////////////////
// 几何/数学
////////////////////////////////////////////////////////////////////////////////////////////////////

/// 转化弧度为角度
extern float convertRadianToDegree(float radian);

/// 转化角度为弧度
extern float convertDegreeToRadian(float degree);

#if (ENABLED_BOX2D)

/// 从 b2Vec2 得到 CCPoint
extern CCPoint pointFromVec(const b2Vec2 & vec);

/// 从 CCPoint 得到 b2Vec2
extern b2Vec2 vecFromPoint(const CCPoint & point);

/// 从 b2Vec2 得到 CCPoint, 米 -> 点
extern CCPoint pointFromVec_meter(const b2Vec2 & vec);

/// 从 CCPoint 得到 b2Vec2, 点 -> 米
extern b2Vec2 vecFromPoint_meter(const CCPoint & point);

#endif // ENABLED_BOX2D

/// 针对于 Box2D 中, 米 -> 点
extern float pointFromMeter(float meterUnit);

/// 针对于 Box2D 中, 点 -> 米
extern float meterFromPoint(float pointUnit);

/// 判断 rect1 包含 rect2
extern bool CCRectContainsRect(cocos2d::CCRect& rect1, cocos2d::CCRect& rect2);

////////////////////////////////////////////////////////////////////////////////////////////////////
// 分辨率处理
////////////////////////////////////////////////////////////////////////////////////////////////////

/// 适配横向分辨率
extern void adapterLandscapeResolution(float contentScale = 1.0f);

/// 适配纵向分辨率
extern void adapterPortraitResolution(float contentScale = 1.0f);

////////////////////////////////////////////////////////////////////////////////////////////////////
// 字符串处理
////////////////////////////////////////////////////////////////////////////////////////////////////

/** 数值转化为 string 类型 **/
extern std::string int32ToString(int32 value);
extern std::string uint32ToString(uint32 value);
extern std::string uint64ToString(uint64 value);
extern std::string float32ToString(float32 value);
extern std::string boolToString(bool value);

/** string 类型转化为数值 **/
extern int32 int32FromString(const std::string & value);
extern uint32 uint32FromString(const std::string & value);
extern uint64 uint64FromString(const std::string & value);
extern float32 float32FromString(const std::string & value);
extern bool boolFromString(const std::string & value);

/// ASCII 转化为小写
extern void asciiToLower(std::string & origin);

/// ASCII 转化为大写
extern void asciiToUpper(std::string & origin);

/**
 * 使用指定的分割符分组字符串
 * @param origin 待切割的字符串
 * @param others 分组的各个字符串存放的容器
 * @param seperator 分隔符
 */
extern void slitStringBySeperator(const std::string & origin, std::vector<std::string> & others, const std::string & seperator);

/**
 * 从字符串后面裁掉连续的指定字符, 如果遇到非连续的字符, 将停止裁剪
 * @param origin 待裁剪的字符串
 * @param chTrim 需要连续裁剪的匹配字符
 * @return 裁剪后的字符串
 */
extern std::string trimCharacterFromLast(const std::string & origin, char chTrim);


/**
 * 根据指定字符, 截取子字符串. 子字符串的范围是 [0, Pos(chSign)), 如果没有找到 chSign, 那么将返回 origin 字符串.
 * @param origin 待裁剪的字符串
 * @param chSign 标记字符
 * @return 截取的字符串
 */
extern std::string subStringWithCharacterFromHead(const std::string& origin, char chSign);

/**
 * 根据指定字符, 截取子字符串. 子字符串的范围是 [Pos(chSign) + 1, origin.length()), 如果没有找到 chSign, 那么将返回 origin 字符串.
 * @param origin 待裁剪的字符串
 * @param chSign 标记字符
 * @return 截取的字符串
 */
extern std::string subStringWithCharacterFromLast(const std::string& origin, char chSign);

/**
 * 删除文件的后缀名, 例如: text.png, 返回结果是 text
 */
extern std::string stringByDeletingPathExtension(const std::string & origin);

/**
 * 添加文件后缀名, 例如: 传入 origin = file, extension = png, 返回的结果是 file.png
 */
extern std::string stringByAppendingPathExtension(const std::string & origin, const std::string & extension);

/**
 * 获得文件的后缀名
 * 传入字符串 -> 返回字符串: 
 *		/tmp/scratch.tiff				->		tiff
 *		.scratch.tiff					->		tiff
 *		/tmp/scratch					->		""
 *		/tmp/							->		""
 *		.scratch.						->		""
 *		/tmp/scratch..tiff				->		tiff
 */
extern std::string pathExtensionWithString(const std::string & file);

#endif /* defined(__AndroidaBooM__CommonUtils__) */
















































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


