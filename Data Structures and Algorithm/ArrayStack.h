#ifndef STACK
#define STACK
#include"Stack.h"
#endif

template<typename object>
class ArrayStack: public Stack<object>
{
private:
	object *buf;
	int cap, tp;

public:
	ArrayStack(int capacity)
		:buf(new object[capacity]), cap(capacity), tp(0) {}

	ArrayStack(const ArrayStack &AS)
	{
		buf = new object[AS.tp + 1];
		for (int i = 0; i < tp; ++i)
			buf[i] = AS.buf[i];
	}

	virtual bool isEmpty() // O(1)
	{
		return tp <= 0;
	}

	virtual bool isFull() // O(1)
	{
		return tp >= cap;
	}

	virtual void push(object o) // O(1)
	{
		if (isFull())
			throw ContainerOverflow();
		buf[tp++] = o;
	}

	virtual object pop() // O(1)
	{
		if (isEmpty())
			throw ContainerUnderflow();
		return buf[--tp];
	}

	virtual object top()
	{
		if (isEmpty())
			throw ContainerUnderflow();
		return buf[tp - 1];
	}

	~ArrayStack()
	{
		delete[] buf;
	}
};