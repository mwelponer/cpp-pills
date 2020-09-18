#include <iostream>

struct Entity {

	int x, y;
	/* if we declare static, we declare there is only one instance of these two 
	 * variables across all the instances of our entity class */ 
	static int z, t; 
	
	void printxy() {
		std::cout << x << ", " << y << std::endl;
	}
	
	// static methods cannot access non static variables 
	static void printzt() {
		std::cout << z << ", " << t << std::endl;
	}
	
	
};

int Entity::z;
int Entity::t;

int main(int argc, char **argv)
{
	Entity e;
	e.x = 2;
	e.y = 3;
	
	Entity e1 = {5, 8};
	
	e.printxy();
	e1.printxy();
	
	
	// let's try to use static variables too
	e.z = 0;
	e.t = 0;
	
	e1.z = 1;
	e1.t = 1;
	/* we can also refer them to in this way, cause being static, they are not 
	 * really part of the class/struct but simply inside a namespace called Entity */
	Entity::z = 1;
	Entity::t = 1;
	// this also apples to methods so instead of writing
	e.printzt();
	e1.printzt(); 
	// we better write
	Entity::printzt();
	
	//return 0;
}
