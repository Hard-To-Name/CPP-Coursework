#ifndef STACK
#define STACK
#include"Stack.h"
#endif

template<typename object>
class LinkedStack: public Stack<object>
{
private:
	struct ListNode {
		object info;
		ListNode *next;
		ListNode(object inf, ListNode *nxt = nullptr)
			: info(inf), next(nxt) {}
	};
	ListNode *head;

public:
	LinkedStack()
		:head(nullptr) {}

	LinkedStack(const LinkedStack &LS)
	{
		if (LS.head == nullptr) head = nullptr;
		else
		{
			head = new ListNode(LS.head->info);
			ListNode *p = head;
			for (ListNode *q = LS.head->next; q != nullptr; q = q->next)
			{
				p->next = new ListNode(q->info);
				p = p->next;
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

	virtual void push(object o) // O(1)
	{
		head = new ListNode(o, head);
	}

	virtual object pop() // O(1)
	{
		if (isEmpty())
			throw ContainerUnderflow();
		ListNode *t = head;
		head = head->next;
		object result = t->info;
		delete t;
		return result;
	}

	virtual object top()
	{
		if (isEmpty())
			throw ContainerUnderflow();
		return head->info;
	}

	~LinkedStack()
	{
		if (isEmpty()) return;
		while (head != nullptr)
		{
			ListNode *temp = head;
			head = head->next;
			delete temp;
		}
	}
};