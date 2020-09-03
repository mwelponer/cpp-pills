#include <iostream>

int main(){
	
	/*pointer is JUST an integer that holds (is) a memory address
	a pointer points to a location in memory*/
	
	int var = 6;
	int* ptr = 0; // 0 or nullptr or NULL
	ptr = &var; // &var means give me the address of variable var
	
	std::cout << "ptr holds " << ptr << ", at that address we find " 
		<< *ptr << std::endl; 
	// *ptr (dereference) is used to access data the pointer points to
	
	// how to use a pointer with arrays
	char* buffer = new char[8];
	delete[] buffer;
	
	// pointer to a pointer
	char** pp = &buffer;
	// so now pp contains the memory address that the pointer buffer points to
}