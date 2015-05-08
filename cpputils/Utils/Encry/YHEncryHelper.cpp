//
//  YHEncryHelper.cpp
//  MonsterHunter
//
//  Created by Zhenyu Yao on 14-1-8.
//
//

#include "YHEncryHelper.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
// SimpleEncryHelper
////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * 普通的加密/解密类
 * @author Zhenyu Yao
 */
class YHSimpleEncryHelper : public YHEncryHelper
{
public:
	
	virtual YHByteArray * encode(YHByteArray * data, YHByteArray * secret)
	{
		char * chars = (char *)secret->getBuffer();
		uint32 charsLen = secret->readableBytes();
		uint32 dataLength = data->readableBytes();
		
		for (uint32 i = 0; i < dataLength; i += charsLen)
		{
			for (uint32 j = 0; i + j < dataLength && j < charsLen; ++j)
			{
				uint32 index = i + j;
				char ch1 = data->getChar(index);
				char ch2 = chars[j];
				char ch = ch1 ^ ch2;
				data->setChar(index, ch);
			}
		}
		
		CC_SAFE_RETAIN(data);
		return data;
	}
	
	virtual YHByteArray * decode(YHByteArray * data, YHByteArray * secret)
	{
		return encode(data, secret);
	}
	
protected:
	
	YHSimpleEncryHelper() {}
	virtual ~YHSimpleEncryHelper() {}
	
	friend class YHEncryHelper;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// YHEncryHelper
////////////////////////////////////////////////////////////////////////////////////////////////////

static YHEncryHelper * s_instance = NULL;

YHEncryHelper * YHEncryHelper::sharedInstance()
{
	if (s_instance == NULL)
	{
		s_instance = new YHSimpleEncryHelper();
	}
	
	return s_instance;
}

void YHEncryHelper::encodeToFile(const std::string & file, YHByteArray * data, YHByteArray * secret)
{
	std::string writeablePath = cocos2d::CCFileUtils::sharedFileUtils()->getWritablePath();
	std::string fullpath = writeablePath + "/" + file;
	
	FILE * pFile = fopen(fullpath.c_str(), "w");
	if (pFile == NULL)
		return;
	
	// 数据加密
	data = encode(data, secret);
	
	// 写入到文件
	fwrite(data->getBuffer(), data->readableBytes(), 1, pFile);
	
	// 释放资源
	fclose(pFile);
	CC_SAFE_RELEASE(data);
}

YHByteArray * YHEncryHelper::decodeWithFile(const std::string & file, YHByteArray * secret)
{
	std::string fullpath = cocos2d::CCFileUtils::sharedFileUtils()->fullPathForFilename(file.c_str());
	FILE * pFile = fopen(fullpath.c_str(), "r");
	
	if (pFile == NULL)
		return NULL;
	
	// 得到文件的大小
	fseek(pFile, 0, SEEK_END);
	size_t size = ftell(pFile);
	fseek(pFile, 0, SEEK_SET);
	
	// 从文件读取数据
	YHByteArray * data = new YHByteArray();
	data->init((uint32)(size + 1));
	fread(data->getBuffer(), size, 1, pFile);
	data->setWriterIndex((uint32)size);
	data->setChar(data->getWriterIndex(), 0);
	fclose(pFile);
	
	YHByteArray * result = decode(data, secret);
	CC_SAFE_RELEASE_NULL(data);
	return result;
}







































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


