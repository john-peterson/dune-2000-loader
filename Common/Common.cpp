// Common functions
// (C) John Peterson, licensed under GNU GPL 3

#include "Common.h"
using namespace std;

// Retrieve the system error message for the last-error code
string ShowError() {
	LPVOID lpMsgBuf;
	LPVOID lpDisplayBuf;
	DWORD dw = GetLastError();
	FormatMessageA(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		dw,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPSTR)&lpMsgBuf,
		0,
		NULL);
	
	return std::string((LPCSTR)lpMsgBuf);
}

void OutputDebugStringEx(const wchar_t* format, ...) {
	wchar_t buffer[1024*8];
	va_list argptr;
	va_start(argptr, format);
	_vsnwprintf(buffer, 1024*8, format, argptr);
	va_end(argptr);
	OutputDebugString(buffer);
	//wcsncat(buffer, L"\n", 1);
	//wprintf(buffer);
}

wstring Format(const wchar_t *fmt, ...) {
	if (!GetConsoleWindow()) {
		AllocConsole();
		int iWidth = 120, iHeight = 50;
		COORD Co = {iWidth, 1000};
		bool SB = SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), Co);
		MoveWindow(GetConsoleWindow(), 0,0, 3000*8,iHeight*14, true);
	}
	static int i = 0; i++;
	static const int MAX_BYTES = 1024*8;
	wchar_t s[MAX_BYTES];
	va_list argptr;
	int cnt;
	va_start(argptr, fmt);
	cnt = _vsnwprintf(s, MAX_BYTES, fmt, argptr);
	wcscat(s, L"\n");
	va_end(argptr);
	return wstring(s);
}

// Read u8 array to string
string ArrayToString(const u8 *data, u32 size, u32 offset, int line_len, bool spaces) {
	string Tmp, Spc;
	if (spaces) Spc = " "; else Spc = "";
	for (u32 i = 0; i < size; i++) {
		Tmp += FormatA("%02x%s", data[i + offset], Spc.c_str());
		if(i > 1 && (i + 1) % line_len == 0) Tmp.append("\n"); // break long lines
	}	
	return Tmp;
}

// Remove any ending forward slashes from directory paths
inline char *StripTailDirSlashes(char *fname) {
	int len = (int)strlen(fname);
	int i = len - 1;
	if (len > 1)
		while (fname[i] == DIR_SEP_CHR)
			fname[i--] = '\0';
	return fname;
}

// Returns true if file filename exists
bool FileExist(wstring filename) {
    if (GetFileAttributes(filename.c_str()) == 0xFFFFFFFF) return false;
    return true;
}

// Get path from full path
wstring GetPath(const wstring full_path) {
	wchar_t drive[_MAX_DRIVE];
	wchar_t dir[_MAX_DIR];
	wchar_t fname[_MAX_FNAME];
	wchar_t ext[_MAX_EXT];
	if (_wsplitpath_s(full_path.c_str(), drive, _MAX_DRIVE, dir, _MAX_DIR, fname, _MAX_FNAME, ext, _MAX_EXT) == 0)
		return wstring(drive) + wstring(dir);
	return L"";
}

wstring GetCurrentDirectoryEx() {
	TCHAR currdirPath[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, currdirPath);
	return wstring(currdirPath);
}

// Open a file for writing
//void Open(int width, int height, char* fname) {
//	if (fname)
//	{
//		/*
//		for(int i = 0; i < nFiles; i++)
//		{
//			// Edit the log file name
//			std::string FileEnding = ".log";
//			std::string FileName = fname;
//			char buffer[33]; _itoa(i, buffer, 10); // convert number to string
//			std::string FullFilename = (FileName + buffer + FileEnding);
//			//__fStdOut[i] = fopen(FullFilename.c_str(), "w");
//			__fStdOut[i] = fopen(FullFilename.c_str(), "r+b");
//		}*/
//	}
//}

// Close and remove the file handles
//void Close()
//{
//
//}

// Clear the file
//void DoClearFile(std::string Filename)
//{
//	if(LogFile)
//	{
//		// Close the current handle
//		LogFile->close();
//		delete LogFile;
//	}
//
//	LogFile = new std::ofstream;
//	// Start a new file and write something to it
//	LogFile->open(Filename.c_str(), std::ios::trunc);
//	*LogFile << "";
//	// Close it again
//	LogFile->close();
//	delete LogFile;
//	LogFile = NULL;
//}
//
//void ClearFile()
//{
//	// Clear both files
//	DoClearFile(LOGFILE);
//	//DoClearFile("dllhook_log.txt");
//}


// File printf function
//int PrintFile(int a, char *fmt, ...)
//{
//	if(gSaveFile)
//	{
//		char s[MAX_BYTES];
//		va_list argptr;
//		int cnt;
//
//		va_start(argptr, fmt);
//		cnt = vsnprintf(s, MAX_BYTES, fmt, argptr);
//		va_end(argptr);
//
//		if(__fStdOut[a]) // TODO: make this work, we have to set all default values to NULL
//			//to make it work
//			fprintf(__fStdOut[a], s);
//
//		return(cnt);
//	}
//	else
//	{
//		return 0;
//	}
//}

// Print to screen
//int Print(const char *fmt, ...)
//{
//	// Warning, mind this value
//	static const int MAX_BYTES = 1024*8;
//
//	char s[MAX_BYTES];
//	va_list argptr;
//	int cnt;
//
//	va_start(argptr, fmt);
//	cnt = vsnprintf(s, MAX_BYTES, fmt, argptr);
//	va_end(argptr);
//
//	DWORD cCharsWritten;
//
//	if(__hStdOut)
//		WriteConsole(__hStdOut, s, strlen(s), &cCharsWritten, NULL);
//
//	// Write to a file
//	/*
//	if(__fStdOut[0])
//	{
//		fprintf(__fStdOut[0], s);
//		fflush(__fStdOut[0]);
//	}
//	*/
//	if(LogFile == NULL)
//	{
//		LogFile = new std::ofstream;
//		// Append to the end of the file
//		LogFile->open(LOGFILE, std::ios::app);
//		// Start a new file
//		//LogFile->open(LOGFILE, std::ios::trunc);
//	}
//
//	*LogFile << s;
//	//*LogFile << GetTimeFormatted() << ": " << s << "\n";
//	//*LogFile << GetTimeFormatted() << ": " << s;
//	
//	LogFile->flush();
//	return(cnt);
//}

// Message box
bool CharArrayFromFormatV(char* out, int outsize, const char* format, va_list args) {
	int writtenCount = vsnprintf(out, outsize, format, args);
	if (writtenCount > 0 && writtenCount < outsize) {
		out[writtenCount] = '\0';
		return true;
	} else {
		out[outsize - 1] = '\0';
		return false;
	}
}
bool MsgBox(const char* format, ...) {
    char buffer[2048];
    va_list args;
    bool ret = false;
    va_start(args, format);
    CharArrayFromFormatV(buffer, 2048, format, args);
	va_end(args);
	return (IDYES == MessageBoxA(0, buffer, "Information", MB_ICONQUESTION));
}

// Time
//std::string GetTimeFormatted() {
//	struct timeb tp;
//	(void)::ftime(&tp);
//	char temp[32];
//
//	time_t ltime;   
//	struct tm * Tm;   
//
//	ltime = time(NULL);   
//	Tm = localtime(&ltime);
//
//	//sprintf(temp, "%02i:%02i:%03i", (tp.time / 60) % 60, (int)(tp.time % 60), tp.millitm);
//	sprintf(temp, "%02i:%02i:%02i:%03i", Tm->tm_hour, Tm->tm_min, Tm->tm_sec, tp.millitm);
//
//	return std::string(temp);
//}

// non-unicode
void OutputDebugStringExA(const char* format, ...) {
	char buffer[1024*8];
	va_list argptr;
	va_start(argptr, format);
	vsnprintf(buffer, 1024*8, format, argptr);
	va_end(argptr);
	OutputDebugStringA(buffer);
	//wcsncat(buffer, L"\n", 1);
	//wprintf(buffer);
}

string FormatA(const char *format, ...) {
	char buffer[1024*8];
	va_list argptr;
	va_start(argptr, format);
	vsnprintf(buffer, 1024*8, format, argptr);
	strcat(buffer, "\n");
	va_end(argptr);
	return string(buffer);
}

string GetCurrentDirectoryExA() {
	CHAR currdirPath[MAX_PATH];
	GetCurrentDirectoryA(MAX_PATH, currdirPath);
	return string(currdirPath);
}

string GetPathA(const string full_path) {
	char drive[_MAX_DRIVE];
	char dir[_MAX_DIR];
	char fname[_MAX_FNAME];
	char ext[_MAX_EXT];

	if (_splitpath_s(full_path.c_str(), drive, _MAX_DRIVE, dir, _MAX_DIR, fname, _MAX_FNAME, ext, _MAX_EXT) == 0) {
		return string(drive) + string(dir);
	}
	return "";
}