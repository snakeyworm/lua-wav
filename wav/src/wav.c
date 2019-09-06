// Caleb Loera John 3:16
// PlaySound Lua binding

#include "lua.h"
#include "lauxlib.h"
#include <windows.h>

#define BIND_SND_MACRO( name, value ) \
	lua_pushinteger( L, value ); \
	lua_setfield( L, -2, name )

int wav_play_sound( lua_State *L ) {

	const char *path = luaL_checkstring( L, 1 );
	int flags = 0;

	if ( lua_isnumber( L, 2 ) )
		flags = lua_tointeger( L, 2 );

	luaL_argcheck( L, ( flags & SND_RESOURCE ) != SND_RESOURCE, 2,
			"SND_RESOURCE flag is not supported" );

	lua_pushboolean( L, PlaySound( path, 0, flags ) );

	return 1;

}

// @formatter:off
luaL_Reg wav_lib[] = {
	{ "play", wav_play_sound, },
	{ NULL, NULL, },
};
// @formatter:on

int luaopen_wav( lua_State *L ) {

	// Test BRANCH 2

	luaL_newlibtable( L, wav_lib );

	BIND_SND_MACRO( "SND_APPLICATION", SND_APPLICATION );
	BIND_SND_MACRO( "SND_ALIAS", SND_ALIAS );
	BIND_SND_MACRO( "SND_ALIAS_ID", SND_ALIAS_ID );
	BIND_SND_MACRO( "SND_ASYNC", SND_ASYNC );
	BIND_SND_MACRO( "SND_FILENAME", SND_FILENAME );
	BIND_SND_MACRO( "SND_LOOP", SND_LOOP );
	BIND_SND_MACRO( "SND_MEMORY", SND_MEMORY );
	BIND_SND_MACRO( "SND_NODEFAULT", SND_NODEFAULT );
	BIND_SND_MACRO( "SND_NOSTOP", SND_NOSTOP );
	BIND_SND_MACRO( "SND_NOWAIT", SND_NOWAIT );
	BIND_SND_MACRO( "SND_RESOURCE", SND_RESOURCE );
	BIND_SND_MACRO( "SND_SYNC", SND_SYNC );

	luaL_setfuncs( L, wav_lib, 0 );

	return 1;

}
