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


	return 0;
}