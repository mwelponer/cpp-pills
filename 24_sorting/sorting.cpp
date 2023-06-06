#include <iostream>
#include <vector>
#include <algorithm> // to use std::sort
#include <functional> // to use std::greater

class Entity {
private: 
    int m_age;
    std::string m_name;
public:
    Entity(const std::string& name, int age) :
        m_name(name), m_age(age) {}
    int getAge() { return m_age; }
    const std::string& getName() const { return m_name; }
};

int main() {
    std::vector<int> values = { 3, 5, 1, 4, 2 };
 
    // default sorting
    std::sort(values.begin(), values.end()); // ascending order by default
    for (int v : values)
        std::cout << v << ", ";
    std::cout << "\n";

    // using a function
    std::sort(values.begin(), values.end(), std::greater<int> ()); // strunct or lambda
    for (int v : values)
        std::cout << v << ", ";
    std::cout << "\n";

    // using a lambda
    std::sort(values.begin(), values.end(), [](int a, int b){ return a < b; });
    for (int v : values)
        std::cout << v << ", ";
    std::cout << "\n";


    // ordering objects using a lambda
    Entity e1("mike", 44);
    Entity e2("roby", 34);
    std::vector<Entity> ents = {e1, e2};
    std::sort(ents.begin(), ents.end(), [](Entity e1, Entity e2) { return e1.getAge() < e2.getAge(); });

    for (Entity e : ents)
        std::cout << e.getName() << ", ";
    std::cout << std::endl;
}
