#ifdef _WIN32 
#include "../interpreter.h"
#include <Windows.h>

const char WinDefs[] = "\
						 #define MB_OK                       0x00000000L \n\
						 #define MB_OKCANCEL                 0x00000001L\
						 ";

struct LibraryFunction Win_Functions[] =
{
	{ Win_MessageBoxA,       "int MessageBoxA(void * hWnd, char * lpText, char * lpCaption, unsigned int uType);" },
	{ Win_OutputDebugStringA, "void OutputDebugStringA(char * message);" },
	{ Win_CopyFileA, "int CopyFileA(char * lpExistingFileName,char *, int bFailIfExists);" },
	{ Win_DeleteFileA, "int DeleteFileA(char * lpFileName);" },
	{ Win_GetFileAttributesA, "unsigned int GetFileAttributesA(char *lpFileName);" },
	{ Win_SetFileAttributesA, "unsigned int SetFileAttributesA(char *lpFileName,unsigned int dwFileAttributes);" },
	{ NULL,             NULL }
};
#endif