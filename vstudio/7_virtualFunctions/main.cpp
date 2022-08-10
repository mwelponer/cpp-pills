#include <iostream>
#include <string>

class Entity 
{
public:
    std::string getName(){ return "Entity"; }
};

class Player : public Entity 
{
private:
    std::string m_name;
public:
    Player(const std::string& name) : m_name(name) {}
    std::string getName() { return m_name; }
};

int main() 
{
    Entity* entity = new Player("Mike"); // polimorphism
    std::cout << entity->getName() << std::endl;
    /* if getName() in base class Entity is not declared virtual
     then the printout will be "Entity" */
}
