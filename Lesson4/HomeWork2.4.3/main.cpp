#include<iostream>
enum  Examination 
{
	Wrong,
	Right
};
class Figure
{
protected:
	std::string name = "Figure";

	int side_a = 0;
	int side_b = 0;
	int side_c = 0;
	int side_d = 0;

	int angel_a = 0;
	int angel_b = 0;
	int angel_c = 0;
	int angel_d = 0;

public:
	
	virtual bool check()
	{
		if ((side_a == 0) && (side_b == 0) && (side_c == 0) && (side_d == 0))
		return Right;
	}
	virtual void print_info()
	{
		std::cout << name << ":" << std::endl;
		std::cout << ((check() == 0) ? "Wrong" : "Right") << std::endl;
		std::cout << "Number of sides: 0" << std::endl;
		std::cout << std::endl;
	}
};

void print(Figure* figure)
{
	figure->print_info();
}

class Triangle : public Figure
{
public:
	Triangle() {}

	Triangle(const int& side_a, const int& side_b, const int& side_c, const int& angel_a, const int& angel_b, const int& angel_c)
	{
		name = "Triangle";
		this->side_a = side_a;
		this->side_b = side_b;
		this->side_c = side_c;
		this->angel_a = angel_a;
		this->angel_b = angel_b;
		this->angel_c = angel_c;
	}
	bool check() override
	{
		if ((side_a > 0) && (side_b > 0) && (side_c > 0) && ((angel_a + angel_b + angel_c) == 180))
		{
			return Right;
		}
		else if((side_a <= 0) || (side_b <= 0) || (side_c <= 0) || ((angel_a + angel_b + angel_c) != 180))
		{
			return Wrong;
		}
	}
	void print_info() override
	{
		std::cout << name << ":" << std::endl;
		std::cout << ((check() == 0) ? "Wrong" : "Right") << std::endl;
		std::cout << "Number of sides: 3" << std::endl;
		std::cout << "Sides : " << "a = " << side_a << " b = " << side_b << " c = " << side_c << std::endl;
		std::cout << "Angels : " << "A = " << angel_a << " B = " << angel_b << " C = " << angel_c << std::endl;
		std::cout << "\n";
	}

};

class RightTriangle : public Triangle
{
public:
	RightTriangle(const int& side_a, const int& side_b, const int& side_c, const int& angel_a, const int& angel_b)
	{
		name = "Right triangle";
		this->side_a = side_a;
		this->side_b = side_b;
		this->side_c = side_c;
		this->angel_a = angel_a;
		this->angel_b = angel_b;
		this->angel_c = 90;
	}
	bool check() override
	{
		if ((angel_c) != 90)
		{
			return Wrong;
		}
		else
		{
			Triangle::check();
		}
	}

};

class IsoscelesTriangle : public Triangle
{
public:
	IsoscelesTriangle(const int& side_a, const int& side_b, const int& angel_a, const int& angel_b)
	{

		name = "IsoscelesTriangle";
		this->side_a = side_a;
		this->side_b = side_b;
		this->angel_a = angel_a;
		this->angel_b = angel_b;
		side_c = side_a;
		angel_c = angel_a;
	}
	bool check() override
	{
		if ((side_c != side_a) || (angel_c != angel_a))
		{
			return Wrong;
		}
		else
		{
			Triangle::check();
		}
	}
};

class EquilateralTriangle : public Triangle
{
public:
	EquilateralTriangle(const int& side_a)
	{

		name = "EquilateralTriangle";
		this->side_a = side_a;
		this->angel_a = 60;
		this->angel_b = 60;
		this->angel_c = 60;
		side_c = side_a;
		side_b = side_a;
	}
	bool check() override
	{
		if ((angel_a != 60) || (angel_c != 60) || (angel_b != 60) || (side_a != side_c) || (side_a != side_b))
		{
			return Wrong;
		}
		else
		{
			Triangle::check();
		}
	}
};

class Quadrangle :public Figure
{

public:

	Quadrangle() {}

	Quadrangle(const int& side_a, const int& side_b, const int& side_c, const int& side_d, const int& angel_a, const int& angel_b, const int& angel_c, const int& angel_d)
	{
		name = "Quadrangle";
		this->side_a = side_a;
		this->side_b = side_b;
		this->side_c = side_c;
		this->side_d = side_d;

		this->angel_a = angel_a;
		this->angel_b = angel_b;
		this->angel_c = angel_c;
		this->angel_d = angel_d;

	}
	bool check() override
	{
		if ((side_a > 0) && (side_b > 0) && (side_c > 0) && (side_d > 0) && ((angel_a + angel_b + angel_c + angel_d) == 360))
		{
			return Right;
		}
		else if ((side_a <= 0) || (side_b <= 0) || (side_c <= 0) || (side_d <= 0) ||((angel_a + angel_b + angel_c + angel_d) != 360))
		{
			return Wrong;
		}
	}
	void print_info() override
	{
		std::cout << name << ":" << std::endl;
		std::cout << ((check() == 0) ? "Wrong" : "Right") << std::endl;
		std::cout << "Number of sides: 4" << std::endl;
		std::cout << "Sides : " << "a = " << side_a << " b = " << side_b << " c = " << side_c << " d = " << side_d << std::endl;
		std::cout << "Angels : " << "A = " << angel_a << " B = " << angel_b << " C = " << angel_c << " D = " << angel_d << std::endl;
		std::cout << "\n";
	}
};

class Rectangle :public Quadrangle
{
public:

	Rectangle() {}

	Rectangle(const int& side_a, const int& side_b)
	{
		name = "Rectangle";
		this->side_a = side_a;
		this->side_b = side_b;
		side_c = side_a;
		side_d = side_b;

		this->angel_a = 90;
		this->angel_b = 90;
		this->angel_c = 90;
		this->angel_d = 90;

	}
	bool check() override
	{
		if ((angel_a != 90) || (angel_c != 90) || (angel_b != 90) || (angel_d != 90) || (side_a != side_c) || (side_d != side_b))
		{
			return Wrong;
		}
		else
		{
			Quadrangle::check();
		}
	}
};

class Square : public Quadrangle
{
public:

	Square() {}

	Square(const int& side_a)
	{
		name = "Square";
		this->side_a = side_a;
		side_b = side_a;
		side_c = side_a;
		side_d = side_a;

		this->angel_a = 90;
		this->angel_b = 90;
		this->angel_c = 90;
		this->angel_d = 90;
	}
	bool check() override
	{
		if ((angel_a != 90) || (angel_c != 90) || (angel_b != 90) || (angel_d != 90) || (side_a != side_c) || (side_a != side_b) || (side_a != side_d))
		{
			return Wrong;
		}
		else
		{
			Quadrangle::check();
		}
	}
};


class Parallelogram : public Quadrangle
{
public:
	Parallelogram(const int& side_a, const int& side_b, const int& angel_a, const int& angel_b)
	{
		name = "Parallelogram";
		this->side_a = side_a;
		this->side_b = side_b;
		side_c = side_a;
		side_d = side_b;

		this->angel_a = angel_a;
		this->angel_b = angel_b;
		angel_c = angel_a;
		angel_d = angel_b;
	}
	bool check() override
	{
		if ((angel_a != angel_c) || (angel_b != angel_d) || (side_a != side_c) || (side_d != side_b))
		{
			return Wrong;
		}
		else
		{
			Quadrangle::check();
		}
	}
};

class Rhombus : public Quadrangle
{
public:
	Rhombus(const int& side_a, const int& angel_a, const int& angel_b)
	{
		name = "Rhombus";
		this->side_a = side_a;
		side_c = side_a;
		side_b = side_a;
		side_d = side_a;

		this->angel_a = angel_a;
		this->angel_b = angel_b;
		angel_c = angel_a;
		angel_d = angel_b;
	}
	bool check() override
	{
		if ((angel_a != angel_c ) || (angel_b != angel_d) || (side_a != side_c) || (side_a != side_b) || (side_a != side_d))
		{
			return Wrong;
		}
		else
		{
			Quadrangle::check();
		}
	}
};

int main()
{
	Figure figure;
	Triangle triangle(20, 30, 800, 120, 30, 30);
	RightTriangle right_triangle(5, 10, 15, 80, 10);
	IsoscelesTriangle isosceles_triangle(25, 30, 10, 160);
	EquilateralTriangle equilateral_triangle(125);
	Rectangle rectangle(50, 60);
	Quadrangle quadrangle(41, 42, 43, 44, 60, 30, 120, 150);
	Square square(555);
	Parallelogram parallelogram(51, 52, 110, 60);
	Rhombus rhombus(75, 123, 124);


	


	print(&figure);
	print(&triangle);
	print(&right_triangle);
	print(&isosceles_triangle);
	print(&equilateral_triangle);
	print(&quadrangle);
	print(&rectangle);
	print(&square);
	print(&parallelogram);
	print(&rhombus);


	return 0;
}