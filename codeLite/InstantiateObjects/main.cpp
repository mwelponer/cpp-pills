#include <iostream>
#include <string>

class Entity 
{
private:
	std::string m_name;
public:
	Entity() : m_name("unknown") {}
	const std::string& getName() {
		return m_name;
	}
};

int main() 
{
	// on the stack
	Entity ent;
	std::cout << ent.getName() << std::endl;
	
	// on the heap
	Entity* entity = new Entity();
	std::cout << entity->getName() << std::endl;
	delete entity;
}