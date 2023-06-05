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
	int* a = new int;
	int* aArr = new int[50]; 
	
	Entity* e = new Entity();
	Entity* another_e = (Entity*)malloc(sizeof(Entity)); // this is the equivalent c version
	// BUT the second will just allocate the memory and not call the constructor!
	
	Entity* eArr = new Entity[50];	
	
	// remember to free the memory when you are done with it!
	delete a, e, another_e;
	delete[] aArr, eArr;
}
