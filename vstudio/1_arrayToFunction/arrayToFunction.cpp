#include <iostream>

int getSum1(int arr[], int size)
{
    int s = 0;
    for (int i=0; i<size; i++)
        s += arr[i];

    return s;
}

int getSum2(int* arr, int size)
{
    int s = 0;
    for (int i=0; i<size; i++)
        s += arr[i];

    return s;
}

int main()
{
    int second[4] = {1, 2, 3, 4};

    std::cout << "getSum: " << getSum1(second, 4) << std::endl;
    std::cout << "getSum: " << getSum2(second, 4) << std::endl;
}
