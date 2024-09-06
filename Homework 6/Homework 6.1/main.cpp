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

int main()
{
	std::string str;
	bool exit = false;
	do
	{
		std::cout << "Input the string: ";
		std::cin >> str;
		std::cout << "Simple hash of string '" << str << "' is: " << simpleStringHash(str) << "\n";
		(str == "exit" ? exit = true : exit);
	} while (!exit);
	return 0;
}