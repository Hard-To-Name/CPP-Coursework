#include"Array.h"

template
	<typename Element>
class Matrix
{
private:
	int rows, cols;
	Array<Array<Element>*> m;
public:
	Matrix(int newRows, int newCols)
		: rows(newRows), cols(newCols), m(rows)
	{
		for (int i = 0; i < rows; i++)
			m[i] = new Array<Element>(cols);
	}
	Matrix operator = (Matrix &mat)
	{
		delete m;
		for (int i = 0; i < rows; ++i)
			m[i] = new Array<Element>(mat.m[i]);
		return this;
	}
	int numRows()
	{
		return rows;
	}
	int numCols()
	{
		return cols;
	}
	Array<Element> &operator [] (int row)
		throw(IndexOutOfBoundsException)
	{
		if (0 > row || row >= rows) { throw IndexOutOfBoundsException(); }
		return *m[row];
	}
	~Matrix()
	{
		for (int i = 0; i < rows; ++i)
			delete m[i];
	}
	void print(ostream &out)
	{
		for (int i = 0; i < rows; i++)
		{
			out << m[i] << endl;
		}
	}
	friend ostream &operator << (ostream &out, Matrix &m)
	{
		m.print(out);
		return out;
	}
};
