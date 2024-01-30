#include<iostream>
#include<string>
#include<fstream>

class Address
{
private:
	std::string city;
	std::string street;
	int house_number = 0;
	int appart_number = 0;

public:

	Address() {};

	Address(const std::string& city, const std::string& street, const int& house_number, const int& appart_number)
	{
		this->city = city;
		this->street = street;
		this->house_number = house_number;
		this->appart_number = appart_number;
	}
	std::string getOutPutAddress()
	{
		std::string out_put_address = city + "," + street + "," + std::to_string(house_number) + "," + std::to_string(appart_number);
		return out_put_address;
	}
	std::string getCity()
	{
		return city;
	}

};


int main()

{

	std::string city;
	std::string street;
	int house_number;
	int appart_number;
	int number_of_addresses;
	Address address(city, street, house_number, appart_number);


	std::ifstream fin("in.txt");

	fin >> number_of_addresses;

	std::ofstream fout("out.txt");

	fout << number_of_addresses << "\n";

	Address* address_array = new Address[number_of_addresses];

	for (int i = 0; number_of_addresses > i; i++)
	{
		fin >> city;
		fin >> street;
		fin >> house_number;
		fin >> appart_number;
		address_array[i] = Address(city, street, house_number, appart_number);

	}

	for (int i = 0; i < number_of_addresses - 1; i++)
	{
		for (int j = 0; j < number_of_addresses - i - 1; j++)
		{
			if (address_array[j].getCity() > address_array[j + 1].getCity())
			{
				std::swap(address_array[j], address_array[j + 1]);
			}

		}

	}


	for (int i = 0; i < number_of_addresses; i++)
	{
		fout << address_array[i].getOutPutAddress() << "\n";
	}


	delete[] address_array;
	fin.close();
	fout.close();


	return 0;
}