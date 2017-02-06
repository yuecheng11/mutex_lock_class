#include "Cmutexlock.hpp"

using namespace std;

MutexLock::MutexLock()
{
	mutexinit();
}

MutexLock::~MutexLock()
{
	mutexDestroy();

}

void MutexLock::mutexinit()
{
	pthread_mutex_init(&m_Mutex,NULL);
}

void MutexLock::mutexDestroy()
{
	pthread_mutex_destroy(&m_Mutex); 
}

void MutexLock::lock()
{
	pthread_mutex_lock(&m_Mutex);
}

void MutexLock::unlock()
{
	pthread_mutex_unlock(&m_Mutex);
}

MutexLock g_Mutex;

void *testMsg(void* testMsg)
{
	char* msg = (char*)testMsg;

	g_Mutex.lock();

	for(int i = 0;i < 5;++i)
	{
		cout<<msg<<" : "<<i+1<<endl;
		sleep(1);
	}
	g_Mutex.unlock();

	return NULL;
}
int main()
{
	pthread_t ptest1,ptest2;

	pthread_create(&ptest1,NULL,&testMsg,(void*)"this first thread");
	pthread_create(&ptest2,NULL,&testMsg,(void*)"this second thread");

	pthread_join(ptest1, NULL);                                 
    pthread_join(ptest2, NULL); 

	return 0;
}
