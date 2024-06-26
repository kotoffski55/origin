
#include <iostream>
#include <conio.h>
#include <thread>
#include <mutex>
#include <ctime>
#include <iomanip>
#include<vector>
#include<Windows.h>
#include<random>
#include<time.h>

int num_threads = 5; // Количество потоков
int calculation_length = 25; // Длина расчета
std::mutex mtx; // Мутекс для синхронизации вывода
std::vector<char> progress_bar(calculation_length);

void gotoxy()
{
    
    for (int i = 0; i < num_threads; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        COORD coord;
        coord.X = 10;
        coord.Y = i;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }
}
void progessBar(int id) 
{
   
    std::clock_t start = std::clock(); // Начало времени выполнения потока
    for (int i = 0; i < calculation_length; ++i)
    {
       
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
            // Отображение прогресс-бара
            std::lock_guard<std::mutex> lg(mtx);  
   
                progress_bar[i] = (char)219;
                std::cout << progress_bar[i];
    }
    // Завершение времени выполнения потока
    std::clock_t end = std::clock();
    double time_spent = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    // Вывод информации о завершении потока
   std::unique_lock<std::mutex> lg(mtx);
   std::cout <<  std::fixed << std::setprecision(2) << time_spent << "s" << std::endl;
}


    int main()
    {
      
        //Запуск потоков
        //std::cout << "# id    progress bar      time  " << std::endl;
        for (int i = 0; i < num_threads; ++i)
        {
            
            std::thread t(progessBar, i);
            //std::thread g(gotoxy);
            //g.join();
            std::cout << i << "  " << t.get_id();
            t.join();
    
        } 

        return 0;
    }