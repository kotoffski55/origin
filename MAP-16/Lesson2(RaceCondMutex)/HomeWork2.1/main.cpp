#include<iostream>
#include<thread>
#include<atomic>

std::atomic_flag atomicFlag;
std::atomic<int> client_count;

int max_client_count;

void clientCountAdd()
{
	for (int i = 0; i <= max_client_count; i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		client_count.store(client_count + 1, std::memory_order::memory_order_relaxed);
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
	client_count.store(0, std::memory_order::memory_order_relaxed);
	std::cout << client_count.is_lock_free() << std::endl;
	std::cout << "Input maximum clients quantity : ";
	std::cin >> max_client_count;

	std::thread thread1{ clientCountAdd };
	std::thread thread2{ clientCountRedus };
	thread1.join();
	thread2.join();



	std::cout << client_count;
	return 0;
}