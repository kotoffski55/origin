#include<iostream>
#include"Triangle.h"
#include"IsoscelesTriangle.h"



IsoscelesTriangle::IsoscelesTriangle(const int& side_a, const int& side_b, const int& angel_a, const int& angel_b)
	{
		name = "IsoscelesTriangle";
		this->side_a = side_a;
		this->side_b = side_b;
		this->angel_a = angel_a;
		this->angel_b = angel_b;
		side_c = side_a;
		angel_c = angel_a;
	}
