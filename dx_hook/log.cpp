//This file is part of Dune 2000 Launcher, licensed under GNU GPL 3

#include "log.h"

char logBuffer[LOGBUFFER_MAX];
std::ofstream *logFile = NULL;

int _Log(const char *Format, ...) {
	if(g_debugoptions.debug_log == true) {
		va_list args;
		va_start(args, Format);
		_vsnprintf_s(logBuffer, LOGBUFFER_MAX, LOGBUFFER_MAX, Format, args);
		
		if(logFile == NULL) {
			logFile = new std::ofstream;
			// Append to the end of the file
			logFile->open(LOGFILE, std::ios::app);
			// Start a new file
			//logFile->open(LOGFILE, std::ios::trunc);
		}

		//*logFile << logBuffer << "\n";
		//*logFile << GetTimeFormatted() << ": " <<logBuffer << "\n";
		//Console::Print("%s\n", logBuffer);
		OutputDebugStringExA(logBuffer);		
	}
	return 0;
}

void LogClose(void) {
	if(logFile != NULL) {
		logFile->close();
		delete logFile;
		logFile = NULL;
	}
}