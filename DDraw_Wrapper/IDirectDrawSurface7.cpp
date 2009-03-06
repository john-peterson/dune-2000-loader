/*
Direct Draw Wrapper
by 2ci-
http://2ci.elitecoders.org
http://www.elitecoders.org
www.game-deception.com
Converted from Direct Draw 4 to 7 by Temp2 27 March 2006
*/

#include "Common.h"
/*** IUnknown methods ***/
HRESULT hkIDirectDrawSurface7::QueryInterface(THIS_ REFIID riid, LPVOID FAR * ppvObj)
{
	AddLog( "hkIDirectDrawSurface7::QueryInterface" );
	return m_pDDrawSurface7->QueryInterface( riid, ppvObj );
}

ULONG hkIDirectDrawSurface7::AddRef(THIS)
{
	AddLog( "hkIDirectDrawSurface7::AddRef" );
	return m_pDDrawSurface7->AddRef( );
}

ULONG hkIDirectDrawSurface7::Release(THIS)
{
	AddLog( "hkIDirectDrawSurface7::Release" );
	return m_pDDrawSurface7->Release( );
}

/*** IDirectDrawSurface methods ***/
HRESULT hkIDirectDrawSurface7::AddAttachedSurface(THIS_ LPDIRECTDRAWSURFACE7 lpdd7Surface )
{
	AddLog( "hkIDirectDrawSurface7::AddAttachedSurface" );
	return m_pDDrawSurface7->AddAttachedSurface( lpdd7Surface );
}

HRESULT hkIDirectDrawSurface7::AddOverlayDirtyRect(THIS_ LPRECT lpRect )
{
	AddLog( "hkIDirectDrawSurface7::AddOverlayDirtyRect" );
	return m_pDDrawSurface7->AddOverlayDirtyRect( lpRect );
}

HRESULT hkIDirectDrawSurface7::Blt(THIS_ LPRECT lpRect, LPDIRECTDRAWSURFACE7 lpdd7Surface, LPRECT lpRect2 ,DWORD dwUnknown, LPDDBLTFX lpDD )
{
	AddLog( "hkIDirectDrawSurface7::Blt" );
	return m_pDDrawSurface7->Blt( lpRect, lpdd7Surface, lpRect2,dwUnknown, lpDD );
}

HRESULT hkIDirectDrawSurface7::BltBatch(THIS_ LPDDBLTBATCH lpBltBatch, DWORD dwOne, DWORD dwTwo )
{
	AddLog( "hkIDirectDrawSurface7::BltBatch" );
	return m_pDDrawSurface7->BltBatch( lpBltBatch, dwOne, dwTwo );
}

HRESULT hkIDirectDrawSurface7::BltFast(THIS_ DWORD dwOne, DWORD dwTwo, LPDIRECTDRAWSURFACE7 lpddSurface7, LPRECT lpRect, DWORD dwThree )
{
	AddLog( "hkIDirectDrawSurface7::BltFast" );
	return m_pDDrawSurface7->BltFast( dwOne, dwTwo, lpddSurface7, lpRect, dwThree );
}

HRESULT hkIDirectDrawSurface7::DeleteAttachedSurface(THIS_ DWORD dwOne, LPDIRECTDRAWSURFACE7 lpddSurface7 )
{
	AddLog( "hkIDirectDrawSurface7::DeleteAttachedSurface" );
	return m_pDDrawSurface7->DeleteAttachedSurface( dwOne, lpddSurface7 );
}

HRESULT hkIDirectDrawSurface7::EnumAttachedSurfaces(THIS_ LPVOID lpUnknown, LPDDENUMSURFACESCALLBACK7 lpdd2Callback )
{
	AddLog( "hkIDirectDrawSurface7::EnumAttachedSurfaces" );
	return m_pDDrawSurface7->EnumAttachedSurfaces( lpUnknown, lpdd2Callback );
}

HRESULT hkIDirectDrawSurface7::EnumOverlayZOrders(THIS_ DWORD dwOne, LPVOID lpUnknown, LPDDENUMSURFACESCALLBACK7 lpdd2Callback)
{
	AddLog( "hkIDirectDrawSurface7::EnumOverlayZOrders" );
	return m_pDDrawSurface7->EnumOverlayZOrders( dwOne, lpUnknown, lpdd2Callback );
}

HRESULT hkIDirectDrawSurface7::Flip(THIS_ LPDIRECTDRAWSURFACE7 lpddSurface7, DWORD dwOne )
{
	AddLog( "hkIDirectDrawSurface7::Flip" );
	return m_pDDrawSurface7->Flip( lpddSurface7, dwOne );
}

HRESULT hkIDirectDrawSurface7::GetAttachedSurface(THIS_ LPDDSCAPS2 lpddCaps2 , LPDIRECTDRAWSURFACE7 FAR * lplpddSurface7 )
{
	AddLog( "hkIDirectDrawSurface7::GetAttachedSurface" );
	return m_pDDrawSurface7->GetAttachedSurface( lpddCaps2, lplpddSurface7 );
}

HRESULT hkIDirectDrawSurface7::GetBltStatus(THIS_ DWORD dwStatus )
{
	AddLog( "hkIDirectDrawSurface7::GetBltStatus" );
	return m_pDDrawSurface7->GetBltStatus( dwStatus );
}

HRESULT hkIDirectDrawSurface7::GetCaps(THIS_ LPDDSCAPS2 lpddCaps2)
{
	AddLog( "hkIDirectDrawSurface7::GetCaps" );
	return m_pDDrawSurface7->GetCaps( lpddCaps2 );
}

HRESULT hkIDirectDrawSurface7::GetClipper(THIS_ LPDIRECTDRAWCLIPPER FAR* lplpddrawClipper )
{
	AddLog( "hkIDirectDrawSurface7::GetClipper" );
	return m_pDDrawSurface7->GetClipper( lplpddrawClipper );
}

HRESULT hkIDirectDrawSurface7::GetColorKey(THIS_ DWORD dwOne, LPDDCOLORKEY lpddColor)
{
	AddLog( "hkIDirectDrawSurface7::GetColorKey" );
	return m_pDDrawSurface7->GetColorKey( dwOne, lpddColor );
}

HRESULT hkIDirectDrawSurface7::GetDC(THIS_ HDC FAR * lpHdc )
{
	AddLog( "hkIDirectDrawSurface7::GetDC" );
	return m_pDDrawSurface7->GetDC( lpHdc );
}

HRESULT hkIDirectDrawSurface7::GetFlipStatus(THIS_ DWORD dwStatus )
{
	AddLog( "hkIDirectDrawSurface7::GetFlipStatus" );
	return m_pDDrawSurface7->GetFlipStatus( dwStatus );
}

HRESULT hkIDirectDrawSurface7::GetOverlayPosition(THIS_ LPLONG lpX, LPLONG lpY)
{
	AddLog( "hkIDirectDrawSurface7::GetOverlayPosition" );
	return m_pDDrawSurface7->GetOverlayPosition( lpX, lpY );
}

HRESULT hkIDirectDrawSurface7::GetPalette(THIS_ LPDIRECTDRAWPALETTE FAR* lplpddPalette )
{
	AddLog( "hkIDirectDrawSurface7::GetPalette" );
	return m_pDDrawSurface7->GetPalette( lplpddPalette );
}

HRESULT hkIDirectDrawSurface7::GetPixelFormat(THIS_ LPDDPIXELFORMAT lpPixelFormat )
{
	AddLog( "hkIDirectDrawSurface7::GetPixelFormat" );
	return m_pDDrawSurface7->GetPixelFormat( lpPixelFormat );
}

HRESULT hkIDirectDrawSurface7::GetSurfaceDesc(THIS_ LPDDSURFACEDESC2 lpddSurfaceDesc2 )
{
	AddLog( "hkIDirectDrawSurface7::GetSurfaceDesc" );
	return m_pDDrawSurface7->GetSurfaceDesc( lpddSurfaceDesc2 );
}

HRESULT hkIDirectDrawSurface7::Initialize(THIS_ LPDIRECTDRAW lpddraw, LPDDSURFACEDESC2 lpddSurfaceDesc2 )
{
	AddLog( "hkIDirectDrawSurface7::Initialize" );
	return m_pDDrawSurface7->Initialize( lpddraw, lpddSurfaceDesc2 );
}

HRESULT hkIDirectDrawSurface7::IsLost(THIS)
{
	AddLog( "hkIDirectDrawSurface7::IsLost" );
	return m_pDDrawSurface7->IsLost( );
}

HRESULT hkIDirectDrawSurface7::Lock(THIS_ LPRECT lpRect, LPDDSURFACEDESC2 lpddSurfaceDesc2, DWORD dwOne, HANDLE hHandle )
{
	AddLog( "hkIDirectDrawSurface7::Lock" );
	return m_pDDrawSurface7->Lock(THIS_ lpRect, lpddSurfaceDesc2, dwOne, hHandle );
}

HRESULT hkIDirectDrawSurface7::ReleaseDC(THIS_ HDC hDC )
{
	AddLog( "hkIDirectDrawSurface7::ReleaseDC" );
	return m_pDDrawSurface7->ReleaseDC( hDC );
}

HRESULT hkIDirectDrawSurface7::Restore(THIS)
{
	AddLog( "hkIDirectDrawSurface7::Restore" );
	return m_pDDrawSurface7->Restore( );
}

HRESULT hkIDirectDrawSurface7::SetClipper(THIS_ LPDIRECTDRAWCLIPPER lpddrawClipper )
{
	AddLog( "hkIDirectDrawSurface7::SetClipper" );
	return m_pDDrawSurface7->SetClipper( lpddrawClipper );
}

HRESULT hkIDirectDrawSurface7::SetColorKey(THIS_ DWORD dwOne, LPDDCOLORKEY lpColorKey )
{
	AddLog( "hkIDirectDrawSurface7::SetColorKey" );
	return m_pDDrawSurface7->SetColorKey( dwOne, lpColorKey );
}


HRESULT hkIDirectDrawSurface7::SetOverlayPosition(THIS_ LONG lgX, LONG lgY)
{
	AddLog( "hkIDirectDrawSurface7::SetOverlayPosition" );
	return m_pDDrawSurface7->SetOverlayPosition( lgX, lgY );
}

HRESULT hkIDirectDrawSurface7::SetPalette(THIS_ LPDIRECTDRAWPALETTE lpddPalette )
{
	AddLog( "hkIDirectDrawSurface7::SetPalette" );
	return m_pDDrawSurface7->SetPalette( lpddPalette );
}

HRESULT hkIDirectDrawSurface7::Unlock(THIS_ LPRECT lpRect )
{
	AddLog( "hkIDirectDrawSurface7::Unlock" );
	return m_pDDrawSurface7->Unlock( lpRect );
}

HRESULT hkIDirectDrawSurface7::UpdateOverlay(THIS_ LPRECT lpRect, LPDIRECTDRAWSURFACE7 lpdd7Surface, LPRECT lpRect2, DWORD dwOne, LPDDOVERLAYFX lpddOverlayFx )
{
	AddLog( "hkIDirectDrawSurface7::UpdateOverlay" );
	return m_pDDrawSurface7->UpdateOverlay( lpRect, lpdd7Surface, lpRect2, dwOne, lpddOverlayFx);
}

HRESULT hkIDirectDrawSurface7::UpdateOverlayDisplay(THIS_ DWORD dwOne )
{
	AddLog( "hkIDirectDrawSurface7::UpdateOverlayDisplay" );
	return m_pDDrawSurface7->UpdateOverlayDisplay( dwOne );
}

HRESULT hkIDirectDrawSurface7::UpdateOverlayZOrder(THIS_ DWORD dwOne, LPDIRECTDRAWSURFACE7 lpdd7Surface )
{
	AddLog( "hkIDirectDrawSurface7::UpdateOverlayZOrder" );
	return m_pDDrawSurface7->UpdateOverlayZOrder( dwOne, lpdd7Surface );
}

/*** Added in the v2 interface ***/

HRESULT hkIDirectDrawSurface7::GetDDInterface(THIS_ LPVOID FAR * lplpVoid )
{
	AddLog( "hkIDirectDrawSurface7::GetDDInterface" );
	return m_pDDrawSurface7->GetDDInterface( lplpVoid );
}


HRESULT hkIDirectDrawSurface7::PageLock(THIS_ DWORD dwOne )
{
	AddLog( "hkIDirectDrawSurface7::PageLock" );
	return m_pDDrawSurface7->PageLock( dwOne );
}

HRESULT hkIDirectDrawSurface7::PageUnlock(THIS_ DWORD dwOne)
{
	AddLog( "hkIDirectDrawSurface7::PageUnlock" );
	return m_pDDrawSurface7->PageUnlock( dwOne );
}


/*** Added in the v3 interface ***/
HRESULT hkIDirectDrawSurface7::SetSurfaceDesc(THIS_ LPDDSURFACEDESC2 lpddSurfaceDesc2, DWORD dwOne )
{
	AddLog( "hkIDirectDrawSurface7::SetSurfaceDesc" );
	return m_pDDrawSurface7->SetSurfaceDesc( lpddSurfaceDesc2, dwOne );
}

/*** Added in the v4 interface ***/
HRESULT hkIDirectDrawSurface7::SetPrivateData(THIS_ REFGUID refGuid, LPVOID lpUnknown, DWORD dwOne, DWORD dwTwo )
{
	AddLog( "hkIDirectDrawSurface7::SetPrivateData" );
	return m_pDDrawSurface7->SetPrivateData( refGuid, lpUnknown, dwOne, dwTwo );
}


HRESULT hkIDirectDrawSurface7::GetPrivateData(THIS_ REFGUID refGuid, LPVOID lpUnknown, LPDWORD lpdwOne )
{
	AddLog( "hkIDirectDrawSurface7::GetPrivateData" );
	return m_pDDrawSurface7->GetPrivateData( refGuid, lpUnknown, lpdwOne );
}

HRESULT hkIDirectDrawSurface7::FreePrivateData(THIS_ REFGUID refGuid )
{
	AddLog( "hkIDirectDrawSurface7::FreePrivateData" );
	return m_pDDrawSurface7->FreePrivateData( refGuid );
}

HRESULT hkIDirectDrawSurface7::GetUniquenessValue(THIS_ LPDWORD lpdwOne )
{
	AddLog( "hkIDirectDrawSurface7::GetUniquenessValue" );
	return m_pDDrawSurface7->GetUniquenessValue( lpdwOne );
}

HRESULT hkIDirectDrawSurface7::ChangeUniquenessValue(THIS)
{
	AddLog( "hkIDirectDrawSurface7::ChangeUniquenessValue" );
	return m_pDDrawSurface7->ChangeUniquenessValue( );
}

HRESULT hkIDirectDrawSurface7::SetPriority(THIS_ DWORD dwPriority)
{
	AddLog( "hkIDirectDrawSurface7::SetPriority" );
	return m_pDDrawSurface7->SetPriority(dwPriority);
}
HRESULT hkIDirectDrawSurface7::GetPriority(THIS_ LPDWORD lpdwPriority)
{
	AddLog( "hkIDirectDrawSurface7::GetPriority" );
	return m_pDDrawSurface7->GetPriority(lpdwPriority);
}
HRESULT hkIDirectDrawSurface7::SetLOD(THIS_ DWORD dwMaxLOD)
{
	AddLog( "hkIDirectDrawSurface7::SetLOD" );
	return m_pDDrawSurface7->SetLOD(dwMaxLOD);
}
HRESULT hkIDirectDrawSurface7::GetLOD(THIS_ LPDWORD lpdwMaxLOD)
{
	AddLog( "hkIDirectDrawSurface7::GetLOD" );
	return m_pDDrawSurface7->GetLOD(lpdwMaxLOD);
}


