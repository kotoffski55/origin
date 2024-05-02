#include<iostream>
#include"ParcerClassINI.h"
#include<string>
#include <fstream>
#include<exception>
#include<filesystem>
#include<vector>

ini_parcer::ini_parcer(std::string file_name)
{
    std::ifstream in(file_name); // окрываем файл для чтения
    if (in.is_open())
    {
        while (in.get(value))//while (std::getline(in, file_name))
        {
            if (value != ' ')// Проверить нужно ли удалять пробелы !!!!!!!!!!!!!!!!!!
            {
                vec_value.push_back(value);//сделать вектор заполнить значениями из файла  + добавить поля в класс ))
                                            // фильтровать через ИЛИ полсле  начинается переменная с латиницы  идет до =
            }                                // после идет ЗНАЧЕНИЕ  до ( "\n" (перенос строки)  ИЛИ  " ;  " 
        }
    }
    else
    {
        throw std::exception();
    }
    in.close();// закрываем файл
}
    
//template<class T>  
int ini_parcer::get_value(std::string section_value)
{
    int x = vec_value[5];
    return x;
}
