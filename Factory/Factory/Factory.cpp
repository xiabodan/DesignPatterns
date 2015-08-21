// Factory.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#if 0
//简单工厂模式
enum CTYPE {COREA, COREB};   
class SingleCore  
{  
public:  
    virtual void Show() = 0;
};  
//单核A  
class SingleCoreA: public SingleCore  
{  
public:  
    void Show() { cout<<"SingleCore A"<<endl; }  
};  
//单核B  
class SingleCoreB: public SingleCore  
{  
public:  
    void Show() { cout<<"SingleCore B"<<endl; }  
};  
//唯一的工厂，可以生产两种型号的处理器核，在内部判断  
class Factory  
{  
public:   
    SingleCore* CreateSingleCore(enum CTYPE ctype)  
    {  
        if(ctype == COREA) //工厂内部判断  
            return new SingleCoreA(); //生产核A  
        else if(ctype == COREB)  
            return new SingleCoreB(); //生产核B  
        else  
            return NULL;  
    }  
};  
#endif



#if 0
//工厂方法
class SingleCore  
{  
public:  
    virtual void Show() = 0;
};  
//单核A  
class SingleCoreA: public SingleCore  
{  
public:  
    void Show() { cout<<"SingleCore A"<<endl; }  
};  
//单核B  
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
//生产A核的工厂  
class FactoryA: public Factory  
{  
public:  
    SingleCoreA* CreateSingleCore() { return new SingleCoreA; }  
};  
//生产B核的工厂  
class FactoryB: public Factory  
{  
public:  
    SingleCoreB* CreateSingleCore() { return new SingleCoreB; }  
};  
#endif


//抽象工厂
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
//多核  
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
//工厂  
class CoreFactory    
{  
public:  
    virtual SingleCore* CreateSingleCore() = 0;
    virtual MultiCore* CreateMultiCore() = 0;
};  
//工厂A，专门用来生产A型号的处理器  
class FactoryA :public CoreFactory  
{  
public:  
    SingleCore* CreateSingleCore() { return new SingleCoreA(); }  
    MultiCore* CreateMultiCore() { return new MultiCoreA(); }  
};  
//工厂B，专门用来生产B型号的处理器  
class FactoryB : public CoreFactory  
{  
public:  
    SingleCore* CreateSingleCore() { return new SingleCoreB(); }  
    MultiCore* CreateMultiCore() { return new MultiCoreB(); }  
}; 

int _tmain(int argc, _TCHAR* argv[])
{
	//简单工厂
	//Factory* F =new Factory();
	//F->CreateSingleCore(COREA)->Show();
	//F->CreateSingleCore(COREB)->Show();

	//工厂方法
	//FactoryA* FA = new FactoryA();
	//FA->CreateSingleCore()->Show();
	//FactoryB* FB = new FactoryB();
	//FB->CreateSingleCore()->Show();

	//抽象工厂
	FactoryA* FA = new FactoryA();
	FA->CreateMultiCore()->Show();
	FA->CreateSingleCore()->Show();
	FactoryB* FB = new FactoryB();
	FB->CreateMultiCore()->Show();
	FB->CreateSingleCore()->Show();

	getchar();
	return 0;
}

