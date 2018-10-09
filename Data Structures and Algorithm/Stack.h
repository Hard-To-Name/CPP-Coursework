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
class Stack
{
public:
	virtual bool isEmpty() = 0;
	virtual bool isFull() = 0;
	virtual void push(object o) = 0;
	virtual object pop() = 0;
	virtual object top() = 0;
	virtual ~Stack() {};
};