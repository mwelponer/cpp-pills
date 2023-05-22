#include <iostream>
#include "Something.h"
#include <string>

class Entity
{

private:
	std::string m_name;
	int m_age;

public:
	/* the constructor */
	Entity()
		: m_name("Unknown"), m_age(0) // initializer list are more efficient way
									  // of initializing class members! Always use this style
	{
		// m_name = "Unknown"; // standard way to initialize class members (less efficient!)
		// m_age = 0;

		std::cout << "Entity created - " << this->m_name << std::endl;
	}

	~Entity()
	{
		std::cout << "Entity destroyed! - " << this->m_name << std::endl;
		/* here you clean any memory that you have used*/
	}

	const std::string &getName() const
	{
		return m_name;
	}

	void setName(const std::string &name)
	{
		this->m_name = name;
		std::cout << "name set" << std::endl;
	}
};

/* Player inherits all memeber functions and methods of Entity */
class Player : public Entity
{

private:
	/* by convention use prefix m_ for private member variables
	to distinguish them from local variables */
	int m_x, m_y;
	int m_speed;

public:
	Player() : m_speed(0)
	{
		std::cout << "Player created - " << this->getName() << std::endl;
	}

	~Player()
	{
		/* nothing to be deallocated here
		cause we just have m_speed that is allocated in-place (without a class) */
		std::cout << "Player destroyed! - " << this->getName() << std::endl;
	}

	void move(int x, int y)
	{
		// this->m_x is like to write (*this).m_x;
		this->m_x += x * this->m_speed;
		this->m_y += y * this->m_speed;
	}
};

int main(int argc, char **argv)
{
	//////////////////////////////////
	// allocating on the STACK !!!
	// the destructor ~Player() gets automatically called at the end of the scope!
	{
		Player p;
		p.move(1, -1);

		// check if inheritance works
		std::cout << "get Name: " << p.getName() << std::endl;
		p.setName("mike");
		std::cout << "get Name: " << p.getName() << std::endl;
	}

	std::cout << " " << std::endl;

	//////////////////////////////////
	// allocating on the HEAP !!!
	// I need to manually call the destructor!
	Player *ptr = new Player();
	ptr->setName("pippo");
	ptr->move(1, -1);
	/* the arrow -> means dereference the pointer (*ptr) and then
	I can use the object member */
	Player &player = *ptr;
	player.move(1, -1); // OR (*ptr).move(1, -1);

	delete ptr; // manually call the destructor

	Something s;
	std::cout << "s_value: " << s.s_value << std::endl;
	Something::s_value = 0;
	std::cout << "s_value: " << s.s_value << std::endl;
	Something::s_function();
	std::cout << "s_value: " << s.s_value << std::endl;
}
