#include<fstream>
#include<iostream>
#include<string>
#include"Timer.h"
using namespace std;

class Sorter
{
protected:
	string *buf;
	int capacity, size;

	void insert(string s)
	{
		buf[size] = s;
		++size;
	}

public:
	Sorter(int cap)
		:buf(new string[cap]), capacity(cap), size(0) {}

	// copy constructor

	double insertAllFromFile(const char *fileName, int numItemsToLoad)
	// O(N^2)
	{
		ifstream in(fileName);
		string temp;
		for (int i = 0; i < numItemsToLoad; ++i)
		{
			in >> temp;
			insert(temp);
		}
		Timer t;
		double eTime;
		t.start();
		sort();
		t.elapsedUserTime(eTime);
		return eTime;
	}

	void print(ostream &out)
	{
		for (int i = 0; i < size; ++i)
		{
			out << buf[i] << endl;
		}
	}

	virtual void sort() = 0;

	~Sorter()
	{
		delete[] buf;
	}
};
