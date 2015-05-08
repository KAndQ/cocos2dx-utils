//
//  YHGameBasicInfo.h
//  MGBX
//
//  Created by Zhenyu Yao on 14-3-17.
//  Copyright (c) 2014年 Mog Gen. All rights reserved.
//

#ifndef __MGBX__YHGameBasicInfo__
#define __MGBX__YHGameBasicInfo__

#include "YHTypes.h"

/**
 * 游戏基础信息基类
 * @author Zhneyu Yao
 */
class YHGameBasicInfo : public YHObject
{
public:
    
    virtual ~YHGameBasicInfo() {}
    
    /// YHGameBasicInfo 对象
    static YHGameBasicInfo * sharedInstance();
    
    /// 初始化
    virtual bool init() = 0;
    
    /// 当前的版本
    virtual std::string version() = 0;
    
    /// 当前的游戏名
    virtual std::string name() = 0;
    
protected:
    
    YHGameBasicInfo() {}
};

#endif /* defined(__MGBX__YHGameBasicInfo__) */














































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


