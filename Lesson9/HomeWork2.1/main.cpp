#include<iostream>
class smart_array
{
private:
	int*ptr;
	int size;
	int element;
public:
	smart_array(int size)
	{
		int* ptr = new int [size];
		for (int i = 0; i < size; i++)
		{
			ptr[i] = i;
		}
	}
	~smart_array()
	{
		delete[] ptr;
	}
	void add_element(int elements)
	{
		int* ptr = new int[size + elements];
		for (int i = 0; i < (size + elements); i++)
		{
			ptr[i] = i;
		}
	}
	int get_element(int element)
	{
		if (element >= 0) 
			for (int i = 0; i < size; i++)
			{
				if (i == element)
				{
					return element;
				}
			}
	}
 };

int main()
{
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}