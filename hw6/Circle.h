class Circle : public Shape
{
private:
	const double PI = 3.14159;
protected:
	int radius;
public:
	Circle(int r_val, int x_val, int y_val, string name_val)
		: Shape(x_val, y_val, name_val), radius(r_val)
	{}
	virtual double area()
	{
		return PI * radius * radius;
	}
	virtual void draw()
	{
		for (int i = radius; i >= -radius; --i)
		{
			double step = 1.0, sqrt = radius * radius - i*i;
			while (step * step - sqrt > 1e-8 ||
				step * step - sqrt < -(1e-8))
			{
				step = (step + sqrt / step) / 2;
			}
			int j, m = 2 * step;
			for (j = 1; j< 3 * radius - m; ++j) cout << ' ';
			cout << '*';
			for (; j < 3 * radius + m; ++j) cout << ' ';
			cout << '*' << endl;
		}
	}
};