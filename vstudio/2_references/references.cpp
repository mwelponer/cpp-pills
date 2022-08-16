#include "entity.h"

/* here if I use int value as argument a new int variable will be created 
 and initialized to what we pass to the function, then inside the 
 function it will be incremented, then it will be destroied outside of the function scope */
void noIncrement(int value) 
{
    value++;
	std::cout << "inside the function: " << value << std::endl;
}

/* if instead we use a reference as argument (pass by reference) we have two 
 advantages: 1. we don't allocate new memory with another int variable, 
 2. we go to modify exactly the variable we have passed to the function, so
 the variable will be incremented and will remain incremented outside of the function scope
*/
void incrementUsingReference(int& value) 
{
	value++;
}

void incrementUsingPointer(int* value) 
{
	(*value)++; // dereference first then increment
}

int rename(Entity& e, const std::string& name)
{
    e.setName(name);
    std::cout << "renamed to " << e.getName() << " (via ref)" << std::endl;
}

int rename(Entity* e, const std::string& name)
{
    e->setName(name);
    std::cout << "renamed to " << e->getName() << " (via ptr)" << std::endl;
}


int main(int argc, char **argv) 
{	
	std::cout << "######### references" << std::endl;
	/* references are just "reference" to an exsisting variable.
	References do not occupy memory, they don't have a storage.
    References have to reference an already exsisting varible, so they are just
	like an alias */
	
	int a = 5;
	std::cout << a << std::endl;
	
    // we declare a reference using the & right after the type
	int& ref = a; // we need to assign reference immediately
	ref = 2; // now if we assign another value to reference, we change the variable the reference references to, so a variable
	std::cout << a << std::endl;
	
	int b = 6;
	ref = b; // now a holds 6 and b also 6
	/* This is because once you have assigned a specific variable to a reference, that
	variable can't be changed. So the reference can't be changed to a different 
	variable. */
	std::cout << a << ", " << b << std::endl;


	std::cout << "########## passing by ref or by ptr" << std::endl;

    // now if we want to increment variable a, if we pass the variable, it will be incremented just inside the function but not outside
    noIncrement(a);
    std::cout << "outside the function: " << a << std::endl;
    
    // but if we pass the memory address of the variable, the variable will be incremented
	incrementUsingPointer(&a);
	std::cout << a << std::endl;

	incrementUsingReference(a);
	std::cout << a << std::endl;
	
	// passing by ref or by pointer with classes
    
	// instance on the stack
	Entity e1("mik");  
    rename(e1, "mike"); // passing by reference (e1 is a ref)
    rename(&e1, "mikey"); // passing by pointer (&e1 is the address of e1)

	// instance on the heap
    Entity* e2 = new Entity("rob");
    rename(e2, "robb"); // passing by pointer (e2 is a pointer)
    rename(*e2, "robby"); // passing by reference (*e2 means dereference so get what the pointer points to)
}