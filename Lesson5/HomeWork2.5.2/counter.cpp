#include"counter.h"


	Counter::Counter()
	{
		this->value = 1;
	}
	Counter::Counter(const int& value)
	{
		this->value = value;
	}
	void Counter::counterSum()
	{
		this->value = this->value + 1;
	}
	int Counter::counterGetValue()
	{
		return value;
	}
	void Counter::counterSubtraction()
	{
		this->value = this->value - 1;
	}

