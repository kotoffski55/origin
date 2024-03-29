#include<iostream>


int fibo(int n)
{
	if (n < 2)
		return n;
	else
		return fibo(n - 1) + fibo(n - 2);
}
int main()
{
	int num;
	std::cout << "Input fibo number : ";
	std::cin >> num;
	std::cout << fibo(num);
	return 0;
}