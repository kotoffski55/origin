#include<iostream>
#include"Triangle.h"
#include"Figure.h"
#include"Errors.h"



Triangle::Triangle() {}

void Triangle::print_info()
{
	std::cout << name << ":" << std::endl;
	std::cout << "Sides : " << "a = " << side_a << " b = " << side_b << " c = " << side_c << std::endl;
	std::cout << "Angels : " << "A = " << angel_a << " B = " << angel_b << " C = " << angel_c << std::endl;
	std::cout << "\n";
}

Triangle::Triangle(const int& side_a, const int& side_b, const int& side_c, const int& angel_a, const int& angel_b, const int& angel_c)
{
	if ((angel_a + angel_b + angel_c) != 180) throw Errors("Error creating figure. Reason: large angles are not equal to 180");
	name = "Triangle";
	this->side_a = side_a;
	this->side_b = side_b;
	this->side_c = side_c;
	this->angel_a = angel_a;
	this->angel_b = angel_b;
	this->angel_c = angel_c;
		
}
