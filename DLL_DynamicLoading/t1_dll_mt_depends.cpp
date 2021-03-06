// t1_dll_mt_depends.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "t1_dll_mt_depends.h"
#include "../t1_dll_mt_depenency/t1_dll_mt_depenency.h"

#include <string>


DLLFUNC1 const char* get_three_words()
{
	//std::string w = get_secret_word();
	auto w = []()-> std::string {return get_secret_word(); };
	static std::string out =  w() + " " + w() + " " + w();
	return out.c_str();
}