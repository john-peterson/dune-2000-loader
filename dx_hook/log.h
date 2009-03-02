/*
Dune 2000 Launcher



This file is part of Dune 2000 Launcher.

Dune 2000 Launcher is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, version 3.

Dune 2000 Launcher is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Dune 2000 Launcher.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _LOG_H
#define _LOG_H

#include <windows.h>
#include <stdio.h>
#include <stdarg.h>
#include <fstream>
#include "HOOKS_BASE.h"

#include "../Common/Common.h"

#define LOGFILE "dllhook_log.txt"
#define LOGBUFFER_MAX 10240 //2048
extern char logBuffer[LOGBUFFER_MAX];

#ifdef _DEBUG
#define Log(fmt, ...) _Log(fmt, __VA_ARGS__);
#else
#define Log(fmt, ...)
#endif

int _Log(const char *Format, ...);
void LogClose(void);

#endif