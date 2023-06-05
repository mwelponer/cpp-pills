C++ pills
===
Copyright (C) 2021 Michele Welponer

- [Pointers](#pointers)
  * [dereference a variable](#dereference-a-variable)
  * [declare a pointer](#declare-a-pointer)
  * [set a pointer](#set-a-pointer)
  * [dereference a pointer](#dereference-a-pointer)
  * [pointer arithmetic](#pointer-arithmetic)
- [References](#references)
  * [Passing by reference](#passing-by-reference)
  * [reasuming](#reasuming)
- [Static keyword](#static-keyword)
  * [general use](#general-use)
  * [inside a scope](#inside-a-scope)
  * [use in object oriented](#use-in-object-oriented)
  * [another good example of static inside a scope](#another-good-example-of-static-inside-a-scope)
- [Enums](#enums)
- [Objects and Classes](#objects-and-classes)
  * [constructor and destructor](#constructor-and-destructor)
  * [class inheritance](#class-inheritance)
  * [virtual functions for methods overriding](#virtual-functions-for-methods-overriding)
  * [interfaces](#interfaces)
  * [visibility](#visibility)
  * [class header](#class-header)
- [Arrays](#arrays)
  * [arrays on the stack memory](#arrays-on-the-stack-memory)
  * [arrays on the heap memory](#arrays-on-the-heap-memory)
  * [array standard library](#array-standard-library)
  * [reasuming](#reasuming-1)
- [Strings](#strings)
  * [manual declaration](#manual-declaration)
  * [declaration via char pointer](#declaration-via-char-pointer)
  * [string standard library](#string-standard-library)
- [Const](#const)
  * [normal use](#normal-use)
  * [with pointers](#with-pointers)
  * [with classes](#with-classes)
- [The ternary operator](#the-ternary-operator)
- [Instantiate classes and objects](#instantiate-classes-and-objects)
  * [Stack Heap memory allocation](#stack-heap-memory-allocation)
  * [the new keyword](#the-new-keyword)
- [Implicit conversion](#implicit-conversion)
- [Operator overloading](#operator-overloading)
- [The this keyword](#the-this-keyword)
- [Smartpointers](#smartpointers)
  * [1. unique pointers](#1-unique-pointers)
  * [2. shared pointers](#2-shared-pointers)
  * [3. weak pointers](#3-weak-pointers)
- [The copy constructor](#the-copy-constructor)
- [The arrow operator](#the-arrow-operator)
- [Dynamic arrays](#dynamic-arrays)
  * [Optimizations](#optimizations)
- [Static and Dynamic libraries](#static-and-dynamic-libraries)
  * [static linking](#static-linking)
  * [dynamic libraries](#dynamic-libraries)
- [Templates](#templates)
- [Macros](#macros)
- [Namespace](#namespace)
- [Function pointers](#function-pointers)
- [Lambdas](#lambdas)
- [Multidimensional arrays](#multidimensional-arrays)
- [Sorting](#sorting-std-sort)
- [Type punning](#type-punning)
- [Union](#union)
- [Virtual Destructors](#virtual-destructors)
- [Casting](#casting)
  * [static cast](#static-cast)
  * [dynamic cast](#dynamic-cast) 
- [Singleton](#singleton)

<small><i><a href='http://ecotrust-canada.github.io/markdown-toc/'>Table of contents generated with markdown-toc</a></i></small>


## Pointers

Pointers hold an integer that is a memory address! We say then a pointer points to a location in memory: that location is the starting location of a memory space (whose lenght is defined by the type).
How to retrieve the memory address of a variable?
Retrieve the **memory address** corresponding to the start of *myVariable* dereferencing that variable using & in front of the variable name.

### dereference a variable

dereferencing a variable gives you the **memory address** at which that variable is stored. It is done by putting a **&** in front of the variable

```c
std::cout << "myVariable mem address: " << &myVariable; 
``` 

### declare a pointer

Declare a **pointer** using * right after its type:
```c
int* myPointer;
```

### set a pointer

```c
int a = 3;
myPointer = &a;
```
now *myPointer* points to *a* and holds the memory address of *a*

### dereference a pointer

dereferencing a pointer gives you the value contained at the memory address pointed by the pointer. It is done by putting a * in front of the pointer

**Dereference** the pointer (***reading***)
```c
b = *myPointer;
```
this will assign/writes 3 (the value pointed by *myPointer*) to *b*

**Dereference** the pointer (***writing***)
```c
*myPointer = 6;
```
this will assign/writes 6 to the variable pointed by *myPointer* i.e. *a*.

Increment the value held by the variable pointed by *myPointer*
```c
(*myPointer)++;
```
first dereference using the *, then increment


### pointer arithmetic

code|meaning
-|-
++*p|take data, increment data, return data
*++p|move pointer to next, read data, return data
*p++|read data, return data, move p to next
(*p)++|take data, increment data, return data


## References

References are like Pointers but less powerful. Reference are just syntax sugar, whatever you can do with references you can also do it using pointers.
Declare and set a **reference**. & is part of the type
```c
int& myRef1 = myVar; // myRef1 now is an alias of myVar
int& myRef2 = *myPtr; // myRef2 now is an alias of the variable pointed by myPtr*
myRef2 = 3; // assigns/writes 3 to the variable referenced by myPtr
```


### Passing by reference

If we want to write a function that increments a variable, we can pass that variable inside the function using a pointer, or more concisely using a reference (i.e. **by reference**)

```c++
// using a pointer: int* value means create a new pointer named
// value which points to the memory address we pass as argument
// so if we want to increment the variable we need to first 
// de-reference the pointer to get the variable and then increment
void  incrementUsingPointer(int* value) {
	(*value)++; // dereference first then increment
    std::cout << "value:" << *value << std::endl;
}

// more simply, by reference: int& value means create a
// reference (alias) named value and make it point exactly 
// to the same variable we pass
void  incrementUsingReference(int& value){
	value++;
	std::cout << "value:" << value << std::endl;
}

int main(){
	int a = 5;
	incrementUsingPointer(&a);
	incrementUsingReference(a);

	// and with classes
	Entity e1; // instance on the stack
	incrementUsingPointer(&e1);
	incrementUsingReference(e1);
	
	Entity* e2 = new Entity(); // instance on the heap
	incrementUsingPointer(e2);
	incrementUsingReference(*e2);
}
```

***NB***: if we don't pass the variable by reference or by pointer to the function and we simply use ``increment(int value)`` a new ``int value`` variable will be created, initialized and incremented inside the function, but the external variable (the one we pass to the function won't be modified!)

### reasuming

code | meaning
-|-
T* p | declare pointer p of type T
T& r | declare reference r of type T
*p | dereference pointer p i.e. get the data/variable/object pointed by p
&v | dereference variable v i.e. get the memory address of v


Examples:
```c
int a = 3; // declare a variable
int* ptr = nullptr; // declare a pointer
ptr = &a; // dereference the variable to get the address and set the pointer point to the variable
std::cout << *ptr << std::endl; // dereference the pointer to get the data, 3

int& ref = *ptr; // create a reference i.e. alias of what the pointer points, i.e. variable a
std::cout << ref << std::endl; // prints 3

ref++; // increment using the reference
std::cout << a << *ptr << ref << std::endl; // 444

a++; // increment the variable a
std::cout << a << *ptr << ref << std::endl; // 555

(*ptr)++; // dereference first to get the data, then increment it 
std::cout << a << *ptr << ref << std::endl; // 666
```

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
First time we call *myFunction* `i` si declared and set. All other times, just incremented. It's like declaring `i` globally outside of the function, but declaring it inside a function we also guarantee that *i* can be modified only inside the function.

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

### another good example of static inside a scope

let's create a **Singleton**. We declare the private static instance globally, then we need a method to get() that instance.

```c++
class Singleton {
private:
	static Singleton* s_instance; // global declaration
public:
	static Singleton& get() {return *s_instance;}
	void hello() {}
};

Singleton* Singleton::s_instance = nullptr;

int main() {
	Singleton::get().hello();
}
```

we can write a most clean Singleton declaring the instance static inside a scope, e.g. inside the get function

```c++
class Singleton {
public:
	static Singleton& get() {
		static Singleton instance; // declaring inside the scope
		return instance;
	}
	void hello() {}
}

int main() {
	Singleton::get().hello();
}
```

## Enums

Stands for enumeration, a set of values. It's a way to give a name to an integer value so the code becomes more readable.

```cpp
enum Example /* optionally specify the type of integer */: unsigned char {
	A, B, C // A will be 0, B and C 1 and 2
	// A = 4, B, C // B and C will be 5 and 6
	// A = 5, B = 3, C = 7
};

class Log(){
public:
	enum Level {
		Error, Warning, Info
	};
private:
	Level m_logLevel = Info;
public:
	void setLevel(Level level){ m_logLevel = level;}
};

int main(){
	Example value = B;
	Log log;
	log.setLevel(Log::Error);
}
```

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
``NB``: *this* is the current object pointer, *->* means dereference the pointer and then use the . to access the member method/field.

### constructor and destructor

the *Entity* object will be instantiated and *m_name* and *m_age* fields will be immediately initialized to *Unknown* and *0* in the constructor.

```cpp
class Entity {
public:
	/* the constructor */
	Entity() 
		: m_name("Unknown"), m_age(0) // initializer list more efficient!
	{
		// standard way to initialize class members (less efficient!)
		//m_name = "Unknown"; 
		//m_age = 0;		
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
the destructor *~Entity* will be called when the *Entity* object gets deleted. Inside the destructor deallocate everything that was created on the heap memory during the construction.
***NB***: if the object was created on the heap (using new operator) we need to call manually the destructor using "*delete*" or "*delete[]*" for arrays. If the object was created on the stack, the destructor will be automatically called when the program gets out of scope.

### class inheritance

```cpp
class Player : public Entity {
private:
	int points;
public:
};
```
the sub class Player extends the base class Entity, so Player class contains everything (methods and fields) that Entity class contains. Player just provides more functionalities to the Entity base class. And it can override any Entity class method. 

### virtual functions for methods overriding

Virtual functions allow us to override methods in sub-classes.

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
	// OR using polimorphism
	Entity*  entity  =  new  Player("Mike"); // polimorphism
	
	/* if Entity::getName() 
	is not virtual, this will output "Entity" */
	std::cout  <<  entity->getName() << std::endl;
}
```
If any sub class overwrites a method, it's good to make that method ***virtual*** in the base class. And to mark with ***override***  the method in the derived class. 
If *getName()* in base class *Entity* is not declared *virtual*then the printout will be *Entity*.

### interfaces
Interfaces (a.k.a. abstract methods or pure virtual functions) allow us to define a function in a base-class that does not have an implementation, and at the same time force the sub-classes to implement that function. 
You are using an interface class when you want to guarantee that the subclasses extending that interface have specific methods
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

***FUN FACT***: actually this is the unique difference between class and struct. In c++ struct remain just to maintain the compatibility with c that doesn't have class.


### class header

example of a class Human that extends from LivingBeing

***Everything inside *Human.h****

```cpp
class Human : public LivingBeing {
private:
    std::string m_name;
    int m_age;
    Human* m_son;
public:
    Human() 
	    :m_name("unknown"), m_age(0){}
    Human(const std::string& name, const int age)
        :m_name(name), m_age(age){}
    Human(const std::string& name, const int age, Human* son)
        :m_name(name), m_age(age), m_son(son{}
    ~Human(){
		if (this->m_son)
			delete son;
    }
        
    void print(){
        std::cout << "Human " << this->m_name << ", age " << this->m_age << std::endl;
    }
    
    int age(){ return this->m_age; }
	Human* son(){ return this->m_son; }
};
```

If we want to separate the file into .h and .cpp then it becomes:

***Human.h***
```cpp
#pragma once
#include <string>

namespace myNamespace {
	class Human : public LivingBeing {
	private:
		std::string m_name;
	    int m_age;
	    Human* m_son;
	public:
	    Human();
	    Human(const std::string& name, const int age);
	    Human(const std::string& name, const int age, Human* son);
		~Human();
	    void print();
	    int age();
	}
}
```

***Human.cpp***

```cpp
#include "Human.h"

namespace myNamespace {
    Human::Human()
	    : m_name("unknown"), m_age(0){}
    Human::Human(const std::string& name, const int age)
	    :m_name(name), m_age(age){}
    Human::Human(const std::string& name, const int age, Human* son)
	    :m_name(name), m_age(age), m_son(son{}
	Human::~Human(){
		if (m_son)
			delete son;
	}
	    	    
    void print(){
	    std::cout << "Human " << this->m_name << ", age " << this->m_age << std::endl;
    }
    
    int age(){ return this->m_age; }
}
```

## Arrays 

### arrays on the stack memory
```c
int stackArr[10]; // now stackArr is already a pointer!
stackArr[3] = 666;
```
an array is just a pointer to the first element of the array so we can write
```c
int* ptr = stackArr;
*(ptr+3) = 666; /* this equals to stackArr[3] = 666; */
```
``*(ptr+3)`` means first increment by 3 the pointer, then dereference it 

***FUN FACT***: in release mode if you read/write out of the array space nobody will complain (no bounds checking, you will be reading/writing where you are not supposed to!). So it is better to write some check code to avoid the situation.
***FUN FACT***: the row arrays do not have any *.size* or *.lenght* operators so: 

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

### array standard library
 
```c
#include <array>
std::array<int, 10> stdArr;
std::cout << stdArr.size() << std::endl;
```
it includes bounds checking and it keeps track of the array size. But of course there is a bit of overhead.

### reasuming

code | meaning
-|-
T ar[n] | declare array ar of n elements of type T
&ar[0] |the memory address of the first element of ar
&ar | the memory address of the first element of ar
ar | the memory address of the first element of ar
T* p = ar | create pointer p that points to the first element of array ar
*(ar + 1) | get the second element of array ar
ar[1] | get the second element of array ar
T* ha = new T[n] | declare on the heap array ha of n elements of type T 
delete[] ha | delete/remove array ha from the heap


## Strings

### manual declaration
A string is just an array of characters. If we want to declare it completely *manually* we need to add the string termination char (``0`` or ``'\0'``) that tells the pointer that the string is terminated.

```c++
char mystring[5] = {'M', 'i', 'k', 'e', 0};
std::cout << mystring << std::endl;
```

### declaration via char pointer
Declaration of a string using a *char pointer* in c++ it is immutable in the sense that you cannot change the lenght of the string, so usually it is declared ``const``. ``#include <string.h>`` is used just to overload the ``<<`` operator for the cout, *strlen* and *strcpy*

```c++
#include <string.h>
const char* name = "Mike";
std::cout << name << ", " << strlen(name) << std::endl;

char* str1 = "Ciao";
char str2[40];
strcpy(str2, str1); // copy str1 into str2 
```

### string standard library
Finally if we want to use the *standard string* implementation. 

```c++
std::string myString = "ciao";
myString += "!";
std::cout << myString << std::endl;
	
/* useful string methods */
myString.size();
myString.find("ao");
bool contains = myString.find("c") != std::string::npos; // std::string::npos means the end of the string
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

Why declaring method const? Non-const objects can call either const or non-const methods. If I declare a const object like entity or a reference, then I will be able to call only on those const methods.
``RULE``: *const objects can not call non-const functions*

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
if an Entity is used as parameter in some function, passed by *const reference* (not to copy all the class object) the normal *getX()* will not work. We need to create another method *getX() const* that will work (promising that inside the const method I don't modify the field). 

***FUN FACT***: if I declare the class field as ***MUTABLE*** i can still modify it's value inside the const method! :P

```c++
class Entity {
private: 
	int m_X;
	mutable int m_debugCount = 0;

	int getX() const {
		m_debugCount++; // allowed because the filed is mutable!
		m_X = 3; // not allowed because the method is const!
		return m_X;
	}	
}
```

## The ternary operator

.. just a syntactic sugar for if else

```c
static int s_level = 1;
static int s_speed = 2;

void printSpeed() {
	s_speed = s_level > 3 ? 10 : 5; // speed becomes 10 if lev>3 else 5
	std::cout << "s_speen: " << s_speed << std::endl;
}

int main() {		
	printSpeed();
	s_level = 7;
	printSpeed();
}
```

## Instantiate classes and objects

```c++
#include <iostream>
#include <string>

class Entity 
{
private:
	std::string m_name;
public:
	Entity()
		: m_name("Unknown"), m_age(-1) {}
	Entity(const std::string&  name)
		: m_name(name), m_age(-1) {}
	Entity(const  int  age)
		: m_age(age), m_name("Unknown") {}
		
	std::string& getName() const { return m_name; }
	int getAge() const {return  m_age;}	
	void setName(const std::string& name) {m_name = name;}
	void setAge(const int age) {m_age = age;}
};
```

### Stack Heap memory allocation

**stack allocation** : as soon as that variable gets out of scope the memory is freed. When that scope ends - whichever scope - the stack pops off and anything was inside gets lost. Data is stored in contiguous way, stack memory is limited but very fast.

```c++
int value = 4;
int array[] = {1, 2, 3, 4, 5};
Entity entity("Mike"); // equals to Entity entity = Entity("Mike");
```

**heap allocation**: when allocated an object inside the heap, it's gonna sit there untill you decide I no longer need it, I will free it.

```c++
int* hvalue = new int;
*hvalue = 4;
int* harray = new int[5];
array[0] = 1;
array[1] = 2;
array[2] = 3;
Entity* hentity = new Entity("Mike");
// free the allocated memory on the heap!
delete hvalue;
delete[] harray;
delete hentity;
```

Allocating on the heap takes longer: when we write "**new** *dataType*" we require the compiler to find and allocate a dataType long free and contiguous space in heap memory and return a pointer to that memory address (i.e. malloc function). Allocation on the heap is indeed a very heavy task, compared to the allocation on the stack that just needs 1 cpu instruction. Moreover, when allocating on the heap, we need then to remember to manually free the allocated memory. So the rule of thumb is ***whenever possible instantiate on the stack otherwise on the heap***. 
It can be impossible to use stack memory when for example:
1. the object is inside a scope and needs to remain alive also outside of that scope, or when 
2. the object is too big to stay on the stack (stack is usually 1-2MB) or 
3. there are too many objects that need to be allocated.

``NB``: So, whenever we use the word **new**, we need then to delete!

### the new keyword

The main purpose of ***new*** is to allocate memory on the **heap** specifically.
When we write "new dataType" we require the compiler to find and allocate a dataType long free and contiguous space in heap memory and return a pointer to that memory address -- basically it finds a block of memory that is big enough to accomodate our needs and then gives us a pointer to that block of memory --
The last thing that new does is also call the *constructor* on the new allocated entity.


```c++
int main(){
	int* a = new int;
	int* aArr = new int[50]; // an array of 50 contiguous int on the heap
	
	Entity* e = new Entity();
	
	// this is the equivalent c version
	Entity* another_e = (Entity*)malloc(sizeof(Entity));
	// it will just allocate the memory and not call the constructor!
	
	Entity* eArr = new Entity[50];

	// remember to free the memory when you are done with it!
	delete a, e, another_e;
	delete[] aArr, eArr;
}
```

## Implicit conversion

is the automatic conversion that c++ does from one type to another, see the following examples

```c++
// some cool printing function
void PrintEntity(const Entity& entity) { // cool printing }

int main()
{
	Entity a("Mike"); 
	// we can also write Entity a = std::string("Mike")
	
	Entity b(43); // we can also write b = 43
	
	// implicit conversion
	PrintEntity(22); 
	// 22 was implicitly converted into an Entity with age 22
	
	// implicit conversion: "Cherno" is firstly casted from 
	// const char array to a std::string then implicitly converted 
	// into an Entity with name Cherno
	PrintEntity(std::string("Cherno"));
	// it can be casted also to Entity
	PrintEntity(Entity("Cherno"));
}

```



## Operator overloading

``+``  ``-``  ``*``  ``/``  ``%``  ``^``  ``&``  ``|``  ``~``  ``!``  ``=``  ``<``  ``>``  ``+=``  ``-=``  ``*=`` ``/=``  ``%=``  ``^=``  ``&=``  ``|=``  ``<<``  ``>>``  ``>>=``  ``<<=``  ``==``  ``!=``  ``<=``  ``>=``  ``<=>``  ``&&``  ``||``  ``++``  ``--``  ``,``  ``->*``  ``->``  ``( )``  ``[ ]``

Operators are just functions! All these c++ operators can be overloaded, i.e. definer/change the behaviour of the operator in the program.
To overload an operator @ we just write the word operator followed by the operator @, then we define the function normally with its parameters.

```c++
struct Vector2 {
	float x, y;
	
	Vector2(float x, float y) : x(x), y(y) {}

	// here is how we overload the + operator
	Vector2 operator+(const Vector2& other) const {
		return Vector2(x + other.x, y + other.y);
	}
};

// another example: overloading of the << operator
std::ostream& operator<<(std::ostream& stream, const Vector2& vector) {
	stream << vector.x << ", " << vector.y;
	return stream;
}
```



## The this keyword

it is just the pointer to the current object instance that the method belongs to.

```c++
// some kinda cool printing function forward definition
void printEntity(Entity* e);

class Entity {
private:
	int x, y;
public:	
	Entity(int x, int y) {
		// this is a pointer so using -> we first dereference 
		// then we use the Entity object
		this->x = x; 
		this->y = y;
		// here we pass the pointer to the current object instance
		// as parameter of the printing function
		printEntity(this);
	}
};
```



## Smartpointers

are **scoped pointers** (created on the stack) that will create and point to objects created on the heap. Once out of the scope the pointer and the pointed objects get automatically deleted. 

### 1. unique pointers
simple type of smarpointer whose created object cannot have more than one pointer reference. *You cannot copy unique pointers*: if you have two unique pointers pointing to the same loc of memory and one of them dies, the loc will be freed and suddenly the second pointer will point then to memory that has been freed.
```c++
std::unique_ptr<Entity> entity = std::make_unique<Entity>();
// OR
std::unique_ptr<Entity> entity(new Entity());
```  
**make_unique** will create a new Entity that can have just one pointer reference.

### 2. shared pointers
smartpointer that can be copied and actually maintain a reference copy count. Will free Entity only when last pointer reference gets deleted.
```c++
{ // first scope
	std::shared_ptr<Entity> anotherPtr;
	{ // second scope
		std::shared_ptr<Entity> sharedEntityPtr = std::make_shared<Entity>();
		anotherPtr = sharedEntityPtr; // ref count = 2
		// at scope exit ref count become 1
	}
	// at scope exit ref count gets 0, Entity object gets freed
}
```  
### 3. weak pointers

weak pointer doesn't increment the reference count of a shared pointer, so in the following example, when we get out of the inner scope, the memory gets freed. However we can still ask the weak pointer, are you expired? are you still valid?

```c++
{
	std::weak_ptr<Entity> anotherPtr;
	{
		std::shared_ptr<Entity> sharedEntityPtr = std::make_shared<Entity>();
		anotherPtr = sharedEntityPtr; // ref count remains 1
		// at scope exit ref count gets 0,  Entity object gets freed
	}
}
```  


## The copy constructor

Unnecessary copying is to be avoided, but sometimes copying is essential. When we are playing with copying class objects we need to verify that the classes we wrote have a copy constructor. Let's write a custom String class to make an example

```c++
class String {
private:
	char* m_buffer;
	unsigned int m_size;
public:
	String(const char* string) {
		m_size = strlen(string);
		m_buffer = new char[m_size + 1];
		memcpy(m_buffer, string, m_size);
		m_buffer[m_size] = 0; // null termination char
	}

	/* this is the copy constructor!! that guarantees that 
	m_buffer of a String object copy will be created on a 
	new block of memory */
	String(const String& other)
		: m_size(other.m_size) {
		m_buffer = new char[m_size + 1];
		memcpy(m_buffer, other.m_buffer, m_size + 1);
	}

	/* this is the way to prevent the user to make copies 
	of the String objects */
	// String(const String& other) = delete;

	~String() {delete[] m_buffer;}
}

int main() {
	String string = "Cherno";
	String another = string; // copying a String object
	/*  */
}
```  


> NB: if  String class doeasn't have a copy construstor that makes a deep copy, the m_buffer of 'string' and 'another' will be the very same at the very same block of memory.

## The arrow operator

If we have an object declared on the stack then to access fields we use ``.`` 
If we have an object on the heap, created with new, so basically a pointer, we access its fields using ``->``
Indeed -> is a shortcut of *dereference a pointer and use a method* of the dereferenced object.
Therefore, when we use the word ``this`` inside the definition of a class, that is the pointer to the actual object we use ``this->`` 

```c++

int main() {
	Entity e; // create an entity on the stack
	Entity* ptr = &e; // make ptr point to it
	
	/* create a reference and assign it the 
	the object dereferenced by ptr pointer */ 
	Entity& entity = *ptr;
	entity.print();

	/* the last two lines can be shortcutted like this */
	(*ptr).print() // dereference first and then use print()
	/* or even better */
	ptr->print();
	ptr->age = 5;
}
```

> so what *->* operator does is dereference that pointer into a reference type and then call its method or field

you can overload the -> operator in this way. Let's create a scoped pointer  as an example

```c++

class Entity {
public:
	void print() const {..}
};

class ScopedPtr {
private:
	Entity* m_obj;
public:
	ScopedPtr(Entity* entity) : m_obj(entity) {}
	~ScopedPtr() {delete m_obj;}

	/* that's how we overload the -> operator */
	const Entity* operator->() const {
		return m_obj;
	}
};

int main() {
	// entity automatically deleted when it goes out of scope
	ScopedPtr entity = new Entity();
	
	/* the overload of the -> operator may allow 
	this even if entity is not a heap allocated entity */
	entity->print(); 
}
```

## Dynamic arrays 

It is just an array for which it is not necessary to specify the size.
So we declare a dynamic array using:

```c++
#include <vector>

std::vector<int> v {1, 2, 3, 4, 5};
std::vector<Point> pointArray;
```

and we add elements to a dynamic array using ``pushback()``:

```c++
pointArray.push_back(Point(x, y));
```

### Optimizations

There are a couple of optimizations we can do using a dynamic array:
1. if we know in advance how many elements we are gonna put into the array we can "reserve" the memory so the array will be resized just one time and not every time a new element is pushed_back in.

```c++
pointArray.reserve(8); 
```

2. we can use ``emplace_back`` passing just the parameters to build a new element, in place of ``push_back``  already istanciated elements. In this way the elements will not be copied around uselessly

```c++
pointArray.emplace_back(x, y);
```

## Static and Dynamic libraries

### static linking
the library gets basically put into your executable (it's inside your .exe file). Technically faster. Use static whenever possible.

Create a *Dependencies* directory and inside another directory with the name of the dependency e.g. GLFW. Inside it we put the *include* folder and the *lib* folder. In VB we go to project properties > c/c++ > general > additional include directories, we select all configurations Win32 and we add $(SolutionDir)Dependencies\GLFW\include.
Now in my code I can ``#include <GLFW/glfw3.h>``

but we haven' t linked our actual library. We need the definition for the glfw3 functions.

We go to project properties > linker > general > additional librariy directories, and we add $(SolutionDir)Dependencies\GLFW\lib-vc2015.
Then we go to project properties > linker > input, and we add glfw3.lib

### dynamic libraries
the library gets linked at run-time. In windows you can use some function like load_library or at the application lunch it loads a .dll file (dynamic link library)

## Templates

It's kind of generics, but it can do much more, it's not limited by the generic type system. It's a template specifying the compiler how to create methods, classes, or whatever, at compile time, based on the specific usage. 
The class *Array* will be compiled if and only when used; type T and size N will be substituted by the type and size we specify when we actually use it (at compile time :P).

```cpp
template<typename T, int N>
class Array {
private:
	T m_array[N];
public:
	int getSize() const { return N; }
};

int main() {
	Array<int, 50> array;
	array.getSize();
}
```
## Macros

Macros are pre-processor, pure text replacing, before everything gets compiled.
A simple example

```cpp
#define WAIT std::cin.get()

int main(){
	WAIT;
}
```

a more useful example, using a parameter and a preprocess definition
```cpp
#ifdef PR_DEBUG // preprocess definition variable
#define LOG(x) std::cout << x << std::endl
#else
#define LOG(x) // this will basically remove LOG line in main
#endif

int main(){
	LOG("Hello");
}
```

## Namespace

The primary purpose of namespaces is to avoid naming conflicts, i.e. with namespaces we can have symbols (classes, functions, variables) with the same signature in different context

```cpp
namspace apple {
	void print(const char* str){}
}

namspace orange {
	void print(const char* str){}
}

int main(){
	orange::print("ciao a tutti");
	// or
	using namespace apple;
	print("ciao a tutti");
}
```

## Function pointers

You can actually assign functions to variables. Starting from that, you can also pass a function into another function as paramenter. There's a whole bunch of things that we can actually do with functions and function pointers that do create intresting and complex logic. 

```cpp
// a very simple function
void helloWorld(){
	std::coutn << "hello" << std::endl;
}

int main(){
	// assign myfunc the memory address of helloWorld function
	auto myfunc = &helloWorld; // because of implicit conversion we can also omit the ampersand &

	// the type auto will be void(*myfunc)() so I can also write
	void(*myfunc)() = helloWorld; 

	// even better, I can use typedef like this
	typedef void(*hworldfunc)() 
	// and then 
	hworldfunc myfunc = helloWorld;

	myfunc();
	myfunc();
}
```

I can also use functions that have parameters so it would become

```cpp
void helloWorld(int value){
	std::coutn << "hello: " << value << std::endl;
}

int main(){
	typedef void(*hwfunc)(int) 
	hwfunc myfunc = helloWorld;

	myfunc(8);
	myfunc(4);
	myfunc(9);
}
```

a more useful exmaple can be this:

```cpp
void printValue(int value){
	std::cout << value << std::endl;
}

void foreach(const std::vector<int>& values, void(*func)(int)){
	for (int v : values)
		func(v);
}

int main(){
	std::vector<int> vector = {1, 2, 3};
	foreach(vector, printValue);
}
```
so here I use foreach function to which I pass a vector of elements and a function pointer. The function the pointer points to defines what I want to do with each element of the vector.
Though we can rewrite this is a more simple way, avoiding to write an extra function, using **lambda**. Lambda is just a normal function except that it is not declared as a normal function.

```cpp
void foreach(const std::vector<int>& values, void(*func)(int)){
	for (int v : values)
		func(v);
}

int main(){
	std::vector<int> vector = {1, 2, 3};
	foreach(vector, [](int value){std::cout << value << std::endl;});
}
```

## Lambdas

ref. https://en.cppreference.com/w/cpp/language/lambda

Lambdas are a way to define "anonymous functions". A way to create a function without the need to "phisically" create a function. This sort of function, we want to treat it more like a variable unless then a formal function that exsists like a symbol in our compiled code.
So when to use it? In C++, whenever we set a function pointer to a function, we can set it to a lambda instead.

```cpp
std::vector<int> v {1, 2, 3, 4};

// defining my lambda: check if i is even or odd
auto is_even = [](int i) { return i % 2 == 0; };
// result is an iterator that points to the first match
// or to end() if no match are found
auto result = std::find_if(begin(v), end(v), is_even);

// if something is found dereference iterator to print the first match
(result != std::end(v))
? std::cout << "v contains an even number: " << *result << '\n'
: std::cout << "v does not contain even numbers\n";
```

```cpp
// inside [] I can put captures, variables/objects that are outside
// my lambda function
// I can use:
// [=] captures everything by value
// [&] captures everything by reference
// zero to n variables/classes by reference or by value
// e.g. [a] to pass variable a by value
// [&a] to passa variable a by reference

int const max = 100;
std::vector<int> vec {178, 101, 123, 145, 45, 33};

auto lambda = [max](int i){ return i < max; };
auto it = std::find_if(begin(vec), end(vec), lambda);
(it != end(vec))
? std::cout << "first element <= then max is: " << *it <<std::endl
: std::cout << "all element are greater then max." << std::endl;
```

## Multidimensional arrays

A simple array is a pointer to the first element of the array

```cpp
// on the stack
int a[50];
int* ptr = a;

// on the heap 
char* buffer = new char[8];
```

A 2d array in C++ is an array of pointers, each one pointing to another array

```cpp
int x[3][4] = {{0,1,2,3}, {4,5,6,7}, {8,9,10,11}}
// OR
int x[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11}
```

On the heap a 2d array in is still a buffer of pointers that points to arrays stored somewhere in the memory.

```cpp
// a pointer to a pointer to an integer
int** a2d = new int*[50];
// with this we just have allocated memory
// specifically 50 integer pointers, so
// 4bytes * 50 = 200 bytes of memory

// now we need to initialize the 50 arrays 
for (int i = 0; i < 50; i++)
	a2d[i] = new int[50];

// so to delete we need to dolete them one by one
for (int i = 0; i < 50; i++)
	delete[] a2d[i];
// and finally
delete[] a2d;
```

so for a 3d array it would be

```cpp
int*** a3d = new int**[50];
for(int i = 0; i < 50; i++){
	a3d[i] = new int*[50];
	for(int i = 0; i < 50; i++)
		a3d[i][j] = new int[50];
}
```

Managing multidimensional arrays this way though is not very convenient, nor very efficient, because an 2d array ends up to be a buffer of pointers to not contiguous arrays, so we continuously jump from one part to another part of the memory. The more optimized version is a single dimension array

```cpp
int* fake2darray = new int[3*3];

for(int i = 0; i < 3*3; i++){
	for(int j = 0; j < 3; j++)
		fake2darray[j + i * 3] = 0; 
}
```
## Sorting std sort

ref. en.cppreference.com/w/cpp/algorithm/sort

sorting a simple array

```cpp
#include <algorithm>
int n = 7; // array size
int a[] = {4,2,5,3,5,8,3};
sort(a, a+n);
```

here we just sort a simple vector of elements
```cpp
#include <algorithm>
std::vector<int> values = {3, 5, 1, 4, 2};
std::sort(values.begin(), values.end()); // 1 2 3 4 5
std::sort(values.rbegin(), values.rend()); // 5 4 3 2 1
```

sorting a string

```cpp
#include <algorithm>
string s = "monkey";
sort(s.begin(), s.end());
```

sorting classes based on some kind of comparison

```cpp
bool compare(Man& m1, Man& m2){
    return m1.age() < m2.age();
}
std::vector<Man> v = {mike, alice, bob};
sort(v.begin(), v.end(), compare);
```
if we want to provide some kind of way to sort providing it with a lambda function

```cpp
#include <functional>

std::sort(values.begin(), values.end(), std::greater<int>()); // > 5 4 3 2 1
std::sort(values.begin(), values.end(), [](int a, int b){ return a < b; }); // > 1 2 3 4 5
std::sort(values.begin(), values.end(), [](int a, int b){ return a > b; }); // > 5 4 3 2 1
```

## type Punning

Type punning an integer to a double would look something like this

```cpp
int a = 50;
double value = *(double*)&a;
// basically take the mem address of a, cast it to double pointer, then dereference the pointer to get back to the value
std::cout << value << std::endl;
```

## Union

Imagine we have a Vector2 and a Vector4 and we want to access Vector4 parts using Vector2

```cpp
struct Vector2 {
	float x, y;
};
// operator overloading to print Vector2
std::ostream& operator<<(std::ostream& stream, Vector2& vector){
	stream << vector.x << ", " << vector.y;
	return stream;
}
```
using type punning, we could write getA() and getB() to get respectively x, y and z, w

```cpp
struct Vector4 {
	float x, y, z, w;
	Vector2& getA() { return *(Vector2*)&x; }
	Vector2& getB() { return *(Vector2*)&z; }
};

int main() {
	Vector4 v4 = {1, 2, 3, 4};
	std::cout << v4.getA() << std::endl;
}
```
using Union we can instead write something simplier like this:

```cpp
struct Vector4 {
	union {	
		// an anonymous struct to structure the data
		struct { float x, y, z, w; }; 
		struct { Vector2 a, b; };
		// so now I can access data in two ways: 
		// 1. using x, y, z, w
		// 2. using a and b, where a happens to be x, y 
		// b happens to be z, w
	};
};

int main(){
	Vector4 v4 = {1, 2, 3, 4};
	v4.z = 33;
	std::cout << v4.b << std::endl;
}
```

## Virtual Destructors

When inheritance and virtual functions come together, then we need to deal with virtual destructors too.

```cpp
class Base {
public:
	Base(){std::cout << "B constr, ";}
	~Base(){std::cout << "B destr, ";}	
};
class Derived : public Base {
public:
	Derived(){std::cout << "D constr, ";}		
	~Derived(){std::cout << "D destr, ";}
};
int main(){
	Derived* derived = new Derived();
	delete derived;
}
```
this will printout ``B constr, D constr, B destr, D destr,`` as we expect!
What will happen when we use a polymorphic like this:

```cpp
int main(){
	Base* poly = new Derived();
	delete poly;
}
```
just the Base destructor will be called, leading to a memory leak!
So to solve this, we need to set destructor of Base class as **virtual**, telling this way that the class may be extended, so call the derived destructors if present

```cpp
class Base {
public:
	Base(){std::cout << "B constr";}
	virtual ~Base(){std::cout << "B destr";}	
}
```
So, *whenever writing a class that you will be extending or might be subclassed, you need to 100% declare destructor as virtual*

## Casting

### static cast 

Type casting, means conversion within the type system that C++ provide us with. If I declare a variable of a specific type, I need to stick with that type unless either there is an **implicit conversion** (C/C++ knows how to convert from one type to another) or we write an **explicit conversion**, so we tell C/C++ how to convert from one type to another.

C style cast:

```cpp
double value = 5.32;
int a = (int)value + 5.4;
```

C++ style cast (static cast):

```cpp
double value = 5.32;
int a = static_cast<int>(value) + 5.4;
```
the good thing about C++ style of casting is that if something goes wrong with my compilation and I get some compile check messages, moreover I can search for casting in my code easily trying to figure out the problem

### dynamic cast

suppose we have another class that extends Base

```cpp
class AnotherClass : public Base {
public:
	AnotherClass () {}
	~AnotherClass () {}	
}
```
and we want to know if a pointer of type Base specialized to Derived or to AnotherClass

```cpp
Derived* derived = new Derived()
Base* base = derived // suppose we don't know that base specialized to derived

AnotherClass* ac = static_cast<AnotherClass*>(base); // will do the conversion
AnotherClass* ac = dynamic_cast<AnotherClass*>(base); // will check if base specialized to AnotherClass, if not it will return NULL, so we can check the type by writing if (!ac) {} or if (ac) {}
```

### reinterpret cast

type punning :P


## Singleton

It's just a single instance of a class that you "have around" your code. A singleton is a class that you only intend to have a **single instance** of. In C++ its just a way to organize a bunch of global variables and static functions that may act on those variables.

```cpp
class BetterSingleton {
public:
	static BetterSingleton& get(){
		static BetterSingleton instance;
		return instance;
	}
	
	void hello() { std::cout << "hello" << std::endl; }
};

Singleton* Singleton::s_instance = nullptr;

int main() {
	Singleton::get().hello();
	BetterSingleton::get().hello();
	std::cin.get();
}
```