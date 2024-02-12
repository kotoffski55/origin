#include<iostream>
#include"Triangle.h"
#include"RightTriangle.h"

RightTriangle::RightTriangle(const int& side_a, const int& side_b, const int& side_c, const int& angel_a, const int& angel_b)
	{
		name = "Right triangle";
		this->side_a = side_a;
		this->side_b = side_b;
		this->side_c = side_c;
		this->angel_a = angel_a;
		this->angel_b = angel_b;
		this->angel_c = 90;
	}
