#include<iostream>
#include<mutex>

class Data
{
public:
	int value;
	std::mutex mutex;

};

void swap_with_lock(Data& a, Data& b) 
{
    std::lock(a.mutex, b.mutex); 
    std::lock_guard<std::mutex> lock1(a.mutex, std::adopt_lock);
    std::lock_guard<std::mutex> lock2(b.mutex, std::adopt_lock);

    std::swap(a.value, b.value);
}
void swap_with_scoped_lock(Data& a, Data& b)
{
    //std::scoped_lock locks(a.mutex, b.mutex);
    std::swap(a.value, b.value); 
}


void swap_with_unique_lock(Data& a, Data& b) {
    std::unique_lock<std::mutex> lock1(a.mutex, std::defer_lock);
    std::unique_lock<std::mutex> lock2(b.mutex, std::defer_lock);
    std::lock(lock1, lock2); 

    std::swap(a.value, b.value);
}

int main()
{
    Data a, b;

    // Заполнение данных
    a.value = 10;
    b.value = 20;

    // Вывод значений перед обменом
    std::cout << "Before swap: a=" << a.value << ", b=" << b.value << std::endl;

    
    swap_with_lock(a, b);
    //swap_with_scoped_lock(a, b);
    swap_with_unique_lock(a, b);

    // Вывод значений после обмена
    std::cout << "After swap: a=" << a.value << ", b=" << b.value << std::endl;

    return 0;
}