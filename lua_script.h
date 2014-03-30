//
//  luascript.h
//  oes2
//
//  Created by fengjian on 13-12-7.
//
//

#ifndef __LUASCRIPT_H__
#define __LUASCRIPT_H__

#include <iostream>
#include <string>

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include "lua_tinker.h"



class lua_manager {
	
	lua_State *L;
	
public:
	
	void do_string(const std::string& code);
	
	void do_file(const std::string& file);
	
	template<typename RV, typename... ARGS>
	RV call(const std::string& name, ARGS... args)
	{
		return lua_tinker::call<RV>(this->L, name.c_str(), args...);
	}
	
	template<typename F>
	void def(const std::string& name, F func)
	{
		lua_tinker::def(this->L, name.c_str(), func);
	}
	
	template<typename T>
	T get(const std::string& name)
	{
		return lua_tinker::get<T>(this->L, name.c_str());
	}
	
	
	template<typename T>
	void set(const std::string& name, T object)
	{
		lua_tinker::set(this->L, name.c_str(), object);
	}
	
	template<typename T>
	void type2lua(T val)
	{
		lua_tinker::type2lua(this->L, val);
	}
	
	
	template<typename CLASS>
	void class_add(const std::string& name)
	{
		lua_tinker::class_add<CLASS>(this->L, name.c_str());
	}
	
	template<typename CLASS, typename P>
	void class_inh()
	{
		lua_tinker::class_inh<CLASS, P>(this->L);
	}
	
	template<typename CLASS, typename... ARGS>
	void class_con()
	{
		auto f = lua_tinker::constructor<CLASS, ARGS...>;
		lua_tinker::class_con<CLASS>(this->L, f);
	}
	
	template<typename CLASS, typename F>
	void class_def(const std::string& name, F func)
	{
		lua_tinker::class_def<CLASS>(this->L, name.c_str(), func);
	}
	

	
	
	template<typename CLASS, typename BASE, typename VAR>
	void class_mem(const std::string& name, VAR BASE::*val)
	{
		lua_tinker::class_mem<CLASS>(this->L, name.c_str(), val);
	}
	
	lua_manager();
	~lua_manager();
};


#endif 
