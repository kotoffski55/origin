#include<iostream>
#include"Triangle.h"
#include"EquilateralTriangle.h"

EquilateralTriangle::EquilateralTriangle(const int& side_a)
	{
		name = "EquilateralTriangle";
		this->side_a = side_a;
		this->angel_a = 60;
		this->angel_b = 60;
		this->angel_c = 60;
		side_c = side_a;
		side_b = side_a;
	}
