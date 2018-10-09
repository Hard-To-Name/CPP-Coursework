#include"MyString.h"

// MyString private structure ListNode definitions
MyString::ListNode::ListNode(char new_info, ListNode *new_next)
	: info(new_info), next(new_next) {}

MyString::ListNode* MyString::ListNode::cstring_to_list(const char *s)
{
	if (s[0] == '\0') return nullptr;
	ListNode *result = new ListNode(s[0], nullptr);
	ListNode *p = result;
	for (int i = 1; s[i] != '\0'; ++i)
	{
		p->next = new ListNode(s[i], nullptr);
		p = p->next;
	}
	return result;
}

MyString::ListNode* MyString::ListNode::lndup(ListNode *L)
{
	if (L == nullptr) return nullptr;
	ListNode *result = new ListNode(L->info, nullptr);
	ListNode *p = result;
	for (ListNode *lp = L->next; lp != nullptr; lp = lp->next)
	{
		p->next = new ListNode(lp->info, nullptr);
		p = p->next;
	}
	return result;
}

MyString::ListNode* MyString::ListNode::ln2dup(ListNode *L1, ListNode *L2)
{
	if (L1 == nullptr) return lndup(L2);
	ListNode *result = lndup(L1);
	ListNode *p = result;
	for (p; p->next != nullptr; p = p->next);
	p->next = lndup(L2);
	return result;
}

MyString::ListNode* MyString::ListNode::lnrev(ListNode *L)
{
	ListNode *result = nullptr;
	for (ListNode *p = L; p != nullptr; p = p->next)
		result = new ListNode(p->info, result);
	return result;
}

int MyString::ListNode::lncmp(ListNode *L1, ListNode *L2)
{
	ListNode *p1 = L1;
	ListNode *p2 = L2;
	while (p1 != nullptr)
	{
		if (p2 == nullptr) return 1;
		if (p1->info != p2->info)
			return p1->info - p2->info;
		p1 = p1->next;
		p2 = p2->next;
	}
	if (p2 == nullptr) return 0;
	else return -1;
}

int MyString::ListNode::lnln(ListNode *L1, ListNode *L2) // L2: to be found
{
	ListNode *p1 = L1;
	int index = 0;
	while (p1 != nullptr)
	{
		ListNode *lp1 = p1;
		ListNode *lp2 = L2;
		while (lp2 != nullptr)
		{
			if (lp1 == nullptr) return -1;
			if (lp1->info != lp2->info) break;
			lp1 = lp1->next;
			lp2 = lp2->next;
		}
		if (lp2 == nullptr) return index;
		p1 = p1->next;
		++index;
	}
}

void MyString::ListNode::delete_ln(ListNode *L)
{
	while (L != nullptr)
	{
		ListNode *p = L;
		if (p->next == nullptr)
		{
			delete p;
			break;
		}
		for (p; p->next->next != nullptr; p = p->next);
		delete p->next;
		p->next = nullptr;
	}
}



// MyString public definitions
MyString::MyString(const char *s = "")
{
	head = ListNode::cstring_to_list(s);
}

MyString::MyString(const MyString &s)
{
	head = ListNode::lndup(s.head);
}

MyString& MyString::operator = (const MyString &s)
{
	ListNode::delete_ln(head);
	head = ListNode::lndup(s.head);
	return *this;
}

char& MyString::operator [] (const int index)
{
	if (index < 0 || head == nullptr)
		error("Index out of bound.");
	ListNode *p = head;
	for (int i = 0; i < index; ++i)
	{
		p = p->next;
		if (p == nullptr)
			error("Index out of bound.");
	}
	return p->info;
}

int MyString::length() const
{
	int i = 0;
	for (ListNode *p = head; p != nullptr; p = p->next) ++i;
	return i;
}

int MyString::indexOf(char c) const
{
	int index = 0;
	for (ListNode *p = head; p != nullptr; p = p->next)
	{
		if (p->info == c) return index;
		++index;
	}
	return -1;
}

int MyString::indexOf(const MyString &pat) const
{
	return ListNode::lnln(head, pat.head);
}

bool MyString::operator == (const MyString &s) const
{
	return !ListNode::lncmp(head, s.head);
}

MyString MyString::operator + (const MyString &s) const
{
	MyString result;
	result.head = ListNode::ln2dup(head, s.head);
	return result;
}

MyString& MyString::operator += (const MyString &s)
{
	ListNode *res = ListNode::ln2dup(head, s.head);
	ListNode::delete_ln(head);
	head = res;
	return *this;
}

MyString MyString::reverse() const
{
	MyString result;
	result.head = ListNode::lnrev(head);
	return result;
}

void MyString::error(const char *s) // O(1)
{
	cerr << "Error: " << s << endl;
	throw 0;
}

void MyString::print(ostream &out) const
{
	for (ListNode *p = head; p != nullptr; p = p->next)
		out << p->info;
}

void MyString::read(istream &in)
{
	char *s = new char[256];
	in.getline(s,255);
	ListNode::delete_ln(head);
	head = ListNode::cstring_to_list(s);
	delete[] s;
}

int MyString::get_NumAllocations()
{
	return 0;
}

MyString::~MyString()
{
	ListNode::delete_ln(head);
}

inline ostream& operator << (ostream &out, const MyString &str)
{
	str.print(out);
	return out;
}

inline istream& operator >> (istream &in, MyString &str)
{
	str.read(in);
	return in;
}



MyString copyConstructorTest(MyString l)
{
	return l;
}

void testReverse()
{
	ifstream in("input.txt");
	if (!in) cout << "Cannot Open" << endl;
	MyString l;

	while (in >> l)
	{
		cout << copyConstructorTest(l)
			<< " " << l.length() << " "
			<< l.reverse() << endl;
	}
}

void testAssignment()
{
	cout << "testAssignment begins." << endl;
	MyString l = MyString("o0oO00oo");
	cout << "Now MyString l is: " << l << "(should be o0oO00oo)" << endl;
	MyString m = l;
	cout << "Now MyString m is: " << m << "(should be " << l << ")" << endl;
	m = MyString();
	cout << "Now MyString m is: " << m << "(should be )" << endl;
	/*
	ifstream in("input.txt");
	MyString x;
	while (in >> x)
	{
	l = x;
	cout << "Now MyString l is: " << l << "(should be " << x << ")" << endl;
	}
	*/
	cout << "testAssignment ends.\n" << endl;
}

void testBrackets()
{
	cout << "testBrackets begins." << endl;
	MyString l("abcdefghi");
	cout << "Test MyString l is: " << l << endl;
	cout << "The first character of MyString l is: " << l[0] << endl;
	cout << "The second character of MyString l is: " << l[1] << endl;
	cout << "The third character of MyString l is: " << l[2] << endl;
	try { cout << l[-1] << endl; }
	catch (int i) { cout << "Successfully catched." << endl; }
	try { cout << l[l.length()] << endl; }
	catch (int i) { cout << "Successfully catched." << endl; }
	ifstream in("input.txt");
	MyString x;
	while (in >> x)
	{
		cout << "Test MyString x is: " << x << endl;
		cout << "The first character of MyString x is: " << x[0] << endl;
		cout << "The last character of MyString x is: " << x[x.length() - 1] << endl;
	}
	cout << "testBrackets ends.\n" << endl;
}

void testIndexOf()
{
	cout << "testIndexOf begins." << endl;
	MyString l("abbcbcbcaac");
	cout << "Test MyString l is: " << l << endl;
	cout << "The index of 'a' that first appears in MyString l is: " << l.indexOf('a') << endl;
	cout << "The index of 'b' that first appears in MyString l is: " << l.indexOf('b') << endl;
	cout << "The index of \"bc\" that first appears in MyString l is: " << l.indexOf(MyString("bc")) << endl;
	cout << "The index of \"cb\" that first appears in MyString l is: " << l.indexOf(MyString("cb")) << endl;
	cout << "testIndexOf ends.\n" << endl;
}

void testEqual()
{
	cout << "testEqual begins." << endl;
	MyString a;
	MyString b;
	MyString c("");
	MyString d(" ");
	MyString e(" ");
	cout << (a == b) << "(should be 1)" << endl;
	cout << (b == c) << "(should be 1)" << endl;
	cout << (c == d) << "(should be 0)" << endl;
	cout << (d == e) << "(should be 1)" << endl;
	cout << "testEqual ends.\n" << endl;
}

void testPlus()
{
	cout << "testPlus begins." << endl;
	MyString a("abc");
	MyString b("def");
	cout << (a + b) << "(should be \"abcdef\")" << endl;
	MyString ab(a + b);
	cout << ab << "(should be \"abcdef\")" << endl;
	MyString nullchar("\0");
	cout << (a + nullchar + b) << "(should be \"abcdef\")" << endl;
	cout << "testPlus ends.\n" << endl;
}

void testPlusAssignment()
{
	cout << "testPlusAssignment begins." << endl;
	MyString a("abc");
	MyString b("def");
	a += b;
	cout << a << "(should be \"abcdef\")" << endl;
	cout << b << "(should be \"def\")" << endl;
	b = MyString("123");
	cout << a << "(should be \"abcdef\")" << endl;
	cout << b << "(should be \"123\")" << endl;
	MyString c("AAA");
	b += a + c;
	cout << b << "(should be \"123abcdefAAA\")" << endl;
	cout << "testPlusAssignment ends.\n" << endl;
}

int main()
{
	try {
		testReverse();
		testAssignment();
		testBrackets();
		testIndexOf();
		testEqual();
		testPlus();
		testPlusAssignment();
	}
	catch (int i) {
		cout << "Got an exception: " << i << endl;
	}
	cerr << "Net memory allocated at program end: " << MyString::get_NumAllocations() << endl;
	cerr << "(should be zero! positive = memory leak, negative = duplicative delete)\n";
	return 0;
}