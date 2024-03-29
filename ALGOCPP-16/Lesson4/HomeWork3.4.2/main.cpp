#include<iostream>
int *append_to_dynamic_array(int &new_item, int &logical_size, int &actual_size, int* arr)
{
	if (new_item == 0)
	{
		return arr;
	}
	arr[actual_size] = new_item;
	actual_size++;
	if (actual_size == logical_size)
	{
		logical_size = logical_size * 2;
		int* new_arr = new int[logical_size];
		for (int i = 0; i < actual_size; i++)
		{
			new_arr[i] = arr[i];
		}
		return new_arr;
		delete[] arr;
	}
	else
	{
		return arr;
	}

}

void print_dynamic_array(int* arr, int  &logical_size, int &actual_size)
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
	int new_item = 0 ;
	std::cout << "Enter actual array size: ";
	std::cin >> actual_size;
	std::cout << "Enter logical array size:  ";
	std::cin >> logical_size;
	std::cout << std::endl;

	int* arr = new int[logical_size];
	
	if (actual_size > logical_size)
	{
		std::cout << "Error! The logical size of the array cannot exceed the actual size!";
	}
	else
	{
		for (int i = 0; i < actual_size; i++)
		{
			std::cout << "Input arr [" << i << "]:";
			std::cin >> arr[i];
		}
		std::cout << std::endl;

		print_dynamic_array(arr, logical_size, actual_size);

		std::cout << std::endl;
	}

	std::cout << "Enter the item to add: ";
	std::cin >> new_item;

	while (new_item != 0)
	{
		append_to_dynamic_array(new_item, logical_size, actual_size, arr);
		std::cout << "Enter the item to add: ";
		std::cin >> new_item;
	}
	
	

	int* new_arr_ptr = append_to_dynamic_array(new_item, logical_size, actual_size, arr);
	std::cout << "Thank you!";
	print_dynamic_array(new_arr_ptr, logical_size, actual_size);
	
	
	delete[] new_arr_ptr;
	

	return 0;
}