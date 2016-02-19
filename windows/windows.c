#ifdef _WIN32 
#include "../interpreter.h"
#include <Windows.h>

const char WinDefs[] = "\
						typedef long LONG_PTR ;\r\n\
						typedef long * PLONG_PTR;\r\n\
					   #define INVALID_HANDLE_VALUE ((HANDLE)(LONG_PTR)-1) \r\n\
					   #define MAX_PATH          (260)	  \r\n\
					   #define MB_OK 0x00000000L		\r\n\
					   #define MB_OKCANCEL 0x00000001L \r\n\
					   typedef char CHAR;				\r\n\
					   typedef unsigned short WORD;	\r\n\
					   typedef void * HANDLE;			\r\n\
					   typedef void * HMODULE;			\r\n\
					   typedef unsigned int DWORD;		\r\n\
					   #define CREATE_ALWAYS		(2) \r\n \
					   #define OPEN_ALWAYS			(4) \r\n \
					   #define CREATE_NEW          (1) \r\n \
					   #define OPEN_EXISTING       (3) \r\n \
					   #define TRUNCATE_EXISTING   (5) \r\n \
					   #define GENERIC_READ                     (0x80000000L) \r\n \
					   #define GENERIC_WRITE                    (0x40000000L) \r\n \
					   #define GENERIC_EXECUTE                  (0x20000000L) \r\n \
					   #define GENERIC_ALL                      (0x10000000L) \r\n \
					   #define INVALID_FILE_SIZE ((DWORD)0xFFFFFFFF) \r\n \
					   #define INVALID_SET_FILE_POINTER ((DWORD)-1) \r\n \
					   #define INVALID_FILE_ATTRIBUTES ((DWORD)-1) \r\n \
					   #define FILE_SHARE_READ                 0x00000001   \r\n \
					   #define FILE_SHARE_WRITE                0x00000002   \r\n \
					   #define FILE_SHARE_DELETE               0x00000004   \r\n \
					   #define FILE_ATTRIBUTE_READONLY             0x00000001   \r\n \
					   #define FILE_ATTRIBUTE_HIDDEN               0x00000002   \r\n \
					   #define FILE_ATTRIBUTE_SYSTEM               0x00000004   \r\n \
					   #define FILE_ATTRIBUTE_DIRECTORY            0x00000010   \r\n \
					   #define FILE_ATTRIBUTE_ARCHIVE              0x00000020   \r\n \
					   #define FILE_ATTRIBUTE_DEVICE               0x00000040   \r\n \
					   #define FILE_ATTRIBUTE_NORMAL               0x00000080   \r\n \
					   #define FILE_ATTRIBUTE_TEMPORARY            0x00000100   \r\n \
					   #define FILE_ATTRIBUTE_SPARSE_FILE          0x00000200   \r\n \
					   #define FILE_ATTRIBUTE_REPARSE_POINT        0x00000400   \r\n \
					   #define FILE_ATTRIBUTE_COMPRESSED           0x00000800   \r\n \
					   #define FILE_ATTRIBUTE_OFFLINE              0x00001000   \r\n \
					   #define FILE_ATTRIBUTE_NOT_CONTENT_INDEXED  0x00002000   \r\n \
					   #define FILE_ATTRIBUTE_ENCRYPTED            0x00004000   \r\n \
					   #define FILE_ATTRIBUTE_INTEGRITY_STREAM     0x00008000   \r\n \
					   #define FILE_ATTRIBUTE_VIRTUAL              0x00010000   \r\n \
					   #define FILE_ATTRIBUTE_NO_SCRUB_DATA        0x00020000   \r\n \
					   #define FILE_NOTIFY_CHANGE_FILE_NAME    0x00000001    \r\n \
					   #define FILE_NOTIFY_CHANGE_DIR_NAME     0x00000002    \r\n \
					   #define FILE_NOTIFY_CHANGE_ATTRIBUTES   0x00000004    \r\n \
					   #define FILE_NOTIFY_CHANGE_SIZE         0x00000008    \r\n \
					   #define FILE_NOTIFY_CHANGE_LAST_WRITE   0x00000010    \r\n \
					   #define FILE_NOTIFY_CHANGE_LAST_ACCESS  0x00000020    \r\n \
					   #define FILE_NOTIFY_CHANGE_CREATION     0x00000040    \r\n \
					   #define FILE_NOTIFY_CHANGE_SECURITY     0x00000100    \r\n \
					   #define FILE_ACTION_ADDED                   0x00000001    \r\n \
					   #define FILE_ACTION_REMOVED                 0x00000002    \r\n \
					   #define FILE_ACTION_MODIFIED                0x00000003    \r\n \
					   #define FILE_ACTION_RENAMED_OLD_NAME        0x00000004    \r\n \
					   #define FILE_ACTION_RENAMED_NEW_NAME        0x00000005    \r\n \
					   #define MAILSLOT_NO_MESSAGE             ((DWORD)-1)  \r\n \
					   #define MAILSLOT_WAIT_FOREVER           ((DWORD)-1)  \r\n \
					   #define FILE_CASE_SENSITIVE_SEARCH          0x00000001   \r\n \
					   #define FILE_CASE_PRESERVED_NAMES           0x00000002   \r\n \
					   #define FILE_UNICODE_ON_DISK                0x00000004   \r\n \
					   #define FILE_PERSISTENT_ACLS                0x00000008   \r\n \
					   #define FILE_FILE_COMPRESSION               0x00000010   \r\n \
					   #define FILE_VOLUME_QUOTAS                  0x00000020   \r\n \
					   #define FILE_SUPPORTS_SPARSE_FILES          0x00000040   \r\n \
					   #define FILE_SUPPORTS_REPARSE_POINTS        0x00000080   \r\n \
					   #define FILE_SUPPORTS_REMOTE_STORAGE        0x00000100   \r\n \
					   #define FILE_VOLUME_IS_COMPRESSED           0x00008000   \r\n \
					   #define FILE_SUPPORTS_OBJECT_IDS            0x00010000   \r\n \
					   #define FILE_SUPPORTS_ENCRYPTION            0x00020000   \r\n \
					   #define FILE_NAMED_STREAMS                  0x00040000   \r\n \
					   #define FILE_READ_ONLY_VOLUME               0x00080000   \r\n \
					   #define FILE_SEQUENTIAL_WRITE_ONCE          0x00100000   \r\n \
					   #define FILE_SUPPORTS_TRANSACTIONS          0x00200000   \r\n \
					   #define FILE_SUPPORTS_HARD_LINKS            0x00400000   \r\n \
					   #define FILE_SUPPORTS_EXTENDED_ATTRIBUTES   0x00800000   \r\n \
					   #define FILE_SUPPORTS_OPEN_BY_FILE_ID       0x01000000   \r\n \
					   #define FILE_SUPPORTS_USN_JOURNAL           0x02000000   \r\n \
					   #define FILE_SUPPORTS_INTEGRITY_STREAMS     0x04000000   \r\n \
					   #define FILE_INVALID_FILE_ID               ((LONGLONG)-1LL)  \r\n \
					   #define FILE_BEGIN           (0)  \r\n \
					   #define FILE_CURRENT         (1)  \r\n \
					   #define FILE_END             (2)  \r\n \
					   typedef struct _FILETIME {\r\n \
					   DWORD dwLowDateTime;\r\n \
					   DWORD dwHighDateTime;\r\n \
					   } FILETIME;\r\n\
					   typedef struct _WIN32_FIND_DATAA { \r\n\
					   DWORD dwFileAttributes; \r\n\
					   FILETIME ftCreationTime; \r\n\
					   FILETIME ftLastAccessTime; \r\n\
					   FILETIME ftLastWriteTime; \r\n\
					   DWORD nFileSizeHigh; \r\n\
					   DWORD nFileSizeLow; \r\n\
					   DWORD dwReserved0; \r\n\
					   DWORD dwReserved1; \r\n\
					   CHAR   cFileName[MAX_PATH]; \r\n\
					   CHAR   cAlternateFileName[14]; \r\n\
					   }WIN32_FIND_DATAA;\r\n\
						typedef struct _SYSTEMTIME {\r\n\
						WORD wYear;\r\n\
						WORD wMonth;\r\n\
						WORD wDayOfWeek;\r\n\
						WORD wDay;\r\n\
						WORD wHour;\r\n\
						WORD wMinute;\r\n\
						WORD wSecond;\r\n\
						WORD wMilliseconds;\r\n\
						} SYSTEMTIME;\r\n\
";

struct LibraryFunction Win_Functions[] =
{
	{ Win_MessageBoxA, "int MessageBoxA(void * hWnd, char * lpText, char * lpCaption, unsigned int uType);" },
	{ Win_OutputDebugStringA, "void OutputDebugStringA(char * message);" },
	{ Win_CopyFileA, "int CopyFileA(char * lpExistingFileName,char *, int bFailIfExists);" },
	{ Win_DeleteFileA, "int DeleteFileA(char * lpFileName);" },
	{ Win_GetFileAttributesA, "unsigned int GetFileAttributesA(char *lpFileName);" },
	{ Win_SetFileAttributesA, "unsigned int SetFileAttributesA(char *lpFileName,unsigned int dwFileAttributes);" },
	{ Win_GetFileSize, "unsigned int GetFileSize(void * hFile,unsigned int *lpFileSizeHigh);" },
	{ Win_CloseHandle, "int CloseHandle(void * hObject);" },
	{ Win_CreateFileA, "void * CreateFileA(char * lpFileName,unsigned int dwDesiredAccess,unsigned int dwShareMode,void * lpSecurityAttributes, unsigned int dwCreationDisposition, unsigned int dwFlagsAndAttributes,void * hTemplateFile); " },
	{ Win_ReadFile, "int ReadFile(void *hFile,void *lpBuffer,unsigned int nNumberOfBytesToRead,unsigned int *lpNumberOfBytesRead,void * lpOverlapped); " },
	{ Win_WriteFile, "int WriteFile(void *hFile,void *lpBuffer,unsigned int nNumberOfBytesToWrite,unsigned int *lpNumberOfBytesWritten,void * lpOverlapped);" },
	{ Win_SetFilePointer, "unsigned int SetFilePointer(void * hFile,long lDistanceToMove,long * lpDistanceToMoveHigh,unsigned int  dwMoveMethod); " },
	{ Win_SetEndOfFile, "int SetEndOfFile(void *hFile);" },
	{ Win_MoveFileA, "int MoveFileA(char * lpExistingFileName,char *lpNewFileName);" },
	{ Win_FindFirstFileA, "void * FindFirstFileA(char * lpFileName,WIN32_FIND_DATAA * lpFindFileData);" },
	{ Win_FindClose, "int FindClose(void * hFindFile);" },
	{ Win_FindNextFileA, "int FindNextFileA(void *hFindFile,WIN32_FIND_DATAA * lpFindFileData);" },
	{ Win_LoadLibraryA, "void * LoadLibraryA(char * lpLibFileName);" },
	{ Win_GetProcAddress, "void * GetProcAddress(char * hModule,char * lpProcName);" },
	{ Win_GetLocalTime, "void GetLocalTime(void * lpSystemTime);" },
	{ Win_GetSystemTime, "void GetSystemTime(void * lpSystemTime);"},
	{ NULL,             NULL }
};
#endif