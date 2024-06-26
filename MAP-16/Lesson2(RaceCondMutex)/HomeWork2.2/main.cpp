
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

int num_threads = 5; // ���������� �������
int calculation_length = 25; // ����� �������
std::mutex mtx; // ������ ��� ������������� ������
std::mutex mtx2; // ������ ��� ������������� ��������� �������
std::vector<char> progress_bar(calculation_length);

void gotoxy()
{
    
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    for (int i = 0; i < num_threads; i++)
    { 
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::lock_guard<std::mutex> lg2(mtx2);
        COORD coord;
        coord.X = 10;
        coord.Y = i;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }
}
void progresBar() 
{
   
    std::clock_t start = std::clock(); // ������ ������� ���������� ������
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    for (int i = 0; i < calculation_length; ++i)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::lock_guard<std::mutex> lg(mtx);
            // ����������� ��������-����
        progress_bar[i] = (char)219;
        std::cout << progress_bar[i];
        std::lock_guard<std::mutex> lg2(mtx2);
                
    }
    
    // ���������� ������� ���������� ������
    std::clock_t end = std::clock();
    double time_spent = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    // ����� ���������� � ���������� ������
   std::lock_guard<std::mutex> lg(mtx);
   std::cout <<  std::fixed << std::setprecision(2) << time_spent << "s" << std::endl;
}


    int main()
    {
      
        //������ �������
        //std::cout << "# id    progress bar      time  " << std::endl;
        for (int i = 0; i < num_threads; ++i)
        {
            std::thread t(progresBar);
            std::thread g(gotoxy);
            g.join();
            std::cout << i << "  " << t.get_id();
            t.join();
    
        } 
 
        return 0;
    }
