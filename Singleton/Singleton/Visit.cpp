#include "Visit.h"
#include "Singleton.h"

using namespace std;
Visit_C::Visit_C()
{

}

Visit_C::~Visit_C()
{

}
void Visit_C::visitSingleton()
{
	cout <<  Singleton_C::Instance()->m_a << endl;
	Singleton_C::Instance()->m_a = 20;
}

void funThreadReadData()
{
	cout<<"In funThreadReadData."<<endl;	
	Singleton_C* SingletonObj = Singleton_C::Create();
	cout<< Singleton_C::Instance()->m_a<<endl;
	Singleton_C::Instance()->m_a = 3;
}

void funThreadWriteData()
{
	cout<<"In funThreadWriteData."<<endl;	
	Singleton_C* SingletonObj = Singleton_C::Create();
	cout<< Singleton_C::Instance()->m_a<<endl;
	Singleton_C::Instance()->m_a = 4;
}

void Visit_C::CreateThreadSingeleton()
{

	HANDLE handle1 = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)funThreadWriteData,0,0,NULL);	
	CloseHandle(handle1);
	HANDLE handle2 = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)funThreadReadData,0,0,NULL);
	CloseHandle(handle2);

}