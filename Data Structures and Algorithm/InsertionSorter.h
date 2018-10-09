#ifndef SORTER
#define SORTER
#include"Sorter.h"
#endif

class InsertionSorter: public Sorter
{
	int binary_search(int start, int end, string &temp)
	// O(lgN)
	{
		if (start == end)
		{
			if (temp < buf[start]) return start;
			else return start + 1;
		}
		int mid = (start + end) / 2;
		if (buf[mid] > temp) return binary_search(start, mid, temp);
		else return binary_search(mid + 1, end, temp);
	}

	void insertion_swap(int i, int j)
	// O(N)
	{
		string temp = buf[i];
		for (int k = i; k > j; --k)
			buf[k] = buf[k - 1];
		buf[j] = temp;
	}

public:
	InsertionSorter(int cap)
		:Sorter(cap) {}

	virtual void sort()
	// O(N^2)
	{
		for (int i = 1; i < size; ++i)
		{
			int j = binary_search(0, i - 1, buf[i]);
			insertion_swap(i, j);
		}
	}

	~InsertionSorter() {}
};
