#include <iostream>
#include <memory>

class Entity 
{

public:
	Entity()
	{
		std::cout << "created Entity!" << std::endl;
	}
	
	~Entity() 
	{
		std::cout << "destroyed Entity!" << std::endl;
	}
};

int main()
{
	std::cout << "\nUNIQUE POINTER" << std::endl;
	////////////////////////////
	// UNIQUE pointer is a simple type of smarpointer that is a scoped 
	// pointer, that means that it will be automatically deleted once it 
	// exits the scope. 
	// You cannot copy unique pointers
	std::unique_ptr<Entity> e;
	{
		std::cout << "..entered scope" << std::endl;
		//std::unique_ptr<Entity> entity(new Entity());
		// OR (this is slightly safer if an exception is thrown)
		std::unique_ptr<Entity> entity = std::make_unique<Entity>();
		// make_unique will create a new Entity that can have just one pointer
		//e = entity; // if we try to assign other pointers we wont be able to compile
		std::cout << "..exiting scope" << std::endl;
	}
	
	
	std::cout << "\nSHARED POINTER" << std::endl;
	////////////////////////////
	// SHARED pointer is a pointer that keeps a references count of the pointers to the
	// object. The memory gets freed only when the last reference gets deleted
	{
		std::cout << "..entered scope" << std::endl;
		std::shared_ptr<Entity> e;
		{
			std::cout << "....entered nested scope" << std::endl;
			std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>(); // a pointer is created (ref == 1)
			// make_shared will create a new Entity that can have many pointers
			e = sharedEntity; // pointer e is assigned with sharedEntity (now we have 2 ptrs to the Entity)
			std::cout << "....exiting nested scope" << std::endl;
			// at scope exit sharedEntity pointer gets deleted, ref count gets decremented to 1
		}
		// the Entity object is is still alive here because the ref count is not zero (e ref)
		
		std::cout << "..exiting scope" << std::endl;
	}
	
	
	std::cout << "\nWEAK POINTER" << std::endl;
	////////////////////////////
	// WEAK pointer is a pointer that doesn't increment the ref count of a shared pointer
	{
		std::cout << "..entered scope" << std::endl;
		std::weak_ptr<Entity> e;
		{
			std::cout << "....entered nested scope" << std::endl;
			std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
			e = sharedEntity; // the ref count is not incremented here because e is a weak pointer
			std::cout << "....exiting nested scope" << std::endl;
			// at scope exit ref count becomes 0 and the Entity gets destroyed
		}
		
		std::cout << "..exiting scope" << std::endl;
	}
	
	std::cin.get();
}
