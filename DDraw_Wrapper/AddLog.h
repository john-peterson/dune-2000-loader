#ifndef AddLog_H
#define AddLog_H

#include <windows.h>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>

#define LOG_FILE "ddraw_debug.txt"

static void __cdecl AddLog( const char *sz, ... )
{
	va_list	va_alist;
	FILE	*fp;

	struct tm * curtime;
    time_t current_time;

	char logbuf[256];

   	time( &current_time );
	curtime = localtime( &current_time );
    	
	sprintf( logbuf, "%02d:%02d:%02d ", curtime->tm_hour, curtime->tm_min, curtime->tm_sec );

	va_start	( va_alist, sz );
	_vsnprintf	( logbuf + strlen( logbuf ), sizeof( logbuf ) - strlen( logbuf ), sz, va_alist );
	va_end		( va_alist );

	Console::Print("%s\x0D\x0A", logbuf);
}

#endif