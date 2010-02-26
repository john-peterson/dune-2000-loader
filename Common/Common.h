///////////////////////////////////////////////////////////////////////////////////
// Copyright Information
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, version 2.0.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License 2.0 for more details.

// A copy of the GPL 2.0 should have been included with the program.
// If not, see http://www.gnu.org/licenses/
///////////////////////////////////////////////////////////////////////////////////

#ifndef _CONSOLE_H
#define _CONSOLE_H

#include <iostream> // System
#include <string>
//#include <stdlib.h>
//#include <stdio.h>
#include <windows.h>


typedef unsigned __int8 u8;
typedef unsigned __int16 u16;
typedef unsigned __int32 u32;
typedef unsigned __int64 u64;

typedef signed __int8 s8;
typedef signed __int16 s16;
typedef signed __int32 s32;
typedef signed __int64 s64;


namespace Console
{

void Open(int width = 80, int height = 60, char* fname = "Console");
int Print(const char *fmt, ...);
int PrintFile(int a, const char *fmt, ...);
void ClearFile();
void ClearScreen();

#ifdef _WIN32
	HWND GetHwnd(void);
#endif

}

std::string ArrayToString(const u8 *data, u32 size, u32 offset = 0, int line_len = 20, bool Space = true);
bool MsgBox(const char* format, ...);
std::string GetTimeFormatted();
std::string DoGetCurrentDirectory();
std::string ShowError();

#endif // _CONSOLE_H