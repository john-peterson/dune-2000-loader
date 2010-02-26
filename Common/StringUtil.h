#ifndef _STRINGUTIL_H
#define _STRINGUTIL_H

#include <iostream> // System
#include <string>
#include <windows.h>

std::string StringFromFormat(const char* format, ...);
bool CharArrayFromFormatV(char* out, int outsize, const char* format, va_list args);
std::string GetPath(const std::string full_path);

#endif // _STRINGUTIL_H