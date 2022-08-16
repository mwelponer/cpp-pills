#include <iostream>
#include <string.h>

/* passing the string around functions*/
void wrongPrintString(std::string string)
{
	string += " 666";
	std::cout << string << std::endl;
}

void printString(const std::string& string)
{
	//string += " 666"; // it is const so we cannot modify the string!
	std::cout << string << std::endl;
}

int main(int argc, char **argv)
{
	/* desclaration of a string using a char pointer 
	 * in c++ it is immutable in the sense that you cannot 
	 * change the lenght of the string, so usually it is 
	 * declared const */
	const char* name = "Mike";
	std::cout << name << std::endl;
	std::cout << strlen(name) << std::endl;
	
	char* str1 = "Ciao";
	char str2[40];
	strcpy(str2, str1); // copy str1 into str2 
	std::cout << str2 << std::endl;
	
	
	
	/* if we want to declare it completely manually 
	 * we need to add the string termination char (0 or '\0') that 
	 * tells the pointer that the string is terminated. */
	char another[5] = {'M', 'i', 'k', 'e', 0};
	std::cout << another << std::endl;
	
	/* finally if we want to use the standard string implementation.
	 * The string include is used just to overload the << operator in 
	 * the cout */
	std::string myString = "ciao";
	std::cout << myString << std::endl;
	
	/* useful string methods */
	std::cout << "size: " << myString.size() << std::endl;
	std::cout << "find: " << myString.find("ao") << std::endl;
	bool contains = myString.find("c") != std::string::npos;
	std::cout << "contains: " << contains << std::endl;
	std::cout << myString.append(" cicco") << std::endl;
	
	/* another way to append text to the string */
	myString += "!";
	std::cout << myString << std::endl;
	
	/* or another way */
	myString = std::string(myString) + "!!!";
	std::cout << myString << std::endl;
	
	
	/* to demonstrate how to use correctly string passing among functions */
	wrongPrintString(myString);
	std::cout << myString << std::endl;

	const std::string test = "my test";
	printString(test);
}
