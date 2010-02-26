///////////////////////////////////////////////////////////////////////////////////
// Includes
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
#include <iostream> // System
#include <string>

//#include <stdio.h>
#include <windows.h>
//#include <stdlib.h>

#include "Common.h"
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
// Common string functions
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
// Printf to string
std::string StringFromFormat(const char* format, ...)
{
	int writtenCount = -1;
	int newSize = (int)strlen(format) + 4;
	char *buf = 0;
	va_list args;
	while (writtenCount < 0)
	{
		delete [] buf;
		buf = new char[newSize + 1];
	
	    va_start(args, format);
		writtenCount = vsnprintf(buf, newSize, format, args);
		va_end(args);
		if (writtenCount >= (int)newSize) {
			writtenCount = -1;
		}
		newSize *= 2;
	}

	buf[writtenCount] = '\0';
	std::string temp = buf;
	return temp;
}

// Read out an u8 array to a string
std::string ArrayToString(const u8 *data, u32 size, u32 offset, int line_len, bool Spaces)
{
	std::string Tmp, Spc;
	if (Spaces) Spc = " "; else Spc = "";
	for (u32 i = 0; i < size; i++)
	{
		Tmp += StringFromFormat("%02x%s", data[i + offset], Spc.c_str());
		if(i > 1 && (i + 1) % line_len == 0) Tmp.append("\n"); // break long lines
	}	
	return Tmp;
}
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
// File system related string functions
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

// Get path from full path
std::string GetPath(const std::string full_path)
{
	char drive[_MAX_DRIVE];
	char dir[_MAX_DIR];
	char fname[_MAX_FNAME];
	char ext[_MAX_EXT];

	if (_splitpath_s(full_path.c_str(), drive, _MAX_DRIVE, dir, _MAX_DIR, fname, _MAX_FNAME, ext, _MAX_EXT) == 0)
	{
		return std::string(drive) + std::string(dir);
	}

	return "";
}
///////////////////////////////////////////////////////////////////////////////////