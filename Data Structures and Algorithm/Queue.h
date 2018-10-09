#ifndef HEADER
#define HEADER
#include<iostream>
#include"ContainerOverflow.h"
#include"ContainerUnderflow.h"
using namespace std;
#endif

/*
void error(const char *msg)
{
cout << msg << endl;
}
*/

template<typename object>
class Queue
{
public:
	virtual bool isEmpty() = 0;
	virtual bool isFull() = 0;
	virtual void enq(object o) = 0;
	virtual object deq() = 0;
	virtual object front() = 0;
	virtual ~Queue() {}
};