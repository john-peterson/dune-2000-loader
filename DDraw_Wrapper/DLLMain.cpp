//////////////////////////////////////////////////////////////////////////////////////////////////////
// Includes
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#include "ddraw.h"
///////////////////////////////////////


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
	HRESULT __stdcall DirectDrawCreate(GUID FAR *lpGUID, LPDIRECTDRAW FAR *lplpDD, IUnknown FAR *pUnkOuter )
	{
		//*lplpDD = YourWrappedDDObject
		return S_OK;
	}
}
///////////////////////////////////////

