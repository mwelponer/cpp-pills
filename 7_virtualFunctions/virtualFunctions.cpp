#include <iostream>
#include <string>

class Entity 
{
public:
    virtual std::string getName(){ return "Entity"; }
};

class Player : public Entity 
{
private:
    std::string m_name;
public:
    Player(const std::string& name) : m_name(name) {}
    std::string getName() override { return m_name; }
};

int main() 
{
    Entity* entity = new Player("Mike"); // polimorphism
    std::cout << entity->getName() << std::endl;
    /* if getName() in base class Entity is not declared virtual
     and the getName in Player is not declared to override
     then the printout will be "Entity" */

    // same here
    Player* pla = new Player("Mike");
	Entity* ent = pla;
    std::cout << ent->getName() << std::endl;

}
