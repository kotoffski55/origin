#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

class big_integer
{
public:
	
	 std:: vector<int> value ;
	 int size;
public:
	big_integer() {};

	big_integer(std::string _value)
	{
		size = _value.length();
		
		for (int i = 0; i < size; i++)
		{
			int int_value = _value[i] - '0';
			value.push_back(int_value);
		}
	}
	big_integer(big_integer&& moved)
	{
			size = moved.size;
			value = moved.value;
	}
	big_integer& operator=(big_integer&& moved)
	{
		if (this != &moved)
		{
			size = moved.size;
			value = moved.value;
		}
		
		return *this;
	}
	~big_integer()
	{

	}
	big_integer operator+(big_integer& other)
	{
		//big_integer result;
		std::reverse(value.begin(), value.end());
		std::reverse(other.value.begin(), other.value.end());
		
		int carry = 0;
		
		//for ( auto i = std::max(value.size(),other.value.size()) -1; i >= 0; i--)
		//{
			//auto value_x = i > value.size() ? value[i] :
			
			//result.value.push_back(value_x + other_y);
		//}
		return this;
	}
	
};
int main()
{
	auto number1 = big_integer("143");
    auto number2 = big_integer("78524");
	auto result = number1 + number2;
	for (auto itr = number1.value.begin(); itr < number1.value.end(); itr++)
	{
		std::cout << *itr;
	}
	return 0;
}