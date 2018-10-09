#ifndef iostream
#include<iostream>
#include<string>
using namespace std;
#endif

class SortedArrayList
{
private:
	string *buf;
	int capacity, size;

	void copyUp(int i)
	{
		for (int x = i; x < size - 1; ++x)
			buf[x] = buf[x + 1];
		--size;
	}

	void copyDown(int i) // O(N)
	{
		for (int x = size; x > i; --x)
			buf[x] = buf[x - 1];
		++size;
	}

	static int binarySearch(string *buf, string key, int min, int max) // O(lgN)
	{
		int mid = 0;
		while (min <= max)
		{
			mid = (min + max) / 2;
			if (buf[mid] > key) max = mid - 1;
			else if (buf[mid] < key)
			{
				++mid;
				min = mid;
			}
			else if (buf[mid] == key) return mid;
		}
		return -mid - 1;
	}

public:
	SortedArrayList(int cap)
		: buf(new string[cap]), capacity(cap), size(0) {}

	SortedArrayList(const SortedArrayList &SAL)
	{
		buf = new string[SAL.size + 1];
		for (int i = 0; i < size; ++i)
			buf[i] = SAL.buf[i];
	}

	bool isEmpty()
	{
		return size == 0;
	}

	bool isFull()
	{
		return size == capacity;
	}

	void insert(string word) // O(N)
	{
		if (isFull()) return;
		int index = binarySearch(buf, word, 0, size - 1);
		if (index < 0)
		{
			index = -index - 1;
			copyDown(index);
			buf[index] = word;
		}
	}

	bool find(string word)
	{
		int index = binarySearch(buf, word, 0, size - 1);
		return index >= 0;
	}

	void remove(string word)
	{
		if (isEmpty()) return;
		int index = binarySearch(buf, word, 0, size - 1);
		if (index < 0) return;
		copyUp(index);
		buf[size] = "";
	}

	void print(ostream &out)
	{
		for (int i = 0; i < size; ++i)
		out << buf[i];
	}

	~SortedArrayList()
	{
		for (int i = size - 1; i >= 0; --i)
			remove(buf[i]);
		delete[] buf;
	}
};

inline ostream& operator << (ostream &out, SortedArrayList SAL)
{
	SAL.print(out);
	return out;
}
