class Rectangle : public Shape
{
protected:
	int height;
	int width;
public:
	Rectangle(int h_val, int w_val, int x_val, int y_val, string name_val)
		: Shape(x_val, y_val, name_val), height(h_val), width(w_val)
	{}
	virtual double area()
	{
		return height * width;
	}
	virtual void draw()
	{
		for (int a = 0; a < width; ++a)
			cout << '*';
		cout << endl;
		if (height == 1) return;
		for (int i = 1; i < height - 1; ++i)
		{
			cout << '*';
			for (int j = 0; j < width - 2; ++j)
				cout << ' ';
			cout << '*' << endl;
		}
		for (int b = 0; b < width; ++b)
			cout << '*';
		cout << endl;
	}
};