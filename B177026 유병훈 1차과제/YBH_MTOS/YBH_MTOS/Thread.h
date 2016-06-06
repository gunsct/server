#include<Windows.h>

class Thread{
private:
	SYSTEM_INFO si;
	HANDLE hThread;

public:
	Thread(){GetSystemInfo(&si);};
	~Thread(){};

	static Thread* GetInstance();

	int CreateThreads(LPTHREAD_START_ROUTINE _workerthread, HANDLE _hcp);
};

#define THREAD ( Thread::GetInstance() )