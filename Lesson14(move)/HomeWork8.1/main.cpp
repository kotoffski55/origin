#include<iostream>
#include<vector>

template<class T>
void move_vectors(std::vector<T>& vec_one, std::vector<T>& vec_two)
{	
	vec_two = std::move(vec_one);
}
template<class vector>
void print_vector(vector b, vector e)
{
	for (auto itr = b; itr != e;itr++)
	{
		std::cout << *itr << " ";
	}
}


int main()
{
	std::vector <std::string> one = { "test_string1", "test_string2" };
	std::vector <std::string> two;
	move_vectors(one, two);
	print_vector(one.begin(), one.end());
	print_vector(two.begin(), two.end());
	return 0;
}