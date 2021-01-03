if(CONFIG_LUA)
set(ZEPHYR_CURRENT_LIBRARY lua)
zephyr_library()
add_definitions("-DLUA_USE_C89")
zephyr_include_directories(./src)
zephyr_library_sources(
	./src/lapi.c
	./src/lauxlib.c
	./src/lcode.c
	./src/lctype.c
	./src/ldebug.c
	./src/ldo.c
	./src/ldump.c
	./src/lfunc.c
	./src/lgc.c
	./src/linit.c
	./src/llex.c
	./src/lmem.c
	./src/lobject.c
	./src/lopcodes.c
	./src/lparser.c
	./src/lstate.c
	./src/lstring.c
	./src/ltable.c
	./src/ltm.c
	./src/lundump.c
	./src/lvm.c
	./src/lzio.c
	)

zephyr_library_sources_ifdef(CONFIG_LUA_MATHLIB	./src/lmathlib.c)
zephyr_library_sources_ifdef(CONFIG_LUA_IOLIB	./src/liolib.c)
zephyr_library_sources_ifdef(CONFIG_LUA_OSLIB	./src/loslib.c)
zephyr_library_sources_ifdef(CONFIG_LUA_UTF8LIB	./src/lutf8lib.c)
zephyr_library_sources_ifdef(CONFIG_LUA_TABLIB	./src/ltablib.c)
zephyr_library_sources_ifdef(CONFIG_LUA_BASELIB	./src/lbaselib.c)
zephyr_library_sources_ifdef(CONFIG_LUA_STRLIB 	./src/lstrlib.c)
zephyr_library_sources_ifdef(CONFIG_LUA_COLIB 	./src/lcorolib.c)
zephyr_library_sources_ifdef(CONFIG_LUA_DBLIB 	./src/ldblib.c)
zephyr_library_sources_ifdef(CONFIG_LUA_LOADLIB	./src/loadlib.c)

endif()
