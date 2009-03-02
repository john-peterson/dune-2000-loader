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

#include "flags.h"
//-------------
//Windows
//-------------
PAIR_FLAG FLAGS_WS[] = {
	pf(WS_BORDER), pf(WS_CAPTION), pf(WS_CHILD), pf(WS_CHILDWINDOW), pf(WS_CLIPCHILDREN),
	pf(WS_CLIPSIBLINGS), pf(WS_DISABLED), pf(WS_DLGFRAME), pf(WS_GROUP), pf(WS_HSCROLL),
	pf(WS_ICONIC), pf(WS_MAXIMIZE), pf(WS_MAXIMIZEBOX), pf(WS_MINIMIZE), pf(WS_MINIMIZEBOX),
	pf(WS_OVERLAPPED), pf(WS_OVERLAPPEDWINDOW), pf(WS_POPUP), pf(WS_POPUPWINDOW), pf(WS_SIZEBOX),
	pf(WS_SYSMENU), pf(WS_TABSTOP), pf(WS_THICKFRAME), pf(WS_TILED), pf(WS_TILEDWINDOW),
	pf(WS_VISIBLE), pf(WS_VSCROLL)
};
UINT CFLAGS_WS = sizeof(FLAGS_WS)/sizeof(FLAGS_WS[0]);

PAIR_FLAG FLAGS_WS_EX[] = {
	pf(WS_EX_ACCEPTFILES), pf(WS_EX_APPWINDOW), pf(WS_EX_CLIENTEDGE),/* pf(WS_EX_COMPOSITED),*/ pf(WS_EX_CONTEXTHELP),
	pf(WS_EX_CONTROLPARENT), pf(WS_EX_DLGMODALFRAME),/* pf(WS_EX_LAYERED),*/ pf(WS_EX_LAYOUTRTL), pf(WS_EX_LEFT),
	pf(WS_EX_LEFTSCROLLBAR), pf(WS_EX_LTRREADING), pf(WS_EX_MDICHILD),/* pf(WS_EX_NOACTIVATE),*/ pf(WS_EX_NOINHERITLAYOUT),
	pf(WS_EX_NOPARENTNOTIFY), pf(WS_EX_OVERLAPPEDWINDOW), pf(WS_EX_PALETTEWINDOW), pf(WS_EX_RIGHT), pf(WS_EX_RIGHTSCROLLBAR),
	pf(WS_EX_RTLREADING), pf(WS_EX_STATICEDGE), pf(WS_EX_TOOLWINDOW), pf(WS_EX_TOPMOST), pf(WS_EX_TRANSPARENT),
	pf(WS_EX_WINDOWEDGE)
};
UINT CFLAGS_WS_EX = sizeof(FLAGS_WS_EX)/sizeof(FLAGS_WS_EX[0]);

//-------------
//DirectX
//-------------
PAIR_FLAG FLAGS_DDSCAPS1[] = {
	pf(DDSCAPS_3DDEVICE), pf(DDSCAPS_ALLOCONLOAD), pf(DDSCAPS_ALPHA), pf(DDSCAPS_BACKBUFFER), pf(DDSCAPS_COMPLEX),
	pf(DDSCAPS_FLIP), pf(DDSCAPS_FRONTBUFFER), pf(DDSCAPS_HWCODEC), pf(DDSCAPS_LIVEVIDEO), pf(DDSCAPS_LOCALVIDMEM),
	pf(DDSCAPS_MIPMAP), pf(DDSCAPS_MODEX), pf(DDSCAPS_NONLOCALVIDMEM), pf(DDSCAPS_OFFSCREENPLAIN), pf(DDSCAPS_OPTIMIZED),
	pf(DDSCAPS_OVERLAY), pf(DDSCAPS_OWNDC), pf(DDSCAPS_PALETTE), pf(DDSCAPS_PRIMARYSURFACE), pf(DDSCAPS_PRIMARYSURFACELEFT),
	pf(DDSCAPS_STANDARDVGAMODE), pf(DDSCAPS_SYSTEMMEMORY), pf(DDSCAPS_TEXTURE), pf(DDSCAPS_VIDEOMEMORY), pf(DDSCAPS_VIDEOPORT),
	pf(DDSCAPS_VISIBLE), pf(DDSCAPS_WRITEONLY), pf(DDSCAPS_ZBUFFER)
};
UINT CFLAGS_DDSCAPS1 = sizeof(FLAGS_DDSCAPS1)/sizeof(FLAGS_DDSCAPS1[0]);

PAIR_FLAG FLAGS_DDSD[] = {
	pf(DDSD_ALL), pf(DDSD_ALPHABITDEPTH), pf(DDSD_BACKBUFFERCOUNT), pf(DDSD_CAPS), pf(DDSD_CKDESTBLT),
	pf(DDSD_CKDESTOVERLAY), pf(DDSD_CKSRCBLT), pf(DDSD_CKSRCOVERLAY), pf(DDSD_HEIGHT), pf(DDSD_LINEARSIZE),
	pf(DDSD_LPSURFACE), pf(DDSD_MIPMAPCOUNT), pf(DDSD_PITCH), pf(DDSD_PIXELFORMAT), pf(DDSD_REFRESHRATE),
	pf(DDSD_TEXTURESTAGE), pf(DDSD_WIDTH), pf(DDSD_ZBUFFERBITDEPTH)
};
UINT CFLAGS_DDSD = sizeof(FLAGS_DDSD)/sizeof(FLAGS_DDSD[0]);

PAIR_FLAG FLAGS_DDPCAPS[] = {
	pf(DDPCAPS_1BIT), pf(DDPCAPS_2BIT), pf(DDPCAPS_4BIT), pf(DDPCAPS_8BIT), pf(DDPCAPS_8BITENTRIES),
	pf(DDPCAPS_ALPHA), pf(DDPCAPS_ALLOW256), pf(DDPCAPS_INITIALIZE), pf(DDPCAPS_PRIMARYSURFACE),
	pf(DDPCAPS_PRIMARYSURFACELEFT), pf(DDPCAPS_VSYNC)
};
UINT CFLAGS_DDPCAPS = sizeof(FLAGS_DDPCAPS)/sizeof(FLAGS_DDPCAPS[0]);

PAIR_FLAG FLAGS_D3DCLEAR[] = {
	pf(D3DCLEAR_TARGET), pf(D3DCLEAR_ZBUFFER)
};
UINT CFLAGS_D3DCLEAR = sizeof(FLAGS_D3DCLEAR)/sizeof(FLAGS_D3DCLEAR[0]);

PAIR_FLAG FLAGS_D3DFVF[] = {
	pf(D3DFVF_RESERVED0), pf(D3DFVF_POSITION_MASK), pf(D3DFVF_XYZ), pf(D3DFVF_XYZRHW), pf(D3DFVF_NORMAL), pf(D3DFVF_RESERVED1), pf(D3DFVF_DIFFUSE), pf(D3DFVF_SPECULAR), pf(D3DFVF_TEXCOUNT_MASK), pf(D3DFVF_TEXCOUNT_SHIFT), pf(D3DFVF_TEX0), pf(D3DFVF_TEX1), pf(D3DFVF_TEX2), pf(D3DFVF_TEX3), pf(D3DFVF_TEX4), pf(D3DFVF_TEX5), pf(D3DFVF_TEX6), pf(D3DFVF_TEX7), pf(D3DFVF_TEX8), pf(D3DFVF_RESERVED2)
};
UINT CFLAGS_D3DFVF = sizeof(FLAGS_D3DFVF)/sizeof(FLAGS_D3DFVF[0]);

PAIR_FLAG FLAGS_DDPF[] = {
	pf(DDPF_ALPHAPIXELS), pf(DDPF_ALPHA), pf(DDPF_FOURCC), pf(DDPF_PALETTEINDEXED4), pf(DDPF_PALETTEINDEXEDTO8), pf(DDPF_PALETTEINDEXED8), pf(DDPF_RGB), pf(DDPF_COMPRESSED), pf(DDPF_RGBTOYUV), pf(DDPF_YUV), pf(DDPF_ZBUFFER), pf(DDPF_PALETTEINDEXED1), pf(DDPF_PALETTEINDEXED2), pf(DDPF_ZPIXELS), pf(DDPF_STENCILBUFFER), pf(DDPF_ALPHAPREMULT), pf(DDPF_LUMINANCE), pf(DDPF_BUMPLUMINANCE), pf(DDPF_BUMPDUDV)
};
UINT CFLAGS_DDPF = sizeof(FLAGS_DDPF)/sizeof(FLAGS_DDPF[0]);

void FlagsToString(PAIR_FLAG FLAGS[], UINT num, DWORD dwFlags, char *buffer, UINT size) {
	if(size <= 0) return;
	buffer[0] = '\0'; //make print safe

	unsigned int at = 0;

	for(UINT i = 0; i < num; i++) {
		if((dwFlags & FLAGS[i].first) == FLAGS[i].first) at += _snprintf_s(buffer+at, size-at, size-at, "%s%s", (at > 0 ? " | " : ""), FLAGS[i].second);
	}
}