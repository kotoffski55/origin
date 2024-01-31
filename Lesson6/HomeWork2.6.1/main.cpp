#include<iostream>

#define MODE 1
#ifndef MODE
#error "You should difene MODE"
#endif // !MODE

#if MODE == 1
#define add(a , b) ((a) + (b))
#endif // MODE == 1


int main()
{

#if MODE == 0

	std::cout << "I'm working in training mode" << std::endl;

#elif MODE == 1

	std::cout << "I'm working in training mode" << std::endl;
	int num_1;
	int num_2;
	std::cout << "Input num 1: ";
	std::cin >> num_1;
	std::cout << "Input num 2: ";
	std::cin >> num_2;

	std::cout << "Sum result :"  << add(num_1, num_2);
#else

	std::cout << "Unknown mode. Shutdown" << std::endl;

#endif // MODE = 0




	return 0;
}