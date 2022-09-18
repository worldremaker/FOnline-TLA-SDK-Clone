#include "fonline.h"
#include "fonline_tla.h"

extern "C" __declspec(dllexport) GameOptions* GameOpt;
extern "C" __declspec(dllexport) asIScriptEngine* ASEngine;

int __stdcall DllMain(void* module, unsigned long reason, void* reserved)
{
	// In this function all global variables is NOT initialized, use DllMainEx instead
	return 1;
}

extern "C" __declspec(dllexport) void __cdecl DllMainEx(bool compiler)
{
	// bool compiler - true if script compiled using ASCompiler, false if script compiled in server
	// In this function all global variables is initialized
}

extern "C" __declspec(dllexport) bool __cdecl _AllowSlotHand1(uint8 slot, Item& item, Critter& fromCr, Critter& toCr)
{
	return toCr.Params[PE_AWARENESS]!=0;
}











