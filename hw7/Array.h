#include<cassert>
#include<iomanip>
#include"IndexOutOfBoundsException.h"

template
    <typename Element>
class Array
{
private:
	int len;
	Element *buf;
public:
	Array(int newLen)
		: len(newLen), buf(new Element[newLen])
	{}
	Array(const Array &l)
		: len(l.len), buf(new Element[l.len])
	{
		for (int i = 0; i < l.len; i++)
			buf[i] = l.buf[i];
	}
	int length()
	{
		return len;
	}
	Array operator = (const Array &l)
	{
		delete[] buf;
		for (int i = 0; i < l.len(); i++)
		{
			buf[i] = l.buf[i];
		}
	}
	Element &operator [] (int i)
		throw(IndexOutOfBoundsException)
	{
		if (0 > i || i >= len) { throw IndexOutOfBoundsException(); }
		return buf[i];
	}
	void print(ostream &out)
	{
		for (int i = 0; i < len; ++i)
			out << setw(8) << setprecision(2) << fixed << right << buf[i];
	}
	~Array()
	{
		delete[] buf;
	}
	friend ostream &operator << (ostream &out, Array &a)
	{
		a.print(out);
		return out;
	}
	friend ostream &operator << (ostream &out, Array *ap)
	{
		ap->print(out);
		return out;
	}
};
