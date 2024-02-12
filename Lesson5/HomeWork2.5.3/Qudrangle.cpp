#include<iostream>
#include"Figure.h"
#include"Quadrangle.h"



Quadrangle::Quadrangle() {};

Quadrangle::Quadrangle(const int& side_a, const int& side_b, const int& side_c, const int& side_d, const int& angel_a, const int& angel_b, const int& angel_c, const int& angel_d)
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
	
	void Quadrangle::print_info()
	{
		std::cout << name << ":" << std::endl;
		std::cout << "Sides : " << "a = " << side_a << " b = " << side_b << " c = " << side_c << " d = " << side_d << std::endl;
		std::cout << "Angels : " << "A = " << angel_a << " B = " << angel_b << " C = " << angel_c << " D = " << angel_d << std::endl;
		std::cout << "\n";
	}
