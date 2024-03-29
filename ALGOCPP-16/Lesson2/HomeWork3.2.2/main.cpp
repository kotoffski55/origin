#include<iostream>
int cache[100] = { 0 };

int fibo(int n)
{
	if (n < 2)
	{
		return n;
	}
	else if (cache[n] != 0)
	{
		return cache[n];
	}
	else
	{
		cache[n] = fibo(n - 1) + fibo(n - 2);
		
	}
	return cache[n];
}
int main()
{
	int num;
	std::cout << "Input fibo number : ";
	std::cin >> num;
	std::cout << fibo(num);
	return 0;
}