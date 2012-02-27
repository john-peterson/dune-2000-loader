// This file is part of Dune 2000 Launcher, licensed under GNU GPL 3
#pragma once

#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <string>
#include <fstream>
#include <sstream>

#define FF8_CONFIG_FILE _T("config.cfg")

struct FF8Config {
	UINT displaymode;
	UINT fsaa;
	UINT b8_paletted_textures_fix;
	UINT expert_mode;
	float tex_uvmap_adj_backgrounds;
	float tex_uvmap_adj_interface;
	UINT stretch_4_3_ar;
};

//not used (delete?)
#define FF8CONFIG_WS_NORMAL 0
#define FF8CONFIG_WS_16_10 1
#define FF8CONFIG_WS_16_9 2

struct FF8Config_DispMode {
	_TCHAR *name;
	UINT resX;
	UINT resY;
	UINT bpp;
	UINT wide;
};

struct FF8Config_FSAA {
	_TCHAR *name;
	UINT mode;
};

extern FF8Config g_config;
extern FF8Config_DispMode displaymode_options[];
extern UINT displaymode_options_count;
extern FF8Config_FSAA fsaa_options[];
extern UINT fsaa_options_count;

typedef std::basic_string<_TCHAR, std::char_traits<_TCHAR> > tstring;
typedef std::basic_ifstream<_TCHAR, std::char_traits<_TCHAR> > tifstream;
typedef std::basic_ofstream<_TCHAR, std::char_traits<_TCHAR> > tofstream;
typedef std::basic_stringstream<_TCHAR, std::char_traits<_TCHAR> > tstringstream;

int LoadConfig(FF8Config &cfg);
int SaveConfig(FF8Config &cfg);
int parseInt(_TCHAR *str);
float parseFloat(_TCHAR *str);