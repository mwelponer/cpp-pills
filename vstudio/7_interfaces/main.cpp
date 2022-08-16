#include <iostream>
#include <string>

/* an interface is a class that consists only of unimplemented methods 
 * - acting as a template - and forces the subclasses to implement them. 
 * Being that an interface has only unimplemented methods, it is not possible to 
 * instantiate it.
 */
class Printable 
{
public:
    virtual std::string getClassName() = 0; /* = 0 makes it a pure virtual function!
    so the method needs to be implemented in a subclass */
};

class Entity : public Printable
{
public:
    std::string getClassName() override { return "Entity";}
    virtual std::string getName() { return "Entity";} /* here the method is virtual
    so it can be overriden in sublasses, but is not pure virtual */
};

class Player : public Entity
{
private:
    std::string m_name;
public:
    Player(const std::string& name)
        : m_name(name) {}
    std::string getClassName() override { return "Player";}
    std::string getName() override { return m_name; }
};

void printClassName(Entity* entity)
{
    std::cout << entity->getClassName() << std::endl;
}

int main()
{
    //Printable* p = new Printable(); //this is not allowed, it's an interface!
    
	Entity* e = new Entity();
    printClassName(e);
    
    Entity* mike = new Player("Mike");
    printClassName(mike);
}
