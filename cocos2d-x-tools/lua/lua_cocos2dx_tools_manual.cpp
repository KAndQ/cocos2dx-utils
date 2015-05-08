//
//  lua_cocos2dx_tools_manual.cpp
//  cocos2d-x-tools
//
//  Created by Zhenyu Yao on 14-9-30.
//
//

#include "lua_cocos2dx_tools_manual.hpp"
#include "cocos2d-x-tools.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"
#include "Utils/Debug/B2DebugDrawLayer.h"

template<class T>
static int tolua_cocos2dx_setHandler(lua_State * tolua_S, const char * className)
{
    int argc = 0;
    T * obj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, className, 0, &tolua_err)) goto tolua_lerror;
#endif
    
    obj = (T *)tolua_tousertype(tolua_S,1,0);
    
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1)
    {
#if COCOS2D_DEBUG >= 1
        if (!toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err))
        {
            goto tolua_lerror;
        }
#endif
        int handler =  toluafix_ref_function(tolua_S,2,0);
        obj->setHandler(handler);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setHandler", argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_cocos2dx_setHandler'.",&tolua_err);
#endif
    
    return 0;
}

static void extendHandler(lua_State * tolua_S, const char * tableName, lua_CFunction fn)
{
    lua_pushstring(tolua_S, tableName);
    lua_rawget(tolua_S, LUA_REGISTRYINDEX);
    if (lua_istable(tolua_S, -1))
    {
        lua_pushstring(tolua_S, "setHandler");
        lua_pushcfunction(tolua_S, fn);
        lua_rawset(tolua_S, -3);
    }
    lua_pop(tolua_S, 1);
}

static int tolua_cocos2dx_YHAnimationKeyEvents_setHandler(lua_State * tolua_S)
{
    return tolua_cocos2dx_setHandler<YHAnimationKeyEvents>(tolua_S, "YHAnimationKeyEvents");
}

static void extendYHAnimationKeyEvents(lua_State * tolua_S)
{
    extendHandler(tolua_S, "YHAnimationKeyEvents", tolua_cocos2dx_YHAnimationKeyEvents_setHandler);
}

static int tolua_cocos2dx_valueMapFromDictionary(lua_State * tolua_S)
{
    int argc = 0;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.__Dictionary",0,&tolua_err)) goto tolua_lerror;
#endif
    
    argc = lua_gettop(tolua_S);
    if (argc == 1)
    {
        cocos2d::__Dictionary * cobj = (cocos2d::__Dictionary*)tolua_tousertype(tolua_S,1,0);
        if (!cobj)
        {
            tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_cocos2dx_valueMapFromDictionary'", nullptr);
            return 0;
        }
        
        cocos2d::ValueMap vm = valueMapFromDictionary(cobj);
        ccvaluemap_to_luaval(tolua_S, vm);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "valueMapFromDictionary",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_cocos2dx_valueMapFromDictionary'.",&tolua_err);
#endif
    
    return 0;
}

static int tolua_cocos2dx_valueVectorFromArray(lua_State * tolua_S)
{
    int argc = 0;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.__Array",0,&tolua_err)) goto tolua_lerror;
#endif
    
    argc = lua_gettop(tolua_S);
    if (argc == 1)
    {
        cocos2d::__Array * cobj = (cocos2d::__Array*)tolua_tousertype(tolua_S,1,0);
        if (!cobj)
        {
            tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_cocos2dx_valueVectorFromArray'", nullptr);
            return 0;
        }
        
        cocos2d::ValueVector vm = valueVectorFromArray(cobj);
        ccvaluevector_to_luaval(tolua_S, vm);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "valueVectorFromArray",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_cocos2dx_valueVectorFromArray'.",&tolua_err);
#endif
    
    return 0;
}

static int tolua_cocos2dx_CCKeyTimeCallbackSprite_setHandler(lua_State * tolua_S)
{
    return tolua_cocos2dx_setHandler<CCKeyTimeCallbackSprite>(tolua_S, "CCKeyTimeCallbackSprite");
}

static void extendCCKeyTimeCallbackSprite(lua_State * tolua_S)
{
    extendHandler(tolua_S, "CCKeyTimeCallbackSprite", tolua_cocos2dx_CCKeyTimeCallbackSprite_setHandler);
}

static int tolua_cocos2dx_AvatarComponent_setHandler(lua_State * tolua_S)
{
    return tolua_cocos2dx_setHandler<AvatarComponent>(tolua_S, "AvatarComponent");
}

static void extendAvatarComponent(lua_State * tolua_S)
{
    extendHandler(tolua_S, "AvatarComponent", tolua_cocos2dx_AvatarComponent_setHandler);
}

static int tolua_cocos2dx_YHDefaultFiniteEffect_setHandler(lua_State * tolua_S)
{
    return tolua_cocos2dx_setHandler<YHDefaultFiniteEffect>(tolua_S, "YHDefaultFiniteEffect");
}

static void extendYHDefaultFiniteEffect(lua_State * tolua_S)
{
    extendHandler(tolua_S, "YHDefaultFiniteEffect", tolua_cocos2dx_YHDefaultFiniteEffect_setHandler);
}

static int tolua_cocos2dx_AEEffectSprite_setHandler(lua_State * tolua_S)
{
    return tolua_cocos2dx_setHandler<AEEffectSprite>(tolua_S, "AEEffectSprite");
}

static void extendAEEffectSprite(lua_State * tolua_S)
{
    extendHandler(tolua_S, "AEEffectSprite", tolua_cocos2dx_AEEffectSprite_setHandler);
}

static int tolua_cocos2dx_YHDataManager_setHandler(lua_State * tolua_S)
{
    return tolua_cocos2dx_setHandler<YHDataManager>(tolua_S, "YHDataManager");
}

static void extendYHDataManager(lua_State * tolua_S)
{
    extendHandler(tolua_S, "YHDataManager", tolua_cocos2dx_YHDataManager_setHandler);
}

static int lua_cocos2dx_tools_B2DebugDrawLayer_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"B2DebugDrawLayer",0,&tolua_err)) goto tolua_lerror;
#endif
    
    argc = lua_gettop(tolua_S)-1;
    
    do
    {
        if (argc == 2)
        {
            b2World * world = nullptr;
            double ptmRatio = 0.0f;
            
            ok &= luaval_to_object(tolua_S, 2, "b2World", &world);
            if (!ok) { break; }
            
            ok &= luaval_to_number(tolua_S, 3, &ptmRatio);
            if (!ok) { break; }
            
            B2DebugDrawLayer * ret = B2DebugDrawLayer::create(world, ptmRatio);
            object_to_luaval<B2DebugDrawLayer>(tolua_S, "B2DebugDrawLayer", (B2DebugDrawLayer*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_B2DebugDrawLayer_create'.",&tolua_err);
#endif
    return 0;
}

TOLUA_API int register_all_cocos2dx_tools_manual(lua_State* tolua_S)
{
    lua_pushcfunction(tolua_S, tolua_cocos2dx_valueMapFromDictionary);
    lua_setglobal(tolua_S, "valueMapFromDictionary");
    lua_pushcfunction(tolua_S, tolua_cocos2dx_valueVectorFromArray);
    lua_setglobal(tolua_S, "valueVectorFromArray");
    
    extendYHAnimationKeyEvents(tolua_S);
    extendCCKeyTimeCallbackSprite(tolua_S);
    extendAvatarComponent(tolua_S);
    extendYHDefaultFiniteEffect(tolua_S);
    extendAEEffectSprite(tolua_S);
    extendYHDataManager(tolua_S);
    
    // B2DebugDrawLayer
    tolua_usertype(tolua_S, "B2DebugDrawLayer");
    tolua_cclass(tolua_S, "B2DebugDrawLayer", "B2DebugDrawLayer", "cc.Layer", nullptr);
    tolua_beginmodule(tolua_S, "B2DebugDrawLayer");
    tolua_function(tolua_S, "create", lua_cocos2dx_tools_B2DebugDrawLayer_create);
    tolua_endmodule(tolua_S);
    
    return 1;
}