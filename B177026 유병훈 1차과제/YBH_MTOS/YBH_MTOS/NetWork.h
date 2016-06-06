#include "global.h"

struct SOCKETINFO
{
	OVERLAPPED overlapped;
	SOCKET sock;
	char buf[BUFSIZE+1];
	int recvbytes;
	int sendbytes;
	WSABUF wsabuf;
};

class NetWork{
private:
	WSADATA wsa;
	HANDLE hcp;

	int retval;
	SOCKET listen_sock;

	// ������ ��ſ� ����� ����
	SOCKET client_sock;
	SOCKADDR_IN clientaddr;
	int addrlen;
	DWORD recvbytes, flags;

	int Init();
	
	void InitServer();
	void Accept();

public:
	NetWork(){Init();};
	~NetWork(){WSACleanup();};

	void Run();
	static DWORD WINAPI WorkerThread(LPVOID arg);
};