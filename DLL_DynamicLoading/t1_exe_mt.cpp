// t1_exe_mt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "../t1_dll_mt_depenency/t1_dll_mt_depenency.h"
#include "../t1_dll_mt_depends/t1_dll_mt_depends.h"

#include <string>
#include <Windows.h>

int main()
{
	std::cout << get_secret_word() << std::endl;
	std::string word = "mmbop";
	std::cout << word << std::endl;
	std::cout << get_three_words() << std::endl;

	int(__cdecl * say_hello)(void) = NULL;
	int(__cdecl * add)(int numArgs, ...) = NULL;
	void(__cdecl * print_num)(int n) = NULL;

	auto hLibDll = LoadLibrary(L".\\lib.dll"); 
	(FARPROC&)say_hello = GetProcAddress(hLibDll, "say_hello");
	(FARPROC&)add = GetProcAddress(hLibDll, "add");
	(FARPROC&)print_num = GetProcAddress(hLibDll, "print_num");
	print_num(add(7, 1, 20, 300, 4000, 50000, 600000, 7000000));
	print_num(add(7, 1, 20, 300, 4000, 50000, 600000, 7000000));
	if (!FreeLibrary(hLibDll)) return -6;

	hLibDll = LoadLibrary(L".\\lib.dll");
	(FARPROC&)say_hello = GetProcAddress(hLibDll, "say_hello");
	(FARPROC&)add = GetProcAddress(hLibDll, "add");
	(FARPROC&)print_num = GetProcAddress(hLibDll, "print_num");
	print_num(add(7, 1, 20, 300, 4000, 50000, 600000, 7000000));
	print_num(add(7, 1, 20, 300, 4000, 50000, 600000, 7000000));
	if (!FreeLibrary(hLibDll)) return -6;


	const char*(__cdecl * get_secret_word2)(void) = NULL;

	auto hDll = LoadLibrary(L".\\t1_dll_mt_depenency.dll");
	if (!hDll) { printf("no\n"); return -7; }
	(FARPROC&)get_secret_word2 = GetProcAddress(hDll, "get_secret_word");
	if (!get_secret_word2) return -8;
	std::cout << get_secret_word2() << std::endl;
	std::cout << get_secret_word2() << std::endl;
	if (!FreeLibrary(hDll)) return -9;

	hDll = LoadLibrary(L".\\t1_dll_mt_depenency.dll");
	if (!hDll) { printf("no\n"); return -7; }
	(FARPROC&)get_secret_word2 = GetProcAddress(hDll, "get_secret_word");
	if (!get_secret_word2) return -8;
	std::cout << get_secret_word2() << std::endl;
	std::cout << get_secret_word2() << std::endl;
	if (!FreeLibrary(hDll)) return -9;

	return 0;
}

