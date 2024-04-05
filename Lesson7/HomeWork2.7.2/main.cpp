#include<iostream>
#include <exception>
#include"Triangle.h"
#include"Figure.h"
#include"Errors.h"
#include"RightTriangle.h"
//#include"IsoscelesTriangle.h"
//#include"EquilateralTriangle.h"
//#include"Quadrangle.h"
//#include"Rectangle.h"
//#include"Square.h"
//#include"Parallelogram.h"
//#include"Rhombus.h"

void print(Figure* figure)
{
	figure->print_info();
}


int main()
{
	
	try
	{
		 RightTriangle right_triangle(5, 10, 15, 30, 40);
		 print(&right_triangle);
		 Triangle triangle(20, 30, 800, 60, 80, 50);
		 print(&triangle);
	}
	catch (Errors err)
	{
		std::cout << err.what();
	}
	
	
	
	
Triangle triangle(20, 30, 800, 60, 80, 50);
	//RightTriangle right_triangle(5, 10, 15, 20, 30);
	//IsoscelesTriangle isosceles_triangle(25, 30, 100, 70);
	//EquilateralTriangle equilateral_triangle(125);
	//Rectangle rectangle(50, 60);
	//Quadrangle quadrangle(41, 42, 43, 44, 45, 46, 47, 48);
	//Square square(555);
	//Parallelogram parallelogram(51, 52, 53, 54);
	//Rhombus rhombus(75, 123, 124);

	
	//print(&isosceles_triangle);
	//print(&equilateral_triangle);
	//print(&quadrangle);
	//print(&rectangle);
	//print(&square);
	//print(&parallelogram);
	//print(&rhombus);
	return 0;
}