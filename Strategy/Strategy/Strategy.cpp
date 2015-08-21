// Strategy.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include <iostream>
#include "stdafx.h"

using namespace std;

//����ӿ�
class ReplaceAlgorithm
{
public:
	virtual void Replace() = 0;
};
//���־�����滻�㷨
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

//Cache��Ҫ�õ��滻�㷨
//��ʽ1 ֱ�����
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
	//��ʽ1 ֱ�����
	//Cache cache(new LRU_ReplaceAlgorithm()); //��¶���㷨�Ķ���
	//cache.Replace();

	Cache<Random_ReplaceAlgorithm> cache; //ģ��ʵ��  
    cache.Replace();  
 
	getchar();
	return 0;
}

