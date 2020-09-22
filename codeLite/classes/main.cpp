#include <iostream>
#include "Something.h"
#include <string>

class Entity {

private:
	std::string m_name;
	
public:
	Entity() :
		m_name("Unknown")
	{
		std::cout << "entity created" << std::endl;
	}
	
	std::string getName(){
		return m_name;
	}
	
	void setName(const std::string& name){
		this->m_name = name;
		std::cout << "name set" << std::endl;
	}
};

/* Player inherits all memeber functions and methods of Entity */
class Player : public Entity {

private:
	/* by convention use prefix m_ for private member variables
	to distinguish them from local variables */
	int m_x, m_y;
	int m_speed;

public:

	Player() :
		m_speed(0) 
	{
		std::cout << "Player created.." << std::endl;
	}
	
	~Player() {
		/* nothing to be deallocated here
		cause we just have m_speed that is a allocated in-place (without a class) */
		std::cout << "Player destroyed!" << std::endl;
	}

	void move(int x, int y){
		// this->m_x is like to write
        //(*this).m_x;
		this->m_x += x * this->m_speed;
		this->m_y += y * this->m_speed;
	}
};

int main(int argc, char **argv)
{
	//////////////////////////////////
    // allocating on the STACK !!!
	Player p;
	p.move(1, -1);
	
	// check if inheritance works
	std::cout << p.getName() << std::endl;
	p.setName("mike");
	std::cout << p.getName() << std::endl;


	//////////////////////////////////
    // allocating on the HEAP !!!
    Player* ptr = new Player;
    ptr->move(1, -1);
    /* the arrow -> means dereference the pointer (*ptr) and then
    I can use the object member */
    Player& player = *ptr;
    player.move(1, -1); // OR (*ptr).move(1, -1);
    
	delete ptr;
	
	Something s;
	std::cout << s.s_value << std::endl;
	Something::s_value = 0;
	std::cout << s.s_value << std::endl;
	Something::s_function();
	std::cout << s.s_value << std::endl;


	std::cin.get();
	//return 0;
}
