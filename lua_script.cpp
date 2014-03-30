//
//  luascript.cpp
//  oes2
//
//  Created by fengjian on 13-12-7.
//
//

#include "lua_script.h"
using namespace std;
using namespace lua_tinker;


lua_manager::lua_manager()
{
	this->L = lua_open();
	luaL_openlibs(this->L);
	lua_tinker::init(this->L);
}

void lua_manager::do_file(const string& file)
{
	lua_tinker::dofile(this->L, file.c_str());
}

void lua_manager::do_string(const string& code)
{
	lua_tinker::dostring(this->L, code.c_str());
}


lua_manager::~lua_manager()
{
	lua_close(this->L);
}