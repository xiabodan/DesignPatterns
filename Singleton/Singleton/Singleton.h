#ifndef	SINGLETON_C_H
#define SINGLETON_C_H
#include <windows.h>
#include <iostream>

class Singleton_C
{

public:
	static Singleton_C* Instance();
	static Singleton_C* Create();
	static void Release();
protected:
	Singleton_C();
	~Singleton_C();
private:
	

public:
	int m_a;
protected:

private:
	static Singleton_C* s_instance;
	static HANDLE m_pMutex;
};

#endif