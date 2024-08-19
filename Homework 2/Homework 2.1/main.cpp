#include<iostream>

int Fibonacci(int num)
{
	if (num == 1 || num == 2)
	{
		return 1;
	}
	if (num == 0)
	{
		return 0;
	}

	return Fibonacci(num - 1) + Fibonacci(num - 2);
}

int main()
{
	int num{};
	std::cout << "Enter the number of numbers you want to know: ";
	std::cin >> num;
	std::cout << "Fibonacci numbers: ";
	for (int i = 0; i < num; ++i)
	{
		std::cout << Fibonacci(i) << " ";
	}
	std::cout << "\n";
	return 0;
}