// threadwin32.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#define maxthread 20//最多20个线程
#define USE_MUTI_WAIT//测试使用等待全部核心对象退出
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
		WaitForMultipleObjects(maxthread, hthread, TRUE, INFINITE);//等待所有线程退出

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


	//关闭所有线程句柄
	    for(i=0; i<maxthread; i++)//vc不允许int标准？
    {
        CloseHandle(hthread[i]);
    }
DeleteCriticalSection(&d);
	return 0;
}

