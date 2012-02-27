//This file is part of Dune 2000 Launcher, licensed under GNU GPL 3
#pragma once

// Use some custom debugging code
#define SETUP_DEBUGGING

#pragma warning(disable:4311) //type cast > size
#pragma warning(disable:4312) //type cast < size

#include <string>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>
#include <stdio.h>
#include <share.h>
#include <tchar.h>
#include "config.h"
#include "resource.h"
using namespace std;

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

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR lpCmdLine, int nCmdShow);
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK InterfaceProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK AboutProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
void LaunchGame(wstring SCmdLine);