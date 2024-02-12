#pragma once

#include"Figure.h"

class Quadrangle :public Figure
{
protected:
	int side_a = 10;
	int side_b = 20;
	int side_c = 30;
	int side_d = 40;
	int angel_a = 50;
	int angel_b = 60;
	int angel_c = 70;
	int angel_d = 80;

public:

	Quadrangle();

	Quadrangle(const int& side_a, const int& side_b, const int& side_c, const int& side_d, const int& angel_a, const int& angel_b, const int& angel_c, const int& angel_d);
	
	void print_info() override;
	
};