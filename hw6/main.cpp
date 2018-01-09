#include"Picture.h"
#include"Circle.h"
#include"Square.h"
#include"Triangle.h"

int main()
{
	Picture pic;
	pic.add(new Triangle(5, 5, 0, 0, "FirstTriangle"));
	pic.add(new Triangle(4, 3, 0, 0, "SecondTriangle"));
	pic.add(new Circle(5, 0, 0, "FirstCircle"));
	pic.add(new Circle(10, 0, 0, "SecondCircle"));
	pic.add(new Square(5, 0, 0, "FirstSquare"));
	pic.add(new Square(10, 0, 0, "SecondSquare"));
	pic.add(new Rectangle(4, 8, 0, 0, "FirstRectangle"));
	pic.add(new Rectangle(8, 4, 0, 0, "SecondRectangle"));
	pic.drawAll();
	cout << "Total area = " << pic.totalArea() << endl;
	return 0;
}