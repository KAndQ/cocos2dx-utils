//
//  YHDate.cpp
//  MGBX
//
//  Created by Zhenyu Yao on 14-3-14.
//  Copyright (c) 2014年 Mog Gen. All rights reserved.
//

#include "YHDate.h"
#include <string>

////////////////////////////////////////////////////////////////////////////////////////////////////
// Public Functions
////////////////////////////////////////////////////////////////////////////////////////////////////

YHDate::YHDate()
{
}

YHDate::~YHDate()
{
    CC_SAFE_DELETE(m_tm);
}

bool YHDate::init()
{
    m_time = time(NULL);
    m_tm = new struct tm();
    *m_tm = *localtime(&m_time);
    return true;
}

bool YHDate::init(const std::string & format)
{
    if (format.length() == 0)
        return init();
    
    size_t beg = 0;
    size_t len = format.find('-', beg);
    
    m_tm = new struct tm();
    
    // 年
    std::string strYear = format.substr(beg, len);
    m_tm->tm_year = atoi(strYear.c_str()) - 1900;
    
    // 月
    beg = len + 1;
    len = format.find('-', beg);
    std::string strMonth = format.substr(beg, len - beg);
    m_tm->tm_mon = atoi(strMonth.c_str()) - 1;
    
    // 日
    beg = len + 1;
    len = format.find(' ', beg);
    std::string strDay = format.substr(beg, len - beg);
    m_tm->tm_mday = atoi(strDay.c_str());
    
    // 时
    beg = len + 1;
    len = format.find(':', beg);
    std::string strHour = format.substr(beg, len - beg);
    m_tm->tm_hour = atoi(strHour.c_str());
    
    // 分
    beg = len + 1;
    len = format.find(':', beg);
    std::string strMin = format.substr(beg, len - beg);
    m_tm->tm_min = atoi(strMin.c_str());
    
    // 秒
    beg = len + 1;
    std::string strSec = format.substr(beg);
    m_tm->tm_sec = atoi(strSec.c_str());
    
    m_time = std::mktime(m_tm);
    *m_tm = *std::localtime(&m_time);
    
    return true;
}

float64 YHDate::difftime(YHDate * date) const
{
    return std::difftime(m_time, date->m_time);
}

bool YHDate::sameTime(YHDate * date) const
{
    return YHDate::difftime(date) == 0.0f;
}

bool YHDate::sameDay(YHDate * date) const
{
    return m_tm->tm_year == date->m_tm->tm_year
        && m_tm->tm_mon == date->m_tm->tm_mon
        && m_tm->tm_mday == date->m_tm->tm_mday;
}

bool YHDate::sameMonth(YHDate * date) const
{
    return m_tm->tm_year == date->m_tm->tm_year
        && m_tm->tm_mon == date->m_tm->tm_mon;
}

bool YHDate::sameYear(YHDate * date) const
{
    return m_tm->tm_year = date->m_tm->tm_year;
}

bool YHDate::isToday() const
{
    return sameDay(YHDate::create());
}

void YHDate::addTimeInterval(float32 timeInterval)
{
    m_time += (time_t)timeInterval;
    *m_tm = *localtime(&m_time);
}

std::string YHDate::toString(char * format) const
{
    char buf[64] = {};
    if (format != nullptr)
        strftime(buf, 64, format, m_tm);
    else
        strftime(buf, 64, "%F %T", m_tm);
    
    return buf;
}

cocos2d::Clonable * YHDate::clone() const
{
    YHDate * date = new YHDate();
    date->init(toString());
    return date;
}








































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


