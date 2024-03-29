#include<iostream>
#include<list>
using namespace std;

class Node
{
public:
	Node(int _data)
	{
		data = _data;
		next_ptr = nullptr;
	}
	int data;
	
    Node* next_ptr;// укуазательь на следующий обьект 
	
};

class List
{
public:
	List();
	~List();

	bool is_empty()
	{
		return first_ptr == nullptr;
	}
	void insert_front(int _value)
	{
		Node* new_node = new Node(_value);
		if (is_empty())
		{
			first_ptr = last_ptr = new_node;
		}
		else
		{
			new_node->next_ptr = first_ptr;
			first_ptr = new_node;
		}
	}
	void remove_front(int _value)
	{
		if (is_empty)
		{
			return;
		}
		if (first_ptr == last_ptr)
		{
			Node* delete_ptr = first_ptr;
			first_ptr = last_ptr = nullptr;
		}
		else
		{

		}
	}
	void print()
	{
		Node* print_ptr = first_ptr;
		while (print_ptr != nullptr)
		{
			cout << print_ptr->data << " ";
			print_ptr = print_ptr->next_ptr;
		}
	}

private:
	Node* first_ptr;
	Node* last_ptr;
};

List::List()
{
	first_ptr = last_ptr = nullptr;
}

List::~List()
{

}
int main()
{
	List L;
	L.insert_front(10);
	L.insert_front(15);
	L.insert_front(20);
	L.insert_front(25);
	L.insert_front(30);
	L.print();
	return 0;
}