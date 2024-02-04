#include<iostream>



class Figure
{
protected:
		std::string name;
	
public:

	virtual void print_info()
	{
		
	}
	
};

void print(Figure* figure)
{
	figure->print_info();
}

class Triangle : public Figure
{

protected:
	int side_a = 10;
	int side_b = 20;
	int side_c = 30;
	int angel_a = 50;
	int angel_b = 60;
	int angel_c = 70;
	
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
	void print_info() override
	{
		std::cout << name << ":" << std::endl;
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
		
	void print_info() override
	{
		std::cout << name << ":" << std::endl;
		std::cout << "Sides : " << "a = " << side_a << " b = " << side_b << " c = " << side_c << std::endl;
		std::cout << "Angels : " << "A = " << angel_a << " B = " << angel_b << " C = " << angel_c << std::endl;
		std::cout << "\n";
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
	void print_info() override
	{
		std::cout << name << ":" << std::endl;
		std::cout << "Sides : " << "a = " << side_a << " b = " << side_b << " c = " << side_c << std::endl;
		std::cout << "Angels : " << "A = " << angel_a << " B = " << angel_b << " C = " << angel_c << std::endl;
		std::cout << "\n";
	}
};

class EquilateralTriangle : public Triangle
{
public:
	EquilateralTriangle(const int& side_a)
	{

		name = "IsoscelesTriangle";
		this->side_a = side_a;
		this->angel_a = 60;
		this->angel_b = 60;
		this->angel_c = 60; 
		side_c = side_a;
		side_b = side_a;
		
	}
	void print_info() override
	{
		std::cout << name << ":" << std::endl;
		std::cout << "Sides : " << "a = " << side_a << " b = " << side_b << " c = " << side_c << std::endl;
		std::cout << "Angels : " << "A = " << angel_a << " B = " << angel_b << " C = " << angel_c << std::endl;
		std::cout << "\n";
	}
};

class Quadrangle :public Figure
{
protected:
	int side_a = 10;
	int side_b = 20;
	int side_c = 30;
	int side_d = 40;
	int angel_a = 50;
	int angel_b = 60;
	int angel_c = 70;
	int angel_d = 80;

public:

	Quadrangle(){}

	Quadrangle(const int& side_a, const int& side_b, const int& side_c,const int& side_d, const int& angel_a, const int& angel_b, const int& angel_c,const int& angel_d)
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
	void print_info() override
	{
		std::cout << name << ":" << std::endl;
		std::cout << "Sides : " << "a = " << side_a << " b = " << side_b << " c = " << side_c << " d = " << side_d << std::endl;
		std::cout << "Angels : " << "A = " << angel_a << " B = " << angel_b << " C = " << angel_c << " D = " << angel_d << std::endl;
		std::cout << "\n";
	}
};

class Rectangle :public Figure
{
protected:
	int side_a = 10;
	int side_b = 20;
	int side_c = 30;
	int side_d = 40;
	int angel_a = 50;
	int angel_b = 60;
	int angel_c = 70;
	int angel_d = 80;

public:

	Rectangle(){}

	Rectangle(const int& side_a, const int& side_b)
	{
		name = "Rectangle";
		this->side_a = side_a;
		this->side_b = side_b;
		side_c = side_a ;
		side_d = side_b;
		
		this->angel_a = 90;
		this->angel_b = 90;
		this->angel_c = 90;
		this->angel_d = 90;
		
	}
	void print_info() override
	{
		std::cout << name << ":" << std::endl;
		std::cout << "Sides : " << "a = " << side_a << " b = " << side_b << " c = " << side_c << " d = " << side_d << std::endl;
		std::cout << "Angels : " << "A = " << angel_a << " B = " << angel_b << " C = " << angel_c << " D = " << angel_d << std::endl;
		std::cout << "\n";
	}
};

class Square : public Rectangle
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
		this->angel_d = 90;;
	}
	void print_info() override
	{
		std::cout << name << ":" << std::endl;
		std::cout << "Sides : " << "a = " << side_a << " b = " << side_b << " c = " << side_c << " d = " << side_d << std::endl;
		std::cout << "Angels : " << "A = " << angel_a << " B = " << angel_b << " C = " << angel_c << " D = " << angel_d << std::endl;
		std::cout << "\n";
	}
};

class Parallelogram : public Rectangle
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
	void print_info() override
	{
		std::cout << name << ":" << std::endl;
		std::cout << "Sides : " << "a = " << side_a << " b = " << side_b << " c = " << side_c << " d = " << side_d << std::endl;
		std::cout << "Angels : " << "A = " << angel_a << " B = " << angel_b << " C = " << angel_c << " D = " << angel_d << std::endl;
		std::cout << "\n";
	}
};

class Rhombus : public Square
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
	void print_info() override
	{
		std::cout << name << ":" << std::endl;
		std::cout << "Sides : " << "a = " << side_a << " b = " << side_b << " c = " << side_c << " d = " << side_d << std::endl;
		std::cout << "Angels : " << "A = " << angel_a << " B = " << angel_b << " C = " << angel_c << " D = " << angel_d << std::endl;
		std::cout << "\n";
	}
};

int main()
{
	Figure figure;
	Triangle triangle(20, 30, 800, 500, 600, 700);
	RightTriangle right_triangle(5, 10, 15, 20, 30);
	IsoscelesTriangle isosceles_triangle(25,30,100,70);
	EquilateralTriangle equilateral_triangle(125);
	Rectangle rectangle(50, 60);
	Quadrangle quadrangle(41,42,43,44,45,46,47,48);
	Square square(555);
	Parallelogram parallelogram(51, 52, 53, 54);
	Rhombus rhombus(75, 123, 124);

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