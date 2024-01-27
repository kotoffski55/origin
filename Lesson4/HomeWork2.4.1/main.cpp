#include<iostream>

class Figure
{
protected:

	int sides_num = 0;
	std::string name = "Figure";
	
public:

	int  getSidesNum()
	{
		return sides_num;
	}
	std::string getName()
	{
		return name;
	}
};

class Triangle : public Figure
{
public:
	Triangle()
	{
		sides_num = 3;
		name = "Triangle";
	}
};

class Quadrangle : public Figure
{
public:
	Quadrangle()
	{
		sides_num = 4;
		name = "Quadrangle";
	}
};

int main()
{
	std::cout << "Number of sides " << std::endl;

	Figure fig;
	std::cout << fig.getName() << " : " << fig.getSidesNum() << std::endl;

	Triangle tr;
	std::cout << tr.getName() << " : " << tr.getSidesNum() << std::endl;

	Quadrangle quad;
	std::cout << quad.getName() << " : " << quad.getSidesNum() << std::endl;

	return 0;
}