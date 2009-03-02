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

#ifndef _DLLMAIN_H
#define _DLLMAIN_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <shlwapi.h>
#include <ddraw.h>
#include <stdio.h>
#include "apihijack.h"
#include "../D2k_Loader/config.h"
#include "DDraw_hooks.h"
#include "DInput_hooks.h"
#include "HOOKS_BASE.h"

typedef HRESULT (__stdcall *DirectDrawCreate_Type)(GUID FAR *, LPDIRECTDRAW FAR *, IUnknown FAR *);
HRESULT __stdcall MyDirectDrawCreate(GUID FAR *lpGUID, LPDIRECTDRAW FAR *lplpDD, IUnknown FAR *pUnkOuter);
typedef HRESULT (__stdcall *DirectInputCreateA_Type)(HINSTANCE, DWORD, LPDIRECTINPUT *, LPUNKNOWN);
HRESULT __stdcall MyDirectInputCreateA(HINSTANCE, DWORD, LPDIRECTINPUT *, LPUNKNOWN);
typedef void *(__stdcall *BinkOpen_Type)(HANDLE, UINT32);
void * WINAPI MyBinkOpen(HANDLE, UINT32);
typedef void (__stdcall *BinkClose_Type)(void *);
void __stdcall MyBinkClose(void *);

#endif