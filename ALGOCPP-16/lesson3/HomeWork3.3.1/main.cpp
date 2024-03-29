#include<iostream>

void merge(const int* left, const int* right, int* arr ,int size_left,int size_right)
{
	
	int left_leight = size_left;
	int right_leight = size_right;
	int num_left = 0;
	int num_right = 0;
	int num_arr = 0;

	while ((num_left < left_leight) || (num_right < right_leight) )
	{
		if (num_left == left_leight)
		{
			arr[num_arr] = right[num_right];
			num_right++;
			num_arr++;
		}
		else if (num_right == right_leight)
		{
			arr[num_arr] = left[num_left];
			num_left++;
		}
		else
		{
			if (left[num_left] <= right[num_right])
			{
				arr[num_arr] = left[num_left];
				num_left++;
			}
			else
			{
				arr[num_arr] = right[num_right];
				num_right++;
			}
			num_arr++;
		}
		
	}
	return ;
}
void merge_sort(int* arr, int size)
{
	if (size == 1)
	{
		return;
	}

	int mid = size / 2;
	int* left = new int[mid];
	int* right = new int[size - mid];
	for (int i = 0; i < mid; i++)
	{
		left[i] = arr[i];
		//std::cout << left[i] << " ";
	}
	for (int i = mid; i < size; i++)
	{
		right[i - mid] = arr[i];
		//std::cout << right[i - mid] << " ";
	}
	merge_sort(left, mid);
	merge_sort(right, (size - mid));
	merge(left, right, arr, mid, (size - mid));

	delete [] left;
	delete[] right;
}
	
	
	
	
	

int main()
{
	//Source array
		//Sorted array:
	const int size_A = 10;
	const int size_B = 15;
	const int size_C = 18;

	int A[size_A] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
	int B[size_B] = { 88 ,91, 87, 59 ,53, 49 ,29 ,16, 4, 27 ,28 ,89, 2 ,25, 74};
	int C[size_C] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
	
	std::cout << "Source array : ";
	for (int i = 0; i < size_A; i++)
	{
		std::cout << A[i] << " ";
	}
	merge_sort(A, size_A);
	std::cout << std:: endl;
	std::cout << "Sorted array : ";
	for (int i = 0; i < size_A; i++)
	{
		std::cout << A[i] << " ";
	}
	
	std::cout << std::endl;

	std::cout << "Source array : ";
	for (int i = 0; i < size_B; i++)
	{
		std::cout << B[i] << " ";
	}
	merge_sort(B, size_B);
	std::cout << std::endl;
	std::cout << "Sorted array : ";
	for (int i = 0; i < size_B; i++)
	{
		std::cout << B[i] << " ";
	}

	std::cout << std::endl;

	std::cout << "Source array : ";
	for (int i = 0; i < size_C; i++)
	{
		std::cout << C[i] << " ";
	}
	merge_sort(C, size_C);
	std::cout << std::endl;
	std::cout << "Sorted array : ";
	for (int i = 0; i < size_C; i++)
	{
		std::cout << C[i] << " ";
	}


	return 0;
}