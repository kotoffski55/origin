#include<iostream>
#include<string>

struct address
{
	std::string city;
	std::string street;
	int house_number;
	int aprt_number;
	int index;

};
void PrintAddress(address& a)
{
	std::cout << "City : " << a.city << std::endl;
	std::cout << "Street : " << a.street << std::endl;
	std::cout << "House number : " << a.house_number << std::endl;
	std::cout << "Apartment number : " << a.aprt_number << std::endl;
	std::cout << "Index : " << a.index << std::endl;
}

int main()
{
	address adr;
	std::cout << "Input City : ";
	std::cin >> adr.city;

	std::cout << "Input Street : ";
	std::cin >> adr.street;

	std::cout << "Input House number : ";
	std::cin >> adr.house_number;

	std::cout << "Input Apartment number : ";
	std::cin >> adr.aprt_number;

	std::cout << "Input Index : ";
	std::cin >> adr.index;

	PrintAddress(adr);

	return 0;
}