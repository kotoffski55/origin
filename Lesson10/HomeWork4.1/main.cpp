#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

template<class T>
T  pow (T a)
{
	return a * a;

}
template<>
vector <int> pow(vector<int> _myvector)
{
	vector<int> result(_myvector.size());
	for (int i = 0; i < 10; i++)
	{
		result[i] = _myvector[i] * _myvector[i];

		return result;
	}
}

int main()
{
	
	vector <int> Myvector{ 1 , 2, 3 };
	
	int sqrt_int = pow<int>(2);
  
	vector <int> pow(vector<int> Myvector);
    
	
	return 0;
}