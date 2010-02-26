/*
http://forum.gamedeception.net/showpost.php?p=66686&postcount=50

Direct Draw Wrapper
by 2ci-
http://2ci.elitecoders.org
http://www.elitecoders.org
www.game-deception.com
Converted from Direct Draw 4 to 7 by Temp2 27 March 2006
*/

#include "Common.h"

#pragma warning(disable:4311) // warning C4311: 'type cast' : pointer truncation from 'PIMAGE_DOS_HEADER' to 'DWORD'
#pragma warning(disable:4312) // warning C4312: 'type cast' : conversion from 'unsigned long' to 'PIMAGE_NT_HEADERS' of greater size

#define MakePtr( type, ptr, addValue )( type )( ( DWORD )( ptr ) + ( DWORD )( addValue ) )


//////////////////////////////////////////////////////////////////////////////////////////////////////
// ...
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
void *InterceptDllCall( HMODULE hModule, char *szDllName, char *szFunctionName, DWORD pNewFunction )
{
	PIMAGE_DOS_HEADER pDosHeader;
	PIMAGE_NT_HEADERS pNTHeader;

	PIMAGE_IMPORT_DESCRIPTOR pImportDesc;
	PIMAGE_THUNK_DATA pThunk;

	DWORD dwOldProtect, dwOldProtect2;

	void *pOldFunction;

	if( !( pOldFunction = GetProcAddress( ( HMODULE )GetModuleHandle( szDllName ), szFunctionName ) ) )
		return( 0 );

	pDosHeader = ( PIMAGE_DOS_HEADER )hModule;

	if( pDosHeader->e_magic != IMAGE_DOS_SIGNATURE )
		return( NULL );

	pNTHeader = MakePtr( PIMAGE_NT_HEADERS, pDosHeader,pDosHeader->e_lfanew );

	if( pNTHeader->Signature != IMAGE_NT_SIGNATURE || ( pImportDesc = MakePtr( PIMAGE_IMPORT_DESCRIPTOR, pDosHeader, pNTHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress ) ) == ( PIMAGE_IMPORT_DESCRIPTOR )pNTHeader )
		return( NULL );

	while( pImportDesc->Name )
	{
		char *szModuleName = MakePtr( char *, pDosHeader,	pImportDesc->Name );

		if( !lstrcmpi( szModuleName, szDllName ) )
			break;

		pImportDesc++;
	}

	if( pImportDesc->Name == NULL )
		return( NULL );

	pThunk = MakePtr( PIMAGE_THUNK_DATA, pDosHeader,	pImportDesc->FirstThunk );

	while( pThunk->u1.Function )
	{
		if( pThunk->u1.Function == ( DWORD )pOldFunction )
		{
			VirtualProtect( ( void * )&pThunk->u1.Function, sizeof( DWORD ), PAGE_EXECUTE_READWRITE, &dwOldProtect );
			pThunk->u1.Function = ( DWORD )pNewFunction;
			VirtualProtect( ( void * )&pThunk->u1.Function, sizeof( DWORD ), dwOldProtect, &dwOldProtect2 );

			return( pOldFunction );
		}
		pThunk++;
	}
	return( NULL ); 
}
//////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
// ...
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
BOOL (WINAPI *pLineTo)(HDC hdc, int nXEnd, int nYEnd);
BOOL WINAPI LineTo_Hook(HDC hdc, int nXEnd, int nYEnd)
{
	BOOL hRet = pLineTo(hdc, nXEnd, nYEnd);
	AddLog( "LineTo" );
	return hRet;
}
HGDIOBJ (WINAPI *pSelectObject)(HDC hdc, HGDIOBJ hgdiobj);
HGDIOBJ WINAPI SelectObject_Hook(HDC hdc, HGDIOBJ hgdiobj)
{
	HGDIOBJ hRet = pSelectObject(hdc, hgdiobj);
	AddLog( "SelectObject" );
	return hRet;
}
HPEN (WINAPI *pCreatePen)(int fnPenStyle, int nWidth, COLORREF crColor);
HPEN WINAPI CreatePen_Hook(int fnPenStyle, int nWidth, COLORREF crColor)
{
	HPEN hRet = pCreatePen(fnPenStyle, nWidth, crColor);
	AddLog( "CreatePen" );
	return hRet;
}
BOOL (WINAPI *pDeleteObject)(HGDIOBJ hObject);
BOOL WINAPI DeleteObject_Hook(HGDIOBJ hObject)
{
	BOOL hRet = pDeleteObject(hObject);
	AddLog( "DeleteObject" );
	return hRet;
}
UINT (WINAPI *pGetSystemPaletteEntries)(HDC hdc, UINT iStartIndex, UINT nEntries, LPPALETTEENTRY lppe);
UINT WINAPI GetSystemPaletteEntries_Hook(HDC hdc, UINT iStartIndex, UINT nEntries, LPPALETTEENTRY lppe)
{
	UINT hRet = pGetSystemPaletteEntries(hdc, iStartIndex, nEntries, lppe);
	AddLog( "GetSystemPaletteEntries" );
	return hRet;
}
BOOL (WINAPI *pMoveToEx)(HDC hdc, int X, int Y, LPPOINT lpPoint);
BOOL WINAPI MoveToEx_Hook(HDC hdc, int X, int Y, LPPOINT lpPoint)
{
	BOOL hRet = pMoveToEx(hdc, X, Y, lpPoint);
	AddLog( "MoveToEx" );
	return hRet;
}
//////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
// DllMain
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
bool WINAPI DllMain( HANDLE hInstance, DWORD dwReason, LPVOID lpReserved )
{
	if( dwReason == DLL_PROCESS_ATTACH )
	{
		Console::Open();
		Console::ClearFile();

		AddLog( "" );
		AddLog( "----------------------------------------------------------------" );
		AddLog( "Log Opened" );
		AddLog( "----------------------------------------------------------------" );
	}
	return( true );
}
//////////////////////////////////////