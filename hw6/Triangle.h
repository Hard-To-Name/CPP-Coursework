class Triangle : public Shape
{
protected:
	int height;
	int base;
public:
	Triangle(int h_val, int b_val, int x_val, int y_val, string name_val)
		: Shape(x_val, y_val, name_val), height(h_val), base(b_val)
	{}
	virtual double area()
	{
		return (double)height * base / 2;
	}
	virtual void draw()
	{
		for (int h = height - 1; h > 0; --h)
		{
			for (int i = 0; i < h; ++i)
			{
				cout << ' ';
			}
			cout << '*';
			for (int i = 0; i < 2 * (height - h) - 3; ++i)
			{
				cout << ' ';
			}
			if (h != height - 1) cout << '*';
			cout << endl;
		}
		for (int i = 0; i < 2 * height - 1; ++i)
			cout << '*';
		cout << endl;
	}
};