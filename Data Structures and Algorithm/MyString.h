#include<iostream>
#include<fstream>
using namespace std;

class MyString
{
	struct ListNode {
		char info;
		ListNode *next;
		ListNode(char new_info, ListNode *new_next);
		static ListNode* cstring_to_list(const char *s);
		static ListNode* lndup(ListNode *L);
		static ListNode* ln2dup(ListNode *L1, ListNode *L2);
		static ListNode* lnrev(ListNode *L);
		static int lncmp(ListNode *L1, ListNode *L2);
		static int lnln(ListNode *L1, ListNode *L2);
		static void delete_ln(ListNode *L);
	};
	ListNode *head;

public:
	explicit MyString(const char *s);
	MyString(const MyString &s);
	MyString& operator = (const MyString &s);
	char& operator [] (const int index);
	int length() const;
	int indexOf(char c) const;
	int indexOf(const MyString &pat) const;
	bool operator == (const MyString &s) const;
	MyString operator + (const MyString &s) const;
	MyString& operator += (const MyString &s);
	MyString reverse() const;
	void error(const char *s);
	void print(ostream &out) const;
	void read(istream &in);
	static int get_NumAllocations();
	~MyString();
};
inline ostream& operator << (ostream &out, const MyString &str);
inline istream& operator >> (istream &in, MyString &str);