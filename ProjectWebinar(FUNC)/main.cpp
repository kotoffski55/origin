#include<iostream>
#include<string>
class B;
class A
{
	friend void set_value(A& obj, int _value);
	int get_value_B1(B& obj)
	{
		return obj.value_1;
	}
public:
	int value = 10; 

};
class B
{
public:
	friend int A::get_value_B1(B& obj);

	int value_1 = 10;
};
void set_value(A& obj, int _value)
{
	obj.value = _value;
}
int main()
{
	A obj1;

	set_value(obj1, 100);

	return 0;
}