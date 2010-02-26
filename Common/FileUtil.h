#ifndef _FILE_UTIL_H
#define _FILE_UTIL_H

#include <iostream> // System
#include <string>
#include <windows.h>

namespace File
{

// Directory seperators
#define DIR_SEP "/"
#define DIR_SEP_CHR '/'

// Returns true if file filename exists
bool Exists(std::string filename);

}

#endif // _FILE_UTIL_H