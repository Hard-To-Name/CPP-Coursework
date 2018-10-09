#ifndef SORTER
#define SORTER
#include"Sorter.h"
#endif

class QuickSorter : public Sorter
{
	void swap(string &str1, string &str2)
	// O(1)
	{
		string temp = str1;
		str1 = str2;
		str2 = temp;
	}

	void medianOfThree(int start, int end)
	// O(1)
	{
		int center = (start + end) / 2;
		if (buf[start] <= buf[center] && buf[center] <= buf[end]) return;
		if (buf[center] <= buf[start] && buf[start] <= buf[end])
			swap(buf[start], buf[center]);
		else swap(buf[end], buf[center]);
	}

	void partition(int start, int end, int pivot)
	// O(N)
	{
		for (int i = start; i < end; ++i)
		{
			if (i < pivot && buf[i] > buf[pivot])
				swap(buf[i], buf[pivot]);
			else if (i > pivot && buf[i] < buf[pivot])
				swap(buf[i], buf[pivot]);
		}
	}

	void insertionsort(int start, int end)
	// O(N^2)
	{
		for (int i = start + 1; i < end; ++i)
		{
			int j = i - 1;
			for (j; j >= 0; --j)
				if (buf[j] > buf[i])
					swap(buf[j], buf[i]);
				else break;
		}
	}

	void quicksort(int start, int end)
	// O(NlgN)
	{
		if (end - start < 16)
			insertionsort(start, end);
		else
		{
			int pivot = (start + end) / 2;
			medianOfThree(start, end);
			partition(start, end, pivot);
			quicksort(start, pivot);
			quicksort(pivot + 1, end);
		}
	}

public:
	QuickSorter(int cap)
		:Sorter(cap) {}

	virtual void sort()
	{
		quicksort(0, size);
	}

	~QuickSorter() {}
};
