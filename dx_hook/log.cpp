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

#include "log.h"

char logBuffer[LOGBUFFER_MAX];
std::ofstream *logFile = NULL;

int _Log(const char *Format, ...)
{
	if(g_debugoptions.debug_log == true)
	{
		va_list args;
		va_start(args, Format);

		_vsnprintf_s(logBuffer, LOGBUFFER_MAX, LOGBUFFER_MAX, Format, args);
		
		if(logFile == NULL)
		{
			logFile = new std::ofstream;
			// Append to the end of the file
			logFile->open(LOGFILE, std::ios::app);
			// Start a new file
			//logFile->open(LOGFILE, std::ios::trunc);
		}

		//*logFile << logBuffer << "\n";
		*logFile << GetTimeFormatted() << ": " <<logBuffer << "\n";		

		//Console::Print("%s\n", logBuffer);
	}

	return 0;
}

void LogClose(void)
{
	if(logFile != NULL) {
		logFile->close();
		delete logFile;
		logFile = NULL;
	}
}