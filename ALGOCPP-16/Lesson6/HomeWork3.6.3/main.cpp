#include<iostream>
#include<string>
int hash(std::string _string)
{
	int  size = _string.size();
	int _hash = 0;
	for (int i = 0; i < size; i++)
	{
		_hash = _hash + static_cast<int> (_string[i]);
	}
	return _hash;
}
int find_substring_light_rabin_karp(std::string _p, std::string _s)
{
	int hash_s = 0;
	int hash_p = hash(_p);
	int size_p = _p.size();
	int size_s = _s.size();
	for (int i = 0; i < size_s; i++)
	{
		if (i + size_p - 1 == size_s)
		{
			return -1;
		}
		if (i == 0)
		{
			hash_s = hash(_s.substr(i, size_p));
		}
		else
		{
			hash_s -= static_cast<int> (_s[i - 1]);
			hash_s += static_cast<int> (_s[i + size_p - 1]);
		}
		if (hash_s != hash_p)
		{
			continue;
		}
		else
		{
			for (int j = 0; j < size_p; j++)
			{
				if (_s[i + j] != _p[j])
				{
					return -1;
				}
				else
				{
					return i;
				}
			}
		}
		
	}
}
	

int main()
{
	std::string s;
	std::string p;
	std::cout << "Enter the text to be searched:";
	std::cin >> s;
	
	do
	{
		std::cout << "Enter the substring you want to find :";
		std::cin >> p;

		int index = find_substring_light_rabin_karp(p, s);
		if (index == -1)
		{
			std:: cout << "Substring " <<  p << " not found" << std::endl;
		}
		else
		{
			std::cout << "Substring " << p << " found at index " << index << std::endl;
		}	
	} 
	while (p != "exit");
	return 0;
}