#include <iostream>
#include <parent.h>
using namespace std;


int main()
{
	Factory_C* F = new Factory_C();
	F->autoopen()->opendoor();
	F->manualopen()->opendoor();
	getchar();
}