#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

        template<class T>
		T sqrt_(T x)
		{
			
			return x * x;
		}
	   template<class T> 
	   vector<T> sqrt_(vector<T> v)
	   {
		   for (size_t i = 0; i < v.size(); ++i)
		   {
			   v[i] = pow(v[i], 2);
		   }
		   return v;
	   }

	
int main()
{

	int y = sqrt_(5);
	vector <int> Myvector{ 1 , 2, 3 };
	
	int x = sqrt_(Myvector)[2];
	

	cout << x;
    cout << y;
	 

	return 0;
}