// (C) John Peterson, licensed under GNU GPL 3
//Direct Draw Wrapper
//by 2ci-
//http://2ci.elitecoders.org
//http://www.elitecoders.org
//www.game-deception.com
//Converted from Direct Draw 4 to 7 by Temp2 27 March 2006
#pragma once

#include <windows.h>
#include <ddraw.h>
#pragma comment( lib, "ddraw.lib" )
#pragma  comment( lib, "dxguid.lib" )
#include "detours.h"
#include "../Common/Common.h"
#include "AddLog.h"
#include "IDirectDraw.h"
#include "IDirectDrawSurface7.h"

#define DD_EXPORT

typedef HRESULT ( WINAPI *DirectDrawCreate_t ) ( GUID FAR *, LPDIRECTDRAW FAR *, IUnknown FAR * );
extern DirectDrawCreate_t pDirectDrawCreate;
HRESULT WINAPI DirectDrawCreate_Hook( GUID FAR *lpGUID, LPDIRECTDRAW FAR *lplpDD, IUnknown FAR *pUnkOuter );
