#ifdef _WIN32 
#include "../interpreter.h"
#include <Windows.h>

void Win_MessageBoxA(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{ 
	ReturnValue->Val->Integer = MessageBoxA(Param[0]->Val->Pointer, Param[1]->Val->Pointer, Param[2]->Val->Pointer, Param[3]->Val->UnsignedInteger);
}

#endif