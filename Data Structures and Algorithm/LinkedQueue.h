#ifndef QUEUE
#define QUEUE
#include"Queue.h"
#endif

template<typename object>
class LinkedQueue: public Queue<object>
{
private:
	struct ListNode {
		object info;
		ListNode *next;
		ListNode(object inf, ListNode *nxt = nullptr)
			: info(inf), next(nxt) {}
	};
	ListNode *head, *tail;

public:
	LinkedQueue()
		:head(nullptr), tail(nullptr) {}

	LinkedQueue(const LinkedQueue &LQ)
	{
		if (LQ.head == nullptr)
			head = tail = nullptr;
		else
		{
			head = new ListNode(LQ.head->info);
			tail = head;
			for (ListNode *p = LQ.head; p != LQ.tail; p = p->next)
			{
				tail->next = new ListNode(p->next->info);
				tail = tail->next;
			}
		}
	}

	virtual bool isEmpty() // O(1)
	{
		return head == nullptr;
	}

	virtual bool isFull() // O(1)
	{
		return false;
	}

	virtual void enq(object o) // O(1)
	{
		ListNode *newNode = new ListNode(o, nullptr);
		if (isEmpty()) head = newNode;
		else tail->next = newNode;
		tail = newNode;
	}

	virtual object deq() // O(1)
	{
		if (isEmpty())
			throw ContainerUnderflow();
		else
		{
			object result = head->info;
			ListNode *temp = head;
			head = head->next;
			delete temp;
			return result;
		}
	}

	virtual object front()
	{
		if (isEmpty())
			throw ContainerUnderflow();
		else return head->info;
	}

	~LinkedQueue()
	{
		if (isEmpty()) return;
		delete tail;
		while (head != nullptr)
		{
			ListNode *temp = head;
			head = head->next;
			delete temp;
		}
	}
};