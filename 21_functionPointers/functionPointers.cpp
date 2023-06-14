#include <iostream>
#include <vector>

void print(int value){
	std::cout << "value: " << value << std::endl;
}

void foreach(const std::vector<int>& values, void(*func)(int)){
	for (int v : values)
		func(v);
}

int main(){

    // let's try to create a function pointer: 
    // 1. let's try to assign fptr the mem address of function print()
    //auto fptr = &printValue;
    //fptr;
    //fptr; 
    // it works..

    // 2. what kind of type is auto? auto is void(*fptr)(int) so
    //void(*fptr)(int) = print;
    
    // 3. or even better using typedef 
    typedef void(*fptr)(int);
    fptr myprint = print;
    print(666);


	std::vector<int> values = {1, 2, 3};
    // here I use foreach function to which I pass a vector of elements 
    // and a function pointer: the function the pointer points 
    // to defines what I want to do with each element of the vector.
	foreach(values, print);

    // or using a lambda function
    foreach(values, [](int value){std::cout << "lvalue: " << value << std::endl;});
}