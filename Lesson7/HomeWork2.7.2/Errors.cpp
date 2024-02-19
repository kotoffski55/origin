#include <exception>
#include"Errors.h"
#include<iostream>

Errors::Errors(std::string _err) : err(_err){}

const char* Errors:: what()
{
	return err.c_str();
}