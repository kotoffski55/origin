#pragma once
#include<iostream>
#include<string>
#include<string>
#include<vector>

class ini_parcer
{
private:
	std::vector<char> vec_value;
	char value;
	
public: 
	ini_parcer(std::string file_name);
	int get_value(std::string section_value);// доделать шаблон см. вебинар
	
};

