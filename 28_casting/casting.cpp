#include <iostream>

class Base {
public: 
	Base() {} 
	virtual ~Base() {} // here it is important to specify virtual otherwise dcast will not work!
};
class Derived : public Base {
public:
	Derived() {}
	~Derived() {}
};
class AnotherClass : public Base {
public:
	AnotherClass() {}
	~AnotherClass() {}	
};

int main() {

    // C style cast
    double value = 5.32;
    std::cout << "value: " << value << std::endl;

    int a = value; // implicit conversion
    std::cout << "a: " << a << std::endl;

    double b = (int)value + 5.25; // explicit conversion    
    std::cout << "b: " << b << std::endl;


    // C++ style casting, static casting
    double c = static_cast<int>(value) + 5.25;
    std::cout << "c: " << c << std::endl;
    // it does a compile time check and may return NULL if the conversion 
    // doesn't succed


    // DYNAMIC CAST
    Derived* derived = new Derived();
    Base* base = derived; 
    // suppose we don't know that base specialized to Derived

    AnotherClass* ac1 = dynamic_cast<AnotherClass*>(base);
    // will check if base specialized to AnotherClass, 
    // if not it will return NULL, so we can check the type by writing 
    std::cout << ((ac1 == NULL) ? "ac1 is NULL" : "ac1, conversion done.") << std::endl;

    AnotherClass* ac2 = static_cast<AnotherClass*>(base); // this will do the conversion
    std::cout << ((ac2 == NULL) ? "ac2 is NULL" : "ac2, conversion done.") << std::endl;

    // so we can use dynamic cast to check if an object is of a specific type.
    // NB: remember to mark the Base distructor as virtual!
}