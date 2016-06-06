#include "Error.h"

Error* Error::GetInstance()
{
	static Error* Instance;

	if( NULL == Instance )
		Instance = new Error;

	return Instance;
}

// 소켓 함수 오류 출력
void Error::err_display(char *msg)
{
	LPVOID lpMsgBuf;

	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER|FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, WSAGetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf, 0, NULL);

	printf("[%s] %s", msg, (char *)lpMsgBuf);

	LocalFree(lpMsgBuf);
}

// 소켓 함수 오류 출력 후 종료
void Error::err_quit( char* msg )
{
	LPVOID lpMsgBuf;

	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER|FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, WSAGetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf, 0, NULL);

	MessageBox(NULL, (LPCTSTR)lpMsgBuf, (LPCTSTR)msg, MB_ICONERROR);

	LocalFree(lpMsgBuf);

	exit(1);
}
