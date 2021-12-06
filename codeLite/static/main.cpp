#include <iostream>

int s_var = 5;
//int var = 8; //this is not allowed: the linker finds multiple definition of var

extern int nother; // extern means find the value of that variable in some other translation unit
extern int s_nother; 

//void function() {} // this is not working because funcition() is already declared in static.cpp

/* but s_function() can be declared as in static.cpp the s_function() is
declared static */
void s_function() {}

/* if i use static variable inside myFunction, the first time we run the
function it declares the variable and initialize it to 0, the other times 
it just refer to the original variable to increment it 
So it's like declaring the variable outside the function, but in this way
the variable can be modified (incremented) only inside the scope of myFunction */
void myFunction() {
	static int i = 0;
	i++;
	std::cout << i << std::endl;
}

int main(int argc, char **argv)
{
	std::cout << s_var << std::endl;
	
	std::cout << nother << std::endl;
	//std::cout << s_nother << std::endl;
	/* this is not working (undefined reference to s_nother) because
	s_another in static.cpp is declared static */
	
	
	myFunction();
	myFunction();
	myFunction();
	
	//return 0;
}
