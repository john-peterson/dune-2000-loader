/*
Direct Draw Wrapper
by 2ci-
http://2ci.elitecoders.org
http://www.elitecoders.org
www.game-deception.com
Converted from Direct Draw 4 to 7 by Temp2 27 March 2006
*/


//////////////////////////////////////////////////////////////////////////////////////////////////////
// Includes
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
#include "Common.h"
/////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
// DllMain
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
extern "C" void *_ReturnAddress( void );
DirectDrawCreate_t pDirectDrawCreate;
hkIDirectDraw	*myIDirectDraw		= 0;
typedef HRESULT (__stdcall *Func_DirectDrawCreate)(GUID FAR *, LPDIRECTDRAW FAR *, IUnknown FAR *);
///////////////////////////////////////


HRESULT WINAPI DirectDrawCreate( GUID FAR *lpGUID, LPDIRECTDRAW FAR *lplpDD, IUnknown FAR *pUnkOuter )
{
	HMODULE		hDDraw = LoadLibrary( "D:\\Windows\\System32\\ddraw.dll" );
	Func_DirectDrawCreate	pDirectDrawCreate = (Func_DirectDrawCreate)GetProcAddress( hDDraw, "DirectDrawCreate" );


	DWORD returnAddress = PtrToUlong( _ReturnAddress() );
	HRESULT returnValue = 0;
	
	returnValue = pDirectDrawCreate( lpGUID, lplpDD, pUnkOuter );
	AddLog("");
	AddLog("");
	AddLog( "DirectDrawCreate: lplpDD = 0x%08X:0x%08X:0x%08X", lplpDD, *lplpDD, returnAddress );

	if( myIDirectDraw ) {
		delete myIDirectDraw;
		myIDirectDraw = 0;
	}
	myIDirectDraw = new hkIDirectDraw( lplpDD );
	
	AddLog( "DirectDrawCreate: lplpDD = 0x%08X:0x%08X:0x%08X", lplpDD, *lplpDD, returnAddress );

	return( returnValue );
}