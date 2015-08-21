// Adapter.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include <iostream>
#include "stdafx.h"

using namespace std;
//˫�˶���
class Deque
{
public:
	void push_back(int x) { cout<<"Deque push_back"<<endl; }
	void push_front(int x) { cout<<"Deque push_front"<<endl; }
	void pop_back() { cout<<"Deque pop_back"<<endl; }
	void pop_front() { cout<<"Deque pop_front"<<endl; }
};
//˳������
class Sequence
{
public:
	virtual void push(int x) = 0;
	virtual void pop() = 0;
};
//ջ
class Stack: public Sequence
{
public:
	void push(int x) { deque.push_back(x); }
	void pop() { deque.pop_back(); }
private:
	Deque deque; //˫�˶���
};
//����
class Queue: public Sequence
{
public:
	void push(int x) { deque.push_back(x); }
	void pop() { deque.pop_front(); }
private:
	Deque deque; //˫�˶���
};

int _tmain(int argc, _TCHAR* argv[])
{

	Sequence *s1 = new Stack();  
    Sequence *s2 = new Queue();  
    s1->push(1); s1->pop();  
    s2->push(1); s2->pop();  
    delete s1; delete s2; 

	getchar();
    return 0;  

}
