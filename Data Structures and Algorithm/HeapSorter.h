#ifndef SORTER
#define SORTER
#include"Sorter.h"
#endif

class HeapSorter : public Sorter
{
	void swap(string &str1, string &str2)
	// O(1)
	{
		string temp = str1;
		str1 = str2;
		str2 = temp;
	}

	void heapify(int n, int i)
	// O(lgN)
	{
		int l = 2 * i + 1;
		if (l >= n) return;
		if (l + 1 < n && buf[l] < buf[l + 1])
			++l;
		if (buf[i] < buf[l])
		{
			swap(buf[i], buf[l]);
			heapify(n, l);
		}
	}

public:
	HeapSorter(int cap)
		:Sorter(cap) {}

	virtual void sort()
	// O(lgN)
	{
		for (int i = (size - 1) / 2; i >= 0; --i)
			heapify(size, i);
		for (int i = size - 1; i >= 0; --i)
		{
			swap(buf[0], buf[i]);
			heapify(i, 0);
		}
	}

	~HeapSorter() {}
};
