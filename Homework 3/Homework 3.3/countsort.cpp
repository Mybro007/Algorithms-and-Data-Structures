#include<iostream>
#define MAX 255

void countSort(int* array, int size) 
{
    int output[MAX]{};
    int count[MAX]{};
    int max = array[0];

    for (int i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}

int main()
{
    int size{};
    std::cout << "Input the length of array: ";
    std::cin >> size;
    int* arr = new int[size];
    std::cout << "Input the array: ";
    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }

    std::cout << "Your array: ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    countSort(arr, size);
    std::cout << "\n";
    std::cout << "Sorted array: ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
}