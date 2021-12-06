#include <iostream>

void noIncrement(int value) {
    value++;
}

void incrementUsingPointer(int* value) {
	(*value)++; // dereference first then increment
}

void incrementUsingReference(int& value) {
	value++;
}


int main(int argc, char **argv) {
	
	/* references are just "reference" to an exsisting variable.
	References do not occupy memory, they don't have a storage.
    References have to reference an already exsisting varible, so they are just
	like an alias */
	
	int a = 5;
	std::cout << a << std::endl;
	
    // we declare a reference using the & right after the type
	int& ref = a; // we need to assign reference immediately
	ref = 2; // now if we assign another value to reference, we change the variable the reference references to, so a variable
	std::cout << a << std::endl;
	
    // now if we want to increment variable a, if we pass the variable, it will be incremented just inside the function but not outside
    noIncrement(a);
    std::cout << a << std::endl;
    
    // but if we pass the memory address of the variable, the variable will be incremented
	incrementUsingPointer(&a);
	std::cout << a << std::endl;

	incrementUsingReference(a);
	std::cout << a << std::endl;
	
	
	int b = 6;
	ref = b; // now a holds 6 and b also 6
	/* This is because once you have assigned a specific variable to a reference, that
	variable can't be changed. So the reference can't be changed to a different 
	variable. */
	std::cout << a << ", " << b << std::endl;
	
	//return 0;
}
