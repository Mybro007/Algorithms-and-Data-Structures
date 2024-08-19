#include<iostream>

int Fibonacci(int num, int* mem)
{
	if (mem[num] == 0)
	{
		if (num == 1 || num == 2)
		{
			mem[num] = 1;
		}
		else if (num == 0)
		{
			mem[num] = 0;
		}
		else
		{
			mem[num] = Fibonacci(num - 1, mem) + Fibonacci(num - 2, mem);
		}
	}
	
	return mem[num];
}

int main()
{
	int num{};
	std::cout << "Enter the number of numbers you want to know: ";
	std::cin >> num;
	int* memory = new int[num]{};
	std::cout << "Fibonacci numbers: ";
	for (int i = 0; i < num; ++i)
	{
		std::cout << Fibonacci(i,memory) << " ";
	}
	std::cout << "\n";
	delete[] memory;
	return 0;
}