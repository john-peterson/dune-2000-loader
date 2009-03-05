//////////////////////////////////////////////////////////////////////////////////////////////////////
// Includes
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
#include <iostream> // With the new .NET compilers iostream.h is replaced with just iostream
#include <windows.h> 
#include <string.h> 
#include "ddraw.h"
/////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
// Declarations and definitions
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
typedef HRESULT (__stdcall *Func_DirectDrawCreate)(GUID FAR *, LPDIRECTDRAW FAR *, IUnknown FAR *);
LPDIRECTDRAW		lplpDD;		// DirectDraw object
/////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
// Main
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
int main ()
{
	// Make the console window bigger
	//MoveWindow(Console::GetHwnd(), 200,0, 200*8,50*14, true);

	// Load DLL
	HMODULE hModule = LoadLibrary("ddraw.dll");
	// Check if LoadLibrary() succeeded
	if(hModule != NULL)
	{
		Func_DirectDrawCreate pDirectDrawCreate = (Func_DirectDrawCreate)GetProcAddress(hModule, "DirectDrawCreate");
		// Check if the function existed
		if(pDirectDrawCreate != NULL)
		{
			HRESULT hr = pDirectDrawCreate(NULL, &lplpDD, NULL);
			//HRESULT ddrval = lplpDD->SetCooperativeLevel( hwnd, DDSCL_NORMAL );
			printf("DirectDrawCreate was called");
		}
		else
		{
			printf("DirectDrawCreate did not exist");
		}
		// Free the DLL
		FreeLibrary(hModule);
	}
	else
	{
		printf("Could not load ddraw.dll");
	}

	// Wait for input before terminating
	std::cin.get();

	return 0;
}
/////////////////////////////////////////////


