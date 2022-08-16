#include <iostream>
#include <array>

int main()
{
    std::cout << "######### arrays on the stack" << std::endl;
    // using [] we specify that it is an array. An array name in c/c++ is 
    // basically a pointer to the first element of the array, without the need to use *
    int array1[10]; // array declaration
    int array2[] = {1, 2, 3, 4, 5}; // array declaration and initialization

    for(int i=0; i<5; i++) 
        std::cout << array2[i] << " "; 
    std::cout << std::endl;
    
    // array2 is a pointer to &array2[0], which is the address of the first element of 
    // the array array2
    std::cout << "array2: " << array2 << std::endl;
    std::cout << "&array2[0]: " << &array2[0] << std::endl;
    std::cout << "&array2: " << &array2 << std::endl;

    // i can access array elements using pointer dereference
    int* ptr = array2;
    std::cout << *ptr << " same as " << array2[0] << std::endl;
    // if array2 is the memory address of the first element, the element at index 1
    // ptr+1 is the memory address of the second element of the array
    std::cout << *(ptr+1) << " same as " << array2[1] << std::endl;
    

    std::cout << "######### arrays on the heap" << std::endl;
    /* declaration of an array on the heap. 
    The difference is lifetime: creating something in the stack 
    will be destroyed when out of the scope, while in the heap
    it will persist until deleted 
    So if you have a function returning an array for example, 
    you have to use the new keyword! */
    int* heapArr = new int[5];
    /* we treat it in the same way of a normal array */
    for (int i=0; i < 5; i++)
        heapArr[i] = i; 
    for (int i=0; i < 5; i++)
        std::cout << "heapArr [" << i << "]:" << heapArr[i] << std::endl;
    
    /* we manually delete the array like this */    
    delete[] heapArr;

    
    std::cout << "######### std::arrays" << std::endl;
    /* declare an array using the standard cpp v11 array */
    std::array<int, 10> stdArr;
    std::cout << stdArr.size() << std::endl;
    /* it supports bounds checking and it keeps track of the array 
     size, but of course with some overhead */
}