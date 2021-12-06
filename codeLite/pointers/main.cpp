#include <iostream>

int main(){
	
	/* pointer doesn't hold data really, it JUST holds an integer that is a memory address!
	A pointer then points to a location in memory: that location is the 
	starting location of a memory space (whose lenght is defined by the type) */
	
	int var = 6;
	// we declare a pointer using the * right after the type
	void* ptr = 0; // 0 or nullptr or NULL
	ptr = (int*)&var; // &var means give me the address of variable var
	// now the pointer ptr points to the beginning of the variable var
	
	std::cout << "ptr holds address " << ptr 
		<< ", at that address we find " << *(int*)ptr
		<< " and var is " << var << std::endl;  
	// being that we declared the pointer void we need to cast it to an integer 
	// pointer with (int*), then we dereference the pointer with *pointer 
	// so with casting it becomes *(int*)ptr
	// dereference is used to access (read/write!) data the pointer points to
	
	// we could have written more easily 
	int* ptr2 = &var;
	std::cout << "ptr2 holds address " << ptr2 
		<< ", at that address we find " << *ptr2
		<< " and var is " << var << std::endl; 
		
	// if now we want to modify the data the pointer points to (e.g. the var variable) 
	// using the pointer itself then we just use the dereference *pointer
	*ptr2 = 3;
	std::cout << "the var now holds " << var << std::endl; 
		
	
	// how to use a pointer with arrays
	// NB: here we use new so the array will be created on the heap, not on the stack!
	char* buffer = new char[8];
	// each char size is 1byte so with this we have created a pointer to the beginning of 
	// an array of 8bytes (8 characters)
	
	memset(buffer, 0, 8); // fill the array with 0 values
	
	// being that we created the array on the heap, once we have used it 
	// we need to manually delete it!
	delete[] buffer;
	
	
	
	// pointer to a pointer
	char** pp = &buffer;
	// so now pp contains the memory address that the pointer buffer points to
}
