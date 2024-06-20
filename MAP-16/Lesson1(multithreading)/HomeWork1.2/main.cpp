#include<iostream>
#include<thread>
#include<vector>
#include <iomanip>

/*auto start = std::chrono::steady_clock::now();
do_something();
auto end = std::chrono::steady_clock::now();
std::chrono::duration<double> elapsed_seconds = end - start;
std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
*/
void vectorSum(std::vector<int>& _v1, std::vector<int>& _v2 ,std::vector<int>& _sum)
{
	for (int i = 0; i < _sum.size(); i++)
	{
		_sum[i] = _v1[i] + _v2[i];
	}
}
int main()
{
	int size = 1000;
	std::vector <int> v1(size);
	std::vector <int> v2(size);
	std::vector <int> sum(size);

	setlocale(LC_ALL, "RUS");

	int cores_count = std::thread::hardware_concurrency(); //Узнаем к-во ядер
	std::cout << "Кол-во аппаратных ядер - " << cores_count << std::endl;

	/*
	auto start = std::chrono::steady_clock::now();
	vectorSum(v1, v2, sum);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout <<" потоков " << std::fixed << std::setprecision(6) << elapsed_seconds.count() << "s\n";
	*/
	
	std::thread t1{vectorSum, v1, v2, sum };
	t1.join();
	

	return 0;
}