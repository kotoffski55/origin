#pragma once
#include<exception>
#include<iostream>
class Errors : public std::exception
{
private:
    std::string err;

public:
    Errors(std::string _err);
   
    virtual const char* what();
};