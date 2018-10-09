#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include<iostream>
using namespace std;

template<typename Element>
class PriorityQueue
{
	Element **queue;
	int *indices, *inverse;
	int size, capacity;

public:
	PriorityQueue(int cap)
		:queue(new Element*[cap]), indices(new int[cap]), 
		inverse(new int[cap]), size(0), capacity(cap) {}

	Element* operator [] (int pos)
	// O(1)
	{
		return queue[pos];
	}

	bool isEmpty()
	// O(1)
	{
		return size == 0;
	}

	void swap(int &i1, int &i2)
	// O(1)
	{
		int temp = i1;
		i1 = i2;
		i2 = temp;
	}

	void sift_up(int pos)
	// O(lgN)
	{
		if (pos == 0 || pos >= size) return;
		int parent = (pos - 1) / 2;
		if (*queue[indices[pos]] < *queue[indices[parent]])
		{
			swap(indices[pos], indices[parent]);
			swap(inverse[indices[pos]], inverse[indices[parent]]);
			sift_up(parent);
		}
	}

	void sift_down(int pos)
	// O(lgN)
	{
		int left = pos * 2 + 1;
		if (left >= size) return;
		if (left + 1 < size && *queue[indices[left]] > *queue[indices[left + 1]])
			++left;
		if (*queue[indices[pos]] > *queue[indices[left]])
		{
			swap(indices[pos], indices[left]);
			swap(inverse[indices[pos]], inverse[indices[left]]);
			sift_down(left);
		}
	}

	void insert(Element &e)
	// O(lgN)
	{
		queue[size] = &e;
		indices[size] = size;
		inverse[size] = size;
		sift_up(size);
		++size;
	}

	Element* extractMin()
	// O(lgN)
	{
		--size;
		swap(indices[0], indices[size]);
		swap(inverse[indices[0]], inverse[indices[size]]);
		sift_down(0);
		return queue[indices[size]];
	}

	void decreaseKey(int id)
	// O(lgN)
	{
		sift_up(inverse[id]);
	}

	
	void print()
	{
		for (int i = 0; i < size; ++i)
		{
			for (Vertex *v = queue[i]; v != nullptr; v = v->adjacent)
				cout << "(" << v->id << ", " << v->distance << ") ->";
			cout << endl;
		}
	}

	~PriorityQueue()
	{
		delete[] indices;
		delete[] inverse;
		delete[] queue;
	}
};

#endif
