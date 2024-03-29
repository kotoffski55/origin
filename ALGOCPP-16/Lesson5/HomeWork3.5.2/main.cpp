#include<iostream>

void print_pyramid(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i == 0)
		{
			std::cout << int(std::log2(i + 1)) << " root " << arr[i] << std::endl;
		}
		else if (i % 2 != 0)
		{
			std::cout << int(std::log2(i + 1)) << " left (" << arr[(i - 1) / 2] << ")" << arr[i] << std::endl;
		}
		else
		{
			std::cout << int(std::log2(i + 1)) << " right (" << arr[(i - 1) / 2] << ")" << arr[i] << std::endl;
		}
	}
}


int main()
{
	static const int size = 6;
	int arr[size] = { 1 ,3, 6, 5, 9, 8 };
	print_pyramid(arr, size);
	std::string command;
	std::cout << "You are here : "  << int(std::log2(1)) << " root " << arr[0] << std::endl;
	
	int i = 0;
	while (command != "exit")
	{
		std::cout << "Enter the command :";
		std::cin >> command;
		
		if (command == "right")
		{
			i = 2 * i + 2;
			if (i  < size)
			{
				std::cout << "OK" << std::endl;
				std::cout << "You are here : " << int(std::log2(i + 1)) << " right (" << arr[(i - 1) / 2] << ")" << arr[i] << std::endl;
			}
			else
			{
				i = (i - 1) / 2;
				std::cout << "Error! Right child is missing" << std::endl;	
				std::cout << "You are here : " << int(std::log2(i + 1)) << " right (" << arr[(i - 1) / 2] << ")" << arr[i] << std::endl;
			}
		}
		if (command == "left")
		{
			i = 2 * i + 1;
			if (i < size)
			{
				std::cout << "OK" << std::endl;
				std::cout << "You are here : " << int(std::log2(i + 1)) << " right (" << arr[(i - 1) / 2] << ")" << arr[i] << std::endl;
			}
			else 
			{
				i = (i - 1) / 2;
				std::cout << "Error! Left  child is missing" << std::endl;
				std::cout << "You are here : " << int(std::log2(i + 1)) << " left (" << arr[(i - 1) / 2] << ")" << arr[i] << std::endl;
			}
		}
		if (command == "up")
		{
			if (i == 0)
			{
				std::cout << "Error! Missing parent" << std::endl;
				std::cout << "You are here : " << int(std::log2(i + 1)) << " root " << arr[i] << std::endl;
			}
			else
			{
				i = (i - 1) / 2;
				std::cout << "OK" << std::endl;
				std::cout << "You are here : " << int(std::log2(i + 1)) << " right (" << arr[(i - 1) / 2] << ")" << arr[i] << std::endl;
			}
		}
	}

	return 0;
}