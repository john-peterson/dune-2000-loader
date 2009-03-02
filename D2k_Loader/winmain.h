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

#ifndef _WINMAIN_H
#define _WINMAIN_H

///////////////////////////////////////////////////////////////////////////////////////
// Settings
// ŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻ




///////////////////////////////////////////////////////////////////////////////////////
// Settings
// ŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻ
// Use some custom debugging code
#define SETUP_DEBUGGING
///////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////
// Include
// ŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻ
#pragma warning(disable:4311) //type cast > size
#pragma warning(disable:4312) //type cast < size

#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>
#include <stdio.h>
#include <share.h>
#include <tchar.h>
#include <string>
#include <fstream>
#include <sstream>
#include "config.h"
#include "resource.h"
///////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////
// Declarations
// ŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻ
typedef std::basic_string<_TCHAR, std::char_traits<_TCHAR> > tstring;
typedef std::basic_ifstream<_TCHAR, std::char_traits<_TCHAR> > tifstream;
typedef std::basic_ofstream<_TCHAR, std::char_traits<_TCHAR> > tofstream;
typedef std::basic_stringstream<_TCHAR, std::char_traits<_TCHAR> > tstringstream;


extern _TCHAR g_szAppTitle[];
extern _TCHAR g_szClassName[];
extern HINSTANCE g_hInst;
extern HWND g_hwndMain, g_hwndInterface;
extern HBRUSH g_hbr;
extern DWORD g_dwWindowStyle;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK InterfaceProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK AboutProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
void LaunchGame(LPCSTR lpCmdLine);
///////////////////////////////////


#endif // _WINMAIN_H