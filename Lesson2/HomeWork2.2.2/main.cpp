#include<iostream>
#include<string>

class Counter
{
private:
	
	int value;

public:
	Counter (int& value ) 
	{
		this->value = value;
	}
	void counterStartValue(int value)
	{
		this->value = value;
	}
	void counterSum(int value)
	{
		this->value = this->value + 1;
	}
	void counterPrint(int value)
	{
		std::cout << this->value;
		std::cout << "\n";
	}
	void counterSubtraction(int value)
	{
		this->value = this->value - 1;
	}

};


int main()
{
	
	
	std::string choice;
	std::string yes = "yes";
	std::string no = "no";
	std::string sum = "+";
	std::string subtraction = "-";
	std::string print = "=";
	std::string end = "x";
	int value;

	Counter count(value);

	std::cout << "Do you want to specify the initial value of the counter? Input yes or no : ";
	std::cin >> choice;

	if (choice == yes)
	{
		std::cout << "Input value : ";
		std::cin >> value;
		count.counterStartValue(value);
	}
	else if (choice == no)
	{
		int value = 1;
		count.counterStartValue(value);
		
	}
	std::cout << "\n";

	

	do
	{
		std::cout << "Input command('+', '-', '='  or  'x') : ";
		std::cin >> choice;

		if (choice == sum)
		{
			count.counterSum(value);
		}
		else if (choice == subtraction)
		{
			count.counterSubtraction(value);
		}
		else if (choice == print)
		{
			count.counterPrint(value);
		}
	} 
	while (choice != end);
	
	
	std::cout << "Goodbye";

	return 0;
}