#include <iostream>
#include <vector>

void printValue(int value){
	std::cout << "value: " << value << std::endl;
}

void foreach(const std::vector<int>& values, void(*func)(int)){
	for (int v : values)
		func(v);
}

int main(){
	std::vector<int> values = {1, 2, 3};
    // so here I use foreach function to which I pass a vector of elements 
    // and a function pointer: the function the pointer points 
    // to defines what I want to do with each element of the vector.
	foreach(values, printValue);

    // or using a lambda function
    foreach(values, [](int value){std::cout << "lvalue: " << value << std::endl;});
}