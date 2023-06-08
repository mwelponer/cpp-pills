#include <iostream>

class Base {
public:
    Base() { std::cout << "Base created" << std::endl; }
    ~Base() { std::cout << "Base destroyed" << std::endl; }
};

class Derived : public Base {
public: 
    Derived() { std::cout << "Derived created" << std::endl; }
    ~Derived() { std::cout << "Derived destroyed" << std::endl; }
};

class CorrectBase {
public:
    CorrectBase() { std::cout << "CorrectBase created" << std::endl; }
    // simply put virtual to avoid memory leaks 
    virtual ~CorrectBase() { std::cout << "CorrectBase destroyed" << std::endl; }
};

class AnotherDerived : public CorrectBase {
public: 
    AnotherDerived() { std::cout << "AnotherDerived created" << std::endl; }
    ~AnotherDerived() { std::cout << "AnotherDerived destroyed" << std::endl; }
};

int main() {
    std::cout << "1" << std::endl;
    Derived* der = new Derived(); 
    delete der; // everything gets destroyed well

    std::cout << "2" << std::endl;
    Base* bas = new Derived();
    delete bas; // Derived is not destroyed! memory leak !!!!!

    std::cout << "3" << std::endl;
    CorrectBase* cbas = new AnotherDerived();
    delete cbas; // Derived is not destroyed! memory leak !!!!!
}