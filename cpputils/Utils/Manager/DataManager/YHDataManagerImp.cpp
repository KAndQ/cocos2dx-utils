//
//  YHDataManagerImp.cpp
//  MonsterHunter
//
//  Created by Zhenyu Yao on 14-1-10.
//
//

#include "YHDataManagerImp.h"
#include "Utils/Buffer/YHByteArray.h"
#include "Utils/Common/CommonUtils.h"


USING_NS_CC;
using namespace std;

static void dictionary_Value(CCDictionary * aDict, const cocos2d::ValueMap & value);
static void array_Value(CCArray * aArray, const cocos2d::ValueVector & value);

static void array_Value(CCArray * aArray, const cocos2d::ValueVector & value)
{
    cocos2d::ValueVector::const_iterator beg = value.begin();
    cocos2d::ValueVector::const_iterator end = value.end();
    for (; beg != end; ++beg)
    {
        const Value & v = *beg;
        if (v.getType() == Value::Type::MAP)
        {
            CCDictionary * dict = new CCDictionary();
            dict->init();
            dictionary_Value(dict, v.asValueMap());
            aArray->addObject(dict);
            dict->release();
        }
        else if (v.getType() == Value::Type::VECTOR)
        {
            CCArray * arr = new CCArray();
            arr->init();
            array_Value(arr, v.asValueVector());
            aArray->addObject(arr);
            arr->release();
        }
        else
        {
            CCString * str = new CCString();
            if (v.getType() == Value::Type::DOUBLE)
                str->initWithFormat("%f", v.asDouble());
            else
                str->initWithFormat("%s", v.asString().c_str());
            aArray->addObject(str);
            str->release();
        }
    }
}

static void dictionary_Value(CCDictionary * aDict, const cocos2d::ValueMap & value)
{
    cocos2d::ValueMap::const_iterator beg = value.begin();
    cocos2d::ValueMap::const_iterator end = value.end();
    for (; beg != end; ++beg)
    {
        const std::string & key = (*beg).first;
        const cocos2d::Value & v = (*beg).second;
        if (v.getType() == Value::Type::MAP)
        {
            CCDictionary * d = new CCDictionary();
            d->init();
            dictionary_Value(d, v.asValueMap());
            aDict->setObject(d, key);
            d->release();
        }
        else if (v.getType() == Value::Type::VECTOR)
        {
            CCArray * a = new CCArray();
            a->init();
            array_Value(a, v.asValueVector());
            aDict->setObject(a, key);
            a->release();
        }
        else
        {
            CCString * str = new CCString();
            if (v.getType() == Value::Type::DOUBLE)
                str->initWithFormat("%f", v.asDouble());
            else
                str->initWithFormat("%s", v.asString().c_str());
            aDict->setObject(str, key);
            str->release();
        }
    }
}

YHDataManagerImp::YHDataManagerImp() : m_waitingFiles(NULL)
{
}

YHDataManagerImp::~YHDataManagerImp()
{
	CC_SAFE_RELEASE_NULL(m_waitingFiles);
}

bool YHDataManagerImp::init()
{
	bool result = YHAbstractDataSetting::init(NULL);
	
	setDict(CCDictionary::create());
	
	m_waitingFiles = CCArray::create();
	CC_SAFE_RETAIN(m_waitingFiles);
	
	return result;
}

void YHDataManagerImp::purgeImages()
{
    std::vector<std::string> allFiles = this->allFiles();
    for (auto s : allFiles)
    {
        // 删除图片资源 & 相关的 CCSpriteFrame 对象
        if (s.find(".png") != string::npos)
        {
            CCTexture2D * tex = this->textureForFile(s);
            if (tex != nullptr)
            {
                SpriteFrameCache::getInstance()->removeSpriteFrameByName("_loadedFileNames");       // clean _loadedFileNames
                SpriteFrameCache::getInstance()->removeSpriteFramesFromTexture(tex);
                TextureCache::getInstance()->removeTexture(tex);
            }
        }
    }
    
    CCLOG("%s", TextureCache::getInstance()->getCachedTextureInfo().c_str());
}

CCObject * YHDataManagerImp::loadFile(const std::string & fullpath)
{
    string suffix = pathExtensionWithString(fullpath);
    asciiToLower(suffix);
    
    // 装载对应的对象
    CCObject * obj = NULL;
    if (suffix.compare("plist-array") == 0)
    {
        ValueVector vv = CCFileUtils::getInstance()->getValueVectorFromFile(fullpath);
        CCArray * arr = new CCArray();
        arr->initWithCapacity((ssize_t)vv.size());
        array_Value(arr, vv);
        obj = arr;
    }
    else if (suffix.compare("plist-dictionary") == 0)
    {
        ValueMap vm = FileUtils::getInstance()->getValueMapFromFile(fullpath);
        CCDictionary * dic = new CCDictionary();
        dic->init();
        dictionary_Value(dic, vm);
        obj = dic;
    }
    else if (suffix.compare("png") == 0 || suffix.compare("jpg") == 0 || suffix.compare("jpeg") == 0
             || suffix.compare("tif") == 0 || suffix.compare("tiff") == 0 || suffix.compare("webp") == 0)
    {
        Image * image = new Image();
        image->initWithImageFile(fullpath);
        obj = image;
    }
    else if (suffix.compare("plist") == 0)
    {
		ValueMap vm = CCFileUtils::getInstance()->getValueMapFromFile(fullpath);
		if (vm.size())
		{
			CCDictionary * dic = new CCDictionary();
			dic->init();
			dictionary_Value(dic, vm);
			obj = dic;
		}
		else
		{
			ValueVector vv = CCFileUtils::getInstance()->getValueVectorFromFile(fullpath);
			if (vv.size())
			{
				CCArray * arr = new CCArray();
				arr->initWithCapacity((ssize_t)vv.size());
				array_Value(arr, vv);
				obj = arr;
			}
			else
			{
				CCASSERT(false, "没有找到适合的解析文件方式。");
			}
		}
    }
    else
    {
        std::string data = FileUtils::getInstance()->getStringFromFile(fullpath);
        YHByteArray * bytes = new YHByteArray();
        bytes->init(data.length() + 1);
        bytes->writeBytes((char *)data.c_str(), data.length() + 1);
        obj = bytes;
    }
    
    return obj;
}

void YHDataManagerImp::setFinishedCallback(const std::function<void ()> & callback)
{
    m_callback = callback;
}










































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


