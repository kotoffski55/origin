#include<iostream>
// Родительский класс  треугольник  
class Triangle
{
protected:
	// защищенные поля  
	std::string name = "Triangle";

	int side_a = 10;
	int side_b = 20;
	int side_c = 30;
	
	int angel_a = 50;
	int angel_b = 60;
	int angel_c = 70;

public:

	//вывод информации  о треугольнике 
	virtual void print_info()
	{
		std::cout << name << ":" << std::endl;
		std::cout << "Sides : " << "a = " << side_a << " b = " << side_b << " c = " << side_c << std::endl;
		std::cout << "Angels : " << "A = " << angel_a << " B = " << angel_b << " C = " << angel_c << std::endl;
		std::cout << "\n";
	}

	
	//Геттеры  для  строн треугольника  
	int  getSideA()
	{
		return side_a;
	}
	int  getSideB()
	{
		return side_b;
	}
	int  getSideC()
	{
		return side_c;
	}

	int getAngelA()
	{
		return angel_a;
	}
	int getAngelB()
	{
		return angel_b;
	}
	int getAngelC()
	{
		return angel_c;
	}

	std::string getName()
	{
		return name;
	}
};

//родительский клаcc четырехугольник  
class Quadrangle 
{
protected:
	// защищенные поля  
	std::string name = "Quadrangle";

	int side_a = 10;
	int side_b = 20;
	int side_c = 30;
	int side_d = 40;

	int angel_a = 50;
	int angel_b = 60;
	int angel_c = 70;
	int angel_d = 80;

public:
	//функция вывода на консоль
	//   
	virtual void print_info() 
	{
		std::cout << name << ":" << std::endl;
		std::cout << "Sides : " << "a = " << side_a << " b = " << side_b << " c = " << side_c << " d = " << side_d << std::endl;
		std::cout << "Angels : " << "A = " << angel_a << " B = " << angel_b << " C = " << angel_c << " D = " << angel_d << std::endl;
		std::cout << "\n";
	}
	//Геттеры  для  строн треугольника  
	int  getSideA()
	{
		return side_a;
	}
	int  getSideB()
	{
		return side_b;
	}
	int  getSideC()
	{
		return side_c;
	}
	int  getSideD()
	{
		return side_d;
	}

	int getAngelA()
	{
		return angel_a;
	}
	int getAngelB()
	{
		return angel_b;
	}
	int getAngelC()
	{
		return angel_c;
	}
	int getAngelD()
	{
		return angel_d;
	}

	std::string getName()
	{
		return name;
	}
};


//Классы наследники для треугольника  

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

int main()
{
	Triangle triangle;
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


	return 0;
}