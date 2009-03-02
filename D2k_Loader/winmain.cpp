//////////////////////////////////////////////////////////////////////////////////////////////////////
/* Copyright Information
// ���������������������

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

////////////////////////////////////////////////////////////////////////////////////////////////////*/


//////////////////////////////////////////////////////////////////////////////////////////////////////
/* Project description
// ���������������������

The purpose of this project is to increase the output resolution of Dune 2000 (1998) so that it can be
displayed properly on current flat screens that has problems with both the 640x400 and 640x480 resolution
that the game produce. In the current form the code is in most parts a copy of a FF8 Launcher by Tobias
Sebring (aka Magix). The goal is to modify this code so that it works with Dune 2000.

////////////////////////////////////////////////////////////////////////////////////////////////////*/


//////////////////////////////////////////////////////////////////////////////////////////////////////
/* Current issues
// ���������������������

The call to ddraw.dll is not picked up. Can it be because the exe loads the main part of the code from
DUNE2000.DAT, and that only calls directly from DUNE2000.EXE are picked up?

////////////////////////////////////////////////////////////////////////////////////////////////////*/


//////////////////////////////////////////////////////////////////////////////////////////////////////
// Includes
// ���������������������
#include "winmain.h"
#include "../Common/Common.h"
/////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
// Declarations and definitions
// ���������������������
_TCHAR g_szAppTitle[] = _T("Dune 2000 Loader v0.1");
_TCHAR g_szClassName[] = _T("D2kLoader");
HINSTANCE g_hInst = NULL;
HWND g_hwndMain = NULL, g_hwndInterface = NULL;
HMENU g_hMenuMain = NULL;
HBRUSH g_hbr = NULL;
DWORD g_dwWindowStyle = 0;
LPSTR g_lpCmdLine = NULL;

#define _NL _T("\r\n")
/////////////////////////////////////////////


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int iCmdShow)
{
	Console::Open(130);
	Console::ClearFile();

	g_hInst = hInstance;
	g_lpCmdLine = lpCmdLine;

	InitCommonControls();

	MSG msg;
	WNDCLASS wndclass;

	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hbrBackground = (HBRUSH)GetSysColorBrush(COLOR_WINDOW); //(HBRUSH)(COLOR_APPWORKSPACE+1);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hIcon = (HICON)LoadImage(g_hInst, MAKEINTRESOURCE(IDI_APP), IMAGE_ICON, 0, 0, LR_SHARED); //LoadIcon(NULL, MAKEINTRESOURCE(IDI_APP));
	wndclass.hInstance = hInstance;
	wndclass.lpfnWndProc = WndProc;
	wndclass.lpszClassName = g_szClassName;
	wndclass.lpszMenuName = NULL; //MAKEINTRESOURCE(IDR_MAINMNU);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;

	if(!RegisterClass(&wndclass)) {
		MessageBox(NULL, _T("Couldn't register window class!"), g_szAppTitle, MB_ICONERROR);
		return 0;
	}

	g_hMenuMain = LoadMenu(g_hInst, MAKEINTRESOURCE(IDR_MAINMNU));
	//g_hMenuInitWnd = GetSubMenu(g_hMenuInit, INIT_MENU_POS);

	g_dwWindowStyle = WS_OVERLAPPEDWINDOW & ~(WS_SIZEBOX | WS_MAXIMIZEBOX );
	g_hwndMain = CreateWindow(g_szClassName, g_szAppTitle, g_dwWindowStyle, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, g_hMenuMain, hInstance, NULL);
	ShowWindow(g_hwndMain, iCmdShow);
	UpdateWindow(g_hwndMain);

	// ----------------------------------------------------
	#ifdef SETUP_DEBUGGING
	// -------------
	// Load the game directly
	LaunchGame(g_lpCmdLine);
	#endif
	// ----------------------

	while(GetMessage(&msg, NULL, 0, 0))
	{
		if(IsDialogMessage(g_hwndInterface, &msg)) continue;
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	//DestroyMenu(g_hMenuInit);

	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
	case WM_CREATE:
		{ //LG
		g_hwndMain = hwnd;

		DWORD color = GetSysColor(COLOR_WINDOW);
		unsigned int c_r = 0, c_g = 0, c_b = 0;
		c_r = GetRValue(color);
		c_g = GetGValue(color);
		c_b = GetBValue(color);

		g_hbr = CreateSolidBrush(RGB(c_r-3, c_g-3, c_b-1));

		CreateDialog(g_hInst, MAKEINTRESOURCE(IDD_INTERFACE), g_hwndMain, (DLGPROC)InterfaceProc);
		
		RECT rect;
		GetWindowRect(g_hwndInterface, &rect);
		AdjustWindowRect(&rect, g_dwWindowStyle, GetMenu(g_hwndMain) != NULL ? true : false);
		SetWindowPos(g_hwndMain, NULL, 0, 0, rect.right-rect.left, rect.bottom-rect.top, SWP_NOMOVE | SWP_NOZORDER | SWP_NOREPOSITION);
		ShowWindow(g_hwndInterface, SW_SHOW);
		}
		return 0;

	case WM_COMMAND:
		switch(wParam)
		{
		case ID_HELP_ABOUT:
			{ //LG
				CreateDialog(g_hInst, MAKEINTRESOURCE(IDD_ABOUT), g_hwndMain, (DLGPROC)AboutProc);
			}
			return 0;

		case ID_FILE_PLAYFF8:
			LaunchGame(g_lpCmdLine);
			return 0;
		case ID_FILE_EXIT:
			DestroyWindow(g_hwndMain);
		}
		break;

	case WM_DESTROY:
		DeleteObject(g_hbr);
		DestroyWindow(g_hwndInterface);

		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

LRESULT CALLBACK InterfaceProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
	case WM_INITDIALOG:
		{ //LG
		g_hwndInterface = hwnd;

		memset(&g_config, 0, sizeof(g_config));
		LoadConfig(g_config);

		//Populate controls
		HWND hwndDispMode = GetDlgItem(g_hwndInterface, IDC_DDDISPLAYMODE);
		for(UINT i = 0; i < displaymode_options_count; i++) {
			ComboBox_AddString(hwndDispMode, displaymode_options[i].name);
		}
		ComboBox_SetCurSel(hwndDispMode, g_config.displaymode);

		HWND hwndFSAA = GetDlgItem(g_hwndInterface, IDC_DDFSAA);
		for(UINT i = 0; i < fsaa_options_count; i++) {
			ComboBox_AddString(hwndFSAA, fsaa_options[i].name);
		}
		ComboBox_SetCurSel(hwndFSAA, g_config.fsaa);

		HWND hwnd8bitPFix = GetDlgItem(g_hwndInterface, IDC_8BITPFIX);
		Button_SetCheck(hwnd8bitPFix, (g_config.b8_paletted_textures_fix == 1 ? BST_CHECKED : BST_UNCHECKED));

		HWND hwndStretch43Ar = GetDlgItem(g_hwndInterface, IDC_STRETCH43AR);
		Button_SetCheck(hwndStretch43Ar, (g_config.stretch_4_3_ar == 1 ? BST_CHECKED : BST_UNCHECKED));

		HWND hwndExpertMode = GetDlgItem(g_hwndInterface, IDC_EXPERTMODE);
		Button_SetCheck(hwndExpertMode, (g_config.expert_mode == 1 ? BST_CHECKED : BST_UNCHECKED));
		
		return true;
		}

	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case IDC_BTPLAY:
			LaunchGame(g_lpCmdLine);
			return TRUE;

		case IDC_DDDISPLAYMODE:
			g_config.displaymode = ComboBox_GetCurSel(GetDlgItem(g_hwndInterface, IDC_DDDISPLAYMODE));
			SaveConfig(g_config);
			
			return TRUE;

		case IDC_DDFSAA:
			g_config.fsaa = ComboBox_GetCurSel(GetDlgItem(g_hwndInterface, IDC_DDFSAA));
			SaveConfig(g_config);
			
			return TRUE;

		case IDC_8BITPFIX:
			if(Button_GetCheck(GetDlgItem(g_hwndInterface, IDC_8BITPFIX)) == BST_CHECKED) g_config.b8_paletted_textures_fix = 1;
			else  g_config.b8_paletted_textures_fix = 0;
			SaveConfig(g_config);
			
			return TRUE;

		case IDC_STRETCH43AR:
			if(Button_GetCheck(GetDlgItem(g_hwndInterface, IDC_STRETCH43AR)) == BST_CHECKED) g_config.stretch_4_3_ar = 1;
			else  g_config.stretch_4_3_ar = 0;
			SaveConfig(g_config);
			
			return TRUE;

		case IDC_EXPERTMODE:
			if(Button_GetCheck(GetDlgItem(g_hwndInterface, IDC_EXPERTMODE)) == BST_CHECKED) g_config.expert_mode = 1;
			else  g_config.expert_mode = 0;
			SaveConfig(g_config);
			
			return TRUE;
		}


	//Sets background of child dialog boxes to transparent
	/*case WM_CTLCOLORDLG:
		{
		HDC hDC = (HDC)wParam;
		SetBkMode(hDC, TRANSPARENT);
		}
		return (INT_PTR)GetStockObject(HOLLOW_BRUSH);

	case WM_CTLCOLORBTN:
		return (INT_PTR)GetSysColorBrush(COLOR_WINDOW);

	case WM_CTLCOLOREDIT:
		return (INT_PTR)GetSysColorBrush(COLOR_WINDOW);

	case WM_CTLCOLORSTATIC:
		{
		HDC hDC = (HDC)wParam;
		SetBkColor(hDC, GetSysColor(COLOR_WINDOW));
		SetBkMode(hDC, TRANSPARENT);
		}
		return (INT_PTR)g_hbr;
	*/
	}

	return FALSE;
}

LRESULT CALLBACK AboutProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static _TCHAR *buffer = NULL;

	switch(message)
	{
	case WM_INITDIALOG:
		{ //LG
		
		HWND hwndAboutText = GetDlgItem(hwnd, IDC_ABOUTTEXT);

		tifstream ifs;
		ifs.open(_T("readme.txt"), std::ios::binary);
		if(ifs.is_open()) {
			ifs.seekg(0, std::ios::end);
			int length = ifs.tellg();
			ifs.seekg(0, std::ios::beg);
			ifs.clear();

			buffer = new _TCHAR[length+1];
			ifs.read(buffer, length);
			buffer[ifs.gcount()] = _T('\0');
			
			ifs.close();
			Edit_SetText(hwndAboutText, buffer);
		} else Edit_SetText(hwndAboutText, _T("readme.txt file is missing..."));

		ShowWindow(hwnd, SW_SHOW);
		return true;
		}

	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case IDOK:
		case IDCANCEL:
			if(buffer != NULL) {
				delete[] buffer;
				buffer = NULL;
			}

			EndDialog(hwnd, NULL);
			return TRUE;
		}

	//Sets background of child dialog boxes to transparent
	case WM_CTLCOLORDLG:
		{
		//HDC hDC = (HDC)wParam;
		//SetBkMode(hDC, TRANSPARENT);
		}
		return (INT_PTR)GetSysColorBrush(COLOR_WINDOW);

	case WM_CTLCOLORBTN:
		return (INT_PTR)GetSysColorBrush(COLOR_WINDOW);

	case WM_CTLCOLOREDIT:
		return (INT_PTR)GetSysColorBrush(COLOR_WINDOW);

	case WM_CTLCOLORSTATIC:
		{
		HDC hDC = (HDC)wParam;
		SetBkColor(hDC, GetSysColor(COLOR_WINDOW));
		SetBkMode(hDC, TRANSPARENT);
		}
		return (INT_PTR)g_hbr;
	
	}

	return FALSE;
}

// Get the FF8.exe path and load the game
void LaunchGame(LPCSTR lpCmdLine)
{

	// ----------------------------------------------------
	#ifdef SETUP_DEBUGGING
	// -------------
	// Use a custom exe path
	//std::string StrPath = "";
	std::string StrPath = "C:\\Files\\Games\\Dune 2000 (1998)\\Game\\DUNE2000.EXE";
	//std::string StrPath = "C:\\Files\\Games\\Final Fantasy VIII (1998)\\Game\\FF8.exe";
	//std::string StrPath = "C:\\Program Files (XP)\\Microsoft Virtual PC\\Virtual PC.exe";
	#endif
	// ----------------------


	_TCHAR exe_path[MAX_PATH];
	memset(&exe_path, 0, sizeof(_TCHAR)*MAX_PATH);

	_TCHAR dir_path[MAX_PATH];
	DWORD dir_path_size = MAX_PATH*sizeof(_TCHAR);
	memset(&dir_path, 0, dir_path_size);

	#ifndef SETUP_DEBUGGING
		int lpCmdLineF_size = (int)strlen(lpCmdLine) + 1;
	#else
		int lpCmdLineF_size = (int)(StrPath.length() + 1);
	#endif
	_TCHAR *lpCmdLineF = new _TCHAR[lpCmdLineF_size];
	#ifdef  _UNICODE
		#ifndef SETUP_DEBUGGING
			MultiByteToWideChar(CP_UTF8, 0, lpCmdLine, -1, lpCmdLineF, lpCmdLineF_size);
		#else
			MultiByteToWideChar(CP_UTF8, 0, StrPath.c_str(), -1, lpCmdLineF, lpCmdLineF_size);
		#endif
	#else
		#ifndef SETUP_DEBUGGING
			_sntprintf_s(lpCmdLineF, lpCmdLineF_size, lpCmdLineF_size, _T("%s"), lpCmdLine);
		#else
			_sntprintf_s(lpCmdLineF, lpCmdLineF_size, lpCmdLineF_size, _T("%s"), StrPath.c_str());
		#endif
	#endif

	FILE *fs;
	#ifdef  _UNICODE
		if(lpCmdLineF_size > 1 && ((fs = _wfsopen(lpCmdLineF, _T("r"), _SH_DENYNO)) != NULL))
	#else
		if(lpCmdLineF_size > 1 && ((fs = _fsopen(lpCmdLineF, _T("r"), _SH_DENYNO)) != NULL))
	#endif
	{
		// From file
		fclose(fs);

		_sntprintf_s((_TCHAR *)&dir_path, MAX_PATH, MAX_PATH, _T("%s"), lpCmdLineF);
		for(int i = MAX_PATH-1; i >= 0; i--)
		{
			if(dir_path[i] == _T('\\'))
			{
				dir_path[i] = _T('\0');
				break;
			}
		}

		_sntprintf_s((_TCHAR *)&exe_path, MAX_PATH, MAX_PATH, _T("%s"), lpCmdLineF);
	}
	else
	{
		// From registry
		/* Dune 2000 creates saves the path to the main exe when the game is installed, in [HKEY_LOCAL_MACHINE\
		   SOFTWARE\Westwood\Dune 2000] \ InstallPath. But it's not needed to run the game (the information in
		   RESOURCE.CFG is enough) so we can't definately know that we have a registry path.
		*/
		/*
		HKEY hFF8_key = NULL;

		if(ERROR_SUCCESS == RegOpenKeyEx(HKEY_LOCAL_MACHINE, _T("SOFTWARE\\Square Soft, Inc\\FINAL FANTASY VIII\\1.00"), 0, KEY_QUERY_VALUE, &hFF8_key))
		{
			if(ERROR_SUCCESS == RegQueryValueEx(hFF8_key, _T("AppPath"), NULL, NULL, (LPBYTE)&dir_path, &dir_path_size))
			{
				_sntprintf_s((_TCHAR *)&exe_path, MAX_PATH, MAX_PATH, _T("%s\\FF8.exe"), dir_path);
			}
		}
		*/
	}

	// ---------------------------------------------------------------------------------
	// Inject our library into the target process
	// --------------------
	if(_tcslen((_TCHAR *)&exe_path) <= 0)
	{
		MessageBox(NULL, _T("DUNE2000.exe path missing from both command line and registry.\n\nCorrect Usage:\nc:\\games\\D2k_loader.exe c:\\games\\DUNE2000.exe"), _T("Dune 2000 Loader"), MB_OK | MB_ICONERROR);
	} else
	{
		//installCOMHook();

		_TCHAR currdirPath[MAX_PATH], libPath[MAX_PATH];
		if(GetCurrentDirectory(MAX_PATH, currdirPath))
		{
			//Error
		}
		_sntprintf_s(libPath, MAX_PATH, MAX_PATH, _T("%s\\DX_Hook.dll"), currdirPath);

		// Logging
		//Console::Print("Path:\n   %s\n   %s\n   %s\n   %s\n", lpCmdLine, lpCmdLineF, exe_path, libPath);
		//return;

		STARTUPINFO si;
		PROCESS_INFORMATION pi;
		memset(&si, 0, sizeof(si));
		memset(&pi, 0, sizeof(pi));
		si.cb = sizeof(si);

		// Launch exe
		#ifdef  _UNICODE
			if(!CreateProcess(NULL, (LPWSTR)&exe_path, NULL, NULL, FALSE, 0, NULL, NULL /*(LPCWSTR)&dir_path*/, &si, &pi))
		#else
			if(!CreateProcess(NULL, (LPSTR)&exe_path, NULL, NULL, FALSE, 0, NULL, NULL /*(LPCWSTR)&dir_path*/, &si, &pi))
		#endif
		{
			_TCHAR mbuffer[255];
			_sntprintf_s((_TCHAR *)&mbuffer, 150, 150, _T("CreateProcess(FF8.exe) returned an error...\n\nERROR CODE: %d\n"),  GetLastError());
			MessageBox(NULL, (_TCHAR *)&mbuffer, _T("Dune 2000 Loader"), MB_OK | MB_ICONERROR);
		}


		// The thread used for the DUNE2000.exe process
		HANDLE hThread;
		void* pLibRemote;
		DWORD hLibModule;
		HMODULE hKernel32 = GetModuleHandle(_T("Kernel32"));

		pLibRemote = VirtualAllocEx(pi.hProcess, NULL, sizeof(libPath), MEM_COMMIT, PAGE_READWRITE);
		WriteProcessMemory(pi.hProcess, pLibRemote, (void*)libPath, sizeof(libPath), NULL );

		// Load thread
		Console::Print("Load thread\n");
		hThread = ::CreateRemoteThread(pi.hProcess, NULL, 0, (LPTHREAD_START_ROUTINE) GetProcAddress(hKernel32, "LoadLibraryW"), pLibRemote, 0, NULL);
		// Wait for ...
		WaitForSingleObject(hThread, INFINITE);
		GetExitCodeThread(hThread, &hLibModule);	
		// Close thread
		Console::Print("Load thread done\n");
		CloseHandle(hThread);
		//
		VirtualFreeEx(pi.hProcess, pLibRemote, sizeof(libPath), MEM_RELEASE);

		// Destroy the application window, but wait for the DUNE2000.exe process to return before terminating the launcher process
		DestroyWindow(g_hwndMain);
		
		// The game was terminated
		WaitForSingleObject(pi.hProcess, INFINITE);
		Console::Print("Unload DLL\n");
		// Unload DLL
		hThread = ::CreateRemoteThread(pi.hProcess, NULL, 0, (LPTHREAD_START_ROUTINE) GetProcAddress(hKernel32, "FreeLibraryW"), (LPVOID)hLibModule, 0, NULL);
		WaitForSingleObject(hThread, INFINITE);
		CloseHandle(hThread);

		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);

		//Release COM-hook and cleanup
		//removeCOMHook();
	}
	// ---------------------------------------

	delete lpCmdLineF;
	lpCmdLineF = NULL;
}