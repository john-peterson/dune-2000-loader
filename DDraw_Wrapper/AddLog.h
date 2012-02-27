// (C) John Peterson, licensed under GNU GPL 3
#pragma once

#include <windows.h>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>

static void __cdecl AddLog( const char *sz, ... ) {
	const int LOGBUFFER_MAX = 256;
	va_list	va_alist;
	char logbuf[LOGBUFFER_MAX];
	va_start	( va_alist, sz );
	_vsnprintf_s(logbuf, LOGBUFFER_MAX, LOGBUFFER_MAX, sz, va_alist);
	va_end		( va_alist );
	//Console::Print("%s: %s\x0D\x0A", GetTimeFormatted().c_str(), logbuf);
	OutputDebugStringExA(logbuf);
}