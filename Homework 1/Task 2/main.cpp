#include<iostream>

int searching(const int* arr, const int size, const int aim)
{
	int left{ 0 };
	int right{ size - 1 };
	int index{};
	while (right > left)
	{
		int middle = (right + left) / 2;
		if (arr[0] > aim)
		{
			index = -1;
			break;
		}
		else if (arr[middle] == aim && arr[middle+1] > aim && arr[middle-1]<=aim)
		{
			index = middle;
			break;
		}
		else if (arr[middle] > aim && arr[middle + 1] > aim && arr[middle - 1] <= aim)
		{
			index = middle-1;
			break;
		}
		else if (arr[middle] >= aim && arr[middle - 1] > aim)
		{
			right = middle+1;
		}
		else if (arr[middle] >= aim && arr[middle + 1] <= aim)
		{
			left = middle - 1;
		}
		else if (arr[middle] < aim)
		{
			left = middle + 1;
		}
		else if (arr[middle] > aim)
		{
			right = middle-1;
		}
	}
	if (left == right && arr[left] == aim)
	{
		index = left;
	}

	return size - 1 - index;
}

int main()
{
	int aim;
	int arr[9] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
	int size = 9;
	std::cout << "Given an array: [";
	for (int i = 0; i < size; ++i)
	{
		std::cout << arr[i];
		if (i != size - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << "].\n";
	std::cout << "Enter the number for which you want to know: how many array elements are greater than this: ";
	std::cin >> aim;
	std::cout << "The number of elements is greater than " << aim << ": " << searching(arr, size, aim);
	return 0;
}