#pragma once
#include<exception>
#include"Errors.h"
class Errors : public std::exception
{
public:
	const char* what() const override;
};