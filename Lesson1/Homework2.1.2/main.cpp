#include<iostream>
#include<string>
#include<tuple>


struct bankAccoutData
{
	int accout_num{ 0 };
	std::string accout_owener_name;
	double account_ballance{ 0 };
};

void changebankAccoutData(bankAccoutData& n, double new_b)
{
	n.account_ballance = new_b;
}

int main()
{
	double new_ballance;

	bankAccoutData acc;

	std::cout << "Input accout number : \n";
	std::cin >> acc.accout_num;

	std::cout << "Input owener name : \n";
	std::cin >> acc.accout_owener_name;

	std::cout << "Input accout ballance : \n";
	std::cin >> acc.account_ballance;

	std::cout << "Input new accout ballance : \n";
	std::cin >> new_ballance;

	changebankAccoutData(acc, new_ballance);

	std::cout << "Your accout : " << acc.accout_owener_name << " , " << acc.accout_num << " , " << acc.account_ballance;

return 0;
}