#include<iostream>

void inputArr(int* arr, int logicalSize)
{
	for (int i = 0; i < logicalSize; ++i)
	{
		std::cout << "Input the arr[" << i << "]: ";
		std::cin >> arr[i];
	}
}

void printArr(int* arr, int actualSize, int logicalSize)
{
	std::cout << "Dinamic array: ";
	for (int i = 0; i < logicalSize; ++i)
	{
		std::cout << arr[i] << " ";
	}
	for (int i = 0; i < actualSize - logicalSize; ++i)
	{
		std::cout << "_ ";
	}
	std::cout << "\n";
}

int main()
{
	int actualSize{};
	int logicalSize{};
	std::cout << "Input the actual size of the array: ";
	std::cin >> actualSize;
	int* arr = new int[actualSize];
	std::cout << "Input the logical size of the array: ";
	std::cin >> logicalSize;
	inputArr(arr, logicalSize);
	printArr(arr, actualSize, logicalSize);
	delete[] arr;
	return 0;
}