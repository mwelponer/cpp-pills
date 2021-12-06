//
//  main.cpp
//  References
//
//  Created by Mike on 06/12/2021.
//

#include <iostream>

void noIncrement(int value) {
    value++;
}

// the function that uses a memory address (a pointer) as parameter
void incrementUsingPointer(int* value) {
    (*value)++; // dereference first then increment
}

// the function that uses a reference as parameter
void incrementUsingReference(int& value) {
    value++; // simply increment the reference
}


int main(int argc, char **argv) {
    
    // references are just "reference" to an exsisting variable. References do not occupy memory, they don't have a storage. References have to reference an already exsisting varible, so they are just like an alias
    
    int a = 5;
    std::cout << "print the variable " << a << std::endl;
    
    // we declare a reference using the & right after the type
    int& ref = a; // we need to assign a variable to the reference immediately
    ref = 1; // now if we modify the reference, we modify the referenced variable
    std::cout << "modify the variable using the reference " << a << std::endl;
    
    // now if we want to increment the variable using a function, if we use a function that uses the variable itself as paramenter, it won't work because the variable will be incremented just inside the scope of the function but not outside
    noIncrement(a);
    std::cout << "using noIncrement " << a << std::endl;
    
    // but if we use a function that uses the memory address of the variable as the parameter, the variable will be incremented
    incrementUsingPointer(&a);
    std::cout << "using incrementUsingPointer " << a << std::endl;
    // the memory address of the variable can be also a pointer
    int* ptr = &a;
    incrementUsingPointer(ptr);
    std::cout << "using incrementUsingPointer " << a << std::endl;
    
    // we can simplify the work using a function that takes a reference as parameter
    incrementUsingReference(a);
    std::cout << "using incrementUsingReference " << a << std::endl;
    // it will work also using the reference ref
    incrementUsingReference(ref);
    std::cout << "using incrementUsingReference " << a << std::endl;
    
    // now if we declare another variable b and we change ref to b
    int b = 9;
    // the reference can't be changed to reference to a different variable. So if we assign b to ref, now a (the variable ref references to) holds 9
    ref = b;
    
    std::cout << "a: " << a << ", b: " << b << std::endl;
    
    //return 0;
}

