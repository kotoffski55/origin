#include<iostream>
#include<thread>
#include<vector>
#include <iomanip>



void vectorSum(std::vector<int>& _v1, std::vector<int>& _v2, std::vector<int>& _sum)
{
	for (int i = 0; i < _sum.size(); i++)
	{
		
		_sum[i] = _v1[i] + _v2[i];
		//std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}
void vectorThreadPrint(std::vector <double> times , int thread_num)
{
	std::cout << thread_num << " потоков " << "  ";
	for (auto itr = times.begin(); itr != times.end(); itr++)
	{
		std::cout << *itr << "  ";
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	int cores_count = std::thread::hardware_concurrency(); //Узнаем к-во ядер
	std::cout << "Кол-во аппаратных ядер - " << cores_count << std::endl;

	std::vector<double> thread_1_times;
	std::vector<double> thread_2_times;
	std::vector<double> thread_4_times;
	std::vector<double> thread_8_times;
	std::vector<double> thread_16_times;
	
	int k = 1;
	std::cout << "           ";
	for (int i = 1; i <= 4; i++)
	{
		int size = 1000 * k;
		k = k * 10;
		std::cout.width(6);
		std::cout << size << "      ";
	}
	std::cout << std::endl;
	k = 1;
	for (int i = 1; i <= 4; i++)
	{
		int size = 1000 * k;
		k = k * 10;
		std::vector <int> v1(size);
		std::vector <int> v2(size);
		std::vector <int> sum(size);
		std::thread t1{ vectorSum, std::ref(v1), std::ref(v2), std::ref(sum) };
		auto start1 = std::chrono::steady_clock::now();
		t1.join();
		auto end1 = std::chrono::steady_clock::now();
		std::chrono::duration<double> elapsed_seconds1 = end1 - start1;
		auto t = elapsed_seconds1.count();
		thread_1_times.push_back(t);
	}
	k = 1;
	for (int i = 1; i <= 4; i++)
	{
		int size = 1000 * k;
		k = k * 10;
		std::vector <int> v1(size);
		std::vector <int> v2(size);
		std::vector <int> sum(size);
		std::thread t1{ vectorSum, std::ref(v1), std::ref(v2), std::ref(sum) };
		std::thread t2{ vectorSum, std::ref(v1), std::ref(v2), std::ref(sum) };
		auto start1 = std::chrono::steady_clock::now();
		t1.join();
		t2.join();
		auto end1 = std::chrono::steady_clock::now();
		std::chrono::duration<double> elapsed_seconds1 = end1 - start1;
		auto t = elapsed_seconds1.count();
		thread_2_times.push_back(t);
	}
	k = 1;
	for (int i = 1; i <= 4; i++)
	{
		int size = 1000 * k;
		k = k * 10;
		std::vector <int> v1(size);
		std::vector <int> v2(size);
		std::vector <int> sum(size);
		std::thread t1{ vectorSum, std::ref(v1), std::ref(v2), std::ref(sum) };
		std::thread t2{ vectorSum, std::ref(v1), std::ref(v2), std::ref(sum) };
		std::thread t3{ vectorSum, std::ref(v1), std::ref(v2), std::ref(sum) };
		std::thread t4{ vectorSum, std::ref(v1), std::ref(v2), std::ref(sum) };
		auto start1 = std::chrono::steady_clock::now();
		t1.join();
		t2.join();
		t3.join();
		t4.join();
		auto end1 = std::chrono::steady_clock::now();
		std::chrono::duration<double> elapsed_seconds1 = end1 - start1;
		auto t = elapsed_seconds1.count();
		thread_4_times.push_back(t);
	}
	k = 1;
	for (int i = 1; i <= 4; i++)
	{
		int size = 1000 * k;
		k = k * 10;
		std::vector <int> v1(size);
		std::vector <int> v2(size);
		std::vector <int> sum(size);
		std::thread t1{ vectorSum, std::ref(v1), std::ref(v2), std::ref(sum) };
		std::thread t2{ vectorSum, std::ref(v1), std::ref(v2), std::ref(sum) };
		std::thread t3{ vectorSum, std::ref(v1), std::ref(v2), std::ref(sum) };
		std::thread t4{ vectorSum, std::ref(v1), std::ref(v2), std::ref(sum) };
		std::thread t5{ vectorSum, std::ref(v1), std::ref(v2), std::ref(sum) };
		std::thread t6{ vectorSum, std::ref(v1), std::ref(v2), std::ref(sum) };
		std::thread t7{ vectorSum, std::ref(v1), std::ref(v2), std::ref(sum) };
		std::thread t8{ vectorSum, std::ref(v1), std::ref(v2), std::ref(sum) };
		auto start1 = std::chrono::steady_clock::now();
		t1.join();
		t2.join();
		t3.join();
		t4.join();
		t5.join();
		t6.join();
		t7.join();
		t8.join();
		auto end1 = std::chrono::steady_clock::now();
		std::chrono::duration<double> elapsed_seconds1 = end1 - start1;
		auto t = elapsed_seconds1.count();
		thread_16_times.push_back(t);
	}
	k = 1;
	for (int i = 1; i <= 4; i++)
	{
		int size = 1000 * k;
		k = k * 10;
		std::vector <int> v1(size);
		std::vector <int> v2(size);
		std::vector <int> sum(size);
		std::thread t1{ vectorSum, std::ref(v1), std::ref(v2), std::ref(sum) };
		std::thread t2{ vectorSum, std::ref(v1), std::ref(v2), std::ref(sum) };
		std::thread t3{ vectorSum, std::ref(v1), std::ref(v2), std::ref(sum) };
		std::thread t4{ vectorSum, std::ref(v1), std::ref(v2), std::ref(sum) };
		std::thread t5{ vectorSum, std::ref(v1), std::ref(v2), std::ref(sum) };
		std::thread t6{ vectorSum, std::ref(v1), std::ref(v2), std::ref(sum) };
		std::thread t7{ vectorSum, std::ref(v1), std::ref(v2), std::ref(sum) };
		std::thread t8{ vectorSum, std::ref(v1), std::ref(v2), std::ref(sum) };
		std::thread t9{ vectorSum, std::ref(v1), std::ref(v2), std::ref(sum) };
		std::thread t10{ vectorSum, std::ref(v1), std::ref(v2), std::ref(sum) };
		std::thread t11{ vectorSum, std::ref(v1), std::ref(v2), std::ref(sum) };
		std::thread t12{ vectorSum, std::ref(v1), std::ref(v2), std::ref(sum) };
		std::thread t13{ vectorSum, std::ref(v1), std::ref(v2), std::ref(sum) };
		std::thread t14{ vectorSum, std::ref(v1), std::ref(v2), std::ref(sum) };
		std::thread t15{ vectorSum, std::ref(v1), std::ref(v2), std::ref(sum) };
		std::thread t16{ vectorSum, std::ref(v1), std::ref(v2), std::ref(sum) };
		auto start1 = std::chrono::steady_clock::now();
		t1.join();
		t2.join();
		t3.join();
		t4.join();
		t5.join();
		t6.join();
		t7.join();
		t8.join();
		t9.join();
		t10.join();
		t11.join();
		t12.join();
		t13.join();
		t14.join();
		t15.join();
		t16.join();
		auto end1 = std::chrono::steady_clock::now();
		std::chrono::duration<double> elapsed_seconds1 = end1 - start1;
		auto t = elapsed_seconds1.count();
		thread_8_times.push_back(t);
	}
	vectorThreadPrint(thread_1_times, 1);
	std::cout << std::endl;
	vectorThreadPrint(thread_2_times, 2);
	std::cout << std::endl;
	vectorThreadPrint(thread_4_times, 4);
	std::cout << std::endl;
	vectorThreadPrint(thread_8_times, 8);
	std::cout << std::endl;
	vectorThreadPrint(thread_16_times, 16);
	std::cout << std::endl;

	return 0;
}