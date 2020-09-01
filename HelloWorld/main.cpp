//
//  main.cpp
//  HelloWorld
//
//  Created by Mike on 30/08/2020.
//  Copyright © 2020 Mike. All rights reserved.
//

#include <iostream>

class Entity {
public:
    virtual std::string getName() { return "Entity"; }
    
    ~Entity() { std::cout << "Entity Destructor" << std::endl; }
};

class Player : public Entity {
private:
    std::string m_Name;
    int m_age;
    
public:
    Player(const std::string& name, int age)
        : m_Name(name), m_age(age) {}
    
    ~Player() { std::cout << "Player Destructor" << std::endl; }
    
    std::string getName() { return m_Name; }
};

void printName(Entity* entity)
{
    std::cout << entity->getName() << std::endl;
}

int main()
{
    std::cout << "Hello, World!" << std::endl;
    
    Entity e0;
    std::cout << e0.getName() << std::endl;
    
    Entity* e = new Entity();
    printName(e);
    
    Player* p = new Player("Michele", 43);
    printName(p);
    
    std::cin.get();
}
