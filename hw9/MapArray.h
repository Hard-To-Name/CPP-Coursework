#define STACK_CAPACITY 10000
#include <iterator>
using namespace std;


template <typename KEY, typename VALUE>
class MapArray
{
private:
	int sz;
	pair<KEY, VALUE>* head[STACK_CAPACITY];
public:
	struct iterator
	{
		typedef forward_iterator_tag iterator_category;
		typedef iterator self_type;
		typedef pair<KEY, VALUE>* value_type;
		typedef pair<KEY, VALUE>*& reference;
		typedef pair<KEY, VALUE>** pointer;
		typedef ptrdiff_t difference_type;
	private:
		pointer ibuf;
	public:
		iterator(pointer ptr) : ibuf(ptr) {}
		self_type operator ++ () 
		{ ++ibuf; return *this; }
		self_type operator ++ (int postfix)
		{ self_type cpy = *this; ibuf++; return cpy; }
		reference operator * () { return *ibuf; }
		pointer operator -> () { return ibuf; }
		bool operator == (const self_type& rhs) const
		{ return ibuf == rhs.ibuf; }
		bool operator != (const self_type& rhs) const
		{ return ibuf != rhs.ibuf; }
	};

	struct const_iterator
	{
		typedef forward_iterator_tag iterator_category;
		typedef const_iterator self_type;
		typedef pair<KEY, VALUE>* value_type;
		typedef pair<KEY, VALUE>*& reference;
		typedef pair<KEY, VALUE>** pointer;
		typedef ptrdiff_t difference_type;
	private:
		pointer ibuf;
	public:
		const_iterator(pointer ptr) : ibuf(ptr) {}
		self_type operator ++ ()
		{
			++ibuf; return *this;
		}
		self_type operator ++ (int postfix)
		{
			self_type cpy = *this; ibuf++; return cpy;
		}
		const reference operator * () { return *ibuf; }
		const pointer operator -> () { return ibuf; }
		bool operator == (const self_type& rhs) const
		{
			return ibuf == rhs.ibuf;
		}
		bool operator != (const self_type& rhs) const
		{
			return ibuf != rhs.ibuf;
		}
	};

	MapArray() : sz(0)
	{
		for (int i = 0; i < STACK_CAPACITY; ++i)
			head[i] = nullptr;
	}
	int size() const { return sz; }
	iterator begin() { return iterator(head); }
	iterator end() { return iterator(head+sz); }
	const_iterator begin() const { return const_iterator(head); }
	const_iterator end() const { return const_iterator(head + sz); }
	int find(const KEY& val)
	{
		for (int i = 0; i < sz; ++i)
			if (head[i]->first == val)
				return i;
		return -1;
	}
	VALUE& operator [] (KEY key)
	{
		int index = find(key);
		if (index == -1)
		{
			head[sz] = new pair<string, int>(key, 0);
			++sz;
			return head[sz-1]->second;
		}
		return head[index]->second;
	}
	void sort()
	{
		for (int i = 0; i < sz; ++i)
		{
			int min = i;
			for (int j = i; j < sz; ++j)
			{
				if (head[min]->first > head[j]->first)
					min = j;
			}
			pair<KEY, VALUE>* temp = head[i];
			head[i] = head[min];
			head[min] = temp;
		}
	}
	~MapArray()
	{
		for (int i = 0; i < STACK_CAPACITY; ++i)
			delete head[i];
	}
};