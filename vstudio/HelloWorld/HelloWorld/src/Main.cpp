/*
* in project properties, select for All configurations and All Platforms
* OUTPUT DIR:		$(SolutionDir)bin\$(Platform)\$(Configuration)\
* INTERMEDIATE DIR:	$(SolutionDir)bin\intermediates\$(Platform)\$(Configuration)\
*/

#include <iostream>

int main()
{
	int a = 8;

	const char* mystring = "Ciao";

	std::cout << "Hello World" << std::endl;
	std::cin.get();
}