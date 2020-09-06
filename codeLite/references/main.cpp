#include <iostream>


void incrementUsingPointer(int* value) {
	(*value)++; // dereference first then increment
}

void incrementUsingReference(int& value) {
	value++;
}


int main(int argc, char **argv) {
	
	/* references are just pointers to an exsisting variable
	they have to reference an already exsisting varible, so they are just 
	like an alias */
	
	int a = 5;
	std::cout << a << std::endl;
	
	int& ref = a;
	ref = 2;
	std::cout << a << std::endl;
	
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
