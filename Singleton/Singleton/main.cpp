#include <iostream>

#include "Singleton.h"
#include "Visit.h"
using namespace std;


int main()
{
	//Singleton_C::Create();
	//Singleton_C* SingletonObj = Singleton_C::Create();
	//cout<< Singleton_C::Instance()->m_a<<endl;
	Visit_C *Visit = new Visit_C;
	Visit->CreateThreadSingeleton();
	//Visit->visitSingleton();
	//cout<< Singleton_C::Instance()->m_a<<endl;
	Singleton_C::Release();

	delete Visit;
	getchar();
}