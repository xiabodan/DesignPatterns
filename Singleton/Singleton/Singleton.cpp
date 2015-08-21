#include "Singleton.h"

Singleton_C* Singleton_C::s_instance = NULL;
HANDLE Singleton_C::m_pMutex = 0;

Singleton_C* Singleton_C::Create()
{
	m_pMutex = CreateMutex(NULL,FALSE,NULL);
	if(s_instance == NULL)
	{
		WaitForSingleObject(m_pMutex, INFINITE);
		if(s_instance == NULL)
		{
			s_instance = new Singleton_C;
		}
		ReleaseMutex(m_pMutex);
	}
	CloseHandle(m_pMutex);
	return s_instance;	

}

Singleton_C* Singleton_C::Instance()
{
	if(s_instance == NULL)
	{
		return NULL;
	}
	return s_instance;
}

void Singleton_C::Release()
{
	if(s_instance == NULL){
	}else{
		delete s_instance;//必须要delete才能进入析构函数
	}
}

Singleton_C::Singleton_C()
	:m_a(1)
{
	m_a = 2;
}
Singleton_C::~Singleton_C()
{
	m_a = 0;
}