/*
Dune 2000 Launcher



This file is part of Dune 2000 Launcher.

Dune 2000 Launcher is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, version 3.

Dune 2000 Launcher is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Dune 2000 Launcher.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "ddraw4_hooks.h"
#include "d3d_hooks.h"
#include "d3d3_hooks.h"
#include "ddrawsurface4_hooks.h"
#include <map>

#ifdef FF8_WINDOWED
HWND g_hwnd = NULL;
LPDIRECTDRAWSURFACE4 g_frontbuffer = NULL;
LPDIRECTDRAWSURFACE4 g_backbuffer = NULL;
#endif

//{ NULL, 0, NULL, NULL },	//
#ifdef _DEBUG
SVTBL_HOOK ddraw4_hooks[] = {
/*0*/	{ "QueryInterface",			0x00, NULL, (PDWORD)DDRAW4_HOOK_QueryInterface },
/*1*/	{ "AddRef",					0x04, NULL, (PDWORD)DDRAW4_HOOK_AddRef },
/*2*/	{ "Release",				0x08, NULL, (PDWORD)DDRAW4_HOOK_Release },
/*3*/	{ "Compact",				0x0C, NULL, (PDWORD)DDRAW4_HOOK_Compact },
/*4*/	{ "CreateClipper",			0x10, NULL, (PDWORD)DDRAW4_HOOK_CreateClipper },
/*5*/	{ "CreatePalette",			0x14, NULL, (PDWORD)DDRAW4_HOOK_CreatePalette },
/*6*/	{ "CreateSurface",			0x18, NULL, (PDWORD)DDRAW4_HOOK_CreateSurface },
/*7*/	{ "DuplicateSurface",		0x1C, NULL, (PDWORD)DDRAW4_HOOK_DuplicateSurface },
/*8*/	{ "EnumDisplayModes",		0x20, NULL, (PDWORD)DDRAW4_HOOK_EnumDisplayModes },
/*9*/	{ "EnumSurfaces",			0x24, NULL, (PDWORD)DDRAW4_HOOK_EnumSurfaces },
/*10*/	{ "FlipToGDISurface",		0x28, NULL, (PDWORD)DDRAW4_HOOK_FlipToGDISurface },
/*11*/	{ "GetCaps",				0x2C, NULL, (PDWORD)DDRAW4_HOOK_GetCaps },
/*12*/	{ "GetDisplayMode",			0x30, NULL, (PDWORD)DDRAW4_HOOK_GetDisplayMode },
/*13*/	{ "GetFourCCCodes",			0x34, NULL, (PDWORD)DDRAW4_HOOK_GetFourCCCodes },
/*14*/	{ "GetGDISurface",			0x38, NULL, (PDWORD)DDRAW4_HOOK_GetGDISurface },
/*15*/	{ "GetMonitorFrequency",	0x3C, NULL, (PDWORD)DDRAW4_HOOK_GetMonitorFrequency },
/*16*/	{ "GetScanLine",			0x40, NULL, (PDWORD)DDRAW4_HOOK_GetScanLine },
/*17*/	{ "GetVerticalBlankStatus",	0x44, NULL, (PDWORD)DDRAW4_HOOK_GetVerticalBlankStatus },
/*18*/	{ "Initialize",				0x48, NULL, (PDWORD)DDRAW4_HOOK_Initialize },
/*19*/	{ "RestoreDisplayMode",		0x4C, NULL, (PDWORD)DDRAW4_HOOK_RestoreDisplayMode },
/*20*/	{ "SetCooperativeLevel",	0x50, NULL, (PDWORD)DDRAW4_HOOK_SetCooperativeLevel },
/*21*/	{ "SetDisplayMode",			0x54, NULL, (PDWORD)DDRAW4_HOOK_SetDisplayMode },
/*22*/	{ "WaitForVerticalBlank",	0x58, NULL, (PDWORD)DDRAW4_HOOK_WaitForVerticalBlank },
/*23*/	{ "GetAvailableVidMem",		0x5C, NULL, (PDWORD)DDRAW4_HOOK_GetAvailableVidMem },
/*24*/	{ "GetSurfaceFromDC",		0x60, NULL, (PDWORD)DDRAW4_HOOK_GetSurfaceFromDC },
/*25*/	{ "RestoreAllSurfaces",		0x64, NULL, (PDWORD)DDRAW4_HOOK_RestoreAllSurfaces },
/*26*/	{ "TestCooperativeLevel",	0x68, NULL, (PDWORD)DDRAW4_HOOK_TestCooperativeLevel },
/*27*/	{ "GetDeviceIdentifier",	0x6C, NULL, (PDWORD)DDRAW4_HOOK_GetDeviceIdentifier }
};
#else
SVTBL_HOOK ddraw4_hooks[] = {
/*0*/	{ "QueryInterface",			0x00, NULL, (PDWORD)DDRAW4_HOOK_QueryInterface },
/*1*/	{ NULL, 0, NULL, NULL },	//{ "AddRef",					0x04, NULL, (PDWORD)DDRAW4_HOOK_AddRef },
/*2*/	{ NULL, 0, NULL, NULL },	//{ "Release",				0x08, NULL, (PDWORD)DDRAW4_HOOK_Release },
/*3*/	{ NULL, 0, NULL, NULL },	//{ "Compact",				0x0C, NULL, (PDWORD)DDRAW4_HOOK_Compact },
/*4*/	{ NULL, 0, NULL, NULL },	//{ "CreateClipper",			0x10, NULL, (PDWORD)DDRAW4_HOOK_CreateClipper },
/*5*/	{ NULL, 0, NULL, NULL },	//{ "CreatePalette",			0x14, NULL, (PDWORD)DDRAW4_HOOK_CreatePalette },
/*6*/	{ "CreateSurface",			0x18, NULL, (PDWORD)DDRAW4_HOOK_CreateSurface },
/*7*/	{ NULL, 0, NULL, NULL },	//{ "DuplicateSurface",		0x1C, NULL, (PDWORD)DDRAW4_HOOK_DuplicateSurface },
/*8*/	{ NULL, 0, NULL, NULL },	//{ "EnumDisplayModes",		0x20, NULL, (PDWORD)DDRAW4_HOOK_EnumDisplayModes },
/*9*/	{ NULL, 0, NULL, NULL },	//{ "EnumSurfaces",			0x24, NULL, (PDWORD)DDRAW4_HOOK_EnumSurfaces },
/*10*/	{ NULL, 0, NULL, NULL },	//{ "FlipToGDISurface",		0x28, NULL, (PDWORD)DDRAW4_HOOK_FlipToGDISurface },
/*11*/	{ NULL, 0, NULL, NULL },	//{ "GetCaps",				0x2C, NULL, (PDWORD)DDRAW4_HOOK_GetCaps },
/*12*/	{ NULL, 0, NULL, NULL },	//{ "GetDisplayMode",			0x30, NULL, (PDWORD)DDRAW4_HOOK_GetDisplayMode },
/*13*/	{ NULL, 0, NULL, NULL },	//{ "GetFourCCCodes",			0x34, NULL, (PDWORD)DDRAW4_HOOK_GetFourCCCodes },
/*14*/	{ NULL, 0, NULL, NULL },	//{ "GetGDISurface",			0x38, NULL, (PDWORD)DDRAW4_HOOK_GetGDISurface },
/*15*/	{ NULL, 0, NULL, NULL },	//{ "GetMonitorFrequency",	0x3C, NULL, (PDWORD)DDRAW4_HOOK_GetMonitorFrequency },
/*16*/	{ NULL, 0, NULL, NULL },	//{ "GetScanLine",			0x40, NULL, (PDWORD)DDRAW4_HOOK_GetScanLine },
/*17*/	{ NULL, 0, NULL, NULL },	//{ "GetVerticalBlankStatus",	0x44, NULL, (PDWORD)DDRAW4_HOOK_GetVerticalBlankStatus },
/*18*/	{ NULL, 0, NULL, NULL },	//{ "Initialize",				0x48, NULL, (PDWORD)DDRAW4_HOOK_Initialize },
/*19*/	{ NULL, 0, NULL, NULL },	//{ "RestoreDisplayMode",		0x4C, NULL, (PDWORD)DDRAW4_HOOK_RestoreDisplayMode },
/*20*/	{ "SetCooperativeLevel",	0x50, NULL, (PDWORD)DDRAW4_HOOK_SetCooperativeLevel },
/*21*/	{ "SetDisplayMode",			0x54, NULL, (PDWORD)DDRAW4_HOOK_SetDisplayMode },
/*22*/	{ NULL, 0, NULL, NULL },	//{ "WaitForVerticalBlank",	0x58, NULL, (PDWORD)DDRAW4_HOOK_WaitForVerticalBlank },
/*23*/	{ NULL, 0, NULL, NULL },	//{ "GetAvailableVidMem",		0x5C, NULL, (PDWORD)DDRAW4_HOOK_GetAvailableVidMem },
/*24*/	{ NULL, 0, NULL, NULL },	//{ "GetSurfaceFromDC",		0x60, NULL, (PDWORD)DDRAW4_HOOK_GetSurfaceFromDC },
/*25*/	{ NULL, 0, NULL, NULL },	//{ "RestoreAllSurfaces",		0x64, NULL, (PDWORD)DDRAW4_HOOK_RestoreAllSurfaces },
/*26*/	{ NULL, 0, NULL, NULL },	//{ "TestCooperativeLevel",	0x68, NULL, (PDWORD)DDRAW4_HOOK_TestCooperativeLevel },
/*27*/	{ NULL, 0, NULL, NULL },	//{ "GetDeviceIdentifier",	0x6C, NULL, (PDWORD)DDRAW4_HOOK_GetDeviceIdentifier }
};
#endif
const unsigned int count_ddraw4_hooks = 28;
bool ishooked_ddraw4_hooks = false;


HRESULT __stdcall DDRAW4_HOOK_QueryInterface(LPVOID *ppvOut, REFIID riid, LPVOID FAR *ppvObj)
{
	const unsigned int hpos = 0;

	DDRAW4_QueryInterface_Type ofn = (DDRAW4_QueryInterface_Type)ddraw4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, riid, ppvObj);
	LogDXError(ret);

	Log("IDirectDraw4::%s(%#010lx, { %#010lx, %#06x, %#06x, { %#04x, %#04x, %#04x, %#04x, %#04x, %#04x, %#04x, %#04x } }, %#010lx)\n", ddraw4_hooks[hpos].name, ppvOut, riid.Data1, riid.Data2, riid.Data3, riid.Data4[0], riid.Data4[1], riid.Data4[2], riid.Data4[3], riid.Data4[4], riid.Data4[5], riid.Data4[6], riid.Data4[7], ppvObj);
	if(ret == S_OK)
	{
		if(riid == IID_IDirect3D && ishooked_d3d_hooks == false)
		{
			HookVTBLCalls(ppvObj, d3d_hooks, count_d3d_hooks, "IDirect3D");
			ishooked_d3d_hooks = true;
		}
		else if(riid == IID_IDirect3D3 && ishooked_d3d3_hooks == false)
		{
			HookVTBLCalls(ppvObj, d3d3_hooks, count_d3d3_hooks, "IDirect3D3");
			ishooked_d3d3_hooks = true;
		}
	}

	return ret;
}


ULONG __stdcall DDRAW4_HOOK_AddRef(LPVOID *ppvOut)
{
	const unsigned int hpos = 1;

	DDRAW4_AddRef_Type ofn = (DDRAW4_AddRef_Type)ddraw4_hooks[hpos].oldFunc;
	ULONG ret = ofn(ppvOut);

	Log("IDirectDraw4::%s(this=%#010lx) return %d;\n", ddraw4_hooks[hpos].name, ppvOut, ret);

	return ret;
}

ULONG __stdcall DDRAW4_HOOK_Release(LPVOID *ppvOut)
{
	const unsigned int hpos = 2;

	DDRAW4_Release_Type ofn = (DDRAW4_Release_Type)ddraw4_hooks[hpos].oldFunc;
	ULONG ret = ofn(ppvOut);

	Log("IDirectDraw4::%s(this=%#010lx) return %d;\n", ddraw4_hooks[hpos].name, ppvOut, ret);

	return ret;
}

HRESULT __stdcall DDRAW4_HOOK_Compact(LPVOID *ppvOut)
{
	const unsigned int hpos = 3;

	//not implemented in ddraw4
	return (HRESULT)0;
}

HRESULT __stdcall DDRAW4_HOOK_CreateClipper(LPVOID *ppvOut, DWORD dwFlags, LPDIRECTDRAWCLIPPER FAR *lplpDDClipper, IUnknown FAR *pUnkOuter)
{
	const unsigned int hpos = 4;

	DDRAW4_CreateClipper_Type ofn = (DDRAW4_CreateClipper_Type)ddraw4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwFlags, lplpDDClipper, pUnkOuter);
	LogDXError(ret);

	Log("IDirectDraw4::%s()\n", ddraw4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAW4_HOOK_CreatePalette(LPVOID *ppvOut, DWORD dwFlags, LPPALETTEENTRY lpDDColorArray, LPDIRECTDRAWPALETTE FAR *lplpDDPalette, IUnknown FAR *pUnkOuter) {
	const unsigned int hpos = 5;

	DDRAW4_CreatePalette_Type ofn = (DDRAW4_CreatePalette_Type)ddraw4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwFlags, lpDDColorArray, lplpDDPalette, pUnkOuter);
	LogDXError(ret);

	Log("IDirectDraw4::%s()\n", ddraw4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAW4_HOOK_CreateSurface(LPVOID *ppvOut, LPDDSURFACEDESC2 lpDDSurfaceDesc, LPDIRECTDRAWSURFACE4 FAR *lplpDDSurface4, IUnknown FAR *pUnkOuter)
{
	const unsigned int hpos = 6;

	if(g_config.displaymode != 0)
	{
		/*if((void *)lpDDSurfaceDesc == (void *)0x00134518) {
				lpDDSurfaceDesc->dwWidth = displaymode_options[g_config.displaymode].resX;
				lpDDSurfaceDesc->dwHeight = displaymode_options[g_config.displaymode].resY;
		}*/
		if(lpDDSurfaceDesc != NULL && lpDDSurfaceDesc->dwWidth == 640 && lpDDSurfaceDesc->dwHeight == 480) {
				lpDDSurfaceDesc->dwWidth = displaymode_options[g_config.displaymode].resX;
				lpDDSurfaceDesc->dwHeight = displaymode_options[g_config.displaymode].resY;
		}
	}

	// 8-bit Paletted Textures Fix (VISTA Compatible)
	if(g_config.b8_paletted_textures_fix >= 1)
	{
		if(lpDDSurfaceDesc != NULL && (lpDDSurfaceDesc->ddsCaps.dwCaps & (DDSCAPS_ALLOCONLOAD | DDSCAPS_TEXTURE)) == (DDSCAPS_ALLOCONLOAD | DDSCAPS_TEXTURE)) {
			lpDDSurfaceDesc->dwFlags |= DDSD_CKSRCBLT;
			lpDDSurfaceDesc->ddckCKSrcBlt.dwColorSpaceLowValue = 0x000000;
			lpDDSurfaceDesc->ddckCKSrcBlt.dwColorSpaceHighValue = 0x000000;
		}
	}

#ifdef FF8_WINDOWED
	if((void *)lpDDSurfaceDesc == (void *)0x00134658)
	{
		Log("IF[lpDDSurfaceDesc == 0x00134658] THEN\n");
		lpDDSurfaceDesc->dwFlags &= ~(DDSD_BACKBUFFERCOUNT);
		//lpDDSurfaceDesc->dwFlags |= (DDSD_WIDTH | DDSD_HEIGHT);
		lpDDSurfaceDesc->dwWidth = 0;
		lpDDSurfaceDesc->dwHeight = 0;
		lpDDSurfaceDesc->dwBackBufferCount = 0;
		lpDDSurfaceDesc->ddsCaps.dwCaps &= ~(DDSCAPS_COMPLEX | DDSCAPS_FLIP | DDSCAPS_PRIMARYSURFACE );
		lpDDSurfaceDesc->ddsCaps.dwCaps |= (DDSCAPS_PRIMARYSURFACE);
	} /*else if((lpDDSurfaceDesc->ddsCaps.dwCaps & (DDSCAPS_ALLOCONLOAD | DDSCAPS_TEXTURE)) && (lpDDSurfaceDesc->dwFlags & DDSD_PIXELFORMAT) && (lpDDSurfaceDesc->ddpfPixelFormat.dwFlags & DDPF_ALPHAPIXELS) && lpDDSurfaceDesc->ddpfPixelFormat.dwRBitMask == 0x7c00 && lpDDSurfaceDesc->ddpfPixelFormat.dwGBitMask == 0x3e0 && lpDDSurfaceDesc->ddpfPixelFormat.dwBBitMask == 0x1f) {
		lpDDSurfaceDesc->ddpfPixelFormat.dwFlags &= ~(DDPF_ALPHAPIXELS);
		lpDDSurfaceDesc->ddpfPixelFormat.dwRGBAlphaBitMask =
			lpDDSurfaceDesc->ddpfPixelFormat.dwYUVAlphaBitMask =
			lpDDSurfaceDesc->ddpfPixelFormat.dwLuminanceAlphaBitMask = 
			lpDDSurfaceDesc->ddpfPixelFormat.dwRGBZBitMask = 
			lpDDSurfaceDesc->ddpfPixelFormat.dwYUVZBitMask = 0x00;
	//Does not work: Crash in battle swirl
	}*/ /*else if((lpDDSurfaceDesc->ddsCaps.dwCaps & (DDSCAPS_SYSTEMMEMORY | DDSCAPS_TEXTURE)) && (lpDDSurfaceDesc->dwFlags & DDSD_PIXELFORMAT) && (lpDDSurfaceDesc->ddpfPixelFormat.dwFlags & DDPF_ALPHAPIXELS) && lpDDSurfaceDesc->ddpfPixelFormat.dwRGBBitCount == 0x020) {
		lpDDSurfaceDesc->ddpfPixelFormat.dwFlags &= ~(DDPF_ALPHAPIXELS);
		lpDDSurfaceDesc->ddpfPixelFormat.dwRGBBitCount =
			lpDDSurfaceDesc->ddpfPixelFormat.dwYUVBitCount =
			lpDDSurfaceDesc->ddpfPixelFormat.dwZBufferBitDepth =
			lpDDSurfaceDesc->ddpfPixelFormat.dwAlphaBitDepth =
			lpDDSurfaceDesc->ddpfPixelFormat.dwLuminanceBitCount =
			lpDDSurfaceDesc->ddpfPixelFormat.dwBumpBitCount = 0x10;
		lpDDSurfaceDesc->ddpfPixelFormat.dwRBitMask =
			lpDDSurfaceDesc->ddpfPixelFormat.dwYBitMask =
			lpDDSurfaceDesc->ddpfPixelFormat.dwStencilBitDepth =
			lpDDSurfaceDesc->ddpfPixelFormat.dwLuminanceBitMask =
			lpDDSurfaceDesc->ddpfPixelFormat.dwBumpDuBitMask = 0xf800;
		lpDDSurfaceDesc->ddpfPixelFormat.dwGBitMask =
			lpDDSurfaceDesc->ddpfPixelFormat.dwUBitMask =
			lpDDSurfaceDesc->ddpfPixelFormat.dwZBitMask =
			lpDDSurfaceDesc->ddpfPixelFormat.dwBumpDvBitMask = 0x7e0;
		lpDDSurfaceDesc->ddpfPixelFormat.dwBBitMask =
			lpDDSurfaceDesc->ddpfPixelFormat.dwVBitMask =
			lpDDSurfaceDesc->ddpfPixelFormat.dwStencilBitMask =
			lpDDSurfaceDesc->ddpfPixelFormat.dwBumpLuminanceBitMask = 0x1f;
		lpDDSurfaceDesc->ddpfPixelFormat.dwRGBAlphaBitMask =
			lpDDSurfaceDesc->ddpfPixelFormat.dwYUVAlphaBitMask =
			lpDDSurfaceDesc->ddpfPixelFormat.dwLuminanceAlphaBitMask = 
			lpDDSurfaceDesc->ddpfPixelFormat.dwRGBZBitMask = 
			lpDDSurfaceDesc->ddpfPixelFormat.dwYUVZBitMask = 0x00;
	}*/

/*
16BIT
->lpDDSurfaceDesc { dwSize=0x0000007c, dwFlags=0x00001007 (DDSD_CAPS | DDSD_HEIGHT | DDSD_PIXELFORMAT | DDSD_WIDTH), dwWidth=0x00000100 (256), dwHeight=0x00000100 (256), lPitch=0000000000 , dwLinearSize=0000000000, dwBackBufferCount=0000000000, dwMipMapCount=0000000000, dwRefreshRate=0000000000, dwAlphaBitDepth=0000000000, dwReserved=0000000000,
lpSurface=0000000000, ddckCKDestOverlay={ 0000000000, 0000000000 }, ddckCKDestBlt={ 0000000000, 0000000000 }, ddckCKSrcOverlay={ 0000000000, 0000000000 }, ddckCKSrcBlt={ 0000000000, 0000000000 },
ddpfPixelFormat={ dwSize=0x00000020, dwFlags=0x00000040 (DDPF_RGB), dwFourCC=0000000000, dwRGBBitCount=0x00000010, dwYUVBitCount=0x00000010, dwZBufferBitDepth=0x00000010, dwAlphaBitDepth=0x00000010, dwLuminanceBitCount=0x00000010, dwBumpBitCount=0x00000010, dwRBitMask=0x0000f800,
dwYBitMask=0x0000f800, dwStencilBitDepth=0x0000f800, dwLuminanceBitMask=0x0000f800, dwBumpDuBitMask=0x0000f800, dwGBitMask=0x000007e0, dwUBitMask=0x000007e0, dwZBitMask=0x000007e0, dwBumpDvBitMask=0x000007e0, dwBBitMask=0x0000001f, dwVBitMask=0x0000001f, dwStencilBitMask=0x0000001f,
dwBumpLuminanceBitMask=0x0000001f, dwRGBAlphaBitMask=0000000000, dwYUVAlphaBitMask=0000000000, dwLuminanceAlphaBitMask=0000000000, dwRGBZBitMask=0000000000, dwYUVZBitMask=0000000000 },
ddsCaps={ 0x00001800 (DDSCAPS_SYSTEMMEMORY | DDSCAPS_TEXTURE), 0000000000, 0000000000, 0000000000 }, dwTextureStage=0000000000 }

32BIT
->lpDDSurfaceDesc { dwSize=0x0000007c, dwFlags=0x00001007 (DDSD_CAPS | DDSD_HEIGHT | DDSD_PIXELFORMAT | DDSD_WIDTH), dwWidth=0x00000100 (256), dwHeight=0x00000100 (256), lPitch=0000000000 , dwLinearSize=0000000000, dwBackBufferCount=0000000000, dwMipMapCount=0000000000, dwRefreshRate=0000000000, dwAlphaBitDepth=0000000000, dwReserved=0000000000,
lpSurface=0000000000, ddckCKDestOverlay={ 0000000000, 0000000000 }, ddckCKDestBlt={ 0000000000, 0000000000 }, ddckCKSrcOverlay={ 0000000000, 0000000000 }, ddckCKSrcBlt={ 0000000000, 0000000000 },
ddpfPixelFormat={ dwSize=0x00000020, dwFlags=0x00000041 (DDPF_ALPHAPIXELS | DDPF_RGB), dwFourCC=0000000000, dwRGBBitCount=0x00000020, dwYUVBitCount=0x00000020, dwZBufferBitDepth=0x00000020, dwAlphaBitDepth=0x00000020, dwLuminanceBitCount=0x00000020, dwBumpBitCount=0x00000020, dwRBitMask=0x00ff0000,
dwYBitMask=0x00ff0000, dwStencilBitDepth=0x00ff0000, dwLuminanceBitMask=0x00ff0000, dwBumpDuBitMask=0x00ff0000, dwGBitMask=0x0000ff00, dwUBitMask=0x0000ff00, dwZBitMask=0x0000ff00, dwBumpDvBitMask=0x0000ff00, dwBBitMask=0x000000ff, dwVBitMask=0x000000ff, dwStencilBitMask=0x000000ff,
dwBumpLuminanceBitMask=0x000000ff, dwRGBAlphaBitMask=0xff000000, dwYUVAlphaBitMask=0xff000000, dwLuminanceAlphaBitMask=0xff000000, dwRGBZBitMask=0xff000000, dwYUVZBitMask=0xff000000 },
ddsCaps={ 0x00001800 (DDSCAPS_SYSTEMMEMORY | DDSCAPS_TEXTURE), 0000000000, 0000000000, 0000000000 }, dwTextureStage=0000000000 }
*/
#endif

	DDRAW4_CreateSurface_Type ofn = (DDRAW4_CreateSurface_Type)ddraw4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpDDSurfaceDesc, lplpDDSurface4, pUnkOuter);
	LogDXError(ret);
	
	Log("IDirectDraw4::%s(this=%#010lx, lpDDSurfaceDesc=%#010lx, lplpDDSurface=%#010lx *[%#010lx], pUnkOuter=%#010lx)\n", ddraw4_hooks[hpos].name, ppvOut, lpDDSurfaceDesc, lplpDDSurface4, (lplpDDSurface4 != NULL ? *lplpDDSurface4 : NULL), pUnkOuter);
	if(lpDDSurfaceDesc != NULL)
	{
		char dwFlags_buffer[LOGBUFFER_MAX], ddscaps1_buffer[LOGBUFFER_MAX], ddpf_buffer[LOGBUFFER_MAX];
		FlagsToString(FLAGS_DDSD, CFLAGS_DDSD, lpDDSurfaceDesc->dwFlags, (char *)&dwFlags_buffer, LOGBUFFER_MAX);
		FlagsToString(FLAGS_DDSCAPS1, CFLAGS_DDSCAPS1, lpDDSurfaceDesc->ddsCaps.dwCaps, (char *)&ddscaps1_buffer, LOGBUFFER_MAX);
		FlagsToString(FLAGS_DDPF, CFLAGS_DDPF, lpDDSurfaceDesc->ddpfPixelFormat.dwFlags, (char *)&ddpf_buffer, LOGBUFFER_MAX);

		Log("->lpDDSurfaceDesc { dwSize=%#010lx, dwFlags=%#010lx (%s), dwWidth=%#010lx (%d), dwHeight=%#010lx (%d), lPitch=%#010lx , dwLinearSize=%#010lx, dwBackBufferCount=%#010lx, dwMipMapCount=%#010lx, dwRefreshRate=%#010lx, dwAlphaBitDepth=%#010lx, dwReserved=%#010lx,\n"
			"  lpSurface=%#010lx, ddckCKDestOverlay={ %#010lx, %#010lx }, ddckCKDestBlt={ %#010lx, %#010lx }, ddckCKSrcOverlay={ %#010lx, %#010lx }, ddckCKSrcBlt={ %#010lx, %#010lx },\n"
			"  ddpfPixelFormat={ dwSize=%#010lx, dwFlags=%#010lx (%s), dwFourCC=%#010lx, dwRGBBitCount=%#010lx, dwYUVBitCount=%#010lx, dwZBufferBitDepth=%#010lx, dwAlphaBitDepth=%#010lx, dwLuminanceBitCount=%#010lx, dwBumpBitCount=%#010lx, dwRBitMask=%#010lx,\n"
			"    dwYBitMask=%#010lx, dwStencilBitDepth=%#010lx, dwLuminanceBitMask=%#010lx, dwBumpDuBitMask=%#010lx, dwGBitMask=%#010lx, dwUBitMask=%#010lx, dwZBitMask=%#010lx, dwBumpDvBitMask=%#010lx, dwBBitMask=%#010lx, dwVBitMask=%#010lx, dwStencilBitMask=%#010lx,\n"
			"    dwBumpLuminanceBitMask=%#010lx, dwRGBAlphaBitMask=%#010lx, dwYUVAlphaBitMask=%#010lx, dwLuminanceAlphaBitMask=%#010lx, dwRGBZBitMask=%#010lx, dwYUVZBitMask=%#010lx },\n"
			"  ddsCaps={ %#010lx (%s), %#010lx, %#010lx, %#010lx }, dwTextureStage=%#010lx }\n",
			lpDDSurfaceDesc->dwSize, lpDDSurfaceDesc->dwFlags, dwFlags_buffer, lpDDSurfaceDesc->dwWidth, (unsigned int)lpDDSurfaceDesc->dwWidth, lpDDSurfaceDesc->dwHeight, (unsigned int)lpDDSurfaceDesc->dwHeight, lpDDSurfaceDesc->lPitch,
			lpDDSurfaceDesc->dwLinearSize, lpDDSurfaceDesc->dwBackBufferCount, lpDDSurfaceDesc->dwMipMapCount, lpDDSurfaceDesc->dwRefreshRate, lpDDSurfaceDesc->dwAlphaBitDepth, lpDDSurfaceDesc->dwReserved, lpDDSurfaceDesc->lpSurface,
			lpDDSurfaceDesc->ddckCKDestOverlay.dwColorSpaceLowValue, lpDDSurfaceDesc->ddckCKDestOverlay.dwColorSpaceHighValue, lpDDSurfaceDesc->ddckCKDestBlt.dwColorSpaceLowValue, lpDDSurfaceDesc->ddckCKDestBlt.dwColorSpaceHighValue,
			lpDDSurfaceDesc->ddckCKSrcOverlay.dwColorSpaceLowValue, lpDDSurfaceDesc->ddckCKSrcOverlay.dwColorSpaceHighValue, lpDDSurfaceDesc->ddckCKSrcBlt.dwColorSpaceLowValue, lpDDSurfaceDesc->ddckCKSrcBlt.dwColorSpaceHighValue,
			
			lpDDSurfaceDesc->ddpfPixelFormat.dwSize, lpDDSurfaceDesc->ddpfPixelFormat.dwFlags, ddpf_buffer, lpDDSurfaceDesc->ddpfPixelFormat.dwFourCC, lpDDSurfaceDesc->ddpfPixelFormat.dwRGBBitCount, lpDDSurfaceDesc->ddpfPixelFormat.dwYUVBitCount,
			lpDDSurfaceDesc->ddpfPixelFormat.dwZBufferBitDepth, lpDDSurfaceDesc->ddpfPixelFormat.dwAlphaBitDepth, lpDDSurfaceDesc->ddpfPixelFormat.dwLuminanceBitCount, lpDDSurfaceDesc->ddpfPixelFormat.dwBumpBitCount,
			lpDDSurfaceDesc->ddpfPixelFormat.dwRBitMask, lpDDSurfaceDesc->ddpfPixelFormat.dwYBitMask, lpDDSurfaceDesc->ddpfPixelFormat.dwStencilBitDepth, lpDDSurfaceDesc->ddpfPixelFormat.dwLuminanceBitMask,
			lpDDSurfaceDesc->ddpfPixelFormat.dwBumpDuBitMask, lpDDSurfaceDesc->ddpfPixelFormat.dwGBitMask, lpDDSurfaceDesc->ddpfPixelFormat.dwUBitMask, lpDDSurfaceDesc->ddpfPixelFormat.dwZBitMask, lpDDSurfaceDesc->ddpfPixelFormat.dwBumpDvBitMask,
			lpDDSurfaceDesc->ddpfPixelFormat.dwBBitMask, lpDDSurfaceDesc->ddpfPixelFormat.dwVBitMask, lpDDSurfaceDesc->ddpfPixelFormat.dwStencilBitMask, lpDDSurfaceDesc->ddpfPixelFormat.dwBumpLuminanceBitMask,
			lpDDSurfaceDesc->ddpfPixelFormat.dwRGBAlphaBitMask, lpDDSurfaceDesc->ddpfPixelFormat.dwYUVAlphaBitMask, lpDDSurfaceDesc->ddpfPixelFormat.dwLuminanceAlphaBitMask, lpDDSurfaceDesc->ddpfPixelFormat.dwRGBZBitMask,
			lpDDSurfaceDesc->ddpfPixelFormat.dwYUVZBitMask,
			
			lpDDSurfaceDesc->ddsCaps.dwCaps, ddscaps1_buffer, lpDDSurfaceDesc->ddsCaps.dwCaps2, lpDDSurfaceDesc->ddsCaps.dwCaps3, lpDDSurfaceDesc->ddsCaps.dwCaps4, lpDDSurfaceDesc->dwTextureStage
		);
	}
	if(ishooked_ddrawsurface4_hooks == false)
	{
		HookVTBLCalls((LPVOID *)lplpDDSurface4, ddrawsurface4_hooks, count_ddrawsurface4_hooks, "IDirectDrawSurface4");
		ishooked_ddrawsurface4_hooks = true;
	}

	// ------------------------------------------------------------------
	// Create a DirectX window
	// ----------------------------
#ifdef FF8_WINDOWED
	if((void *)lpDDSurfaceDesc == (void *)0x00134658)
	{
		Log("IF[lpDDSurfaceDesc == 0x00134658] THEN\n");
		if(SUCCEEDED(ret))
		{

			LPDIRECTDRAWCLIPPER pcClipper;
			if(FAILED(((LPDIRECTDRAW4)ppvOut)->CreateClipper(0, &pcClipper, NULL)))
			{
				Log("ERROR: Couldn't create clipper\n");
			}

			// Associate the clipper with the window
			Log("g_hwnd=%#01lx\n", g_hwnd);
			pcClipper->SetHWnd(0, g_hwnd);
			(*lplpDDSurface4)->SetClipper(pcClipper);
			//SAFE_RELEASE(pcClipper);

			HRESULT hr = 0;
			LPDIRECTDRAWSURFACE4 lpddsB = NULL;
			LPDIRECTDRAWSURFACE4 lpddsZ = NULL;
			DDSURFACEDESC2 ddsd;
			ZeroMemory(&ddsd, sizeof(ddsd));
			ddsd.dwSize = sizeof(ddsd);
			ddsd.dwFlags = (DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT);
			ddsd.ddsCaps.dwCaps    = (lpDDSurfaceDesc->ddsCaps.dwCaps);
			ddsd.ddsCaps.dwCaps &= ~(DDSCAPS_PRIMARYSURFACE);
			ddsd.ddsCaps.dwCaps |= (DDSCAPS_OFFSCREENPLAIN);
			ddsd.dwWidth           = 640;
			ddsd.dwHeight          = 480;
			//hRes = lpdd->lpVtbl->CreateSurface(lpdd, &ddsd, &lpddZBuffer,NULL);
			hr = ((LPDIRECTDRAW4)ppvOut)->CreateSurface(&ddsd, &lpddsB, NULL);
			if(FAILED(hr))
			{
				Log("ERROR: Failed to create WINDOWED backbuffer!");
			} else {
				//hr = (*lplpDDSurface4)->AddAttachedSurface(lpddsB);
				//if(FAILED(hr)) {
				//	Log("ERROR: Failed to attach WINDOWED backbuffer to frontbuffer!");
				//} else {
					g_frontbuffer = (*lplpDDSurface4);
					g_backbuffer = lpddsB;
					/*hr = ((LPDIRECTDRAW4)ppvOut)->CreateSurface(&ddsd, &lpddsZ, NULL);
					if(FAILED(hr)) {
						Log("ERROR: Failed to create WINDOWED z-buffer!");
					} else {
						hr = lpddsB->AddAttachedSurface(lpddsZ);
						if(FAILED(hr)) {
							Log("ERROR: Failed to attach WINDOWED z-buffer to backbuffer!");
						} else {
							
						}
					}*/
				//}
			}
		}
	}
#endif
	// ----------------------------------

	return ret;
}


HRESULT __stdcall DDRAW4_HOOK_DuplicateSurface(LPVOID *ppvOut, LPDIRECTDRAWSURFACE4 lpDDSurface4, LPDIRECTDRAWSURFACE4 FAR *lplpDupDDSurface4)
{
	const unsigned int hpos = 7;

	DDRAW4_DuplicateSurface_Type ofn = (DDRAW4_DuplicateSurface_Type)ddraw4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpDDSurface4, lplpDupDDSurface4);
	LogDXError(ret);

	Log("IDirectDraw4::%s()\n", ddraw4_hooks[hpos].name);

	return ret;
}


HRESULT __stdcall DDRAW4_HOOK_EnumDisplayModes(LPVOID *ppvOut, DWORD dwFlags, LPDDSURFACEDESC2 lpDDSurfaceDesc2, LPVOID lpContext, LPDDENUMMODESCALLBACK2 lpEnumModesCallback2)
{
	const unsigned int hpos = 8;

	DDRAW4_EnumDisplayModes_Type ofn = (DDRAW4_EnumDisplayModes_Type)ddraw4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwFlags, lpDDSurfaceDesc2, lpContext, lpEnumModesCallback2);
	LogDXError(ret);

	Log("IDirectDraw4::%s()\n", ddraw4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAW4_HOOK_EnumSurfaces(LPVOID *ppvOut, DWORD dwFlags, LPDDSURFACEDESC2 lpDDSD2, LPVOID lpContext, LPDDENUMSURFACESCALLBACK2 lpEnumSurfacesCallback2) {
	const unsigned int hpos = 9;

	DDRAW4_EnumSurfaces_Type ofn = (DDRAW4_EnumSurfaces_Type)ddraw4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwFlags, lpDDSD2, lpContext, lpEnumSurfacesCallback2);
	LogDXError(ret);

	Log("IDirectDraw4::%s()\n", ddraw4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAW4_HOOK_FlipToGDISurface(LPVOID *ppvOut) {
	const unsigned int hpos = 10;

	DDRAW4_FlipToGDISurface_Type ofn = (DDRAW4_FlipToGDISurface_Type)ddraw4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut);
	LogDXError(ret);

	Log("IDirectDraw4::%s()\n", ddraw4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAW4_HOOK_GetCaps(LPVOID *ppvOut, LPDDCAPS lpDDDriverCaps, LPDDCAPS lpDDHELCaps) {
	const unsigned int hpos = 11;

	DDRAW4_GetCaps_Type ofn = (DDRAW4_GetCaps_Type)ddraw4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpDDDriverCaps, lpDDHELCaps);
	LogDXError(ret);

	Log("IDirectDraw4::%s()\n", ddraw4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAW4_HOOK_GetDisplayMode(LPVOID *ppvOut, LPDDSURFACEDESC2 lpDDSurfaceDesc2) {
	const unsigned int hpos = 12;

	DDRAW4_GetDisplayMode_Type ofn = (DDRAW4_GetDisplayMode_Type)ddraw4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpDDSurfaceDesc2);
	LogDXError(ret);

	Log("IDirectDraw4::%s()\n", ddraw4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAW4_HOOK_GetFourCCCodes(LPVOID *ppvOut, LPDWORD lpNumCodes, LPDWORD lpCodes) {
	const unsigned int hpos = 13;

	DDRAW4_GetFourCCCodes_Type ofn = (DDRAW4_GetFourCCCodes_Type)ddraw4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpNumCodes, lpCodes);
	LogDXError(ret);

	Log("IDirectDraw4::%s()\n", ddraw4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAW4_HOOK_GetGDISurface(LPVOID *ppvOut, LPDIRECTDRAWSURFACE2 FAR *lplpGDIDDSurface4) {
	const unsigned int hpos = 14;

	DDRAW4_GetGDISurface_Type ofn = (DDRAW4_GetGDISurface_Type)ddraw4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lplpGDIDDSurface4);
	LogDXError(ret);

	Log("IDirectDraw4::%s()\n", ddraw4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAW4_HOOK_GetMonitorFrequency(LPVOID *ppvOut, LPDWORD lpdwFrequency) {
	const unsigned int hpos = 15;

	DDRAW4_GetMonitorFrequency_Type ofn = (DDRAW4_GetMonitorFrequency_Type)ddraw4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpdwFrequency);
	LogDXError(ret);

	Log("IDirectDraw4::%s()\n", ddraw4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAW4_HOOK_GetScanLine(LPVOID *ppvOut, LPDWORD lpdwScanLine) {
	const unsigned int hpos = 16;

	DDRAW4_GetScanLine_Type ofn = (DDRAW4_GetScanLine_Type)ddraw4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpdwScanLine);
	LogDXError(ret);

	Log("IDirectDraw4::%s()\n", ddraw4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAW4_HOOK_GetVerticalBlankStatus(LPVOID *ppvOut, LPBOOL lpbIsInVB) {
	const unsigned int hpos = 17;

	DDRAW4_GetVerticalBlankStatus_Type ofn = (DDRAW4_GetVerticalBlankStatus_Type)ddraw4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpbIsInVB);
	LogDXError(ret);

	Log("IDirectDraw4::%s()\n", ddraw4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAW4_HOOK_Initialize(LPVOID *ppvOut, GUID FAR *lpGUID) {
	const unsigned int hpos = 18;

	DDRAW4_Initialize_Type ofn = (DDRAW4_Initialize_Type)ddraw4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpGUID);
	LogDXError(ret);

	Log("IDirectDraw4::%s()\n", ddraw4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAW4_HOOK_RestoreDisplayMode(LPVOID *ppvOut) {
	const unsigned int hpos = 19;

	DDRAW4_RestoreDisplayMode_Type ofn = (DDRAW4_RestoreDisplayMode_Type)ddraw4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut);
	LogDXError(ret);

	Log("IDirectDraw4::%s()\n", ddraw4_hooks[hpos].name);

	return ret;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////
// Save the hWnd for the window it has created.
// ŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻ
HRESULT __stdcall DDRAW4_HOOK_SetCooperativeLevel(LPVOID *ppvOut, HWND hWnd, DWORD dwFlags)
{
	const unsigned int hpos = 20;

#ifdef FF8_WINDOWED
	dwFlags &= ~(DDSCL_FULLSCREEN | DDSCL_EXCLUSIVE);
	dwFlags |= DDSCL_NORMAL;

	g_hwnd = hWnd;
	DWORD style = (DWORD)GetWindowLong(hWnd, GWL_STYLE);
	/*DWORD exstyle = (DWORD)GetWindowLong(hWnd, GWL_EXSTYLE);

	char style_buffer[LOGBUFFER_MAX], exstyle_buffer[LOGBUFFER_MAX];
	FlagsToString(FLAGS_WS, CFLAGS_WS, style, (char *)&style_buffer, LOGBUFFER_MAX);
	FlagsToString(FLAGS_WS_EX, CFLAGS_WS_EX, exstyle, (char *)&exstyle_buffer, LOGBUFFER_MAX);
	
	Log("WINDOW STYLE: %s\nWINDOW EX STYLE: %s\n", style_buffer, exstyle_buffer);*/

	// Change the window style from full screen to windowed
	style &= ~(WS_POPUP);
	style |= (WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX);
	SetWindowLong(hWnd, GWL_STYLE, style);
	SetWindowPos(hWnd, HWND_TOP, 100, 100, 0, 0, SWP_NOSIZE);

	hWnd = NULL; // windowed mode
#endif

	DDRAW4_SetCooperativeLevel_Type ofn = (DDRAW4_SetCooperativeLevel_Type)ddraw4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, hWnd, dwFlags);
	LogDXError(ret);

	Log("IDirectDraw4::%s(this=%#010lx, hWnd=%#010lx, dwFlags=%#010lx)\n", ddraw4_hooks[hpos].name, ppvOut, hWnd, dwFlags);

	return ret;
}
////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
// Set display mode
// ŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻ
HRESULT __stdcall DDRAW4_HOOK_SetDisplayMode(LPVOID *ppvOut, DWORD dwWidth, DWORD dwHeight, DWORD dwBPP, DWORD dwRefreshRate, DWORD dwFlags)
{
	const unsigned int hpos = 21;

	if(g_config.displaymode != 0)
	{
		dwWidth = displaymode_options[g_config.displaymode].resX;
		dwHeight = displaymode_options[g_config.displaymode].resY;
		dwBPP = displaymode_options[g_config.displaymode].bpp;
	}

#ifndef FF8_WINDOWED
	DDRAW4_SetDisplayMode_Type ofn = (DDRAW4_SetDisplayMode_Type)ddraw4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwWidth, dwHeight, dwBPP, dwRefreshRate, dwFlags);
	LogDXError(ret);
#else
	HRESULT ret = S_OK;
#endif

	Log("IDirectDraw4::%s(this=%#010lx, dwWidth=%#010lx (%d), dwHeight=%#010lx (%d), dwBPP=%#010lx (%d), dwRefreshRate=%#010lx (%d), dwFlags=%#010lx)\n", ddraw4_hooks[hpos].name, ppvOut, dwWidth, dwWidth, dwHeight, dwHeight, dwBPP, dwBPP, dwRefreshRate, dwRefreshRate, dwFlags);

	return ret;
}
////////////////////////////////////


HRESULT __stdcall DDRAW4_HOOK_WaitForVerticalBlank(LPVOID *ppvOut, DWORD dwFlags, HANDLE hEvent)
{
	const unsigned int hpos = 22;

	DDRAW4_WaitForVerticalBlank_Type ofn = (DDRAW4_WaitForVerticalBlank_Type)ddraw4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwFlags, hEvent);
	LogDXError(ret);

	Log("IDirectDraw4::%s()\n", ddraw4_hooks[hpos].name);

	return ret;
}


HRESULT __stdcall DDRAW4_HOOK_GetAvailableVidMem(LPVOID *ppvOut, LPDDSCAPS2 lpDDSCaps2, LPDWORD lpdwTotal, LPDWORD lpdwFree)
{
	const unsigned int hpos = 23;

	DDRAW4_GetAvailableVidMem_Type ofn = (DDRAW4_GetAvailableVidMem_Type)ddraw4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpDDSCaps2, lpdwTotal, lpdwFree);
	LogDXError(ret);

	Log("IDirectDraw4::%s(this=%#010lx, lpDDSCaps=%#010lx, lpdwTotal=%#010lx (%d), lpdwFree=%#010lx (%d))\n", ddraw4_hooks[hpos].name, ppvOut, lpDDSCaps2, lpdwTotal, lpdwTotal, lpdwFree, lpdwFree);
	if(lpDDSCaps2 != NULL) {
		char ddscaps1_buffer[LOGBUFFER_MAX];
		FlagsToString(FLAGS_DDSCAPS1, CFLAGS_DDSCAPS1, lpDDSCaps2->dwCaps, (char *)&ddscaps1_buffer, LOGBUFFER_MAX);

		Log("->lpDDSCaps2 { %#010lx (%s), %#010lx, %#010lx, %#010lx }\n",
			lpDDSCaps2->dwCaps, ddscaps1_buffer, lpDDSCaps2->dwCaps2, lpDDSCaps2->dwCaps3, lpDDSCaps2->dwCaps4
		);
	}
	return ret;
}

HRESULT __stdcall DDRAW4_HOOK_GetSurfaceFromDC(LPVOID *ppvOut, HDC hdc, LPDIRECTDRAWSURFACE4 *lpDDS4) {
	const unsigned int hpos = 24;

	DDRAW4_GetSurfaceFromDC_Type ofn = (DDRAW4_GetSurfaceFromDC_Type)ddraw4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, hdc, lpDDS4);
	LogDXError(ret);

	Log("IDirectDraw4::%s()\n", ddraw4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAW4_HOOK_RestoreAllSurfaces(LPVOID *ppvOut) {
	const unsigned int hpos = 25;

	DDRAW4_RestoreAllSurfaces_Type ofn = (DDRAW4_RestoreAllSurfaces_Type)ddraw4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut);
	LogDXError(ret);

	Log("IDirectDraw4::%s()\n", ddraw4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAW4_HOOK_TestCooperativeLevel(LPVOID *ppvOut) {
	const unsigned int hpos = 26;

	DDRAW4_TestCooperativeLevel_Type ofn = (DDRAW4_TestCooperativeLevel_Type)ddraw4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut);
	LogDXError(ret);

	Log("IDirectDraw4::%s()\n", ddraw4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAW4_HOOK_GetDeviceIdentifier(LPVOID *ppvOut, LPDDDEVICEIDENTIFIER lpdddi, DWORD dwFlags) {
	const unsigned int hpos = 27;

	DDRAW4_GetDeviceIdentifier_Type ofn = (DDRAW4_GetDeviceIdentifier_Type)ddraw4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpdddi, dwFlags);
	LogDXError(ret);

	Log("IDirectDraw4::%s()\n", ddraw4_hooks[hpos].name);

	return ret;
}