#include<iostream>
#include"ParcerClassINI.h"
#include"ParcerClassINI.cpp"
#include<string>
#include<fstream>
#include<Windows.h>


int main()

{
	SetConsoleOutputCP(CP_UTF8);
	setlocale(LC_ALL, "Russian");
	try
	{
		ini_parcer parser("test.ini");
		for (int i = 0; i < 100; i++)
		{
			//std::cout << parser.vec_value[i];
		}
		
		auto value = parser.get_value("value");
		std::cout << value;
	}
	catch(std::exception& ex)
	{
		std::cout << "Error reading from file";
	}
	
	
	//auto value = parser.get_value<int>("section.value");
	
}