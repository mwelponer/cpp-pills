#include <iostream>

class Entity
{
private:
    std::string m_name;

public:
    Entity(const std::string& name);
    void setName(const std::string& name);
    const std::string& getName(){return m_name;};
};