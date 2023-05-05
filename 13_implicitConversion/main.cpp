#include <iostream>
#include <string>

class Entity 
{
private:
	std::string m_name;
	int m_age;
	float m_height;
public:
	Entity(const std::string& name) 
		: m_name(name), m_age(-1) {}
		
	Entity(int age) 
		: m_name("unknown"), m_age(age) {}

	explicit Entity(float height)
		: m_name("unknown"), m_height(height) {}

	std::string getName() const 
	{ 
		return this->m_name;
	}
};

void static PrintEntity(const Entity& entity)
{ 
	// some cool printing
	std::cout << "entity: " << entity.getName() << std::endl;
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
	// c++ does the implicit conversion automagically only if there is not 
	// more than 1 conversion to do between the two types
	PrintEntity(22); 
	
	// implicit conversion: "Cherno" was firstly casted from 
	// a const char array to a std string then implicitly converted 
	// into an Entity with name Cherno
	PrintEntity(std::string("Cherno"));
	// or either
	PrintEntity(Entity("Cherno"));


	// explicit keyword in front of the contructor deisable any form of implicit conversion
	float height = 172.5f;
	Entity another_c = height;
	PrintEntity(another_c);
}
