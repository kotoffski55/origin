#include<iostream>
#include<vector>
#include<list>
#include<set>
template<class container>
void print_container(container begin, container end)
{
	for (auto itr = begin; itr != end; itr++)
	{
		std::cout << *itr << ", ";
	}
}
int main()
{
	std::set<std::string> test_set = { "one", "two", "three", "four" };
	print_container(test_set.begin(),test_set.end());

	std::cout << std:: endl;

	std::list<std::string> test_list = { "one", "two", "three", "four" };
	print_container(test_list.begin(), test_list.end());

	std::cout << std::endl;

	std::vector<std::string> test_vector = { "one", "two", "three", "four" };
	print_container(test_vector.begin(), test_vector.end());

	return 0;

}