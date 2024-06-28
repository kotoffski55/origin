#include<iostream>
#include<mutex>
#include<vector>
#include <algorithm>
#include <thread>
#include <future>
void selectionSortAsync(std::vector<int>& vec) {
	for (size_t i = 0; i < vec.size(); ++i) {
		std::promise<size_t> promise;
		std::future<size_t> future = promise.get_future();

		std::thread([&vec, i, &promise]() 
			{
			size_t min = i;
			for (size_t j = i + 1; j < vec.size(); ++j) {
				if (vec[j] < vec[min]) {
					min = j;
				}
			}
			promise.set_value(min);
			}).join();

			size_t actualMin = future.get();

			if (i != actualMin) {
				std::swap(vec[i], vec[actualMin]);
			}
	}
}
void selectionSort(std::vector<int> &vec )
{
	int min = 0;
	
	for (int i = 0; i < vec.size(); i++)
	{
		min = i; 
		for (int j = i + 1; j < vec.size(); j++)
			min = (vec[j] < vec[min]) ? j : min;
		
		if (i != min)
		{
			std::swap(vec[i], vec[min]);
		}
	}

}
void fillArray(std::vector<int> &vec, int _size)
{
	for (int i = 0; i < _size ; i++)
	{
		int value = rand() % 100;
		
		vec.push_back(value);
	}
}
void printArray(std::vector<int> &vec)
{
	for (auto itr = vec.begin(); itr != vec.end(); itr++)
	{
		std::cout << *itr << " ";
	}
}
int main()
{
	int size = 0;
	std::cout << "Input array size : ";
	std::cin >> size;

	std::vector<int> vec;
	fillArray(vec , size);
	//selectionSort(vec);
	selectionSortAsync(vec);
	printArray(vec);

	return 0;
}