#include "Thread.h"

Thread* Thread::GetInstance()
{
	static Thread* Instance;

	if( NULL == Instance )
		Instance = new Thread;

	return Instance;
}

int Thread::CreateThreads(LPTHREAD_START_ROUTINE _workerthread, HANDLE _hcp){
	for(int i=0; i<(int)si.dwNumberOfProcessors*2; i++){
		hThread = CreateThread(NULL, 0, _workerthread, _hcp, 0, NULL);
		if(hThread == NULL) return 1;
		CloseHandle(hThread);
	}
}