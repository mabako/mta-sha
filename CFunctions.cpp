/*********************************************************
*
*  Multi Theft Auto: San Andreas - Deathmatch
*
*  ml_base, External lua add-on module
*
*  Copyright © 2003-2008 MTA.  All Rights Reserved.
*
*  Grand Theft Auto is © 2002-2003 Rockstar North
*
*  THE FOLLOWING SOURCES ARE PART OF THE MULTI THEFT
*  AUTO SOFTWARE DEVELOPMENT KIT AND ARE RELEASED AS
*  OPEN SOURCE FILES. THESE FILES MAY BE USED AS LONG
*  AS THE DEVELOPER AGREES TO THE LICENSE THAT IS
*  PROVIDED WITH THIS PACKAGE.
*
*********************************************************/

#include "CFunctions.h"
#include "extra/CLuaArguments.h"
#include "sha/sha1.h"
#include "sha/sha2.h"

#define fn(a,b,c) \
int CFunctions::b( lua_State* luaVM ) \
{ \
    if( luaVM ) \
    { \
        CLuaArguments args; \
		if( lua_type ( luaVM, 1 ) == LUA_TSTRING || lua_type ( luaVM, 1 ) == LUA_TNUMBER ) \
		{ \
			unsigned char hval[ c ]; \
			a( hval, (unsigned const char*) lua_tostring( luaVM, 1 ), lua_objlen( luaVM, 1 ) ); \
			\
			char pBuffer[ c*2+1 ]; \
			for( unsigned int i = 0; i < c; ++ i ) \
				sprintf ( pBuffer+i*2, "%02x", hval[i] ); \
			args.PushString( pBuffer ); \
		} \
		else \
		{ \
			luaL_error( luaVM, "Bad argument @ '" #a "'" ); \
			args.PushBoolean( false ); \
		} \
        args.PushArguments( luaVM ); \
        return 1; \
    } \
    return 0; \
}

fn(sha1,f_sha1,SHA1_DIGEST_SIZE);
fn(sha224,f_sha224,SHA224_DIGEST_SIZE);
fn(sha256,f_sha256,SHA256_DIGEST_SIZE);
#ifdef WIN32
fn(sha384,f_sha384,SHA384_DIGEST_SIZE);
fn(sha512,f_sha512,SHA512_DIGEST_SIZE);
#endif

#undef fn
