#include"Square.h"
#include"Rectangle.h"
Square::Square() {};

	Square::Square(const int& side_a)
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
