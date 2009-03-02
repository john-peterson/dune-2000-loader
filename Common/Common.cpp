// Copyright (C) 2003-2008 Dolphin Project.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, version 2.0.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License 2.0 for more details.

// A copy of the GPL 2.0 should have been included with the program.
// If not, see http://www.gnu.org/licenses/

// Official SVN repository and contact information can be found at
// http://code.google.com/p/dolphin-emu/



///////////////////////////////////////////////////////////////////////////////////
// Includes
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯
#include <iostream> // System
#include <fstream>
#include <string>

#include <time.h>
#include <sys/timeb.h>

//#include <stdio.h>
#ifdef _WIN32
	#include <windows.h>
#endif
//#include <stdlib.h>

#include "Common.h"
//////////////////////////////////



namespace Console
{


///////////////////////////////////////////////////////////////////////////////////
// Settings
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯
// Option to compile without logging
#define LOGGING_ENABLED
#ifdef LOGGING_ENABLED

// On and off
bool g_consoleEnable = true;
bool gSaveFile = true;

// Settings
const int nFiles = 1;


// Create handles
FILE* __fStdOut[nFiles];
#ifdef _WIN32
	HANDLE __hStdOut = NULL;
#endif


// Warning, mind this maximum size value
static const int MAX_BYTES = 1024*8;
char LogBuffer[MAX_BYTES];
std::ofstream *LogFile = NULL;
#define LOGFILE "Console.txt"

#endif // LOGGING_ENABLED
///////////////////////////////////



// =======================================================================================
/* Start console window - width and height is the size of console window, if you specify
fname, the output will also be written to this file. TODO: Close the file pointer when the app
is closed */
// -------------
void Open(int width, int height, char* fname)
{
#ifdef LOGGING_ENABLED
#ifdef _WIN32

	AllocConsole();

	SetConsoleTitle(fname);
	__hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD co = {width,height};
	SetConsoleScreenBufferSize(__hStdOut, co);

	SMALL_RECT coo = {0,0,(width - 1),70}; // top, left, right, bottom
	SetConsoleWindowInfo(__hStdOut, TRUE, &coo);

	// Rsize the window to
	MoveWindow(Console::GetHwnd(), 200,0, width*8,70*14, true); // big wide window

	// ---------------------------------------------------------------------------------------
	// Open a file for writing
	// --------------------------
	if(fname)
	{
		/*
		for(int i = 0; i < nFiles; i++)
		{
			// Edit the log file name
			std::string FileEnding = ".log";
			std::string FileName = fname;
			char buffer[33]; _itoa(i, buffer, 10); // convert number to string
			std::string FullFilename = (FileName + buffer + FileEnding);
			//__fStdOut[i] = fopen(FullFilename.c_str(), "w");
			__fStdOut[i] = fopen(FullFilename.c_str(), "r+b");
		}*/
	}
	// --------------------------------------


#endif
#endif
}


// =======================================================================================
// Close and remove the file handles
// -------------------------
/*
void Close()
{

}
*/
// =======================================


// =======================================================================================
// Clear the file
// -------------------------
void DoClearFile(std::string Filename)
{
	if(LogFile)
	{
		// Close the current handle
		LogFile->close();
		delete LogFile;
	}

	LogFile = new std::ofstream;
	// Start a new file and write something to it
	LogFile->open(Filename.c_str(), std::ios::trunc);
	*LogFile << "";
	// Close it again
	LogFile->close();
	delete LogFile;
	LogFile = NULL;
}

void ClearFile()
{
	// Clear both files
	DoClearFile(LOGFILE);
	DoClearFile("dllhook_log.txt");

}
// =================================================


// =======================================================================================
// File printf function
// -------------------------
int PrintFile(int a, char *fmt, ...)
{
	if(gSaveFile)
	{
		char s[MAX_BYTES];
		va_list argptr;
		int cnt;

		va_start(argptr, fmt);
		cnt = vsnprintf(s, MAX_BYTES, fmt, argptr);
		va_end(argptr);

		if(__fStdOut[a]) // TODO: make this work, we have to set all default values to NULL
			//to make it work
			fprintf(__fStdOut[a], s);

		return(cnt);
	}
	else
	{
		return 0;
	}
}



// =======================================================================================
// Printf to screen function
// ------------
int Print(const char *fmt, ...)
{
#ifdef LOGGING_ENABLED
	// Warning, mind this value
	static const int MAX_BYTES = 1024*8;

#ifdef _WIN32
	char s[MAX_BYTES];
	va_list argptr;
	int cnt;

	va_start(argptr, fmt);
	cnt = vsnprintf(s, MAX_BYTES, fmt, argptr);
	va_end(argptr);

	DWORD cCharsWritten;

	if(__hStdOut)
		WriteConsole(__hStdOut, s, strlen(s), &cCharsWritten, NULL);

	// ------------------------------------------------
	// Write to a file
	// ------------
	/*
	if(__fStdOut[0])
	{
		fprintf(__fStdOut[0], s);
		fflush(__fStdOut[0]);
	}
	*/
	if(LogFile == NULL)
	{
		LogFile = new std::ofstream;
		// Append to the end of the file
		LogFile->open(LOGFILE, std::ios::app);
		// Start a new file
		//LogFile->open(LOGFILE, std::ios::trunc);
	}

	//*LogFile << s << "\n";
	//*LogFile << GetTimeFormatted() << ": " << s << "\n";
	*LogFile << GetTimeFormatted() << ": " << s;
	
	LogFile->flush();
	// -----------------------

	return(cnt);
#else
	return 0;
#endif // _WIN32
#endif // LOGGING_ENABLED
}


// =======================================================================================
// Clear console screen
// --------------
void ClearScreen() 
{ 
#if defined(_WIN32)
	if(g_consoleEnable)
	{
		COORD coordScreen = { 0, 0 }; 
		DWORD cCharsWritten; 
		CONSOLE_SCREEN_BUFFER_INFO csbi; 
		DWORD dwConSize; 

		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
	    
		GetConsoleScreenBufferInfo(hConsole, &csbi); 
		dwConSize = csbi.dwSize.X * csbi.dwSize.Y; 
		FillConsoleOutputCharacter(hConsole, TEXT(' '), dwConSize, 
			coordScreen, &cCharsWritten); 
		GetConsoleScreenBufferInfo(hConsole, &csbi); 
		FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, 
			coordScreen, &cCharsWritten); 
		SetConsoleCursorPosition(hConsole, coordScreen); 
	}
#endif
}
// =================================


// =======================================================================================
// Get window handle of console window to be able to resize it
// ---------------------
#if defined(_WIN32)
HWND GetHwnd(void)
{

   #define MY_BUFSIZE 1024 // Buffer size for console window titles.
   HWND hwndFound;         // This is what is returned to the caller.
   char pszNewWindowTitle[MY_BUFSIZE]; // Contains fabricated
                                       // WindowTitle.
   char pszOldWindowTitle[MY_BUFSIZE]; // Contains original
                                       // WindowTitle.

   // Fetch current window title.

   GetConsoleTitle(pszOldWindowTitle, MY_BUFSIZE);

   // Format a "unique" NewWindowTitle.

   wsprintf(pszNewWindowTitle,"%d/%d",
               GetTickCount(),
               GetCurrentProcessId());

   // Change current window title.

   SetConsoleTitle(pszNewWindowTitle);

   // Ensure window title has been updated.

   Sleep(40);

   // Look for NewWindowTitle.

   hwndFound = FindWindow(NULL, pszNewWindowTitle);

   // Restore original window title.

   SetConsoleTitle(pszOldWindowTitle);

   return(hwndFound);
}
#endif // _WIN32


} // Console
// =================================



// ===================================================================================
// For Debugging. Read out an u8 array.
// ----------------
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
// ================


// ===================================================================================
// 
// ---------------------
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
		// ARGH! vsnprintf does no longer return -1 on truncation in newer libc!
		// WORKAROUND! let's fake the old behaviour (even though it's less efficient).
		// TODO: figure out why the fix causes an invalid read in strlen called from vsnprintf :(
//		if (writtenCount >= (int)newSize)
//			writtenCount = -1;
		newSize *= 2;
	}

	buf[writtenCount] = '\0';
	std::string temp = buf;
	return temp;
}




///////////////////////////////////////////////////////////////////////////
// Message box
// ¯¯¯¯¯¯¯¯¯
bool CharArrayFromFormatV(char* out, int outsize, const char* format, va_list args)
{
	int writtenCount = vsnprintf(out, outsize, format, args);

	if (writtenCount > 0 && writtenCount < outsize)
	{
		out[writtenCount] = '\0';
		return true;
	}
	else
	{
		out[outsize - 1] = '\0';
		return false;
	}
}

bool MsgBox(const char* format, ...)
{
	// ---------------------------------
	// Read message and write it to the log
	// -----------
    char buffer[2048];
    va_list args;
    bool ret = false;

    va_start(args, format);
    CharArrayFromFormatV(buffer, 2048, format, args);

	va_end(args);
	// -----------	

	return (IDYES == MessageBox(0, buffer, "Information", MB_ICONQUESTION));
}
////////////////////////////////



///////////////////////////////////////////////////////////////////////////
// Time
// ¯¯¯¯¯¯¯¯¯

// Return the current time formatted as Minutes:Seconds:Milliseconds in the form 00:00:000
// tp.time: Seconds since 1970
std::string GetTimeFormatted()
{
	struct timeb tp;
	(void)::ftime(&tp);
	char temp[32];

	time_t ltime;   
	struct tm * Tm;   

	ltime = time(NULL);   
	Tm = localtime(&ltime);

	//sprintf(temp, "%02i:%02i:%03i", (tp.time / 60) % 60, (int)(tp.time % 60), tp.millitm);
	sprintf(temp, "%02i:%02i:%02i:%03i", Tm->tm_hour, Tm->tm_min, Tm->tm_sec, tp.millitm);

	return std::string(temp);
}
////////////////////////////////