#include<iostream>
#include"Triangle.h"
#include"Figure.h"



	Triangle::Triangle() {}

	Triangle::Triangle(const int& side_a, const int& side_b, const int& side_c, const int& angel_a, const int& angel_b, const int& angel_c)
	{
		name = "Triangle";
		this->side_a = side_a;
		this->side_b = side_b;
		this->side_c = side_c;
		this->angel_a = angel_a;
		this->angel_b = angel_b;
		this->angel_c = angel_c;
	}
	void Triangle::print_info()
	{
		std::cout << name << ":" << std::endl;
		std::cout << "Sides : " << "a = " << side_a << " b = " << side_b << " c = " << side_c << std::endl;
		std::cout << "Angels : " << "A = " << angel_a << " B = " << angel_b << " C = " << angel_c << std::endl;
		std::cout << "\n";
	}