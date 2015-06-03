#include "lua_cocos2dx_dictionary_auto.hpp"
#include "CCDictionary.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_cocos2dx_dictionary___Dictionary_count(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::__Dictionary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.__Dictionary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::__Dictionary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dictionary___Dictionary_count'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dictionary___Dictionary_count'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->count();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.__Dictionary:count",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dictionary___Dictionary_count'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dictionary___Dictionary_setObject(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::__Dictionary* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.__Dictionary",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::__Dictionary*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dictionary___Dictionary_setObject'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            cocos2d::Ref* arg0;
            ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 2, "cc.Ref",&arg0);

            if (!ok) { break; }
            long arg1;
            ok &= luaval_to_long(tolua_S, 3, &arg1, "cc.__Dictionary:setObject");

            if (!ok) { break; }
            cobj->setObject(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            cocos2d::Ref* arg0;
            ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 2, "cc.Ref",&arg0);

            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1, "cc.__Dictionary:setObject");

            if (!ok) { break; }
            cobj->setObject(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "cc.__Dictionary:setObject",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dictionary___Dictionary_setObject'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dictionary___Dictionary_removeObjectForKey(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::__Dictionary* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.__Dictionary",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::__Dictionary*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dictionary___Dictionary_removeObjectForKey'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long arg0;
            ok &= luaval_to_long(tolua_S, 2, &arg0, "cc.__Dictionary:removeObjectForKey");

            if (!ok) { break; }
            cobj->removeObjectForKey(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.__Dictionary:removeObjectForKey");

            if (!ok) { break; }
            cobj->removeObjectForKey(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "cc.__Dictionary:removeObjectForKey",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dictionary___Dictionary_removeObjectForKey'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dictionary___Dictionary_clone(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::__Dictionary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.__Dictionary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::__Dictionary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dictionary___Dictionary_clone'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dictionary___Dictionary_clone'", nullptr);
            return 0;
        }
        cocos2d::__Dictionary* ret = cobj->clone();
        object_to_luaval<cocos2d::__Dictionary>(tolua_S, "cc.__Dictionary",(cocos2d::__Dictionary*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.__Dictionary:clone",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dictionary___Dictionary_clone'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dictionary___Dictionary_objectForKey(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::__Dictionary* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.__Dictionary",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::__Dictionary*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dictionary___Dictionary_objectForKey'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long arg0;
            ok &= luaval_to_long(tolua_S, 2, &arg0, "cc.__Dictionary:objectForKey");

            if (!ok) { break; }
            cocos2d::Ref* ret = cobj->objectForKey(arg0);
            object_to_luaval<cocos2d::Ref>(tolua_S, "cc.Ref",(cocos2d::Ref*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.__Dictionary:objectForKey");

            if (!ok) { break; }
            cocos2d::Ref* ret = cobj->objectForKey(arg0);
            object_to_luaval<cocos2d::Ref>(tolua_S, "cc.Ref",(cocos2d::Ref*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "cc.__Dictionary:objectForKey",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dictionary___Dictionary_objectForKey'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dictionary___Dictionary_randomObject(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::__Dictionary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.__Dictionary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::__Dictionary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dictionary___Dictionary_randomObject'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dictionary___Dictionary_randomObject'", nullptr);
            return 0;
        }
        cocos2d::Ref* ret = cobj->randomObject();
        object_to_luaval<cocos2d::Ref>(tolua_S, "cc.Ref",(cocos2d::Ref*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.__Dictionary:randomObject",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dictionary___Dictionary_randomObject'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dictionary___Dictionary_init(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::__Dictionary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.__Dictionary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::__Dictionary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dictionary___Dictionary_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dictionary___Dictionary_init'", nullptr);
            return 0;
        }
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.__Dictionary:init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dictionary___Dictionary_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dictionary___Dictionary_removeAllObjects(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::__Dictionary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.__Dictionary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::__Dictionary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dictionary___Dictionary_removeAllObjects'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dictionary___Dictionary_removeAllObjects'", nullptr);
            return 0;
        }
        cobj->removeAllObjects();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.__Dictionary:removeAllObjects",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dictionary___Dictionary_removeAllObjects'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dictionary___Dictionary_removeObjectsForKeys(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::__Dictionary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.__Dictionary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::__Dictionary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dictionary___Dictionary_removeObjectsForKeys'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::__Array* arg0;

        ok &= luaval_to_object<cocos2d::__Array>(tolua_S, 2, "cc.__Array",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dictionary___Dictionary_removeObjectsForKeys'", nullptr);
            return 0;
        }
        cobj->removeObjectsForKeys(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.__Dictionary:removeObjectsForKeys",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dictionary___Dictionary_removeObjectsForKeys'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dictionary___Dictionary_valueForKey(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::__Dictionary* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.__Dictionary",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::__Dictionary*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dictionary___Dictionary_valueForKey'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long arg0;
            ok &= luaval_to_long(tolua_S, 2, &arg0, "cc.__Dictionary:valueForKey");

            if (!ok) { break; }
            const cocos2d::__String* ret = cobj->valueForKey(arg0);
            object_to_luaval<cocos2d::__String>(tolua_S, "cc.__String",(cocos2d::__String*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.__Dictionary:valueForKey");

            if (!ok) { break; }
            const cocos2d::__String* ret = cobj->valueForKey(arg0);
            object_to_luaval<cocos2d::__String>(tolua_S, "cc.__String",(cocos2d::__String*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "cc.__Dictionary:valueForKey",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dictionary___Dictionary_valueForKey'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dictionary___Dictionary_writeToFile(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::__Dictionary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.__Dictionary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::__Dictionary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dictionary___Dictionary_writeToFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.__Dictionary:writeToFile"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dictionary___Dictionary_writeToFile'", nullptr);
            return 0;
        }
        bool ret = cobj->writeToFile(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.__Dictionary:writeToFile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dictionary___Dictionary_writeToFile'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dictionary___Dictionary_removeObjectForElememt(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::__Dictionary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.__Dictionary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::__Dictionary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dictionary___Dictionary_removeObjectForElememt'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::DictElement* arg0;

        ok &= luaval_to_object<cocos2d::DictElement>(tolua_S, 2, "cc.DictElement",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dictionary___Dictionary_removeObjectForElememt'", nullptr);
            return 0;
        }
        cobj->removeObjectForElememt(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.__Dictionary:removeObjectForElememt",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dictionary___Dictionary_removeObjectForElememt'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dictionary___Dictionary_allKeys(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::__Dictionary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.__Dictionary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::__Dictionary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dictionary___Dictionary_allKeys'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dictionary___Dictionary_allKeys'", nullptr);
            return 0;
        }
        cocos2d::__Array* ret = cobj->allKeys();
        object_to_luaval<cocos2d::__Array>(tolua_S, "cc.__Array",(cocos2d::__Array*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.__Dictionary:allKeys",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dictionary___Dictionary_allKeys'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dictionary___Dictionary_allKeysForObject(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::__Dictionary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.__Dictionary",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::__Dictionary*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dictionary___Dictionary_allKeysForObject'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Ref* arg0;

        ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 2, "cc.Ref",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dictionary___Dictionary_allKeysForObject'", nullptr);
            return 0;
        }
        cocos2d::__Array* ret = cobj->allKeysForObject(arg0);
        object_to_luaval<cocos2d::__Array>(tolua_S, "cc.__Array",(cocos2d::__Array*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.__Dictionary:allKeysForObject",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dictionary___Dictionary_allKeysForObject'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dictionary___Dictionary_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.__Dictionary",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dictionary___Dictionary_create'", nullptr);
            return 0;
        }
        cocos2d::__Dictionary* ret = cocos2d::__Dictionary::create();
        object_to_luaval<cocos2d::__Dictionary>(tolua_S, "cc.__Dictionary",(cocos2d::__Dictionary*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.__Dictionary:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dictionary___Dictionary_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_dictionary___Dictionary_createWithContentsOfFile(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.__Dictionary",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.__Dictionary:createWithContentsOfFile"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dictionary___Dictionary_createWithContentsOfFile'", nullptr);
            return 0;
        }
        cocos2d::__Dictionary* ret = cocos2d::__Dictionary::createWithContentsOfFile(arg0);
        object_to_luaval<cocos2d::__Dictionary>(tolua_S, "cc.__Dictionary",(cocos2d::__Dictionary*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.__Dictionary:createWithContentsOfFile",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dictionary___Dictionary_createWithContentsOfFile'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_dictionary___Dictionary_createWithDictionary(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.__Dictionary",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        cocos2d::__Dictionary* arg0;
        ok &= luaval_to_object<cocos2d::__Dictionary>(tolua_S, 2, "cc.__Dictionary",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dictionary___Dictionary_createWithDictionary'", nullptr);
            return 0;
        }
        cocos2d::__Dictionary* ret = cocos2d::__Dictionary::createWithDictionary(arg0);
        object_to_luaval<cocos2d::__Dictionary>(tolua_S, "cc.__Dictionary",(cocos2d::__Dictionary*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.__Dictionary:createWithDictionary",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dictionary___Dictionary_createWithDictionary'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_dictionary___Dictionary_createWithContentsOfFileThreadSafe(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.__Dictionary",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.__Dictionary:createWithContentsOfFileThreadSafe"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dictionary___Dictionary_createWithContentsOfFileThreadSafe'", nullptr);
            return 0;
        }
        cocos2d::__Dictionary* ret = cocos2d::__Dictionary::createWithContentsOfFileThreadSafe(arg0);
        object_to_luaval<cocos2d::__Dictionary>(tolua_S, "cc.__Dictionary",(cocos2d::__Dictionary*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.__Dictionary:createWithContentsOfFileThreadSafe",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dictionary___Dictionary_createWithContentsOfFileThreadSafe'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_dictionary___Dictionary_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::__Dictionary* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dictionary___Dictionary_constructor'", nullptr);
            return 0;
        }
        cobj = new cocos2d::__Dictionary();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.__Dictionary");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.__Dictionary:__Dictionary",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dictionary___Dictionary_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_dictionary___Dictionary_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (__Dictionary)");
    return 0;
}

int lua_register_cocos2dx_dictionary___Dictionary(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.__Dictionary");
    tolua_cclass(tolua_S,"__Dictionary","cc.__Dictionary","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"__Dictionary");
        tolua_function(tolua_S,"new",lua_cocos2dx_dictionary___Dictionary_constructor);
        tolua_function(tolua_S,"count",lua_cocos2dx_dictionary___Dictionary_count);
        tolua_function(tolua_S,"setObject",lua_cocos2dx_dictionary___Dictionary_setObject);
        tolua_function(tolua_S,"removeObjectForKey",lua_cocos2dx_dictionary___Dictionary_removeObjectForKey);
        tolua_function(tolua_S,"clone",lua_cocos2dx_dictionary___Dictionary_clone);
        tolua_function(tolua_S,"objectForKey",lua_cocos2dx_dictionary___Dictionary_objectForKey);
        tolua_function(tolua_S,"randomObject",lua_cocos2dx_dictionary___Dictionary_randomObject);
        tolua_function(tolua_S,"init",lua_cocos2dx_dictionary___Dictionary_init);
        tolua_function(tolua_S,"removeAllObjects",lua_cocos2dx_dictionary___Dictionary_removeAllObjects);
        tolua_function(tolua_S,"removeObjectsForKeys",lua_cocos2dx_dictionary___Dictionary_removeObjectsForKeys);
        tolua_function(tolua_S,"valueForKey",lua_cocos2dx_dictionary___Dictionary_valueForKey);
        tolua_function(tolua_S,"writeToFile",lua_cocos2dx_dictionary___Dictionary_writeToFile);
        tolua_function(tolua_S,"removeObjectForElememt",lua_cocos2dx_dictionary___Dictionary_removeObjectForElememt);
        tolua_function(tolua_S,"allKeys",lua_cocos2dx_dictionary___Dictionary_allKeys);
        tolua_function(tolua_S,"allKeysForObject",lua_cocos2dx_dictionary___Dictionary_allKeysForObject);
        tolua_function(tolua_S,"create", lua_cocos2dx_dictionary___Dictionary_create);
        tolua_function(tolua_S,"createWithContentsOfFile", lua_cocos2dx_dictionary___Dictionary_createWithContentsOfFile);
        tolua_function(tolua_S,"createWithDictionary", lua_cocos2dx_dictionary___Dictionary_createWithDictionary);
        tolua_function(tolua_S,"createWithContentsOfFileThreadSafe", lua_cocos2dx_dictionary___Dictionary_createWithContentsOfFileThreadSafe);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::__Dictionary).name();
    g_luaType[typeName] = "cc.__Dictionary";
    g_typeCast["__Dictionary"] = "cc.__Dictionary";
    return 1;
}
TOLUA_API int register_all_cocos2dx_dictionary(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"cc",0);
	tolua_beginmodule(tolua_S,"cc");

	lua_register_cocos2dx_dictionary___Dictionary(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

