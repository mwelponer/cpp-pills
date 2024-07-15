C++ in short
==========
Copyright (C) 2024 Michele Welponer

- [Pointers](#pointers)
  * [Pointers arithmetic](#pointers-arithmetic)
  * [void pointer](#void-pointer)
  * [this keyword](#this-keyword)
  * [SmartPointers](#smartpointers)
- [References](#references)
- [Classes](#classes)
  * [Class Header](#class-header)
  * [Stack Heap memory allocation](#stack-heap-memory-allocation)
- [static](#static)
  * [outside class/struct](#outside-class-struct)
  * [inside local scope](#inside-local-scope)
  * [in object oriented](#in-object-oriented)
    + [singleton](#singleton)
- [const](#const)
  * [outside class/struct](#outside-class-struct-1)
  * [with pointers](#with-pointers)
  * [in object oriented](#in-object-oriented-1)
- [Operator overloading](#operator-overloading)
- [Logical operators](#logical-operators)
- [Bitwise operators](#bitwise-operators)
- [Templates](#templates)
- [Macros](#macros)
- [Namespace](#namespace)
- [Strings](#strings)
  * [C style strings](#c-style-strings)
    + [C string handling functions](#c-string-handling-functions)
  * [declaration via char pointer](#declaration-via-char-pointer)
  * [std string](#std-string)
- [Arrays](#arrays)
  * [multidimensional arrays](#multidimensional-arrays)
  * [std array](#std-array)
  * [dynamic arrays std vector](#dynamic-arrays-std-vector)
  * [Bitset](#bitset)
- [Iterators](#iterators)
- [algorithm header](#algorithm-header)
  * [find](#find)
  * [std sort](#std-sort)
  * [std equal](#std-equal)
  * [Other](#other)
- [Math](#math)
  * [max and min](#max-and-min)
  * [integer division](#integer-division)
- [Data structures](#data-structures)
  * [Deque](#deque)
  * [Stack std stack](#stack-std-stack)
  * [Queue  std queue](#queue--std-queue)
  * [Set](#set)
    + [unordered set](#unordered-set)
    + [std set](#std-set)
  * [Map](#map)
  * [unordered map](#unordered-map)
    + [sorting unordered_map](#sorting-unordered-map)
    + [std map](#std-map)
  * [Priority queue or maxHeap std queue](#priority-queue-or-maxheap-std-queue)
  * [Linkedlists std list](#linkedlists-std-list)
  * [Tuples std tuple](#tuples-std-tuple)
  * [Pairs std pair](#pairs-std-pair)
- [Custom data structures](#custom-data-structures)
  * [Binarytree](#binarytree)
    + [BFS](#bfs)
    + [stackDFS](#stackdfs)
    + [recursiveDFS](#recursivedfs)
  * [Trie](#trie)

<small><i><a href='http://ecotrust-canada.github.io/markdown-toc/'>Table of contents generated with markdown-toc</a></i></small>


## Pointers
Pointers hold an integer that is a memory address! We say then a pointer points to a location in memory: that location is the starting location of a memory space (whose lenght is defined by the type)

```cpp
int a = 3 // declare a variable
int* ptr //declare a pointer
&a // dereference a variable -> mem address of a
ptr = &a // set a pointer to point to variable a

*ptr // dereference a pointer -> 3 i.e., get data of the variable ptr points to
++*ptr // get data, then increment it -> a holds 4 now
*++ptr // move pointer, then get data
*ptr++ // get data (dereference) then move pointer
(*ptr)++ // get data then increment it -> a holds 4 now
```

### Pointers arithmetic

``p*++``,  ``p++*`` and ``++p*`` are all **syntax errors**

```cpp
// the [] array operator is secretly a pointer, so it's somehow like to write
// int* b = {3, 0, 7}, but sintattically it's not correct, so we write
int b[] = {3, 0, 7};
int* p = b;

switch(4) {
	case 1:
		std::cout << *++p << std::endl; // move p, then dereference p -> 0
		std::cout << *++p << std::endl; // -> 7, [3 0 7]
		break;
	case 11:
		std::cout << *(++p) << std::endl; // move p, then dereference p -> 0
		std::cout << *(++p) << std::endl; // -> 7, [3 0 7]
		break;
	case 2:
		std::cout << ++*p << std::endl; // dereference p, then increment -> 4
		std::cout << ++*p << std::endl; // -> 5, [5 0 7]
		break;
	case 22:
		std::cout << ++(*p) << std::endl; // dereference p, then increment -> 4
		std::cout << ++(*p) << std::endl; // -> 5, [5 0 7]
		break;
	case 3:
		std::cout << *p++ << std::endl; // dereference p, then move p -> 3
		std::cout << *p++ << std::endl; // -> 0, [3 0 7]
		break;
	case 33:
		std::cout << *(p++) << std::endl; // dereference p, then move p -> 3
		std::cout << *(p++) << std::endl; // -> 0, [3 0 7]
		break;
	case 4:
		std::cout << (*p)++ << std::endl; // dereference p, then print, then increment -> 3
		std::cout << (*p)++ << std::endl; // -> 4, [5 0 7]
		break;
	//default:
		// code block
}

std::cout << b[0] << " " << b[1] << " " << b[2] << std::endl;
```

### void pointer

A void pointer is a pointer that has no associated data type with it. A void pointer can hold an address of any type and can be typecasted to any type.

```cpp
int a = 10;
char b = 'x';

// void pointer holds address of int 'a'
void* p = &a;
// void pointer holds address of char 'b'
p = &b;

// assign char s with what void pointer p is pointing
char s = *(char*)p;
std::cout <<  "s:"  << s << std::endl; // => s:x
```

### this keyword

In object oriented, it is just the pointer to the current object instance that the method belongs to.

### SmartPointers

```cpp
// will create an object that can have just 1 pointer reference
std::unique_ptr<int> uPtr = std::make_unique<int>();

// it maintains a reference counter. Object will be deleted only when last pointer gets deleted
std::shared_ptr<int> uPtr = std::shared_ptr<int>();

// Like shared but it doesn't increment the reference count
std::weak_ptr<int> uPtr = std::make_weak<int>();
// check if weak pointer is intact
string state = w_ptr.lock() ? "intact" : "gone"; cout << "state: " << state << endl;
```

## References
References are like Pointers but less powerful. Reference are just syntax sugar, whatever you can do with references you can also do it using pointers.

```cpp
int a = 3
int& ref = a // ref is now an alias of a
ref = 6 // update variable a, through alias ref
```

```cpp
int b = 3
int* ptr = &b
int& ref2 = *ptr // ref2 is an alias of the variable pointed by ptr, i.e. b  
```

references are often used passed as arguments in functions (***pass by reference***). 

```cpp
void incrementUsingRef(int& value){
  value++;
  std::cout << "value:" << value << std::endl;  
}

incrementUsingRef(a) // we pass a variable 
incrementUsingRef(ref) // we pass a reference, i.e. an alias of a variable 
```
**NB**: the external variable we pass by reference will actually be incremented. If we don't use a reference but simply a variable, a new variable will be created, incremented inside the function, then destroyed as soon as the program goes out of the function scope.


## Classes

example of a class Human that extends from LivingBeing

***Everything inside *Human.h****

```cpp
// define a parent class 
class LivingBeing {
public:
	virtual ~LivingBeing(){ std::cout << "destr"; } /* declare virtual destructor to 
	ensure a proper memory cleaning of the derived classes when deleted */

	virtual std::string getName(){return "LivingBeing";}
	// virtual std::string getName() = 0; /* '= 0' makes it a pure virtual function!
	the method NEEDS to be implemented in the subclasses. The presence of a 
	pure virtual function makes also become the class an interface */
};

// define extending class
#include <iostream>
#include <string>

class Human : LivingBeing{
private:
    std::string m_name;
    int m_age;
    Human* m_son;
public:
    // Constructors
    Human() 
	    // m_son pointer needs to be initialized in any case,
	    // wild pointers can lead to unpredictable behviour
        : m_name("unknown"), m_age(-1), m_son(nullptr) {} 
    Human(const std::string& name, int age)
        : m_name(name), m_age(age), m_son(nullptr) {}
    Human(const std::string& name, int age, Human* son)
        : m_name(name), m_age(age), m_son(son) {}

    // Copy constructor: creates a deep copy of `m_son` if it exists
    Human(const Human& other)
        : m_name(other.m_name), m_age(other.m_age), m_son(nullptr) {
        if (other.m_son)
            m_son = new Human(*other.m_son);
    }
    
    // Copy assignment operator: it defines what happens when an object 
    // is assigned to another object using the assignment operator `=`
	Human& operator=(const Human& other) {
	    if (this == &other)
	        return *this;

	    // Free existing resource
	    delete m_son;

	    // Copy data
	    m_name = other.m_name;
	    m_age = other.m_age;

	    // Copy the son if it exists
	    if (other.m_son)
	        m_son = new Human(*other.m_son);
		else
	        m_son = nullptr;

	    return *this;
	}

    // Destructor
    ~Human() { delete m_son; }
        
    // override parent method    
    std::string getName() const override { return m_name; }
    // Methods
    void print() const { std::cout << "Human " << m_name 
	    << ", age " << m_age << std::endl; }
    int age() const { return m_age; }
    Human* son() const { return m_son; }
};

int main() {
    Human parent("John", 40);
    Human child("Chris", 10);

    parent.print();
    child.print();
}
```

### Class Header

If we want to separate the file into .h and .cpp then it becomes:

***Human.h***
```cpp
#pragma once
#include <string>
#include <iostream>

namespace myNamespace {
	class Human {
	private:
		std::string m_name;
	    int m_age;
	public:
	    Human();
	    Human(const std::string& name, const int age);
	    // Methods that do not modify the object should be marked as `const`.
	    void print() const;
	    int age() const;
	};
}
```

***Human.cpp***

```cpp
#include "Human.h"

namespace myNamespace {
    Human::Human()
	    : m_name("unknown"), m_age(-1){}
    Human::Human(const std::string& name, const int age)
	    :m_name(name), m_age(age){}
	    	    
    void Human::print() const { cout << "Human " << m_name << ", age " << m_age << endl; }
    int Human::age() const { return this->m_age; }
}
```

***main.cpp***

```cpp
#include "Human.h"

int main() {
    myNamespace::Human person1;
    myNamespace::Human person2("Alice", 30);

    person1.print();
    person2.print();

    return 0;
}
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

Allocating on the heap takes longer: when we write "new dataType" we require the compiler to find and allocate a dataType long free and contiguous space in heap memory and return a pointer to that memory address (malloc function). Allocation on the heap is indeed a very heavy task, compared to the stack one that just need 1 cpu instruction. Moreover, when allocating on the heap, we need then to remember to manually free the allocated memory. So the rule of thumb is *whenever possible instantiate on the stack otherwise on the heap*. 
It can be impossible to use stack memory when for example:
1. the object is inside a scope and needs to remain alive also outside of that scope, or when 
2. the object is too big to stay on the stack (stack is usually 1-2MB) or 
3. there are too many objects that need to be allocated.

``NB``: So, whenever we use the word **new**, we need then to delete!


## static

### outside class/struct

a static variable is visible only inside the specific translation unit (file) where i declare it. If it is not static I can access it from another translation unit declaring  external

```cpp
// translation unit 1
static int s_v = 5;
int v = 6; 
```

```cpp
// translation unit 2
external int v; // way to accecc v defined in t.u.1
```

..so **always mark functions and variable static** unless you actually need them to be linked across different translation units.

### inside local scope

static variable inside a scope/function has the same effect of declaring the variable globally outside the scope/function, but declaring it inside the function guarantee `i` can be modified only inside the function.

```cpp
void func() {
	static int v = 0;
	cout >> ++v >> endl;
}

func(); // >>> 1
func(); // >>> 2
```

### in object oriented

static field inside a class are shared among all class entities. 
**NB**: Static methods cannot access non-static fields.

```cpp
struct Entity {
	static int x;
	int y;
	
	static void print() {cout << x << y << endl;}
	static void s_print() {cout << x << endl;}
};
```

#### singleton

it is basically a single instance of a class that you have around. So in some sense a singleton in c++ acts pretty much like a namespace, as it is a way to organize a bunch of global variables and static functions into a kind of "organized blob".

```cpp
class Singleton {
private:
	static Singleton* s_instance; // global declaration
public:
	static Singleton& get() {return *s_instance;}
};
```

## const

### outside class/struct

const variables become constant, not supposted to be modified, e.g. `const int MAX_AGE = 90;`

### with pointers

- const before `*` : cannot modify what the pointer points to ~~`*ptr = 5;`~~
	- `const int* ptr`
	- `int const* ptr`
- const after `*` : cannot modify the pointer memory address ~~`ptr = &v;`~~
	- `int* const ptr`


### in object oriented

Declaring an object const ( i.e. when I pass by const reference an object to a function e.g. `func(const Entity& e)`), I will be able to call only its const methods. Const methods promise not to modify fields e.g. Entity `string const getName(){}` will not modify `name`.
**NB**: const objects cannot call non-const methods, so cannot modfy fields
**NB**: if I declare a field mutable then I can still modify its value inside a const method

## Operator overloading

``+``  ``-``  ``*``  ``/``  ``%``  ``^``  ``&``  ``|``  ``~``  ``!``  ``=``  ``<``  ``>``  ``+=``  ``-=``  ``*=`` ``/=``  ``%=``  ``^=``  ``&=``  ``|=``  ``<<``  ``>>``  ``>>=``  ``<<=``  ``==``  ``!=``  ``<=``  ``>=``  ``<=>``  ``&&``  ``||``  ``++``  ``--``  ``,``  ``->*``  ``->``  ``( )``  ``[ ]``

Operators are just functions! All these c++ operators can be overloaded, i.e. definer/change the behaviour of the operator in the program.
To overload an operator, e.g. the operator "@" we just write the word *operator* followed by the operator we want to overload @, then we define the function normally with its parameters.


**example** of overloading opertor "**<<**" to print a standard `std::vector<T>` object

```cpp
template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
  int size = vec.size();

  stream << "[";
  for (int i = 0; i < size; i++)
    i == size-1 ? os << vector[i] : os << vector[i] << ", ";
  os << "]";

  return os;
}
```

**example** of overloading opertor "**<<**" to print a custom `vector2<T>` object

`vector2.h` file:

```cpp
#pragma once
#include <iostream>

struct vector2 {
    float x, y;
    vector2(float x = 0, float y = 0) : 
	    x(x), y(y) {}
};

// Declare the operator<< overloading function
std::ostream& operator<<(std::ostream& os, const vector2& vec);
```

`vector2.cpp` file:

```cpp
#include "vector2.h"

template<typename T>
std::ostream& operator<<(std::ostream& os, const vector2<T>& vec) {
    os << "vector2(" << vec.x << ", " << vec.y << ")";
    return os;
}
```

Usage:

```cpp
#include "vector2.h"

int main() {
    vector2 v(3.0f, 4.0f);
    std::cout << v << std::endl;
}
```

**example** of overloading operator "**+**" to define how to add two Vector2 objects 

```c++
struct Vector2 {
	float x, y;
	
	Vector2(float x, float y) : x(x), y(y) {}

	// here is how we overload the + operator
	Vector2 operator+(const Vector2& other) const {
		return Vector2(x + other.x, y + other.y);
	}
};
```

**example** of overloading of operator "**new**", to define what to do each time the word new is used: keep track of heap allocation count, show the quantity of heap memory allocated

```cpp
static uint32_t s_AllocCount = 0;
void* operator new(size_t size){
	s_AllocCount++;
	std::cout << "Allocating " << size << " bytes\n";
	return malloc(size);
}
std::cout << s_AllocCount << " allocations\n";
```


## Logical operators

used to perform logical operations on boolean expressions. Combine multiple conditions and evaluate the result as either true or false. Conditions are evaluated from left to right
The logical **AND** operator (&&) returns true if *both of its operands are true*.
The logical **OR** operator (||) returns true if *at least one of its operands is true*. 
The logical **NOT** operator (!) is a unary operator that *negates the value of its operand*

```c++
bool a = true;
bool b = false;
bool result = a && b;  // result false (immediately if a is false)
bool result = a || b;  // result is true (immediately if a is true)
bool result = !a;  // result is false
```

## Bitwise operators

Bitwise operators are used to perform operations on individual bits of binary numbers. These operators allow you to manipulate the binary representation of integers at a bit level. There are six bitwise operators in C++:

The bitwise **AND** (&) operator compares the corresponding bits of two operands and returns 1 if *both bits* are 1, otherwise it returns 0
The bitwise **OR** (|) operator compares the corresponding bits of two operands and returns 1 if *at least one* of the bits is 1, otherwise it returns 0
The bitwise **XOR** (^) operator compares the corresponding bits of two operands and returns 1 if *the bits are different*, otherwise it returns 0
The bitwise **NOT** (~) operator is a unary operator that flips the bits of its operand. It returns *the one's complement* of the operand. For example:

```c++
int a = 5; // binary representation: 0101
int b = 3; // binary representation: 0011
int result = a & b; // binary representation: 0001 (1 in decimal)
int result = a | b; // binary representation: 0111 (7 in decimal)
int result = a ^ b; // binary representation: 0110 (6 in decimal)
int result = ~a; // binary representation: 1010 (-6 in decimal)
```

The left shift **<<** operator shifts the bits of the left operand to the left by a specified number of positions. The vacant positions are filled with zeros.  
***NB***: left shift multiplies the original number by 2

The right shift **>>** operator shifts the bits of the left operand to the right by a specified number of positions. The vacant positions are filled with the sign bit (for signed types) or with zeros (for unsigned types). ***NB***:  right shifts are equivalent to dividing a number by 2

```c++
int a = 5; // binary representation: 0101
int result = a << 2; // binary representation: 010100 (20 in decimal)
int result = a >> 2; // binary representation: 0001 (1 in decimal)
```

## Templates

Array will be compiled if and only when used; type T and size N will be substituted by the type and size we specify when we use it.

```cpp
template<typename T, int N>
class Array {
private:
	T m_array[N];
public:
	getSize() const { return N; }
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

## Strings

### C style strings

also known as **null-terminated strings**. 
A string is just an array of characters. If we want to declare it completely *manually* we need to add the string termination char (``0`` or ``'\0'``) that tells the pointer that the string is terminated.

```cpp
char str[5] = {'M', 'i', 'k', 'e', \0};
std::cout << str << std::endl;
```
we can also do 

```cpp
char str[] = "John is from USA.";
```

and we can both use it as function parameters like this

```cpp
void log(const char* ptr){
	std::cout << ptr << std::endl;
}
```

#### C string handling functions

**NB**: `#include <cstring>`

-  `strcpy(destination, source);` copies the source string to the destination string. The destination must be large enough to hold the source string including the null terminator.
-  `strcat(destination, source);` appends the source string to the destination string. The destination must have enough space to hold the combined string.
-  `strcmp(str1, str2);` compares two strings lexicographically. It returns 0 if they are equal, a negative value if `str1` is less than `str2`, and a positive value if `str1` is greater than `str2`.
-  `strlen(str);` returns the length of the string, not counting the null terminator.
- `strstr(str, substr);` find the first occurrence of substr in str
- `strchr(str, char);` find the first occurrence of ch in str

```cpp
const char* str = "Hello, World!"; 
const char* substr = "World"; 

// Find the first occurrence of substr in str 
const char* pos = strstr(str, substr); 
if (pos != nullptr) 
	cout << "found at: " << (pos - str) << endl;
```

**NB**: `#include <cctype>`

- `isalnum(char)` checks if char is alphanumeric 
check if a char is alphanumeric


```cpp
example
```

### declaration via char pointer

Declaration of a string using a *char pointer* in c++ it is immutable in the sense that you cannot change the lenght of the string, so usually it is declared ``const``

```cpp
const char* name = "Mike";
std::cout << name << ", " << strlen(name) << std::endl;

char* str1 = "Ciao";
char str2[40];
strcpy(str2, str1); // copy str1 into str2 
```

***Find***
``size_t find(const char* s, size_t pos = 0)``
**s**: the sub-string to be searched
**pos**: the initial position from where the string search is to begin. 
If the sub-string is not found it returns **string::npos** (a static member with its value as the highest possible for the size_t data type).

```cpp
std::string str = "geeks4geeks" // string
char arr[] = "geeks" // substring to search
size_t found = str.find(arr, 3) // the index of the first occurence of arr starting from 3 -> 6

if (found != std::string::npos)
	std::cout << found << std::endl
```

### std string
i.e. ``std::string``

Finally if we want to use the *standard string* implementation. ``#include <string.h>`` is used just to overload the ``<<`` operator for the cout 

```cpp
std::string myString = "ciao";
myString += "!";
std::cout << myString << std::endl;
	
/* useful string methods */
str.size(); // length of the string 
str.at(2) // char at pos 2
str.append() // ???
str.substr(11, 3); // substring that begins at pos 11, length 3
stoi(str) // converts string to int
	stoi("123") // -> int 123
	stoi("54 fifty four" // -> 54
std::to_string(13)  // int to string
int('a') // char to ascii -> 97
char(97) // int to ascii value -> 'a'
toupper('a') // char to upper-case
tolower('A') // char to lower-case
std::string mystring(1, mychar) // converts mychar to string

// converts vector of chars to string
mystring(v.begin(), v.end()) 

// convert a vector of strings to string
#include <sstream>
std::vector<std::string> vec = {"ciao", "a", "tutti"};
std::stringstream ss;
for (auto e : vec)
	ss << (e + " ");
std::string out = ss.str();
```

Here is the way to split a string using ``getline(string, token, char delimiter)`` with 1 char delimiter
```cpp
#include <sstream>

std::string str = "I love to read articles.";
std::stringstream ss(str);
while (getline(ss, str, ' '))
	std::cout << str << std::endl;
```

Here is a way to split a string with a string delimiter 
```cpp
std::string s = "scott--tiger--mushroom";
std::string delimiter = "--";

size_t pos = 0;
std::string token;
while ((pos = s.find(delimiter)) != std::string::npos) {
    token = s.substr(0, pos);
    std::cout << token << std::endl;
    s.erase(0, pos + delimiter.length());
}
std::cout << s << std::endl;
```

***Find***
C++ Style ``size_t find (const string& str, size_t pos = 0)``

**str**: the sub-string to be searched
**pos**: the initial position from where the string search is to begin.
If the sub-string is not found it returns **string::npos** (a static member with its value as the highest possible for the size_t data type).

```cpp
std::string str = "geeks4geeks" // string
std::string str1 = "geeks" // substring to find
size_t found = str.find(str1) // gets the index of the first occurance of substring into string

if (found != string::npos)
	std::cout << found << std::endl
```

## Arrays 

***arrays on the stack memory***
```cpp
int stackArr[4] // declare: stackArr is now a pointer to the 1st element of the array
int stackArr[] = {1, 2, 3, 4} // declare and set 
stackArr[3] = 666
```
***NB***:  we cannot use increment and decrement (++/--) operator on the array name e.g., ~~stackArr++~~, because the array name is not an lvalue pointer. But we can always write

```cpp
int* ptr = stackArr;
std::cout << ++ptr << std::endl; // => 2
*(ptr+3) = 666 // this equals to stackArr[3] = 666
```

***arrays on the heap memory***

```cpp
int* heapArr = new int[10];
delete[] heapArr; // free the memeory allocated for the array
```

***NB***:  the raw arrays do not have any *.size* or *.lenght* operators so: 

1. if you declare the array in the stack use this trick:
```cpp
int size = sizeof(stackArr) / sizeof(int);
```
2. if you declare the array in the heap just do:
```cpp
static const int numOfElements = 10;
int* heapArr = new[numOfElements];
```

### multidimensional arrays

A simple array is a pointer to the first element of the array

```cpp
// on the stack
int = a[50];
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

Managing multidimensional arrays this way though is not very convenient, nor very efficient, because a 2d array ends up to be a buffer of pointers to not contiguous arrays, so we continuously jump from one part to another part of the memory. The more optimized version is a single dimension array

```cpp
int* fake2darray = new int[3*3];

for(int i = 0; i < 3*3; i++){
	for(int j = 0; j < 3; j++)
		fake2darray[j + i * 3] = 0; 
}
```


### std array
i.e. ``std::array``

The array from the c++ standard library v11 includes bounds checking in debug mode and it keeps track of the array size. There is of course a bit of overhead but it remains pretty fast.
```cpp
#include <array>
std::array<int, 10> stdArr
stdArr.size() // num of elements of the array
stdArr.empty() // boolean checks the size of the array
stdArr.fill(0) // fill the array with 0
``` 

### dynamic arrays std vector
i.e. dynamic arrays ``std::vector``

https://www.geeksforgeeks.org/vector-in-cpp-stl/?ref=gcse

It is just an array for which it is not necessary to specify the size.

```cpp
#include <vector>

void print(std::vector<int>& v){
    std::cout << "[";
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++){
        if (it == v.end() - 1)
            std::cout << *it << "]\n";
        else
            std::cout << *it << ", ";
    }
}

for (auto x : v)
	cout << x << endl;

// using lambda
for_each( v.begin(), v.end(), [](int i) { cout << i << endl; } );

std::vector<int> v; // declaration
std::vector<int> v = {3, 6, 5}; // init v.1
std::vector<int> v{3, 6, 5}; // init v.2
std::vector<int> v(3); // size 3, initial value 0
std::vector<int> v(10, 5); // size 10, initial value 5
v.assign(10, 5); // [5,5,5,5,5,5,5,5,5,5]
v.push_back(6) // insert 6 as last element
v.pop_back() // remove last element
v.begin() // the pointer to the first element
v.end() // the pointer to the last element
v.front() // first element 
v.back() // last element 
v.insert(v.begin(), value) // insert value as first element
v.erase(v.begin()) // remove the first element
v.clear() // erase the vector
v.size() // number of elements in the vector
v.max_size() // max number of elements the vec can hold
v.capacity() // size of the space currently allocated
v.resize(n) // reduce to its first n elements, removing those beyond if necessary
v.reserve(n) // reallocate storage increasing capacity to n if necessary
v.empty() // checks is the vector is empty
v.shrink_to_fit() // reduce the capacity to fit the size
v1.swap(v2); // swap elements of v1 with elements of v2

// converts vector of chars to string
mystring(v.begin(), v.end()) 

// convert a vector of strings to string
#include <sstream>
std::stringstream  ss;
for (auto e : vec)
	ss << e;
ss.str()
```

### Bitset

A bitset is an array whose each value is either 0 or 1. The benefit of using bitsets is that they require less memory than ordinary arrays

```cpp
#include  <bitset>
// initialization ways
bitset<10> s; 
s[1] = 1; 
s[3] = 1;
bitset<10> s(std::string("0010011010")); // from right to left
std::cout << "s:" << s << std::endl;
std::cout << "1 counts:" << s.count() << std::endl;

bitset<10> a(string("0010110110"));
bitset<10> b(string("1011011000"));
cout << (a&b) << "\n"; // 0010010000
cout << (a|b) << "\n"; // 1011111110
cout << (a^b) << "\n"; // 1001101110
```

## Iterators

An iterator is an abstract type that points to an element in a data structure.

**begin()** and **end()**: These are member functions of containers (like `std::vector`, `std::map`, etc.) that return iterators. `begin()` returns an iterator to the first element, and `end()` returns an iterator to one past the last element.

```cpp
#include <iostream>
#include <vector>

std::vector<int> v = {1, 2, 3};

for (auto it = v.begin(); it != v.end(); ++it) 
    std::cout << *it << "\n";
```

**std::prev()** and **std::next()**: These are utility functions provided in `<iterator>` to work with iterators:
`std::prev` returns an iterator to the previous element 
`std::next` returns an iterator to the next element.

```cpp
#include <vector>
#include <iterator>

std::vector<int> v = {1, 2, 3};
auto it = v.begin();
auto it_next = std::next(it);
auto it_prev = std::prev(it_next);
```

**lower_bound()** and **upper_bound()**: These are both:
- functions provided in `<algorithm>` or 
- member functions of associative containers like `std::map` and `std::set`. `lower_bound` returns an iterator to the first element not less than the given value, and `upper_bound` returns an iterator to the first element greater than the given value.

```cpp
#include <map>

// lower/upper_bound as MAP member function
std::map<int, std::string> m = {{1, "one"}, {2, "two"}, {3, "three"}};
auto it_lb = m.lower_bound(2); // Iterator to the element with key 2
auto it_ub = m.upper_bound(2); // Iterator to the element with key > 2

// lower_bound as STD function
int arr[] = {1, 2, 3, 5};
int size = sizeof(arr) / sizeof(int);
auto index = std::lower_bound(arr, arr+size, 3) - arr;
if (index < size)
    std::cout << "index: " << index << std::endl;
else
    std::cout << "Not found" << std::endl;
```

**erase()**: This is a member function of containers that supports erasing elements, such as `std::vector`, `std::map`, and `std::set`. It removes elements at the given position or in the given range and returns an iterator to the element following the last removed element.

```cpp
#include <vector>
#include <map>

std::vector<int> v = {1, 2, 3};
// Erases element at index 1
auto it_erase = v.erase(v.begin()+1); 
// Erases element all but last
auto it_erase = v.erase(v.begin(), v.end()-1);
```

## algorithm header

### find 

**find()**: This is both 
- a member function of associative containers like `std::map` and `std::set` and 
- a non-member function in `<algorithm>`. It returns an iterator to the element if found, otherwise, it returns the end iterator.

```cpp
#include <map>
#include <algorithm>
#include <vector>

// find as MAP member function
std::map<int, std::string> m = {{1, "one"}, {2, "two"}, {3, "three"}};
auto it_find = m.find(2);
if (it_find == m.end()) 
	cout << "not found" << endl;

// find as STD function
std::vector<int> v = {1, 2, 3};
auto it_alg_find = std::find(v.begin(), v.end(), 2);
```

std::reverse
std::random_shuffle

### std sort

```cpp
#include <algorithm>

// sort an array
int a[] = {4,2,5,3,5,8,3};
int size = sizeof(a) / sizeof(a[0]);
std::sort(a, a+size);

// sort a vector of primitives
std::vector<int> values = {3, 5, 1, 4, 2};
std::sort(values.begin(), values.end()); // 1 2 3 4 5
std::sort(values.rbegin(), values.rend()); // 5 4 3 2 1

// using lambda
std::sort(values.begin(), values.end(), std::greater<int>()); // > 5 4 3 2 1
std::sort(values.begin(), values.end(), [](int a, int b){ return a < b; }); // > 1 2 3 4 5
std::sort(values.begin(), values.end(), [](int a, int b){ return a > b; }); // > 5 4 3 2 1

// sort a string
string s = "monkey";
sort(s.begin(), s.end());

// sort a vector of custom objects
bool compare(Man& m1, Man& m2){
    return m1.age() < m2.age();
}
std::vector<Man> v = {mike, alice, bob};
sort(v.begin(), v.end(), compare);
```

### std equal

used to check whether the elements in two ranges are equal. It compares the elements in the specified ranges using the equality operator (`==`)

```cpp
std::vector<int> v1 = {3, 5};
std::vector<int> v2 = {3, 5};
bool b = std::equal(v1.begin(), v1.end(), v2.begin());
```

### Other

-   **std::find**: Finds the first occurrence of a value in a range.
```cpp
auto it = std::find(v.begin(), v.end(), 4);
```

-   **std::find_if**: Finds the first element satisfying a predicate.
```cpp
auto it = std::find_if(v.begin(), v.end(), [](int x) { return x > 3; });
```

-   **std::binary_search**: Checks if a value exists in a sorted range.
```cpp    
bool found = std::binary_search(v.begin(), v.end(), 4);
```    
-   **std::lower_bound**: Finds the first position where a value can be inserted without violating order.
```cpp
auto it = std::lower_bound(v.begin(), v.end(), 4);
``` 
    
-   **std::upper_bound**: Finds the first position after the last element that is less than a given value.
```cpp
auto it = std::upper_bound(v.begin(), v.end(), 4);
```
    
-   **std::equal_range**: Returns a pair of iterators representing the range of elements equal to a given value.
```cpp    
auto range = std::equal_range(v.begin(), v.end(), 4);
``` 
    
-   **std::copy**: Copies a range of elements to a new location.
```cpp    
std::vector<int> dest(v.size());
std::copy(v.begin(), v.end(), dest.begin());
```
    
-   **std::copy_if**: Copies elements satisfying a predicate to a new location.
```cpp
std::vector<int> even;
std::copy_if(v.begin(), v.end(), std::back_inserter(even), [](int x) { return x % 2 == 0; });
```
    
-   **std::fill**: Fills a range with a specified value.
```cpp
std::fill(v.begin(), v.end(), 0);
```

-   **std::transform**: Applies a function to each element in a range and stores the result in a new range.
```cpp
std::transform(v.begin(), v.end(), v.begin(), [](int x) { return x * 2; });
```

-   **std::replace**: Replaces all occurrences of a value in a range with another value.
```cpp
std::replace(v.begin(), v.end(), 1, 99);
```

-   **std::remove**: Removes elements equal to a value (without reducing the container size).
```cpp
auto new_end = std::remove(v.begin(), v.end(), 99);
v.erase(new_end, v.end());
```

-   **std::for_each**: Applies a function to each element in a range.
```cpp
std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << " "; });
```

-   **std::accumulate**: Computes the sum of elements in a range.
```cpp
int sum = std::accumulate(v.begin(), v.end(), 0);
```

-   **std::unique**: Removes consecutive duplicate elements in a range.
```cpp
auto new_end = std::unique(v.begin(), v.end());
v.erase(new_end, v.end());
```

-   **std::reverse**: Reverses the order of elements in a range.
```cpp
std::reverse(v.begin(), v.end());
```

-   **std::rotate**: Rotates the elements in a range.
```cpp
std::rotate(v.begin(), v.begin() + 1, v.end());
```

-   **std::merge**: Merges two sorted ranges.
```cpp
std::vector<int> result(v1.size() + v2.size());
std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin());
```

- **std::random_shuffle**: Shuffles elements randomly within a range.
```cpp
std::random_shuffle(v.begin(), v.end());
```

## Math

### max and min

```cpp
#include <limits.h>

int min = INT_MAX;
int max = INT_MIN;
```

### integer division

```cpp
printf("1/2 = %f", (float)(1/2)); // returns 0.000000
```
because both operands of the division (1 and 2) are integers, so the integer division applies, therefore the decimal part is discarded.
To solve just cast one of the two operands to float

```cpp
printf("1/2 = %f", (float)(1/(float)2)); // now it returns 0.500000
```

## Data structures

### Deque

A deque is a dynamic array whose size can be efficiently changed at both ends. Adding and removing elements take O (1) time on average at both ends.

```cpp
#include  <stack>
std::deque<int> d;
d.push_back(5); // [5]
d.push_back(2); // [5,2]
d.push_front(3); // [3,5,2]
d.pop_back(); // [3,5]
d.pop_front(); // [5]
std::cout << d.front() << std::endl;
std::cout << d.back() << std::endl;
```


### Stack std stack
i.e. ``std::stack``

A stack is a data structure that provides two O (1) time operations: adding an element to the top, and removing an element from the top. It is only possible to access the top element of a stack.

https://www.geeksforgeeks.org/stack-in-cpp-stl/?ref=gcse

```cpp
#include <stack>

// NB: if I pass s by reference i.e.
// (std::stack<int>& s), 
// then I pass the actual reference and 
// everytime I print I empty the stack!
void print(std::stack<int> s){
    std::cout << "(";
    while (!s.empty()){
        if (s.size() == 1)
            std::cout << s.top() << ")\n";
        else
            std::cout << s.top() << ", ";
        s.pop();
    }
}

std::stack<int> s
s.push(1)
s.push(2)
s.push(3)
s.top() // the last inserted
s.pop()
s.size()
s.empty()
s.swap(stack2)
```

### Queue  std queue

i.e. ``std::queue``

A queue also provides two O (1) time operations: adding an element to the end of the queue, and removing the first element in the queue. It is only possible to access the first and last element of a queue.

https://www.geeksforgeeks.org/queue-cpp-stl/?ref=lbp

```cpp
#include <queue>

void print(std::queue<int> q){
	std::cout << "(";
	while(!q.empty()){
		if (q.size() == 1)
			std::cout << q.front() << ")\n";
		else
			std::cout << q.front() << ", ";
		q.pop(); 
	}
}

std::queue<int> q
q.push(10) // insert an element 
q.size() // number of elements
q.front() // the first inserted, i.e. peek
q.back() // the last inserted
q.pop() // pops from the front
q.empty() // boolean is empty or not
q1.swap(q2);
```

https://www.geeksforgeeks.org/deque-cpp-stl/?ref=lbp

### Set

A data structure that maintains a collection of elements

#### unordered set

i.e. ``std::unordered_set``

unordered_set use hasing, and its operations work in O (1) time on average

```cpp
#include  <unordered_set>

void print(std::unordered_set<int>& hs){
    std::cout << "{";
    int size = hs.size(), i = 0;
    for(auto it = hs.begin(); it != hs.end(); ++it, i++){
        if (i == size - 1)
            std::cout << *it << "}\n";
        else
            std::cout << *it << ", ";
    }
}

std::unordered_set<int> hs; // declare set
std::unordered_set<int> hs({1, 2, 3, 4})
std::unordered_set<int>::iterator it // set iterator
hs.insert(key) // insert
hs.emplace(key) // insert key if not present, returns pair (iterator pointing to key, boolean false if key was already present or true if not)
hs.find(key) == hs.end() // boolean key is not in
hs.count(key) == 1 // boolean key is in
hs.erase(key)
hs.clear()
hs.size()
hs.empty() // boolean check if it is empty
```

#### std set

i.e. ``std::set``

based on a balanced binary tree, its operations work in O(logn) time on average


### Map

a generalized array that consists of key-value-pairs elements.

### unordered map

i.e. ``std::unordered_map``

unordered_map use hashing, and its operations work in O (1) time on average

```cpp
#include <unordered_map>

for (auto it = hm.begin(); it != hm.end(); ++it, i++)
    cout << it->first << ", " << it->second;

for (auto kv : map)
	cout << kv.first << ", " << kv.second;
	
std::unordered_map<std::string, int> hm // declare map
std::unordered_map<std::string, int>::iterator it // map iterator
hm["one"] = 1 // insert keys:values
hm["two"] // returns the value at key "two"
hm.begin()
hm.end()
hm.erase(key)
hm.find(key) == hm.end() // boolean key is not it
hm.count(key) // boolean 0/1 key exists
hm.clear()
hm.size()
hm.empty() // check if it is empty
```

#### sorting unordered_map

```c++
// CONVERT map into a vector of pairs
std::vector<pair<int, int>> myVec(hm.begin(), hm.end());

// ORDER unsorted_map by key
int cmpK(pair<int, int> a, pair<int, int> b){
	return a.first < b.first;
}
sort(myVec.begin(), myVec.end(), cmpK);

// ORDER unsorted_map by value
int cmpV(pair<int, int> a, pair<int, int> b){
	return a.second < b.second;
}
sort(myVec.begin(), myVec.end(), cmpV);
```

#### std map

i.e. ``std::map``

based on a balanced binary tree, its operations work in O(logn) time on average

### Priority queue or maxHeap std queue
i.e. priority queue, ``std::priority_queue`` by default is a maxheap. 

A priority queue maintains a set of elements. The supported operations are insertion and, retrieval and removal of the maximum element. Insertion and removal take O (log n ) time,
and retrieval takes O (1) time

**NB**: For the minheap push() negative values and negate top().

```cpp
#include <queue>

void print(std::priority_queue<int> pq){
    std::cout << "(";
    while (!pq.empty()){
        std::cout << pq.top();
        if (pq.size() > 1)
            std::cout << ", ";
        else
            std::cout << ")\n";
        pq.pop();
    }
}

int arr[6] = { 10, 2, 4, 8, 6, 9 }

std::priority_queue<int> pq
for (int i = 0; i < 6; i++)
	pq.push(arr[i])

pq.empty() // boolean is empty or not
pq.push(4) // insert element
pq.top() // get next to be popped	
pq.pop()
pq.size()
```

**NB**: nice way to initialize a heap, given an array/vector in O(n) using *heapify*. This is the trick:

```cpp
// with an array
int myarr[] = {1,5,8,9,6,7,3,4};
int size = sizeof(myarr) / sizeof(int);
std::priority_queue<int>  pq(myarr, myarr + size);

// with a vector
std::vector<int> myvec{1,5,8,9,6,7,3,4};
std::priority_queue<int>  pq(myvec.begin(), myvec.end());
// OR
std::priority_queue<int> pq(std::less<int>(), vec); // maxheap

// and with > c++17:
std::priority_queue<int> pq(std::greater<int>(), vec); // minheap
```

priority queue using user-defined type

```c++
class Man {
prinvate:
	int m_age;
	// ...
public:
	Man(int age) : m_age(age) {}
	// ...
	bool operator<(const Man& another) const {
		return age < another.age;
	}
}
```

### Linkedlists std list

i.e. ``std::list``

is a data structure that consists of a sequence of elements, each connected to the next one through pointers. Unlike arrays, linked lists do not have a fixed size, and elements can be dynamically allocated and deallocated. The basic building block of a linked list is a node, and each node contains data and a pointer/reference to the next node in the sequence

```c++
#include <iostream>
#include <list>

int main() {
    // Creating a linked list using std::list
    std::list<int> myList;

    // Inserting elements at the beginning
    myList.push_front(1);
    myList.push_front(7);
    myList.push_front(3);

    // Displaying the linked list
    std::cout << "Linked List: ";
    for (const auto& element : myList) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}
```

other useful methods

```c++
myList.push_back(value); // Adds an element to the end of the list
myList.push_front(value); // Adds an element to the beginning of the list
myList.pop_back(); // Removes the last element in the list
myList.pop_front(); // Removes the first element in the list

auto iterator = myList.insert(position, value); // Inserts an element before the specified iterator position

myList.erase(position); // Removes the element at the specified iterator position
myList.erase(first, last); // Removes elements in the range [first, last)
myList.clear(); // Removes all elements from the list

size_t size = myList.size(); // Returns the number of elements in the list
bool isEmpty = myList.empty(); // Returns true if the list is empty, false otherwise

auto firstElement = myList.front(); // Returns a reference to the first element in the list
auto lastElement = myList.back(); // Returns a reference to the last element in the list
auto beginIterator = myList.begin(); // Returns an iterator pointing to the first element
auto endIterator = myList.end(); // Returns an iterator pointing one past the last element

myList.reverse(); // Reverses the order of elements in the list
myList.sort(); // Sorts the elements in the list in ascending order
myList1.merge(myList2); // Merges two sorted lists into one sorted list
```

### Tuples std tuple

A tuple is an object that can hold a number of elements. The elements of the same tuple can be at the same time of different data types.

```cpp
#include<tuple>
// Declaring tuple then init
std::tuple <char,int,float> tu;
tu = make_tuple('a',10,15.5);
// Declare & Init
std::tuple<char,int,float> tu(20,'g',17.5);
std::tuple_size<decltype(tu)>::value // num of elements
tup1.swap(tup2)

// unpacking
tie(i_val, ch_val, f_val) = tu; // without ignore
tie(i_val,ignore,f_val) = tu; // ignoring char value
```

### Pairs std pair

i.e. ``std::pair``

Like a tuple, it provides a way to store two heterogeneous objects as a single unit.

```cpp
// declaration
std::pair<std::string, float> pr;
// assignment 
pr = std::make_pair("GeeksForGeeks", 4.56);
// but more simply..
pr = {"Mike is the Best", 4.56};
// access the objects using 'first' and 'second'
pr.first // > Mike is the Best
pr.second // > 4.56

// unpacking
std::pair<int, int> pr = { 1, 2 };
int a, b;
tie(a, b) = pr;
```

## Custom data structures
### Binarytree

A tree with max 2 children. 

- **depth**: tree root with no children has depth 1
- **height**: tree root with no children has height 0
- **balanced**: 
	- height of left subt and height of right subt do not differ more then 1
     - left subt is balanced and right subt is balanced
- **Binary Search Tree**:
	- the left subt contains only nodes with keys  *less than*  the node's key
	- the right subt contains only nodes with keys  *greater than* the node's key.
	- both the left and right subt must also be BST

```cpp
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode()
	    : val(0), left(nullptr), right(nullptr){}
	TreeNode(int val) 
	    : val(val), left(nullptr), right(nullptr){}
	TreeNode(int val, TreeNode* left, TreeNode* right) 
	    : val(val), left(left), right(right){}
	~TreeNode(){
	    // std::cout << "deleting node " << val << std::endl;
	    if (left) delete left;
	    if (right) delete right;
	}
};
```

#### BFS
visiting in BFS / levelorder

```cpp
#include <queue>

void  printLevelOrder(TreeNode* root) {
	std::queue<TreeNode*> q;
	q.push(root);
	int levels = 0;
	while (!q.empty()){
	    int size = q.size();
	    for(int i = 0; i < size; i++){
	        TreeNode* t = q.front();
	        std::cout << t->val << std::endl;
	        if (t->left) q.push(t->left);
	        if (t->right) q.push(t->right);
	        q.pop();
	    }
	    levels++;
	    std::cout << std::endl;
	}
	std::cout << "number of levels:" << levels << std::endl;
}
```

#### stackDFS
visiting in DFS using a stack gives **pre-order**

```cpp
#include <stack>

void  printPreOrder(TreeNode* root) {
	std::stack<TreeNode*> s;
	s.push(root);

	while (!s.empty()){
	    TreeNode* t = s.top();
	    
	    std::cout << t->val << std::endl;
	    s.pop();
	    if (t->right) s.push(t->right);
	    if (t->left) s.push(t->left);
	}
}
```

#### recursiveDFS
visiting in DFS using recursion can give **(pre/in/post)-order**

```cpp

void  printPreOrder(TreeNode* root) {
	while (root){
		std::cout << root->val << " " << std::endl; 
		printPreOrder(root->left);
		printPreOrder(root->right);
	}
}

void  printInOrder(TreeNode* root) {
	while (root){ 
		printPreOrder(root->left);
		std::cout << root->val << " " << std::endl;
		printPreOrder(root->right);
	}
}

void  printPostOrder(TreeNode* root) {
	while (root){ 
		printPreOrder(root->left);
		printPreOrder(root->right);		
		std::cout << root->val << " " << std::endl;
	}
}
```

### Trie
i.e. prefix tree

```cpp
#include <unordered_map>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() : root(new TrieNode()) {}

    // Inserts a word into the Trie
    void insert(const std::string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isEndOfWord = true;
    }

    // Searches for a word in the Trie
    bool search(const std::string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                return false; // Prefix not found
            }
            current = current->children[ch];
        }
        return current->isEndOfWord; // Full word found if this node marks the end
    }

    // Checks if a word prefix exists in the Trie
    bool startsWith(const std::string& prefix) {
        TrieNode* current = root;
        for (char ch : prefix) {
            if (current->children.find(ch) == current->children.end()) {
                return false; // Prefix not found
            }
            current = current->children[ch];
        }
        return true; // Prefix found
    }

    // Destructor to delete Trie nodes
    ~Trie() {
        deleteTrie(root);
    }

private:
    // Recursive function to delete Trie nodes
    void deleteTrie(TrieNode* node) {
        for (auto& child : node->children) {
            deleteTrie(child.second);
        }
        delete node;
    }
};
```