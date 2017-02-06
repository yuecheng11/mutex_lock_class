#ifndef _CMUTEXLOCK_H
#define _CMUTEXLOCK_H

#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

class MutexLock
{
public:
	MutexLock();
	~MutexLock();
	void lock();
	void unlock();
private:
	void mutexinit();
	void mutexDestroy();
private:
	pthread_mutex_t m_Mutex;
};

#endif