#include <iostream>

int s_var = 5;
//int var = 8; //this is not allowed: the linker finds multiple definition of var

extern int nother;
extern int s_nother; 

/* this is not working because funcition is already declared in static.cpp
but s_function() can be declared as in static.cpp the s_function() is
declared static */
//void funciotn() {} 
void s_function() {}

/*if i use static variable inside a function, the first time we run the
function it declare the variable and initialize it to 0, the other times 
it just refer to the original variable to increment it*/
void example() {
	static int i = 0;
	i++;
	
	std::cout << i << std::endl;
}

int main(int argc, char **argv)
{
	std::cout << s_var << std::endl;
	
	std::cout << nother << std::endl;
	/*this is not working (undefined reference to s_nother) because
	s_another in static.cpp is declared static*/
	//std::cout << s_nother << std::endl;
	
	
	example();
	example();
	example();
	
	//return 0;
}
