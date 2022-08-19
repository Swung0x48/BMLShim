#pragma once
#include "ModInfo.h"

extern "C" __declspec(dllexport) int add(int a, int b);
extern "C" __declspec(dllexport) ModInfo* GetModInfo(const char* path);
