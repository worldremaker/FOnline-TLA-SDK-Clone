#include "fonline_tla.h"

// Engine data
GameOptions* Game;
asIScriptEngine* ASEngine;
void (*Log)(const char* frmt, ...);

// Extern data definition
_GlobalVars GlobalVars;

// Test function
EXPORT void TestFunc(ScriptString& str)
{
	Log("TEST %s", str.Buffer.c_str());
}
