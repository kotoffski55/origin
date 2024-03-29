#include<iostream>
void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
	std::cout << "Dynamic array: ";
	for (int i = 0; i < actual_size; i++)
	{
		std::cout << arr[i] << " ";
	}
	for (int i = 0; i < (logical_size - actual_size); i++)
	{
	std::cout << " _ ";
	}

}


int main()
{
	int actual_size = 0;
	int logical_size = 0;
	std::cout << "Enter actual array size: ";
	std::cin >> actual_size;
	std::cout << "Enter logical array size:  ";
    std::cin >> logical_size;
	std::cout << std::endl;

	if (actual_size > logical_size)
	{
		std::cout << "Error! The logical size of the array cannot exceed the actual size!";
	}
	else
	{
		int* arr = new int[logical_size];
		for (int i = 0; i < actual_size ; i++)
		{
			std::cout << "Input arr [" << i << "]:";
			std::cin >> arr[i];
		}
		std::cout << std::endl;
		print_dynamic_array(arr, logical_size, actual_size);
		delete[] arr;
	}
	

	return 0;
}