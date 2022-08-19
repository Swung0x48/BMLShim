#include "pch.h"
#include "exports.h"
#include "IMod.h"
#include "IBML.h"

typedef IMod* (*EntryFunc)(IBML*);
int add(int a, int b) {
	return a + b;
}

ModInfo g_Info;
ModInfo* GetModInfo(const char* path)
{
	HMODULE handle = LoadLibraryEx(path, NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
	if (!handle) {
		return nullptr;
	}
	EntryFunc entry = reinterpret_cast<EntryFunc>(GetProcAddress(handle, "BMLEntry"));
	IMod* mod = entry(nullptr);
	g_Info.ID = mod->GetID();
	g_Info.Name = mod->GetName();
	g_Info.Version = mod->GetVersion();
	g_Info.Author = mod->GetAuthor();
	BMLVersion version = mod->GetBMLVersion();
	g_Info.BMLMajor = mod->GetBMLVersion().major;
	g_Info.BMLMinor = mod->GetBMLVersion().minor;
	g_Info.BMLBuild = mod->GetBMLVersion().build;
	return &g_Info;
}
