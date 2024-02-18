#include<iostream>

const int size = 9;
int arr[size] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };

int NumdersOfValue(int arr[], int x)
{
	int left = 0;
	int right = size - 1;
	int middle = 0;
	while (left <= right)
	{
		middle = ((left + right) / 2);
		if (arr[middle] > x)
		{
			right = middle - 1;		
		}
		else if (arr[middle] <= x)
		{
			left = middle + 1;
		}
	}
	return size - left;
}

int main()
{
	int x;

	std::cout << "Enter a reference point :  ";
	std::cin >> x;
	
	std::cout << "Number of elements in the array greater than " << x  << " : " << NumdersOfValue(arr, x);

	return 0;
}