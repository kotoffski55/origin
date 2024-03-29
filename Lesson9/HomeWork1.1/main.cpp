#include<iostream>
using namespace std;

struct point 
{
	double x;
	double y;

	point(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
};
void print_point(const point& point_object)
{
	std::cout << "x:" << point_object.x << ", y: " << point_object.y << std::endl;
}

int main()
{
	
	for (int i = 0; i < 5; i++)
	{	
		point my_point(i, 2 * i);
		print_point(my_point);	
	};
	return 0;
}
