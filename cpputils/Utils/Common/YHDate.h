//
//  YHDate.h
//  MGBX
//
//  Created by Zhenyu Yao on 14-3-14.
//  Copyright (c) 2014年 Mog Gen. All rights reserved.
//

#ifndef __MGBX__YHDate__
#define __MGBX__YHDate__

#include "YHTypes.h"
#include <ctime>

/// 一天的秒数
#define YHDate_OneDay_Seconds       86400

/**
 * 时间函数
 * @author Zhenyu Yao
 */
class YHDate : public YHObject, public cocos2d::Clonable
{
public:
    
    YHDate();
    virtual ~YHDate();
    
    /// 以当前时间初始化
    virtual bool init();
    
    /**
     * 以指定格式的字符串初始化
     * @param format 格式化字符串
     * @note 字符串格式, 例如: 2001-08-23 14:55:02
     * @return 初始化成功返回 true, 否则返回 false
     */
    virtual bool init(const std::string & format);
    
    /// 创建 YHDate 对象
    CREATE_FUNC(YHDate);
    
    /// 使用 init(const std::string & format) 初始化创建 YHDate 对象
    static YHDate * create(const std::string & format)
    {
        YHDate * instance = new YHDate();
        if (instance != nullptr && instance->init(format))
        {
            instance->autorelease();
            return instance;
        }
        
        CC_SAFE_DELETE(instance);
        return nullptr;
    }
    
    /// 线程安全的创建 YHDate 对象, 使用完返回的对象后, 必须手动 release
    static YHDate * createThreadSafe(const std::string & format = "")
    {
        YHDate * date = new YHDate();
        if (date != nullptr)
        {
            bool ret = false;
            if (format.empty())
                ret = date->init();
            else
                ret = date->init(format);
            
            if (ret)
                return date;
        }
        
        CC_SAFE_DELETE(date);
        return nullptr;
    }
    
    /// tm
    struct std::tm * get_tm() const { return m_tm; }
    
    /// time_t
    std::time_t get_time_t() const { return m_time; }
    
    /// seconds [0, 60]
    int32 sec() const { return m_tm->tm_sec; }
    
    /// minutes [0, 59]
    int32 min() const { return m_tm->tm_min; }
    
    /// hours [0, 23]
    int32 hour() const { return m_tm->tm_hour; }
    
    /// month day [1, 31]
    int32 mday() const { return m_tm->tm_mday; }
    
    /// month [0, 11]
    int32 mon() const { return m_tm->tm_mon; }
    
    /// years since 1900
    int32 year() const { return m_tm->tm_year; }
    
    /// years year() + 1900
    int32 year2() const { return m_tm->tm_year + 1900; }
    
    /// days since Sunday [0, 6]
    int32 wday() const { return m_tm->tm_wday; }
    
    /// days since January 1 [0, 365]
    int32 yday() const { return m_tm->tm_yday; }
    
    /// Daylight Saving Time flag
    int32 isdst() const { return m_tm->tm_isdst; }
    
    /**
     * 与 date 时间的秒数
     * @param date 比较的时间
     * @return 如果当前对象晚于 date 对象, 返回正值, 否则返回负值, 返回值以秒为单位
     */
    float64 difftime(YHDate * date) const;
    
    /// 判断是否是同一时间
    bool sameTime(YHDate * date) const;
    
    /// 判断同天
    bool sameDay(YHDate * date) const;
    
    /// 判断同月
    bool sameMonth(YHDate * date) const;
    
    /// 判断同年
    bool sameYear(YHDate * date) const;
    
    /// 判断是否今天
    bool isToday() const;
    
    /**
     * 与当前时间变化若干秒
     * @param timeInterval 变化的时间, 以秒为单位
     */
    void addTimeInterval(float32 timeInterval);
    
    /**
     * 返回当前时间的字符串, 默认输出格式 2001-08-23 14:55:02
     * @param format 格式化字符串
     * @note 格式化的规则请查看 http://www.cplusplus.com/reference/ctime/strftime/
     * @return 字符串
     */
    std::string toString(char * format = nullptr) const;
    
    virtual Clonable * clone() const;
    
private:
    
    std::time_t m_time;
    std::tm * m_tm;
};

#endif /* defined(__MGBX__YHDate__) */














































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


