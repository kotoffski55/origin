#include<iostream>
#include<cmath>

int real_string_hash(std::string _string ,int _p, int _n)
{
	int  size = _string.size();
	int _hash = 0;
	
	for (int i = 0; i < size; i++)
	{
		
		_hash = _hash + static_cast<int> (_string[i]) * pow(_p, i);
	}
	return _hash % _n;
}
int main()
{
	std::string string;
	int p ;
	int n ;
	std::cout << "Input p:";
	std::cin >> p;
	std::cout <<  "Input n :";
	std::cin >> n;
	do
	{
		std::cout << "Input string :";
		std::cin >> string;

		int hash = real_string_hash(string , p, n);
		std::cout << "Hash of the string " << string << " = " << hash << std::endl;

	} while (string != "exit");

	return 0;
}