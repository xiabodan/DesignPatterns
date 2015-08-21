#ifndef  PARENT_H
#define  PARENT_H


#include <iostream>
using namespace std;

class OpenDoor_C
{
public:
	virtual void opendoor() = 0;
};

class AutoOpen_C : public OpenDoor_C
{
	void opendoor()
	{
		cout << "I can AutoOpen!" << endl;
	}
};


class ManualOpen_C : public OpenDoor_C
{
	void opendoor()
	{
		cout << "I can ManualOpen!" << endl;
	}
};

class Factory_C 
{
public:
	OpenDoor_C* autoopen(){return  new AutoOpen_C; }
	OpenDoor_C* manualopen(){return  new ManualOpen_C;}
};

#endif // ! 