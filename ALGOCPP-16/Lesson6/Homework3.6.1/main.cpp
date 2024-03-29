#include<iostream>

int simple_string_hash(std::string _string)
{
	int  size = _string.size();
	int _hash = 0;
	for (int i = 0; i < size; i++)
	{
		_hash =  _hash + static_cast<int> (_string[i]);
	}
	return _hash;
}
int main()
{
	std::string string;
	do
	{
		std::cout << "Input string :";
		std::cin >> string;

		int hash = simple_string_hash(string);
		std::cout << "Naive hash of the string " << string << " = " << hash << std::endl;
		
	}
    while (string != "exit");

	return 0;
}