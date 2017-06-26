#define EXTENSION_NAME DefReview
#define LIB_NAME "DefReview"
#define MODULE_NAME "defreview"

#define DLIB_LOG_DOMAIN LIB_NAME
#include <dmsdk/sdk.h>

#if defined(DM_PLATFORM_IOS)
#include "objc/DefReviewIOS.h"

static int isSupported(lua_State* L) {
    bool status = DefReview_isSupported();
    lua_pushboolean(L, status);
    return 1;
}

static int requestReview(lua_State* L) {
    DefReview_requestReview();
    return 0;
}

static const luaL_reg Module_methods[] =
{
    {"isSupported", isSupported},
    {"requestReview", requestReview},
    {0, 0}
};

static void LuaInit(lua_State* L)
{
    int top = lua_gettop(L);
    luaL_register(L, MODULE_NAME, Module_methods);
    lua_pop(L, 1);
    assert(top == lua_gettop(L));
}

dmExtension::Result AppInitializeReview(dmExtension::AppParams* params)
{
    return dmExtension::RESULT_OK;
}

dmExtension::Result InitializeReview(dmExtension::Params* params)
{
    LuaInit(params->m_L);
    return dmExtension::RESULT_OK;
}

dmExtension::Result AppFinalizeReview(dmExtension::AppParams* params)
{
    return dmExtension::RESULT_OK;
}

dmExtension::Result FinalizeReview(dmExtension::Params* params)
{
    return dmExtension::RESULT_OK;
}

static dmExtension::Result UpdateReview(dmExtension::Params* params)
{
    return dmExtension::RESULT_OK;
}

#else // unsupported platforms

dmExtension::Result AppInitializeReview(dmExtension::AppParams* params)
{
    return dmExtension::RESULT_OK;
}

dmExtension::Result InitializeReview(dmExtension::Params* params)
{
    dmLogWarning("Registered %s (null) Extension\n", MODULE_NAME);
    return dmExtension::RESULT_OK;
}

dmExtension::Result AppFinalizeReview(dmExtension::AppParams* params)
{
    return dmExtension::RESULT_OK;
}

dmExtension::Result FinalizeReview(dmExtension::Params* params)
{
    return dmExtension::RESULT_OK;
}

static dmExtension::Result UpdateReview(dmExtension::Params* params)
{
    return dmExtension::RESULT_OK;
}
#endif


DM_DECLARE_EXTENSION(EXTENSION_NAME, LIB_NAME, AppInitializeReview, AppFinalizeReview, InitializeReview, UpdateReview, 0, FinalizeReview)
