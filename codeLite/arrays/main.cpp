#include <iostream>
#include <array>

int main()
{
    /* declaration of an array of int with size 5 in the stack
     the memory allocated is contiguous and 
     equal to sizeof(int)*5 */
    int example[5];
    
    /* access elements of an array read/write 
     write */
    for (int i=0; i < 5; i++)
        example[i] = 0; 
        
    /* and read */
    for (int i=0; i < 5; i++)
        std::cout << example[i] << std::endl;
    
    /* an array is just a pointer to the first element so 
     we can write */
    int* ptr = example;
 
    /* so this line */
    example[3] = 666; std::cout << example[3] << std::endl;
    
    /* equals to this one */
    *(ptr + 3) = 777; std::cout << example[3] << std::endl;
    
    
    /* declaration of an array on the heap. 
     The difference is lifetime: creating something in the stack 
     will be destroyed when out of the scope, while in the heap
     it will persist until deleted 
     So if you have a function returning an array for example, 
     you have to use the new keyword! */
    int* heapArr = new int[5];
    
    /* we treat it in the same way of a normal array */
    for (int i=0; i < 5; i++) 
        heapArr[i] = 0; 
    for (int i=0; i < 5; i++)
        std::cout << heapArr[i] << std::endl;    
        
    /* we manually delete the array like this */    
    delete[] heapArr;
    
    
    /* declare an array using the standard cpp v11 array */
    std::array<int, 10> stdArr;
    std::cout << stdArr.size() << std::endl;
    /* it supports bounds checking and it keeps track of the array 
     size, but of course with some overhead */
}
