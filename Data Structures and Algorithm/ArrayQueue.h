#ifndef QUEUE
#define QUEUE
#include"Queue.h"
#endif

template<typename object>
class ArrayQueue: public Queue<object>
{
private:
	object *buf;
	int capacity, frnt, rear;

public:
	ArrayQueue(int cap)
		:buf(new object[cap + 1]), frnt(0), rear(0), capacity(cap + 1) {}

	ArrayQueue(const ArrayQueue &AQ)
	{
		buf = new object[AQ.rear - AQ.frnt + 1];
		for (int i = 0; i < AQ.rear - AQ.frnt; ++i)
			buf[i] = AQ.buf[i];
	}

	virtual bool isEmpty()
	{
		return frnt == rear;
	}

	virtual bool isFull()
	{
		return (rear + 1) % capacity == frnt;
	}

	virtual void enq(object o)
	{
		if (isFull())
			throw ContainerOverflow();
		buf[rear] = o;
		rear = (rear + 1) % capacity;
	}

	virtual object deq()
	{
		if (isEmpty())
			throw ContainerUnderflow();
		object result = buf[frnt];
		frnt = (frnt + 1) % capacity;
		return result;
	}

	virtual object front()
	{
		if (isEmpty())
			throw ContainerUnderflow();
		return buf[frnt];
	}

	~ArrayQueue()
	{
		delete[] buf;
	}
};