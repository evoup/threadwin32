// threadwin32.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#define maxthread 20//���20���߳�
#define USE_MUTI_WAIT//����ʹ�õȴ�ȫ�����Ķ����˳�
HANDLE hthread[maxthread];
CRITICAL_SECTION d;
DWORD WINAPI ThreadProc( LPVOID lpParam ) 
{
EnterCriticalSection(&d);
printf("I`m a thread!\n");
LeaveCriticalSection(&d);

return 0; 
}
int main(int argc, char* argv[])
{
	//printf("Hello World!\n");
	InitializeCriticalSection(&d);
	for (int i=0;i<maxthread;i++){
		//hthread[]
		printf("%d\n",i);
		hthread[i]=CreateThread(NULL,0,ThreadProc,NULL,0,NULL);
//WaitForSingleObject(
		WaitForMultipleObjects(maxthread, hthread, TRUE, INFINITE);//�ȴ������߳��˳�

GetLastError();

			//
        /*hThread[i] = CreateThread( 
            NULL,              // default security attributes
            0,                 // use default stack size  
            ThreadProc,        // thread function 
            pData,             // argument to thread function 
            0,                 // use default creation flags 
            &dwThreadId[i]);   // returns the thread identifier 
			*/

			//
	
	}


	//�ر������߳̾��
	    for(i=0; i<maxthread; i++)//vc������int��׼��
    {
        CloseHandle(hthread[i]);
    }
DeleteCriticalSection(&d);
	return 0;
}

