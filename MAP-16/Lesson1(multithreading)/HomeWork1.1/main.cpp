#include<iostream>
#include<thread>
int client_count = 0;
int max_client_count;

void clientCountAdd()
{
	for (int i = 0; i <= max_client_count; i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		client_count++;
		std::cout << client_count << std::endl;
	}
	
	
}
void clientCountRedus()
{
	for (int i = 0; i <= max_client_count; i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		client_count--;
		std::cout << client_count << std::endl;
	}
}
	
int main()
{
	std::cout << "Input maximum clients quantity : ";
	std::cin >> max_client_count;
	
		std::thread thread1{ clientCountAdd };
		std::thread thread2{ clientCountRedus };
		thread1.join();
		thread2.join();
	


	std::cout << client_count;
	return 0;
}