#include "math_func.h"

double exp(double a, double b)

{
	double tmp = a;
	for (int i = 0; i < (b - 1); i++)
	{
		a = a * tmp;
	}
	return a;
}
double add(double a, double b)
{
	return a + b;
}
double sub(double a, double b)
{
	return a - b;
}
double mult(double a, double b)
{
	return a * b;
}
double div(double a, double b)
{
	return a / b;
}