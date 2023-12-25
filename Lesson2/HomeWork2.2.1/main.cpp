#include<iostream>
#include<string>

class Calculator
{
private:

	double num1;
	double num2;

public:
	Calculator(double& num1, double& num2)
	{
		this->num1 = num1;
		this->num2 = num2;
	};
	bool  set_num1(double num1)
	{
		if (num1 != 0)
		{
			this->num1 = num1;
			return true;
		}
		else
		{
			return false;
		}
	}
	bool  set_num2(double num2)
	{
		if (num2 != 0)
		{
			this->num2 = num2;
			return true;
		}
		else
			return false;
	}

	double add(double num1, double num2)
	{
		return num1 + num2;
	}
	double multiply(double num1, double num2)
	{
		return num1 * num2;
	}
	double subtract_1_2(double num1, double num2)
	{
		return num1 - num2;
	}
	double subtract_2_1(double num1, double num2)
	{
		return num2 - num1;
	}
	double divide_1_2(double num1, double num2)
	{
		return num1 / num2;
	}
	double divide_2_1(double num1, double num2)
	{
		return num2 / num1;
	}
};

	int main()
	{
		double num1;
		double num2;

		Calculator cal(num1, num2);

		std::cout << "Input num1 : ";
		std::cin >> num1;

		while (!(cal.set_num1(num1)))
		{
			std::cout << "Wrong input ! \n";
			std::cout << "Input num1 : ";
			std::cin >> num1;
		}

		std::cout << "Input num2 : ";
		std::cin >> num2;

		while (!(cal.set_num2(num2)))
		{
			std::cout << "Wrong input ! \n";
			std::cout << "Input num2 : ";
			std::cin >> num2;
		}

		std::cout << "num1 + num2  = " << cal.add(num1, num2) << std::endl;
		std::cout << "num1 * num2  = " << cal.multiply(num1, num2) << std::endl;
		std::cout << "num1 - num2  = " << cal.subtract_1_2(num1, num2) << std::endl;
		std::cout << "num2 - num1  = " << cal.subtract_2_1(num1, num2) << std::endl;
		std::cout << "num1 / num2  = " << cal.divide_1_2(num1, num2) << std::endl;
		std::cout << "num2 / num1  = " << cal.divide_2_1(num1, num2) << std::endl;


		return 0;
	}
