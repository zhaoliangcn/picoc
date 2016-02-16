#ifdef _WIN32 
#include "../interpreter.h"
#include <Windows.h>

void Win_CopyFileA(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{	
	ReturnValue->Val->Integer = CopyFileA(Param[0]->Val->Pointer, Param[1]->Val->Pointer, Param[2]->Val->Integer);
}
void Win_DeleteFileA(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	ReturnValue->Val->Integer = DeleteFileA(Param[0]->Val->Pointer);
}
void Win_GetFileAttributesA(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	ReturnValue->Val->UnsignedInteger = GetFileAttributesA(Param[0]->Val->Pointer);
}
void Win_SetFileAttributesA(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	ReturnValue->Val->UnsignedInteger = SetFileAttributesA(Param[0]->Val->Pointer, Param[1]->Val->UnsignedInteger);
}
#endif