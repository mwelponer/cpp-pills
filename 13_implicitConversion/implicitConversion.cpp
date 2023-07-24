#include <iostream>
#include <string>
#include <vector>

class Entity 
{
private:
	std::string m_name;
	int m_age;
	std::vector<int> m_vector;

public:
	Entity(const std::string& name) 
		: m_name(name), m_age(-1) {}
		
	Entity(int age) 
		: m_name("unknown"), m_age(age) {}

	explicit Entity(std::vector<int>& vector)
		: m_name("unknown"), m_vector(vector) {}

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
	//Entity another_b = 43;
	
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


	// explicit keyword in front of the contructor disable any form of implicit conversion
	std::vector<int> vector = {1, 2, 3};

	// this will give compilation error !!!
	// PrintEntity(vector); 

	// we need to explicitly say
	Entity another_c(vector);
	PrintEntity(another_c);
	// or directly
	PrintEntity(Entity(vector));
}
