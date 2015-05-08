//
//  CCEncryptNumber.cpp
//  MGBX
//
//  Created by Zhenyu Yao on 14-3-21.
//  Copyright (c) 2014年 Mog Gen. All rights reserved.
//

#include "CCEncryptNumber.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
// Public Functions
////////////////////////////////////////////////////////////////////////////////////////////////////

CCEncryptNumber::CCEncryptNumber()
{
}

CCEncryptNumber::~CCEncryptNumber()
{
}

bool CCEncryptNumber::init(int32 value)
{
    init();
    setBitXOR(sizeof(int32), (uint8 *)&value);
    m_num1 = value;
    return true;
}

bool CCEncryptNumber::init(uint32 value)
{
    init();
    setBitXOR(sizeof(uint32), (uint8 *)&value);
    m_num2 = value;
    return true;
}

bool CCEncryptNumber::init(float32 value)
{
    init();
    setBitXOR(sizeof(float32), (uint8 *)&value);
    m_num3 = value;
    return true;
}

bool CCEncryptNumber::init(float64 value)
{
    init();
    setBitXOR(sizeof(float64), (uint8 *)&value);
    m_num4 = value;
    return true;
}

bool CCEncryptNumber::init(bool value)
{
    return init((int32)value);
}

int32 CCEncryptNumber::int32Value()
{
    int32 value = m_num1;
    setBitXOR(sizeof(int32), (uint8 *)&value);
    return value;
}

uint32 CCEncryptNumber::uint32Value()
{
    uint32 value = m_num2;
    setBitXOR(sizeof(uint32), (uint8 *)&value);
    return value;
}

float32 CCEncryptNumber::float32Value()
{
    float32 value = m_num3;
    setBitXOR(sizeof(float32), (uint8 *)&value);
    return value;
}

float64 CCEncryptNumber::float64Value()
{
    float64 value = m_num4;
    setBitXOR(sizeof(float64), (uint8 *)&value);
    return value;
}

bool CCEncryptNumber::boolValue()
{
    return int32Value();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// Private Functions
////////////////////////////////////////////////////////////////////////////////////////////////////

void CCEncryptNumber::init()
{
    while (m_bits == 0)
        m_bits = rand();
}

void CCEncryptNumber::setBitXOR(size_t size, uint8 * bits)
{
    for (size_t i = 0; i < size; ++i)
        bits[i] ^= m_bits;
}











































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


