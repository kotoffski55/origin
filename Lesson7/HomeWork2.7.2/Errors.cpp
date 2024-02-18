#include <exception>
#include"Errors.h"
const char* Errors::what() const
{
	return "Error creating figure.Reason: sum of angles does not equal 180";
};