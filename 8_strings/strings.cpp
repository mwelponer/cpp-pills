#include <iostream>
#include <string.h> // for strlen and strcpy

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
	"Mike"; // this is a string literal and it has type const char[5] 
	// because of the \0 at the end

	std::cout << "######### string using char*" << std::endl;
	/* declaration of a string using a char pointer 
	 * in c++ it is immutable in the sense that you cannot 
	 * change the lenght of the string, or the value of any of 
	 * its characters so usually it is declared const */
	const char* name = "Mike";
	std::cout << name << ", " << strlen(name) << std::endl;
	
	const char* str1 = "Ciao";
	std::cout << str1 << ", " << strlen(str1) << std::endl;
	char str2[40];
	strcpy(str2, str1); // copy str1 into str2 
	std::cout << str2 << ", " << strlen(str2) << std::endl;
	

	std::cout << "######### string manually initialized" << std::endl;
	/* if we want to declare it completely manually 
	 * we need to add the string termination char (0 or '\0') that 
	 * tells the pointer that the string is terminated. */
	char another[5] = {'M', 'i', 'k', 'e', 0};
	std::cout << another << std::endl;
	

	std::cout << "######### std::string" << std::endl;
	/* finally if we want to use the standard string implementation.
	 * The string include is used just to overload the << operator in 
	 * the cout */
	std::string myString = "ciao";
	std::cout << myString << std::endl;
	
	/* useful string methods */
	std::cout << "size: " << myString.size() << std::endl;
	std::cout << "char at index 3: " << myString[2] << std::endl;
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
