// Factory.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#if 0
//�򵥹���ģʽ
enum CTYPE {COREA, COREB};   
class SingleCore  
{  
public:  
    virtual void Show() = 0;
};  
//����A  
class SingleCoreA: public SingleCore  
{  
public:  
    void Show() { cout<<"SingleCore A"<<endl; }  
};  
//����B  
class SingleCoreB: public SingleCore  
{  
public:  
    void Show() { cout<<"SingleCore B"<<endl; }  
};  
//Ψһ�Ĺ������������������ͺŵĴ������ˣ����ڲ��ж�  
class Factory  
{  
public:   
    SingleCore* CreateSingleCore(enum CTYPE ctype)  
    {  
        if(ctype == COREA) //�����ڲ��ж�  
            return new SingleCoreA(); //������A  
        else if(ctype == COREB)  
            return new SingleCoreB(); //������B  
        else  
            return NULL;  
    }  
};  
#endif



#if 0
//��������
class SingleCore  
{  
public:  
    virtual void Show() = 0;
};  
//����A  
class SingleCoreA: public SingleCore  
{  
public:  
    void Show() { cout<<"SingleCore A"<<endl; }  
};  
//����B  
class SingleCoreB: public SingleCore  
{  
public:  
    void Show() { cout<<"SingleCore B"<<endl; }  
};  
class Factory  
{  
public:  
    virtual SingleCore* CreateSingleCore() = 0;
};  
//����A�˵Ĺ���  
class FactoryA: public Factory  
{  
public:  
    SingleCoreA* CreateSingleCore() { return new SingleCoreA; }  
};  
//����B�˵Ĺ���  
class FactoryB: public Factory  
{  
public:  
    SingleCoreB* CreateSingleCore() { return new SingleCoreB; }  
};  
#endif


//���󹤳�
class SingleCore   
{  
public:  
    virtual void Show() = 0;
};  
class SingleCoreA: public SingleCore    
{  
public:  
    void Show() { cout<<"Single Core A"<<endl; }  
};  
class SingleCoreB :public SingleCore  
{  
public:  
    void Show() { cout<<"Single Core B"<<endl; }  
};  
//���  
class MultiCore    
{  
public:  
    virtual void Show() = 0;
};  
class MultiCoreA : public MultiCore    
{  
public:  
    void Show() { cout<<"Multi Core A"<<endl; }  
  
};  
class MultiCoreB : public MultiCore    
{  
public:  
    void Show() { cout<<"Multi Core B"<<endl; }  
};  
//����  
class CoreFactory    
{  
public:  
    virtual SingleCore* CreateSingleCore() = 0;
    virtual MultiCore* CreateMultiCore() = 0;
};  
//����A��ר����������A�ͺŵĴ�����  
class FactoryA :public CoreFactory  
{  
public:  
    SingleCore* CreateSingleCore() { return new SingleCoreA(); }  
    MultiCore* CreateMultiCore() { return new MultiCoreA(); }  
};  
//����B��ר����������B�ͺŵĴ�����  
class FactoryB : public CoreFactory  
{  
public:  
    SingleCore* CreateSingleCore() { return new SingleCoreB(); }  
    MultiCore* CreateMultiCore() { return new MultiCoreB(); }  
}; 

int _tmain(int argc, _TCHAR* argv[])
{
	//�򵥹���
	//Factory* F =new Factory();
	//F->CreateSingleCore(COREA)->Show();
	//F->CreateSingleCore(COREB)->Show();

	//��������
	//FactoryA* FA = new FactoryA();
	//FA->CreateSingleCore()->Show();
	//FactoryB* FB = new FactoryB();
	//FB->CreateSingleCore()->Show();

	//���󹤳�
	FactoryA* FA = new FactoryA();
	FA->CreateMultiCore()->Show();
	FA->CreateSingleCore()->Show();
	FactoryB* FB = new FactoryB();
	FB->CreateMultiCore()->Show();
	FB->CreateSingleCore()->Show();

	getchar();
	return 0;
}

