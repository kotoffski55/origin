#include"Parallelogram.h"
#include"Rectangle.h"

Parallelogram::Parallelogram(const int& side_a, const int& side_b, const int& angel_a, const int& angel_b)
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
