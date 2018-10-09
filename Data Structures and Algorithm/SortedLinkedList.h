#ifndef iostream
#include<iostream>
#include<string>
using namespace std;
#endif

class SortedLinkedList
{
private:
	struct ListNode {
		string info;
		ListNode *next;
		ListNode(string inf, ListNode * nxt = nullptr)
			:info(inf), next(nxt) {}
	};
	ListNode *head;

	static ListNode* sequentialSearch(ListNode * buf, string word)
	{
		for (ListNode *p = buf; p != nullptr; p = p->next)
		{
			if (p->info == word)
				return p;
			else if (p->info > word)
				return nullptr;
		}
		return nullptr;
	}

public:
	explicit SortedLinkedList()
		:head(nullptr) {}

	SortedLinkedList(const SortedLinkedList &SLL)
	{
		if (SLL.head == nullptr)
			head = nullptr;
		else
		{
			head = new ListNode(SLL.head->info, nullptr);
			ListNode *p = head;
			for (ListNode *q = SLL.head; q->next != nullptr; q = q->next)
			{
				p->next = new ListNode(q->next->info, nullptr);
				p = p->next;
			}
		}
	}

	bool isEmpty()
	{
		return (head == nullptr);
	}

	bool isFull()
	{
		return false;
	}

	void insert(string word) // O(N)
	{
		ListNode *c = head;
		ListNode *p = nullptr;
		for (c; c != nullptr && word > c->info; c = c->next)
			p = c;
		if (p == nullptr)
			head = new ListNode(word, head);
		else p->next = new ListNode(word, c);
	}

	bool find(string word)
	{
		return sequentialSearch(head, word) != nullptr;
	}

	void remove(string word)
	{
		if (isEmpty()) return;
		if (head->info == word)
		{
			ListNode *temp = head;
			head = head->next;
			delete temp;
			return;
		}
		for (ListNode *p = head; p->next != nullptr; p = p->next)
			if (p->next->info == word)
			{
				ListNode *temp = p->next;
				p->next = p->next->next;
				delete temp;
				return;
			}
	}

	void print(ostream &out)
	{
		for (ListNode *p = head; p != nullptr; p = p->next)
			out << p->info << endl;
	}

	~SortedLinkedList()
	{
		while (head != nullptr)
			remove(head->info);
	}
};

inline ostream& operator << (ostream &out, SortedLinkedList &SLL)
{
	SLL.print(out);
	return out;
}
