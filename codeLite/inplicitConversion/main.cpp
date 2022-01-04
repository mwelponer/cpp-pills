#include <iostream>
#include <string>

class Entity 
{
private:
	std::string m_name;
	int m_age;
public:
	Entity(const std::string& name) 
		: m_name(name), m_age(-1) {}
		
	Entity(int age) 
		: m_name("unknown"), m_age(age) {}
};

void PrintEntity(const Entity& entity) 
{ 
	// some cool printing 
}

int main()
{
	Entity a("Mike");
	Entity b(43); 
	// these are equivalent to 
	Entity another_a = std::string("Mike");
	Entity another_b = 43;
	
	// implicit conversion: 22 was implicitly converted into 
	// an Entity with age 22
	PrintEntity(22); 
	
	// implicit conversion: "Cherno" was firstly casted from 
	// a const char array to a std string then implicitly converted 
	// into an Entity with name Cherno
	PrintEntity(std::string("Cherno"));
	// or either
	PrintEntity(Entity("Cherno"));
}
