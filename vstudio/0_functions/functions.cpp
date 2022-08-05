#include <iostream>

int multiply(int a, int b)
{
	return a*b;
}

int main(int argc, char **argv)
{
	std::cout << multiply(3, 4) << std::endl;
	
	// by default the main function returns 0
	//return 0;
}