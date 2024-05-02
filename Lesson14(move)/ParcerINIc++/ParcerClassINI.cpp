#include<iostream>
#include"ParcerClassINI.h"
#include<string>
#include <fstream>

void ini_parcer::do_somefing()
{
	std::cout << "Doing something!" << std::endl;
}
ini_parcer::ini_parcer(std::string file_name)
{
    std::ifstream in(file_name); // окрываем файл для чтения
    if (in.is_open())
    {
        while (std::getline(in,file_name ))
        {
            std::cout << file_name << std::endl;
        }
    }
    in.close();     // закрываем файл
}
