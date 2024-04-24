#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

class big_integer
{
private:

	std::vector<int> value;
   
public:
	big_integer() {};

	big_integer& operator=(big_integer&& other) noexcept
	{
		{
			value = std::move(other.value);
		}

		return *this;
	}

	big_integer(std::string _value)
	{
		int size = _value.length();

		for (int i = 0; i < size; i++)
		{
			int int_value = _value[i] - '0';
			value.push_back(int_value);
		}
	}
	big_integer(big_integer&& other) noexcept
	{
		{
			value = std::move(other.value);
		}
	}
	
	~big_integer()
	{

	}
	big_integer operator+(big_integer& other)
	{
		big_integer result;
		std::reverse(value.begin(), value.end());
		std::reverse(other.value.begin(), other.value.end());

		int carry = 0;

		for (auto i = 0; i <  std::max(value.size(), other.value.size()); i++)
		{
			auto value_x = i >= value.size() ? 0 : value[i];
			auto other_x = i >= other.value.size() ? 0 : other.value[i];
			auto sum = value_x + other_x + carry;
			if (sum >= 10)
			{
				sum = sum - 10;
				carry = 1;
			}
			else
			{
				carry = 0;
			}
			result.value.push_back(sum);
		}
	   std::reverse(result.value.begin(), result.value.end());
	   return result;
	}
	void print_value()
	{
		for (auto itr = value.begin(); itr != value.end(); itr++)
		{
			std::cout << *itr;
		}
	}
	

};
int main()	
{
	auto number1 = big_integer("143");
	auto number2 = big_integer("78529");
	auto result = number1 + number2;
	result.print_value();
	
	return 0;
}