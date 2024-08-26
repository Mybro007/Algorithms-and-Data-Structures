#include<iostream>
#include<string>

class DeleteException : std::exception
{
public:
	const char* what() const noexcept override
	{
		return "The first element cannot be removed because the array is empty. Goodbye!\n";
	}
};

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

int* copyArr(int* arr, int* newArr, int& actualSize, int& logicalSize)
{
	for (int i = 1; i < logicalSize; ++i)
	{
		newArr[i-1] = arr[i];
	}
	return newArr;
}

int* sizeReduce(int* arr, int& actualSize, int& logicalSize)
{
	actualSize /= 3;
	int* newArr = new int[actualSize];
	copyArr(arr, newArr, actualSize, logicalSize);
	return newArr;
}

void deleteTheFirstElement(int*& arr, int& actualSize, int& logicalSize)
{
	try
	{
		if (logicalSize == 0)
		{
			throw DeleteException();
		}
	}
	catch (const DeleteException& ex)
	{
		std::cout << ex.what();
		exit(0);
	}

	if (logicalSize - 1 <= actualSize / 3)
	{
		int* newArr = sizeReduce(arr, actualSize, logicalSize);
		arr = newArr;
	}
	else
	{
		int* newArr = new int[actualSize - 1]{};
		newArr = copyArr(arr, newArr, actualSize, logicalSize);
		arr = newArr;
	}
	logicalSize--;
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
		std::cout << ex.what();
		exit(0);
	}
	inputArr(arr, logicalSize);
	printArr(arr, actualSize, logicalSize);
	std::string answer;
	std::cout << "Do you want to delete first element of array? Print yes or no: ";
	std::cin >> answer;
	while (answer != "no")
	{
		deleteTheFirstElement(arr, actualSize, logicalSize);
		printArr(arr, actualSize, logicalSize);
		std::cout << "Do you want to delete first element of array? Print yes or no: ";
		std::cin >> answer;
	}
	std::cout << "Tank you! ";
	printArr(arr, actualSize, logicalSize);
	delete[] arr;
	return 0;
}