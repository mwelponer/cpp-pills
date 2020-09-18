#include <iostream>

/* struct is just a class in which members are public by default whereas in cpp
class members are private by default
struct are there to maintain compatibility with c
struct are used mainly for plain data, like for example definition of a 2dVector */
struct Player {
	int x, y;
	int speed;
	
	void move(int xa, int ya){
		x += xa * speed;
		y += ya * speed;
	}
};

int main(int argc, char **argv)
{
	Player p;
	p.move(1, -1);
	//return 0;
}
