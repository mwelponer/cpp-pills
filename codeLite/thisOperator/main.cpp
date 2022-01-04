#include <iostream>

class Entity;
// the declaration of our fancy printing function
void printEntity(Entity* e);

class Entity 
{
private:
	int x, y;
	
public:	
	Entity(int x, int y)
		/*: x(x), y(y) */
	{
		// this is a pointer so using -> we first dereference 
		// then we use the x or y variable
		this->x = x; 
		this->y = y;
		
		printEntity(this);
	}
};

void printEntity(Entity* e)
{
	std::cout << "passo" << std::endl;
}


int main()
{
	Entity entity = Entity(2, 5);
}
