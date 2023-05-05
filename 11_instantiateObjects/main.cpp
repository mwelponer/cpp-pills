#include <iostream>
#include <string>


class Entity 
{
private:
	std::string m_name;
public:
	Entity() : m_name("Mike") 
	{
		std::cout << "created Entity!" << std::endl;
	}
	
	~Entity() 
	{
		std::cout << "destroyed Entity!" << std::endl;
	}
	
	const std::string& getName() {
		return m_name;
	}
};

// this is a Unique pointer that will
// be automatically destroied as soon as the 
// ScopedPtr gets out of scope
class ScopedPtr
{
private:
	Entity* m_ptr;
public:
	ScopedPtr(Entity* ptr)
		: m_ptr(ptr) 
	{
	}
	~ScopedPtr()
	{
		delete m_ptr;
	}
};

int main() 
{
	////////////////////////////
	// ALLOCATING ON THE STACK
	// everything that is created on the STACK stops to 
	// exist when it goes out of scope. Any kind of scope 
	// like two simple curly brackets 
	{
		std::cout << "\n..entered scope" << std::endl;
		Entity entity1;
		std::cout << "..exiting scope" << std::endl;
	}
	// CAN"T DO THIS ANYMORE
	//std::cout << entity1->getName() << std::endl;
	
	
	////////////////////////////
	// ALLOCATING ON THE HEAP
	// everything that is created on the HEAP (using the word new
	// and a pointer) exists until I manually destroy it, or program ends
	Entity* entity2 = NULL;
	{
		std::cout << "\n..entered scope" << std::endl;
		entity2 = new Entity();
		std::cout << "..exiting scope" << std::endl;
	}
	
	std::cout << "entity name: " << entity2->getName() << std::endl;
	delete entity2; // manually
	
	
	////////////////////////////
	// USE OF OUR CUSTOM SCOPED POINTER
	{
		std::cout << "\n..entered scope" << std::endl;
		
		ScopedPtr ptr = new Entity();  
		// this equals to write:
		//ScopedPtr ptr = ScopedPtr(new Entity());
		// or:
		//ScopedPtr ptr(new Entity());
		// implicit conversion from an Entity pointer (new Entity on the heap) 
		// to a ScopedPtr object (ptr on the stack) that holds 
		// the new Entity
		
		std::cout << "..exiting scope" << std::endl;		
	}
	
	std::cin.get();
}
