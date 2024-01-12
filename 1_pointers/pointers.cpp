#include <iostream>

int main()
{
	/* pointer doesn't hold data really, it JUST holds an integer that is a memory address!
	A pointer then points to a location in memory: that location is the 
	starting location of a memory space (whose lenght is defined by the type) */
	
	int var = 6;
	// we declare a pointer using the * right after the type
	void* ptr = 0; // 0 or nullptr or NULL
	ptr = (int*)&var; // &var means give me the address of variable var (dereference 
	// variable var)
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

	buffer[0] = 'a';
	buffer[1] = 'b';
	std::cout << "first element of the array is " << buffer[0] << std::endl;
	std::cout << "second element of the array is " << buffer[1] << std::endl;

	//memset(buffer, 0, 8); // fill the array with 0 values
	
	// being that we created the array on the heap, once we have used it 
	// we need to manually delete it!
	delete[] buffer;
	
	
	// pointer to a pointer
	char** pp = &buffer;
	// so now pp contains the memory address that the pointer buffer points to
	
	// declaration of two pointers on one line
	// if we write int* x, y then we are declaring x as an int pointer and y as a normal int variable
	int* x, *y;


	std::cout << "\nPointer arithmetics:" << std::endl;

	// these are all **syntax errors**
	// p*++;
	// p++*; 
	// ++p*;

	// the [] array operator is secretly a pointer, so it's somehow like to write
	// int* b = {3, 0, 7}, but sintattically it's not correct, so we write
	int b[] = {3, 0, 7};
	int* p = b;

	switch(4) {
		case 1:
			std::cout << *++p << std::endl; // move p, then dereference p -> 0
			std::cout << *++p << std::endl; // -> 7, [3 0 7]
			break;
		case 11:
			std::cout << *(++p) << std::endl; // move p, then dereference p -> 0
			std::cout << *(++p) << std::endl; // -> 7, [3 0 7]
			break;
		case 2:
			std::cout << ++*p << std::endl; // dereference p, then increment -> 4
			std::cout << ++*p << std::endl; // -> 5, [5 0 7]
			break;
		case 22:
			std::cout << ++(*p) << std::endl; // dereference p, then increment -> 4
			std::cout << ++(*p) << std::endl; // -> 5, [5 0 7]
			break;
		case 3:
			std::cout << *p++ << std::endl; // dereference p, then move p -> 3
			std::cout << *p++ << std::endl; // -> 0, [3 0 7]
			break;
		case 33:
			std::cout << *(p++) << std::endl; // dereference p, then move p -> 3
			std::cout << *(p++) << std::endl; // -> 0, [3 0 7]
			break;
		case 4:
			std::cout << (*p)++ << std::endl; // dereference p, then print, then increment -> 3
			std::cout << (*p)++ << std::endl; // -> 4, [5 0 7]
			break;
		//default:
			// code block
	}

	std::cout << b[0] << " " << b[1] << " " << b[2] << std::endl;
}