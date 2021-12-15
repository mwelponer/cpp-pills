C++ for dummies
===

## Pointers

Retrieve the **memory address** corresponding to the start of *myVariable*
```c
std::cout << "myVariable mem address: " << &myVariable; 
``` 

Declare & set a **pointer** 
```c
int* myPointer = &myVariable;
```
now *myPointer* points to *myVariable* holds the memory address of *myVariable*

**Dereference** the pointer (***reading***)
```c
anotherVariable = *myPointer;
```
this will assign/writes 3 (the value pointed by *myPointer*) to *anotherVariable*

**Dereference** the pointer (***writing***)
```c
*myPointer = 3;
```
this will assign/writes 3 to the variable pointed by *myPointer*.

Increment the value held by the variable pointed by *myPointer*
```c
(*myPointer)++;
```
first dereference using the *, then increment


## References

Declare & set a **reference**
```c
int& myReference = myVariable;
```
*myReference* now is an alias of *myVariable*.

```c
myReference = 3;
```
assigns/writes 3 to the variable referenced by *myPointer*


## Static keyword

### general use

**Declare** a variable static
```c
static int myVariable = 5;
```
*myVariable* will be visible only in that specific translation unit (file) 

### inside a scope

Inside a function for example, but could be inside a for loop or whatever other type of scope
```c
void myFunction() {
	static int i = 0;
	i++;
}
```
First time we call *myFunction* *i* si declared and set. All other times, just incremented. It's like declaring *i* outside of the scope, but here we also obtain that i can be modified (incremented) only inside *myFunction*.

### use in object oriented

Declaring a field or a method static inside a class/struct
```c

struct Entity {
	static int x;
	int y; 
	void print() { std::cout << x << ", " << y << std::endl;}
	static void s_print() {std::cout << "x:" x << std::endl;}
};
```
*x* will be unique and shared among all the *Entity* instances. 
Non-static methods can access static and non-static variables.
Static methods cannot access non-static variables. 

## Objects and Classes

Example of a **simple class**
```cpp
class Entity {
private:
	std::string m_name;
    int m_age;
public:
	Entity(){} 
	const std::string& getName() const { return m_name;}
	void setName(const std::string& name) {
		this->m_name = name;
	}
};
```
*this->* equals to *(*this).* i.e. dereference pointer and use method/field

### constructor and destructor ~

the *Entity* object will be instantiated and *m_name* and *m_age* fields will be immediately initialized to *Unknown* and *0* in the constructor.

```cpp
Entity {
public:
	/* the constructor */
	Entity() : m_name("Unknown"), m_age(0) {
		std::cout << "Entity created" << std::endl;
	}
	/* the destructor */
	~Entity() {
		/* deallocate here everything created on the 
		heap in the constructor */
		std::cout << "Entity destroyed!" << std::endl;
	}
};
```
the destructor *~Entity* will be called when deleting the *Entity* object. Inside the destructor deallocate with *delete* or *delete[]* everything that was created on the heap memory during the construction

### class inheritance

```cpp
class Player : public Entity {
private:
	int points;
public:
};
```
the sub class Player extends the base class Entity, so Player class contains everything (methods and fields) that Entity class contains. Player just provides more functionalities to the Entity base class. And it can override any Entity class method. 

### virtual functions i.e. methods overriding

```cpp
class Entity {
public:
	virtual std::string getName(){return "Entity";}
};

class Player : public Entity {
private:
	std::string m_Name;
public:
	Player(const std::string& name)
		: m_Name(name){}
	std::string getName() override {return m_Name;}
};

int main() {
	Player* p = new Player("Mike");
	Entity* entity = p;
	entity->getName(); /* if Entity::getName() 
	is not virtual, this will output "Entity" */
}
```
If any sub class overwrites a method, it's good to make that method ***virtual*** in the base class. And to mark with ***override***  the method in the derived class. 

### interfaces
you are using an interface class when you want to guarantee that the subclasses extending that interface have specific methods
```cpp
class Printable {
public:
    virtual std::string getClassName() = 0;
};
```
``= 0`` makes it a pure virtual function! so the method needs to be implemented in the subclasses. *Printable* being an interface, cannot be instantiated.


### visibility

```cpp
class Entity {
private:
	int x, y;
protected:
	std::string name;
public: 
	getCoordinates(){};
};
```

in general all that goes under **public** can be seen from outside and inside the class, all that goes under **private** can only be seen within the class itself. All that goes under **protected** can be seen from within the class itself and the subclasses.

```cpp
class Entity {
//private:
	int x, y; /* private by default */
};
```
in classes if I don't specify the visibility, it will be private by default, so like to write *private:* before the declaration of the methods/fileds

```c
struct Entity {
//public:
	int x, y; /* public by default */
};
```

in structs if I don't specify the visibility, it will be public by default, so like to write *public:* before the declaration of the methods/fileds. 

**FUN FACT**: actually this is the unique difference between class and struct. In c++ struct remain just to maintain the compatibility with c that doesn't have class.

## Arrays 

### arrays on the stack memory
```c
int stackArr[10];
stackArr[3] = 666;
```
an array is just a pointer to the first element of the array so we can write
```c
int* ptr = stackArr;
*(ptr+3) = 666; /* this equals to 
stackArr[3] = 666; */
```
``*(ptr+3)`` means first increment by 3 the pointer, then dereference it 

**FUN FACT**: in release mode if you read/write out of the array space nobody will complain (no bounds checking, you will be reading/writing where you are not supposed to!). So it is better to write some check code to avoid the situation.
**FUN FACT**: the row arrays do not have any *.size* or *.lenght* operators so: 
1. if you declare the array in the stack use this trick:
```c
lenght = sizeof(stackArr) / sizeof(int);
```
2. if you declare the array in the heap just do:
```c
static const int numOfElements = 10;
int* heapArr = new[numOfElements];
```

### arrays on the heap memory

```c
int* heapArr = new int[10];
delete[] heapArr;
```

Why should you declare an array on the heap? The difference is lifetime: creating something in the stack will be destroyed as soon as out of the scope. In the heap it will persist until deleted. 
**E.g.** if you have a function returning an array for example, you have to use the new keyword!

In general it is better - whenever possible - to declare the arrays in the stack to avoid all the pointer jumping to get to the actual data. Example:

```cpp
Entity {
public:
	int stackArr[10];
	/* if instead here I use an array on the heap 
	int heapArr = new[10]; my Entity will contain 
	a pointer to the array so to get the data it 
	will need to jump to another space in memory */
	Entity {
		for (int i=0; i<10; i++)
			stackArr[i] = 0;
	}
};
```

### array from the c++ standard library v11
 
```c
#include <array>
std::array<int, 10> stdArr;
std::cout << stdArr.size() << std::endl;
```
it includes bounds checking and it keeps track of the array size. But of course there is a bit of overhead.

## Strings

### manual declaration
A string is just an array of characters. If we want to declare it completely *manually* we need to add the string termination char (``0`` or ``'\0'``) that tells the pointer that the string is terminated.

```c++
char mystring[5] = {'M', 'i', 'k', 'e', 0};
std::cout << mystring << std::endl;
```

### declaration via char pointer
Declaration of a string using a *char pointer* in c++ it is immutable in the sense that you cannot change the lenght of the string, so usually it is declared ``const``

```c++
const char* name = "Mike";
std::cout << name << ", " << strlen(name) << std::endl;

char* str1 = "Ciao";
char str2[40];
strcpy(str2, str1); // copy str1 into str2 
```

### string from the c++ standard library
Finally if we want to use the *standard string* implementation. ``#include <string.h>`` is used just to overload the ``<<`` operator for the cout 

```c++
std::string myString = "ciao";
myString += "!";
std::cout << myString << std::endl;
	
/* useful string methods */
myString.size();
myString.find("ao");
bool contains = myString.find("c") != std::string::npos;
```


## Const

### normal use

```c
const int MAX_AGE = 90;
```
normal use of const: the 'variable' MAX_AGE becomes basically a constant, it is not supposed to be modified.

### with pointers

const BEFORE the asterix: what the pointer points at can't be modfied

```c++
const int* a = new int; // i.e.: int const* a
// *a = 5; // I cannot modify what the pointer points at!
```

const AFTER the asterix: the pointer address can't be modified

```c
int* const b = new int;
*b = 5; // I still can modify what the pointer points at
//b = &MAX_AGE; // but I cannot modify the pointer address
```

and of ourse: const BEFORE & AFTER the asterix: the pointer address and what it points at cannot be modified

```c
const int* const c = new int;
//*b = 5; // I cannot modify what the pointer points at
//b = &MAX_AGE; // I cannot modify the pointer address
```

### with classes

```c++
class Entity {
private:
	int m_X, m_Y;
	int* age;
public:
	/* used by a non-const Entity or Entity reference/pointer */
	int getX() {
		m_X = 2; // this is allowed
		return m_X;
	}

	/* This method will be used by a const Entity reference */
	/* const here means I cannot modify the field inside the method */
	int getX() const {
		//m_X = 2; // this is not allowed
		return m_X;
	}
};
```
if an Entity is used as parameter in some function, passed by *const reference* (not to copy all the class object) the normal *getX()* will not work. We need to create another method *getX() const* that will work (promising that the field inside the method will not be modified).
