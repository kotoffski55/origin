#include<iostream>
// Родительский класс  треугольник 


class Figure
{
	
		// защищенные поля 
protected:
		std::string name;
		int side_a = 10;
		int side_b = 20;
		int side_c = 30;
		int side_d = 40;
		int angel_a = 50;
		int angel_b = 60;
		int angel_c = 70;
		int angel_d = 80;
public:

	virtual void print_info()
	{
		std::cout << name << ":" << std::endl;
		std::cout << "Sides : " << "a = " << side_a << " b = " << side_b << " c = " << side_c << " d = " << side_d << std::endl;
		std::cout << "Angels : " << "A = " << angel_a << " B = " << angel_b << " C = " << angel_c << " D = " << angel_d << std::endl;
		std::cout << "\n";
	}
	
};

class Triangle : public Figure
{
	
public:

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

	//вывод информации  о треугольнике 
	void print_info() override
	{
		std::cout << name << ":" << std::endl;
		std::cout << "Sides : " << "a = " << side_a << " b = " << side_b << " c = " << side_c << std::endl;
		std::cout << "Angels : " << "A = " << angel_a << " B = " << angel_b << " C = " << angel_c << std::endl;
		std::cout << "\n";
	}


};
//Функция вызова метода печати 
void print(Figure* figure)
{
	figure->print_info();
}


  
class Rectangle :public Figure
{


public:

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


/*

class RightTriangle : public Triangle
{
public:
	RightTriangle()
	{
		angel_c = 90;
		name = "Right triangle";
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
	IsoscelesTriangle()
	{
		side_c = side_a;
		angel_c = angel_a;
		name = "IsoscelesTriangle";
	}
	void print_info() override
	{
		std::cout << name << ":" << std::endl;
		std::cout << "Sides : " << "a = " << side_a << " b = " << side_b << " c = " << side_c << std::endl;
		std::cout << "Angels : " << "A = " << angel_a << " B = " << angel_b << " C = " << angel_c << std::endl;
		std::cout << "\n";
	}
};



//Классы наследники  для  четырехугольника 

class Rectangle : public Quadrangle
{
public:
	Rectangle()
	{
		angel_a = 90;
		angel_b = 90;
		angel_c = 90;
		angel_d = 90;

		side_c = side_a;
		side_d = side_b;

		name = "Rectangle";
	}
	void print_info() override
	{
		std::cout << name << ":" << std::endl;
		std::cout << "Sides : " << "a = " << side_a << " b = " << side_b << " c = " << side_c << " d = " << side_d << std::endl;
		std::cout << "Angels : " << "A = " << angel_a << " B = " << angel_b << " C = " << angel_c << " D = " << angel_d << std::endl;
		std::cout << "\n";
	}
};

// Для квадрата  базовый класс прямоугольник 
class Square : public Rectangle
{
public:
	Square()
	{

		side_a = 50;
		side_b = 50;
		side_c = 50;
		side_d = 50;

		name = "Square";
	}
	void print_info() override
	{
		std::cout << name << ":" << std::endl;
		std::cout << "Sides : " << "a = " << side_a << " b = " << side_b << " c = " << side_c << " d = " << side_d << std::endl;
		std::cout << "Angels : " << "A = " << angel_a << " B = " << angel_b << " C = " << angel_c << " D = " << angel_d << std::endl;
		std::cout << "\n";
	}
};

class Parallelogram : public Quadrangle
{
public:
	Parallelogram()
	{

		angel_c = angel_a;
		angel_d = angel_b;

		side_c = side_a;
		side_d = side_b;

		name = "Parallelogram";
	}
	void print_info() override
	{
		std::cout << name << ":" << std::endl;
		std::cout << "Sides : " << "a = " << side_a << " b = " << side_b << " c = " << side_c << " d = " << side_d << std::endl;
		std::cout << "Angels : " << "A = " << angel_a << " B = " << angel_b << " C = " << angel_c << " D = " << angel_d << std::endl;
		std::cout << "\n";
	}
};

//Для ромба возьмем базовый класс квадрат  
class Rhombus : public Square
{
public:
	Rhombus()
	{
		angel_a = 30;
		angel_c = angel_a;
		angel_b = 50;
		angel_d = angel_b;

		name = "Rhombus";
	}
	void print_info() override
	{
		std::cout << name << ":" << std::endl;
		std::cout << "Sides : " << "a = " << side_a << " b = " << side_b << " c = " << side_c << " d = " << side_d << std::endl;
		std::cout << "Angels : " << "A = " << angel_a << " B = " << angel_b << " C = " << angel_c << " D = " << angel_d << std::endl;
		std::cout << "\n";
	}
};
*/
int main()
{
	Figure figure;
	Triangle triangle(20, 30, 800, 500, 600, 700);
	Rectangle rectangle(50, 60);
	
	
	print(&triangle);
	print(&rectangle);
	/*
	RightTriangle right_triangle;
	IsoscelesTriangle isosceles_triangle;

	Quadrangle qudrangle;
	Rectangle rectangle;
	Square square;
	Parallelogram parallelogram;
	Rhombus rhombus;
	

	Triangle* ptr_triangle = &triangle;
	ptr_triangle->print_info();

	Triangle* ptr_right_triangle = &right_triangle;
	ptr_right_triangle->print_info();

	Triangle* ptr_isosceles_triangle = &isosceles_triangle;
	ptr_isosceles_triangle->print_info();

	Quadrangle* ptr_qudrangle = &qudrangle;
	ptr_qudrangle->print_info();
	
	Quadrangle* ptr_rectangle = &rectangle;
	ptr_rectangle->print_info();

	Quadrangle* ptr_square = &square;
	ptr_square->print_info();

	Quadrangle* ptr_parallelogram = &parallelogram;
	ptr_parallelogram->print_info();

	Quadrangle* ptr_rhombus = &rhombus;
	ptr_rhombus->print_info();
	*/


	return 0;
}