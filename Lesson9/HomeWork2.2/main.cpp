#include<iostream>

#include<iostream>

class smart_array
{
private:
	int* arr;
	int count = 0;
	size_t size_;
public:

	smart_array(const smart_array&) = delete;
	smart_array& operator=(const smart_array&) = delete;

	smart_array(size_t snz)
	{
		size_ = snz;
		arr = new int[size_];
	}
	~smart_array()
	{
		delete[] arr;
	}
	void add_element(int value)
	{
		if (count > size_)
		{
			throw std::string{ "Error" };
		}
		else
			arr[count] = value;
		count++;
	}
	int  get_element(int index)
	{
		if (index < 0 && index > size_)
		{
			throw std::string{ "Error" };
		}
		return arr[index];
	}
	int get_size()
	{
		return size_;
	}
	void copy_value(int value ,int index)
	{
		arr[index] = value;
	}

};

int main()
try {
	smart_array arr(5);
	arr.add_element(1);
	arr.add_element(4);
	arr.add_element(155);

	smart_array new_array(2);
	new_array.add_element(44);
	new_array.add_element(34);
	
	
		if (arr.get_size() > new_array.get_size())
		{
			int new_size = new_array.get_size();
			for (int i = 0; i < new_size; i++)
			{
				int copy_value = new_array.get_element(i);
				new_array.copy_value(copy_value, i);
			}
		}
	}

catch (const std::exception& ex) {
	std::cout << ex.what() << std::endl;

	return 0;
}