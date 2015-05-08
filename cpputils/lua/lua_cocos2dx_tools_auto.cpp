#include "lua_cocos2dx_tools_auto.hpp"
#include "cocos2d-x-tools.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_cocos2dx_tools_YHObject_getSelf(lua_State* tolua_S)
{
    int argc = 0;
    YHObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHObject_getSelf'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Ref* ret = cobj->getSelf();
        object_to_luaval<cocos2d::Ref>(tolua_S, "cc.Ref",(cocos2d::Ref*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getSelf",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHObject_getSelf'.",&tolua_err);
#endif

    return 0;
}
static int lua_cocos2dx_tools_YHObject_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (YHObject)");
    return 0;
}

int lua_register_cocos2dx_tools_YHObject(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"YHObject");
    tolua_cclass(tolua_S,"YHObject","YHObject","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"YHObject");
        tolua_function(tolua_S,"getSelf",lua_cocos2dx_tools_YHObject_getSelf);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(YHObject).name();
    g_luaType[typeName] = "YHObject";
    g_typeCast["YHObject"] = "YHObject";
    return 1;
}

int lua_cocos2dx_tools_YHAnimationKeyEvents_setNode(lua_State* tolua_S)
{
    int argc = 0;
    YHAnimationKeyEvents* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHAnimationKeyEvents",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHAnimationKeyEvents*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHAnimationKeyEvents_setNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Node* arg0;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0);
        if(!ok)
            return 0;
        cobj->setNode(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setNode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationKeyEvents_setNode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHAnimationKeyEvents_getAction(lua_State* tolua_S)
{
    int argc = 0;
    YHAnimationKeyEvents* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHAnimationKeyEvents",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHAnimationKeyEvents*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHAnimationKeyEvents_getAction'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Action* ret = cobj->getAction();
        object_to_luaval<cocos2d::Action>(tolua_S, "cc.Action",(cocos2d::Action*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getAction",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationKeyEvents_getAction'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHAnimationKeyEvents_getNode(lua_State* tolua_S)
{
    int argc = 0;
    YHAnimationKeyEvents* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHAnimationKeyEvents",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHAnimationKeyEvents*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHAnimationKeyEvents_getNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Node* ret = cobj->getNode();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationKeyEvents_getNode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHAnimationKeyEvents_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YHAnimationKeyEvents",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 1)
        {
            cocos2d::__Dictionary* arg0;
            ok &= luaval_to_object<cocos2d::__Dictionary>(tolua_S, 2, "cc.__Dictionary",&arg0);
            if (!ok) { break; }
            YHAnimationKeyEvents* ret = YHAnimationKeyEvents::create(arg0);
            object_to_luaval<YHAnimationKeyEvents>(tolua_S, "YHAnimationKeyEvents",(YHAnimationKeyEvents*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 2)
        {
            cocos2d::__Dictionary* arg0;
            ok &= luaval_to_object<cocos2d::__Dictionary>(tolua_S, 2, "cc.__Dictionary",&arg0);
            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1);
            if (!ok) { break; }
            YHAnimationKeyEvents* ret = YHAnimationKeyEvents::create(arg0, arg1);
            object_to_luaval<YHAnimationKeyEvents>(tolua_S, "YHAnimationKeyEvents",(YHAnimationKeyEvents*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 1)
        {
            cocos2d::Animation* arg0;
            ok &= luaval_to_object<cocos2d::Animation>(tolua_S, 2, "cc.Animation",&arg0);
            if (!ok) { break; }
            YHAnimationKeyEvents* ret = YHAnimationKeyEvents::create(arg0);
            object_to_luaval<YHAnimationKeyEvents>(tolua_S, "YHAnimationKeyEvents",(YHAnimationKeyEvents*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 2)
        {
            cocos2d::Animation* arg0;
            ok &= luaval_to_object<cocos2d::Animation>(tolua_S, 2, "cc.Animation",&arg0);
            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1);
            if (!ok) { break; }
            YHAnimationKeyEvents* ret = YHAnimationKeyEvents::create(arg0, arg1);
            object_to_luaval<YHAnimationKeyEvents>(tolua_S, "YHAnimationKeyEvents",(YHAnimationKeyEvents*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 3)
        {
            cocos2d::Animation* arg0;
            ok &= luaval_to_object<cocos2d::Animation>(tolua_S, 2, "cc.Animation",&arg0);
            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1);
            if (!ok) { break; }
            bool arg2;
            ok &= luaval_to_boolean(tolua_S, 4,&arg2);
            if (!ok) { break; }
            YHAnimationKeyEvents* ret = YHAnimationKeyEvents::create(arg0, arg1, arg2);
            object_to_luaval<YHAnimationKeyEvents>(tolua_S, "YHAnimationKeyEvents",(YHAnimationKeyEvents*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationKeyEvents_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tools_YHAnimationKeyEvents_constructor(lua_State* tolua_S)
{
    int argc = 0;
    YHAnimationKeyEvents* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new YHAnimationKeyEvents();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"YHAnimationKeyEvents");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "YHAnimationKeyEvents",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationKeyEvents_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_tools_YHAnimationKeyEvents_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (YHAnimationKeyEvents)");
    return 0;
}

int lua_register_cocos2dx_tools_YHAnimationKeyEvents(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"YHAnimationKeyEvents");
    tolua_cclass(tolua_S,"YHAnimationKeyEvents","YHAnimationKeyEvents","YHObject",nullptr);

    tolua_beginmodule(tolua_S,"YHAnimationKeyEvents");
        tolua_function(tolua_S,"new",lua_cocos2dx_tools_YHAnimationKeyEvents_constructor);
        tolua_function(tolua_S,"setNode",lua_cocos2dx_tools_YHAnimationKeyEvents_setNode);
        tolua_function(tolua_S,"getAction",lua_cocos2dx_tools_YHAnimationKeyEvents_getAction);
        tolua_function(tolua_S,"getNode",lua_cocos2dx_tools_YHAnimationKeyEvents_getNode);
        tolua_function(tolua_S,"create", lua_cocos2dx_tools_YHAnimationKeyEvents_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(YHAnimationKeyEvents).name();
    g_luaType[typeName] = "YHAnimationKeyEvents";
    g_typeCast["YHAnimationKeyEvents"] = "YHAnimationKeyEvents";
    return 1;
}

int lua_cocos2dx_tools_YHAnimationFrameDefiner_getIndex(lua_State* tolua_S)
{
    int argc = 0;
    YHAnimationFrameDefiner* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHAnimationFrameDefiner",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHAnimationFrameDefiner*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHAnimationFrameDefiner_getIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        unsigned int ret = cobj->getIndex();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getIndex",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationFrameDefiner_getIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHAnimationFrameDefiner_getUserInfo(lua_State* tolua_S)
{
    int argc = 0;
    YHAnimationFrameDefiner* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHAnimationFrameDefiner",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHAnimationFrameDefiner*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHAnimationFrameDefiner_getUserInfo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::ValueMap& ret = cobj->getUserInfo();
        ccvaluemap_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getUserInfo",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationFrameDefiner_getUserInfo'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHAnimationFrameDefiner_getDelayUnit(lua_State* tolua_S)
{
    int argc = 0;
    YHAnimationFrameDefiner* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHAnimationFrameDefiner",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHAnimationFrameDefiner*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHAnimationFrameDefiner_getDelayUnit'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->getDelayUnit();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDelayUnit",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationFrameDefiner_getDelayUnit'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHAnimationFrameDefiner_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YHAnimationFrameDefiner",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        cocos2d::__Dictionary* arg0;
        ok &= luaval_to_object<cocos2d::__Dictionary>(tolua_S, 2, "cc.__Dictionary",&arg0);
        if(!ok)
            return 0;
        YHAnimationFrameDefiner* ret = YHAnimationFrameDefiner::create(arg0);
        object_to_luaval<YHAnimationFrameDefiner>(tolua_S, "YHAnimationFrameDefiner",(YHAnimationFrameDefiner*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationFrameDefiner_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tools_YHAnimationFrameDefiner_constructor(lua_State* tolua_S)
{
    int argc = 0;
    YHAnimationFrameDefiner* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::__Dictionary* arg0;

        ok &= luaval_to_object<cocos2d::__Dictionary>(tolua_S, 2, "cc.__Dictionary",&arg0);
        if(!ok)
            return 0;
        cobj = new YHAnimationFrameDefiner(arg0);
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"YHAnimationFrameDefiner");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "YHAnimationFrameDefiner",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationFrameDefiner_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_tools_YHAnimationFrameDefiner_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (YHAnimationFrameDefiner)");
    return 0;
}

int lua_register_cocos2dx_tools_YHAnimationFrameDefiner(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"YHAnimationFrameDefiner");
    tolua_cclass(tolua_S,"YHAnimationFrameDefiner","YHAnimationFrameDefiner","YHObject",nullptr);

    tolua_beginmodule(tolua_S,"YHAnimationFrameDefiner");
        tolua_function(tolua_S,"new",lua_cocos2dx_tools_YHAnimationFrameDefiner_constructor);
        tolua_function(tolua_S,"getIndex",lua_cocos2dx_tools_YHAnimationFrameDefiner_getIndex);
        tolua_function(tolua_S,"getUserInfo",lua_cocos2dx_tools_YHAnimationFrameDefiner_getUserInfo);
        tolua_function(tolua_S,"getDelayUnit",lua_cocos2dx_tools_YHAnimationFrameDefiner_getDelayUnit);
        tolua_function(tolua_S,"create", lua_cocos2dx_tools_YHAnimationFrameDefiner_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(YHAnimationFrameDefiner).name();
    g_luaType[typeName] = "YHAnimationFrameDefiner";
    g_typeCast["YHAnimationFrameDefiner"] = "YHAnimationFrameDefiner";
    return 1;
}

int lua_cocos2dx_tools_YHAnimationDefiner_getDelay(lua_State* tolua_S)
{
    int argc = 0;
    YHAnimationDefiner* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHAnimationDefiner",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHAnimationDefiner*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHAnimationDefiner_getDelay'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->getDelay();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDelay",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationDefiner_getDelay'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHAnimationDefiner_parse_ver2(lua_State* tolua_S)
{
    int argc = 0;
    YHAnimationDefiner* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHAnimationDefiner",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHAnimationDefiner*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHAnimationDefiner_parse_ver2'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::__Dictionary* arg0;

        ok &= luaval_to_object<cocos2d::__Dictionary>(tolua_S, 2, "cc.__Dictionary",&arg0);
        if(!ok)
            return 0;
        cobj->parse_ver2(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "parse_ver2",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationDefiner_parse_ver2'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHAnimationDefiner_parse_ver1(lua_State* tolua_S)
{
    int argc = 0;
    YHAnimationDefiner* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHAnimationDefiner",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHAnimationDefiner*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHAnimationDefiner_parse_ver1'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::__Dictionary* arg0;

        ok &= luaval_to_object<cocos2d::__Dictionary>(tolua_S, 2, "cc.__Dictionary",&arg0);
        if(!ok)
            return 0;
        cobj->parse_ver1(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "parse_ver1",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationDefiner_parse_ver1'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHAnimationDefiner_getLoop(lua_State* tolua_S)
{
    int argc = 0;
    YHAnimationDefiner* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHAnimationDefiner",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHAnimationDefiner*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHAnimationDefiner_getLoop'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        unsigned int ret = cobj->getLoop();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getLoop",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationDefiner_getLoop'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHAnimationDefiner_getRestoreOriginFrame(lua_State* tolua_S)
{
    int argc = 0;
    YHAnimationDefiner* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHAnimationDefiner",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHAnimationDefiner*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHAnimationDefiner_getRestoreOriginFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->getRestoreOriginFrame();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getRestoreOriginFrame",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationDefiner_getRestoreOriginFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHAnimationDefiner_getResources(lua_State* tolua_S)
{
    int argc = 0;
    YHAnimationDefiner* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHAnimationDefiner",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHAnimationDefiner*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHAnimationDefiner_getResources'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const std::vector<std::string>& ret = cobj->getResources();
        ccvector_std_string_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getResources",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationDefiner_getResources'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHAnimationDefiner_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YHAnimationDefiner",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        YHAnimationDefiner* ret = YHAnimationDefiner::create();
        object_to_luaval<YHAnimationDefiner>(tolua_S, "YHAnimationDefiner",(YHAnimationDefiner*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationDefiner_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tools_YHAnimationDefiner_constructor(lua_State* tolua_S)
{
    int argc = 0;
    YHAnimationDefiner* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new YHAnimationDefiner();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"YHAnimationDefiner");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "YHAnimationDefiner",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationDefiner_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_tools_YHAnimationDefiner_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (YHAnimationDefiner)");
    return 0;
}

int lua_register_cocos2dx_tools_YHAnimationDefiner(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"YHAnimationDefiner");
    tolua_cclass(tolua_S,"YHAnimationDefiner","YHAnimationDefiner","YHObject",nullptr);

    tolua_beginmodule(tolua_S,"YHAnimationDefiner");
        tolua_function(tolua_S,"new",lua_cocos2dx_tools_YHAnimationDefiner_constructor);
        tolua_function(tolua_S,"getDelay",lua_cocos2dx_tools_YHAnimationDefiner_getDelay);
        tolua_function(tolua_S,"parse_ver2",lua_cocos2dx_tools_YHAnimationDefiner_parse_ver2);
        tolua_function(tolua_S,"parse_ver1",lua_cocos2dx_tools_YHAnimationDefiner_parse_ver1);
        tolua_function(tolua_S,"getLoop",lua_cocos2dx_tools_YHAnimationDefiner_getLoop);
        tolua_function(tolua_S,"getRestoreOriginFrame",lua_cocos2dx_tools_YHAnimationDefiner_getRestoreOriginFrame);
        tolua_function(tolua_S,"getResources",lua_cocos2dx_tools_YHAnimationDefiner_getResources);
        tolua_function(tolua_S,"create", lua_cocos2dx_tools_YHAnimationDefiner_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(YHAnimationDefiner).name();
    g_luaType[typeName] = "YHAnimationDefiner";
    g_typeCast["YHAnimationDefiner"] = "YHAnimationDefiner";
    return 1;
}

int lua_cocos2dx_tools_YHSpriteDefiner_assignToSprite(lua_State* tolua_S)
{
    int argc = 0;
    YHSpriteDefiner* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHSpriteDefiner",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHSpriteDefiner*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHSpriteDefiner_assignToSprite'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Sprite* arg0;

        ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 2, "cc.Sprite",&arg0);
        if(!ok)
            return 0;
        cobj->assignToSprite(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "assignToSprite",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHSpriteDefiner_assignToSprite'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHSpriteDefiner_getBlendFunc(lua_State* tolua_S)
{
    int argc = 0;
    YHSpriteDefiner* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHSpriteDefiner",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHSpriteDefiner*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHSpriteDefiner_getBlendFunc'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::BlendFunc ret = cobj->getBlendFunc();
        blendfunc_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getBlendFunc",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHSpriteDefiner_getBlendFunc'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHSpriteDefiner_getZOrder(lua_State* tolua_S)
{
    int argc = 0;
    YHSpriteDefiner* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHSpriteDefiner",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHSpriteDefiner*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHSpriteDefiner_getZOrder'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getZOrder();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getZOrder",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHSpriteDefiner_getZOrder'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHSpriteDefiner_setBlendFunc(lua_State* tolua_S)
{
    int argc = 0;
    YHSpriteDefiner* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHSpriteDefiner",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHSpriteDefiner*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHSpriteDefiner_setBlendFunc'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::BlendFunc arg0;

        #pragma warning NO CONVERSION TO NATIVE FOR BlendFunc;
        if(!ok)
            return 0;
        cobj->setBlendFunc(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBlendFunc",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHSpriteDefiner_setBlendFunc'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHSpriteDefiner_getAnchorPoint(lua_State* tolua_S)
{
    int argc = 0;
    YHSpriteDefiner* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHSpriteDefiner",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHSpriteDefiner*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHSpriteDefiner_getAnchorPoint'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Vec2 ret = cobj->getAnchorPoint();
        vec2_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getAnchorPoint",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHSpriteDefiner_getAnchorPoint'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHSpriteDefiner_getRandomRotate(lua_State* tolua_S)
{
    int argc = 0;
    YHSpriteDefiner* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHSpriteDefiner",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHSpriteDefiner*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHSpriteDefiner_getRandomRotate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->getRandomRotate();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getRandomRotate",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHSpriteDefiner_getRandomRotate'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHSpriteDefiner_setRandomRotate(lua_State* tolua_S)
{
    int argc = 0;
    YHSpriteDefiner* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHSpriteDefiner",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHSpriteDefiner*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHSpriteDefiner_setRandomRotate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setRandomRotate(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setRandomRotate",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHSpriteDefiner_setRandomRotate'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHSpriteDefiner_getPosition(lua_State* tolua_S)
{
    int argc = 0;
    YHSpriteDefiner* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHSpriteDefiner",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHSpriteDefiner*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHSpriteDefiner_getPosition'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Vec2 ret = cobj->getPosition();
        vec2_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getPosition",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHSpriteDefiner_getPosition'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHSpriteDefiner_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YHSpriteDefiner",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 1)
        {
            cocos2d::__Dictionary* arg0;
            ok &= luaval_to_object<cocos2d::__Dictionary>(tolua_S, 2, "cc.__Dictionary",&arg0);
            if (!ok) { break; }
            YHSpriteDefiner* ret = YHSpriteDefiner::create(arg0);
            object_to_luaval<YHSpriteDefiner>(tolua_S, "YHSpriteDefiner",(YHSpriteDefiner*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            YHSpriteDefiner* ret = YHSpriteDefiner::create();
            object_to_luaval<YHSpriteDefiner>(tolua_S, "YHSpriteDefiner",(YHSpriteDefiner*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHSpriteDefiner_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tools_YHSpriteDefiner_constructor(lua_State* tolua_S)
{
    int argc = 0;
    YHSpriteDefiner* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            cocos2d::__Dictionary* arg0;
            ok &= luaval_to_object<cocos2d::__Dictionary>(tolua_S, 2, "cc.__Dictionary",&arg0);

            if (!ok) { break; }
            cobj = new YHSpriteDefiner(arg0);
            cobj->autorelease();
            int ID =  (int)cobj->_ID ;
            int* luaID =  &cobj->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"YHSpriteDefiner");
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            cobj = new YHSpriteDefiner();
            cobj->autorelease();
            int ID =  (int)cobj->_ID ;
            int* luaID =  &cobj->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"YHSpriteDefiner");
            return 1;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "YHSpriteDefiner",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHSpriteDefiner_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_tools_YHSpriteDefiner_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (YHSpriteDefiner)");
    return 0;
}

int lua_register_cocos2dx_tools_YHSpriteDefiner(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"YHSpriteDefiner");
    tolua_cclass(tolua_S,"YHSpriteDefiner","YHSpriteDefiner","YHObject",nullptr);

    tolua_beginmodule(tolua_S,"YHSpriteDefiner");
        tolua_function(tolua_S,"new",lua_cocos2dx_tools_YHSpriteDefiner_constructor);
        tolua_function(tolua_S,"assignToSprite",lua_cocos2dx_tools_YHSpriteDefiner_assignToSprite);
        tolua_function(tolua_S,"getBlendFunc",lua_cocos2dx_tools_YHSpriteDefiner_getBlendFunc);
        tolua_function(tolua_S,"getZOrder",lua_cocos2dx_tools_YHSpriteDefiner_getZOrder);
        tolua_function(tolua_S,"setBlendFunc",lua_cocos2dx_tools_YHSpriteDefiner_setBlendFunc);
        tolua_function(tolua_S,"getAnchorPoint",lua_cocos2dx_tools_YHSpriteDefiner_getAnchorPoint);
        tolua_function(tolua_S,"getRandomRotate",lua_cocos2dx_tools_YHSpriteDefiner_getRandomRotate);
        tolua_function(tolua_S,"setRandomRotate",lua_cocos2dx_tools_YHSpriteDefiner_setRandomRotate);
        tolua_function(tolua_S,"getPosition",lua_cocos2dx_tools_YHSpriteDefiner_getPosition);
        tolua_function(tolua_S,"create", lua_cocos2dx_tools_YHSpriteDefiner_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(YHSpriteDefiner).name();
    g_luaType[typeName] = "YHSpriteDefiner";
    g_typeCast["YHSpriteDefiner"] = "YHSpriteDefiner";
    return 1;
}

int lua_cocos2dx_tools_YHAnimationPair_setAction(lua_State* tolua_S)
{
    int argc = 0;
    YHAnimationPair* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHAnimationPair",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHAnimationPair*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHAnimationPair_setAction'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Action* arg0;

        ok &= luaval_to_object<cocos2d::Action>(tolua_S, 2, "cc.Action",&arg0);
        if(!ok)
            return 0;
        cobj->setAction(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setAction",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationPair_setAction'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHAnimationPair_getAction(lua_State* tolua_S)
{
    int argc = 0;
    YHAnimationPair* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHAnimationPair",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHAnimationPair*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHAnimationPair_getAction'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Action* ret = cobj->getAction();
        object_to_luaval<cocos2d::Action>(tolua_S, "cc.Action",(cocos2d::Action*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getAction",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationPair_getAction'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHAnimationPair_setKeyEvents(lua_State* tolua_S)
{
    int argc = 0;
    YHAnimationPair* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHAnimationPair",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHAnimationPair*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHAnimationPair_setKeyEvents'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        YHAnimationKeyEvents* arg0;

        ok &= luaval_to_object<YHAnimationKeyEvents>(tolua_S, 2, "YHAnimationKeyEvents",&arg0);
        if(!ok)
            return 0;
        cobj->setKeyEvents(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setKeyEvents",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationPair_setKeyEvents'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHAnimationPair_getKeyEvents(lua_State* tolua_S)
{
    int argc = 0;
    YHAnimationPair* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHAnimationPair",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHAnimationPair*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHAnimationPair_getKeyEvents'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        YHAnimationKeyEvents* ret = cobj->getKeyEvents();
        object_to_luaval<YHAnimationKeyEvents>(tolua_S, "YHAnimationKeyEvents",(YHAnimationKeyEvents*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getKeyEvents",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationPair_getKeyEvents'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHAnimationPair_constructor(lua_State* tolua_S)
{
    int argc = 0;
    YHAnimationPair* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new YHAnimationPair();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"YHAnimationPair");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "YHAnimationPair",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationPair_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_tools_YHAnimationPair_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (YHAnimationPair)");
    return 0;
}

int lua_register_cocos2dx_tools_YHAnimationPair(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"YHAnimationPair");
    tolua_cclass(tolua_S,"YHAnimationPair","YHAnimationPair","YHObject",nullptr);

    tolua_beginmodule(tolua_S,"YHAnimationPair");
        tolua_function(tolua_S,"new",lua_cocos2dx_tools_YHAnimationPair_constructor);
        tolua_function(tolua_S,"setAction",lua_cocos2dx_tools_YHAnimationPair_setAction);
        tolua_function(tolua_S,"getAction",lua_cocos2dx_tools_YHAnimationPair_getAction);
        tolua_function(tolua_S,"setKeyEvents",lua_cocos2dx_tools_YHAnimationPair_setKeyEvents);
        tolua_function(tolua_S,"getKeyEvents",lua_cocos2dx_tools_YHAnimationPair_getKeyEvents);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(YHAnimationPair).name();
    g_luaType[typeName] = "YHAnimationPair";
    g_typeCast["YHAnimationPair"] = "YHAnimationPair";
    return 1;
}

int lua_cocos2dx_tools_YHAnimationHelper_runForeverAnimation(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YHAnimationHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        cocos2d::Animation* arg0;
        cocos2d::Sprite* arg1;
        ok &= luaval_to_object<cocos2d::Animation>(tolua_S, 2, "cc.Animation",&arg0);
        ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 3, "cc.Sprite",&arg1);
        if(!ok)
            return 0;
        YHAnimationHelper::runForeverAnimation(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "runForeverAnimation",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationHelper_runForeverAnimation'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tools_YHAnimationHelper_runActionWithSprite(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YHAnimationHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 4)
        {
            cocos2d::Sprite* arg0;
            ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 2, "cc.Sprite",&arg0);
            if (!ok) { break; }
            cocos2d::Animation* arg1;
            ok &= luaval_to_object<cocos2d::Animation>(tolua_S, 3, "cc.Animation",&arg1);
            if (!ok) { break; }
            bool arg2;
            ok &= luaval_to_boolean(tolua_S, 4,&arg2);
            if (!ok) { break; }
            AnimatorData* arg3;
            ok &= luaval_to_object<AnimatorData>(tolua_S, 5, "AnimatorData",&arg3);
            if (!ok) { break; }
            YHAnimationHelper::runActionWithSprite(arg0, arg1, arg2, arg3);
            return 0;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 5)
        {
            cocos2d::Sprite* arg0;
            ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 2, "cc.Sprite",&arg0);
            if (!ok) { break; }
            cocos2d::Animation* arg1;
            ok &= luaval_to_object<cocos2d::Animation>(tolua_S, 3, "cc.Animation",&arg1);
            if (!ok) { break; }
            bool arg2;
            ok &= luaval_to_boolean(tolua_S, 4,&arg2);
            if (!ok) { break; }
            AnimatorInitData* arg3;
            ok &= luaval_to_object<AnimatorInitData>(tolua_S, 5, "AnimatorInitData",&arg3);
            if (!ok) { break; }
            AnimatorAnimData* arg4;
            ok &= luaval_to_object<AnimatorAnimData>(tolua_S, 6, "AnimatorAnimData",&arg4);
            if (!ok) { break; }
            YHAnimationHelper::runActionWithSprite(arg0, arg1, arg2, arg3, arg4);
            return 0;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "runActionWithSprite",argc, 5);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationHelper_runActionWithSprite'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tools_YHAnimationHelper_createForeverAnimate(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YHAnimationHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        cocos2d::Animation* arg0;
        ok &= luaval_to_object<cocos2d::Animation>(tolua_S, 2, "cc.Animation",&arg0);
        if(!ok)
            return 0;
        cocos2d::RepeatForever* ret = YHAnimationHelper::createForeverAnimate(arg0);
        object_to_luaval<cocos2d::RepeatForever>(tolua_S, "cc.RepeatForever",(cocos2d::RepeatForever*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "createForeverAnimate",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationHelper_createForeverAnimate'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tools_YHAnimationHelper_runAnimation(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YHAnimationHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        cocos2d::Animation* arg0;
        cocos2d::Sprite* arg1;
        ok &= luaval_to_object<cocos2d::Animation>(tolua_S, 2, "cc.Animation",&arg0);
        ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 3, "cc.Sprite",&arg1);
        if(!ok)
            return 0;
        YHAnimationHelper::runAnimation(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "runAnimation",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationHelper_runAnimation'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tools_YHAnimationHelper_createAnimate(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YHAnimationHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        cocos2d::Animation* arg0;
        ok &= luaval_to_object<cocos2d::Animation>(tolua_S, 2, "cc.Animation",&arg0);
        if(!ok)
            return 0;
        cocos2d::Animate* ret = YHAnimationHelper::createAnimate(arg0);
        object_to_luaval<cocos2d::Animate>(tolua_S, "cc.Animate",(cocos2d::Animate*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "createAnimate",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationHelper_createAnimate'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tools_YHAnimationHelper_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (YHAnimationHelper)");
    return 0;
}

int lua_register_cocos2dx_tools_YHAnimationHelper(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"YHAnimationHelper");
    tolua_cclass(tolua_S,"YHAnimationHelper","YHAnimationHelper","YHObject",nullptr);

    tolua_beginmodule(tolua_S,"YHAnimationHelper");
        tolua_function(tolua_S,"runForeverAnimation", lua_cocos2dx_tools_YHAnimationHelper_runForeverAnimation);
        tolua_function(tolua_S,"runActionWithSprite", lua_cocos2dx_tools_YHAnimationHelper_runActionWithSprite);
        tolua_function(tolua_S,"createForeverAnimate", lua_cocos2dx_tools_YHAnimationHelper_createForeverAnimate);
        tolua_function(tolua_S,"runAnimation", lua_cocos2dx_tools_YHAnimationHelper_runAnimation);
        tolua_function(tolua_S,"createAnimate", lua_cocos2dx_tools_YHAnimationHelper_createAnimate);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(YHAnimationHelper).name();
    g_luaType[typeName] = "YHAnimationHelper";
    g_typeCast["YHAnimationHelper"] = "YHAnimationHelper";
    return 1;
}

int lua_cocos2dx_tools_YHAnimationCache_getAnimationFileDic(lua_State* tolua_S)
{
    int argc = 0;
    YHAnimationCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHAnimationCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHAnimationCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHAnimationCache_getAnimationFileDic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::__Dictionary* ret = cobj->getAnimationFileDic();
        object_to_luaval<cocos2d::__Dictionary>(tolua_S, "cc.__Dictionary",(cocos2d::__Dictionary*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getAnimationFileDic",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationCache_getAnimationFileDic'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHAnimationCache_addAnimations(lua_State* tolua_S)
{
    int argc = 0;
    YHAnimationCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHAnimationCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHAnimationCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHAnimationCache_addAnimations'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::__Dictionary* arg0;

        ok &= luaval_to_object<cocos2d::__Dictionary>(tolua_S, 2, "cc.__Dictionary",&arg0);
        if(!ok)
            return 0;
        cobj->addAnimations(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addAnimations",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationCache_addAnimations'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHAnimationCache_animationForKey_Ver2(lua_State* tolua_S)
{
    int argc = 0;
    YHAnimationCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHAnimationCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHAnimationCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHAnimationCache_animationForKey_Ver2'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cocos2d::Animation* ret = cobj->animationForKey_Ver2(arg0);
        object_to_luaval<cocos2d::Animation>(tolua_S, "cc.Animation",(cocos2d::Animation*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "animationForKey_Ver2",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationCache_animationForKey_Ver2'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHAnimationCache_animationForKey_Ver1(lua_State* tolua_S)
{
    int argc = 0;
    YHAnimationCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHAnimationCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHAnimationCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHAnimationCache_animationForKey_Ver1'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cocos2d::Animation* ret = cobj->animationForKey_Ver1(arg0);
        object_to_luaval<cocos2d::Animation>(tolua_S, "cc.Animation",(cocos2d::Animation*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "animationForKey_Ver1",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationCache_animationForKey_Ver1'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHAnimationCache_cleanAllAnimations(lua_State* tolua_S)
{
    int argc = 0;
    YHAnimationCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHAnimationCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHAnimationCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHAnimationCache_cleanAllAnimations'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->cleanAllAnimations();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cleanAllAnimations",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationCache_cleanAllAnimations'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHAnimationCache_init(lua_State* tolua_S)
{
    int argc = 0;
    YHAnimationCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHAnimationCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHAnimationCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHAnimationCache_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationCache_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHAnimationCache_animationForKeyFromCache_Ver1(lua_State* tolua_S)
{
    int argc = 0;
    YHAnimationCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHAnimationCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHAnimationCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHAnimationCache_animationForKeyFromCache_Ver1'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cocos2d::Animation* ret = cobj->animationForKeyFromCache_Ver1(arg0);
        object_to_luaval<cocos2d::Animation>(tolua_S, "cc.Animation",(cocos2d::Animation*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "animationForKeyFromCache_Ver1",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationCache_animationForKeyFromCache_Ver1'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHAnimationCache_animationForKeyFromCache_Ver2(lua_State* tolua_S)
{
    int argc = 0;
    YHAnimationCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHAnimationCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHAnimationCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHAnimationCache_animationForKeyFromCache_Ver2'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cocos2d::Animation* ret = cobj->animationForKeyFromCache_Ver2(arg0);
        object_to_luaval<cocos2d::Animation>(tolua_S, "cc.Animation",(cocos2d::Animation*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "animationForKeyFromCache_Ver2",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationCache_animationForKeyFromCache_Ver2'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHAnimationCache_foreverAnimateForKey(lua_State* tolua_S)
{
    int argc = 0;
    YHAnimationCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHAnimationCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHAnimationCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHAnimationCache_foreverAnimateForKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cocos2d::RepeatForever* ret = cobj->foreverAnimateForKey(arg0);
        object_to_luaval<cocos2d::RepeatForever>(tolua_S, "cc.RepeatForever",(cocos2d::RepeatForever*)ret);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        bool arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_boolean(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cocos2d::RepeatForever* ret = cobj->foreverAnimateForKey(arg0, arg1);
        object_to_luaval<cocos2d::RepeatForever>(tolua_S, "cc.RepeatForever",(cocos2d::RepeatForever*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "foreverAnimateForKey",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationCache_foreverAnimateForKey'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHAnimationCache_animateForKey(lua_State* tolua_S)
{
    int argc = 0;
    YHAnimationCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHAnimationCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHAnimationCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHAnimationCache_animateForKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cocos2d::Animate* ret = cobj->animateForKey(arg0);
        object_to_luaval<cocos2d::Animate>(tolua_S, "cc.Animate",(cocos2d::Animate*)ret);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        bool arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_boolean(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cocos2d::Animate* ret = cobj->animateForKey(arg0, arg1);
        object_to_luaval<cocos2d::Animate>(tolua_S, "cc.Animate",(cocos2d::Animate*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "animateForKey",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationCache_animateForKey'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHAnimationCache_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YHAnimationCache",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        YHAnimationCache* ret = YHAnimationCache::create();
        object_to_luaval<YHAnimationCache>(tolua_S, "YHAnimationCache",(YHAnimationCache*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationCache_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tools_YHAnimationCache_constructor(lua_State* tolua_S)
{
    int argc = 0;
    YHAnimationCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new YHAnimationCache();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"YHAnimationCache");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "YHAnimationCache",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHAnimationCache_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_tools_YHAnimationCache_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (YHAnimationCache)");
    return 0;
}

int lua_register_cocos2dx_tools_YHAnimationCache(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"YHAnimationCache");
    tolua_cclass(tolua_S,"YHAnimationCache","YHAnimationCache","YHObject",nullptr);

    tolua_beginmodule(tolua_S,"YHAnimationCache");
        tolua_function(tolua_S,"new",lua_cocos2dx_tools_YHAnimationCache_constructor);
        tolua_function(tolua_S,"getAnimationFileDic",lua_cocos2dx_tools_YHAnimationCache_getAnimationFileDic);
        tolua_function(tolua_S,"addAnimations",lua_cocos2dx_tools_YHAnimationCache_addAnimations);
        tolua_function(tolua_S,"animationForKey_Ver2",lua_cocos2dx_tools_YHAnimationCache_animationForKey_Ver2);
        tolua_function(tolua_S,"animationForKey_Ver1",lua_cocos2dx_tools_YHAnimationCache_animationForKey_Ver1);
        tolua_function(tolua_S,"cleanAllAnimations",lua_cocos2dx_tools_YHAnimationCache_cleanAllAnimations);
        tolua_function(tolua_S,"init",lua_cocos2dx_tools_YHAnimationCache_init);
        tolua_function(tolua_S,"animationForKeyFromCache_Ver1",lua_cocos2dx_tools_YHAnimationCache_animationForKeyFromCache_Ver1);
        tolua_function(tolua_S,"animationForKeyFromCache_Ver2",lua_cocos2dx_tools_YHAnimationCache_animationForKeyFromCache_Ver2);
        tolua_function(tolua_S,"foreverAnimateForKey",lua_cocos2dx_tools_YHAnimationCache_foreverAnimateForKey);
        tolua_function(tolua_S,"animateForKey",lua_cocos2dx_tools_YHAnimationCache_animateForKey);
        tolua_function(tolua_S,"create", lua_cocos2dx_tools_YHAnimationCache_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(YHAnimationCache).name();
    g_luaType[typeName] = "YHAnimationCache";
    g_typeCast["YHAnimationCache"] = "YHAnimationCache";
    return 1;
}

int lua_cocos2dx_tools_ActionContext_initialize(lua_State* tolua_S)
{
    int argc = 0;
    ActionContext* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ActionContext",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ActionContext*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_ActionContext_initialize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->initialize();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initialize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_ActionContext_initialize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_ActionContext_getAction(lua_State* tolua_S)
{
    int argc = 0;
    ActionContext* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ActionContext",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (ActionContext*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_ActionContext_getAction'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            cocos2d::__Dictionary* arg0;
            ok &= luaval_to_object<cocos2d::__Dictionary>(tolua_S, 2, "cc.__Dictionary",&arg0);

            if (!ok) { break; }
            cocos2d::Action* ret = cobj->getAction(arg0);
            object_to_luaval<cocos2d::Action>(tolua_S, "cc.Action",(cocos2d::Action*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);

            if (!ok) { break; }
            cocos2d::__Dictionary* arg1;
            ok &= luaval_to_object<cocos2d::__Dictionary>(tolua_S, 3, "cc.__Dictionary",&arg1);

            if (!ok) { break; }
            cocos2d::Action* ret = cobj->getAction(arg0, arg1);
            object_to_luaval<cocos2d::Action>(tolua_S, "cc.Action",(cocos2d::Action*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getAction",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_ActionContext_getAction'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_ActionContext_getContext(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ActionContext",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        ActionContext* ret = ActionContext::getContext();
        object_to_luaval<ActionContext>(tolua_S, "ActionContext",(ActionContext*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "getContext",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_ActionContext_getContext'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tools_ActionContext_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ActionContext)");
    return 0;
}

int lua_register_cocos2dx_tools_ActionContext(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ActionContext");
    tolua_cclass(tolua_S,"ActionContext","ActionContext","YHObject",nullptr);

    tolua_beginmodule(tolua_S,"ActionContext");
        tolua_function(tolua_S,"initialize",lua_cocos2dx_tools_ActionContext_initialize);
        tolua_function(tolua_S,"getAction",lua_cocos2dx_tools_ActionContext_getAction);
        tolua_function(tolua_S,"getContext", lua_cocos2dx_tools_ActionContext_getContext);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(ActionContext).name();
    g_luaType[typeName] = "ActionContext";
    g_typeCast["ActionContext"] = "ActionContext";
    return 1;
}

int lua_cocos2dx_tools_AnimatorInitData_initializeNode(lua_State* tolua_S)
{
    int argc = 0;
    AnimatorInitData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AnimatorInitData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AnimatorInitData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AnimatorInitData_initializeNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Node* arg0;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0);
        if(!ok)
            return 0;
        cobj->initializeNode(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initializeNode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorInitData_initializeNode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AnimatorInitData_setPosScale(lua_State* tolua_S)
{
    int argc = 0;
    AnimatorInitData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AnimatorInitData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AnimatorInitData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AnimatorInitData_setPosScale'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setPosScale(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setPosScale",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorInitData_setPosScale'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AnimatorInitData_tweenToNow(lua_State* tolua_S)
{
    int argc = 0;
    AnimatorInitData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AnimatorInitData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AnimatorInitData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AnimatorInitData_tweenToNow'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Node* arg0;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0);
        if(!ok)
            return 0;
        cobj->tweenToNow(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        cocos2d::Node* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->tweenToNow(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tweenToNow",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorInitData_tweenToNow'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AnimatorInitData_data(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"AnimatorInitData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        cocos2d::__Dictionary* arg0;
        ok &= luaval_to_object<cocos2d::__Dictionary>(tolua_S, 2, "cc.__Dictionary",&arg0);
        if(!ok)
            return 0;
        AnimatorInitData* ret = AnimatorInitData::data(arg0);
        object_to_luaval<AnimatorInitData>(tolua_S, "AnimatorInitData",(AnimatorInitData*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "data",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorInitData_data'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tools_AnimatorInitData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (AnimatorInitData)");
    return 0;
}

int lua_register_cocos2dx_tools_AnimatorInitData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"AnimatorInitData");
    tolua_cclass(tolua_S,"AnimatorInitData","AnimatorInitData","YHObject",nullptr);

    tolua_beginmodule(tolua_S,"AnimatorInitData");
        tolua_function(tolua_S,"initializeNode",lua_cocos2dx_tools_AnimatorInitData_initializeNode);
        tolua_function(tolua_S,"setPosScale",lua_cocos2dx_tools_AnimatorInitData_setPosScale);
        tolua_function(tolua_S,"tweenToNow",lua_cocos2dx_tools_AnimatorInitData_tweenToNow);
        tolua_function(tolua_S,"data", lua_cocos2dx_tools_AnimatorInitData_data);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(AnimatorInitData).name();
    g_luaType[typeName] = "AnimatorInitData";
    g_typeCast["AnimatorInitData"] = "AnimatorInitData";
    return 1;
}

int lua_cocos2dx_tools_AnimatorAnimData_isForever(lua_State* tolua_S)
{
    int argc = 0;
    AnimatorAnimData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AnimatorAnimData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AnimatorAnimData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AnimatorAnimData_isForever'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isForever();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isForever",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorAnimData_isForever'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AnimatorAnimData_getSumTime(lua_State* tolua_S)
{
    int argc = 0;
    AnimatorAnimData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AnimatorAnimData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AnimatorAnimData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AnimatorAnimData_getSumTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->getSumTime();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getSumTime",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorAnimData_getSumTime'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AnimatorAnimData_getDelayTimeAction(lua_State* tolua_S)
{
    int argc = 0;
    AnimatorAnimData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AnimatorAnimData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AnimatorAnimData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AnimatorAnimData_getDelayTimeAction'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::DelayTime* ret = cobj->getDelayTimeAction();
        object_to_luaval<cocos2d::DelayTime>(tolua_S, "cc.DelayTime",(cocos2d::DelayTime*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDelayTimeAction",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorAnimData_getDelayTimeAction'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AnimatorAnimData_runActions(lua_State* tolua_S)
{
    int argc = 0;
    AnimatorAnimData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AnimatorAnimData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AnimatorAnimData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AnimatorAnimData_runActions'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Node* arg0;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0);
        if(!ok)
            return 0;
        cobj->runActions(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        cocos2d::Node* arg0;
        std::vector<int> arg1;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0);

        ok &= luaval_to_std_vector_int(tolua_S, 3, &arg1);
        if(!ok)
            return 0;
        cobj->runActions(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "runActions",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorAnimData_runActions'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AnimatorAnimData_action(lua_State* tolua_S)
{
    int argc = 0;
    AnimatorAnimData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AnimatorAnimData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AnimatorAnimData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AnimatorAnimData_action'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cocos2d::Action* ret = cobj->action(arg0);
        object_to_luaval<cocos2d::Action>(tolua_S, "cc.Action",(cocos2d::Action*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "action",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorAnimData_action'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AnimatorAnimData_setPosScale(lua_State* tolua_S)
{
    int argc = 0;
    AnimatorAnimData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AnimatorAnimData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AnimatorAnimData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AnimatorAnimData_setPosScale'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setPosScale(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setPosScale",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorAnimData_setPosScale'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AnimatorAnimData_getOffsetTime(lua_State* tolua_S)
{
    int argc = 0;
    AnimatorAnimData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AnimatorAnimData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AnimatorAnimData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AnimatorAnimData_getOffsetTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->getOffsetTime();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getOffsetTime",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorAnimData_getOffsetTime'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AnimatorAnimData_data(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"AnimatorAnimData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        cocos2d::__Dictionary* arg0;
        ok &= luaval_to_object<cocos2d::__Dictionary>(tolua_S, 2, "cc.__Dictionary",&arg0);
        if(!ok)
            return 0;
        AnimatorAnimData* ret = AnimatorAnimData::data(arg0);
        object_to_luaval<AnimatorAnimData>(tolua_S, "AnimatorAnimData",(AnimatorAnimData*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "data",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorAnimData_data'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tools_AnimatorAnimData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (AnimatorAnimData)");
    return 0;
}

int lua_register_cocos2dx_tools_AnimatorAnimData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"AnimatorAnimData");
    tolua_cclass(tolua_S,"AnimatorAnimData","AnimatorAnimData","YHObject",nullptr);

    tolua_beginmodule(tolua_S,"AnimatorAnimData");
        tolua_function(tolua_S,"isForever",lua_cocos2dx_tools_AnimatorAnimData_isForever);
        tolua_function(tolua_S,"getSumTime",lua_cocos2dx_tools_AnimatorAnimData_getSumTime);
        tolua_function(tolua_S,"getDelayTimeAction",lua_cocos2dx_tools_AnimatorAnimData_getDelayTimeAction);
        tolua_function(tolua_S,"runActions",lua_cocos2dx_tools_AnimatorAnimData_runActions);
        tolua_function(tolua_S,"action",lua_cocos2dx_tools_AnimatorAnimData_action);
        tolua_function(tolua_S,"setPosScale",lua_cocos2dx_tools_AnimatorAnimData_setPosScale);
        tolua_function(tolua_S,"getOffsetTime",lua_cocos2dx_tools_AnimatorAnimData_getOffsetTime);
        tolua_function(tolua_S,"data", lua_cocos2dx_tools_AnimatorAnimData_data);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(AnimatorAnimData).name();
    g_luaType[typeName] = "AnimatorAnimData";
    g_typeCast["AnimatorAnimData"] = "AnimatorAnimData";
    return 1;
}

int lua_cocos2dx_tools_AnimatorData_getAnimData(lua_State* tolua_S)
{
    int argc = 0;
    AnimatorData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AnimatorData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AnimatorData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AnimatorData_getAnimData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        AnimatorAnimData* ret = cobj->getAnimData();
        object_to_luaval<AnimatorAnimData>(tolua_S, "AnimatorAnimData",(AnimatorAnimData*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getAnimData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorData_getAnimData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AnimatorData_getInitData(lua_State* tolua_S)
{
    int argc = 0;
    AnimatorData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AnimatorData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AnimatorData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AnimatorData_getInitData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        AnimatorInitData* ret = cobj->getInitData();
        object_to_luaval<AnimatorInitData>(tolua_S, "AnimatorInitData",(AnimatorInitData*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getInitData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorData_getInitData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AnimatorData_setPosScale(lua_State* tolua_S)
{
    int argc = 0;
    AnimatorData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AnimatorData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AnimatorData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AnimatorData_setPosScale'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setPosScale(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setPosScale",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorData_setPosScale'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AnimatorData_data(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"AnimatorData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 1)
        {
            cocos2d::__Dictionary* arg0;
            ok &= luaval_to_object<cocos2d::__Dictionary>(tolua_S, 2, "cc.__Dictionary",&arg0);
            if (!ok) { break; }
            AnimatorData* ret = AnimatorData::data(arg0);
            object_to_luaval<AnimatorData>(tolua_S, "AnimatorData",(AnimatorData*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 2)
        {
            AnimatorInitData* arg0;
            ok &= luaval_to_object<AnimatorInitData>(tolua_S, 2, "AnimatorInitData",&arg0);
            if (!ok) { break; }
            AnimatorAnimData* arg1;
            ok &= luaval_to_object<AnimatorAnimData>(tolua_S, 3, "AnimatorAnimData",&arg1);
            if (!ok) { break; }
            AnimatorData* ret = AnimatorData::data(arg0, arg1);
            object_to_luaval<AnimatorData>(tolua_S, "AnimatorData",(AnimatorData*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "data",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorData_data'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tools_AnimatorData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (AnimatorData)");
    return 0;
}

int lua_register_cocos2dx_tools_AnimatorData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"AnimatorData");
    tolua_cclass(tolua_S,"AnimatorData","AnimatorData","YHObject",nullptr);

    tolua_beginmodule(tolua_S,"AnimatorData");
        tolua_function(tolua_S,"getAnimData",lua_cocos2dx_tools_AnimatorData_getAnimData);
        tolua_function(tolua_S,"getInitData",lua_cocos2dx_tools_AnimatorData_getInitData);
        tolua_function(tolua_S,"setPosScale",lua_cocos2dx_tools_AnimatorData_setPosScale);
        tolua_function(tolua_S,"data", lua_cocos2dx_tools_AnimatorData_data);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(AnimatorData).name();
    g_luaType[typeName] = "AnimatorData";
    g_typeCast["AnimatorData"] = "AnimatorData";
    return 1;
}

int lua_cocos2dx_tools_AnimatorModuleData_assignToNode(lua_State* tolua_S)
{
    int argc = 0;
    AnimatorModuleData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AnimatorModuleData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AnimatorModuleData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AnimatorModuleData_assignToNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Node* arg0;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0);
        if(!ok)
            return 0;
        cobj->assignToNode(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "assignToNode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorModuleData_assignToNode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AnimatorModuleData_createSpecialSprite(lua_State* tolua_S)
{
    int argc = 0;
    AnimatorModuleData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AnimatorModuleData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AnimatorModuleData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AnimatorModuleData_createSpecialSprite'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        CCSpecialSprite* ret = cobj->createSpecialSprite();
        object_to_luaval<CCSpecialSprite>(tolua_S, "CCSpecialSprite",(CCSpecialSprite*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "createSpecialSprite",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorModuleData_createSpecialSprite'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AnimatorModuleData_data(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"AnimatorModuleData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        cocos2d::__Dictionary* arg0;
        ok &= luaval_to_object<cocos2d::__Dictionary>(tolua_S, 2, "cc.__Dictionary",&arg0);
        if(!ok)
            return 0;
        AnimatorModuleData* ret = AnimatorModuleData::data(arg0);
        object_to_luaval<AnimatorModuleData>(tolua_S, "AnimatorModuleData",(AnimatorModuleData*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "data",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorModuleData_data'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tools_AnimatorModuleData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (AnimatorModuleData)");
    return 0;
}

int lua_register_cocos2dx_tools_AnimatorModuleData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"AnimatorModuleData");
    tolua_cclass(tolua_S,"AnimatorModuleData","AnimatorModuleData","YHObject",nullptr);

    tolua_beginmodule(tolua_S,"AnimatorModuleData");
        tolua_function(tolua_S,"assignToNode",lua_cocos2dx_tools_AnimatorModuleData_assignToNode);
        tolua_function(tolua_S,"createSpecialSprite",lua_cocos2dx_tools_AnimatorModuleData_createSpecialSprite);
        tolua_function(tolua_S,"data", lua_cocos2dx_tools_AnimatorModuleData_data);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(AnimatorModuleData).name();
    g_luaType[typeName] = "AnimatorModuleData";
    g_typeCast["AnimatorModuleData"] = "AnimatorModuleData";
    return 1;
}

int lua_cocos2dx_tools_AnimatorSettingData_data(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"AnimatorSettingData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        cocos2d::__Dictionary* arg0;
        ok &= luaval_to_object<cocos2d::__Dictionary>(tolua_S, 2, "cc.__Dictionary",&arg0);
        if(!ok)
            return 0;
        AnimatorSettingData* ret = AnimatorSettingData::data(arg0);
        object_to_luaval<AnimatorSettingData>(tolua_S, "AnimatorSettingData",(AnimatorSettingData*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "data",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorSettingData_data'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tools_AnimatorSettingData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (AnimatorSettingData)");
    return 0;
}

int lua_register_cocos2dx_tools_AnimatorSettingData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"AnimatorSettingData");
    tolua_cclass(tolua_S,"AnimatorSettingData","AnimatorSettingData","YHObject",nullptr);

    tolua_beginmodule(tolua_S,"AnimatorSettingData");
        tolua_function(tolua_S,"data", lua_cocos2dx_tools_AnimatorSettingData_data);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(AnimatorSettingData).name();
    g_luaType[typeName] = "AnimatorSettingData";
    g_typeCast["AnimatorSettingData"] = "AnimatorSettingData";
    return 1;
}

int lua_cocos2dx_tools_AnimatorDataCache_addData(lua_State* tolua_S)
{
    int argc = 0;
    AnimatorDataCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AnimatorDataCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AnimatorDataCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AnimatorDataCache_addData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        AnimatorData* arg0;
        std::string arg1;

        ok &= luaval_to_object<AnimatorData>(tolua_S, 2, "AnimatorData",&arg0);

        ok &= luaval_to_std_string(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->addData(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addData",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorDataCache_addData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AnimatorDataCache_autorelease(lua_State* tolua_S)
{
    int argc = 0;
    AnimatorDataCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AnimatorDataCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AnimatorDataCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AnimatorDataCache_autorelease'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Ref* ret = cobj->autorelease();
        object_to_luaval<cocos2d::Ref>(tolua_S, "cc.Ref",(cocos2d::Ref*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "autorelease",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorDataCache_autorelease'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AnimatorDataCache_clean(lua_State* tolua_S)
{
    int argc = 0;
    AnimatorDataCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AnimatorDataCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AnimatorDataCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AnimatorDataCache_clean'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->clean();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "clean",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorDataCache_clean'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AnimatorDataCache_release(lua_State* tolua_S)
{
    int argc = 0;
    AnimatorDataCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AnimatorDataCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AnimatorDataCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AnimatorDataCache_release'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->release();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "release",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorDataCache_release'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AnimatorDataCache_retain(lua_State* tolua_S)
{
    int argc = 0;
    AnimatorDataCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AnimatorDataCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AnimatorDataCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AnimatorDataCache_retain'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->retain();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "retain",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorDataCache_retain'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AnimatorDataCache_getData(lua_State* tolua_S)
{
    int argc = 0;
    AnimatorDataCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AnimatorDataCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AnimatorDataCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AnimatorDataCache_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        AnimatorData* ret = cobj->getData(arg0);
        object_to_luaval<AnimatorData>(tolua_S, "AnimatorData",(AnimatorData*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorDataCache_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AnimatorDataCache_sharedCache(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"AnimatorDataCache",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        AnimatorDataCache* ret = AnimatorDataCache::sharedCache();
        object_to_luaval<AnimatorDataCache>(tolua_S, "AnimatorDataCache",(AnimatorDataCache*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "sharedCache",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorDataCache_sharedCache'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tools_AnimatorDataCache_constructor(lua_State* tolua_S)
{
    int argc = 0;
    AnimatorDataCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new AnimatorDataCache();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"AnimatorDataCache");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "AnimatorDataCache",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorDataCache_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_tools_AnimatorDataCache_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (AnimatorDataCache)");
    return 0;
}

int lua_register_cocos2dx_tools_AnimatorDataCache(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"AnimatorDataCache");
    tolua_cclass(tolua_S,"AnimatorDataCache","AnimatorDataCache","YHObject",nullptr);

    tolua_beginmodule(tolua_S,"AnimatorDataCache");
        tolua_function(tolua_S,"new",lua_cocos2dx_tools_AnimatorDataCache_constructor);
        tolua_function(tolua_S,"addData",lua_cocos2dx_tools_AnimatorDataCache_addData);
        tolua_function(tolua_S,"autorelease",lua_cocos2dx_tools_AnimatorDataCache_autorelease);
        tolua_function(tolua_S,"clean",lua_cocos2dx_tools_AnimatorDataCache_clean);
        tolua_function(tolua_S,"release",lua_cocos2dx_tools_AnimatorDataCache_release);
        tolua_function(tolua_S,"retain",lua_cocos2dx_tools_AnimatorDataCache_retain);
        tolua_function(tolua_S,"getData",lua_cocos2dx_tools_AnimatorDataCache_getData);
        tolua_function(tolua_S,"sharedCache", lua_cocos2dx_tools_AnimatorDataCache_sharedCache);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(AnimatorDataCache).name();
    g_luaType[typeName] = "AnimatorDataCache";
    g_typeCast["AnimatorDataCache"] = "AnimatorDataCache";
    return 1;
}

int lua_cocos2dx_tools_AnimatorModuleDataCache_addData(lua_State* tolua_S)
{
    int argc = 0;
    AnimatorModuleDataCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AnimatorModuleDataCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AnimatorModuleDataCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AnimatorModuleDataCache_addData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        AnimatorModuleData* arg0;
        std::string arg1;

        ok &= luaval_to_object<AnimatorModuleData>(tolua_S, 2, "AnimatorModuleData",&arg0);

        ok &= luaval_to_std_string(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->addData(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addData",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorModuleDataCache_addData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AnimatorModuleDataCache_autorelease(lua_State* tolua_S)
{
    int argc = 0;
    AnimatorModuleDataCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AnimatorModuleDataCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AnimatorModuleDataCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AnimatorModuleDataCache_autorelease'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Ref* ret = cobj->autorelease();
        object_to_luaval<cocos2d::Ref>(tolua_S, "cc.Ref",(cocos2d::Ref*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "autorelease",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorModuleDataCache_autorelease'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AnimatorModuleDataCache_clean(lua_State* tolua_S)
{
    int argc = 0;
    AnimatorModuleDataCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AnimatorModuleDataCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AnimatorModuleDataCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AnimatorModuleDataCache_clean'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->clean();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "clean",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorModuleDataCache_clean'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AnimatorModuleDataCache_release(lua_State* tolua_S)
{
    int argc = 0;
    AnimatorModuleDataCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AnimatorModuleDataCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AnimatorModuleDataCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AnimatorModuleDataCache_release'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->release();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "release",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorModuleDataCache_release'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AnimatorModuleDataCache_retain(lua_State* tolua_S)
{
    int argc = 0;
    AnimatorModuleDataCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AnimatorModuleDataCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AnimatorModuleDataCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AnimatorModuleDataCache_retain'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->retain();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "retain",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorModuleDataCache_retain'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AnimatorModuleDataCache_getData(lua_State* tolua_S)
{
    int argc = 0;
    AnimatorModuleDataCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AnimatorModuleDataCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AnimatorModuleDataCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AnimatorModuleDataCache_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        AnimatorModuleData* ret = cobj->getData(arg0);
        object_to_luaval<AnimatorModuleData>(tolua_S, "AnimatorModuleData",(AnimatorModuleData*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorModuleDataCache_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AnimatorModuleDataCache_sharedCache(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"AnimatorModuleDataCache",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        AnimatorModuleDataCache* ret = AnimatorModuleDataCache::sharedCache();
        object_to_luaval<AnimatorModuleDataCache>(tolua_S, "AnimatorModuleDataCache",(AnimatorModuleDataCache*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "sharedCache",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorModuleDataCache_sharedCache'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tools_AnimatorModuleDataCache_constructor(lua_State* tolua_S)
{
    int argc = 0;
    AnimatorModuleDataCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new AnimatorModuleDataCache();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"AnimatorModuleDataCache");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "AnimatorModuleDataCache",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorModuleDataCache_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_tools_AnimatorModuleDataCache_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (AnimatorModuleDataCache)");
    return 0;
}

int lua_register_cocos2dx_tools_AnimatorModuleDataCache(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"AnimatorModuleDataCache");
    tolua_cclass(tolua_S,"AnimatorModuleDataCache","AnimatorModuleDataCache","YHObject",nullptr);

    tolua_beginmodule(tolua_S,"AnimatorModuleDataCache");
        tolua_function(tolua_S,"new",lua_cocos2dx_tools_AnimatorModuleDataCache_constructor);
        tolua_function(tolua_S,"addData",lua_cocos2dx_tools_AnimatorModuleDataCache_addData);
        tolua_function(tolua_S,"autorelease",lua_cocos2dx_tools_AnimatorModuleDataCache_autorelease);
        tolua_function(tolua_S,"clean",lua_cocos2dx_tools_AnimatorModuleDataCache_clean);
        tolua_function(tolua_S,"release",lua_cocos2dx_tools_AnimatorModuleDataCache_release);
        tolua_function(tolua_S,"retain",lua_cocos2dx_tools_AnimatorModuleDataCache_retain);
        tolua_function(tolua_S,"getData",lua_cocos2dx_tools_AnimatorModuleDataCache_getData);
        tolua_function(tolua_S,"sharedCache", lua_cocos2dx_tools_AnimatorModuleDataCache_sharedCache);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(AnimatorModuleDataCache).name();
    g_luaType[typeName] = "AnimatorModuleDataCache";
    g_typeCast["AnimatorModuleDataCache"] = "AnimatorModuleDataCache";
    return 1;
}

int lua_cocos2dx_tools_AnimatorSettingDataCache_addData(lua_State* tolua_S)
{
    int argc = 0;
    AnimatorSettingDataCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AnimatorSettingDataCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AnimatorSettingDataCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AnimatorSettingDataCache_addData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        AnimatorSettingData* arg0;
        std::string arg1;

        ok &= luaval_to_object<AnimatorSettingData>(tolua_S, 2, "AnimatorSettingData",&arg0);

        ok &= luaval_to_std_string(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->addData(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addData",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorSettingDataCache_addData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AnimatorSettingDataCache_autorelease(lua_State* tolua_S)
{
    int argc = 0;
    AnimatorSettingDataCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AnimatorSettingDataCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AnimatorSettingDataCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AnimatorSettingDataCache_autorelease'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Ref* ret = cobj->autorelease();
        object_to_luaval<cocos2d::Ref>(tolua_S, "cc.Ref",(cocos2d::Ref*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "autorelease",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorSettingDataCache_autorelease'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AnimatorSettingDataCache_clean(lua_State* tolua_S)
{
    int argc = 0;
    AnimatorSettingDataCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AnimatorSettingDataCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AnimatorSettingDataCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AnimatorSettingDataCache_clean'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->clean();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "clean",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorSettingDataCache_clean'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AnimatorSettingDataCache_release(lua_State* tolua_S)
{
    int argc = 0;
    AnimatorSettingDataCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AnimatorSettingDataCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AnimatorSettingDataCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AnimatorSettingDataCache_release'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->release();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "release",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorSettingDataCache_release'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AnimatorSettingDataCache_retain(lua_State* tolua_S)
{
    int argc = 0;
    AnimatorSettingDataCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AnimatorSettingDataCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AnimatorSettingDataCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AnimatorSettingDataCache_retain'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->retain();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "retain",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorSettingDataCache_retain'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AnimatorSettingDataCache_getData(lua_State* tolua_S)
{
    int argc = 0;
    AnimatorSettingDataCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AnimatorSettingDataCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AnimatorSettingDataCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AnimatorSettingDataCache_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        AnimatorSettingData* ret = cobj->getData(arg0);
        object_to_luaval<AnimatorSettingData>(tolua_S, "AnimatorSettingData",(AnimatorSettingData*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorSettingDataCache_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AnimatorSettingDataCache_sharedCache(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"AnimatorSettingDataCache",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        AnimatorSettingDataCache* ret = AnimatorSettingDataCache::sharedCache();
        object_to_luaval<AnimatorSettingDataCache>(tolua_S, "AnimatorSettingDataCache",(AnimatorSettingDataCache*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "sharedCache",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorSettingDataCache_sharedCache'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tools_AnimatorSettingDataCache_constructor(lua_State* tolua_S)
{
    int argc = 0;
    AnimatorSettingDataCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new AnimatorSettingDataCache();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"AnimatorSettingDataCache");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "AnimatorSettingDataCache",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AnimatorSettingDataCache_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_tools_AnimatorSettingDataCache_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (AnimatorSettingDataCache)");
    return 0;
}

int lua_register_cocos2dx_tools_AnimatorSettingDataCache(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"AnimatorSettingDataCache");
    tolua_cclass(tolua_S,"AnimatorSettingDataCache","AnimatorSettingDataCache","YHObject",nullptr);

    tolua_beginmodule(tolua_S,"AnimatorSettingDataCache");
        tolua_function(tolua_S,"new",lua_cocos2dx_tools_AnimatorSettingDataCache_constructor);
        tolua_function(tolua_S,"addData",lua_cocos2dx_tools_AnimatorSettingDataCache_addData);
        tolua_function(tolua_S,"autorelease",lua_cocos2dx_tools_AnimatorSettingDataCache_autorelease);
        tolua_function(tolua_S,"clean",lua_cocos2dx_tools_AnimatorSettingDataCache_clean);
        tolua_function(tolua_S,"release",lua_cocos2dx_tools_AnimatorSettingDataCache_release);
        tolua_function(tolua_S,"retain",lua_cocos2dx_tools_AnimatorSettingDataCache_retain);
        tolua_function(tolua_S,"getData",lua_cocos2dx_tools_AnimatorSettingDataCache_getData);
        tolua_function(tolua_S,"sharedCache", lua_cocos2dx_tools_AnimatorSettingDataCache_sharedCache);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(AnimatorSettingDataCache).name();
    g_luaType[typeName] = "AnimatorSettingDataCache";
    g_typeCast["AnimatorSettingDataCache"] = "AnimatorSettingDataCache";
    return 1;
}

int lua_cocos2dx_tools_YHCCActionHelper_runIntervalForeverAnimation2(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YHCCActionHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        double arg0;
        cocos2d::Animation* arg1;
        cocos2d::Sprite* arg2;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_object<cocos2d::Animation>(tolua_S, 3, "cc.Animation",&arg1);
        ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 4, "cc.Sprite",&arg2);
        if(!ok)
            return 0;
        YHCCActionHelper::runIntervalForeverAnimation2(arg0, arg1, arg2);
        return 0;
    }
    if (argc == 4)
    {
        double arg0;
        cocos2d::Animation* arg1;
        cocos2d::Sprite* arg2;
        std::function<void ()> arg3;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_object<cocos2d::Animation>(tolua_S, 3, "cc.Animation",&arg1);
        ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 4, "cc.Sprite",&arg2);
        do {
			// Lambda binding for lua is not supported.
			assert(false);
		} while(0)
		;
        if(!ok)
            return 0;
        YHCCActionHelper::runIntervalForeverAnimation2(arg0, arg1, arg2, arg3);
        return 0;
    }
    if (argc == 5)
    {
        double arg0;
        cocos2d::Animation* arg1;
        cocos2d::Sprite* arg2;
        std::function<void ()> arg3;
        std::function<void ()> arg4;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_object<cocos2d::Animation>(tolua_S, 3, "cc.Animation",&arg1);
        ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 4, "cc.Sprite",&arg2);
        do {
			// Lambda binding for lua is not supported.
			assert(false);
		} while(0)
		;
        do {
			// Lambda binding for lua is not supported.
			assert(false);
		} while(0)
		;
        if(!ok)
            return 0;
        YHCCActionHelper::runIntervalForeverAnimation2(arg0, arg1, arg2, arg3, arg4);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "runIntervalForeverAnimation2",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHCCActionHelper_runIntervalForeverAnimation2'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tools_YHCCActionHelper_runNormalForeverScale(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YHCCActionHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 4)
    {
        double arg0;
        double arg1;
        double arg2;
        cocos2d::Node* arg3;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_number(tolua_S, 3,&arg1);
        ok &= luaval_to_number(tolua_S, 4,&arg2);
        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 5, "cc.Node",&arg3);
        if(!ok)
            return 0;
        YHCCActionHelper::runNormalForeverScale(arg0, arg1, arg2, arg3);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "runNormalForeverScale",argc, 4);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHCCActionHelper_runNormalForeverScale'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tools_YHCCActionHelper_runNormalForeverMove(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YHCCActionHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        cocos2d::Point arg0;
        double arg1;
        cocos2d::Node* arg2;
        ok &= luaval_to_point(tolua_S, 2, &arg0);
        ok &= luaval_to_number(tolua_S, 3,&arg1);
        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 4, "cc.Node",&arg2);
        if(!ok)
            return 0;
        YHCCActionHelper::runNormalForeverMove(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "runNormalForeverMove",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHCCActionHelper_runNormalForeverMove'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tools_YHCCActionHelper_runForeverFadeInOut(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YHCCActionHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        cocos2d::Node* arg0;
        double arg1;
        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0);
        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        YHCCActionHelper::runForeverFadeInOut(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "runForeverFadeInOut",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHCCActionHelper_runForeverFadeInOut'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tools_YHCCActionHelper_runIntervalForeverAnimation(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YHCCActionHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        double arg0;
        cocos2d::Animation* arg1;
        cocos2d::Sprite* arg2;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_object<cocos2d::Animation>(tolua_S, 3, "cc.Animation",&arg1);
        ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 4, "cc.Sprite",&arg2);
        if(!ok)
            return 0;
        YHCCActionHelper::runIntervalForeverAnimation(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "runIntervalForeverAnimation",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHCCActionHelper_runIntervalForeverAnimation'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tools_YHCCActionHelper_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (YHCCActionHelper)");
    return 0;
}

int lua_register_cocos2dx_tools_YHCCActionHelper(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"YHCCActionHelper");
    tolua_cclass(tolua_S,"YHCCActionHelper","YHCCActionHelper","YHObject",nullptr);

    tolua_beginmodule(tolua_S,"YHCCActionHelper");
        tolua_function(tolua_S,"runIntervalForeverAnimation2", lua_cocos2dx_tools_YHCCActionHelper_runIntervalForeverAnimation2);
        tolua_function(tolua_S,"runNormalForeverScale", lua_cocos2dx_tools_YHCCActionHelper_runNormalForeverScale);
        tolua_function(tolua_S,"runNormalForeverMove", lua_cocos2dx_tools_YHCCActionHelper_runNormalForeverMove);
        tolua_function(tolua_S,"runForeverFadeInOut", lua_cocos2dx_tools_YHCCActionHelper_runForeverFadeInOut);
        tolua_function(tolua_S,"runIntervalForeverAnimation", lua_cocos2dx_tools_YHCCActionHelper_runIntervalForeverAnimation);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(YHCCActionHelper).name();
    g_luaType[typeName] = "YHCCActionHelper";
    g_typeCast["YHCCActionHelper"] = "YHCCActionHelper";
    return 1;
}

int lua_cocos2dx_tools_YHDefaultFiniteEffect_reset(lua_State* tolua_S)
{
    int argc = 0;
    YHDefaultFiniteEffect* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHDefaultFiniteEffect",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (YHDefaultFiniteEffect*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHDefaultFiniteEffect_reset'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            cocos2d::__Array* arg0;
            ok &= luaval_to_object<cocos2d::__Array>(tolua_S, 2, "cc.__Array",&arg0);

            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1);

            if (!ok) { break; }
            cobj->reset(arg0, arg1);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            cocos2d::FiniteTimeAction* arg0;
            ok &= luaval_to_object<cocos2d::FiniteTimeAction>(tolua_S, 2, "cc.FiniteTimeAction",&arg0);

            if (!ok) { break; }
            cobj->reset(arg0);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0);

            if (!ok) { break; }
            cobj->reset(arg0);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            cobj->reset();
            return 0;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "reset",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHDefaultFiniteEffect_reset'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHDefaultFiniteEffect_setColor(lua_State* tolua_S)
{
    int argc = 0;
    YHDefaultFiniteEffect* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHDefaultFiniteEffect",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHDefaultFiniteEffect*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHDefaultFiniteEffect_setColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color3B arg0;

        ok &= luaval_to_color3b(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setColor(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHDefaultFiniteEffect_setColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHDefaultFiniteEffect_resetBasicParams(lua_State* tolua_S)
{
    int argc = 0;
    YHDefaultFiniteEffect* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHDefaultFiniteEffect",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHDefaultFiniteEffect*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHDefaultFiniteEffect_resetBasicParams'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->resetBasicParams();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "resetBasicParams",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHDefaultFiniteEffect_resetBasicParams'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHDefaultFiniteEffect_setParent(lua_State* tolua_S)
{
    int argc = 0;
    YHDefaultFiniteEffect* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHDefaultFiniteEffect",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHDefaultFiniteEffect*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHDefaultFiniteEffect_setParent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Node* arg0;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0);
        if(!ok)
            return 0;
        cobj->setParent(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setParent",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHDefaultFiniteEffect_setParent'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHDefaultFiniteEffect_autoRemoveFromParent(lua_State* tolua_S)
{
    int argc = 0;
    YHDefaultFiniteEffect* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHDefaultFiniteEffect",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHDefaultFiniteEffect*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHDefaultFiniteEffect_autoRemoveFromParent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->autoRemoveFromParent();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "autoRemoveFromParent",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHDefaultFiniteEffect_autoRemoveFromParent'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHDefaultFiniteEffect_isActive(lua_State* tolua_S)
{
    int argc = 0;
    YHDefaultFiniteEffect* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHDefaultFiniteEffect",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHDefaultFiniteEffect*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHDefaultFiniteEffect_isActive'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isActive();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isActive",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHDefaultFiniteEffect_isActive'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHDefaultFiniteEffect_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YHDefaultFiniteEffect",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 1)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            YHDefaultFiniteEffect* ret = YHDefaultFiniteEffect::create(arg0);
            object_to_luaval<YHDefaultFiniteEffect>(tolua_S, "YHDefaultFiniteEffect",(YHDefaultFiniteEffect*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            YHDefaultFiniteEffect* ret = YHDefaultFiniteEffect::create();
            object_to_luaval<YHDefaultFiniteEffect>(tolua_S, "YHDefaultFiniteEffect",(YHDefaultFiniteEffect*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 2)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            cocos2d::Rect arg1;
            ok &= luaval_to_rect(tolua_S, 3, &arg1);
            if (!ok) { break; }
            YHDefaultFiniteEffect* ret = YHDefaultFiniteEffect::create(arg0, arg1);
            object_to_luaval<YHDefaultFiniteEffect>(tolua_S, "YHDefaultFiniteEffect",(YHDefaultFiniteEffect*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHDefaultFiniteEffect_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tools_YHDefaultFiniteEffect_createWithTexture(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YHDefaultFiniteEffect",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 2)
        {
            cocos2d::Texture2D* arg0;
            ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);
            if (!ok) { break; }
            cocos2d::Rect arg1;
            ok &= luaval_to_rect(tolua_S, 3, &arg1);
            if (!ok) { break; }
            YHDefaultFiniteEffect* ret = YHDefaultFiniteEffect::createWithTexture(arg0, arg1);
            object_to_luaval<YHDefaultFiniteEffect>(tolua_S, "YHDefaultFiniteEffect",(YHDefaultFiniteEffect*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 1)
        {
            cocos2d::Texture2D* arg0;
            ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);
            if (!ok) { break; }
            YHDefaultFiniteEffect* ret = YHDefaultFiniteEffect::createWithTexture(arg0);
            object_to_luaval<YHDefaultFiniteEffect>(tolua_S, "YHDefaultFiniteEffect",(YHDefaultFiniteEffect*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "createWithTexture",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHDefaultFiniteEffect_createWithTexture'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tools_YHDefaultFiniteEffect_createWithSpriteFrameName(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YHDefaultFiniteEffect",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        YHDefaultFiniteEffect* ret = YHDefaultFiniteEffect::createWithSpriteFrameName(arg0);
        object_to_luaval<YHDefaultFiniteEffect>(tolua_S, "YHDefaultFiniteEffect",(YHDefaultFiniteEffect*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "createWithSpriteFrameName",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHDefaultFiniteEffect_createWithSpriteFrameName'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tools_YHDefaultFiniteEffect_createWithSpriteFrame(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YHDefaultFiniteEffect",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        cocos2d::SpriteFrame* arg0;
        ok &= luaval_to_object<cocos2d::SpriteFrame>(tolua_S, 2, "cc.SpriteFrame",&arg0);
        if(!ok)
            return 0;
        YHDefaultFiniteEffect* ret = YHDefaultFiniteEffect::createWithSpriteFrame(arg0);
        object_to_luaval<YHDefaultFiniteEffect>(tolua_S, "YHDefaultFiniteEffect",(YHDefaultFiniteEffect*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "createWithSpriteFrame",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHDefaultFiniteEffect_createWithSpriteFrame'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tools_YHDefaultFiniteEffect_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (YHDefaultFiniteEffect)");
    return 0;
}

int lua_register_cocos2dx_tools_YHDefaultFiniteEffect(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"YHDefaultFiniteEffect");
    tolua_cclass(tolua_S,"YHDefaultFiniteEffect","YHDefaultFiniteEffect","cc.Sprite",nullptr);

    tolua_beginmodule(tolua_S,"YHDefaultFiniteEffect");
        tolua_function(tolua_S,"reset",lua_cocos2dx_tools_YHDefaultFiniteEffect_reset);
        tolua_function(tolua_S,"setColor",lua_cocos2dx_tools_YHDefaultFiniteEffect_setColor);
        tolua_function(tolua_S,"resetBasicParams",lua_cocos2dx_tools_YHDefaultFiniteEffect_resetBasicParams);
        tolua_function(tolua_S,"setParent",lua_cocos2dx_tools_YHDefaultFiniteEffect_setParent);
        tolua_function(tolua_S,"autoRemoveFromParent",lua_cocos2dx_tools_YHDefaultFiniteEffect_autoRemoveFromParent);
        tolua_function(tolua_S,"isActive",lua_cocos2dx_tools_YHDefaultFiniteEffect_isActive);
        tolua_function(tolua_S,"create", lua_cocos2dx_tools_YHDefaultFiniteEffect_create);
        tolua_function(tolua_S,"createWithTexture", lua_cocos2dx_tools_YHDefaultFiniteEffect_createWithTexture);
        tolua_function(tolua_S,"createWithSpriteFrameName", lua_cocos2dx_tools_YHDefaultFiniteEffect_createWithSpriteFrameName);
        tolua_function(tolua_S,"createWithSpriteFrame", lua_cocos2dx_tools_YHDefaultFiniteEffect_createWithSpriteFrame);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(YHDefaultFiniteEffect).name();
    g_luaType[typeName] = "YHDefaultFiniteEffect";
    g_typeCast["YHDefaultFiniteEffect"] = "YHDefaultFiniteEffect";
    return 1;
}

int lua_cocos2dx_tools_CCSpecialSprite_draw(lua_State* tolua_S)
{
    int argc = 0;
    CCSpecialSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCSpecialSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCSpecialSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_CCSpecialSprite_draw'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Renderer* arg0;
        cocos2d::kmMat4 arg1;
        bool arg2;

        ok &= luaval_to_object<cocos2d::Renderer>(tolua_S, 2, "cc.Renderer",&arg0);

        ok &= luaval_to_kmMat4(tolua_S, 3, &arg1);

        ok &= luaval_to_boolean(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        cobj->draw(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "draw",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_CCSpecialSprite_draw'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_CCSpecialSprite_initWithFile(lua_State* tolua_S)
{
    int argc = 0;
    CCSpecialSprite* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCSpecialSprite",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CCSpecialSprite*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_CCSpecialSprite_initWithFile'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);

            if (!ok) { break; }
            cocos2d::Rect arg1;
            ok &= luaval_to_rect(tolua_S, 3, &arg1);

            if (!ok) { break; }
            bool ret = cobj->initWithFile(arg0, arg1);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);

            if (!ok) { break; }
            bool ret = cobj->initWithFile(arg0);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initWithFile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_CCSpecialSprite_initWithFile'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_CCSpecialSprite_initWithSpriteFrameName(lua_State* tolua_S)
{
    int argc = 0;
    CCSpecialSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCSpecialSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCSpecialSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_CCSpecialSprite_initWithSpriteFrameName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        bool ret = cobj->initWithSpriteFrameName(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initWithSpriteFrameName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_CCSpecialSprite_initWithSpriteFrameName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_CCSpecialSprite_initWithSpriteFrame(lua_State* tolua_S)
{
    int argc = 0;
    CCSpecialSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCSpecialSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCSpecialSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_CCSpecialSprite_initWithSpriteFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::SpriteFrame* arg0;

        ok &= luaval_to_object<cocos2d::SpriteFrame>(tolua_S, 2, "cc.SpriteFrame",&arg0);
        if(!ok)
            return 0;
        bool ret = cobj->initWithSpriteFrame(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initWithSpriteFrame",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_CCSpecialSprite_initWithSpriteFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_CCSpecialSprite_init(lua_State* tolua_S)
{
    int argc = 0;
    CCSpecialSprite* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCSpecialSprite",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CCSpecialSprite*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_CCSpecialSprite_init'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            cocos2d::__Dictionary* arg0;
            ok &= luaval_to_object<cocos2d::__Dictionary>(tolua_S, 2, "cc.__Dictionary",&arg0);

            if (!ok) { break; }
            bool ret = cobj->init(arg0);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            bool ret = cobj->init();
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            AnimatorModuleData* arg0;
            ok &= luaval_to_object<AnimatorModuleData>(tolua_S, 2, "AnimatorModuleData",&arg0);

            if (!ok) { break; }
            bool ret = cobj->init(arg0);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_CCSpecialSprite_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_CCSpecialSprite_initWithTexture(lua_State* tolua_S)
{
    int argc = 0;
    CCSpecialSprite* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCSpecialSprite",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CCSpecialSprite*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_CCSpecialSprite_initWithTexture'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            cocos2d::Texture2D* arg0;
            ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);

            if (!ok) { break; }
            cocos2d::Rect arg1;
            ok &= luaval_to_rect(tolua_S, 3, &arg1);

            if (!ok) { break; }
            bool ret = cobj->initWithTexture(arg0, arg1);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            cocos2d::Texture2D* arg0;
            ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);

            if (!ok) { break; }
            bool ret = cobj->initWithTexture(arg0);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 3) {
            cocos2d::Texture2D* arg0;
            ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);

            if (!ok) { break; }
            cocos2d::Rect arg1;
            ok &= luaval_to_rect(tolua_S, 3, &arg1);

            if (!ok) { break; }
            bool arg2;
            ok &= luaval_to_boolean(tolua_S, 4,&arg2);

            if (!ok) { break; }
            bool ret = cobj->initWithTexture(arg0, arg1, arg2);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initWithTexture",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_CCSpecialSprite_initWithTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_CCSpecialSprite_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CCSpecialSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 1)
        {
            cocos2d::__Dictionary* arg0;
            ok &= luaval_to_object<cocos2d::__Dictionary>(tolua_S, 2, "cc.__Dictionary",&arg0);
            if (!ok) { break; }
            CCSpecialSprite* ret = CCSpecialSprite::create(arg0);
            object_to_luaval<CCSpecialSprite>(tolua_S, "CCSpecialSprite",(CCSpecialSprite*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            CCSpecialSprite* ret = CCSpecialSprite::create();
            object_to_luaval<CCSpecialSprite>(tolua_S, "CCSpecialSprite",(CCSpecialSprite*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 1)
        {
            AnimatorModuleData* arg0;
            ok &= luaval_to_object<AnimatorModuleData>(tolua_S, 2, "AnimatorModuleData",&arg0);
            if (!ok) { break; }
            CCSpecialSprite* ret = CCSpecialSprite::create(arg0);
            object_to_luaval<CCSpecialSprite>(tolua_S, "CCSpecialSprite",(CCSpecialSprite*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_CCSpecialSprite_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tools_CCSpecialSprite_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSpecialSprite)");
    return 0;
}

int lua_register_cocos2dx_tools_CCSpecialSprite(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CCSpecialSprite");
    tolua_cclass(tolua_S,"CCSpecialSprite","CCSpecialSprite","cc.Sprite",nullptr);

    tolua_beginmodule(tolua_S,"CCSpecialSprite");
        tolua_function(tolua_S,"draw",lua_cocos2dx_tools_CCSpecialSprite_draw);
        tolua_function(tolua_S,"initWithFile",lua_cocos2dx_tools_CCSpecialSprite_initWithFile);
        tolua_function(tolua_S,"initWithSpriteFrameName",lua_cocos2dx_tools_CCSpecialSprite_initWithSpriteFrameName);
        tolua_function(tolua_S,"initWithSpriteFrame",lua_cocos2dx_tools_CCSpecialSprite_initWithSpriteFrame);
        tolua_function(tolua_S,"init",lua_cocos2dx_tools_CCSpecialSprite_init);
        tolua_function(tolua_S,"initWithTexture",lua_cocos2dx_tools_CCSpecialSprite_initWithTexture);
        tolua_function(tolua_S,"create", lua_cocos2dx_tools_CCSpecialSprite_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CCSpecialSprite).name();
    g_luaType[typeName] = "CCSpecialSprite";
    g_typeCast["CCSpecialSprite"] = "CCSpecialSprite";
    return 1;
}

int lua_cocos2dx_tools_YHEffectDefiner_getAnimationName(lua_State* tolua_S)
{
    int argc = 0;
    YHEffectDefiner* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHEffectDefiner",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHEffectDefiner*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHEffectDefiner_getAnimationName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const char* ret = cobj->getAnimationName();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getAnimationName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHEffectDefiner_getAnimationName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHEffectDefiner_getType(lua_State* tolua_S)
{
    int argc = 0;
    YHEffectDefiner* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHEffectDefiner",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHEffectDefiner*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHEffectDefiner_getType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = (int)cobj->getType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHEffectDefiner_getType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHEffectDefiner_setSpriteDefiner(lua_State* tolua_S)
{
    int argc = 0;
    YHEffectDefiner* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHEffectDefiner",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHEffectDefiner*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHEffectDefiner_setSpriteDefiner'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        YHSpriteDefiner* arg0;

        ok &= luaval_to_object<YHSpriteDefiner>(tolua_S, 2, "YHSpriteDefiner",&arg0);
        if(!ok)
            return 0;
        cobj->setSpriteDefiner(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setSpriteDefiner",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHEffectDefiner_setSpriteDefiner'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHEffectDefiner_getSpriteDefiner(lua_State* tolua_S)
{
    int argc = 0;
    YHEffectDefiner* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHEffectDefiner",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHEffectDefiner*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHEffectDefiner_getSpriteDefiner'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        YHSpriteDefiner* ret = cobj->getSpriteDefiner();
        object_to_luaval<YHSpriteDefiner>(tolua_S, "YHSpriteDefiner",(YHSpriteDefiner*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getSpriteDefiner",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHEffectDefiner_getSpriteDefiner'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHEffectDefiner_setAnimationName(lua_State* tolua_S)
{
    int argc = 0;
    YHEffectDefiner* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHEffectDefiner",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHEffectDefiner*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHEffectDefiner_setAnimationName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setAnimationName(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setAnimationName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHEffectDefiner_setAnimationName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHEffectDefiner_constructor(lua_State* tolua_S)
{
    int argc = 0;
    YHEffectDefiner* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            cocos2d::__Dictionary* arg0;
            ok &= luaval_to_object<cocos2d::__Dictionary>(tolua_S, 2, "cc.__Dictionary",&arg0);

            if (!ok) { break; }
            cobj = new YHEffectDefiner(arg0);
            cobj->autorelease();
            int ID =  (int)cobj->_ID ;
            int* luaID =  &cobj->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"YHEffectDefiner");
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            _YHEffectDefineType_ arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);

            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

            if (!ok) { break; }
            cobj = new YHEffectDefiner(arg0, arg1);
            cobj->autorelease();
            int ID =  (int)cobj->_ID ;
            int* luaID =  &cobj->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"YHEffectDefiner");
            return 1;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "YHEffectDefiner",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHEffectDefiner_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_tools_YHEffectDefiner_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (YHEffectDefiner)");
    return 0;
}

int lua_register_cocos2dx_tools_YHEffectDefiner(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"YHEffectDefiner");
    tolua_cclass(tolua_S,"YHEffectDefiner","YHEffectDefiner","YHObject",nullptr);

    tolua_beginmodule(tolua_S,"YHEffectDefiner");
        tolua_function(tolua_S,"new",lua_cocos2dx_tools_YHEffectDefiner_constructor);
        tolua_function(tolua_S,"getAnimationName",lua_cocos2dx_tools_YHEffectDefiner_getAnimationName);
        tolua_function(tolua_S,"getType",lua_cocos2dx_tools_YHEffectDefiner_getType);
        tolua_function(tolua_S,"setSpriteDefiner",lua_cocos2dx_tools_YHEffectDefiner_setSpriteDefiner);
        tolua_function(tolua_S,"getSpriteDefiner",lua_cocos2dx_tools_YHEffectDefiner_getSpriteDefiner);
        tolua_function(tolua_S,"setAnimationName",lua_cocos2dx_tools_YHEffectDefiner_setAnimationName);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(YHEffectDefiner).name();
    g_luaType[typeName] = "YHEffectDefiner";
    g_typeCast["YHEffectDefiner"] = "YHEffectDefiner";
    return 1;
}

int lua_cocos2dx_tools_YHEffectFactory_effectSpriteForDefiner(lua_State* tolua_S)
{
    int argc = 0;
    YHEffectFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHEffectFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHEffectFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHEffectFactory_effectSpriteForDefiner'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const YHEffectDefiner* arg0;

        ok &= luaval_to_object<const YHEffectDefiner>(tolua_S, 2, "YHEffectDefiner",&arg0);
        if(!ok)
            return 0;
        YHDefaultFiniteEffect* ret = cobj->effectSpriteForDefiner(arg0);
        object_to_luaval<YHDefaultFiniteEffect>(tolua_S, "YHDefaultFiniteEffect",(YHDefaultFiniteEffect*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "effectSpriteForDefiner",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHEffectFactory_effectSpriteForDefiner'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHEffectFactory_setAnimationCache(lua_State* tolua_S)
{
    int argc = 0;
    YHEffectFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHEffectFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHEffectFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHEffectFactory_setAnimationCache'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        YHAnimationCache* arg0;

        ok &= luaval_to_object<YHAnimationCache>(tolua_S, 2, "YHAnimationCache",&arg0);
        if(!ok)
            return 0;
        cobj->setAnimationCache(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setAnimationCache",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHEffectFactory_setAnimationCache'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHEffectFactory_cleanAll(lua_State* tolua_S)
{
    int argc = 0;
    YHEffectFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHEffectFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHEffectFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHEffectFactory_cleanAll'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->cleanAll();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cleanAll",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHEffectFactory_cleanAll'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHEffectFactory_addEffectDefiner(lua_State* tolua_S)
{
    int argc = 0;
    YHEffectFactory* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHEffectFactory",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (YHEffectFactory*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHEffectFactory_addEffectDefiner'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            cocos2d::__Dictionary* arg0;
            ok &= luaval_to_object<cocos2d::__Dictionary>(tolua_S, 2, "cc.__Dictionary",&arg0);

            if (!ok) { break; }
            cobj->addEffectDefiner(arg0);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);

            if (!ok) { break; }
            YHEffectDefiner* arg1;
            ok &= luaval_to_object<YHEffectDefiner>(tolua_S, 3, "YHEffectDefiner",&arg1);

            if (!ok) { break; }
            cobj->addEffectDefiner(arg0, arg1);
            return 0;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addEffectDefiner",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHEffectFactory_addEffectDefiner'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHEffectFactory_effectDefinerForKey(lua_State* tolua_S)
{
    int argc = 0;
    YHEffectFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHEffectFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHEffectFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHEffectFactory_effectDefinerForKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        YHEffectDefiner* ret = cobj->effectDefinerForKey(arg0);
        object_to_luaval<YHEffectDefiner>(tolua_S, "YHEffectDefiner",(YHEffectDefiner*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "effectDefinerForKey",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHEffectFactory_effectDefinerForKey'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHEffectFactory_effectSpriteForKey(lua_State* tolua_S)
{
    int argc = 0;
    YHEffectFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHEffectFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHEffectFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHEffectFactory_effectSpriteForKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        YHDefaultFiniteEffect* ret = cobj->effectSpriteForKey(arg0);
        object_to_luaval<YHDefaultFiniteEffect>(tolua_S, "YHDefaultFiniteEffect",(YHDefaultFiniteEffect*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "effectSpriteForKey",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHEffectFactory_effectSpriteForKey'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHEffectFactory_init(lua_State* tolua_S)
{
    int argc = 0;
    YHEffectFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHEffectFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHEffectFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHEffectFactory_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHEffectFactory_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHEffectFactory_cleanAllSprites(lua_State* tolua_S)
{
    int argc = 0;
    YHEffectFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHEffectFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHEffectFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHEffectFactory_cleanAllSprites'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->cleanAllSprites();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cleanAllSprites",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHEffectFactory_cleanAllSprites'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHEffectFactory_getAnimationCache(lua_State* tolua_S)
{
    int argc = 0;
    YHEffectFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHEffectFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHEffectFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHEffectFactory_getAnimationCache'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        YHAnimationCache* ret = cobj->getAnimationCache();
        object_to_luaval<YHAnimationCache>(tolua_S, "YHAnimationCache",(YHAnimationCache*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getAnimationCache",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHEffectFactory_getAnimationCache'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHEffectFactory_cleanAllEffectDefiners(lua_State* tolua_S)
{
    int argc = 0;
    YHEffectFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHEffectFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHEffectFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHEffectFactory_cleanAllEffectDefiners'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->cleanAllEffectDefiners();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cleanAllEffectDefiners",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHEffectFactory_cleanAllEffectDefiners'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHEffectFactory_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YHEffectFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        YHEffectFactory* ret = YHEffectFactory::create();
        object_to_luaval<YHEffectFactory>(tolua_S, "YHEffectFactory",(YHEffectFactory*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHEffectFactory_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tools_YHEffectFactory_constructor(lua_State* tolua_S)
{
    int argc = 0;
    YHEffectFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new YHEffectFactory();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"YHEffectFactory");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "YHEffectFactory",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHEffectFactory_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_tools_YHEffectFactory_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (YHEffectFactory)");
    return 0;
}

int lua_register_cocos2dx_tools_YHEffectFactory(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"YHEffectFactory");
    tolua_cclass(tolua_S,"YHEffectFactory","YHEffectFactory","YHObject",nullptr);

    tolua_beginmodule(tolua_S,"YHEffectFactory");
        tolua_function(tolua_S,"new",lua_cocos2dx_tools_YHEffectFactory_constructor);
        tolua_function(tolua_S,"effectSpriteForDefiner",lua_cocos2dx_tools_YHEffectFactory_effectSpriteForDefiner);
        tolua_function(tolua_S,"setAnimationCache",lua_cocos2dx_tools_YHEffectFactory_setAnimationCache);
        tolua_function(tolua_S,"cleanAll",lua_cocos2dx_tools_YHEffectFactory_cleanAll);
        tolua_function(tolua_S,"addEffectDefiner",lua_cocos2dx_tools_YHEffectFactory_addEffectDefiner);
        tolua_function(tolua_S,"effectDefinerForKey",lua_cocos2dx_tools_YHEffectFactory_effectDefinerForKey);
        tolua_function(tolua_S,"effectSpriteForKey",lua_cocos2dx_tools_YHEffectFactory_effectSpriteForKey);
        tolua_function(tolua_S,"init",lua_cocos2dx_tools_YHEffectFactory_init);
        tolua_function(tolua_S,"cleanAllSprites",lua_cocos2dx_tools_YHEffectFactory_cleanAllSprites);
        tolua_function(tolua_S,"getAnimationCache",lua_cocos2dx_tools_YHEffectFactory_getAnimationCache);
        tolua_function(tolua_S,"cleanAllEffectDefiners",lua_cocos2dx_tools_YHEffectFactory_cleanAllEffectDefiners);
        tolua_function(tolua_S,"create", lua_cocos2dx_tools_YHEffectFactory_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(YHEffectFactory).name();
    g_luaType[typeName] = "YHEffectFactory";
    g_typeCast["YHEffectFactory"] = "YHEffectFactory";
    return 1;
}

int lua_cocos2dx_tools_AEEffectSprite_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"AEEffectSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        cocos2d::Vector<AvatarComponent *> arg0;
        ok &= luaval_to_ccvector(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        AEEffectSprite* ret = AEEffectSprite::create(arg0);
        object_to_luaval<AEEffectSprite>(tolua_S, "AEEffectSprite",(AEEffectSprite*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AEEffectSprite_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tools_AEEffectSprite_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (AEEffectSprite)");
    return 0;
}

int lua_register_cocos2dx_tools_AEEffectSprite(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"AEEffectSprite");
    tolua_cclass(tolua_S,"AEEffectSprite","AEEffectSprite","CCSpecialSprite",nullptr);

    tolua_beginmodule(tolua_S,"AEEffectSprite");
        tolua_function(tolua_S,"create", lua_cocos2dx_tools_AEEffectSprite_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(AEEffectSprite).name();
    g_luaType[typeName] = "AEEffectSprite";
    g_typeCast["AEEffectSprite"] = "AEEffectSprite";
    return 1;
}

int lua_cocos2dx_tools_Shaker_setNode(lua_State* tolua_S)
{
    int argc = 0;
    Shaker* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Shaker",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Shaker*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_Shaker_setNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Node* arg0;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0);
        if(!ok)
            return 0;
        cobj->setNode(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setNode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_Shaker_setNode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_Shaker_setRandom(lua_State* tolua_S)
{
    int argc = 0;
    Shaker* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Shaker",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Shaker*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_Shaker_setRandom'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setRandom(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setRandom",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_Shaker_setRandom'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_Shaker_setAmpMax(lua_State* tolua_S)
{
    int argc = 0;
    Shaker* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Shaker",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Shaker*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_Shaker_setAmpMax'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Vec2 arg0;

        ok &= luaval_to_vec2(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setAmpMax(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setAmpMax",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_Shaker_setAmpMax'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_Shaker_update(lua_State* tolua_S)
{
    int argc = 0;
    Shaker* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Shaker",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Shaker*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_Shaker_update'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->update(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "update",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_Shaker_update'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_Shaker_stop(lua_State* tolua_S)
{
    int argc = 0;
    Shaker* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Shaker",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Shaker*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_Shaker_stop'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->stop();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "stop",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_Shaker_stop'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_Shaker_getAmpMax(lua_State* tolua_S)
{
    int argc = 0;
    Shaker* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Shaker",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Shaker*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_Shaker_getAmpMax'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Vec2 ret = cobj->getAmpMax();
        vec2_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getAmpMax",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_Shaker_getAmpMax'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_Shaker_setOrigin(lua_State* tolua_S)
{
    int argc = 0;
    Shaker* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Shaker",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Shaker*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_Shaker_setOrigin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Vec2 arg0;

        ok &= luaval_to_vec2(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setOrigin(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setOrigin",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_Shaker_setOrigin'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_Shaker_start(lua_State* tolua_S)
{
    int argc = 0;
    Shaker* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Shaker",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Shaker*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_Shaker_start'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Vec2 arg0;
        double arg1;
        double arg2;

        ok &= luaval_to_vec2(tolua_S, 2, &arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);

        ok &= luaval_to_number(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        cobj->start(arg0, arg1, arg2);
        return 0;
    }
    if (argc == 4) 
    {
        cocos2d::Vec2 arg0;
        double arg1;
        double arg2;
        double arg3;

        ok &= luaval_to_vec2(tolua_S, 2, &arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);

        ok &= luaval_to_number(tolua_S, 4,&arg2);

        ok &= luaval_to_number(tolua_S, 5,&arg3);
        if(!ok)
            return 0;
        cobj->start(arg0, arg1, arg2, arg3);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "start",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_Shaker_start'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_Shaker_getPosition(lua_State* tolua_S)
{
    int argc = 0;
    Shaker* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Shaker",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Shaker*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_Shaker_getPosition'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Vec2 ret = cobj->getPosition();
        vec2_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getPosition",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_Shaker_getPosition'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_Shaker_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"Shaker",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        Shaker* ret = Shaker::create();
        object_to_luaval<Shaker>(tolua_S, "Shaker",(Shaker*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_Shaker_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tools_Shaker_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Shaker)");
    return 0;
}

int lua_register_cocos2dx_tools_Shaker(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"Shaker");
    tolua_cclass(tolua_S,"Shaker","Shaker","YHObject",nullptr);

    tolua_beginmodule(tolua_S,"Shaker");
        tolua_function(tolua_S,"setNode",lua_cocos2dx_tools_Shaker_setNode);
        tolua_function(tolua_S,"setRandom",lua_cocos2dx_tools_Shaker_setRandom);
        tolua_function(tolua_S,"setAmpMax",lua_cocos2dx_tools_Shaker_setAmpMax);
        tolua_function(tolua_S,"update",lua_cocos2dx_tools_Shaker_update);
        tolua_function(tolua_S,"stop",lua_cocos2dx_tools_Shaker_stop);
        tolua_function(tolua_S,"getAmpMax",lua_cocos2dx_tools_Shaker_getAmpMax);
        tolua_function(tolua_S,"setOrigin",lua_cocos2dx_tools_Shaker_setOrigin);
        tolua_function(tolua_S,"start",lua_cocos2dx_tools_Shaker_start);
        tolua_function(tolua_S,"getPosition",lua_cocos2dx_tools_Shaker_getPosition);
        tolua_function(tolua_S,"create", lua_cocos2dx_tools_Shaker_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(Shaker).name();
    g_luaType[typeName] = "Shaker";
    g_typeCast["Shaker"] = "Shaker";
    return 1;
}

int lua_cocos2dx_tools_AvatarComponent_getAnimation(lua_State* tolua_S)
{
    int argc = 0;
    AvatarComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AvatarComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AvatarComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AvatarComponent_getAnimation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Animation* ret = cobj->getAnimation();
        object_to_luaval<cocos2d::Animation>(tolua_S, "cc.Animation",(cocos2d::Animation*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getAnimation",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AvatarComponent_getAnimation'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AvatarComponent_handleKeyEvent(lua_State* tolua_S)
{
    int argc = 0;
    AvatarComponent* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AvatarComponent",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (AvatarComponent*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AvatarComponent_handleKeyEvent'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            cocos2d::Node* arg0;
            ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0);

            if (!ok) { break; }
            cocos2d::__Dictionary* arg1;
            ok &= luaval_to_object<cocos2d::__Dictionary>(tolua_S, 3, "cc.__Dictionary",&arg1);

            if (!ok) { break; }
            cobj->handleKeyEvent(arg0, arg1);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            cocos2d::Node* arg0;
            ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0);

            if (!ok) { break; }
            cocos2d::AnimationFrame* arg1;
            ok &= luaval_to_object<cocos2d::AnimationFrame>(tolua_S, 3, "cc.AnimationFrame",&arg1);

            if (!ok) { break; }
            cobj->handleKeyEvent(arg0, arg1);
            return 0;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "handleKeyEvent",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AvatarComponent_handleKeyEvent'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AvatarComponent_getAnimatorData(lua_State* tolua_S)
{
    int argc = 0;
    AvatarComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AvatarComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AvatarComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AvatarComponent_getAnimatorData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        AnimatorData* ret = cobj->getAnimatorData();
        object_to_luaval<AnimatorData>(tolua_S, "AnimatorData",(AnimatorData*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getAnimatorData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AvatarComponent_getAnimatorData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AvatarComponent_tween(lua_State* tolua_S)
{
    int argc = 0;
    AvatarComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AvatarComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AvatarComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AvatarComponent_tween'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Animation* arg0;
        AnimatorData* arg1;

        ok &= luaval_to_object<cocos2d::Animation>(tolua_S, 2, "cc.Animation",&arg0);

        ok &= luaval_to_object<AnimatorData>(tolua_S, 3, "AnimatorData",&arg1);
        if(!ok)
            return 0;
        cobj->tween(arg0, arg1);
        return 0;
    }
    if (argc == 3) 
    {
        cocos2d::Animation* arg0;
        AnimatorData* arg1;
        double arg2;

        ok &= luaval_to_object<cocos2d::Animation>(tolua_S, 2, "cc.Animation",&arg0);

        ok &= luaval_to_object<AnimatorData>(tolua_S, 3, "AnimatorData",&arg1);

        ok &= luaval_to_number(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        cobj->tween(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tween",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AvatarComponent_tween'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AvatarComponent_setAnimation(lua_State* tolua_S)
{
    int argc = 0;
    AvatarComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AvatarComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AvatarComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AvatarComponent_setAnimation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Animation* arg0;

        ok &= luaval_to_object<cocos2d::Animation>(tolua_S, 2, "cc.Animation",&arg0);
        if(!ok)
            return 0;
        cobj->setAnimation(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setAnimation",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AvatarComponent_setAnimation'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AvatarComponent_setAnimatorData(lua_State* tolua_S)
{
    int argc = 0;
    AvatarComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AvatarComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AvatarComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AvatarComponent_setAnimatorData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        AnimatorData* arg0;

        ok &= luaval_to_object<AnimatorData>(tolua_S, 2, "AnimatorData",&arg0);
        if(!ok)
            return 0;
        cobj->setAnimatorData(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setAnimatorData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AvatarComponent_setAnimatorData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AvatarComponent_setKeyTimeCallback(lua_State* tolua_S)
{
    int argc = 0;
    AvatarComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AvatarComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AvatarComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_AvatarComponent_setKeyTimeCallback'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        YHAnimationKeyEvents* arg0;

        ok &= luaval_to_object<YHAnimationKeyEvents>(tolua_S, 2, "YHAnimationKeyEvents",&arg0);
        if(!ok)
            return 0;
        cobj->setKeyTimeCallback(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setKeyTimeCallback",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AvatarComponent_setKeyTimeCallback'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_AvatarComponent_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"AvatarComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        cocos2d::Animation* arg0;
        YHAnimationKeyEvents* arg1;
        AnimatorData* arg2;
        ok &= luaval_to_object<cocos2d::Animation>(tolua_S, 2, "cc.Animation",&arg0);
        ok &= luaval_to_object<YHAnimationKeyEvents>(tolua_S, 3, "YHAnimationKeyEvents",&arg1);
        ok &= luaval_to_object<AnimatorData>(tolua_S, 4, "AnimatorData",&arg2);
        if(!ok)
            return 0;
        AvatarComponent* ret = AvatarComponent::create(arg0, arg1, arg2);
        object_to_luaval<AvatarComponent>(tolua_S, "AvatarComponent",(AvatarComponent*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_AvatarComponent_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tools_AvatarComponent_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (AvatarComponent)");
    return 0;
}

int lua_register_cocos2dx_tools_AvatarComponent(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"AvatarComponent");
    tolua_cclass(tolua_S,"AvatarComponent","AvatarComponent","cc.Sprite",nullptr);

    tolua_beginmodule(tolua_S,"AvatarComponent");
        tolua_function(tolua_S,"getAnimation",lua_cocos2dx_tools_AvatarComponent_getAnimation);
        tolua_function(tolua_S,"handleKeyEvent",lua_cocos2dx_tools_AvatarComponent_handleKeyEvent);
        tolua_function(tolua_S,"getAnimatorData",lua_cocos2dx_tools_AvatarComponent_getAnimatorData);
        tolua_function(tolua_S,"tween",lua_cocos2dx_tools_AvatarComponent_tween);
        tolua_function(tolua_S,"setAnimation",lua_cocos2dx_tools_AvatarComponent_setAnimation);
        tolua_function(tolua_S,"setAnimatorData",lua_cocos2dx_tools_AvatarComponent_setAnimatorData);
        tolua_function(tolua_S,"setKeyTimeCallback",lua_cocos2dx_tools_AvatarComponent_setKeyTimeCallback);
        tolua_function(tolua_S,"create", lua_cocos2dx_tools_AvatarComponent_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(AvatarComponent).name();
    g_luaType[typeName] = "AvatarComponent";
    g_typeCast["AvatarComponent"] = "AvatarComponent";
    return 1;
}

int lua_cocos2dx_tools_YHDevice_platform(lua_State* tolua_S)
{
    int argc = 0;
    YHDevice* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHDevice",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHDevice*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHDevice_platform'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        std::string ret = cobj->platform();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "platform",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHDevice_platform'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHDevice_deviceIdentifier(lua_State* tolua_S)
{
    int argc = 0;
    YHDevice* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHDevice",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHDevice*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHDevice_deviceIdentifier'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        std::string ret = cobj->deviceIdentifier();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "deviceIdentifier",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHDevice_deviceIdentifier'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHDevice_isJailBrokeDevice(lua_State* tolua_S)
{
    int argc = 0;
    YHDevice* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHDevice",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHDevice*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHDevice_isJailBrokeDevice'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isJailBrokeDevice();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isJailBrokeDevice",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHDevice_isJailBrokeDevice'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHDevice_osVersion(lua_State* tolua_S)
{
    int argc = 0;
    YHDevice* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHDevice",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHDevice*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHDevice_osVersion'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        std::string ret = cobj->osVersion();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "osVersion",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHDevice_osVersion'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHDevice_sharedInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YHDevice",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        YHDevice* ret = YHDevice::sharedInstance();
        object_to_luaval<YHDevice>(tolua_S, "YHDevice",(YHDevice*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "sharedInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHDevice_sharedInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tools_YHDevice_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (YHDevice)");
    return 0;
}

int lua_register_cocos2dx_tools_YHDevice(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"YHDevice");
    tolua_cclass(tolua_S,"YHDevice","YHDevice","YHObject",nullptr);

    tolua_beginmodule(tolua_S,"YHDevice");
        tolua_function(tolua_S,"platform",lua_cocos2dx_tools_YHDevice_platform);
        tolua_function(tolua_S,"deviceIdentifier",lua_cocos2dx_tools_YHDevice_deviceIdentifier);
        tolua_function(tolua_S,"isJailBrokeDevice",lua_cocos2dx_tools_YHDevice_isJailBrokeDevice);
        tolua_function(tolua_S,"osVersion",lua_cocos2dx_tools_YHDevice_osVersion);
        tolua_function(tolua_S,"sharedInstance", lua_cocos2dx_tools_YHDevice_sharedInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(YHDevice).name();
    g_luaType[typeName] = "YHDevice";
    g_typeCast["YHDevice"] = "YHDevice";
    return 1;
}

int lua_cocos2dx_tools_YHGameBasicInfo_init(lua_State* tolua_S)
{
    int argc = 0;
    YHGameBasicInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHGameBasicInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHGameBasicInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHGameBasicInfo_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHGameBasicInfo_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHGameBasicInfo_version(lua_State* tolua_S)
{
    int argc = 0;
    YHGameBasicInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHGameBasicInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHGameBasicInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHGameBasicInfo_version'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        std::string ret = cobj->version();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "version",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHGameBasicInfo_version'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHGameBasicInfo_name(lua_State* tolua_S)
{
    int argc = 0;
    YHGameBasicInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHGameBasicInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHGameBasicInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHGameBasicInfo_name'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        std::string ret = cobj->name();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "name",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHGameBasicInfo_name'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHGameBasicInfo_sharedInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YHGameBasicInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        YHGameBasicInfo* ret = YHGameBasicInfo::sharedInstance();
        object_to_luaval<YHGameBasicInfo>(tolua_S, "YHGameBasicInfo",(YHGameBasicInfo*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "sharedInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHGameBasicInfo_sharedInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tools_YHGameBasicInfo_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (YHGameBasicInfo)");
    return 0;
}

int lua_register_cocos2dx_tools_YHGameBasicInfo(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"YHGameBasicInfo");
    tolua_cclass(tolua_S,"YHGameBasicInfo","YHGameBasicInfo","YHObject",nullptr);

    tolua_beginmodule(tolua_S,"YHGameBasicInfo");
        tolua_function(tolua_S,"init",lua_cocos2dx_tools_YHGameBasicInfo_init);
        tolua_function(tolua_S,"version",lua_cocos2dx_tools_YHGameBasicInfo_version);
        tolua_function(tolua_S,"name",lua_cocos2dx_tools_YHGameBasicInfo_name);
        tolua_function(tolua_S,"sharedInstance", lua_cocos2dx_tools_YHGameBasicInfo_sharedInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(YHGameBasicInfo).name();
    g_luaType[typeName] = "YHGameBasicInfo";
    g_typeCast["YHGameBasicInfo"] = "YHGameBasicInfo";
    return 1;
}

int lua_cocos2dx_tools_SoundController_stopAllEffects(lua_State* tolua_S)
{
    int argc = 0;
    SoundController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_SoundController_stopAllEffects'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->stopAllEffects();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "stopAllEffects",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_SoundController_stopAllEffects'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_SoundController_allFiles(lua_State* tolua_S)
{
    int argc = 0;
    SoundController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_SoundController_allFiles'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        std::vector<std::string> ret = cobj->allFiles();
        ccvector_std_string_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "allFiles",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_SoundController_allFiles'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_SoundController_fileWithKey(lua_State* tolua_S)
{
    int argc = 0;
    SoundController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_SoundController_fileWithKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        const char* ret = cobj->fileWithKey(arg0);
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "fileWithKey",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_SoundController_fileWithKey'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_SoundController_getEffectsVolume(lua_State* tolua_S)
{
    int argc = 0;
    SoundController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_SoundController_getEffectsVolume'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->getEffectsVolume();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getEffectsVolume",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_SoundController_getEffectsVolume'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_SoundController_fadeInVolume(lua_State* tolua_S)
{
    int argc = 0;
    SoundController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_SoundController_fadeInVolume'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->fadeInVolume();
        return 0;
    }
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->fadeInVolume(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "fadeInVolume",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_SoundController_fadeInVolume'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_SoundController_stopEffect(lua_State* tolua_S)
{
    int argc = 0;
    SoundController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_SoundController_stopEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->stopEffect(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "stopEffect",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_SoundController_stopEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_SoundController_pauseBackgroundMusic(lua_State* tolua_S)
{
    int argc = 0;
    SoundController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_SoundController_pauseBackgroundMusic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->pauseBackgroundMusic();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "pauseBackgroundMusic",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_SoundController_pauseBackgroundMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_SoundController_willPlayBackgroundMusic(lua_State* tolua_S)
{
    int argc = 0;
    SoundController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_SoundController_willPlayBackgroundMusic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->willPlayBackgroundMusic();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "willPlayBackgroundMusic",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_SoundController_willPlayBackgroundMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_SoundController_setBackgroundMusicVolume(lua_State* tolua_S)
{
    int argc = 0;
    SoundController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_SoundController_setBackgroundMusicVolume'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setBackgroundMusicVolume(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBackgroundMusicVolume",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_SoundController_setBackgroundMusicVolume'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_SoundController_appendMappingFile(lua_State* tolua_S)
{
    int argc = 0;
    SoundController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_SoundController_appendMappingFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::__Dictionary* arg0;

        ok &= luaval_to_object<cocos2d::__Dictionary>(tolua_S, 2, "cc.__Dictionary",&arg0);
        if(!ok)
            return 0;
        cobj->appendMappingFile(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "appendMappingFile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_SoundController_appendMappingFile'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_SoundController_playEffectWithKey(lua_State* tolua_S)
{
    int argc = 0;
    SoundController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_SoundController_playEffectWithKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        unsigned int ret = cobj->playEffectWithKey(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        bool arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_boolean(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        unsigned int ret = cobj->playEffectWithKey(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    if (argc == 3) 
    {
        std::string arg0;
        bool arg1;
        double arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_boolean(tolua_S, 3,&arg1);

        ok &= luaval_to_number(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        unsigned int ret = cobj->playEffectWithKey(arg0, arg1, arg2);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    if (argc == 4) 
    {
        std::string arg0;
        bool arg1;
        double arg2;
        double arg3;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_boolean(tolua_S, 3,&arg1);

        ok &= luaval_to_number(tolua_S, 4,&arg2);

        ok &= luaval_to_number(tolua_S, 5,&arg3);
        if(!ok)
            return 0;
        unsigned int ret = cobj->playEffectWithKey(arg0, arg1, arg2, arg3);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    if (argc == 5) 
    {
        std::string arg0;
        bool arg1;
        double arg2;
        double arg3;
        double arg4;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_boolean(tolua_S, 3,&arg1);

        ok &= luaval_to_number(tolua_S, 4,&arg2);

        ok &= luaval_to_number(tolua_S, 5,&arg3);

        ok &= luaval_to_number(tolua_S, 6,&arg4);
        if(!ok)
            return 0;
        unsigned int ret = cobj->playEffectWithKey(arg0, arg1, arg2, arg3, arg4);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "playEffectWithKey",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_SoundController_playEffectWithKey'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_SoundController_stopBackgroundMusic(lua_State* tolua_S)
{
    int argc = 0;
    SoundController* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundController",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SoundController*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_SoundController_stopBackgroundMusic'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 0) {
            cobj->stopBackgroundMusic();
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            bool arg0;
            ok &= luaval_to_boolean(tolua_S, 2,&arg0);

            if (!ok) { break; }
            cobj->stopBackgroundMusic(arg0);
            return 0;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "stopBackgroundMusic",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_SoundController_stopBackgroundMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_SoundController_getBackgroundMusicVolume(lua_State* tolua_S)
{
    int argc = 0;
    SoundController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_SoundController_getBackgroundMusicVolume'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->getBackgroundMusicVolume();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getBackgroundMusicVolume",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_SoundController_getBackgroundMusicVolume'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_SoundController_isBackgroundMusicPlaying(lua_State* tolua_S)
{
    int argc = 0;
    SoundController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_SoundController_isBackgroundMusicPlaying'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isBackgroundMusicPlaying();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isBackgroundMusicPlaying",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_SoundController_isBackgroundMusicPlaying'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_SoundController_init(lua_State* tolua_S)
{
    int argc = 0;
    SoundController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_SoundController_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->init();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_SoundController_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_SoundController_pauseAllEffects(lua_State* tolua_S)
{
    int argc = 0;
    SoundController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_SoundController_pauseAllEffects'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->pauseAllEffects();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "pauseAllEffects",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_SoundController_pauseAllEffects'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_SoundController_preloadBackgroundMusic(lua_State* tolua_S)
{
    int argc = 0;
    SoundController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_SoundController_preloadBackgroundMusic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->preloadBackgroundMusic(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "preloadBackgroundMusic",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_SoundController_preloadBackgroundMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_SoundController_playBackgroundMusic(lua_State* tolua_S)
{
    int argc = 0;
    SoundController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_SoundController_playBackgroundMusic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        bool arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_boolean(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->playBackgroundMusic(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "playBackgroundMusic",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_SoundController_playBackgroundMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_SoundController_update(lua_State* tolua_S)
{
    int argc = 0;
    SoundController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_SoundController_update'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->update(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "update",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_SoundController_update'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_SoundController_playEffect(lua_State* tolua_S)
{
    int argc = 0;
    SoundController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_SoundController_playEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        bool arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_boolean(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        unsigned int ret = cobj->playEffect(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    if (argc == 3) 
    {
        const char* arg0;
        bool arg1;
        double arg2;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_boolean(tolua_S, 3,&arg1);

        ok &= luaval_to_number(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        unsigned int ret = cobj->playEffect(arg0, arg1, arg2);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    if (argc == 4) 
    {
        const char* arg0;
        bool arg1;
        double arg2;
        double arg3;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_boolean(tolua_S, 3,&arg1);

        ok &= luaval_to_number(tolua_S, 4,&arg2);

        ok &= luaval_to_number(tolua_S, 5,&arg3);
        if(!ok)
            return 0;
        unsigned int ret = cobj->playEffect(arg0, arg1, arg2, arg3);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    if (argc == 5) 
    {
        const char* arg0;
        bool arg1;
        double arg2;
        double arg3;
        double arg4;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_boolean(tolua_S, 3,&arg1);

        ok &= luaval_to_number(tolua_S, 4,&arg2);

        ok &= luaval_to_number(tolua_S, 5,&arg3);

        ok &= luaval_to_number(tolua_S, 6,&arg4);
        if(!ok)
            return 0;
        unsigned int ret = cobj->playEffect(arg0, arg1, arg2, arg3, arg4);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "playEffect",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_SoundController_playEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_SoundController_resumeAllEffects(lua_State* tolua_S)
{
    int argc = 0;
    SoundController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_SoundController_resumeAllEffects'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->resumeAllEffects();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "resumeAllEffects",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_SoundController_resumeAllEffects'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_SoundController_playBGMWithKey(lua_State* tolua_S)
{
    int argc = 0;
    SoundController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_SoundController_playBGMWithKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->playBGMWithKey(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        std::string arg0;
        bool arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_boolean(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->playBGMWithKey(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "playBGMWithKey",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_SoundController_playBGMWithKey'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_SoundController_unloadEffect(lua_State* tolua_S)
{
    int argc = 0;
    SoundController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_SoundController_unloadEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->unloadEffect(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        const char* arg0;
        bool arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_boolean(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->unloadEffect(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "unloadEffect",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_SoundController_unloadEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_SoundController_setSubPath(lua_State* tolua_S)
{
    int argc = 0;
    SoundController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_SoundController_setSubPath'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setSubPath(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setSubPath",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_SoundController_setSubPath'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_SoundController_rewindBackgroundMusic(lua_State* tolua_S)
{
    int argc = 0;
    SoundController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_SoundController_rewindBackgroundMusic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->rewindBackgroundMusic();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "rewindBackgroundMusic",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_SoundController_rewindBackgroundMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_SoundController_preloadEffect(lua_State* tolua_S)
{
    int argc = 0;
    SoundController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_SoundController_preloadEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->preloadEffect(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        const char* arg0;
        bool arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_boolean(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->preloadEffect(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "preloadEffect",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_SoundController_preloadEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_SoundController_fadeOutVolume(lua_State* tolua_S)
{
    int argc = 0;
    SoundController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_SoundController_fadeOutVolume'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->fadeOutVolume();
        return 0;
    }
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->fadeOutVolume(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "fadeOutVolume",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_SoundController_fadeOutVolume'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_SoundController_getSubPath(lua_State* tolua_S)
{
    int argc = 0;
    SoundController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_SoundController_getSubPath'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        std::string ret = cobj->getSubPath();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getSubPath",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_SoundController_getSubPath'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_SoundController_pauseEffect(lua_State* tolua_S)
{
    int argc = 0;
    SoundController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_SoundController_pauseEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->pauseEffect(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "pauseEffect",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_SoundController_pauseEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_SoundController_resumeBackgroundMusic(lua_State* tolua_S)
{
    int argc = 0;
    SoundController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_SoundController_resumeBackgroundMusic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->resumeBackgroundMusic();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "resumeBackgroundMusic",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_SoundController_resumeBackgroundMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_SoundController_setEffectsVolume(lua_State* tolua_S)
{
    int argc = 0;
    SoundController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_SoundController_setEffectsVolume'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setEffectsVolume(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setEffectsVolume",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_SoundController_setEffectsVolume'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_SoundController_resumeEffect(lua_State* tolua_S)
{
    int argc = 0;
    SoundController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_SoundController_resumeEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->resumeEffect(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "resumeEffect",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_SoundController_resumeEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_SoundController_sharedSoundController(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"SoundController",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        SoundController* ret = SoundController::sharedSoundController();
        object_to_luaval<SoundController>(tolua_S, "SoundController",(SoundController*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "sharedSoundController",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_SoundController_sharedSoundController'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tools_SoundController_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (SoundController)");
    return 0;
}

int lua_register_cocos2dx_tools_SoundController(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"SoundController");
    tolua_cclass(tolua_S,"SoundController","SoundController","YHObject",nullptr);

    tolua_beginmodule(tolua_S,"SoundController");
        tolua_function(tolua_S,"stopAllEffects",lua_cocos2dx_tools_SoundController_stopAllEffects);
        tolua_function(tolua_S,"allFiles",lua_cocos2dx_tools_SoundController_allFiles);
        tolua_function(tolua_S,"fileWithKey",lua_cocos2dx_tools_SoundController_fileWithKey);
        tolua_function(tolua_S,"getEffectsVolume",lua_cocos2dx_tools_SoundController_getEffectsVolume);
        tolua_function(tolua_S,"fadeInVolume",lua_cocos2dx_tools_SoundController_fadeInVolume);
        tolua_function(tolua_S,"stopEffect",lua_cocos2dx_tools_SoundController_stopEffect);
        tolua_function(tolua_S,"pauseBackgroundMusic",lua_cocos2dx_tools_SoundController_pauseBackgroundMusic);
        tolua_function(tolua_S,"willPlayBackgroundMusic",lua_cocos2dx_tools_SoundController_willPlayBackgroundMusic);
        tolua_function(tolua_S,"setBackgroundMusicVolume",lua_cocos2dx_tools_SoundController_setBackgroundMusicVolume);
        tolua_function(tolua_S,"appendMappingFile",lua_cocos2dx_tools_SoundController_appendMappingFile);
        tolua_function(tolua_S,"playEffectWithKey",lua_cocos2dx_tools_SoundController_playEffectWithKey);
        tolua_function(tolua_S,"stopBackgroundMusic",lua_cocos2dx_tools_SoundController_stopBackgroundMusic);
        tolua_function(tolua_S,"getBackgroundMusicVolume",lua_cocos2dx_tools_SoundController_getBackgroundMusicVolume);
        tolua_function(tolua_S,"isBackgroundMusicPlaying",lua_cocos2dx_tools_SoundController_isBackgroundMusicPlaying);
        tolua_function(tolua_S,"init",lua_cocos2dx_tools_SoundController_init);
        tolua_function(tolua_S,"pauseAllEffects",lua_cocos2dx_tools_SoundController_pauseAllEffects);
        tolua_function(tolua_S,"preloadBackgroundMusic",lua_cocos2dx_tools_SoundController_preloadBackgroundMusic);
        tolua_function(tolua_S,"playBackgroundMusic",lua_cocos2dx_tools_SoundController_playBackgroundMusic);
        tolua_function(tolua_S,"update",lua_cocos2dx_tools_SoundController_update);
        tolua_function(tolua_S,"playEffect",lua_cocos2dx_tools_SoundController_playEffect);
        tolua_function(tolua_S,"resumeAllEffects",lua_cocos2dx_tools_SoundController_resumeAllEffects);
        tolua_function(tolua_S,"playBGMWithKey",lua_cocos2dx_tools_SoundController_playBGMWithKey);
        tolua_function(tolua_S,"unloadEffect",lua_cocos2dx_tools_SoundController_unloadEffect);
        tolua_function(tolua_S,"setSubPath",lua_cocos2dx_tools_SoundController_setSubPath);
        tolua_function(tolua_S,"rewindBackgroundMusic",lua_cocos2dx_tools_SoundController_rewindBackgroundMusic);
        tolua_function(tolua_S,"preloadEffect",lua_cocos2dx_tools_SoundController_preloadEffect);
        tolua_function(tolua_S,"fadeOutVolume",lua_cocos2dx_tools_SoundController_fadeOutVolume);
        tolua_function(tolua_S,"getSubPath",lua_cocos2dx_tools_SoundController_getSubPath);
        tolua_function(tolua_S,"pauseEffect",lua_cocos2dx_tools_SoundController_pauseEffect);
        tolua_function(tolua_S,"resumeBackgroundMusic",lua_cocos2dx_tools_SoundController_resumeBackgroundMusic);
        tolua_function(tolua_S,"setEffectsVolume",lua_cocos2dx_tools_SoundController_setEffectsVolume);
        tolua_function(tolua_S,"resumeEffect",lua_cocos2dx_tools_SoundController_resumeEffect);
        tolua_function(tolua_S,"sharedSoundController", lua_cocos2dx_tools_SoundController_sharedSoundController);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(SoundController).name();
    g_luaType[typeName] = "SoundController";
    g_typeCast["SoundController"] = "SoundController";
    return 1;
}

int lua_cocos2dx_tools_YHTimer_reset(lua_State* tolua_S)
{
    int argc = 0;
    YHTimer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHTimer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHTimer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHTimer_reset'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->reset();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "reset",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHTimer_reset'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHTimer_updateTimer(lua_State* tolua_S)
{
    int argc = 0;
    YHTimer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHTimer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHTimer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHTimer_updateTimer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        bool ret = cobj->updateTimer(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "updateTimer",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHTimer_updateTimer'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHTimer_getRunning(lua_State* tolua_S)
{
    int argc = 0;
    YHTimer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHTimer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHTimer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHTimer_getRunning'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->getRunning();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getRunning",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHTimer_getRunning'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHTimer_getInterval(lua_State* tolua_S)
{
    int argc = 0;
    YHTimer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHTimer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHTimer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHTimer_getInterval'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->getInterval();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getInterval",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHTimer_getInterval'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHTimer_resume(lua_State* tolua_S)
{
    int argc = 0;
    YHTimer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHTimer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHTimer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHTimer_resume'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->resume();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "resume",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHTimer_resume'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHTimer_setInterval(lua_State* tolua_S)
{
    int argc = 0;
    YHTimer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHTimer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHTimer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHTimer_setInterval'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setInterval(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setInterval",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHTimer_setInterval'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHTimer_initWithInterval(lua_State* tolua_S)
{
    int argc = 0;
    YHTimer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHTimer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHTimer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHTimer_initWithInterval'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        bool ret = cobj->initWithInterval(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initWithInterval",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHTimer_initWithInterval'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHTimer_isTimeOut(lua_State* tolua_S)
{
    int argc = 0;
    YHTimer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHTimer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHTimer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHTimer_isTimeOut'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isTimeOut();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isTimeOut",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHTimer_isTimeOut'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHTimer_start(lua_State* tolua_S)
{
    int argc = 0;
    YHTimer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHTimer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHTimer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHTimer_start'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->start();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "start",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHTimer_start'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHTimer_init(lua_State* tolua_S)
{
    int argc = 0;
    YHTimer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHTimer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHTimer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHTimer_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHTimer_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHTimer_pause(lua_State* tolua_S)
{
    int argc = 0;
    YHTimer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHTimer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHTimer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHTimer_pause'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->pause();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "pause",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHTimer_pause'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHTimer_getElapse(lua_State* tolua_S)
{
    int argc = 0;
    YHTimer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHTimer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHTimer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHTimer_getElapse'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->getElapse();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getElapse",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHTimer_getElapse'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHTimer_timerWithInterval(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YHTimer",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        YHTimer* ret = YHTimer::timerWithInterval(arg0);
        object_to_luaval<YHTimer>(tolua_S, "YHTimer",(YHTimer*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "timerWithInterval",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHTimer_timerWithInterval'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tools_YHTimer_timer(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YHTimer",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        YHTimer* ret = YHTimer::timer();
        object_to_luaval<YHTimer>(tolua_S, "YHTimer",(YHTimer*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "timer",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHTimer_timer'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tools_YHTimer_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (YHTimer)");
    return 0;
}

int lua_register_cocos2dx_tools_YHTimer(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"YHTimer");
    tolua_cclass(tolua_S,"YHTimer","YHTimer","YHObject",nullptr);

    tolua_beginmodule(tolua_S,"YHTimer");
        tolua_function(tolua_S,"reset",lua_cocos2dx_tools_YHTimer_reset);
        tolua_function(tolua_S,"updateTimer",lua_cocos2dx_tools_YHTimer_updateTimer);
        tolua_function(tolua_S,"getRunning",lua_cocos2dx_tools_YHTimer_getRunning);
        tolua_function(tolua_S,"getInterval",lua_cocos2dx_tools_YHTimer_getInterval);
        tolua_function(tolua_S,"resume",lua_cocos2dx_tools_YHTimer_resume);
        tolua_function(tolua_S,"setInterval",lua_cocos2dx_tools_YHTimer_setInterval);
        tolua_function(tolua_S,"initWithInterval",lua_cocos2dx_tools_YHTimer_initWithInterval);
        tolua_function(tolua_S,"isTimeOut",lua_cocos2dx_tools_YHTimer_isTimeOut);
        tolua_function(tolua_S,"start",lua_cocos2dx_tools_YHTimer_start);
        tolua_function(tolua_S,"init",lua_cocos2dx_tools_YHTimer_init);
        tolua_function(tolua_S,"pause",lua_cocos2dx_tools_YHTimer_pause);
        tolua_function(tolua_S,"getElapse",lua_cocos2dx_tools_YHTimer_getElapse);
        tolua_function(tolua_S,"timerWithInterval", lua_cocos2dx_tools_YHTimer_timerWithInterval);
        tolua_function(tolua_S,"timer", lua_cocos2dx_tools_YHTimer_timer);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(YHTimer).name();
    g_luaType[typeName] = "YHTimer";
    g_typeCast["YHTimer"] = "YHTimer";
    return 1;
}

int lua_cocos2dx_tools_YHTimerCache_createTimerWithInterval(lua_State* tolua_S)
{
    int argc = 0;
    YHTimerCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHTimerCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHTimerCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHTimerCache_createTimerWithInterval'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        YHTimer* ret = cobj->createTimerWithInterval(arg0);
        object_to_luaval<YHTimer>(tolua_S, "YHTimer",(YHTimer*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "createTimerWithInterval",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHTimerCache_createTimerWithInterval'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHTimerCache_createTimer(lua_State* tolua_S)
{
    int argc = 0;
    YHTimerCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHTimerCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHTimerCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHTimerCache_createTimer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        YHTimer* ret = cobj->createTimer();
        object_to_luaval<YHTimer>(tolua_S, "YHTimer",(YHTimer*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "createTimer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHTimerCache_createTimer'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHTimerCache_destroyTimer(lua_State* tolua_S)
{
    int argc = 0;
    YHTimerCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHTimerCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHTimerCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHTimerCache_destroyTimer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        YHTimer* arg0;

        ok &= luaval_to_object<YHTimer>(tolua_S, 2, "YHTimer",&arg0);
        if(!ok)
            return 0;
        cobj->destroyTimer(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "destroyTimer",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHTimerCache_destroyTimer'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHTimerCache_sharedTimerCache(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YHTimerCache",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        YHTimerCache* ret = YHTimerCache::sharedTimerCache();
        object_to_luaval<YHTimerCache>(tolua_S, "YHTimerCache",(YHTimerCache*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "sharedTimerCache",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHTimerCache_sharedTimerCache'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tools_YHTimerCache_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (YHTimerCache)");
    return 0;
}

int lua_register_cocos2dx_tools_YHTimerCache(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"YHTimerCache");
    tolua_cclass(tolua_S,"YHTimerCache","YHTimerCache","YHObject",nullptr);

    tolua_beginmodule(tolua_S,"YHTimerCache");
        tolua_function(tolua_S,"createTimerWithInterval",lua_cocos2dx_tools_YHTimerCache_createTimerWithInterval);
        tolua_function(tolua_S,"createTimer",lua_cocos2dx_tools_YHTimerCache_createTimer);
        tolua_function(tolua_S,"destroyTimer",lua_cocos2dx_tools_YHTimerCache_destroyTimer);
        tolua_function(tolua_S,"sharedTimerCache", lua_cocos2dx_tools_YHTimerCache_sharedTimerCache);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(YHTimerCache).name();
    g_luaType[typeName] = "YHTimerCache";
    g_typeCast["YHTimerCache"] = "YHTimerCache";
    return 1;
}

int lua_cocos2dx_tools_YHFontManager_addFonts(lua_State* tolua_S)
{
    int argc = 0;
    YHFontManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHFontManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHFontManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHFontManager_addFonts'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::__Dictionary* arg0;

        ok &= luaval_to_object<cocos2d::__Dictionary>(tolua_S, 2, "cc.__Dictionary",&arg0);
        if(!ok)
            return 0;
        cobj->addFonts(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addFonts",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHFontManager_addFonts'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHFontManager_fontNameForKey(lua_State* tolua_S)
{
    int argc = 0;
    YHFontManager* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHFontManager",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (YHFontManager*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHFontManager_fontNameForKey'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);

            if (!ok) { break; }
            std::string ret = cobj->fontNameForKey(arg0);
            tolua_pushcppstring(tolua_S,ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            std::string ret = cobj->fontNameForKey(arg0);
            tolua_pushcppstring(tolua_S,ret);
            return 1;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "fontNameForKey",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHFontManager_fontNameForKey'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHFontManager_defaultFontManager(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YHFontManager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        YHFontManager* ret = YHFontManager::defaultFontManager();
        object_to_luaval<YHFontManager>(tolua_S, "YHFontManager",(YHFontManager*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "defaultFontManager",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHFontManager_defaultFontManager'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tools_YHFontManager_constructor(lua_State* tolua_S)
{
    int argc = 0;
    YHFontManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new YHFontManager();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"YHFontManager");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "YHFontManager",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHFontManager_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_tools_YHFontManager_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (YHFontManager)");
    return 0;
}

int lua_register_cocos2dx_tools_YHFontManager(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"YHFontManager");
    tolua_cclass(tolua_S,"YHFontManager","YHFontManager","YHObject",nullptr);

    tolua_beginmodule(tolua_S,"YHFontManager");
        tolua_function(tolua_S,"new",lua_cocos2dx_tools_YHFontManager_constructor);
        tolua_function(tolua_S,"addFonts",lua_cocos2dx_tools_YHFontManager_addFonts);
        tolua_function(tolua_S,"fontNameForKey",lua_cocos2dx_tools_YHFontManager_fontNameForKey);
        tolua_function(tolua_S,"defaultFontManager", lua_cocos2dx_tools_YHFontManager_defaultFontManager);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(YHFontManager).name();
    g_luaType[typeName] = "YHFontManager";
    g_typeCast["YHFontManager"] = "YHFontManager";
    return 1;
}

int lua_cocos2dx_tools_YHLanguageManager_textForKey(lua_State* tolua_S)
{
    int argc = 0;
    YHLanguageManager* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHLanguageManager",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (YHLanguageManager*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHLanguageManager_textForKey'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);

            if (!ok) { break; }
            std::string ret = cobj->textForKey(arg0);
            tolua_pushcppstring(tolua_S,ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            std::string ret = cobj->textForKey(arg0);
            tolua_pushcppstring(tolua_S,ret);
            return 1;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "textForKey",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHLanguageManager_textForKey'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHLanguageManager_addTexts(lua_State* tolua_S)
{
    int argc = 0;
    YHLanguageManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHLanguageManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHLanguageManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHLanguageManager_addTexts'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::__Dictionary* arg0;

        ok &= luaval_to_object<cocos2d::__Dictionary>(tolua_S, 2, "cc.__Dictionary",&arg0);
        if(!ok)
            return 0;
        cobj->addTexts(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addTexts",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHLanguageManager_addTexts'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHLanguageManager_sharedManager(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YHLanguageManager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        YHLanguageManager* ret = YHLanguageManager::sharedManager();
        object_to_luaval<YHLanguageManager>(tolua_S, "YHLanguageManager",(YHLanguageManager*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "sharedManager",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHLanguageManager_sharedManager'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tools_YHLanguageManager_constructor(lua_State* tolua_S)
{
    int argc = 0;
    YHLanguageManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new YHLanguageManager();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"YHLanguageManager");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "YHLanguageManager",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHLanguageManager_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_tools_YHLanguageManager_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (YHLanguageManager)");
    return 0;
}

int lua_register_cocos2dx_tools_YHLanguageManager(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"YHLanguageManager");
    tolua_cclass(tolua_S,"YHLanguageManager","YHLanguageManager","YHObject",nullptr);

    tolua_beginmodule(tolua_S,"YHLanguageManager");
        tolua_function(tolua_S,"new",lua_cocos2dx_tools_YHLanguageManager_constructor);
        tolua_function(tolua_S,"textForKey",lua_cocos2dx_tools_YHLanguageManager_textForKey);
        tolua_function(tolua_S,"addTexts",lua_cocos2dx_tools_YHLanguageManager_addTexts);
        tolua_function(tolua_S,"sharedManager", lua_cocos2dx_tools_YHLanguageManager_sharedManager);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(YHLanguageManager).name();
    g_luaType[typeName] = "YHLanguageManager";
    g_typeCast["YHLanguageManager"] = "YHLanguageManager";
    return 1;
}

int lua_cocos2dx_tools_YHDataManager_addObject(lua_State* tolua_S)
{
    int argc = 0;
    YHDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHDataManager_addObject'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        cocos2d::Ref* arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 3, "cc.Ref",&arg1);
        if(!ok)
            return 0;
        cobj->addObject(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addObject",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHDataManager_addObject'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHDataManager_allFiles(lua_State* tolua_S)
{
    int argc = 0;
    YHDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHDataManager_allFiles'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        std::vector<std::string> ret = cobj->allFiles();
        ccvector_std_string_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "allFiles",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHDataManager_allFiles'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHDataManager_stringForFile(lua_State* tolua_S)
{
    int argc = 0;
    YHDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHDataManager_stringForFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        const std::string& ret = cobj->stringForFile(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "stringForFile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHDataManager_stringForFile'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHDataManager_dictionaryForFile(lua_State* tolua_S)
{
    int argc = 0;
    YHDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHDataManager_dictionaryForFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cocos2d::__Dictionary* ret = cobj->dictionaryForFile(arg0);
        object_to_luaval<cocos2d::__Dictionary>(tolua_S, "cc.__Dictionary",(cocos2d::__Dictionary*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "dictionaryForFile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHDataManager_dictionaryForFile'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHDataManager_charsForFile(lua_State* tolua_S)
{
    int argc = 0;
    YHDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHDataManager_charsForFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        const char* ret = cobj->charsForFile(arg0);
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "charsForFile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHDataManager_charsForFile'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHDataManager_addFile(lua_State* tolua_S)
{
    int argc = 0;
    YHDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHDataManager_addFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->addFile(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addFile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHDataManager_addFile'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHDataManager_completed(lua_State* tolua_S)
{
    int argc = 0;
    YHDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHDataManager_completed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->completed();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "completed",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHDataManager_completed'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHDataManager_stop(lua_State* tolua_S)
{
    int argc = 0;
    YHDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHDataManager_stop'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->stop();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "stop",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHDataManager_stop'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHDataManager_update(lua_State* tolua_S)
{
    int argc = 0;
    YHDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHDataManager_update'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->update(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "update",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHDataManager_update'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHDataManager_setFinishedCallback(lua_State* tolua_S)
{
    int argc = 0;
    YHDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHDataManager_setFinishedCallback'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::function<void ()> arg0;

        do {
			// Lambda binding for lua is not supported.
			assert(false);
		} while(0)
		;
        if(!ok)
            return 0;
        cobj->setFinishedCallback(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setFinishedCallback",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHDataManager_setFinishedCallback'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHDataManager_removeFile(lua_State* tolua_S)
{
    int argc = 0;
    YHDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHDataManager_removeFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->removeFile(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeFile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHDataManager_removeFile'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHDataManager_start(lua_State* tolua_S)
{
    int argc = 0;
    YHDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHDataManager_start'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->start();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "start",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHDataManager_start'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHDataManager_arrayForFile(lua_State* tolua_S)
{
    int argc = 0;
    YHDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHDataManager_arrayForFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cocos2d::__Array* ret = cobj->arrayForFile(arg0);
        object_to_luaval<cocos2d::__Array>(tolua_S, "cc.__Array",(cocos2d::__Array*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "arrayForFile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHDataManager_arrayForFile'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHDataManager_bytesForFile(lua_State* tolua_S)
{
    int argc = 0;
    YHDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHDataManager_bytesForFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        YHByteArray* ret = cobj->bytesForFile(arg0);
        object_to_luaval<YHByteArray>(tolua_S, "YHByteArray",(YHByteArray*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "bytesForFile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHDataManager_bytesForFile'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHDataManager_textureForFile(lua_State* tolua_S)
{
    int argc = 0;
    YHDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHDataManager_textureForFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cocos2d::Texture2D* ret = cobj->textureForFile(arg0);
        object_to_luaval<cocos2d::Texture2D>(tolua_S, "cc.Texture2D",(cocos2d::Texture2D*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "textureForFile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHDataManager_textureForFile'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHDataManager_removeAllFiles(lua_State* tolua_S)
{
    int argc = 0;
    YHDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHDataManager_removeAllFiles'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeAllFiles();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeAllFiles",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHDataManager_removeAllFiles'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHDataManager_purgeImages(lua_State* tolua_S)
{
    int argc = 0;
    YHDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHDataManager_purgeImages'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->purgeImages();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "purgeImages",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHDataManager_purgeImages'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHDataManager_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YHDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        YHDataManager* ret = YHDataManager::create();
        object_to_luaval<YHDataManager>(tolua_S, "YHDataManager",(YHDataManager*)ret);
        return 1;
    }
    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        YHDataManager* ret = YHDataManager::create(arg0);
        object_to_luaval<YHDataManager>(tolua_S, "YHDataManager",(YHDataManager*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHDataManager_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tools_YHDataManager_helpLoadSpriteFrames(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YHDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        YHDataManager* arg0;
        ok &= luaval_to_object<YHDataManager>(tolua_S, 2, "YHDataManager",&arg0);
        if(!ok)
            return 0;
        YHDataManager::helpLoadSpriteFrames(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "helpLoadSpriteFrames",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHDataManager_helpLoadSpriteFrames'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tools_YHDataManager_constructor(lua_State* tolua_S)
{
    int argc = 0;
    YHDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new YHDataManager();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"YHDataManager");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "YHDataManager",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHDataManager_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_tools_YHDataManager_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (YHDataManager)");
    return 0;
}

int lua_register_cocos2dx_tools_YHDataManager(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"YHDataManager");
    tolua_cclass(tolua_S,"YHDataManager","YHDataManager","YHObject",nullptr);

    tolua_beginmodule(tolua_S,"YHDataManager");
        tolua_function(tolua_S,"new",lua_cocos2dx_tools_YHDataManager_constructor);
        tolua_function(tolua_S,"addObject",lua_cocos2dx_tools_YHDataManager_addObject);
        tolua_function(tolua_S,"allFiles",lua_cocos2dx_tools_YHDataManager_allFiles);
        tolua_function(tolua_S,"stringForFile",lua_cocos2dx_tools_YHDataManager_stringForFile);
        tolua_function(tolua_S,"dictionaryForFile",lua_cocos2dx_tools_YHDataManager_dictionaryForFile);
        tolua_function(tolua_S,"charsForFile",lua_cocos2dx_tools_YHDataManager_charsForFile);
        tolua_function(tolua_S,"addFile",lua_cocos2dx_tools_YHDataManager_addFile);
        tolua_function(tolua_S,"completed",lua_cocos2dx_tools_YHDataManager_completed);
        tolua_function(tolua_S,"stop",lua_cocos2dx_tools_YHDataManager_stop);
        tolua_function(tolua_S,"update",lua_cocos2dx_tools_YHDataManager_update);
        tolua_function(tolua_S,"setFinishedCallback",lua_cocos2dx_tools_YHDataManager_setFinishedCallback);
        tolua_function(tolua_S,"removeFile",lua_cocos2dx_tools_YHDataManager_removeFile);
        tolua_function(tolua_S,"start",lua_cocos2dx_tools_YHDataManager_start);
        tolua_function(tolua_S,"arrayForFile",lua_cocos2dx_tools_YHDataManager_arrayForFile);
        tolua_function(tolua_S,"bytesForFile",lua_cocos2dx_tools_YHDataManager_bytesForFile);
        tolua_function(tolua_S,"textureForFile",lua_cocos2dx_tools_YHDataManager_textureForFile);
        tolua_function(tolua_S,"removeAllFiles",lua_cocos2dx_tools_YHDataManager_removeAllFiles);
        tolua_function(tolua_S,"purgeImages",lua_cocos2dx_tools_YHDataManager_purgeImages);
        tolua_function(tolua_S,"create", lua_cocos2dx_tools_YHDataManager_create);
        tolua_function(tolua_S,"helpLoadSpriteFrames", lua_cocos2dx_tools_YHDataManager_helpLoadSpriteFrames);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(YHDataManager).name();
    g_luaType[typeName] = "YHDataManager";
    g_typeCast["YHDataManager"] = "YHDataManager";
    return 1;
}

int lua_cocos2dx_tools_ScissorNode_setArgs(lua_State* tolua_S)
{
    int argc = 0;
    ScissorNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ScissorNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ScissorNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_ScissorNode_setArgs'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        int arg0;
        int arg1;
        int arg2;
        int arg3;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2);

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3);
        if(!ok)
            return 0;
        cobj->setArgs(arg0, arg1, arg2, arg3);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setArgs",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_ScissorNode_setArgs'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_ScissorNode_visit(lua_State* tolua_S)
{
    int argc = 0;
    ScissorNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ScissorNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ScissorNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_ScissorNode_visit'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Renderer* arg0;
        cocos2d::Mat4 arg1;
        unsigned int arg2;

        ok &= luaval_to_object<cocos2d::Renderer>(tolua_S, 2, "cc.Renderer",&arg0);

        ok &= luaval_to_mat4(tolua_S, 3, &arg1);

        ok &= luaval_to_uint32(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        cobj->visit(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "visit",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_ScissorNode_visit'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_ScissorNode_setModel(lua_State* tolua_S)
{
    int argc = 0;
    ScissorNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ScissorNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ScissorNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_ScissorNode_setModel'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setModel(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setModel",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_ScissorNode_setModel'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_ScissorNode_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ScissorNode",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        ScissorNode* ret = ScissorNode::create();
        object_to_luaval<ScissorNode>(tolua_S, "ScissorNode",(ScissorNode*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_ScissorNode_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tools_ScissorNode_constructor(lua_State* tolua_S)
{
    int argc = 0;
    ScissorNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new ScissorNode();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"ScissorNode");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "ScissorNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_ScissorNode_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_tools_ScissorNode_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ScissorNode)");
    return 0;
}

int lua_register_cocos2dx_tools_ScissorNode(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ScissorNode");
    tolua_cclass(tolua_S,"ScissorNode","ScissorNode","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"ScissorNode");
        tolua_function(tolua_S,"new",lua_cocos2dx_tools_ScissorNode_constructor);
        tolua_function(tolua_S,"setArgs",lua_cocos2dx_tools_ScissorNode_setArgs);
        tolua_function(tolua_S,"visit",lua_cocos2dx_tools_ScissorNode_visit);
        tolua_function(tolua_S,"setModel",lua_cocos2dx_tools_ScissorNode_setModel);
        tolua_function(tolua_S,"create", lua_cocos2dx_tools_ScissorNode_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(ScissorNode).name();
    g_luaType[typeName] = "ScissorNode";
    g_typeCast["ScissorNode"] = "ScissorNode";
    return 1;
}

int lua_cocos2dx_tools_YHUITileBackground_init(lua_State* tolua_S)
{
    int argc = 0;
    YHUITileBackground* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUITileBackground",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUITileBackground*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUITileBackground_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        TileBackground_TileType arg0;
        const char* arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        bool ret = cobj->init(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUITileBackground_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUITileBackground_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YHUITileBackground",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        TileBackground_TileType arg0;
        const char* arg1;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        YHUITileBackground* ret = YHUITileBackground::create(arg0, arg1);
        object_to_luaval<YHUITileBackground>(tolua_S, "YHUITileBackground",(YHUITileBackground*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUITileBackground_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tools_YHUITileBackground_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (YHUITileBackground)");
    return 0;
}

int lua_register_cocos2dx_tools_YHUITileBackground(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"YHUITileBackground");
    tolua_cclass(tolua_S,"YHUITileBackground","YHUITileBackground","cc.Sprite",nullptr);

    tolua_beginmodule(tolua_S,"YHUITileBackground");
        tolua_function(tolua_S,"init",lua_cocos2dx_tools_YHUITileBackground_init);
        tolua_function(tolua_S,"create", lua_cocos2dx_tools_YHUITileBackground_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(YHUITileBackground).name();
    g_luaType[typeName] = "YHUITileBackground";
    g_typeCast["YHUITileBackground"] = "YHUITileBackground";
    return 1;
}

int lua_cocos2dx_tools_YHUIUnitComboBackground_initWithUnitFrameNameAndSize(lua_State* tolua_S)
{
    int argc = 0;
    YHUIUnitComboBackground* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUIUnitComboBackground",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUIUnitComboBackground*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUIUnitComboBackground_initWithUnitFrameNameAndSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        cocos2d::Size arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_size(tolua_S, 3, &arg1);
        if(!ok)
            return 0;
        bool ret = cobj->initWithUnitFrameNameAndSize(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initWithUnitFrameNameAndSize",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIUnitComboBackground_initWithUnitFrameNameAndSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUIUnitComboBackground_createWithUnitFrameNameAndSize(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YHUIUnitComboBackground",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        const char* arg0;
        cocos2d::Size arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= luaval_to_size(tolua_S, 3, &arg1);
        if(!ok)
            return 0;
        YHUIUnitComboBackground* ret = YHUIUnitComboBackground::createWithUnitFrameNameAndSize(arg0, arg1);
        object_to_luaval<YHUIUnitComboBackground>(tolua_S, "YHUIUnitComboBackground",(YHUIUnitComboBackground*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "createWithUnitFrameNameAndSize",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIUnitComboBackground_createWithUnitFrameNameAndSize'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tools_YHUIUnitComboBackground_constructor(lua_State* tolua_S)
{
    int argc = 0;
    YHUIUnitComboBackground* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new YHUIUnitComboBackground();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"YHUIUnitComboBackground");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "YHUIUnitComboBackground",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIUnitComboBackground_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_tools_YHUIUnitComboBackground_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (YHUIUnitComboBackground)");
    return 0;
}

int lua_register_cocos2dx_tools_YHUIUnitComboBackground(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"YHUIUnitComboBackground");
    tolua_cclass(tolua_S,"YHUIUnitComboBackground","YHUIUnitComboBackground","cc.Sprite",nullptr);

    tolua_beginmodule(tolua_S,"YHUIUnitComboBackground");
        tolua_function(tolua_S,"new",lua_cocos2dx_tools_YHUIUnitComboBackground_constructor);
        tolua_function(tolua_S,"initWithUnitFrameNameAndSize",lua_cocos2dx_tools_YHUIUnitComboBackground_initWithUnitFrameNameAndSize);
        tolua_function(tolua_S,"createWithUnitFrameNameAndSize", lua_cocos2dx_tools_YHUIUnitComboBackground_createWithUnitFrameNameAndSize);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(YHUIUnitComboBackground).name();
    g_luaType[typeName] = "YHUIUnitComboBackground";
    g_typeCast["YHUIUnitComboBackground"] = "YHUIUnitComboBackground";
    return 1;
}

int lua_cocos2dx_tools_YHISpriteNumber_setNumber(lua_State* tolua_S)
{
    int argc = 0;
    YHISpriteNumber* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHISpriteNumber",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (YHISpriteNumber*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHISpriteNumber_setNumber'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);

            if (!ok) { break; }
            cobj->setNumber(arg0);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0);

            if (!ok) { break; }
            cobj->setNumber(arg0);
            return 0;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setNumber",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHISpriteNumber_setNumber'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHISpriteNumber_layout(lua_State* tolua_S)
{
    int argc = 0;
    YHISpriteNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHISpriteNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHISpriteNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHISpriteNumber_layout'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->layout();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "layout",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHISpriteNumber_layout'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHISpriteNumber_setInterval(lua_State* tolua_S)
{
    int argc = 0;
    YHISpriteNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHISpriteNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHISpriteNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHISpriteNumber_setInterval'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setInterval(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setInterval",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHISpriteNumber_setInterval'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHISpriteNumber_setIconInterval(lua_State* tolua_S)
{
    int argc = 0;
    YHISpriteNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHISpriteNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHISpriteNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHISpriteNumber_setIconInterval'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setIconInterval(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setIconInterval",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHISpriteNumber_setIconInterval'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHISpriteNumber_getNumberFontWidth(lua_State* tolua_S)
{
    int argc = 0;
    YHISpriteNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHISpriteNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHISpriteNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHISpriteNumber_getNumberFontWidth'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->getNumberFontWidth();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getNumberFontWidth",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHISpriteNumber_getNumberFontWidth'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHISpriteNumber_setAlignType(lua_State* tolua_S)
{
    int argc = 0;
    YHISpriteNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHISpriteNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHISpriteNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHISpriteNumber_setAlignType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        YHSpriteNumber_AlignType arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setAlignType(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setAlignType",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHISpriteNumber_setAlignType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHISpriteNumber_setIcon(lua_State* tolua_S)
{
    int argc = 0;
    YHISpriteNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHISpriteNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHISpriteNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHISpriteNumber_setIcon'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Sprite* arg0;

        ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 2, "cc.Sprite",&arg0);
        if(!ok)
            return 0;
        cobj->setIcon(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setIcon",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHISpriteNumber_setIcon'.",&tolua_err);
#endif

    return 0;
}
static int lua_cocos2dx_tools_YHISpriteNumber_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (YHISpriteNumber)");
    return 0;
}

int lua_register_cocos2dx_tools_YHISpriteNumber(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"YHISpriteNumber");
    tolua_cclass(tolua_S,"YHISpriteNumber","YHISpriteNumber","cc.Sprite",nullptr);

    tolua_beginmodule(tolua_S,"YHISpriteNumber");
        tolua_function(tolua_S,"setNumber",lua_cocos2dx_tools_YHISpriteNumber_setNumber);
        tolua_function(tolua_S,"layout",lua_cocos2dx_tools_YHISpriteNumber_layout);
        tolua_function(tolua_S,"setInterval",lua_cocos2dx_tools_YHISpriteNumber_setInterval);
        tolua_function(tolua_S,"setIconInterval",lua_cocos2dx_tools_YHISpriteNumber_setIconInterval);
        tolua_function(tolua_S,"getNumberFontWidth",lua_cocos2dx_tools_YHISpriteNumber_getNumberFontWidth);
        tolua_function(tolua_S,"setAlignType",lua_cocos2dx_tools_YHISpriteNumber_setAlignType);
        tolua_function(tolua_S,"setIcon",lua_cocos2dx_tools_YHISpriteNumber_setIcon);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(YHISpriteNumber).name();
    g_luaType[typeName] = "YHISpriteNumber";
    g_typeCast["YHISpriteNumber"] = "YHISpriteNumber";
    return 1;
}

int lua_cocos2dx_tools_YHUISpriteNumber_setNumber(lua_State* tolua_S)
{
    int argc = 0;
    YHUISpriteNumber* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUISpriteNumber",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (YHUISpriteNumber*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUISpriteNumber_setNumber'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);

            if (!ok) { break; }
            cobj->setNumber(arg0);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0);

            if (!ok) { break; }
            cobj->setNumber(arg0);
            return 0;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setNumber",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUISpriteNumber_setNumber'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUISpriteNumber_layout(lua_State* tolua_S)
{
    int argc = 0;
    YHUISpriteNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUISpriteNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUISpriteNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUISpriteNumber_layout'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->layout();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "layout",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUISpriteNumber_layout'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUISpriteNumber_setColor(lua_State* tolua_S)
{
    int argc = 0;
    YHUISpriteNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUISpriteNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUISpriteNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUISpriteNumber_setColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color3B arg0;

        ok &= luaval_to_color3b(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setColor(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUISpriteNumber_setColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUISpriteNumber_setInterval(lua_State* tolua_S)
{
    int argc = 0;
    YHUISpriteNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUISpriteNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUISpriteNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUISpriteNumber_setInterval'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setInterval(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setInterval",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUISpriteNumber_setInterval'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUISpriteNumber_setIconInterval(lua_State* tolua_S)
{
    int argc = 0;
    YHUISpriteNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUISpriteNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUISpriteNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUISpriteNumber_setIconInterval'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setIconInterval(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setIconInterval",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUISpriteNumber_setIconInterval'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUISpriteNumber_setOpacity(lua_State* tolua_S)
{
    int argc = 0;
    YHUISpriteNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUISpriteNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUISpriteNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUISpriteNumber_setOpacity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setOpacity(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setOpacity",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUISpriteNumber_setOpacity'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUISpriteNumber_getNumberFontWidth(lua_State* tolua_S)
{
    int argc = 0;
    YHUISpriteNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUISpriteNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUISpriteNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUISpriteNumber_getNumberFontWidth'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->getNumberFontWidth();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getNumberFontWidth",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUISpriteNumber_getNumberFontWidth'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUISpriteNumber_init(lua_State* tolua_S)
{
    int argc = 0;
    YHUISpriteNumber* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUISpriteNumber",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (YHUISpriteNumber*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUISpriteNumber_init'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 3) {
            cocos2d::SpriteFrame* arg0;
            ok &= luaval_to_object<cocos2d::SpriteFrame>(tolua_S, 2, "cc.SpriteFrame",&arg0);

            if (!ok) { break; }
            cocos2d::Size arg1;
            ok &= luaval_to_size(tolua_S, 3, &arg1);

            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2);

            if (!ok) { break; }
            bool ret = cobj->init(arg0, arg1, arg2);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 4) {
            cocos2d::Texture2D* arg0;
            ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);

            if (!ok) { break; }
            cocos2d::Vec2 arg1;
            ok &= luaval_to_vec2(tolua_S, 3, &arg1);

            if (!ok) { break; }
            cocos2d::Size arg2;
            ok &= luaval_to_size(tolua_S, 4, &arg2);

            if (!ok) { break; }
            double arg3;
            ok &= luaval_to_number(tolua_S, 5,&arg3);

            if (!ok) { break; }
            bool ret = cobj->init(arg0, arg1, arg2, arg3);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 3) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cocos2d::Size arg1;
            ok &= luaval_to_size(tolua_S, 3, &arg1);

            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2);

            if (!ok) { break; }
            bool ret = cobj->init(arg0, arg1, arg2);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUISpriteNumber_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUISpriteNumber_getNumbers(lua_State* tolua_S)
{
    int argc = 0;
    YHUISpriteNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUISpriteNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUISpriteNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUISpriteNumber_getNumbers'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::__Array* ret = cobj->getNumbers();
        object_to_luaval<cocos2d::__Array>(tolua_S, "cc.__Array",(cocos2d::__Array*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getNumbers",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUISpriteNumber_getNumbers'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUISpriteNumber_setNumberOffset(lua_State* tolua_S)
{
    int argc = 0;
    YHUISpriteNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUISpriteNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUISpriteNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUISpriteNumber_setNumberOffset'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Vec2 arg0;

        ok &= luaval_to_vec2(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setNumberOffset(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setNumberOffset",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUISpriteNumber_setNumberOffset'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUISpriteNumber_setAlignType(lua_State* tolua_S)
{
    int argc = 0;
    YHUISpriteNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUISpriteNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUISpriteNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUISpriteNumber_setAlignType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        YHSpriteNumber_AlignType arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setAlignType(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setAlignType",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUISpriteNumber_setAlignType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUISpriteNumber_setIcon(lua_State* tolua_S)
{
    int argc = 0;
    YHUISpriteNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUISpriteNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUISpriteNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUISpriteNumber_setIcon'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Sprite* arg0;

        ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 2, "cc.Sprite",&arg0);
        if(!ok)
            return 0;
        cobj->setIcon(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setIcon",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUISpriteNumber_setIcon'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUISpriteNumber_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YHUISpriteNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 3)
        {
            cocos2d::SpriteFrame* arg0;
            ok &= luaval_to_object<cocos2d::SpriteFrame>(tolua_S, 2, "cc.SpriteFrame",&arg0);
            if (!ok) { break; }
            cocos2d::Size arg1;
            ok &= luaval_to_size(tolua_S, 3, &arg1);
            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2);
            if (!ok) { break; }
            YHUISpriteNumber* ret = YHUISpriteNumber::create(arg0, arg1, arg2);
            object_to_luaval<YHUISpriteNumber>(tolua_S, "YHUISpriteNumber",(YHUISpriteNumber*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 4)
        {
            cocos2d::Texture2D* arg0;
            ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);
            if (!ok) { break; }
            cocos2d::Vec2 arg1;
            ok &= luaval_to_vec2(tolua_S, 3, &arg1);
            if (!ok) { break; }
            cocos2d::Size arg2;
            ok &= luaval_to_size(tolua_S, 4, &arg2);
            if (!ok) { break; }
            double arg3;
            ok &= luaval_to_number(tolua_S, 5,&arg3);
            if (!ok) { break; }
            YHUISpriteNumber* ret = YHUISpriteNumber::create(arg0, arg1, arg2, arg3);
            object_to_luaval<YHUISpriteNumber>(tolua_S, "YHUISpriteNumber",(YHUISpriteNumber*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 3)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            cocos2d::Size arg1;
            ok &= luaval_to_size(tolua_S, 3, &arg1);
            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2);
            if (!ok) { break; }
            YHUISpriteNumber* ret = YHUISpriteNumber::create(arg0, arg1, arg2);
            object_to_luaval<YHUISpriteNumber>(tolua_S, "YHUISpriteNumber",(YHUISpriteNumber*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUISpriteNumber_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tools_YHUISpriteNumber_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (YHUISpriteNumber)");
    return 0;
}

int lua_register_cocos2dx_tools_YHUISpriteNumber(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"YHUISpriteNumber");
    tolua_cclass(tolua_S,"YHUISpriteNumber","YHUISpriteNumber","YHISpriteNumber",nullptr);

    tolua_beginmodule(tolua_S,"YHUISpriteNumber");
        tolua_function(tolua_S,"setNumber",lua_cocos2dx_tools_YHUISpriteNumber_setNumber);
        tolua_function(tolua_S,"layout",lua_cocos2dx_tools_YHUISpriteNumber_layout);
        tolua_function(tolua_S,"setColor",lua_cocos2dx_tools_YHUISpriteNumber_setColor);
        tolua_function(tolua_S,"setInterval",lua_cocos2dx_tools_YHUISpriteNumber_setInterval);
        tolua_function(tolua_S,"setIconInterval",lua_cocos2dx_tools_YHUISpriteNumber_setIconInterval);
        tolua_function(tolua_S,"setOpacity",lua_cocos2dx_tools_YHUISpriteNumber_setOpacity);
        tolua_function(tolua_S,"getNumberFontWidth",lua_cocos2dx_tools_YHUISpriteNumber_getNumberFontWidth);
        tolua_function(tolua_S,"init",lua_cocos2dx_tools_YHUISpriteNumber_init);
        tolua_function(tolua_S,"getNumbers",lua_cocos2dx_tools_YHUISpriteNumber_getNumbers);
        tolua_function(tolua_S,"setNumberOffset",lua_cocos2dx_tools_YHUISpriteNumber_setNumberOffset);
        tolua_function(tolua_S,"setAlignType",lua_cocos2dx_tools_YHUISpriteNumber_setAlignType);
        tolua_function(tolua_S,"setIcon",lua_cocos2dx_tools_YHUISpriteNumber_setIcon);
        tolua_function(tolua_S,"create", lua_cocos2dx_tools_YHUISpriteNumber_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(YHUISpriteNumber).name();
    g_luaType[typeName] = "YHUISpriteNumber";
    g_typeCast["YHUISpriteNumber"] = "YHUISpriteNumber";
    return 1;
}

int lua_cocos2dx_tools_YHUIDecimalNumber_setNumber(lua_State* tolua_S)
{
    int argc = 0;
    YHUIDecimalNumber* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUIDecimalNumber",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (YHUIDecimalNumber*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUIDecimalNumber_setNumber'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);

            if (!ok) { break; }
            cobj->setNumber(arg0);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0);

            if (!ok) { break; }
            cobj->setNumber(arg0);
            return 0;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setNumber",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIDecimalNumber_setNumber'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUIDecimalNumber_layout(lua_State* tolua_S)
{
    int argc = 0;
    YHUIDecimalNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUIDecimalNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUIDecimalNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUIDecimalNumber_layout'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->layout();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "layout",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIDecimalNumber_layout'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUIDecimalNumber_setColor(lua_State* tolua_S)
{
    int argc = 0;
    YHUIDecimalNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUIDecimalNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUIDecimalNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUIDecimalNumber_setColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color3B arg0;

        ok &= luaval_to_color3b(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setColor(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIDecimalNumber_setColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUIDecimalNumber_setInterval(lua_State* tolua_S)
{
    int argc = 0;
    YHUIDecimalNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUIDecimalNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUIDecimalNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUIDecimalNumber_setInterval'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setInterval(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setInterval",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIDecimalNumber_setInterval'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUIDecimalNumber_setPlaces(lua_State* tolua_S)
{
    int argc = 0;
    YHUIDecimalNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUIDecimalNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUIDecimalNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUIDecimalNumber_setPlaces'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setPlaces(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setPlaces",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIDecimalNumber_setPlaces'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUIDecimalNumber_setIconInterval(lua_State* tolua_S)
{
    int argc = 0;
    YHUIDecimalNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUIDecimalNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUIDecimalNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUIDecimalNumber_setIconInterval'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setIconInterval(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setIconInterval",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIDecimalNumber_setIconInterval'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUIDecimalNumber_setOpacity(lua_State* tolua_S)
{
    int argc = 0;
    YHUIDecimalNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUIDecimalNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUIDecimalNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUIDecimalNumber_setOpacity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setOpacity(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setOpacity",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIDecimalNumber_setOpacity'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUIDecimalNumber_getNumberFontWidth(lua_State* tolua_S)
{
    int argc = 0;
    YHUIDecimalNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUIDecimalNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUIDecimalNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUIDecimalNumber_getNumberFontWidth'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->getNumberFontWidth();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getNumberFontWidth",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIDecimalNumber_getNumberFontWidth'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUIDecimalNumber_init(lua_State* tolua_S)
{
    int argc = 0;
    YHUIDecimalNumber* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUIDecimalNumber",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (YHUIDecimalNumber*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUIDecimalNumber_init'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 4) {
            cocos2d::SpriteFrame* arg0;
            ok &= luaval_to_object<cocos2d::SpriteFrame>(tolua_S, 2, "cc.SpriteFrame",&arg0);

            if (!ok) { break; }
            cocos2d::Size arg1;
            ok &= luaval_to_size(tolua_S, 3, &arg1);

            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2);

            if (!ok) { break; }
            cocos2d::Sprite* arg3;
            ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 5, "cc.Sprite",&arg3);

            if (!ok) { break; }
            bool ret = cobj->init(arg0, arg1, arg2, arg3);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 5) {
            cocos2d::Texture2D* arg0;
            ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);

            if (!ok) { break; }
            cocos2d::Vec2 arg1;
            ok &= luaval_to_vec2(tolua_S, 3, &arg1);

            if (!ok) { break; }
            cocos2d::Size arg2;
            ok &= luaval_to_size(tolua_S, 4, &arg2);

            if (!ok) { break; }
            double arg3;
            ok &= luaval_to_number(tolua_S, 5,&arg3);

            if (!ok) { break; }
            cocos2d::Sprite* arg4;
            ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 6, "cc.Sprite",&arg4);

            if (!ok) { break; }
            bool ret = cobj->init(arg0, arg1, arg2, arg3, arg4);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 4) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cocos2d::Size arg1;
            ok &= luaval_to_size(tolua_S, 3, &arg1);

            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2);

            if (!ok) { break; }
            cocos2d::Sprite* arg3;
            ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 5, "cc.Sprite",&arg3);

            if (!ok) { break; }
            bool ret = cobj->init(arg0, arg1, arg2, arg3);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIDecimalNumber_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUIDecimalNumber_setAlignType(lua_State* tolua_S)
{
    int argc = 0;
    YHUIDecimalNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUIDecimalNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUIDecimalNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUIDecimalNumber_setAlignType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        YHSpriteNumber_AlignType arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setAlignType(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setAlignType",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIDecimalNumber_setAlignType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUIDecimalNumber_setIcon(lua_State* tolua_S)
{
    int argc = 0;
    YHUIDecimalNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUIDecimalNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUIDecimalNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUIDecimalNumber_setIcon'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Sprite* arg0;

        ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 2, "cc.Sprite",&arg0);
        if(!ok)
            return 0;
        cobj->setIcon(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setIcon",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIDecimalNumber_setIcon'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUIDecimalNumber_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YHUIDecimalNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 4)
        {
            cocos2d::SpriteFrame* arg0;
            ok &= luaval_to_object<cocos2d::SpriteFrame>(tolua_S, 2, "cc.SpriteFrame",&arg0);
            if (!ok) { break; }
            cocos2d::Size arg1;
            ok &= luaval_to_size(tolua_S, 3, &arg1);
            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2);
            if (!ok) { break; }
            cocos2d::Sprite* arg3;
            ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 5, "cc.Sprite",&arg3);
            if (!ok) { break; }
            YHUIDecimalNumber* ret = YHUIDecimalNumber::create(arg0, arg1, arg2, arg3);
            object_to_luaval<YHUIDecimalNumber>(tolua_S, "YHUIDecimalNumber",(YHUIDecimalNumber*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 5)
        {
            cocos2d::Texture2D* arg0;
            ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);
            if (!ok) { break; }
            cocos2d::Vec2 arg1;
            ok &= luaval_to_vec2(tolua_S, 3, &arg1);
            if (!ok) { break; }
            cocos2d::Size arg2;
            ok &= luaval_to_size(tolua_S, 4, &arg2);
            if (!ok) { break; }
            double arg3;
            ok &= luaval_to_number(tolua_S, 5,&arg3);
            if (!ok) { break; }
            cocos2d::Sprite* arg4;
            ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 6, "cc.Sprite",&arg4);
            if (!ok) { break; }
            YHUIDecimalNumber* ret = YHUIDecimalNumber::create(arg0, arg1, arg2, arg3, arg4);
            object_to_luaval<YHUIDecimalNumber>(tolua_S, "YHUIDecimalNumber",(YHUIDecimalNumber*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 4)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            cocos2d::Size arg1;
            ok &= luaval_to_size(tolua_S, 3, &arg1);
            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2);
            if (!ok) { break; }
            cocos2d::Sprite* arg3;
            ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 5, "cc.Sprite",&arg3);
            if (!ok) { break; }
            YHUIDecimalNumber* ret = YHUIDecimalNumber::create(arg0, arg1, arg2, arg3);
            object_to_luaval<YHUIDecimalNumber>(tolua_S, "YHUIDecimalNumber",(YHUIDecimalNumber*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 4);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIDecimalNumber_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tools_YHUIDecimalNumber_constructor(lua_State* tolua_S)
{
    int argc = 0;
    YHUIDecimalNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new YHUIDecimalNumber();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"YHUIDecimalNumber");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "YHUIDecimalNumber",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIDecimalNumber_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_tools_YHUIDecimalNumber_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (YHUIDecimalNumber)");
    return 0;
}

int lua_register_cocos2dx_tools_YHUIDecimalNumber(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"YHUIDecimalNumber");
    tolua_cclass(tolua_S,"YHUIDecimalNumber","YHUIDecimalNumber","YHISpriteNumber",nullptr);

    tolua_beginmodule(tolua_S,"YHUIDecimalNumber");
        tolua_function(tolua_S,"new",lua_cocos2dx_tools_YHUIDecimalNumber_constructor);
        tolua_function(tolua_S,"setNumber",lua_cocos2dx_tools_YHUIDecimalNumber_setNumber);
        tolua_function(tolua_S,"layout",lua_cocos2dx_tools_YHUIDecimalNumber_layout);
        tolua_function(tolua_S,"setColor",lua_cocos2dx_tools_YHUIDecimalNumber_setColor);
        tolua_function(tolua_S,"setInterval",lua_cocos2dx_tools_YHUIDecimalNumber_setInterval);
        tolua_function(tolua_S,"setPlaces",lua_cocos2dx_tools_YHUIDecimalNumber_setPlaces);
        tolua_function(tolua_S,"setIconInterval",lua_cocos2dx_tools_YHUIDecimalNumber_setIconInterval);
        tolua_function(tolua_S,"setOpacity",lua_cocos2dx_tools_YHUIDecimalNumber_setOpacity);
        tolua_function(tolua_S,"getNumberFontWidth",lua_cocos2dx_tools_YHUIDecimalNumber_getNumberFontWidth);
        tolua_function(tolua_S,"init",lua_cocos2dx_tools_YHUIDecimalNumber_init);
        tolua_function(tolua_S,"setAlignType",lua_cocos2dx_tools_YHUIDecimalNumber_setAlignType);
        tolua_function(tolua_S,"setIcon",lua_cocos2dx_tools_YHUIDecimalNumber_setIcon);
        tolua_function(tolua_S,"create", lua_cocos2dx_tools_YHUIDecimalNumber_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(YHUIDecimalNumber).name();
    g_luaType[typeName] = "YHUIDecimalNumber";
    g_typeCast["YHUIDecimalNumber"] = "YHUIDecimalNumber";
    return 1;
}

int lua_cocos2dx_tools_YHUIPercentNumber_layout(lua_State* tolua_S)
{
    int argc = 0;
    YHUIPercentNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUIPercentNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUIPercentNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUIPercentNumber_layout'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->layout();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "layout",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIPercentNumber_layout'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUIPercentNumber_setColor(lua_State* tolua_S)
{
    int argc = 0;
    YHUIPercentNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUIPercentNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUIPercentNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUIPercentNumber_setColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color3B arg0;

        ok &= luaval_to_color3b(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setColor(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIPercentNumber_setColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUIPercentNumber_setPercentInterval(lua_State* tolua_S)
{
    int argc = 0;
    YHUIPercentNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUIPercentNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUIPercentNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUIPercentNumber_setPercentInterval'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setPercentInterval(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setPercentInterval",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIPercentNumber_setPercentInterval'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUIPercentNumber_setOpacity(lua_State* tolua_S)
{
    int argc = 0;
    YHUIPercentNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUIPercentNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUIPercentNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUIPercentNumber_setOpacity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setOpacity(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setOpacity",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIPercentNumber_setOpacity'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUIPercentNumber_getNumberFontWidth(lua_State* tolua_S)
{
    int argc = 0;
    YHUIPercentNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUIPercentNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUIPercentNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUIPercentNumber_getNumberFontWidth'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->getNumberFontWidth();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getNumberFontWidth",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIPercentNumber_getNumberFontWidth'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUIPercentNumber_init(lua_State* tolua_S)
{
    int argc = 0;
    YHUIPercentNumber* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUIPercentNumber",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (YHUIPercentNumber*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUIPercentNumber_init'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 5) {
            cocos2d::SpriteFrame* arg0;
            ok &= luaval_to_object<cocos2d::SpriteFrame>(tolua_S, 2, "cc.SpriteFrame",&arg0);

            if (!ok) { break; }
            cocos2d::Size arg1;
            ok &= luaval_to_size(tolua_S, 3, &arg1);

            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2);

            if (!ok) { break; }
            cocos2d::Sprite* arg3;
            ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 5, "cc.Sprite",&arg3);

            if (!ok) { break; }
            cocos2d::Sprite* arg4;
            ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 6, "cc.Sprite",&arg4);

            if (!ok) { break; }
            bool ret = cobj->init(arg0, arg1, arg2, arg3, arg4);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 6) {
            cocos2d::Texture2D* arg0;
            ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);

            if (!ok) { break; }
            cocos2d::Vec2 arg1;
            ok &= luaval_to_vec2(tolua_S, 3, &arg1);

            if (!ok) { break; }
            cocos2d::Size arg2;
            ok &= luaval_to_size(tolua_S, 4, &arg2);

            if (!ok) { break; }
            double arg3;
            ok &= luaval_to_number(tolua_S, 5,&arg3);

            if (!ok) { break; }
            cocos2d::Sprite* arg4;
            ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 6, "cc.Sprite",&arg4);

            if (!ok) { break; }
            cocos2d::Sprite* arg5;
            ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 7, "cc.Sprite",&arg5);

            if (!ok) { break; }
            bool ret = cobj->init(arg0, arg1, arg2, arg3, arg4, arg5);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 5) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cocos2d::Size arg1;
            ok &= luaval_to_size(tolua_S, 3, &arg1);

            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2);

            if (!ok) { break; }
            cocos2d::Sprite* arg3;
            ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 5, "cc.Sprite",&arg3);

            if (!ok) { break; }
            cocos2d::Sprite* arg4;
            ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 6, "cc.Sprite",&arg4);

            if (!ok) { break; }
            bool ret = cobj->init(arg0, arg1, arg2, arg3, arg4);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 5);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIPercentNumber_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUIPercentNumber_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YHUIPercentNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 5)
        {
            cocos2d::SpriteFrame* arg0;
            ok &= luaval_to_object<cocos2d::SpriteFrame>(tolua_S, 2, "cc.SpriteFrame",&arg0);
            if (!ok) { break; }
            cocos2d::Size arg1;
            ok &= luaval_to_size(tolua_S, 3, &arg1);
            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2);
            if (!ok) { break; }
            cocos2d::Sprite* arg3;
            ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 5, "cc.Sprite",&arg3);
            if (!ok) { break; }
            cocos2d::Sprite* arg4;
            ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 6, "cc.Sprite",&arg4);
            if (!ok) { break; }
            YHUIPercentNumber* ret = YHUIPercentNumber::create(arg0, arg1, arg2, arg3, arg4);
            object_to_luaval<YHUIPercentNumber>(tolua_S, "YHUIPercentNumber",(YHUIPercentNumber*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 6)
        {
            cocos2d::Texture2D* arg0;
            ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);
            if (!ok) { break; }
            cocos2d::Vec2 arg1;
            ok &= luaval_to_vec2(tolua_S, 3, &arg1);
            if (!ok) { break; }
            cocos2d::Size arg2;
            ok &= luaval_to_size(tolua_S, 4, &arg2);
            if (!ok) { break; }
            double arg3;
            ok &= luaval_to_number(tolua_S, 5,&arg3);
            if (!ok) { break; }
            cocos2d::Sprite* arg4;
            ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 6, "cc.Sprite",&arg4);
            if (!ok) { break; }
            cocos2d::Sprite* arg5;
            ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 7, "cc.Sprite",&arg5);
            if (!ok) { break; }
            YHUIPercentNumber* ret = YHUIPercentNumber::create(arg0, arg1, arg2, arg3, arg4, arg5);
            object_to_luaval<YHUIPercentNumber>(tolua_S, "YHUIPercentNumber",(YHUIPercentNumber*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 5)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            cocos2d::Size arg1;
            ok &= luaval_to_size(tolua_S, 3, &arg1);
            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2);
            if (!ok) { break; }
            cocos2d::Sprite* arg3;
            ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 5, "cc.Sprite",&arg3);
            if (!ok) { break; }
            cocos2d::Sprite* arg4;
            ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 6, "cc.Sprite",&arg4);
            if (!ok) { break; }
            YHUIPercentNumber* ret = YHUIPercentNumber::create(arg0, arg1, arg2, arg3, arg4);
            object_to_luaval<YHUIPercentNumber>(tolua_S, "YHUIPercentNumber",(YHUIPercentNumber*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 5);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIPercentNumber_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tools_YHUIPercentNumber_constructor(lua_State* tolua_S)
{
    int argc = 0;
    YHUIPercentNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new YHUIPercentNumber();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"YHUIPercentNumber");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "YHUIPercentNumber",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIPercentNumber_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_tools_YHUIPercentNumber_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (YHUIPercentNumber)");
    return 0;
}

int lua_register_cocos2dx_tools_YHUIPercentNumber(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"YHUIPercentNumber");
    tolua_cclass(tolua_S,"YHUIPercentNumber","YHUIPercentNumber","YHUIDecimalNumber",nullptr);

    tolua_beginmodule(tolua_S,"YHUIPercentNumber");
        tolua_function(tolua_S,"new",lua_cocos2dx_tools_YHUIPercentNumber_constructor);
        tolua_function(tolua_S,"layout",lua_cocos2dx_tools_YHUIPercentNumber_layout);
        tolua_function(tolua_S,"setColor",lua_cocos2dx_tools_YHUIPercentNumber_setColor);
        tolua_function(tolua_S,"setPercentInterval",lua_cocos2dx_tools_YHUIPercentNumber_setPercentInterval);
        tolua_function(tolua_S,"setOpacity",lua_cocos2dx_tools_YHUIPercentNumber_setOpacity);
        tolua_function(tolua_S,"getNumberFontWidth",lua_cocos2dx_tools_YHUIPercentNumber_getNumberFontWidth);
        tolua_function(tolua_S,"init",lua_cocos2dx_tools_YHUIPercentNumber_init);
        tolua_function(tolua_S,"create", lua_cocos2dx_tools_YHUIPercentNumber_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(YHUIPercentNumber).name();
    g_luaType[typeName] = "YHUIPercentNumber";
    g_typeCast["YHUIPercentNumber"] = "YHUIPercentNumber";
    return 1;
}

int lua_cocos2dx_tools_YHUIProductNumber_layout(lua_State* tolua_S)
{
    int argc = 0;
    YHUIProductNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUIProductNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUIProductNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUIProductNumber_layout'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->layout();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "layout",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIProductNumber_layout'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUIProductNumber_setColor(lua_State* tolua_S)
{
    int argc = 0;
    YHUIProductNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUIProductNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUIProductNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUIProductNumber_setColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color3B arg0;

        ok &= luaval_to_color3b(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setColor(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIProductNumber_setColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUIProductNumber_setOpacity(lua_State* tolua_S)
{
    int argc = 0;
    YHUIProductNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUIProductNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUIProductNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUIProductNumber_setOpacity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setOpacity(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setOpacity",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIProductNumber_setOpacity'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUIProductNumber_getNumberFontWidth(lua_State* tolua_S)
{
    int argc = 0;
    YHUIProductNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUIProductNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUIProductNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUIProductNumber_getNumberFontWidth'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->getNumberFontWidth();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getNumberFontWidth",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIProductNumber_getNumberFontWidth'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUIProductNumber_init(lua_State* tolua_S)
{
    int argc = 0;
    YHUIProductNumber* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUIProductNumber",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (YHUIProductNumber*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUIProductNumber_init'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 4) {
            cocos2d::SpriteFrame* arg0;
            ok &= luaval_to_object<cocos2d::SpriteFrame>(tolua_S, 2, "cc.SpriteFrame",&arg0);

            if (!ok) { break; }
            cocos2d::Size arg1;
            ok &= luaval_to_size(tolua_S, 3, &arg1);

            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2);

            if (!ok) { break; }
            cocos2d::Sprite* arg3;
            ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 5, "cc.Sprite",&arg3);

            if (!ok) { break; }
            bool ret = cobj->init(arg0, arg1, arg2, arg3);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 5) {
            cocos2d::Texture2D* arg0;
            ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);

            if (!ok) { break; }
            cocos2d::Vec2 arg1;
            ok &= luaval_to_vec2(tolua_S, 3, &arg1);

            if (!ok) { break; }
            cocos2d::Size arg2;
            ok &= luaval_to_size(tolua_S, 4, &arg2);

            if (!ok) { break; }
            double arg3;
            ok &= luaval_to_number(tolua_S, 5,&arg3);

            if (!ok) { break; }
            cocos2d::Sprite* arg4;
            ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 6, "cc.Sprite",&arg4);

            if (!ok) { break; }
            bool ret = cobj->init(arg0, arg1, arg2, arg3, arg4);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 4) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cocos2d::Size arg1;
            ok &= luaval_to_size(tolua_S, 3, &arg1);

            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2);

            if (!ok) { break; }
            cocos2d::Sprite* arg3;
            ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 5, "cc.Sprite",&arg3);

            if (!ok) { break; }
            bool ret = cobj->init(arg0, arg1, arg2, arg3);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIProductNumber_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUIProductNumber_setProductInterval(lua_State* tolua_S)
{
    int argc = 0;
    YHUIProductNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUIProductNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUIProductNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUIProductNumber_setProductInterval'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setProductInterval(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setProductInterval",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIProductNumber_setProductInterval'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUIProductNumber_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YHUIProductNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 4)
        {
            cocos2d::SpriteFrame* arg0;
            ok &= luaval_to_object<cocos2d::SpriteFrame>(tolua_S, 2, "cc.SpriteFrame",&arg0);
            if (!ok) { break; }
            cocos2d::Size arg1;
            ok &= luaval_to_size(tolua_S, 3, &arg1);
            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2);
            if (!ok) { break; }
            cocos2d::Sprite* arg3;
            ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 5, "cc.Sprite",&arg3);
            if (!ok) { break; }
            YHUIProductNumber* ret = YHUIProductNumber::create(arg0, arg1, arg2, arg3);
            object_to_luaval<YHUIProductNumber>(tolua_S, "YHUIProductNumber",(YHUIProductNumber*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 5)
        {
            cocos2d::Texture2D* arg0;
            ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);
            if (!ok) { break; }
            cocos2d::Vec2 arg1;
            ok &= luaval_to_vec2(tolua_S, 3, &arg1);
            if (!ok) { break; }
            cocos2d::Size arg2;
            ok &= luaval_to_size(tolua_S, 4, &arg2);
            if (!ok) { break; }
            double arg3;
            ok &= luaval_to_number(tolua_S, 5,&arg3);
            if (!ok) { break; }
            cocos2d::Sprite* arg4;
            ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 6, "cc.Sprite",&arg4);
            if (!ok) { break; }
            YHUIProductNumber* ret = YHUIProductNumber::create(arg0, arg1, arg2, arg3, arg4);
            object_to_luaval<YHUIProductNumber>(tolua_S, "YHUIProductNumber",(YHUIProductNumber*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 4)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            cocos2d::Size arg1;
            ok &= luaval_to_size(tolua_S, 3, &arg1);
            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2);
            if (!ok) { break; }
            cocos2d::Sprite* arg3;
            ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 5, "cc.Sprite",&arg3);
            if (!ok) { break; }
            YHUIProductNumber* ret = YHUIProductNumber::create(arg0, arg1, arg2, arg3);
            object_to_luaval<YHUIProductNumber>(tolua_S, "YHUIProductNumber",(YHUIProductNumber*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 4);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIProductNumber_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tools_YHUIProductNumber_constructor(lua_State* tolua_S)
{
    int argc = 0;
    YHUIProductNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new YHUIProductNumber();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"YHUIProductNumber");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "YHUIProductNumber",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIProductNumber_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_tools_YHUIProductNumber_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (YHUIProductNumber)");
    return 0;
}

int lua_register_cocos2dx_tools_YHUIProductNumber(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"YHUIProductNumber");
    tolua_cclass(tolua_S,"YHUIProductNumber","YHUIProductNumber","YHUISpriteNumber",nullptr);

    tolua_beginmodule(tolua_S,"YHUIProductNumber");
        tolua_function(tolua_S,"new",lua_cocos2dx_tools_YHUIProductNumber_constructor);
        tolua_function(tolua_S,"layout",lua_cocos2dx_tools_YHUIProductNumber_layout);
        tolua_function(tolua_S,"setColor",lua_cocos2dx_tools_YHUIProductNumber_setColor);
        tolua_function(tolua_S,"setOpacity",lua_cocos2dx_tools_YHUIProductNumber_setOpacity);
        tolua_function(tolua_S,"getNumberFontWidth",lua_cocos2dx_tools_YHUIProductNumber_getNumberFontWidth);
        tolua_function(tolua_S,"init",lua_cocos2dx_tools_YHUIProductNumber_init);
        tolua_function(tolua_S,"setProductInterval",lua_cocos2dx_tools_YHUIProductNumber_setProductInterval);
        tolua_function(tolua_S,"create", lua_cocos2dx_tools_YHUIProductNumber_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(YHUIProductNumber).name();
    g_luaType[typeName] = "YHUIProductNumber";
    g_typeCast["YHUIProductNumber"] = "YHUIProductNumber";
    return 1;
}

int lua_cocos2dx_tools_YHUITimeNumber_setHourVisible(lua_State* tolua_S)
{
    int argc = 0;
    YHUITimeNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUITimeNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUITimeNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUITimeNumber_setHourVisible'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setHourVisible(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setHourVisible",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUITimeNumber_setHourVisible'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUITimeNumber_setIconAndInterval(lua_State* tolua_S)
{
    int argc = 0;
    YHUITimeNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUITimeNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUITimeNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUITimeNumber_setIconAndInterval'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Sprite* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 2, "cc.Sprite",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->setIconAndInterval(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setIconAndInterval",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUITimeNumber_setIconAndInterval'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUITimeNumber_setMinVisible(lua_State* tolua_S)
{
    int argc = 0;
    YHUITimeNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUITimeNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUITimeNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUITimeNumber_setMinVisible'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setMinVisible(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setMinVisible",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUITimeNumber_setMinVisible'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUITimeNumber_setIconInterval(lua_State* tolua_S)
{
    int argc = 0;
    YHUITimeNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUITimeNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUITimeNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUITimeNumber_setIconInterval'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setIconInterval(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setIconInterval",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUITimeNumber_setIconInterval'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUITimeNumber_setTimeWithMilliSecond(lua_State* tolua_S)
{
    int argc = 0;
    YHUITimeNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUITimeNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUITimeNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUITimeNumber_setTimeWithMilliSecond'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setTimeWithMilliSecond(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        unsigned int arg0;
        bool arg1;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0);

        ok &= luaval_to_boolean(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->setTimeWithMilliSecond(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setTimeWithMilliSecond",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUITimeNumber_setTimeWithMilliSecond'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUITimeNumber_init(lua_State* tolua_S)
{
    int argc = 0;
    YHUITimeNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUITimeNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUITimeNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUITimeNumber_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 7) 
    {
        cocos2d::Sprite* arg0;
        double arg1;
        cocos2d::Sprite* arg2;
        double arg3;
        std::string arg4;
        cocos2d::Size arg5;
        double arg6;

        ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 2, "cc.Sprite",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);

        ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 4, "cc.Sprite",&arg2);

        ok &= luaval_to_number(tolua_S, 5,&arg3);

        ok &= luaval_to_std_string(tolua_S, 6,&arg4);

        ok &= luaval_to_size(tolua_S, 7, &arg5);

        ok &= luaval_to_number(tolua_S, 8,&arg6);
        if(!ok)
            return 0;
        bool ret = cobj->init(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 7);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUITimeNumber_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUITimeNumber_setTimeWithSecond(lua_State* tolua_S)
{
    int argc = 0;
    YHUITimeNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUITimeNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUITimeNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUITimeNumber_setTimeWithSecond'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setTimeWithSecond(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        unsigned int arg0;
        bool arg1;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0);

        ok &= luaval_to_boolean(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->setTimeWithSecond(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setTimeWithSecond",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUITimeNumber_setTimeWithSecond'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUITimeNumber_contentWidth(lua_State* tolua_S)
{
    int argc = 0;
    YHUITimeNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUITimeNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUITimeNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUITimeNumber_contentWidth'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->contentWidth();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "contentWidth",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUITimeNumber_contentWidth'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUITimeNumber_setAlignType(lua_State* tolua_S)
{
    int argc = 0;
    YHUITimeNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUITimeNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUITimeNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUITimeNumber_setAlignType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        YHSpriteNumber_AlignType arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setAlignType(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setAlignType",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUITimeNumber_setAlignType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUITimeNumber_setIcon(lua_State* tolua_S)
{
    int argc = 0;
    YHUITimeNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUITimeNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUITimeNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUITimeNumber_setIcon'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Sprite* arg0;

        ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 2, "cc.Sprite",&arg0);
        if(!ok)
            return 0;
        cobj->setIcon(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setIcon",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUITimeNumber_setIcon'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUITimeNumber_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YHUITimeNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 7)
    {
        cocos2d::Sprite* arg0;
        double arg1;
        cocos2d::Sprite* arg2;
        double arg3;
        std::string arg4;
        cocos2d::Size arg5;
        double arg6;
        ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 2, "cc.Sprite",&arg0);
        ok &= luaval_to_number(tolua_S, 3,&arg1);
        ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 4, "cc.Sprite",&arg2);
        ok &= luaval_to_number(tolua_S, 5,&arg3);
        ok &= luaval_to_std_string(tolua_S, 6,&arg4);
        ok &= luaval_to_size(tolua_S, 7, &arg5);
        ok &= luaval_to_number(tolua_S, 8,&arg6);
        if(!ok)
            return 0;
        YHUITimeNumber* ret = YHUITimeNumber::create(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
        object_to_luaval<YHUITimeNumber>(tolua_S, "YHUITimeNumber",(YHUITimeNumber*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 7);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUITimeNumber_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tools_YHUITimeNumber_constructor(lua_State* tolua_S)
{
    int argc = 0;
    YHUITimeNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new YHUITimeNumber();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"YHUITimeNumber");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "YHUITimeNumber",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUITimeNumber_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_tools_YHUITimeNumber_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (YHUITimeNumber)");
    return 0;
}

int lua_register_cocos2dx_tools_YHUITimeNumber(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"YHUITimeNumber");
    tolua_cclass(tolua_S,"YHUITimeNumber","YHUITimeNumber","cc.Sprite",nullptr);

    tolua_beginmodule(tolua_S,"YHUITimeNumber");
        tolua_function(tolua_S,"new",lua_cocos2dx_tools_YHUITimeNumber_constructor);
        tolua_function(tolua_S,"setHourVisible",lua_cocos2dx_tools_YHUITimeNumber_setHourVisible);
        tolua_function(tolua_S,"setIconAndInterval",lua_cocos2dx_tools_YHUITimeNumber_setIconAndInterval);
        tolua_function(tolua_S,"setMinVisible",lua_cocos2dx_tools_YHUITimeNumber_setMinVisible);
        tolua_function(tolua_S,"setIconInterval",lua_cocos2dx_tools_YHUITimeNumber_setIconInterval);
        tolua_function(tolua_S,"setTimeWithMilliSecond",lua_cocos2dx_tools_YHUITimeNumber_setTimeWithMilliSecond);
        tolua_function(tolua_S,"init",lua_cocos2dx_tools_YHUITimeNumber_init);
        tolua_function(tolua_S,"setTimeWithSecond",lua_cocos2dx_tools_YHUITimeNumber_setTimeWithSecond);
        tolua_function(tolua_S,"contentWidth",lua_cocos2dx_tools_YHUITimeNumber_contentWidth);
        tolua_function(tolua_S,"setAlignType",lua_cocos2dx_tools_YHUITimeNumber_setAlignType);
        tolua_function(tolua_S,"setIcon",lua_cocos2dx_tools_YHUITimeNumber_setIcon);
        tolua_function(tolua_S,"create", lua_cocos2dx_tools_YHUITimeNumber_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(YHUITimeNumber).name();
    g_luaType[typeName] = "YHUITimeNumber";
    g_typeCast["YHUITimeNumber"] = "YHUITimeNumber";
    return 1;
}

int lua_cocos2dx_tools_YHUIVirguleNumber_setRNumber(lua_State* tolua_S)
{
    int argc = 0;
    YHUIVirguleNumber* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUIVirguleNumber",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (YHUIVirguleNumber*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUIVirguleNumber_setRNumber'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);

            if (!ok) { break; }
            cobj->setRNumber(arg0);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0);

            if (!ok) { break; }
            cobj->setRNumber(arg0);
            return 0;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setRNumber",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIVirguleNumber_setRNumber'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUIVirguleNumber_setIconAndInterval(lua_State* tolua_S)
{
    int argc = 0;
    YHUIVirguleNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUIVirguleNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUIVirguleNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUIVirguleNumber_setIconAndInterval'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Sprite* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 2, "cc.Sprite",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->setIconAndInterval(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setIconAndInterval",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIVirguleNumber_setIconAndInterval'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUIVirguleNumber_setIconInterval(lua_State* tolua_S)
{
    int argc = 0;
    YHUIVirguleNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUIVirguleNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUIVirguleNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUIVirguleNumber_setIconInterval'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setIconInterval(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setIconInterval",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIVirguleNumber_setIconInterval'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUIVirguleNumber_setVirgule(lua_State* tolua_S)
{
    int argc = 0;
    YHUIVirguleNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUIVirguleNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUIVirguleNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUIVirguleNumber_setVirgule'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Sprite* arg0;

        ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 2, "cc.Sprite",&arg0);
        if(!ok)
            return 0;
        cobj->setVirgule(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setVirgule",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIVirguleNumber_setVirgule'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUIVirguleNumber_getNumberFontWidth(lua_State* tolua_S)
{
    int argc = 0;
    YHUIVirguleNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUIVirguleNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUIVirguleNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUIVirguleNumber_getNumberFontWidth'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->getNumberFontWidth();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getNumberFontWidth",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIVirguleNumber_getNumberFontWidth'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUIVirguleNumber_init(lua_State* tolua_S)
{
    int argc = 0;
    YHUIVirguleNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUIVirguleNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUIVirguleNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUIVirguleNumber_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        std::string arg0;
        cocos2d::Size arg1;
        double arg2;
        cocos2d::Sprite* arg3;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_size(tolua_S, 3, &arg1);

        ok &= luaval_to_number(tolua_S, 4,&arg2);

        ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 5, "cc.Sprite",&arg3);
        if(!ok)
            return 0;
        bool ret = cobj->init(arg0, arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIVirguleNumber_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUIVirguleNumber_getLNumberSprite(lua_State* tolua_S)
{
    int argc = 0;
    YHUIVirguleNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUIVirguleNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUIVirguleNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUIVirguleNumber_getLNumberSprite'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Sprite* ret = cobj->getLNumberSprite();
        object_to_luaval<cocos2d::Sprite>(tolua_S, "cc.Sprite",(cocos2d::Sprite*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getLNumberSprite",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIVirguleNumber_getLNumberSprite'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUIVirguleNumber_getRNumberSprite(lua_State* tolua_S)
{
    int argc = 0;
    YHUIVirguleNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUIVirguleNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUIVirguleNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUIVirguleNumber_getRNumberSprite'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Sprite* ret = cobj->getRNumberSprite();
        object_to_luaval<cocos2d::Sprite>(tolua_S, "cc.Sprite",(cocos2d::Sprite*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getRNumberSprite",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIVirguleNumber_getRNumberSprite'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUIVirguleNumber_setAlignType(lua_State* tolua_S)
{
    int argc = 0;
    YHUIVirguleNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUIVirguleNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUIVirguleNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUIVirguleNumber_setAlignType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        YHSpriteNumber_AlignType arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setAlignType(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setAlignType",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIVirguleNumber_setAlignType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUIVirguleNumber_setIcon(lua_State* tolua_S)
{
    int argc = 0;
    YHUIVirguleNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUIVirguleNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUIVirguleNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUIVirguleNumber_setIcon'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Sprite* arg0;

        ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 2, "cc.Sprite",&arg0);
        if(!ok)
            return 0;
        cobj->setIcon(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setIcon",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIVirguleNumber_setIcon'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUIVirguleNumber_setLNumber(lua_State* tolua_S)
{
    int argc = 0;
    YHUIVirguleNumber* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUIVirguleNumber",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (YHUIVirguleNumber*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUIVirguleNumber_setLNumber'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);

            if (!ok) { break; }
            cobj->setLNumber(arg0);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0);

            if (!ok) { break; }
            cobj->setLNumber(arg0);
            return 0;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setLNumber",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIVirguleNumber_setLNumber'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUIVirguleNumber_setLRNumber(lua_State* tolua_S)
{
    int argc = 0;
    YHUIVirguleNumber* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUIVirguleNumber",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (YHUIVirguleNumber*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUIVirguleNumber_setLRNumber'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);

            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1);

            if (!ok) { break; }
            cobj->setLRNumber(arg0, arg1);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0);

            if (!ok) { break; }
            unsigned int arg1;
            ok &= luaval_to_uint32(tolua_S, 3,&arg1);

            if (!ok) { break; }
            cobj->setLRNumber(arg0, arg1);
            return 0;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setLRNumber",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIVirguleNumber_setLRNumber'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUIVirguleNumber_setVirguleInterval(lua_State* tolua_S)
{
    int argc = 0;
    YHUIVirguleNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YHUIVirguleNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YHUIVirguleNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_YHUIVirguleNumber_setVirguleInterval'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setVirguleInterval(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setVirguleInterval",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIVirguleNumber_setVirguleInterval'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_YHUIVirguleNumber_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YHUIVirguleNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 4)
    {
        std::string arg0;
        cocos2d::Size arg1;
        double arg2;
        cocos2d::Sprite* arg3;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        ok &= luaval_to_size(tolua_S, 3, &arg1);
        ok &= luaval_to_number(tolua_S, 4,&arg2);
        ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 5, "cc.Sprite",&arg3);
        if(!ok)
            return 0;
        YHUIVirguleNumber* ret = YHUIVirguleNumber::create(arg0, arg1, arg2, arg3);
        object_to_luaval<YHUIVirguleNumber>(tolua_S, "YHUIVirguleNumber",(YHUIVirguleNumber*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 4);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_YHUIVirguleNumber_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tools_YHUIVirguleNumber_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (YHUIVirguleNumber)");
    return 0;
}

int lua_register_cocos2dx_tools_YHUIVirguleNumber(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"YHUIVirguleNumber");
    tolua_cclass(tolua_S,"YHUIVirguleNumber","YHUIVirguleNumber","CCSpecialSprite",nullptr);

    tolua_beginmodule(tolua_S,"YHUIVirguleNumber");
        tolua_function(tolua_S,"setRNumber",lua_cocos2dx_tools_YHUIVirguleNumber_setRNumber);
        tolua_function(tolua_S,"setIconAndInterval",lua_cocos2dx_tools_YHUIVirguleNumber_setIconAndInterval);
        tolua_function(tolua_S,"setIconInterval",lua_cocos2dx_tools_YHUIVirguleNumber_setIconInterval);
        tolua_function(tolua_S,"setVirgule",lua_cocos2dx_tools_YHUIVirguleNumber_setVirgule);
        tolua_function(tolua_S,"getNumberFontWidth",lua_cocos2dx_tools_YHUIVirguleNumber_getNumberFontWidth);
        tolua_function(tolua_S,"init",lua_cocos2dx_tools_YHUIVirguleNumber_init);
        tolua_function(tolua_S,"getLNumberSprite",lua_cocos2dx_tools_YHUIVirguleNumber_getLNumberSprite);
        tolua_function(tolua_S,"getRNumberSprite",lua_cocos2dx_tools_YHUIVirguleNumber_getRNumberSprite);
        tolua_function(tolua_S,"setAlignType",lua_cocos2dx_tools_YHUIVirguleNumber_setAlignType);
        tolua_function(tolua_S,"setIcon",lua_cocos2dx_tools_YHUIVirguleNumber_setIcon);
        tolua_function(tolua_S,"setLNumber",lua_cocos2dx_tools_YHUIVirguleNumber_setLNumber);
        tolua_function(tolua_S,"setLRNumber",lua_cocos2dx_tools_YHUIVirguleNumber_setLRNumber);
        tolua_function(tolua_S,"setVirguleInterval",lua_cocos2dx_tools_YHUIVirguleNumber_setVirguleInterval);
        tolua_function(tolua_S,"create", lua_cocos2dx_tools_YHUIVirguleNumber_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(YHUIVirguleNumber).name();
    g_luaType[typeName] = "YHUIVirguleNumber";
    g_typeCast["YHUIVirguleNumber"] = "YHUIVirguleNumber";
    return 1;
}

int lua_cocos2dx_tools_CCKeyTimeCallbackSprite_playWithSequenceFrames(lua_State* tolua_S)
{
    int argc = 0;
    CCKeyTimeCallbackSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCKeyTimeCallbackSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCKeyTimeCallbackSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_CCKeyTimeCallbackSprite_playWithSequenceFrames'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Animation* arg0;
        bool arg1;

        ok &= luaval_to_object<cocos2d::Animation>(tolua_S, 2, "cc.Animation",&arg0);

        ok &= luaval_to_boolean(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->playWithSequenceFrames(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "playWithSequenceFrames",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_CCKeyTimeCallbackSprite_playWithSequenceFrames'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_CCKeyTimeCallbackSprite_playWithDataDict(lua_State* tolua_S)
{
    int argc = 0;
    CCKeyTimeCallbackSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCKeyTimeCallbackSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCKeyTimeCallbackSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_CCKeyTimeCallbackSprite_playWithDataDict'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Animation* arg0;
        cocos2d::__Dictionary* arg1;
        bool arg2;

        ok &= luaval_to_object<cocos2d::Animation>(tolua_S, 2, "cc.Animation",&arg0);

        ok &= luaval_to_object<cocos2d::__Dictionary>(tolua_S, 3, "cc.__Dictionary",&arg1);

        ok &= luaval_to_boolean(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        cobj->playWithDataDict(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "playWithDataDict",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_CCKeyTimeCallbackSprite_playWithDataDict'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_CCKeyTimeCallbackSprite_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CCKeyTimeCallbackSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 3)
        {
            cocos2d::Animation* arg0;
            ok &= luaval_to_object<cocos2d::Animation>(tolua_S, 2, "cc.Animation",&arg0);
            if (!ok) { break; }
            cocos2d::__Dictionary* arg1;
            ok &= luaval_to_object<cocos2d::__Dictionary>(tolua_S, 3, "cc.__Dictionary",&arg1);
            if (!ok) { break; }
            bool arg2;
            ok &= luaval_to_boolean(tolua_S, 4,&arg2);
            if (!ok) { break; }
            CCKeyTimeCallbackSprite* ret = CCKeyTimeCallbackSprite::create(arg0, arg1, arg2);
            object_to_luaval<CCKeyTimeCallbackSprite>(tolua_S, "CCKeyTimeCallbackSprite",(CCKeyTimeCallbackSprite*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 2)
        {
            cocos2d::Animation* arg0;
            ok &= luaval_to_object<cocos2d::Animation>(tolua_S, 2, "cc.Animation",&arg0);
            if (!ok) { break; }
            bool arg1;
            ok &= luaval_to_boolean(tolua_S, 3,&arg1);
            if (!ok) { break; }
            CCKeyTimeCallbackSprite* ret = CCKeyTimeCallbackSprite::create(arg0, arg1);
            object_to_luaval<CCKeyTimeCallbackSprite>(tolua_S, "CCKeyTimeCallbackSprite",(CCKeyTimeCallbackSprite*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_CCKeyTimeCallbackSprite_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tools_CCKeyTimeCallbackSprite_constructor(lua_State* tolua_S)
{
    int argc = 0;
    CCKeyTimeCallbackSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new CCKeyTimeCallbackSprite();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"CCKeyTimeCallbackSprite");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CCKeyTimeCallbackSprite",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_CCKeyTimeCallbackSprite_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_tools_CCKeyTimeCallbackSprite_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCKeyTimeCallbackSprite)");
    return 0;
}

int lua_register_cocos2dx_tools_CCKeyTimeCallbackSprite(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CCKeyTimeCallbackSprite");
    tolua_cclass(tolua_S,"CCKeyTimeCallbackSprite","CCKeyTimeCallbackSprite","cc.Sprite",nullptr);

    tolua_beginmodule(tolua_S,"CCKeyTimeCallbackSprite");
        tolua_function(tolua_S,"new",lua_cocos2dx_tools_CCKeyTimeCallbackSprite_constructor);
        tolua_function(tolua_S,"playWithSequenceFrames",lua_cocos2dx_tools_CCKeyTimeCallbackSprite_playWithSequenceFrames);
        tolua_function(tolua_S,"playWithDataDict",lua_cocos2dx_tools_CCKeyTimeCallbackSprite_playWithDataDict);
        tolua_function(tolua_S,"create", lua_cocos2dx_tools_CCKeyTimeCallbackSprite_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CCKeyTimeCallbackSprite).name();
    g_luaType[typeName] = "CCKeyTimeCallbackSprite";
    g_typeCast["CCKeyTimeCallbackSprite"] = "CCKeyTimeCallbackSprite";
    return 1;
}

int lua_cocos2dx_tools_CCEncryptNumber_uint32Value(lua_State* tolua_S)
{
    int argc = 0;
    CCEncryptNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCEncryptNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCEncryptNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_CCEncryptNumber_uint32Value'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        unsigned int ret = cobj->uint32Value();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "uint32Value",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_CCEncryptNumber_uint32Value'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_CCEncryptNumber_float64Value(lua_State* tolua_S)
{
    int argc = 0;
    CCEncryptNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCEncryptNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCEncryptNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_CCEncryptNumber_float64Value'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->float64Value();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "float64Value",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_CCEncryptNumber_float64Value'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_CCEncryptNumber_boolValue(lua_State* tolua_S)
{
    int argc = 0;
    CCEncryptNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCEncryptNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCEncryptNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_CCEncryptNumber_boolValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->boolValue();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "boolValue",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_CCEncryptNumber_boolValue'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_CCEncryptNumber_int32Value(lua_State* tolua_S)
{
    int argc = 0;
    CCEncryptNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCEncryptNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCEncryptNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_CCEncryptNumber_int32Value'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->int32Value();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "int32Value",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_CCEncryptNumber_int32Value'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_CCEncryptNumber_init(lua_State* tolua_S)
{
    int argc = 0;
    CCEncryptNumber* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCEncryptNumber",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CCEncryptNumber*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_CCEncryptNumber_init'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0);

            if (!ok) { break; }
            bool ret = cobj->init(arg0);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);

            if (!ok) { break; }
            bool ret = cobj->init(arg0);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0);

            if (!ok) { break; }
            bool ret = cobj->init(arg0);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0);

            if (!ok) { break; }
            bool ret = cobj->init(arg0);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            bool arg0;
            ok &= luaval_to_boolean(tolua_S, 2,&arg0);

            if (!ok) { break; }
            bool ret = cobj->init(arg0);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_CCEncryptNumber_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_CCEncryptNumber_float32Value(lua_State* tolua_S)
{
    int argc = 0;
    CCEncryptNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCEncryptNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCEncryptNumber*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_CCEncryptNumber_float32Value'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->float32Value();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "float32Value",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_CCEncryptNumber_float32Value'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_CCEncryptNumber_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CCEncryptNumber",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 1)
        {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0);
            if (!ok) { break; }
            CCEncryptNumber* ret = CCEncryptNumber::create(arg0);
            object_to_luaval<CCEncryptNumber>(tolua_S, "CCEncryptNumber",(CCEncryptNumber*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 1)
        {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
            if (!ok) { break; }
            CCEncryptNumber* ret = CCEncryptNumber::create(arg0);
            object_to_luaval<CCEncryptNumber>(tolua_S, "CCEncryptNumber",(CCEncryptNumber*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 1)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0);
            if (!ok) { break; }
            CCEncryptNumber* ret = CCEncryptNumber::create(arg0);
            object_to_luaval<CCEncryptNumber>(tolua_S, "CCEncryptNumber",(CCEncryptNumber*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 1)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0);
            if (!ok) { break; }
            CCEncryptNumber* ret = CCEncryptNumber::create(arg0);
            object_to_luaval<CCEncryptNumber>(tolua_S, "CCEncryptNumber",(CCEncryptNumber*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_CCEncryptNumber_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tools_CCEncryptNumber_constructor(lua_State* tolua_S)
{
    int argc = 0;
    CCEncryptNumber* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new CCEncryptNumber();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"CCEncryptNumber");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CCEncryptNumber",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_CCEncryptNumber_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_tools_CCEncryptNumber_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCEncryptNumber)");
    return 0;
}

int lua_register_cocos2dx_tools_CCEncryptNumber(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CCEncryptNumber");
    tolua_cclass(tolua_S,"CCEncryptNumber","CCEncryptNumber","YHObject",nullptr);

    tolua_beginmodule(tolua_S,"CCEncryptNumber");
        tolua_function(tolua_S,"new",lua_cocos2dx_tools_CCEncryptNumber_constructor);
        tolua_function(tolua_S,"uint32Value",lua_cocos2dx_tools_CCEncryptNumber_uint32Value);
        tolua_function(tolua_S,"float64Value",lua_cocos2dx_tools_CCEncryptNumber_float64Value);
        tolua_function(tolua_S,"boolValue",lua_cocos2dx_tools_CCEncryptNumber_boolValue);
        tolua_function(tolua_S,"int32Value",lua_cocos2dx_tools_CCEncryptNumber_int32Value);
        tolua_function(tolua_S,"init",lua_cocos2dx_tools_CCEncryptNumber_init);
        tolua_function(tolua_S,"float32Value",lua_cocos2dx_tools_CCEncryptNumber_float32Value);
        tolua_function(tolua_S,"create", lua_cocos2dx_tools_CCEncryptNumber_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CCEncryptNumber).name();
    g_luaType[typeName] = "CCEncryptNumber";
    g_typeCast["CCEncryptNumber"] = "CCEncryptNumber";
    return 1;
}

int lua_cocos2dx_tools_ShaderNode_draw(lua_State* tolua_S)
{
    int argc = 0;
    ShaderNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ShaderNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ShaderNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_ShaderNode_draw'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Renderer* arg0;
        cocos2d::Mat4 arg1;
        unsigned int arg2;

        ok &= luaval_to_object<cocos2d::Renderer>(tolua_S, 2, "cc.Renderer",&arg0);

        ok &= luaval_to_mat4(tolua_S, 3, &arg1);

        ok &= luaval_to_uint32(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        cobj->draw(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "draw",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_ShaderNode_draw'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_ShaderNode_initWithVertex(lua_State* tolua_S)
{
    int argc = 0;
    ShaderNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ShaderNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ShaderNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_ShaderNode_initWithVertex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        const char* arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        bool ret = cobj->initWithVertex(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initWithVertex",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_ShaderNode_initWithVertex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_ShaderNode_update(lua_State* tolua_S)
{
    int argc = 0;
    ShaderNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ShaderNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ShaderNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_ShaderNode_update'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->update(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "update",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_ShaderNode_update'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_ShaderNode_loadShaderVertex(lua_State* tolua_S)
{
    int argc = 0;
    ShaderNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ShaderNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ShaderNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_ShaderNode_loadShaderVertex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        const char* arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        cobj->loadShaderVertex(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "loadShaderVertex",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_ShaderNode_loadShaderVertex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_ShaderNode_setContentSize(lua_State* tolua_S)
{
    int argc = 0;
    ShaderNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ShaderNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ShaderNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tools_ShaderNode_setContentSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Size arg0;

        ok &= luaval_to_size(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setContentSize(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setContentSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_ShaderNode_setContentSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tools_ShaderNode_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ShaderNode",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        ShaderNode* ret = ShaderNode::create();
        object_to_luaval<ShaderNode>(tolua_S, "ShaderNode",(ShaderNode*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_ShaderNode_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tools_ShaderNode_constructor(lua_State* tolua_S)
{
    int argc = 0;
    ShaderNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new ShaderNode();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"ShaderNode");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "ShaderNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tools_ShaderNode_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_tools_ShaderNode_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ShaderNode)");
    return 0;
}

int lua_register_cocos2dx_tools_ShaderNode(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ShaderNode");
    tolua_cclass(tolua_S,"ShaderNode","ShaderNode","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"ShaderNode");
        tolua_function(tolua_S,"new",lua_cocos2dx_tools_ShaderNode_constructor);
        tolua_function(tolua_S,"draw",lua_cocos2dx_tools_ShaderNode_draw);
        tolua_function(tolua_S,"initWithVertex",lua_cocos2dx_tools_ShaderNode_initWithVertex);
        tolua_function(tolua_S,"update",lua_cocos2dx_tools_ShaderNode_update);
        tolua_function(tolua_S,"loadShaderVertex",lua_cocos2dx_tools_ShaderNode_loadShaderVertex);
        tolua_function(tolua_S,"setContentSize",lua_cocos2dx_tools_ShaderNode_setContentSize);
        tolua_function(tolua_S,"create", lua_cocos2dx_tools_ShaderNode_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(ShaderNode).name();
    g_luaType[typeName] = "ShaderNode";
    g_typeCast["ShaderNode"] = "ShaderNode";
    return 1;
}
TOLUA_API int register_all_cocos2dx_tools(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,nullptr,0);
	tolua_beginmodule(tolua_S,nullptr);

	lua_register_cocos2dx_tools_YHISpriteNumber(tolua_S);
	lua_register_cocos2dx_tools_YHUISpriteNumber(tolua_S);
	lua_register_cocos2dx_tools_YHUIProductNumber(tolua_S);
	lua_register_cocos2dx_tools_CCSpecialSprite(tolua_S);
	lua_register_cocos2dx_tools_YHUIVirguleNumber(tolua_S);
	lua_register_cocos2dx_tools_CCKeyTimeCallbackSprite(tolua_S);
	lua_register_cocos2dx_tools_YHObject(tolua_S);
	lua_register_cocos2dx_tools_YHSpriteDefiner(tolua_S);
	lua_register_cocos2dx_tools_YHAnimationFrameDefiner(tolua_S);
	lua_register_cocos2dx_tools_YHUITileBackground(tolua_S);
	lua_register_cocos2dx_tools_AnimatorInitData(tolua_S);
	lua_register_cocos2dx_tools_CCEncryptNumber(tolua_S);
	lua_register_cocos2dx_tools_ScissorNode(tolua_S);
	lua_register_cocos2dx_tools_Shaker(tolua_S);
	lua_register_cocos2dx_tools_ShaderNode(tolua_S);
	lua_register_cocos2dx_tools_YHDataManager(tolua_S);
	lua_register_cocos2dx_tools_YHLanguageManager(tolua_S);
	lua_register_cocos2dx_tools_YHDefaultFiniteEffect(tolua_S);
	lua_register_cocos2dx_tools_YHUIDecimalNumber(tolua_S);
	lua_register_cocos2dx_tools_YHUIPercentNumber(tolua_S);
	lua_register_cocos2dx_tools_YHEffectFactory(tolua_S);
	lua_register_cocos2dx_tools_YHTimerCache(tolua_S);
	lua_register_cocos2dx_tools_YHCCActionHelper(tolua_S);
	lua_register_cocos2dx_tools_YHAnimationHelper(tolua_S);
	lua_register_cocos2dx_tools_YHGameBasicInfo(tolua_S);
	lua_register_cocos2dx_tools_YHAnimationPair(tolua_S);
	lua_register_cocos2dx_tools_YHTimer(tolua_S);
	lua_register_cocos2dx_tools_YHAnimationKeyEvents(tolua_S);
	lua_register_cocos2dx_tools_AnimatorModuleDataCache(tolua_S);
	lua_register_cocos2dx_tools_ActionContext(tolua_S);
	lua_register_cocos2dx_tools_AnimatorData(tolua_S);
	lua_register_cocos2dx_tools_YHUIUnitComboBackground(tolua_S);
	lua_register_cocos2dx_tools_AnimatorModuleData(tolua_S);
	lua_register_cocos2dx_tools_AnimatorSettingData(tolua_S);
	lua_register_cocos2dx_tools_AvatarComponent(tolua_S);
	lua_register_cocos2dx_tools_YHFontManager(tolua_S);
	lua_register_cocos2dx_tools_YHEffectDefiner(tolua_S);
	lua_register_cocos2dx_tools_AnimatorDataCache(tolua_S);
	lua_register_cocos2dx_tools_AnimatorAnimData(tolua_S);
	lua_register_cocos2dx_tools_AEEffectSprite(tolua_S);
	lua_register_cocos2dx_tools_YHUITimeNumber(tolua_S);
	lua_register_cocos2dx_tools_AnimatorSettingDataCache(tolua_S);
	lua_register_cocos2dx_tools_YHAnimationDefiner(tolua_S);
	lua_register_cocos2dx_tools_YHAnimationCache(tolua_S);
	lua_register_cocos2dx_tools_SoundController(tolua_S);
	lua_register_cocos2dx_tools_YHDevice(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

