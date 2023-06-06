#include <iostream>

struct entity {
    int a, b;
};

int main(){
    int a = 5;
    std::cout << "a:" << a << std::endl;
    double value = a; // this one here is an implicit conversion 
    // so the compiler implicitly did 
    // double value = (double)a;
    // what was actually done was a conversion from int to double
    // so we will find different things into the memory
    std::cout << "value:" << value << std::endl;


    // what instead if we want to take that exsisting memory and 
    // treat it as a double (type punning)
    // we take memory address of 'a', cast it to double pointer, then 
    // dereference to get back the value 
    value = *(double*)&a;
    std::cout << "value:" << value << std::endl;


    // a more interesting example: let's type punning a struct into an array
    entity e = {5, 8};
    int* arr = (int*)&e;

    std::cout << "arr: " << arr[0] << ", " << arr[1] << std::endl;
}