//////////////////////////////////////////////////////////////////////////////////////////////////////
// Includes
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
#include <iostream>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#define DDRAW_HOOK
#include <ddraw.h>
///////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
// Declarations and definitions
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
typedef HRESULT (__stdcall *Func_DirectDrawCreate)(GUID FAR *, LPDIRECTDRAW FAR *, IUnknown FAR *);
/////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
// DLL Main
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
HINSTANCE g_hinstance = NULL;
BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
   switch (ul_reason_for_call)
   {
      case DLL_PROCESS_ATTACH:
         g_hinstance = hModule;
      case DLL_THREAD_ATTACH:
      case DLL_THREAD_DETACH:
      case DLL_PROCESS_DETACH:
         break;
   }
   return TRUE;
}
///////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
// Exported functions
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
extern "C"
{
	HRESULT __declspec(dllexport) DirectDrawCreate(GUID FAR *lpGUID, LPDIRECTDRAW FAR *lplpDD, IUnknown FAR *pUnkOuter )
	{
		// Load the real ddraw.dll
		HMODULE hModule = LoadLibrary("D:\\Windows\\System32\\ddraw.dll");
		HRESULT hr = NULL;
		if(hModule != NULL)
		{
			Func_DirectDrawCreate pDirectDrawCreate = (Func_DirectDrawCreate)GetProcAddress(hModule, "DirectDrawCreate");
			if(pDirectDrawCreate != NULL)
			{
				hr = pDirectDrawCreate(lpGUID, lplpDD, pUnkOuter);
				printf("DirectDrawCreate succeeded\n");
			}
			else
			{
				printf("DirectDrawCreate failed\n");
			}

			FreeLibrary(hModule);
		}
		else
		{
			printf("Could not load System32\\ddraw.dll\n");
		}
		return hr;
	}
}
///////////////////////////////////////

