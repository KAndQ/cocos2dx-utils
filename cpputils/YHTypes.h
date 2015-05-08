//
//  YHTypes.h
//  AndroidaBooM
//
//  Created by Zhenyu Yao on 13-4-12.
//
//

#ifndef AndroidaBooM_YHTypes_h
#define AndroidaBooM_YHTypes_h

#define ENABLED_BOX2D 1
#define ENABLED_JSONCPP 0

#include "cocos2d.h"
#include "cocos-ext.h"
#include "HttpClient.h"
#include "HttpRequest.h"
#include "HttpResponse.h"

#if (ENABLED_BOX2D)
#include <Box2D/Box2D.h>
#endif // ENABLED_BOX2D

class YHEvent;
class YHEventDispatcher;

#if (!ENABLED_BOX2D)

typedef char int8;
typedef unsigned char uint8;
typedef int int32;
typedef unsigned int uint32;
typedef short int16;
typedef unsigned short uint16;
typedef float float32;
typedef double float64;

#endif // ENABLED_BOX2D

typedef long long int64;
typedef unsigned long long uint64;

typedef cocos2d::DictElement CCDictElement;
typedef cocos2d::network::HttpRequest CCHttpRequest;
typedef cocos2d::network::HttpResponse CCHttpResponse;
typedef cocos2d::network::HttpClient CCHttpClient;
typedef cocos2d::ReverseTime CCReverseTime;

#define CCPointFromString PointFromString
#define CCSizeFromString SizeFromString

#define Default_BlendFunc BlendFunc::ALPHA_PREMULTIPLIED

/**
 * 接口继承此类, 以得到实现此接口的 CCObject 对象, 非 CCObject 对象实现时 返回 NULL.
 * 当传入的是实现此接口对象的时候, 实现此接口的对象能够通过 getSelf() 操作得到自身的引用, 从而进行 retain/release/autorelease 等资源控制操作.
 * @author Zhenyu Yao
 */
class ICCObject
{
public:

	/// 得到实现此接口的父类
	virtual cocos2d::CCObject * getSelf() = 0;

};

/**
 * 一切对象的基类
 * @author Zhenyu Yao
 */
class YHObject : public cocos2d::Ref, public ICCObject
{
public:
	YHObject() {};
	virtual ~YHObject() {};
	virtual cocos2d::CCObject * getSelf() { return this; }
};

typedef void (YHObject::*ListenerSelector)(YHEvent * obj);

#define LISTENER_SELECTOR(__SEL__) (ListenerSelector)(&__SEL__)
#define RunListenerSelector(__Target__, __Selector__, __Object__) (__Target__->*__Selector__)(__Object__)

#endif


