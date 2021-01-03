/*
** $Id: linit.c $
** Initialization of libraries for lua.c and other clients
** See Copyright Notice in lua.h
*/


#define linit_c
#define LUA_LIB

/*
** If you embed Lua in your program and need to open the standard
** libraries, call luaL_openlibs in your program. If you need a
** different set of libraries, copy this file to your project and edit
** it to suit your needs.
**
** You can also *preload* libraries, so that a later 'require' can
** open the library, which is already linked to the application.
** For that, do the following code:
**
**  luaL_getsubtable(L, LUA_REGISTRYINDEX, LUA_PRELOAD_TABLE);
**  lua_pushcfunction(L, luaopen_modname);
**  lua_setfield(L, -2, modname);
**  lua_pop(L, 1);  // remove PRELOAD table
*/

#include "lprefix.h"


#include <stddef.h>

#include "lua.h"

#include "lualib.h"
#include "lauxlib.h"


/*
** these libs are loaded by lua.c and are readily available to any Lua
** program
*/
static const luaL_Reg loadedlibs[] = {
#if CONFIG_LUA_BASELIB
  {LUA_GNAME, luaopen_base},
#endif
#if CONFIG_LUA_LOADLIB
  {LUA_LOADLIBNAME, luaopen_package},
#endif
#if CONFIG_LUA_COLIB
  {LUA_COLIBNAME, luaopen_coroutine},
#endif
#if CONFIG_LUA_TABLIB
  {LUA_TABLIBNAME, luaopen_table},
#endif
#if CONFIG_LUA_IOLIB
  {LUA_IOLIBNAME, luaopen_io},
#endif
#if CONFIG_LUA_OSLIB
  {LUA_OSLIBNAME, luaopen_os},
#endif
#if CONFIG_LUA_STRLIB
  {LUA_STRLIBNAME, luaopen_string},
#endif
#if CONFIG_LUA_MATHLIB
  {LUA_MATHLIBNAME, luaopen_math},
#endif
#if CONFIG_LUA_UTF8LIB
  {LUA_UTF8LIBNAME, luaopen_utf8},
#endif
#if CONFIG_LUA_DBLIB
  {LUA_DBLIBNAME, luaopen_debug},
#endif
  {NULL, NULL}
};


LUALIB_API void luaL_openlibs (lua_State *L) {
  const luaL_Reg *lib;
  /* "require" functions from 'loadedlibs' and set results to global table */
  for (lib = loadedlibs; lib->func; lib++) {
    luaL_requiref(L, lib->name, lib->func, 1);
    lua_pop(L, 1);  /* remove lib */
  }
}

