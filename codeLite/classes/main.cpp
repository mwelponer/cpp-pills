#include <iostream>
#include "Something.h"

class Player {

private:
	/* by convention use prefix m_ for private member variables
	to distinguish them from local variables */
	int m_x, m_y;
	int m_speed;

public:

	Player() : m_speed(0) {}

	void move(int x, int y){
		// this->m_x is like to write (*Player).m_x 
		this->m_x += x * this->m_speed;
		this->m_y += y * this->m_speed;
	}
};

int main(int argc, char **argv)
{
	Player p;
	p.move(1, -1);

	Something s;
	std::cout << s.s_value << std::endl;
	Something::s_value = 0;
	std::cout << s.s_value << std::endl;
	Something::s_function();
	std::cout << s.s_value << std::endl;

	//return 0;
}
