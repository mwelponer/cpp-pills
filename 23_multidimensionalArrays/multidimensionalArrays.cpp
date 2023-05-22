#include <iostream>

int main(){

    // ONE DIMENSION ARRAY //////////////
    ////////////// on the stack, an array is a pointer by definition
    int a[50];
    int* ptr = a;
    ////////////// on the heap 
    char* str = new char[100];

    // TWO DIMENSION ARRAY //////////////
    ////////////// on the stack
    int x[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
    // print out 
    for (int r=0; r < 3; r++){
        for (int c=0; c < 4; c++)
            std::cout << x[r][c];
        std::cout << std::endl;
    }
    ////////////// on the heap
    // a pointer to a pointer to an integer
    int** a2d = new int*[3];
    // with this we just have allocated memory
    // specifically 50 integer pointers, so
    // 4bytes * 50 = 200 bytes of memory
    // now we need to initialize the 50 arrays 
    for (int i = 0; i < 3; i++)
        a2d[i] = new int[4];
    // print out
    for (int r=0; r < 3; r++){
        for (int c=0; c < 4; c++)
            std::cout << *(a2d[r] + c);
        std::cout << std::endl;
    }
    // so to delete we need to dolete them one by one
    for (int i = 0; i < 3; i++)
        delete[] a2d[i];
    // and finally
    delete[] a2d;
}