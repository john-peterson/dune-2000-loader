// Common functions
// (C) John Peterson, licensed under GNU GPL 3

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <time.h>
#include <sys/timeb.h>
using namespace std;

typedef unsigned __int8 u8;
typedef unsigned __int16 u16;
typedef unsigned __int32 u32;
typedef unsigned __int64 u64;

typedef signed __int8 s8;
typedef signed __int16 s16;
typedef signed __int32 s32;
typedef signed __int64 s64;

#define DIR_SEP "/"
#define DIR_SEP_CHR '/'

string ShowError();
void OutputDebugStringEx(const wchar_t* format, ...);
string ArrayToString(const u8 *data, u32 size, u32 offset = 0, int line_len = 20, bool Space = true);
wstring Format(const wchar_t *fmt, ...);

wstring GetCurrentDirectoryEx();
wstring GetPath(const wstring full_path);
bool FileExist(wstring filename);

bool CharArrayFromFormatV(char* out, int outsize, const char* format, va_list args);
bool MsgBox(const char* format, ...);

void Open(int width = 80, int height = 60, char* fname = "Log");
int Print(const char *fmt, ...);
int PrintFile(int a, const char *fmt, ...);
void ClearFile();

string GetTimeFormatted();

// non-unicode
void OutputDebugStringExA(const char* format, ...);
string GetCurrentDirectoryExA();
string FormatA(const char* format, ...);
string GetPathA(const wstring full_path);