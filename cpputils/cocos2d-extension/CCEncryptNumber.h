//
//  CCEncryptNumber.h
//  MGBX
//
//  Created by Zhenyu Yao on 14-3-21.
//  Copyright (c) 2014年 Mog Gen. All rights reserved.
//

#ifndef __MGBX__CCEncryptNumber__
#define __MGBX__CCEncryptNumber__

#include "YHTypes.h"

/**
 * 加密的数字对象
 * @author Zhenyu Yao
 */
class CCEncryptNumber : public YHObject
{
public:
    
    CCEncryptNumber();
    virtual ~CCEncryptNumber();
    
    /* 初始化 */
    
    virtual bool init(int32 value);
    virtual bool init(uint32 value);
    virtual bool init(float32 value);
    virtual bool init(float64 value);
    virtual bool init(bool value);
    
#define CREATE_ENCRYPT_NUMBER(_Num_Type_) \
        static CCEncryptNumber * create(_Num_Type_ value) \
        {   \
            CCEncryptNumber * instance = new CCEncryptNumber(); \
            if (instance != nullptr && instance->init(value))  \
            {   \
                instance->autorelease();    \
                return instance;    \
            }   \
                \
            CC_SAFE_DELETE(instance);   \
            return nullptr; \
        }
    
    CREATE_ENCRYPT_NUMBER(int32);
    CREATE_ENCRYPT_NUMBER(uint32);
    CREATE_ENCRYPT_NUMBER(float32);
    CREATE_ENCRYPT_NUMBER(float64);
    
    virtual int32 int32Value();
    virtual uint32 uint32Value();
    virtual float32 float32Value();
    virtual float64 float64Value();
    virtual bool boolValue();
    
protected:
    
    /// 每个初始化函数必须调用的初始化
    virtual void init();
    
    /// 将每个字节的数据异或
    virtual void setBitXOR(size_t size, uint8 * bits);
    
protected:
    
    uint8 m_bits = 0;
    
    union
    {
        int32 m_num1;
        uint32 m_num2;
        float32 m_num3;
        float64 m_num4;
    };
};

#endif /* defined(__MGBX__CCEncryptNumber__) */














































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


