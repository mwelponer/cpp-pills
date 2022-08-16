#include "entity.h"

Entity::Entity(const std::string& name)
    : m_name(name)
{
    std::cout << "enity " << this->m_name << " created."<< std::endl;
}

void Entity::setName(const std::string& name){
    this->m_name = name;
}
