/*
Direct Draw Wrapper
by 2ci-
http://2ci.elitecoders.org
http://www.elitecoders.org
www.game-deception.com
Converted from Direct Draw 4 to 7 by Temp2 27 March 2006
*/

#include "Common.h"

// The DirectDrawSurface interface
hkIDirectDrawSurface7	myIDirectDrawSurface7;//		= 0;

// The DirectDrawSurface
LPDIRECTDRAWSURFACE7	fakeSurface = NULL;

/*** IUnknown methods ***/
HRESULT hkIDirectDraw7::QueryInterface( REFIID riid, LPVOID FAR * ppvObj )
{
	AddLog( "hkIDirectDraw7::QueryInterface" );
	return m_pDDraw7->QueryInterface( riid, ppvObj );
}

ULONG hkIDirectDraw7::AddRef( THIS )
{
	AddLog( "hkIDirectDraw7::AddRef" );
	return m_pDDraw7->AddRef( );
}

ULONG hkIDirectDraw7::Release( THIS )
{
	AddLog( "hkIDirectDraw7::Release" );
	return m_pDDraw7->Release( );
}

/*** IDirectDraw methods ***/
HRESULT hkIDirectDraw7::Compact(THIS)
{
	AddLog( "hkIDirectDraw7::Compact" );
	return m_pDDraw7->Compact( );
}

HRESULT hkIDirectDraw7::CreateClipper(THIS_ DWORD dwUnknown, LPDIRECTDRAWCLIPPER FAR* lpClipper, IUnknown FAR * lpUnknown )
{
	AddLog( "hkIDirectDraw7::CreateClipper" );
	return m_pDDraw7->CreateClipper( dwUnknown, lpClipper, lpUnknown );
}

HRESULT hkIDirectDraw7::CreatePalette(THIS_ DWORD dwUnknown, LPPALETTEENTRY lpPaletteEntry, LPDIRECTDRAWPALETTE FAR* lpDDPalette, IUnknown FAR * lpUnknown )
{
	AddLog( "hkIDirectDraw7::CreatePalette" );
	return m_pDDraw7->CreatePalette( dwUnknown, lpPaletteEntry, lpDDPalette, lpUnknown );
}

HRESULT hkIDirectDraw7::CreateSurface(THIS_  LPDDSURFACEDESC2 lpDDSurfaceDesc, LPDIRECTDRAWSURFACE7 FAR * lpDDSurface, IUnknown FAR * lpUnknown )
{
	HRESULT hRes = m_pDDraw7->CreateSurface(lpDDSurfaceDesc, lpDDSurface, lpUnknown);
    if(hRes == DD_OK) myIDirectDrawSurface7.SetupHook(lpDDSurface);
	AddLog( "hkIDirectDraw7::CreateSurface" );
	return(hRes);
	/*
	AddLog( "hkIDirectDraw7::CreateSurface" );
	return m_pDDraw7->CreateSurface(lpDDSurfaceDesc, lpDDSurface,lpUnknown );
	*/
}

HRESULT hkIDirectDraw7::DuplicateSurface( THIS_ LPDIRECTDRAWSURFACE7 DDSurface, LPDIRECTDRAWSURFACE7 FAR * lpDDSurface)
{
	AddLog( "hkIDirectDraw7::DuplicateSurface" );
	return m_pDDraw7->DuplicateSurface( DDSurface, lpDDSurface );
}

HRESULT hkIDirectDraw7::EnumDisplayModes( THIS_ DWORD dwUnknown, LPDDSURFACEDESC2 lpDDSurfaceDesc, LPVOID lpVoidUnknown, LPDDENUMMODESCALLBACK2 lpEnumCallback )
{
	AddLog( "hkIDirectDraw7::EnumDisplayModes" );
	return m_pDDraw7->EnumDisplayModes( dwUnknown, lpDDSurfaceDesc, lpVoidUnknown, lpEnumCallback );
}

HRESULT hkIDirectDraw7::EnumSurfaces(THIS_ DWORD dwUnknown, LPDDSURFACEDESC2 lpDDSurfaceDesc, LPVOID lpVoidUnknown, LPDDENUMSURFACESCALLBACK7 lpSurfaceCallback )
{
	AddLog( "hkIDirectDraw7::EnumSurfaces" );
	return m_pDDraw7->EnumSurfaces( dwUnknown, lpDDSurfaceDesc, lpVoidUnknown, lpSurfaceCallback );
}

HRESULT hkIDirectDraw7::FlipToGDISurface(THIS)
{
	AddLog( "hkIDirectDraw7::FlipToGDISurface" );
	return m_pDDraw7->FlipToGDISurface( );
}

HRESULT hkIDirectDraw7::GetCaps( THIS_ LPDDCAPS lpddCaps, LPDDCAPS lpddCaps2 )
{
	AddLog( "hkIDirectDraw7::GetCaps" );
	return m_pDDraw7->GetCaps( lpddCaps, lpddCaps2 );
}

HRESULT hkIDirectDraw7::GetDisplayMode( THIS_ LPDDSURFACEDESC2 lpDDSurfaceDesc )
{
	AddLog( "hkIDirectDraw7::GetDisplayMode" );
	return m_pDDraw7->GetDisplayMode( lpDDSurfaceDesc );
}

HRESULT hkIDirectDraw7::GetFourCCCodes(THIS_ LPDWORD lpdwUnknown1, LPDWORD lpdwUnknown2 )
{
	AddLog( "hkIDirectDraw7::GetFourCCCodes" );
	return m_pDDraw7->GetFourCCCodes( lpdwUnknown1, lpdwUnknown2 );
}

HRESULT hkIDirectDraw7::GetGDISurface(THIS_ LPDIRECTDRAWSURFACE7 FAR * lpddSurface )
{
	AddLog( "hkIDirectDraw7::GetGDISurface(" );
	return m_pDDraw7->GetGDISurface( lpddSurface );
}

HRESULT hkIDirectDraw7::GetMonitorFrequency(THIS_ LPDWORD lpdwFrequency )
{
	AddLog( "hkIDirectDraw7::GetMonitorFrequency" );
	return m_pDDraw7->GetMonitorFrequency( lpdwFrequency );
}

HRESULT hkIDirectDraw7::GetScanLine(THIS_ LPDWORD lpdwScanline )
{
	AddLog( "hkIDirectDraw7::GetScanLine" );
	return m_pDDraw7->GetScanLine( lpdwScanline );
}

HRESULT hkIDirectDraw7::GetVerticalBlankStatus(THIS_ LPBOOL lpValue )
{
	AddLog( "hkIDirectDraw7::GetVerticalBlankStatus" );
	return m_pDDraw7->GetVerticalBlankStatus( lpValue );
}

HRESULT hkIDirectDraw7::Initialize(THIS_ GUID FAR * lpGuid )
{
	AddLog( "hkIDirectDraw7::Initialize" );
	return m_pDDraw7->Initialize( lpGuid );
}

HRESULT hkIDirectDraw7::RestoreDisplayMode(THIS)
{
	AddLog( "hkIDirectDraw7::RestoreDisplayMode" );
	return m_pDDraw7->RestoreDisplayMode( );
}

HRESULT hkIDirectDraw7::SetCooperativeLevel(THIS_ HWND hwnd, DWORD dwMode )
{
	AddLog( "hkIDirectDraw7::SetCooperativeLevel" );
	AddLog( "\thwnd = 0x%08X dwMode = %i", hwnd, dwMode );
	return m_pDDraw7->SetCooperativeLevel( hwnd, dwMode );
}

HRESULT hkIDirectDraw7::SetDisplayMode(THIS_ DWORD dwOne, DWORD dwTwo, DWORD dwThree, DWORD dwFour, DWORD dwFive )
{
	AddLog( "hkIDirectDraw7::SetDisplayMode" );
	return m_pDDraw7->SetDisplayMode( dwOne, dwTwo, dwThree, dwFour, dwFive );
}

HRESULT hkIDirectDraw7::WaitForVerticalBlank(THIS_ DWORD dwUnknown, HANDLE hHandle )
{
	AddLog( "hkIDirectDraw7::WaitForVerticalBlank" );
	return m_pDDraw7->WaitForVerticalBlank( dwUnknown, hHandle );
}

/*** Added in the v2 interface ***/
HRESULT hkIDirectDraw7::GetAvailableVidMem( THIS_ LPDDSCAPS2 lpDDCaps2, LPDWORD lpdwUnknown1, LPDWORD lpdwUnknown2 )
{
	AddLog( "hkIDirectDraw7::GetAvailableVidMem" );
	return m_pDDraw7->GetAvailableVidMem( lpDDCaps2, lpdwUnknown1, lpdwUnknown2 );
}

/*** Added in the V4 Interface ***/
HRESULT hkIDirectDraw7::GetSurfaceFromDC(THIS_ HDC hDC, LPDIRECTDRAWSURFACE7 * lpddSurface7 )
{
	AddLog( "hkIDirectDraw7::GetSurfaceFromDC" );
	return m_pDDraw7->GetSurfaceFromDC( hDC, lpddSurface7 );
}

HRESULT hkIDirectDraw7::RestoreAllSurfaces(THIS)
{
	AddLog( "hkIDirectDraw7::RestoreAllSurfaces" );
	return m_pDDraw7->RestoreAllSurfaces( );
}

HRESULT hkIDirectDraw7::TestCooperativeLevel(THIS)
{
	AddLog( "hkIDirectDraw7::TestCooperativeLevel" );
	return m_pDDraw7->TestCooperativeLevel( );
}

HRESULT hkIDirectDraw7::GetDeviceIdentifier(THIS_ LPDDDEVICEIDENTIFIER2 lpDeviceIdentifier, DWORD dwUnknown )
{
	AddLog( "hkIDirectDraw7::GetDeviceIdentifier" );
	return m_pDDraw7->GetDeviceIdentifier( lpDeviceIdentifier, dwUnknown );
}

HRESULT hkIDirectDraw7::StartModeTest(THIS_ LPSIZE lpModesToTest, DWORD dwNumEntries, DWORD  dwFlags)
{
	AddLog( "hkIDirectDraw7::StartModeTest" );
	return m_pDDraw7->StartModeTest(lpModesToTest, dwNumEntries, dwFlags);
}

HRESULT hkIDirectDraw7::EvaluateMode(THIS_ DWORD  dwFlags, DWORD  *pSecondsUntilTimeout)
{
	AddLog( "hkIDirectDraw7::EvaluateMode" );
	return m_pDDraw7->EvaluateMode( dwFlags, pSecondsUntilTimeout );
}

