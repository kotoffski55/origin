#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<map>

class ini_parcer
{
private:
	//std::vector<char> all_symbol_from_file;
	std::string all_symbol_from_file;
	char symbol;
	std::multimap<std::string, std::pair<std::string, std::string>> sections_and_values;
public: 
	ini_parcer(std::string file_name);
    //std::multimap<std::string, std::pair<std::string, std::string>> sections_and_values;
	char get_value(int index);// доделать шаблон см. вебинар
	int get_size();

};

