// This file is part of Dune 2000 Launcher, licensed under GNU GPL 3

#include "config.h"

FF8Config g_config;

FF8Config_DispMode displaymode_options[] =
{
	{ _T("640x480 (16-bpp FS 4:3) [Original Resolution]"), 640, 480, 16 },
	{ _T("800x600 (16-bpp FS 4:3)"), 800, 600, 16 },
	{ _T("1024x768 (16-bpp FS 4:3)"), 1024, 768, 16 },
	{ _T("1152x864 (16-bpp FS 4:3)"), 1152, 864, 16 },
	{ _T("1280x720 (16-bpp WS 16:9)"), 1280, 720, 16 },
	{ _T("1280x768 (16-bpp WS 1.67:1)"), 1280, 720, 16 },
	{ _T("1280x800 (16-bpp WS 16:10)"), 1280, 800, 16 },
	{ _T("1280x960 (16-bpp FS 4:3) [x2]"), 1280, 960, 16 },
	{ _T("1280x1024 (16-bpp FS 5:4) [x2]"), 1280, 1024, 16 },
	{ _T("1360x768 (16-bpp WS 16:9)"), 1360, 768, 16 },
	{ _T("1366x768 (16-bpp WS 16:9)"), 1366, 768, 16 },
	{ _T("1440x900 (16-bpp WS 16:10)"), 1440, 900, 16 },
	{ _T("1600x900 (16-bpp WS 16:9)"), 1600, 900, 16 },
	{ _T("1600x1200 (16-bpp FS 4:3)"), 1600, 1200, 16 },
	{ _T("1680x1050 (16-bpp WS 16:10)"), 1680, 1050, 16 },
	{ _T("1920x1080 (16-bpp WS 16:9)"), 1920, 1080, 16 },
	{ _T("1920x1200 (16-bpp WS 16:10)"), 1920, 1200, 16 },
	{ _T("1920x1440 (16-bpp FS 4:3) [x3]"), 1920, 1440, 16 },
	{ _T("2048x1536 (16-bpp FS 4:3)"), 2048, 1536, 16 },
	{ _T("2560x1600 (16-bpp WS 16:10)"), 2560, 1600, 16 },
	{ _T("2560x1920 (16-bpp FS 4:3) [x4]"), 2560, 1920, 16 },
};
UINT displaymode_options_count = sizeof(displaymode_options)/sizeof(displaymode_options[0]);

FF8Config_FSAA fsaa_options[] =
{
	{ _T("Use global setting"), 0},
	{ _T("4x FSAA"), 4},
};
UINT fsaa_options_count = sizeof(fsaa_options)/sizeof(fsaa_options[0]);

int LoadConfig(FF8Config &cfg)
{
	_TCHAR buffer[200];
	tifstream ifs;
	ifs.open(FF8_CONFIG_FILE);
	if(ifs) {
		while(ifs.getline(buffer, 200, _T('\n'))) { // EOF or failure stops the reading
			UINT at = 0;
			_TCHAR *val = NULL;
			while(buffer[at] != _T('\0')) {
				if(buffer[at] == _T('=')) {
					buffer[at] = _T('\0');
					val =&(buffer[at+1]);
					break;
				}
				at++;
			}

			if(val != NULL)
			{
				//Displaymode
				if(_tcscmp(_T("displaymode"), buffer) == 0) {
					cfg.displaymode = parseInt(val);
				//FSAA
				} else if(_tcscmp(_T("fsaa"), buffer) == 0) {
					cfg.fsaa = parseInt(val);
				//8-bit Paletted Textures
				} else if(_tcscmp(_T("8bit_paletted_textures_fix"), buffer) == 0) {
					cfg.b8_paletted_textures_fix = parseInt(val);
				//Stretch 4:3 Aspect Ratio
				} else if(_tcscmp(_T("stretch_4:3_ar"), buffer) == 0) {
					cfg.stretch_4_3_ar = parseInt(val);
				//expert mode
				} else if(_tcscmp(_T("expert_mode"), buffer) == 0) {
					cfg.expert_mode = parseInt(val);
				//expert mode: uvmapping_comp_backgrounds
				} else if(_tcscmp(_T("expert_tex_uvmap_adj_backgrounds"), buffer) == 0) {
					cfg.tex_uvmap_adj_backgrounds = parseFloat(val);
				//expert mode: uvmapping_comp_interface
				} else if(_tcscmp(_T("expert_tex_uvmap_adj_interface"), buffer) == 0) {
					cfg.tex_uvmap_adj_interface = parseFloat(val);
				}
			}
		}
		ifs.close();
	}

	return 1;
}

int SaveConfig(FF8Config &cfg) {
	tofstream ofs;
	ofs.open(FF8_CONFIG_FILE);
	if(ofs) {
		ofs << "displaymode=" << cfg.displaymode << "\n";
		ofs << "fsaa=" << cfg.fsaa << "\n";
		ofs << "8bit_paletted_textures_fix=" << cfg.b8_paletted_textures_fix << "\n";
		ofs << "stretch_4:3_ar=" << cfg.stretch_4_3_ar << "\n";
		ofs << "expert_mode=" << cfg.expert_mode << "\n";
		ofs << "expert_tex_uvmap_adj_backgrounds=" << cfg.tex_uvmap_adj_backgrounds << "\n";
		ofs << "expert_tex_uvmap_adj_interface=" << cfg.tex_uvmap_adj_interface << "\n";

		ofs.close();
	}

	return 1;	
}

int parseInt(_TCHAR *str) {
	tstringstream ss;
	int i;
	ss << str;
	ss >> i;

	return i;
}

float parseFloat(_TCHAR *str) {
	tstringstream ss;
	float i;
	ss << str;
	ss >> i;

	return i;
}