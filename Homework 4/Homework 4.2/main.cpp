#include<iostream>

class SizeException : std::exception
{
public:
	const char* what() const noexcept override
	{
		return "Logical size cannot exceed actual size!!!\n";
	}
};

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

void copyArr(int* arr, int* newArr, int logicalSize)
{
	for (int i = 0; i < logicalSize; ++i)
	{
		newArr[i] = arr[i];
	}
}

void sizeUp(int* arr, int& actualSize, int& logicalSize)
{
	actualSize *= 2;
	int* newArr = new int[actualSize];
	copyArr(arr, newArr, logicalSize);
	arr = newArr;
}

void appendDynamic(int* arr, int& actualSize, int& logicalSize, const int& current)
{
	if (logicalSize >= actualSize)
	{
		sizeUp(arr, actualSize, logicalSize);
	}
	logicalSize++;
	arr[logicalSize-1] = current;
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
	try
	{
		if (logicalSize > actualSize)
		{
			throw SizeException();
		}
	}
	catch (const SizeException ex)
	{
		std::cout<<ex.what();
		exit(0);
	}
	inputArr(arr, logicalSize);
	printArr(arr, actualSize, logicalSize);
	int current{ -1 };
	std::cout << "Input the element to add to array: ";
	std::cin >> current;
	while (current != 0)
	{
		appendDynamic(arr, actualSize, logicalSize, current);
		printArr(arr, actualSize, logicalSize);
		std::cout << "Input the element to add to array: ";
		std::cin >> current;
	}
	std::cout<<"Thank you! Your array: ";
	printArr(arr, actualSize, logicalSize);
	std::cout<<"\n";
	delete[] arr;
	return 0;
}
