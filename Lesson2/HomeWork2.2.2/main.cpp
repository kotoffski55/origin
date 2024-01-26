#include<iostream>
#include<string>

class Counter
{
private:

	int value;


public:
	Counter()
	{
		this->value = 1;
	}
	Counter(const int& value)
	{
		this->value = value;
	}
	void counterSum()
	{
		this->value = this->value + 1;
	}
	int counterGetValue()
	{
		return this->value;
	}
	void counterSubtraction()
	{
		this->value = this->value - 1;
	}

	void counterInAction()
	{
		do
		{
			std::cout << "Input command('+', '-', '='  or  'x') : ";
			std::cin >> choice_2;

			if (choice_2 == sum)
			{
				count.counterSum();
			}
			else if (choice_2 == subtraction)
			{
				count.counterSubtraction();
			}
			else if (choice_2 == print)
			{
				count.counterPrint();
			}
		} while (choice_2 != end);


		std::cout << "Goodbye";

	}
};


int main()
{


	std::string choice_1;
	std::string choice_2;
	std::string yes = "yes";
	std::string no = "no";
	std::string sum = "+";
	std::string subtraction = "-";
	std::string print = "=";
	std::string end = "x";
	int value;




	std::cout << "Do you want to specify the initial value of the counter? Input yes or no : ";
	std::cin >> choice_1;

	if (choice_1 == yes)
	{
		std::cout << "Input value : ";
		std::cin >> value;
		Counter count(value);
		count.counterInAction;

	else if (choice_1 == no)
	{
		Counter count;
		do
		{
			std::cout << "Input command('+', '-', '='  or  'x') : ";
			std::cin >> choice_2;

			if (choice_2 == sum)
			{
				count.counterSum();
			}
			else if (choice_2 == subtraction)
			{
				count.counterSubtraction();
			}
			else if (choice_2 == print)
			{
				std::cout << count.counterGetValue();
			}
		} while (choice_2 != end);


		std::cout << "Goodbye";
	}
	std::cout << "\n";





	return 0;
	}