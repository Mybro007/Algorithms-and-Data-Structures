#include<iostream>
#include<string>

long realHash(const std::string str, const int p, const int n)
{
	long answ{};
	long mult{ 1 };
	for (int i = 0; i < str.size(); i++)
	{
		answ += mult * str[i];
		mult *= p;
	}
	return answ % n;
}

int main()
{
	std::string str;
	int p{};
	int n{};
	std::cout << "Input the multiplier for hash function (p): ";
	std::cin >> p;
	std::cout << "Input the divider for hash function (n): ";
	std::cin >> n;
	bool exit = false;
	do
	{
		std::cout << "Input the string: ";
		std::cin >> str;
		std::cout << "Simple hash of string '" << str << "' is: " << realHash(str,p,n) << "\n";
		(str == "exit" ? exit = true : exit);
	} while (!exit);
	return 0;
}