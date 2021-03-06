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

#include "d3ddevice3_hooks.h"

//{ NULL, 0, NULL, NULL },	//
#ifdef _DEBUG
SVTBL_HOOK d3ddevice3_hooks[] = {
/*0*/	{ "QueryInterface",				0x00, NULL, (PDWORD)D3DDEVICE3_HOOK_QueryInterface },
/*1*/	{ NULL, 0, NULL, NULL },	//{ "AddRef",						0x04, NULL, (PDWORD)D3DDEVICE3_HOOK_AddRef },
/*2*/	{ NULL, 0, NULL, NULL },	//{ "Release",					0x08, NULL, (PDWORD)D3DDEVICE3_HOOK_Release },
/*3*/	{ "GetCaps",					0x0C, NULL, (PDWORD)D3DDEVICE3_HOOK_GetCaps },
/*4*/	{ "GetStats",					0x10, NULL, (PDWORD)D3DDEVICE3_HOOK_GetStats },
/*5*/	{ "AddViewport",				0x14, NULL, (PDWORD)D3DDEVICE3_HOOK_AddViewport },
/*6*/	{ "DeleteViewport",				0x18, NULL, (PDWORD)D3DDEVICE3_HOOK_DeleteViewport },
/*7*/	{ "NextViewport",				0x1C, NULL, (PDWORD)D3DDEVICE3_HOOK_NextViewport },
/*8*/	{ "EnumTextureFormats",			0x20, NULL, (PDWORD)D3DDEVICE3_HOOK_EnumTextureFormats },
/*9*/	{ "BeginScene",					0x24, NULL, (PDWORD)D3DDEVICE3_HOOK_BeginScene },
/*10*/	{ "EndScene",					0x28, NULL, (PDWORD)D3DDEVICE3_HOOK_EndScene },
/*11*/	{ "GetDirect3D",				0x2C, NULL, (PDWORD)D3DDEVICE3_HOOK_GetDirect3D },
/*12*/	{ "SetCurrentViewport",			0x30, NULL, (PDWORD)D3DDEVICE3_HOOK_SetCurrentViewport },
/*13*/	{ "GetCurrentViewport",			0x34, NULL, (PDWORD)D3DDEVICE3_HOOK_GetCurrentViewport },
/*14*/	{ "SetRenderTarget",			0x38, NULL, (PDWORD)D3DDEVICE3_HOOK_SetRenderTarget },
/*15*/	{ "GetRenderTarget",			0x3C, NULL, (PDWORD)D3DDEVICE3_HOOK_GetRenderTarget },
/*16*/	{ "Begin",						0x40, NULL, (PDWORD)D3DDEVICE3_HOOK_Begin },
/*17*/	{ "BeginIndexed",				0x44, NULL, (PDWORD)D3DDEVICE3_HOOK_BeginIndexed },
/*18*/	{ "Vertex",						0x48, NULL, (PDWORD)D3DDEVICE3_HOOK_Vertex },
/*19*/	{ "Index",						0x4C, NULL, (PDWORD)D3DDEVICE3_HOOK_Index },
/*20*/	{ "End",						0x50, NULL, (PDWORD)D3DDEVICE3_HOOK_End },
/*21*/	{ "GetRenderState",				0x54, NULL, (PDWORD)D3DDEVICE3_HOOK_GetRenderState },
/*22*/	{ NULL, 0, NULL, NULL },	//{ "SetRenderState",				0x58, NULL, (PDWORD)D3DDEVICE3_HOOK_SetRenderState },
/*23*/	{ "GetLightState",				0x5C, NULL, (PDWORD)D3DDEVICE3_HOOK_GetLightState },
/*24*/	{ "SetLightState",				0x60, NULL, (PDWORD)D3DDEVICE3_HOOK_SetLightState },
/*25*/	{ "SetTransform",				0x64, NULL, (PDWORD)D3DDEVICE3_HOOK_SetTransform },
/*26*/	{ "GetTransform",				0x68, NULL, (PDWORD)D3DDEVICE3_HOOK_GetTransform },
/*27*/	{ "MultiplyTransform",			0x6C, NULL, (PDWORD)D3DDEVICE3_HOOK_MultiplyTransform },
/*28*/	{ "DrawPrimitive",				0x70, NULL, (PDWORD)D3DDEVICE3_HOOK_DrawPrimitive },
/*29*/	{ "DrawIndexedPrimitive",		0x74, NULL, (PDWORD)D3DDEVICE3_HOOK_DrawIndexedPrimitive },
/*30*/	{ "SetClipStatus",				0x78, NULL, (PDWORD)D3DDEVICE3_HOOK_SetClipStatus },
/*31*/	{ "GetClipStatus",				0x7C, NULL, (PDWORD)D3DDEVICE3_HOOK_GetClipStatus },
/*32*/	{ "DrawPrimitiveStrided",		0x80, NULL, (PDWORD)D3DDEVICE3_HOOK_DrawPrimitiveStrided },
/*33*/	{ "DrawIndexedPrimitiveStrided",0x84, NULL, (PDWORD)D3DDEVICE3_HOOK_DrawIndexedPrimitiveStrided },
/*34*/	{ "DrawPrimitiveVB",			0x88, NULL, (PDWORD)D3DDEVICE3_HOOK_DrawPrimitiveVB },
/*35*/	{ "DrawIndexedPrimitiveVB",		0x8C, NULL, (PDWORD)D3DDEVICE3_HOOK_DrawIndexedPrimitiveVB },
/*36*/	{ "ComputeSphereVisibility",	0x90, NULL, (PDWORD)D3DDEVICE3_HOOK_ComputeSphereVisibility },
/*37*/	{ "GetTexture",					0x94, NULL, (PDWORD)D3DDEVICE3_HOOK_GetTexture },
/*38*/	{ "SetTexture",					0x98, NULL, (PDWORD)D3DDEVICE3_HOOK_SetTexture },
/*39*/	{ "GetTextureStageState",		0x9C, NULL, (PDWORD)D3DDEVICE3_HOOK_GetTextureStageState },
/*40*/	{ "SetTextureStageState",		0xA0, NULL, (PDWORD)D3DDEVICE3_HOOK_SetTextureStageState },
/*41*/	{ "ValidateDevice",				0xA4, NULL, (PDWORD)D3DDEVICE3_HOOK_ValidateDevice }
};
#else
SVTBL_HOOK d3ddevice3_hooks[] = {
/*0*/	{ "QueryInterface",				0x00, NULL, (PDWORD)D3DDEVICE3_HOOK_QueryInterface },
/*1*/	{ NULL, 0, NULL, NULL },	//{ "AddRef",						0x04, NULL, (PDWORD)D3DDEVICE3_HOOK_AddRef },
/*2*/	{ NULL, 0, NULL, NULL },	//{ "Release",					0x08, NULL, (PDWORD)D3DDEVICE3_HOOK_Release },
/*3*/	{ NULL, 0, NULL, NULL },	//{ "GetCaps",					0x0C, NULL, (PDWORD)D3DDEVICE3_HOOK_GetCaps },
/*4*/	{ NULL, 0, NULL, NULL },	//{ "GetStats",					0x10, NULL, (PDWORD)D3DDEVICE3_HOOK_GetStats },
/*5*/	{ NULL, 0, NULL, NULL },	//{ "AddViewport",				0x14, NULL, (PDWORD)D3DDEVICE3_HOOK_AddViewport },
/*6*/	{ NULL, 0, NULL, NULL },	//{ "DeleteViewport",				0x18, NULL, (PDWORD)D3DDEVICE3_HOOK_DeleteViewport },
/*7*/	{ NULL, 0, NULL, NULL },	//{ "NextViewport",				0x1C, NULL, (PDWORD)D3DDEVICE3_HOOK_NextViewport },
/*8*/	{ NULL, 0, NULL, NULL },	//{ "EnumTextureFormats",			0x20, NULL, (PDWORD)D3DDEVICE3_HOOK_EnumTextureFormats },
/*9*/	{ NULL, 0, NULL, NULL },	//{ "BeginScene",					0x24, NULL, (PDWORD)D3DDEVICE3_HOOK_BeginScene },
/*10*/	{ NULL, 0, NULL, NULL },	//{ "EndScene",					0x28, NULL, (PDWORD)D3DDEVICE3_HOOK_EndScene },
/*11*/	{ NULL, 0, NULL, NULL },	//{ "GetDirect3D",				0x2C, NULL, (PDWORD)D3DDEVICE3_HOOK_GetDirect3D },
/*12*/	{ NULL, 0, NULL, NULL },	//{ "SetCurrentViewport",			0x30, NULL, (PDWORD)D3DDEVICE3_HOOK_SetCurrentViewport },
/*13*/	{ NULL, 0, NULL, NULL },	//{ "GetCurrentViewport",			0x34, NULL, (PDWORD)D3DDEVICE3_HOOK_GetCurrentViewport },
/*14*/	{ NULL, 0, NULL, NULL },	//{ "SetRenderTarget",			0x38, NULL, (PDWORD)D3DDEVICE3_HOOK_SetRenderTarget },
/*15*/	{ NULL, 0, NULL, NULL },	//{ "GetRenderTarget",			0x3C, NULL, (PDWORD)D3DDEVICE3_HOOK_GetRenderTarget },
/*16*/	{ NULL, 0, NULL, NULL },	//{ "Begin",						0x40, NULL, (PDWORD)D3DDEVICE3_HOOK_Begin },
/*17*/	{ NULL, 0, NULL, NULL },	//{ "BeginIndexed",				0x44, NULL, (PDWORD)D3DDEVICE3_HOOK_BeginIndexed },
/*18*/	{ NULL, 0, NULL, NULL },	//{ "Vertex",						0x48, NULL, (PDWORD)D3DDEVICE3_HOOK_Vertex },
/*19*/	{ NULL, 0, NULL, NULL },	//{ "Index",						0x4C, NULL, (PDWORD)D3DDEVICE3_HOOK_Index },
/*20*/	{ NULL, 0, NULL, NULL },	//{ "End",						0x50, NULL, (PDWORD)D3DDEVICE3_HOOK_End },
/*21*/	{ NULL, 0, NULL, NULL },	//{ "GetRenderState",				0x54, NULL, (PDWORD)D3DDEVICE3_HOOK_GetRenderState },
/*22*/	{ NULL, 0, NULL, NULL },	//{ "SetRenderState",				0x58, NULL, (PDWORD)D3DDEVICE3_HOOK_SetRenderState },
/*23*/	{ NULL, 0, NULL, NULL },	//{ "GetLightState",				0x5C, NULL, (PDWORD)D3DDEVICE3_HOOK_GetLightState },
/*24*/	{ NULL, 0, NULL, NULL },	//{ "SetLightState",				0x60, NULL, (PDWORD)D3DDEVICE3_HOOK_SetLightState },
/*25*/	{ NULL, 0, NULL, NULL },	//{ "SetTransform",				0x64, NULL, (PDWORD)D3DDEVICE3_HOOK_SetTransform },
/*26*/	{ NULL, 0, NULL, NULL },	//{ "GetTransform",				0x68, NULL, (PDWORD)D3DDEVICE3_HOOK_GetTransform },
/*27*/	{ NULL, 0, NULL, NULL },	//{ "MultiplyTransform",			0x6C, NULL, (PDWORD)D3DDEVICE3_HOOK_MultiplyTransform },
/*28*/	{ NULL, 0, NULL, NULL },	//{ "DrawPrimitive",				0x70, NULL, (PDWORD)D3DDEVICE3_HOOK_DrawPrimitive },
/*29*/	{ "DrawIndexedPrimitive",		0x74, NULL, (PDWORD)D3DDEVICE3_HOOK_DrawIndexedPrimitive },
/*30*/	{ NULL, 0, NULL, NULL },	//{ "SetClipStatus",				0x78, NULL, (PDWORD)D3DDEVICE3_HOOK_SetClipStatus },
/*31*/	{ NULL, 0, NULL, NULL },	//{ "GetClipStatus",				0x7C, NULL, (PDWORD)D3DDEVICE3_HOOK_GetClipStatus },
/*32*/	{ NULL, 0, NULL, NULL },	//{ "DrawPrimitiveStrided",		0x80, NULL, (PDWORD)D3DDEVICE3_HOOK_DrawPrimitiveStrided },
/*33*/	{ NULL, 0, NULL, NULL },	//{ "DrawIndexedPrimitiveStrided",0x84, NULL, (PDWORD)D3DDEVICE3_HOOK_DrawIndexedPrimitiveStrided },
/*34*/	{ NULL, 0, NULL, NULL },	//{ "DrawPrimitiveVB",			0x88, NULL, (PDWORD)D3DDEVICE3_HOOK_DrawPrimitiveVB },
/*35*/	{ NULL, 0, NULL, NULL },	//{ "DrawIndexedPrimitiveVB",		0x8C, NULL, (PDWORD)D3DDEVICE3_HOOK_DrawIndexedPrimitiveVB },
/*36*/	{ NULL, 0, NULL, NULL },	//{ "ComputeSphereVisibility",	0x90, NULL, (PDWORD)D3DDEVICE3_HOOK_ComputeSphereVisibility },
/*37*/	{ NULL, 0, NULL, NULL },	//{ "GetTexture",					0x94, NULL, (PDWORD)D3DDEVICE3_HOOK_GetTexture },
/*38*/	{ NULL, 0, NULL, NULL },	//{ "SetTexture",					0x98, NULL, (PDWORD)D3DDEVICE3_HOOK_SetTexture },
/*39*/	{ NULL, 0, NULL, NULL },	//{ "GetTextureStageState",		0x9C, NULL, (PDWORD)D3DDEVICE3_HOOK_GetTextureStageState },
/*40*/	{ NULL, 0, NULL, NULL },	//{ "SetTextureStageState",		0xA0, NULL, (PDWORD)D3DDEVICE3_HOOK_SetTextureStageState },
/*41*/	{ NULL, 0, NULL, NULL },	//{ "ValidateDevice",				0xA4, NULL, (PDWORD)D3DDEVICE3_HOOK_ValidateDevice }
};
#endif
const unsigned int count_d3ddevice3_hooks = 42;
bool ishooked_d3ddevice3_hooks = false;

HRESULT __stdcall D3DDEVICE3_HOOK_QueryInterface(LPVOID *ppvOut, REFIID riid, LPVOID FAR *ppvObj) {
	const unsigned int hpos = 0;

	D3DDEVICE3_QueryInterface_Type ofn = (D3DDEVICE3_QueryInterface_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, riid, ppvObj);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s(%#010lx, { %#010lx, %#06x, %#06x, { %#04x, %#04x, %#04x, %#04x, %#04x, %#04x, %#04x, %#04x } }, %#010lx)\n", d3ddevice3_hooks[hpos].name, ppvOut, riid.Data1, riid.Data2, riid.Data3, riid.Data4[0], riid.Data4[1], riid.Data4[2], riid.Data4[3], riid.Data4[4], riid.Data4[5], riid.Data4[6], riid.Data4[7], ppvObj);

	return ret;
}

ULONG __stdcall D3DDEVICE3_HOOK_AddRef(LPVOID *ppvOut) {
	const unsigned int hpos = 1;

	D3DDEVICE3_AddRef_Type ofn = (D3DDEVICE3_AddRef_Type)d3ddevice3_hooks[hpos].oldFunc;
	ULONG ret = ofn(ppvOut);

	Log("IDirect3DDevice3::%s()\n", d3ddevice3_hooks[hpos].name);

	return ret;
}

ULONG __stdcall D3DDEVICE3_HOOK_Release(LPVOID *ppvOut) {
	const unsigned int hpos = 2;

	D3DDEVICE3_Release_Type ofn = (D3DDEVICE3_Release_Type)d3ddevice3_hooks[hpos].oldFunc;
	ULONG ret = ofn(ppvOut);

	Log("IDirect3DDevice3::%s(%#010lx)\n", d3ddevice3_hooks[hpos].name, ppvOut);

	return ret;
}

HRESULT __stdcall D3DDEVICE3_HOOK_GetCaps(LPVOID *ppvOut, LPD3DDEVICEDESC lpD3DHWDevDesc, LPD3DDEVICEDESC lpD3DHELDevDesc) {
	const unsigned int hpos = 3;

	D3DDEVICE3_GetCaps_Type ofn = (D3DDEVICE3_GetCaps_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpD3DHWDevDesc, lpD3DHELDevDesc);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s()\n", d3ddevice3_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall D3DDEVICE3_HOOK_GetStats(LPVOID *ppvOut, LPD3DSTATS lpD3DStats) {
	const unsigned int hpos = 4;

	D3DDEVICE3_GetStats_Type ofn = (D3DDEVICE3_GetStats_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpD3DStats);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s()\n", d3ddevice3_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall D3DDEVICE3_HOOK_AddViewport(LPVOID *ppvOut, LPDIRECT3DVIEWPORT3 lpDirect3DViewport) {
	const unsigned int hpos = 5;

	D3DDEVICE3_AddViewport_Type ofn = (D3DDEVICE3_AddViewport_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpDirect3DViewport);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s(this=%#010lx, lpDirect3DViewport=%#010lx)\n", d3ddevice3_hooks[hpos].name, ppvOut, lpDirect3DViewport);

	return ret;
}

HRESULT __stdcall D3DDEVICE3_HOOK_DeleteViewport(LPVOID *ppvOut, LPDIRECT3DVIEWPORT3 lpDirect3DViewport) {
	const unsigned int hpos = 6;

	D3DDEVICE3_DeleteViewport_Type ofn = (D3DDEVICE3_DeleteViewport_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpDirect3DViewport);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s(this=%#010lx, lpDirect3DViewport=%#010lx)\n", d3ddevice3_hooks[hpos].name, ppvOut, lpDirect3DViewport);

	return ret;
}

HRESULT __stdcall D3DDEVICE3_HOOK_NextViewport(LPVOID *ppvOut, LPDIRECT3DVIEWPORT3 lpDirect3DViewport, LPDIRECT3DVIEWPORT3 *lplpAnotherViewport, DWORD dwFlags) {
	const unsigned int hpos = 7;

	D3DDEVICE3_NextViewport_Type ofn = (D3DDEVICE3_NextViewport_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpDirect3DViewport, lplpAnotherViewport, dwFlags);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s()\n", d3ddevice3_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall D3DDEVICE3_HOOK_EnumTextureFormats(LPVOID *ppvOut, LPD3DENUMPIXELFORMATSCALLBACK lpd3dEnumTextureProc, LPVOID lpArg) {
	const unsigned int hpos = 8;

	D3DDEVICE3_EnumTextureFormats_Type ofn = (D3DDEVICE3_EnumTextureFormats_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpd3dEnumTextureProc, lpArg);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s(thid=%#010lx, lpd3dEnumTextureProc=%#010lx, lpArg=%#010lx)\n", d3ddevice3_hooks[hpos].name, ppvOut, lpd3dEnumTextureProc, lpArg);

	return ret;
}

HRESULT __stdcall D3DDEVICE3_HOOK_BeginScene(LPVOID *ppvOut) {
	const unsigned int hpos = 9;

	D3DDEVICE3_BeginScene_Type ofn = (D3DDEVICE3_BeginScene_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s(this=%#010lx)\n", d3ddevice3_hooks[hpos].name, ppvOut);

	return ret;
}

HRESULT __stdcall D3DDEVICE3_HOOK_EndScene(LPVOID *ppvOut) {
	const unsigned int hpos = 10;

	D3DDEVICE3_EndScene_Type ofn = (D3DDEVICE3_EndScene_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s(this=%#010lx)\n", d3ddevice3_hooks[hpos].name, ppvOut);

	return ret;
}

HRESULT __stdcall D3DDEVICE3_HOOK_GetDirect3D(LPVOID *ppvOut, LPDIRECT3D3 *lplpD3D) {
	const unsigned int hpos = 11;

	D3DDEVICE3_GetDirect3D_Type ofn = (D3DDEVICE3_GetDirect3D_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lplpD3D);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s(this=%#010lx, lplpD3D=%#010lx *[%#010lx])\n", d3ddevice3_hooks[hpos].name, ppvOut, lplpD3D, (lplpD3D != NULL ? *lplpD3D : NULL));

	return ret;
}

HRESULT __stdcall D3DDEVICE3_HOOK_SetCurrentViewport(LPVOID *ppvOut, LPDIRECT3DVIEWPORT3 lpd3dViewport) {
	const unsigned int hpos = 12;

	D3DDEVICE3_SetCurrentViewport_Type ofn = (D3DDEVICE3_SetCurrentViewport_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpd3dViewport);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s(this=%#010lx, lpd3dViewport=%#010lx)\n", d3ddevice3_hooks[hpos].name, ppvOut, lpd3dViewport);

	return ret;
}

HRESULT __stdcall D3DDEVICE3_HOOK_GetCurrentViewport(LPVOID *ppvOut, LPDIRECT3DVIEWPORT3 *lplpd3dViewport) {
	const unsigned int hpos = 13;

	D3DDEVICE3_GetCurrentViewport_Type ofn = (D3DDEVICE3_GetCurrentViewport_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lplpd3dViewport);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s(this=%#010lx, lplpd3dViewport=%#010lx *[%#010lx])\n", d3ddevice3_hooks[hpos].name, ppvOut, lplpd3dViewport, (lplpd3dViewport != NULL ? *lplpd3dViewport : NULL));

	return ret;
}

HRESULT __stdcall D3DDEVICE3_HOOK_SetRenderTarget(LPVOID *ppvOut, LPDIRECTDRAWSURFACE4 lpNewRenderTarget, DWORD dwFlags) {
	const unsigned int hpos = 14;

	D3DDEVICE3_SetRenderTarget_Type ofn = (D3DDEVICE3_SetRenderTarget_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpNewRenderTarget, dwFlags);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s(this=%#010lx, lpNewRenderTarget=%#010lx, dwFlags=%#010lx)\n", d3ddevice3_hooks[hpos].name, ppvOut, lpNewRenderTarget, dwFlags);

	return ret;
}

HRESULT __stdcall D3DDEVICE3_HOOK_GetRenderTarget(LPVOID *ppvOut, LPDIRECTDRAWSURFACE4 *lplpRenderTarget) {
	const unsigned int hpos = 15;

	D3DDEVICE3_GetRenderTarget_Type ofn = (D3DDEVICE3_GetRenderTarget_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lplpRenderTarget);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s(this=%#010lx, lplpRenderTarget=%#010lx *[%#010lx])\n", d3ddevice3_hooks[hpos].name, ppvOut, lplpRenderTarget, (lplpRenderTarget != NULL ? *lplpRenderTarget : NULL));

	return ret;
}

HRESULT __stdcall D3DDEVICE3_HOOK_Begin(LPVOID *ppvOut, D3DPRIMITIVETYPE d3dpt, DWORD dwVertexTypeDesc, DWORD dwFlags) {
	const unsigned int hpos = 16;

	D3DDEVICE3_Begin_Type ofn = (D3DDEVICE3_Begin_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, d3dpt, dwVertexTypeDesc, dwFlags);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s()\n", d3ddevice3_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall D3DDEVICE3_HOOK_BeginIndexed(LPVOID *ppvOut, D3DPRIMITIVETYPE dptPrimitiveType, DWORD dwVertexTypeDesc, LPVOID lpvVertices, DWORD dwNumVertices, DWORD dwFlags) {
	const unsigned int hpos = 17;

	D3DDEVICE3_BeginIndexed_Type ofn = (D3DDEVICE3_BeginIndexed_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dptPrimitiveType, dwVertexTypeDesc, lpvVertices, dwNumVertices, dwFlags);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s()\n", d3ddevice3_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall D3DDEVICE3_HOOK_Vertex(LPVOID *ppvOut, LPVOID lpVertex) {
	const unsigned int hpos = 18;

	D3DDEVICE3_Vertex_Type ofn = (D3DDEVICE3_Vertex_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpVertex);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s()\n", d3ddevice3_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall D3DDEVICE3_HOOK_Index(LPVOID *ppvOut, WORD wVertexIndex) {
	const unsigned int hpos = 19;

	D3DDEVICE3_Index_Type ofn = (D3DDEVICE3_Index_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, wVertexIndex);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s()\n", d3ddevice3_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall D3DDEVICE3_HOOK_End(LPVOID *ppvOut, DWORD dwFlags) {
	const unsigned int hpos = 20;

	D3DDEVICE3_End_Type ofn = (D3DDEVICE3_End_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwFlags);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s()\n", d3ddevice3_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall D3DDEVICE3_HOOK_GetRenderState(LPVOID *ppvOut, D3DRENDERSTATETYPE dwRenderStateType, LPDWORD lpdwRenderState) {
	const unsigned int hpos = 21;

	D3DDEVICE3_GetRenderState_Type ofn = (D3DDEVICE3_GetRenderState_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwRenderStateType, lpdwRenderState);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s(this=%#010lx, dwRenderStateType=%#010lx (%d), lpdwRenderState=%#010lx)\n", d3ddevice3_hooks[hpos].name, ppvOut, dwRenderStateType, dwRenderStateType, lpdwRenderState);

	return ret;
}

HRESULT __stdcall D3DDEVICE3_HOOK_SetRenderState(LPVOID *ppvOut, D3DRENDERSTATETYPE dwRenderStateType, DWORD dwRenderState) {
	const unsigned int hpos = 22;

	D3DDEVICE3_SetRenderState_Type ofn = (D3DDEVICE3_SetRenderState_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwRenderStateType, dwRenderState);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s(this=%#010lx, dwRenderStateType=%d, dwRenderState=%#010lx)\n", d3ddevice3_hooks[hpos].name, ppvOut, (unsigned int)dwRenderStateType, dwRenderState);

	return ret;
}

HRESULT __stdcall D3DDEVICE3_HOOK_GetLightState(LPVOID *ppvOut, D3DLIGHTSTATETYPE dwLightStateType, LPDWORD lpdwLightState) {
	const unsigned int hpos = 23;

	D3DDEVICE3_GetLightState_Type ofn = (D3DDEVICE3_GetLightState_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwLightStateType, lpdwLightState);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s()\n", d3ddevice3_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall D3DDEVICE3_HOOK_SetLightState(LPVOID *ppvOut, D3DLIGHTSTATETYPE dwLightStateType, DWORD dwLightState) {
	const unsigned int hpos = 24;

	D3DDEVICE3_SetLightState_Type ofn = (D3DDEVICE3_SetLightState_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwLightStateType, dwLightState);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s()\n", d3ddevice3_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall D3DDEVICE3_HOOK_SetTransform(LPVOID *ppvOut, D3DTRANSFORMSTATETYPE dtstTransformStateType, LPD3DMATRIX lpD3DMatrix) {
	const unsigned int hpos = 25;

	D3DDEVICE3_SetTransform_Type ofn = (D3DDEVICE3_SetTransform_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dtstTransformStateType, lpD3DMatrix);
	LogDXError(ret);

	char lpD3DMatrix_buffer[LOGBUFFER_MAX];
	if(lpD3DMatrix != NULL) {
		_snprintf_s(lpD3DMatrix_buffer, LOGBUFFER_MAX, LOGBUFFER_MAX, " { { %.3f, %.3f, %.3f, %.3f }, { %.3f, %.3f, %.3f, %.3f }, { %.3f, %.3f, %.3f, %.3f }, { %.3f, %.3f, %.3f, %.3f } }", lpD3DMatrix->_11, lpD3DMatrix->_12, lpD3DMatrix->_13, lpD3DMatrix->_14, lpD3DMatrix->_21, lpD3DMatrix->_22, lpD3DMatrix->_23, lpD3DMatrix->_24, lpD3DMatrix->_31, lpD3DMatrix->_32, lpD3DMatrix->_33, lpD3DMatrix->_34, lpD3DMatrix->_41, lpD3DMatrix->_42, lpD3DMatrix->_43, lpD3DMatrix->_44);
	} else lpD3DMatrix_buffer[0] = '\0';
	Log("IDirect3DDevice3::%s(this=%#010lx, dtstTransformStateType=%#010lx (%s), lpD3DMatrix=%#010lx%s)\n", d3ddevice3_hooks[hpos].name, ppvOut, dtstTransformStateType, (dtstTransformStateType == D3DTRANSFORMSTATE_WORLD ? "D3DTRANSFORMSTATE_WORLD" : (dtstTransformStateType == D3DTRANSFORMSTATE_VIEW ? "D3DTRANSFORMSTATE_VIEW" : (dtstTransformStateType == D3DTRANSFORMSTATE_PROJECTION ? "D3DTRANSFORMSTATE_PROJECTION" : ""))), lpD3DMatrix, lpD3DMatrix_buffer);

	return ret;
}

HRESULT __stdcall D3DDEVICE3_HOOK_GetTransform(LPVOID *ppvOut, D3DTRANSFORMSTATETYPE dtstTransformStateType, LPD3DMATRIX lpD3DMatrix) {
	const unsigned int hpos = 26;

	D3DDEVICE3_GetTransform_Type ofn = (D3DDEVICE3_GetTransform_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dtstTransformStateType, lpD3DMatrix);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s()\n", d3ddevice3_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall D3DDEVICE3_HOOK_MultiplyTransform(LPVOID *ppvOut, D3DTRANSFORMSTATETYPE dtstTransformStateType, LPD3DMATRIX lpD3DMatrix) {
	const unsigned int hpos = 27;

	D3DDEVICE3_MultiplyTransform_Type ofn = (D3DDEVICE3_MultiplyTransform_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dtstTransformStateType, lpD3DMatrix);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s()\n", d3ddevice3_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall D3DDEVICE3_HOOK_DrawPrimitive(LPVOID *ppvOut, D3DPRIMITIVETYPE dptPrimitiveType, DWORD dwVertexTypeDesc, LPVOID lpvVertices, DWORD dwVertexCount, DWORD dwFlags) {
	const unsigned int hpos = 28;

	D3DDEVICE3_DrawPrimitive_Type ofn = (D3DDEVICE3_DrawPrimitive_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dptPrimitiveType, dwVertexTypeDesc, lpvVertices, dwVertexCount, dwFlags);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s(this=%#010lx, dtpPrimitiveType=%d, dwVertexTypeDesc=%#010lx, lpvVertices=%#010lx, dwVertexCount=%d, dwFlags=%#010lx)\n", d3ddevice3_hooks[hpos].name, ppvOut, (unsigned int)dptPrimitiveType, dwVertexTypeDesc, lpvVertices, dwVertexCount, dwFlags);

	return ret;
}

HRESULT __stdcall D3DDEVICE3_HOOK_DrawIndexedPrimitive(LPVOID *ppvOut, D3DPRIMITIVETYPE d3dptPrimitiveType, DWORD dwVertexTypeDesc, LPVOID lpvVertices, DWORD dwVertexCount, LPWORD lpwIndices, DWORD dwIndexCount, DWORD dwFlags) {
	const unsigned int hpos = 29;

	if(g_config.displaymode >= 0) {
		typedef struct { float x, y, z, rhw; DWORD diffuse, specular; float u, v; } _FF8VERTEX;
		_FF8VERTEX *vert = (_FF8VERTEX *)lpvVertices;

		//Log("vert[0] = {x=%.10f, y=%.10f, z=%.10f, rhw=%.10f, t1=%.10f, t2=%.10f, t3=%.10f, t4=%.10f\n", vert[0].x, vert[0].y, vert[0].z, vert[0].rhw, vert[0].t1, vert[0].t2, vert[0].t3, vert[0].t4 );
		//Log("vert[1] = {x=%.10f, y=%.10f, z=%.10f, rhw=%#010lx, t1=%#010lx, t2=%#010lx, t3=%#010lx, t4=%#010lx\n", vert[1].x, vert[1].y, vert[1].z, vert[0].rhw, vert[1].t1, vert[1].t2, vert[1].t3, vert[1].t4 );

		if(dwVertexCount >= 1) {
			/*float modX = (float)displaymode_options[g_config.displaymode].resX/640.0f;
			float modY = (float)displaymode_options[g_config.displaymode].resY/480.0f;
			float mod = (modX > modY ? modY : modX);*/
			float offsetX = 0;
			float offsetY = 0;
			if(g_config.stretch_4_3_ar == 0) {
				offsetX = (float)(g_currentviewport.x-g_currentviewport.old_x*g_game.mod);
				offsetY = (float)(g_currentviewport.y-g_currentviewport.old_y*g_game.mod);
			} else {
				offsetX = (float)(g_currentviewport.x-g_currentviewport.old_x*g_game.modX);
				offsetY = (float)(g_currentviewport.y-g_currentviewport.old_y*g_game.modY);
			}
			//Log("Mod=%f, OffsetX=%f, OffsetY=%f", g_game.mod, offsetX, offsetY);
			//Log("g_currentviewport { x=%f, y=%f, old_x=%f, old_y=%f }\n", g_currentviewport.x, g_currentviewport.y, g_currentviewport.old_x, g_currentviewport.old_y);

			float b_adjX = 0, b_adjY = 0;
			if(g_config.stretch_4_3_ar == 0) { 
				b_adjX = b_adjY = (g_config.expert_mode >= 1 ? g_config.tex_uvmap_adj_backgrounds : 0.0005f);
			} else {
				b_adjX = (g_config.expert_mode >= 1 ? g_config.tex_uvmap_adj_backgrounds : 0.0005f)*(g_game.modX > g_game.modY ? 1+g_game.modX-g_game.modY : 1);
				b_adjY = (g_config.expert_mode >= 1 ? g_config.tex_uvmap_adj_backgrounds : 0.0005f)*(g_game.modX < g_game.modY ? 1+g_game.modY-g_game.modX : 1);
			}

			float i_adjX = 0, i_adjY = 0;
			if(g_config.stretch_4_3_ar == 0) { 
				i_adjX = i_adjY = (g_config.expert_mode >= 1 ? g_config.tex_uvmap_adj_interface : 0.0005f);
			} else {
				i_adjX = (g_config.expert_mode >= 1 ? g_config.tex_uvmap_adj_interface : 0.0005f)*(g_game.modX > g_game.modY ? 1+g_game.modX-g_game.modY : 1);
				i_adjY = (g_config.expert_mode >= 1 ? g_config.tex_uvmap_adj_interface : 0.0005f)*(g_game.modX < g_game.modY ? 1+g_game.modY-g_game.modX : 1);
			}

			for(DWORD i = 0; i < dwVertexCount; i++) {
				//dwVertexCount%4 == 0: array of squares [x,y / x2,y / x,y2 / x2,y2] with 16x16px texture coords [u2-u=16 / v2-v=16] (the makeup off background textures)
				//vert[i].rhw != 1.0f: exclude interface textures
				//vert[i].z == vert[i+1].z && vert[i].z == vert[i+2].z && vert[i].z == vert[i+3].z: !TEMP! excludes most 3d textures (change if possible) //DOES NOT WORK
				if(dwVertexCount%4 == 0 && vert[i].rhw != 1.0f) { // && vert[i].z == vert[i+1].z && vert[i].z == vert[i+2].z && vert[i].z == vert[i+3].z
					//const float adj = 0.0015f; //adv. 0x0001f in 1280x960+
					if(i%4 == 0) {
						vert[i].u += b_adjX;
						vert[i].v += b_adjY;
					} else if(i%4 == 1) {
						vert[i].u -= b_adjX;
						vert[i].v += b_adjY;
					} else if(i%4 == 2) {
						vert[i].u += b_adjX;
						vert[i].v -= b_adjY;
					} else {
						vert[i].u -= b_adjX;
						vert[i].v -= b_adjY;
					}
				}

				//dwVertexCount%4 == 0: array of squares [x,y / x,y2 / x2,y / x2,y2] with 16x16px texture coords [u2-u=16 / v2-v=16] (the makeup off interface textures) !NOTE! the order of vertices is different from a background texture array
				//vert[i].rhw == 1.0f: exclusively interface textures
				if(dwVertexCount%4 == 0 && vert[i].rhw == 1.0f) {
					//const float adj = 0.0015f;
					if(i%4 == 0) {
						vert[i].u += i_adjX;
						vert[i].v += i_adjY;
					} else if(i%4 == 1) {
						vert[i].u += i_adjX;
						vert[i].v -= i_adjY;
					} else if(i%4 == 2) {
						vert[i].u -= i_adjX;
						vert[i].v += i_adjY;
					} else {
						vert[i].u -= i_adjX;
						vert[i].v -= i_adjY;
					}
				}

				float pt[2] = { vert[i].x, vert[i].y };
				/*if(vert[i].rhw == 1.0f) {
					for(UINT n = 0; n < 2; n++) {
						if(n == 1) continue;
						if(pt[n] < 0) {
							UINT c = (UINT)abs(ceil(pt[n] * 100)) % 100;
							//if(c >= 0 && c < 13) c = 0;
							//else if(c >= 13 && c < 38) c = 25;
							//else if(c >= 38 && c < 63) c = 50;
							//else if(c >= 63 && c < 88) c = 75;
							//else c = 100;
							if(c >= 0 && c < 50) c = 0;
							else c = 100;

							pt[n] = (ceil(pt[n] * 100) - (UINT)ceil(pt[n] * 100) % 100 - c) / 100;
						} else {
							UINT c = (UINT)floor(pt[n] * 100) % 100;
							//if(c >= 0 && c < 13) c = 0;
							//else if(c >= 13 && c < 38) c = 25;
							//else if(c >= 38 && c < 63) c = 50;
							//else if(c >= 63 && c < 88) c = 75;
							//else c = 100;
							if(c >= 0 && c < 50) c = 0;
							else c = 100;

							pt[n] = (floor(pt[n] * 100) - (UINT)floor(pt[n] * 100) % 100 + c) / 100;
						}
					}
				}*/
				if(g_config.stretch_4_3_ar == 0) { 
					vert[i].x  = pt[0]*g_game.mod+offsetX;
					vert[i].y  = pt[1]*g_game.mod+offsetY;
				} else {
					vert[i].x  = pt[0]*g_game.modX+offsetX;
					vert[i].y  = pt[1]*g_game.modY+offsetY;
				}
				Log("vert[%d] = {x=%.10f, y=%.10f, z=%.10f, rhw=%.10f, diffuse=%#010lx, specular=%#010lx, u=%.10f, v=%.10f\n", i, vert[i].x, vert[i].y, vert[i].z, vert[i].rhw, vert[i].diffuse, vert[i].specular, vert[i].u, vert[i].v );
				//if(vert[i].u == 0.0f) vert[i].u = 1.0f/256.0f;
				//if(vert[i].u == 1.0f) vert[i].u = 1.0f-(1.0f/256.0f);
				//if(vert[i].v == 0.0f) vert[i].v = 1.0f/256.0f;
				//if(vert[i].v == 1.0f) vert[i].v = 1.0f-(1.0f/256.0f);
				
				if(g_debugoptions.tex_uvmap_notextures == true) {
					//toggle tex_uvmap_notextures
					vert[i].u = vert[i].v = 0;
				}
			}
		}
	}

	D3DDEVICE3_DrawIndexedPrimitive_Type ofn = (D3DDEVICE3_DrawIndexedPrimitive_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, d3dptPrimitiveType, dwVertexTypeDesc, lpvVertices, dwVertexCount, lpwIndices, dwIndexCount, dwFlags);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s(this=%#010lx, d3dptPrimitiveType=%d, dwVertexTypeDesc=%#010lx, lpvVertices=%#010lx, dwVertexCount=%d, lpwIndices=%#010lx, dwIndexCount=%d, dwFlags=%#010lx)\n", d3ddevice3_hooks[hpos].name, ppvOut, (unsigned int)d3dptPrimitiveType, dwVertexTypeDesc, lpvVertices, dwVertexCount, lpwIndices, dwIndexCount, dwFlags);

	if(g_config.displaymode != 0) {
		typedef struct { float x, y, z, rhw; DWORD t1, t2, t3, t4; } _FF8VERTEX;
		_FF8VERTEX *vert = (_FF8VERTEX *)lpvVertices;

		//Log("vert[0] = {x=%.10f, y=%.10f, z=%.10f, rhw=%.3f, t1=%d, t2=%d, t3=%d, t4=%d\n", vert[0].x, vert[0].y, vert[0].z, vert[0].rhw, vert[0].t1, vert[0].t2, vert[0].t3, vert[0].t4 );
		//Log("vert[1] = {x=%.10f, y=%.10f, z=%.10f, rhw=%.3f, t1=%d, t2=%d, t3=%d, t4=%d\n", vert[1].x, vert[1].y, vert[1].z, vert[0].rhw, vert[1].t1, vert[1].t2, vert[1].t3, vert[1].t4 );
	}

	return ret;
}

HRESULT __stdcall D3DDEVICE3_HOOK_SetClipStatus(LPVOID *ppvOut, LPD3DCLIPSTATUS lpD3DClipStatus) {
	const unsigned int hpos = 30;

	D3DDEVICE3_SetClipStatus_Type ofn = (D3DDEVICE3_SetClipStatus_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpD3DClipStatus);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s()\n", d3ddevice3_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall D3DDEVICE3_HOOK_GetClipStatus(LPVOID *ppvOut, LPD3DCLIPSTATUS lpD3DClipStatus) {
	const unsigned int hpos = 31;

	D3DDEVICE3_GetClipStatus_Type ofn = (D3DDEVICE3_GetClipStatus_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpD3DClipStatus);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s()\n", d3ddevice3_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall D3DDEVICE3_HOOK_DrawPrimitiveStrided(LPVOID *ppvOut, D3DPRIMITIVETYPE dptPrimitiveType, DWORD dwVertexTypeDesc, LPD3DDRAWPRIMITIVESTRIDEDDATA lpVertexArray, DWORD dwVertexCount, DWORD dwFlags) {
	const unsigned int hpos = 32;

	D3DDEVICE3_DrawPrimitiveStrided_Type ofn = (D3DDEVICE3_DrawPrimitiveStrided_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dptPrimitiveType, dwVertexTypeDesc, lpVertexArray, dwVertexCount, dwFlags);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s()\n", d3ddevice3_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall D3DDEVICE3_HOOK_DrawIndexedPrimitiveStrided(LPVOID *ppvOut, D3DPRIMITIVETYPE d3dptPrimitiveType, DWORD dwVertexTypeDesc, LPD3DDRAWPRIMITIVESTRIDEDDATA lpVertexArray, DWORD dwVertexCount, LPWORD lpwIndices, DWORD dwIndexCount, DWORD dwFlags) {
	const unsigned int hpos = 33;

	D3DDEVICE3_DrawIndexedPrimitiveStrided_Type ofn = (D3DDEVICE3_DrawIndexedPrimitiveStrided_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, d3dptPrimitiveType, dwVertexTypeDesc, lpVertexArray, dwVertexCount, lpwIndices, dwIndexCount, dwFlags);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s()\n", d3ddevice3_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall D3DDEVICE3_HOOK_DrawPrimitiveVB(LPVOID *ppvOut, D3DPRIMITIVETYPE d3dptPrimitiveType, LPDIRECT3DVERTEXBUFFER lpd3dVertexBuffer, DWORD dwStartVertex, DWORD dwNumVertices, DWORD dwFlags) {
	const unsigned int hpos = 34;

	D3DDEVICE3_DrawPrimitiveVB_Type ofn = (D3DDEVICE3_DrawPrimitiveVB_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, d3dptPrimitiveType, lpd3dVertexBuffer, dwStartVertex, dwNumVertices, dwFlags);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s()\n", d3ddevice3_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall D3DDEVICE3_HOOK_DrawIndexedPrimitiveVB(LPVOID *ppvOut, D3DPRIMITIVETYPE d3dptPrimitiveType, LPDIRECT3DVERTEXBUFFER lpd3dVertexBuffer, LPWORD lpwIndices, DWORD dwIndexCount, DWORD dwFlags) {
	const unsigned int hpos = 35;

	D3DDEVICE3_DrawIndexedPrimitiveVB_Type ofn = (D3DDEVICE3_DrawIndexedPrimitiveVB_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, d3dptPrimitiveType, lpd3dVertexBuffer, lpwIndices, dwIndexCount, dwFlags);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s()\n", d3ddevice3_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall D3DDEVICE3_HOOK_ComputeSphereVisibility(LPVOID *ppvOut, LPD3DVECTOR lpCenters, LPD3DVALUE lpRadii, DWORD dwNumSpheres, DWORD dwFlags, LPDWORD lpdwReturnValues) {
	const unsigned int hpos = 36;

	D3DDEVICE3_ComputeSphereVisibility_Type ofn = (D3DDEVICE3_ComputeSphereVisibility_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpCenters, lpRadii, dwNumSpheres, dwFlags, lpdwReturnValues);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s()\n", d3ddevice3_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall D3DDEVICE3_HOOK_GetTexture(LPVOID *ppvOut, DWORD dwStage, LPDIRECT3DTEXTURE2 *lplpTexture) {
	const unsigned int hpos = 37;

	D3DDEVICE3_GetTexture_Type ofn = (D3DDEVICE3_GetTexture_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwStage, lplpTexture);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s(this=%#010lx, dwStage=%#010lx, lplpTexture=%#010lx *[%#010lx])\n", d3ddevice3_hooks[hpos].name, ppvOut, dwStage, lplpTexture, (lplpTexture != NULL ? *lplpTexture : NULL));

	return ret;
}


#ifdef _DEBUG_DLL
void SaveDDBToDisk(HDC hDC, HBITMAP hBitmap, const char* fileName)
{
   BITMAP bmp;
   BITMAPINFO bi;
   void* data;
   FILE* fp;
   BITMAPFILEHEADER bmfh;

   // get DDB info
   if(GetObject(hBitmap, sizeof(bmp), &bmp) == 0) {
		Log("GetObject() FAILED!\n");
   }

   // Convert the HBITMAP into a DIB
   bi.bmiHeader.biSize = sizeof(BITMAPINFO);
   bi.bmiHeader.biWidth = bmp.bmWidth;
   bi.bmiHeader.biHeight = bmp.bmHeight;
   bi.bmiHeader.biPlanes = 1;
   bi.bmiHeader.biBitCount = 24;
   bi.bmiHeader.biCompression = BI_RGB;
   bi.bmiHeader.biSizeImage = 0;
   bi.bmiHeader.biXPelsPerMeter = 0;
   bi.bmiHeader.biYPelsPerMeter = 0;
   bi.bmiHeader.biClrUsed = 0;
   bi.bmiHeader.biClrImportant = 0;
   if(GetDIBits(hDC, hBitmap, 0, bmp.bmHeight, NULL, &bi, DIB_RGB_COLORS) == 0) {
		Log("GetDIBits(size) FAILED!\n");
   }
   // GetDIBits filled in bi.bmiHeader.biSizeImage, allocate memory and now get the DIB bits
   data = malloc(bi.bmiHeader.biSizeImage);

   if(GetDIBits(hDC, hBitmap, 0, bmp.bmHeight, data, &bi, DIB_RGB_COLORS) == 0) {
		Log("GetDIBits() FAILED!\n");
   }
   // Now save into disk file.
   fp = fopen(fileName, "wb");

   // First, the bitmap file header
   bmfh.bfType = *(WORD*)"BM";
   bmfh.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + bi.bmiHeader.biSizeImage;
   bmfh.bfReserved1 = 0;
   bmfh.bfReserved2 = 0;
   bmfh.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

   fwrite(&bmfh, sizeof(BITMAPFILEHEADER), 1, fp);

   // Next, the bitmap info header
   fwrite(&bi.bmiHeader, sizeof(BITMAPINFOHEADER), 1, fp);

   // Finally, the data itself
   fwrite(data, sizeof(BYTE), bi.bmiHeader.biSizeImage, fp);
   Log("fwrite(%#010lx, %d, %d)\n", data, sizeof(BYTE), bi.bmiHeader.biSizeImage);

   fclose(fp);
   free(data);
}
#endif

HRESULT __stdcall D3DDEVICE3_HOOK_SetTexture(LPVOID *ppvOut, DWORD dwStage, LPDIRECT3DTEXTURE2 lpTexture) {
	const unsigned int hpos = 38;

#ifdef _DEBUG_DLL
	std::ifstream ifs;
	char buf[MAX_PATH];
	_snprintf_s(buf, MAX_PATH, MAX_PATH, "textures\\%#010lx.bmp", (DWORD)lpTexture);
	ifs.open(buf);
	if(ifs.is_open()) {
		ifs.close();
	} else {
		//does not exist
		std::map<LPVOID, LPVOID>::const_iterator tex = textures.find((LPVOID)lpTexture);
		if(!(tex == textures.end())) {
			LPDIRECTDRAWSURFACE4 pDDSurface = (LPDIRECTDRAWSURFACE4)tex->second;
			Log("SAVING TEXTURE %#010lx.bmp TO DISK... (SURFACE=%#010lx)\n", lpTexture, pDDSurface);

			HDC hdc, hmemdc;
			HBITMAP hbitmap;
			HRESULT r;
			HGDIOBJ hPrev;
			DDSURFACEDESC2 ddsd;
			ddsd.dwSize = sizeof(DDSURFACEDESC2);
			if(S_OK != pDDSurface->GetSurfaceDesc(&ddsd)) {
					Log("pDDSurface->GetSurfaceDesc() FAILED!\n");
			}

			if((r = pDDSurface->GetDC(&hdc)) != S_OK) {
				Log("pDDSurface->GetDC() FAILED!\n");
			}
			if((hmemdc=CreateCompatibleDC(hdc)) == NULL) {
				Log("CreateCompatibleDC() FAILED!\n");
			}
			if((hbitmap=CreateCompatibleBitmap(hdc, ddsd.dwWidth, ddsd.dwHeight)) == NULL) {
				Log("CreateCompatibleBitmap() FAILED!\n");
			}

			if(!(hPrev = SelectObject(hmemdc, hbitmap))) {
				Log("SelectObject() FAILED!\n");
			}

			if(BitBlt(hmemdc, 0, 0, ddsd.dwWidth , ddsd.dwHeight , hdc ,0 ,0,SRCCOPY) == 0) {
				Log("BitBlt() FAILED!\n");
			}
			if(!(hPrev = SelectObject(hmemdc, hPrev))) {
				Log("SelectObject(prev) FAILED!\n");
			}

			SaveDDBToDisk(hmemdc, hbitmap, buf);

			DeleteDC(hmemdc);

			pDDSurface->ReleaseDC(hdc);
		} else {
			Log("COULD NOT LOCATE SURFACE ASSOCIATED WITH TEXTURE!\n");
		}
	}
#endif

	D3DDEVICE3_SetTexture_Type ofn = (D3DDEVICE3_SetTexture_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwStage, lpTexture);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s(this=%#010lx, dwStage=%#010lx, lpTexture=%#010lx)\n", d3ddevice3_hooks[hpos].name, ppvOut, dwStage, lpTexture);

	return ret;
}

HRESULT __stdcall D3DDEVICE3_HOOK_GetTextureStageState(LPVOID *ppvOut, DWORD dwStage, D3DTEXTURESTAGESTATETYPE dwState, LPDWORD lpdwValue) {
	const unsigned int hpos = 39;

	D3DDEVICE3_GetTextureStageState_Type ofn = (D3DDEVICE3_GetTextureStageState_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwStage, dwState, lpdwValue);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s()\n", d3ddevice3_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall D3DDEVICE3_HOOK_SetTextureStageState(LPVOID *ppvOut, DWORD dwStage, D3DTEXTURESTAGESTATETYPE dwState, DWORD dwValue) {
	const unsigned int hpos = 40;

	D3DDEVICE3_SetTextureStageState_Type ofn = (D3DDEVICE3_SetTextureStageState_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwStage, dwState, dwValue);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s()\n", d3ddevice3_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall D3DDEVICE3_HOOK_ValidateDevice(LPVOID *ppvOut, LPDWORD lpdwPasses) {
	const unsigned int hpos = 41;

	D3DDEVICE3_ValidateDevice_Type ofn = (D3DDEVICE3_ValidateDevice_Type)d3ddevice3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpdwPasses);
	LogDXError(ret);

	Log("IDirect3DDevice3::%s(this=%#010lx, lpdwPasses=%#010lx)\n", d3ddevice3_hooks[hpos].name, ppvOut, lpdwPasses);

	return ret;
}