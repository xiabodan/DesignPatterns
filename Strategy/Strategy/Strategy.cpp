// Strategy.cpp : 定义控制台应用程序的入口点。
//
#include <iostream>
#include "stdafx.h"

using namespace std;

//抽象接口
class ReplaceAlgorithm
{
public:
	virtual void Replace() = 0;
};
//三种具体的替换算法
class LRU_ReplaceAlgorithm : public ReplaceAlgorithm
{
public:
	void Replace() { cout<<"Least Recently Used replace algorithm"<<endl; }
};

class FIFO_ReplaceAlgorithm : public ReplaceAlgorithm
{
public:
	void Replace() { cout<<"First in First out replace algorithm"<<endl; }
};
class Random_ReplaceAlgorithm: public ReplaceAlgorithm
{
public:
	void Replace() { cout<<"Random replace algorithm"<<endl; }
};

//Cache需要用到替换算法
//方式1 直接替代
//class Cache
//{
//private:
//	ReplaceAlgorithm *m_ra;
//public:
//	Cache(ReplaceAlgorithm *ra) { m_ra = ra; }
//	~Cache() { delete m_ra; }
//	void Replace() { m_ra->Replace(); }
//};

template <class RA>
class Cache{
private:
	RA m_ra;
public:
	Cache();
	~Cache();
	void Replace(){m_ra.Replace();}
};

int _tmain(int argc, _TCHAR* argv[])
{
	//方式1 直接替代
	//Cache cache(new LRU_ReplaceAlgorithm()); //暴露了算法的定义
	//cache.Replace();

	Cache<Random_ReplaceAlgorithm> cache; //模板实参  
    cache.Replace();  
 
	getchar();
	return 0;
}

