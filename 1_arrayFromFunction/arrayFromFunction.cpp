#include <iostream>

int* fun()
{
    // to return the address of a variable (a pointer) outside of the function
    // the pointer needs to be static!
    static int arr[3] = {1, 2, 3};
    return arr;
}

int main()
{
    int* ptr = fun();

    for(int i=0; i<3; i++)
        std::cout << *(ptr+i) << std::endl;
}