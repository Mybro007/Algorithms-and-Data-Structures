#include<iostream>

void quickSort(int* array, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = array[(i + j) / 2];
    int temp;

    while (i <= j)
    {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low)
        quickSort(array, low, j);
    if (i < high)
        quickSort(array, i, high);
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
    quickSort(arr, 0, size-1);
    std::cout << "\n";
    std::cout << "Sorted array: ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}