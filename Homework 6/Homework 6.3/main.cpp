#include<iostream>
#include<string>

int simpleStringHash(const std::string s)
{
	int hash{};
	for (size_t i = 0; i < s.size(); i++)
	{
		hash += s[i];
	}
	return hash;
}

int find(const std::string s, const std::string p)
{
	int phash = simpleStringHash(p);
	int h{};
	bool match = false;
	int answer{ -1 };
	for (int i = 0; i < s.size(); i++)
	{
		if (i == 0)
		{
			std::string _str{};
			_str.resize(p.size());
			for (int i = 0; i < p.size(); i++)
			{
				_str[i] = s[i];
			}
			h = simpleStringHash(_str);
		}
		else
		{
			h -= s[i - 1];
			h += s[i + p.size() - 1];
		}

		if (h != phash)
		{
			match = false;
		}
		else
		{
			for (int j = 0; j < p.size(); j++)
			{
				if (s[i + j] != p[j])
				{
					match = false;
					break;
				}
				else
				{
					match = true;
				}
			}
		}

		if (match)
		{
			answer = i;
			break;
		}
	}
	return answer;
}

int main()
{
	std::string str;
	std::string substr;
	bool exit = false;
	std::cout << "Input the string: ";
	std::cin >> str;
	do
	{
		std::cout << "Input the substring which you want to find: ";
		std::cin >> substr;
		if (find(str, substr) != -1)
		{
			std::cout << "Substring '" << substr << "' is found by index: " << find(str, substr) << "\n";
		}
		else
		{
			std::cout << "Substring '" << substr << "' not found!\n";
		}
		(substr == "exit" ? exit = true : exit);
	} while (!exit);
	return 0;
}