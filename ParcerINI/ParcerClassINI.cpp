#include<iostream>
#include"ParcerClassINI.h"
#include<string>
#include <fstream>
#include<exception>
#include<filesystem>
#include<vector>

ini_parcer::ini_parcer(std::string file_name)
{
    std::ifstream in(file_name); // �������� ���� ��� ������
    if (in.is_open())
    {
        while (in.get(value))//while (std::getline(in, file_name))
        {
            if (value != ' ')// ��������� ����� �� ������� ������� !!!!!!!!!!!!!!!!!!
            {
                vec_value.push_back(value);//������� ������ ��������� ���������� �� �����  + �������� ���� � ����� ))
                                            // ����������� ����� ��� ������  ���������� ���������� � ��������  ���� �� =
            }                                // ����� ���� ��������  �� ( "\n" (������� ������)  ���  " ;  " 
        }
    }
    else
    {
        throw std::exception();
    }
    in.close();// ��������� ����
}
    
//template<class T>  
int ini_parcer::get_value(std::string section_value)
{
    int x = vec_value[5];
    return x;
}
