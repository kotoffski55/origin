#include<iostream>
#include<string>

size_t function(std::string str, int forbidden_length)
{
	std::string bad_length = "Вы ввели слово запретной длины! До свидания";
	
		if (str.length() == forbidden_length)
		{
			throw bad_length;
		}
		else
		{			
			return str.length();
		}
}
int main()
{
	system("chcp 1251");
	system("cls");
	setlocale(LC_ALL, "");
	int forbidden_length;
	std::string str;
	std::cout << "Введите запретную длину: ";
	std::cin >> forbidden_length;
	
	do
	{
		std::cout << "Введите слово: ";
		std::cin >> str;
		try
		{
			std::cout << "Длина слова " << str << " равна " << function(str, forbidden_length) << std::endl;
		}
		catch (std::string err)
		{
			std::cout << err << std::endl;
		}
	}
	while (str.length() != forbidden_length);

	return 0;
}