#include"Rectangle.h"

class Square : public Rectangle
{
public:
	Square(int s_val, int x_val, int y_val, string name_val)
		: Rectangle(s_val, s_val, x_val, y_val, name_val)
	{}
};