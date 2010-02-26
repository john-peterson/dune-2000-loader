///////////////////////////////////////////////////////////////////////////////////
// Includes
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
#include <iostream> // System
#include <string>

//#include <stdio.h>
#include <windows.h>
//#include <stdlib.h>

#include "Common.h"
#include "FileUtil.h"
///////////////////////////////////////////////////////////////////////////////////

namespace File
{

///////////////////////////////////////////////////////////////////////////////////
// Common file functions
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

// Remove any ending forward slashes from directory paths
inline char *StripTailDirSlashes(char *fname)
{
	int len = (int)strlen(fname);
	int i = len - 1;
	if (len > 1)
		while (fname[i] == DIR_SEP_CHR)
			fname[i--] = '\0';
	return fname;
}

// Returns true if file filename exists
bool Exists(std::string filename)
{
    DWORD       fileAttr;

    fileAttr = GetFileAttributes(filename.c_str());
    if (0xFFFFFFFF == fileAttr)
        return false;
    return true;

}

///////////////////////////////////////////////////////////////////////////////////

} // namespace