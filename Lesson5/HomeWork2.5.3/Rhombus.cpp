#include"Square.h"
#include"Rhombus.h"


	Rhombus::Rhombus(const int& side_a, const int& angel_a, const int& angel_b)
	{
		name = "Rhombus";
		this->side_a = side_a;
		side_c = side_a;
		side_b = side_a;
		side_d = side_a;

		this->angel_a = angel_a;
		this->angel_b = angel_b;
		angel_c = angel_a;
		angel_d = angel_b;
	}
