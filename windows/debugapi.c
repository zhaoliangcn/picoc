#ifdef _WIN32 
#include "../interpreter.h"
#include <Windows.h>

void Win_OutputDebugStringA(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	OutputDebugStringA(Param[0]->Val->Pointer);
}
#endif