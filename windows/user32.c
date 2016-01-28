#ifdef _WIN32 
#include "../interpreter.h"
#include <Windows.h>

const char WinDefs[] = "\
						 #define MB_OK                       0x00000000L \n\
						 #define MB_OKCANCEL                 0x00000001L\
						 ";

void Win_MessageBoxA(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	ReturnValue->Val->Integer = MessageBoxA(Param[0]->Val->Pointer, Param[1]->Val->Pointer, Param[2]->Val->Pointer, Param[3]->Val->UnsignedInteger);
}
struct LibraryFunction Win_Functions[] =
{
	{ Win_MessageBoxA,       "int MessageBoxA(void * hWnd, char * lpText, char * lpCaption, unsigned int uType);" },
	{ NULL,             NULL }
};
#endif