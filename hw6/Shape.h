#include<iostream>
using namespace std;

class Shape
{
public:
	int centerX;
	int centerY;
	string name;
	Shape(int x_val, int y_val, string name_val)
		: centerX(x_val),  centerY(y_val), name(name_val)
	{}
	virtual double area() = 0;
	virtual void draw() = 0;
	virtual ~Shape() {}
};