#include<iostream>
#include<string>

enum class months
{
	january = 1,
	february,
	march,
	april,
	may,
	june,
	jule,
	august,
	september,
	october,
	november,
	december
};

int main()
{



	int month_num;

	do
	{


		std::cout << "Input month's number : ";

		std::cin >> month_num;
		if (month_num == 0)
		{
			std::cout << "Goodbye";
			break;
		}

		switch (month_num)
		{
		case static_cast<int>(months::january):

			std::cout << "January";

			break;

		case static_cast<int>(months::february):

			std::cout << "February";

			break;

		case static_cast<int>(months::march):

			std::cout << "March";

			break;

		case static_cast<int>(months::april):

			std::cout << "April";

			break;

		case static_cast<int>(months::may):

			std::cout << "May";

			break;

		case static_cast<int>(months::june):

			std::cout << "June";

			break;

		case static_cast<int>(months::jule):

			std::cout << "Jule";

			break;

		case static_cast<int>(months::august):

			std::cout << "August";

			break;

		case static_cast<int>(months::september):

			std::cout << "September";

			break;

		case static_cast<int>(months::october):

			std::cout << "October";

			break;

		case static_cast<int>(months::november):

			std::cout << "November";

			break;

		case static_cast<int>(months::december):

			std::cout << "December";

			break;

		default:

			std::cout << "Wrong number";

		}
		std::cout << "\n";
	} while (month_num != 0);

	return 0;
}