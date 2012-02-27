// This file is part of Dune 2000 Launcher, licensed under GNU GPL 3

// Project description
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
//The purpose of this project is to increase the output resolution of Dune 2000 (1998) so that it can be
//displayed properly on current flat screens that has problems with both the 640x400 and 640x480 resolution
//that the game produce. In the current form the code is in most parts a copy of a FF8 Launcher by Tobias
//Sebring (aka Magix). The goal is to modify this code so that it works with Dune 2000.

// Current issues
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
//The call to ddraw.dll is not picked up. Can it be because the exe loads the main part of the code from
//DUNE2000.DAT, and that only calls directly from DUNE2000.EXE are picked up?

#include "winmain.h"
#include "../Common/Common.h"

_TCHAR g_szAppTitle[] = _T("Dune 2000 Loader");
_TCHAR g_szClassName[] = _T("D2kLoader");
HINSTANCE g_hInst = NULL;
HWND g_hwndMain = NULL, g_hwndInterface = NULL;
HMENU g_hMenuMain = NULL;
HBRUSH g_hbr = NULL;
DWORD g_dwWindowStyle = 0;
LPWSTR g_lpCmdLine = NULL;
#define _NL _T("\r\n")

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR SCmdLine, int iCmdShow) {
	g_hInst = hInstance;
	g_lpCmdLine = SCmdLine;

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

#ifdef SETUP_DEBUGGING
	// Load the game directly
	LaunchGame(wstring(g_lpCmdLine));
#endif

	while(GetMessage(&msg, NULL, 0, 0)) {
		if(IsDialogMessage(g_hwndInterface, &msg)) continue;
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	//DestroyMenu(g_hMenuInit);
	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch(message) {
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

LRESULT CALLBACK InterfaceProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch(message) {
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
		switch(LOWORD(wParam)) {
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

LRESULT CALLBACK AboutProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	static _TCHAR *buffer = NULL;
	switch(message) {
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
		switch(LOWORD(wParam)) {
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

// Get the target exe path and load it
void LaunchGame(wstring SCmdLine) {
	wstring exe_path, dir_path, libPath;

	// Use a custom exe path
	#ifdef SETUP_DEBUGGING
	SCmdLine = L"TestTarget2.exe";
	//SCmdLine = "I:\\Games\\Dune 2000 (1998)\\DUNE2000.EXE";
	//SCmdLine = "C:\\Files\\Games\\Final Fantasy VIII (1998)\\Game\\FF8.exe";
	//SCmdLine = "C:\\Program Files (XP)\\Microsoft Virtual PC\\Virtual PC.exe";
	#endif

	// Get path
	if(FileExist(SCmdLine)) {
		dir_path = GetPath(SCmdLine);
		exe_path = SCmdLine;
	} else {
		// From registry
		// Dune 2000 saves the path to the main exe in [HKEY_LOCAL_MACHINE\SOFTWARE\Westwood\Dune 2000]\InstallPath
		// when the game is installed. But it's not needed to run the game (the information in
		// RESOURCE.CFG is enough) so we can't definately know that we have a registry path.

		//HKEY hFF8_key = NULL;
		//if (ERROR_SUCCESS == RegOpenKeyEx(HKEY_LOCAL_MACHINE, _T("SOFTWARE\\Square Soft, Inc\\FINAL FANTASY VIII\\1.00"), 0, KEY_QUERY_VALUE, &hFF8_key)) {
		//	if (ERROR_SUCCESS == RegQueryValueEx(hFF8_key, _T("AppPath"), NULL, NULL, (LPBYTE)&dir_path, &dir_path_size))
		//		_sntprintf_s((_TCHAR *)&exe_path, MAX_PATH, MAX_PATH, _T("%s\\FF8.exe"), dir_path);
		//}
	}

	// Dll directory
	libPath = Format(L"%s\\DX_Hook.dll", GetCurrentDirectoryEx().c_str());
		
	// Inject our library into the target process
	if (SCmdLine.empty()) {
		MessageBox(NULL,
		_T("DUNE2000.exe path missing from both command line and registry.\n\n")
		_T("Correct Usage:\nc:\\games\\D2k_loader.exe c:\\games\\DUNE2000.exe"),
		_T("Dune 2000 Loader"), MB_OK | MB_ICONERROR);
	}
	else if (!FileExist(SCmdLine)) {
		MessageBox(NULL, Format(L"Could not find '%s'", SCmdLine.c_str()).c_str(),
		L"Dune 2000 Loader", MB_OK | MB_ICONERROR);	
	} else if (!FileExist(libPath)) {
		MessageBox(NULL, Format(L"Could not find '%s'", libPath.c_str()).c_str(),
		L"Dune 2000 Loader", MB_OK | MB_ICONERROR);	
	} else {
		//installCOMHook();

		// Logging
		OutputDebugStringEx(L"Path:\n   %s\n   %s\n   %s\n", SCmdLine.c_str(), exe_path.c_str(), libPath.c_str());
		//return;

		// Create process ID templates to store the new process ID in
		STARTUPINFOA si;
		PROCESS_INFORMATION pi;
		memset(&si, 0, sizeof(si));
		memset(&pi, 0, sizeof(pi));
		si.cb = sizeof(si);

		// Launch exe
		if (!CreateProcessA(NULL, (LPSTR)exe_path.c_str(), NULL, NULL, FALSE, 0, NULL, NULL /*(LPSTR)dir_path.c_str()*/, &si, &pi)) {
			MessageBoxA(NULL, FormatA("CreateProcess returned an error: %s\n", ShowError().c_str()).c_str(), "Dune 2000 Loader", MB_OK | MB_ICONERROR);
		}

		// The thread used for the target process
		HANDLE hThread;
		void* pLibRemote;
		DWORD hLibModule;
		HMODULE hKernel32 = GetModuleHandle(_T("Kernel32"));

		pLibRemote = VirtualAllocEx(pi.hProcess, NULL, sizeof(libPath), MEM_COMMIT, PAGE_READWRITE);
		WriteProcessMemory(pi.hProcess, pLibRemote, libPath.c_str(), libPath.length(), NULL );

		// Create remote thread
		OutputDebugStringEx(L"CreateRemoteThread\n");
		hThread = ::CreateRemoteThread(pi.hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)GetProcAddress(hKernel32, "LoadLibraryA"), pLibRemote, 0, NULL);
		if (hThread == NULL) {
			OutputDebugStringEx(L"CreateRemoteThread: %s\n", ShowError().c_str());
		}
		
		// Wait for LoadLibrary
		WaitForSingleObject(hThread, INFINITE);
		GetExitCodeThread(hThread, &hLibModule);	
		// Dll is loaded, close thread
		OutputDebugStringEx(L"Load thread done\n");
		CloseHandle(hThread);
		VirtualFreeEx(pi.hProcess, pLibRemote, sizeof(libPath), MEM_RELEASE);
		// Destroy the application window, 
		DestroyWindow(g_hwndMain);
		
		// Wait for the target process to return before terminating the launcher process
		WaitForSingleObject(pi.hProcess, INFINITE);
		// Unload DLL
		OutputDebugStringEx(L"Unload DLL\n");
		hThread = ::CreateRemoteThread(pi.hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)GetProcAddress(hKernel32, "FreeLibraryA"), (LPVOID)hLibModule, 0, NULL);
		WaitForSingleObject(hThread, INFINITE);
		CloseHandle(hThread);
		// Close target process
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);

		//Release COM-hook and cleanup
		//removeCOMHook();
	}
	// ---------------------------------------
	
#ifdef SETUP_DEBUGGING
	cin.get();
#endif
}
