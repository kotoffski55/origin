#include<iostream>
#include"ParcerClassINI.h"
#include<string>
#include <fstream>
#include<exception>
#include<filesystem>
#include<vector>
#include<map>
#include<cctype>
ini_parcer::ini_parcer(std::string file_name)
{
    std::ifstream in(file_name); // окрываем файл для чтения
    if (in.is_open())
    {
        while (in.get(symbol))//while (std::getline(in, file_name))
        {
            all_symbol_from_file.push_back(symbol);

            //сделать вектор заполнить значениями из файла  + добавить поля в класс ))
            // фильтровать через ИЛИ полсле  начинается переменная с латиницы  идет до =
           // после идет ЗНАЧЕНИЕ  до ( "\n" (перенос строки)  ИЛИ  " ;  " 
        }
    }
    else
    {
        throw std::exception();
    }
    in.close();// закрываем файл
        
    // заполняем Multimap (контейнер) значения ми из строки(файла) (КЛЮЧ - ЗНАЧЕНЕ  .где КЛЮЧ - Section ,
    //  ЗНАЧЕНИЕ - пара (имя переменной  , значение ) !!!!!!!!!!!!!!!!!!!!!!!
       
        int pos_begin_section = 0;
        for (int i = 0; i < all_symbol_from_file.size(); i++)
        {
          
            if (all_symbol_from_file[i] == ';' )
            {
                while (all_symbol_from_file[i] != '\n')
                {
                    if ((i == all_symbol_from_file.size())) { break; }
                    i++;
                }
            }
            int count_section_symbol = 0;
            if (all_symbol_from_file[i] == '[')
            {
                pos_begin_section = i + 1;
                while (all_symbol_from_file[i] != ']')
                {
                    count_section_symbol++;
                    i++;
                }
                std::string key_section = all_symbol_from_file.substr(pos_begin_section, count_section_symbol - 1);
                std::cout << key_section << std::endl;

                std::pair<std::string, std::string> pair = {};//добработать заполнение пары  имя пременной - значение.                                           
                sections_and_values.insert({ key_section , pair });
            }
            int pos_begin_var_name = 0;
            int count_var_name_symbol = 0;
            if ((std::isalpha(all_symbol_from_file[i]) != 0))
            {
                pos_begin_var_name = i;
                while (all_symbol_from_file[i] != '=')
                {
                    count_var_name_symbol++;
                    i++;
                }
                std::string var_name = all_symbol_from_file.substr(pos_begin_var_name, count_var_name_symbol);
                std::cout << var_name <<  ":";
            }
            int pos_begin_var_value = 0;
            int count_var_value = 0;
            if (all_symbol_from_file[i] == '=')
            {
                int pos_begin_var_value = i + 1;
                while ((all_symbol_from_file[i] != '\n') && (all_symbol_from_file[i] != ';'))
                {
                    count_var_value++;
                    i++;
                }
                std::string var_value = all_symbol_from_file.substr(pos_begin_var_value, count_var_value - 1);
                std::cout << var_value << std::endl;
            }
        }
        
        

}
    
//template<class T>  
char ini_parcer::get_value(int index)
{
    char  x = all_symbol_from_file[index];
    return x;
}
int ini_parcer::get_size()
{
    return all_symbol_from_file.size();
}
