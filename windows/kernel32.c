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
void Win_GetFileSize(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	ReturnValue->Val->UnsignedInteger = GetFileSize(Param[0]->Val->Pointer, Param[1]->Val->Pointer);
}
void Win_CloseHandle(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	ReturnValue->Val->Integer = CloseHandle(Param[0]->Val->Pointer);
}
void Win_CreateFileA(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	ReturnValue->Val->Pointer = CreateFileA(Param[0]->Val->Pointer, Param[1]->Val->UnsignedInteger, Param[2]->Val->UnsignedInteger, Param[3]->Val->Pointer, Param[4]->Val->UnsignedInteger, Param[5]->Val->UnsignedInteger, Param[6]->Val->Pointer);
}
void Win_ReadFile(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	ReturnValue->Val->Integer = ReadFile(Param[0]->Val->Pointer, Param[1]->Val->Pointer, Param[2]->Val->UnsignedInteger, Param[3]->Val->Pointer, Param[4]->Val->Pointer);
}
void Win_WriteFile(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	ReturnValue->Val->Integer = WriteFile(Param[0]->Val->Pointer, Param[1]->Val->Pointer, Param[2]->Val->UnsignedInteger, Param[3]->Val->Pointer, Param[4]->Val->Pointer);
}
void Win_SetFilePointer(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	ReturnValue->Val->UnsignedInteger = SetFilePointer(Param[0]->Val->Pointer, Param[1]->Val->LongInteger, Param[2]->Val->Pointer, Param[3]->Val->UnsignedInteger);	
}
void Win_SetEndOfFile(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	ReturnValue->Val->Integer = SetEndOfFile(Param[0]->Val->Pointer);
}
void Win_MoveFileA(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{	
	ReturnValue->Val->Integer = MoveFileA(Param[0]->Val->Pointer, Param[1]->Val->Pointer); 
}
void Win_FindFirstFileA(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	ReturnValue->Val->Pointer = FindFirstFileA(Param[0]->Val->Pointer, Param[1]->Val->Pointer);
}
void Win_FindNextFileA(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	ReturnValue->Val->Integer = FindNextFileA(Param[0]->Val->Pointer, Param[1]->Val->Pointer);
}
void Win_FindClose(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	ReturnValue->Val->Integer = FindClose(Param[0]->Val->Pointer); 
}
void Win_LoadLibraryA(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	ReturnValue->Val->Pointer = LoadLibraryA(Param[0]->Val->Pointer);
}
void Win_GetProcAddress(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	ReturnValue->Val->Pointer = GetProcAddress(Param[0]->Val->Pointer, Param[1]->Val->Pointer);
}
void Win_GetLocalTime(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	GetLocalTime((LPSYSTEMTIME)Param[0]->Val->Pointer);
}
void Win_GetSystemTime(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	GetSystemTime((LPSYSTEMTIME)Param[0]->Val->Pointer);
}
#endif