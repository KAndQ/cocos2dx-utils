//
//  lua_cocos2dx_tools_manual.h
//  cocos2d-x-tools
//
//  Created by Zhenyu Yao on 14-9-30.
//
//

#ifndef __cocos2d_x_tools__lua_cocos2dx_tools_manual__
#define __cocos2d_x_tools__lua_cocos2dx_tools_manual__

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif

int register_all_cocos2dx_tools_manual(lua_State* tolua_S);

#endif /* defined(__cocos2d_x_tools__lua_cocos2dx_tools_manual__) */
