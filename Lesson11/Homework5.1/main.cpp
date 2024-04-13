#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<string>

int main()
{
	std::string new_string;
	std::multimap <char, int> map_char;
	std::getline(std::cin, new_string);
	int count = 0;
	
	for (int i = 0; i < new_string.length(); i++)
	{	
		map_char.insert({ new_string[i] , count });
	}
	for (int i = 0; i < new_string.length(); i++)
	{
		auto key = map_char.find(new_string[i]);
		if (key == map_char.end())
			key->second = 1;
		else
			key->second++;
	}
	
	for (auto itr = map_char.begin(); itr != map_char.end(); ++itr)
	{
		if (itr->second != 0)
		{
			std::cout << itr->first << " : " << itr->second << std::endl;	
		}
	}
	
	return 0;
}