/*
Direct Draw Wrapper
by 2ci-
http://2ci.elitecoders.org
http://www.elitecoders.org
www.game-deception.com
Converted from Direct Draw 4 to 7 by Temp2 27 March 2006
*/

#include "Common.h"

hkIDirectDraw7	*myIDirectDraw7		= 0;

/*** IUnknown methods ***/
HRESULT hkIDirectDraw::QueryInterface( REFIID riid, LPVOID FAR * ppvObj )
{
	HRESULT hRet = m_pDDraw->QueryInterface( riid, ppvObj );
	AddLog( "hkIDirectDraw::QueryInterface" );

	if( riid == IID_IDirectDraw7 ) {

		AddLog( "Direct Draw 7 Interface requested" );
		if( myIDirectDraw7 ) {
			delete myIDirectDraw7;
			myIDirectDraw7 = 0;
		}		
		myIDirectDraw7 = new hkIDirectDraw7( (IDirectDraw7 ** )ppvObj );
	}
	return( hRet );
}

ULONG hkIDirectDraw::AddRef( THIS )
{
	AddLog( "hkIDirectDraw::AddRef" );
	return m_pDDraw->AddRef( );
}

ULONG hkIDirectDraw::Release( THIS )
{
	AddLog( "hkIDirectDraw::Release" );
	return m_pDDraw->Release( );
}

/*** IDirectDraw methods ***/
HRESULT hkIDirectDraw::Compact(THIS)
{
	AddLog( "hkIDirectDraw::Compact" );
	return m_pDDraw->Compact( );
}

HRESULT hkIDirectDraw::CreateClipper(THIS_ DWORD dwUnknown, LPDIRECTDRAWCLIPPER FAR* lpClipper, IUnknown FAR * lpUnknown )
{
	AddLog( "hkIDirectDraw::CreateClipper" );
	return m_pDDraw->CreateClipper( dwUnknown, lpClipper, lpUnknown );
}

HRESULT hkIDirectDraw::CreatePalette(THIS_ DWORD dwUnknown, LPPALETTEENTRY lpPaletteEntry, LPDIRECTDRAWPALETTE FAR* lpDDPalette, IUnknown FAR * lpUnknown )
{
	AddLog( "hkIDirectDraw::CreatePalette" );
	return m_pDDraw->CreatePalette( dwUnknown, lpPaletteEntry, lpDDPalette, lpUnknown );
}

HRESULT hkIDirectDraw::CreateSurface(THIS_  LPDDSURFACEDESC lpDDSurfaceDesc, LPDIRECTDRAWSURFACE FAR * lpDDSurface, IUnknown FAR * lpUnknown )
{
	AddLog( "hkIDirectDraw::CreateSurface" );
	return m_pDDraw->CreateSurface( lpDDSurfaceDesc, lpDDSurface, lpUnknown );
}

HRESULT hkIDirectDraw::DuplicateSurface( THIS_ LPDIRECTDRAWSURFACE DDSurface, LPDIRECTDRAWSURFACE FAR * lpDDSurface)
{
	AddLog( "hkIDirectDraw::DuplicateSurface" );
	return m_pDDraw->DuplicateSurface( DDSurface, lpDDSurface );
}

HRESULT hkIDirectDraw::EnumDisplayModes( THIS_ DWORD dwUnknown, LPDDSURFACEDESC lpDDSurfaceDesc, LPVOID lpVoidUnknown, LPDDENUMMODESCALLBACK lpEnumCallback )
{
	AddLog( "hkIDirectDraw::EnumDisplayModes" );
	return m_pDDraw->EnumDisplayModes( dwUnknown, lpDDSurfaceDesc, lpVoidUnknown, lpEnumCallback );
}

HRESULT hkIDirectDraw::EnumSurfaces(THIS_ DWORD dwUnknown, LPDDSURFACEDESC lpDDSurfaceDesc, LPVOID lpVoidUnknown, LPDDENUMSURFACESCALLBACK lpSurfaceCallback )
{
	AddLog( "hkIDirectDraw::EnumSurfaces" );
	return m_pDDraw->EnumSurfaces( dwUnknown, lpDDSurfaceDesc, lpVoidUnknown, lpSurfaceCallback );
}

HRESULT hkIDirectDraw::FlipToGDISurface(THIS)
{
	AddLog( "hkIDirectDraw::FlipToGDISurface" );
	return m_pDDraw->FlipToGDISurface( );
}

HRESULT hkIDirectDraw::GetCaps( THIS_ LPDDCAPS lpddCaps, LPDDCAPS lpddCaps2 )
{
	AddLog( "hkIDirectDraw::GetCaps" );
	return m_pDDraw->GetCaps( lpddCaps, lpddCaps2 );
}

HRESULT hkIDirectDraw::GetDisplayMode( THIS_ LPDDSURFACEDESC lpDDSurfaceDesc )
{
	AddLog( "hkIDirectDraw::GetDisplayMode" );
	return m_pDDraw->GetDisplayMode( lpDDSurfaceDesc );
}

HRESULT hkIDirectDraw::GetFourCCCodes(THIS_ LPDWORD lpdwUnknown1, LPDWORD lpdwUnknown2 )
{
	AddLog( "hkIDirectDraw::GetFourCCCodes" );
	return m_pDDraw->GetFourCCCodes( lpdwUnknown1, lpdwUnknown2 );
}

HRESULT hkIDirectDraw::GetGDISurface(THIS_ LPDIRECTDRAWSURFACE FAR * lpddSurface )
{
	AddLog( "hkIDirectDraw::GetGDISurface(" );
	return m_pDDraw->GetGDISurface( lpddSurface );
}

HRESULT hkIDirectDraw::GetMonitorFrequency(THIS_ LPDWORD lpdwFrequency )
{
	AddLog( "hkIDirectDraw::GetMonitorFrequency" );
	return m_pDDraw->GetMonitorFrequency( lpdwFrequency );
}

HRESULT hkIDirectDraw::GetScanLine(THIS_ LPDWORD lpdwScanline )
{
	AddLog( "hkIDirectDraw::GetScanLine" );
	return m_pDDraw->GetScanLine( lpdwScanline );
}

HRESULT hkIDirectDraw::GetVerticalBlankStatus(THIS_ LPBOOL lpValue )
{
	AddLog( "hkIDirectDraw::GetVerticalBlankStatus" );
	return m_pDDraw->GetVerticalBlankStatus( lpValue );
}

HRESULT hkIDirectDraw::Initialize(THIS_ GUID FAR * lpGuid )
{
	AddLog( "hkIDirectDraw::Initialize" );
	return m_pDDraw->Initialize( lpGuid );
}

HRESULT hkIDirectDraw::RestoreDisplayMode(THIS)
{
	AddLog( "hkIDirectDraw::RestoreDisplayMode" );
	return m_pDDraw->RestoreDisplayMode( );
}

HRESULT hkIDirectDraw::SetCooperativeLevel(THIS_ HWND hwnd, DWORD dwMode )
{
	AddLog( "hkIDirectDraw::SetCooperativeLevel" );
	return m_pDDraw->SetCooperativeLevel( hwnd, dwMode );
}

HRESULT hkIDirectDraw::SetDisplayMode(THIS_ DWORD dwOne, DWORD dwTwo, DWORD dwThree )
{
	AddLog( "hkIDirectDraw::SetDisplayMode" );
	return m_pDDraw->SetDisplayMode( dwOne, dwTwo, dwThree );
}

HRESULT hkIDirectDraw::WaitForVerticalBlank(THIS_ DWORD dwUnknown, HANDLE hHandle )
{
	AddLog( "hkIDirectDraw::WaitForVerticalBlank" );
	return m_pDDraw->WaitForVerticalBlank( dwUnknown, hHandle );
}
