#include<iostream>
#include"math_func.h"
using namespace std;

enum Operations
{
	addition = 1,
	subtraction ,
	multiplication,
	division,
	exponentiation
};

int main()
{
	double a;
	double b;
	int oper;
	cout << "Input 1-st number : ";
	cin >> a;
	cout << "Input 2-nd number : ";
	cin >> b;

	cout << "Select the operation (1 - addition, 2 - subtraction, 3 - multiplication, 4 - division, 5 - exponentiation):";
	cin >> oper;

	if (oper == addition)
	{
		cout << a << " + " << b << " = " << add(a, b);
	}
	else if (oper == subtraction)
	{
		cout << a << " - " << b << " = " << sub(a, b);
	}
	else if (oper == multiplication)
	{
		cout << a << " * " << b << " = " << mult(a, b);
	}
	else if (oper == division)
	{
		cout << a << " / " << b << " = " << div(a, b);
	}
	else if (oper == exponentiation)
	{
		cout << a << " ^ " << b << " = " << exp(a, b);
	}
	return 0;
}