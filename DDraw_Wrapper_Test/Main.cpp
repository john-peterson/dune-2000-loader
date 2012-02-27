// (C) John Peterson, licensed under GNU GPL 3
#include <iostream>
#include <windows.h> 
#include <string.h> 
#include "ddraw.h"
using namespace std;

typedef HRESULT (__stdcall *Func_DirectDrawCreate)(GUID FAR *, LPDIRECTDRAW FAR *, IUnknown FAR *);
LPDIRECTDRAW		g_lplpDD;		// DirectDraw object

// Main
int main () {
	// Load DLL
	HMODULE hModule = LoadLibrary("ddraw.dll");
	// Check if LoadLibrary() succeeded
	if(hModule != NULL) {
		Func_DirectDrawCreate pDirectDrawCreate = (Func_DirectDrawCreate)GetProcAddress(hModule, "DirectDrawCreate");
		// Check if the function existed
		if(pDirectDrawCreate != NULL) {
			HRESULT hr = pDirectDrawCreate(NULL, &g_lplpDD, NULL);			
			printf("DirectDrawCreate was called: 0x%08x\n", (int)g_lplpDD);

			// Test if the pointer works
			//HRESULT ddrval = lplpDD->SetCooperativeLevel( NULL, DDSCL_NORMAL );
			DDSURFACEDESC ddsd;
			ZeroMemory( &ddsd, sizeof(DDSURFACEDESC) );
			ddsd.dwSize = sizeof(DDSURFACEDESC);
			HRESULT ddrval = g_lplpDD->GetDisplayMode( &ddsd );
			printf("GetDisplayMode: %ix%ix%i\n", ddsd.dwWidth, ddsd.dwHeight, ddsd.ddpfPixelFormat.dwRGBBitCount);
		}
		else {
			printf("DirectDrawCreate did not exist");
		}
		// Free the DLL
		FreeLibrary(hModule);
	}
	else {
		printf("Could not load ddraw.dll");
	}

	// Wait for input before terminating
	cin.get();
	return 0;
}