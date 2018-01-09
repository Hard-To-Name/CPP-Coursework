#include "String.h"

String::String(const char * s)
{
	head = ListNode::stringToList(s);
}
String::String(const String & s)
{
	head = ListNode::copy(s.head);
}
String String::operator = (const String & s)
{
	ListNode::deleteList(head);
	head = ListNode::copy(s.head);
	return *this;
}
char & String::operator [] (const int index)
{
	ListNode* p = head;
	if (index >= ListNode::length(head))
	{
		cout << "Index out of range." << endl;
		if (!p)
		{
			char n = 'L';
			return n;
		}
		return p->info;
	}
	for (int i = 0; i < index; ++i)
	{
		p = p->next;
	}
	return p->info;
}
int String::size() const
{
	return ListNode::length(head);
}
int String::indexOf(char c) const
{
	int count = 0;
	for (ListNode* p = head; p != nullptr; p = p->next)
	{
		if (p->info == c)
			return count;
		++count;
	}
	return -1;
}
bool String::operator == (const String & s) const
{
	return !ListNode::compare(head, s.head);
}
bool String::operator < (const String & s) const
{
	return ListNode::compare(head, s.head) == -1;
}
/// concatenates this and s, for a third String
String String::operator + (const String & s) const
{
	String result;
	result.head = ListNode::append(head, s.head);
	return result;
}
/// concatenates s onto end of this
String String::operator += (const String & s)
{
	ListNode* temp = ListNode::append(head, s.head);
	ListNode::deleteList(head);
	head = temp;
	return *this;
}
String String::reverse() const // does not modify this String
{
	String result;
	result.head = ListNode::reverse(head);
	return result;
}
void String::print(ostream & out) const
{
	for (ListNode* p = head; p != nullptr; p = p->next)
	{
		out << p->info;
	}
}
void String::read(istream & in)
{
	char* s = new char[256];
	in >> s;
	ListNode::deleteList(head);
	head = ListNode::stringToList(s);
	delete[] s;
}
String::~String()
{
	ListNode::deleteList(head);
}
String::ListNode::ListNode(char newInfo, String::ListNode * newNext)
	: info(newInfo), next(newNext)
{
}// Below: primitives you *must* write and use (try recursion)
String::ListNode * String::ListNode::stringToList(const char *s) // for constructor
{
	if (!*s) return nullptr;
	return new ListNode(*s, stringToList(s + 1));
}
String::ListNode * String::ListNode::copy(ListNode * L) // when a copy of list needed
{
	if (!L) return nullptr;
	return new ListNode(L->info, copy(L->next));
}
String::ListNode * String::ListNode::reverse(ListNode * L) // for reverse()
{
	ListNode* head = nullptr;
	for (ListNode* p = L->next; p != nullptr; p = p->next)
	{
		head = new ListNode(p->info, head);
	}
	return head;
}
String::ListNode * String::ListNode::append(ListNode * L1, ListNode * L2) // for +
{
	/*
	if (!L1) return copy(L2);
	ListNode* result = ListNode::copy(L1);
	ListNode* p = result;
	while (p->next != nullptr) p = p->next;
	p->next = ListNode::copy(L2);
	return result;
	*/
	if (!L1) return copy(L2);
	return new ListNode(L1->info, append(L1->next, L2));\
}
int String::ListNode::compare(ListNode * L1, ListNode * L2) //like strcmp
{
	ListNode* p1 = L1;
	ListNode* p2 = L2;
	while (true)
	{
		if (p1 == nullptr && p2 == nullptr) return 0;
		if (p1 == nullptr) return -1;
		if (p2 == nullptr) return 1;
		if (p1->info > p2->info) return 1;
		if (p1->info < p2->info) return -1;
		p1 = p1->next;
		p2 = p2->next;
	}
}
void String::ListNode::deleteList(ListNode * L) // called to delete any list
{
	if (L != nullptr)
	{
		deleteList(L->next);
		delete L;
	}
}
int String::ListNode::length(ListNode * L) // O(N) so call rarely
{
	int len = 0;
	for (ListNode* p = L; p != nullptr; p = p->next)
		++len;
	return len;
}
ostream & operator << (ostream & out, String str)
{
	str.print(out);
	return out;
}
istream & operator >> (istream & in, String & str)
{
	str.read(in);
	return in;
}