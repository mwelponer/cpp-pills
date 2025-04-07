C++ pills
===
Copyright (C) 2021 Michele Welponer

  * [Pointers](#pointers)
    + [Retrieving the Memory Address of a Variable](#retrieving-the-memory-address-of-a-variable)
    + [Declaring a Pointer](#declaring-a-pointer)
    + [Assigning a Pointer](#assigning-a-pointer)
    + [Dereferencing a Pointer](#dereferencing-a-pointer)
    + [Pointer Arithmetic](#pointer-arithmetic)
    + [Pointers and Arrays](#pointers-and-arrays)
    + [Complex Pointer Syntax](#complex-pointer-syntax)
    + [Practical Example with Switch Cases](#practical-example-with-switch-cases)
  * [References](#references)
    + [Declaring and Assigning References](#declaring-and-assigning-references)
    + [Passing by Reference](#passing-by-reference)
    + [Key Note on Passing by Value](#key-note-on-passing-by-value)
    + [Recap](#recap)
    + [Examples](#examples)
  * [Static Keyword](#static-keyword)
    + [General Use](#general-use)
    + [Static Variables Inside Local Scope](#static-variables-inside-local-scope)
    + [Static in Object-Oriented Programming](#static-in-object-oriented-programming)
    + [Static in Singleton Pattern](#static-in-singleton-pattern)
    + [Summary of Static Usage](#summary-of-static-usage)
  * [Enums](#enums)
    + [Syntax and Basic Usage](#syntax-and-basic-usage)
    + [Enums in Classes](#enums-in-classes)
    + [Example Usage](#example-usage)
    + [Key Points About Enums:](#key-points-about-enums-)
    + [Scoped Enums (C++11)](#scoped-enums--c--11-)
  * [Objects and Classes](#objects-and-classes)
    + [Example of a Simple Class](#example-of-a-simple-class)
    + [Constructor and Destructor](#constructor-and-destructor)
    + [Class Inheritance](#class-inheritance)
    + [Virtual Functions for Overriding](#virtual-functions-for-overriding)
    + [Interfaces (Abstract Classes)](#interfaces--abstract-classes-)
    + [Visibility (Access Specifiers)](#visibility--access-specifiers-)
    + [Classes vs. Structs](#classes-vs-structs)
    + [Class Headers and Source Files](#class-headers-and-source-files)
  * [Arrays](#arrays)
    + [Arrays on the Stack Memory](#arrays-on-the-stack-memory)
    + [Arrays on the Heap Memory](#arrays-on-the-heap-memory)
    + [Array Limitations](#array-limitations)
    + [Array Standard Library (`std::array`)](#array-standard-library---std--array--)
    + [Summary Table](#summary-table)
  * [Strings](#strings)
    + [C-Style Strings](#c-style-strings)
    + [C String Handling Functions](#c-string-handling-functions)
    + [Declaring Strings via `char*`](#declaring-strings-via--char--)
    + [Standard Library Strings](#standard-library-strings)
  * [Const](#const)
    + [Normal Use](#normal-use)
    + [With Pointers](#with-pointers)
    + [With Classes](#with-classes)
    + [Mutable Keyword](#mutable-keyword)
    + [Summary of `const` Usage](#summary-of--const--usage)
  * [The ternary operator](#the-ternary-operator)
  * [Memory management](#memory-management)
    + [Stack and Heap Memory Allocation](#stack-and-heap-memory-allocation)
    + [Differences Between Stack and Heap](#differences-between-stack-and-heap)
    + [The `new` Keyword](#the--new--keyword)
  * [Implicit Conversion](#implicit-conversion)
    + [Note on the `explicit` Keyword](#note-on-the--explicit--keyword)
  * [Operator Overloading](#operator-overloading)
    + [Example 1: print std::vector](#example-1--print-std--vector)
    + [Example 2: print custom vec2](#example-2--print-custom-vec2)
    + [Example 3: add custom vec2](#example-3--add-custom-vec2)
    + [Example 4: track memory allocations](#example-4--track-memory-allocations)
    + [Key Notes:](#key-notes-)
  * [The this keyword](#the-this-keyword)
  * [Smart Pointers](#smart-pointers)
    + [Unique Pointers](#unique-pointers)
    + [Shared Pointers](#shared-pointers)
    + [Weak Pointers](#weak-pointers)
  * [The Rule of Five in C++](#the-rule-of-five-in-c--)
    + [1. Destructor](#1-destructor)
    + [2. Copy Constructor](#2-copy-constructor)
    + [3. Copy Assignment Operator](#3-copy-assignment-operator)
    + [4. Move Constructor](#4-move-constructor)
    + [5. Move Assignment Operator](#5-move-assignment-operator)
    + [Why the Rule of Five Matters](#why-the-rule-of-five-matters)
    + [Example: A Complete Rule of Five Implementation](#example--a-complete-rule-of-five-implementation)
  * [The Arrow Operator](#the-arrow-operator)
    + [Stack vs. Heap Access](#stack-vs-heap-access)
    + [Example](#example)
    + [Using with `this`](#using-with--this-)
    + [Overloading the Arrow Operator](#overloading-the-arrow-operator)
  * [Dynamic Arrays](#dynamic-arrays)
    + [Optimizations](#optimizations)
    + [Example: Using a Dynamic Array](#example--using-a-dynamic-array)
  * [Static and Dynamic Libraries](#static-and-dynamic-libraries)
    + [Static Linking](#static-linking)
    + [Dynamic Linking](#dynamic-linking)
  * [Templates](#templates)
    + [Example: Template Class](#example--template-class)
    + [Template Functions](#template-functions)
    + [Advantages of Templates](#advantages-of-templates)
  * [Macros](#macros)
  * [Namespace](#namespace)
    + [Key Concepts](#key-concepts)
    + [Namespace Nesting](#namespace-nesting)
  * [Function pointers](#function-pointers)
  * [Lambdas](#lambdas)
    + [Components of a Lambda](#components-of-a-lambda)
    + [Examples](#examples-1)
    + [Other Examples](#other-examples)

  * [Multidimensional arrays](#multidimensional-arrays)
  * [Sorting std sort](#sorting-std-sort)
  * [type Punning](#type-punning)
  * [Union](#union)
  * [Virtual Destructors](#virtual-destructors)
  * [Casting](#casting)
    + [static cast](#static-cast)
    + [dynamic cast](#dynamic-cast)
    + [reinterpret cast](#reinterpret-cast)
    + [const cast](#const-cast)
  * [Singleton](#singleton)
  * [lvalues and rvalues](#lvalues-and-rvalues)
    + [lvalue](#lvalue)
    + [rvalue](#rvalue)
  * [Logical operators](#logical-operators)
  * [Bitwise operators](#bitwise-operators)
  * [Threads](#threads)
    + [Mutex](#mutex)
    + [Condition variables](#condition-variables)
      - [std::lock_guard vs std::unique_lock](#std--lock-guard-vs-std--unique-lock)
    + [BOOST library semplification](#boost-library-semplification)
      - [Lockfree Queue](#lockfree-queue)
      - [Atomic operations](#atomic-operations)
  * [Standard input](#standard-input)
  * [Input file stream](#input-file-stream)
  * [CMake](#cmake)
    + [subdirectories](#subdirectories)
    + [include](#include)
    + [multiple translation units / main entry points](#multiple-translation-units---main-entry-points)
    + [library](#library)

<small><i><a href='http://ecotrust-canada.github.io/markdown-toc/'>Table of contents generated with markdown-toc</a></i></small>




## Pointers

Pointers are variables that hold the **memory address** of another variable. A pointer "points" to a specific location in memory, which is the starting location of a memory block (its size depends on the type of data stored).


### Retrieving the Memory Address of a Variable

To retrieve the **memory address** of a variable, use the **`&` (address-of operator)** in front of the variable name.

```cpp
std::cout << "myVar addr: " << &myVar << std::endl;
```


### Declaring a Pointer

A pointer is declared using an asterisk (`*`) after the type of the variable it will point to:

```cpp
int* myPointer; // or
int* myPointer = nullptr;
```

**`NOTE`**: `nullptr` is safer than `NULL` or `0`


### Assigning a Pointer

A pointer can be assigned the memory address of a variable using the `&` operator:

```cpp
int a = 3;
int* myPointer = &a;
```

Now, `myPointer` points to `a` and holds its memory address.


### Dereferencing a Pointer

Dereferencing a pointer means accessing the value stored at the memory address it points to. This is done using the asterisk (`*`) operator in front of the pointer.

**Reading the Value**

```cpp
int b = *myPtr; // b is assigned the value stored at the address pointed to by myPtr (3)
```

**Writing to the Value**

```cpp
*myPtr = 6; // Assigns 6 to the variable 'a', which is pointed to by myPtr
```

**Incrementing the Value via the Pointer**

You can increment the value of the variable pointed to by a pointer:

```cpp
++(*myPtr);  // Pre-increment: increments the value before using it
(*myPtr)++;  // Post-increment: increments the value after using it
```


### Pointer Arithmetic

Pointers support arithmetic operations. For example, incrementing a pointer moves it to the next memory location for the type it points to:

```cpp
int arr[] = {10, 20, 30};
int* ptr = arr;

std::cout << *ptr << std::endl;   // 10
ptr++;
std::cout << *ptr << std::endl;   // 20
```


### Pointers and Arrays

The array subscript operator (`[]`) is essentially syntactic sugar for pointer arithmetic. 

```cpp
char str[] = "Hello";
char* ptr = str;

std::cout << str << std::endl; // Hello
std::cout << str[1] << std::endl; // 'e'

std::cout << ptr << std::endl; // Hello
std::cout << *ptr << std::endl; // H
std::cout << ptr[1] << std::endl;  // 'e', equivalent to *(ptr + 1)
```

**`NOTE`**: The array subscript operator `[]` in `char str[]` is secretly a pointer, so it's somehow like to write something like ~~`char* str`~~ but sintattically it is not correct


### Complex Pointer Syntax

Certain pointer expressions can seem confusing, but understanding the order of operations clarifies them:

**Syntax Examples:**

1.  **Pre-increment Pointer, Then Dereference**:
    
    ```cpp
    *++ptr;  // Increment the pointer, then dereference the new address
    ```
    
2.  **Dereference, Then Pre-increment the Value**:
    
    ```cpp
    ++*ptr;  // Increment the value stored at the address pointed to by ptr
    ```
    
3.  **Dereference, Then Post-increment the Pointer**:
    
    ```cpp
    *ptr++;  // Dereference the current pointer, then increment the pointer
    ```
`p*++`, `p++*` and `++p*` are all **syntax errors**.

**`NOTE`**: if you are asking yourself where a pointer is stored, the answer is anywhere in the memory, as a pointer is just an integer variable holding the memory address of the variable it is pointing to. If you are curious to know the memory address of a pointer, use the address-of operator `&` or the `std::addressof()` function:

```cpp
int* ptr = nullptr;
std::cout << "Address of ptr: " << &ptr << std::endl;
```


### Practical Example with Switch Cases

The following example demonstrates various pointer operations:

```cpp
int b[] = {3, 0, 7};
int* p = b;

switch (4) {
    case 1:
        std::cout << *++p << std::endl; // Increment p, then dereference -> 0
        std::cout << *++p << std::endl; // -> 7
        break;

    case 2:
        std::cout << ++*p << std::endl; // Increment the value at p -> 4
        std::cout << ++*p << std::endl; // -> 5
        break;

    case 3:
        std::cout << *p++ << std::endl; // Dereference p, then increment -> 3
        std::cout << *p++ << std::endl; // -> 0
        break;

    case 4:
        std::cout << (*p)++ << std::endl; // Dereference p, print, then increment -> 3
        std::cout << (*p)++ << std::endl; // -> 4
        break;

    default:
        break;
}

std::cout << b[0] << " " << b[1] << " " << b[2] << std::endl;
```






## References

References in C++ are less flexible but more convenient than pointers. They serve as **aliases** for other variables, providing an alternative way to access them. References are essentially syntax sugar for pointers, and anything you can achieve with references can also be achieved using pointers.


### Declaring and Assigning References

A reference is declared using the `&` symbol (as part of the type). When declaring a reference, it must be initialized immediately to bind it to a variable.

```cpp
int& myRef1 = myVar;   // myRef1 is now an alias for myVar
int& myRef2 = *myPtr;  // myRef2 is an alias for the variable pointed to by myPtr
myRef2 = 3;            // Assigns 3 to the variable referenced by myPtr
```


### Passing by Reference

References are often used to pass variables to functions "by reference," allowing the function to modify the original variable. This is a more concise alternative to passing pointers.

**Example: Passing by Pointer vs. Passing by Reference**

Using pointers:

```cpp
void incrementUsingPointer(int* value) {
    (*value)++;  // Dereference the pointer first to modify the value
    std::cout << "Value in function: " << *value << std::endl;
}
```

Using references:

```cpp
void incrementUsingReference(int& value) {
    value++;  // Directly modify the referenced variable
    std::cout << "Value in function: " << value << std::endl;
}
```

By value (no modification to the original variable): 

```cpp
void increment(int value) {
    value++;
    std::cout << "Value in function: " << value << std::endl;
}
```

`NOTE`: if we don't use by reference or by pointer and we simply use `increment(int value)` a new `int value` variable will be created, initialized and incremented inside the function, but the external variable (the one we pass to the function won't be modified!)

**Main Function Example:**

```cpp
int main() {
    int a = 5;
    int& ref = a;  // Create a reference to a

    incrementUsingPointer(&a); // '6', a is incremented
    std::cout << a << std::endl; // => 6

    incrementUsingReference(ref); // '7', a is incremented
    std::cout << a << ref << std::endl; // => 7 7

    incrementUsingReference(a); // '8', a is incremented
    std::cout << a << ref << std::endl; // => 8 8

    increment(a); // '9', but a is not modified
    std::cout << a << ref << std::endl; // => 8 8
}
```

**Example with Classes:**

References also work with objects:

```cpp
class Entity {};

void incrementUsingPointer(Entity* e) {
    // Work with the object using the pointer
}

void incrementUsingReference(Entity& e) {
    // Work with the object using the reference
}

int main() {
    Entity e1;                    // Instance on the stack
    incrementUsingPointer(&e1);   // Pass pointer
    incrementUsingReference(e1);  // Pass reference

    Entity* e2 = new Entity();    // Instance on the heap
    incrementUsingPointer(e2);    // Pass pointer
    incrementUsingReference(*e2); // Pass dereferenced pointer as a reference
    delete e2;
}
```


### Key Note on Passing by Value

If a variable is passed by value (e.g., `increment(int value)`), a **new variable** is created inside the function. Any modifications made to it do not affect the original variable outside the function.


### Recap


| Code                | Meaning                                                                 
|-|--|
| `T* p = nullptr;`   | Declare a pointer `p` of type `T`, initialized to `nullptr`
| `T& r = v;`         | Declare a reference `r` of type `T` to the variable `v`; `r` is an alias for `v`
| `*p`                | Dereference pointer `p` to access the value it points to
| `&v`                | Get the memory address of variable `v`, which can be assigned to a pointer


### Examples

```cpp
int a = 3; // Declare a variable
int* ptr = nullptr; // Declare a pointer
ptr = &a; // Assign the address of a to ptr
std::cout << *ptr << std::endl; // Dereference ptr to get the value, => 3

int& ref = a; // Create a reference (alias) to a
std::cout << ref << std::endl; // Output the value of a via the reference, => 3

int& ref2 = *ptr; // Create a reference to the value pointed to by ptr
std::cout << ref2 << std::endl; // Output the value, => 3

ref++; // Increment the value using the reference
std::cout << a << " " << *ptr << " " << ref << std::endl; // => 4 4 4

a++; // Increment the variable directly
std::cout << a << " " << *ptr << " " << ref << std::endl;  // => 5 5 5

(*ptr)++; // Increment the value via the pointer
std::cout << a << " " << *ptr << " " << ref << std::endl;  // => 6 6 6
```









## Static Keyword

The `static` keyword has different uses depending on the context. It can be applied to variables, functions, and class members, with behavior varying between global, local, and object-oriented scopes.


### General Use

**`static` Variables and Functions (Outside a Class/Struct)**

```cpp
static int myVariable = 5;
static void myFunc();
```

-   **`myVariable`**: A static global variable is visible only within the specific **translation unit** (file) where it is declared. This means you can define another variable with the same name in a different translation unit without causing linking conflicts.
-   **`myFunc`**: A static global function is similarly restricted to the translation unit.

This behavior is equivalent to making the variable or function "private" to the file.

**`NOTE`**: if you don't declare a global variable as `static` (e.g., `int var = 5;`), you can access it from another translation unit using the `extern` keyword:

```cpp
// In translation unit A:
int var = 5;

// In translation unit B:
extern int var; // Refers to the variable defined in unit A
```

**Best Practice**: Always mark global functions and variables as `static` unless you explicitly need them to be accessible across different translation units.


### Static Variables Inside Local Scope

A `static` variable declared within a local scope (e.g., inside a function or loop) retains its value between calls to that scope. Unlike regular local variables, it is only initialized once and persists for the lifetime of the program.

**Example:**

```cpp
void func() {
	static int i = 0;
	std::cout << ++i << std::endl;
}
```

-   The first time `func()` is called, `i` is initialized to `0`, then incremented to `1`.
-   On subsequent calls, `i` retains its value and is incremented further.

**Output**:

```cpp
func(); // Output: 1
func(); // Output: 2
func(); // Output: 3
```

This is similar to declaring `i` globally, but since it is scoped to the function, it can only be modified within `func()`.


### Static in Object-Oriented Programming

When used inside a class or struct, `static` members are shared across all instances of that class.

**Example:**

```cpp
struct Entity {
	static int x; // Shared by all Entity instances
	int y;        // Unique to each instance

	void print() {
		std::cout << "x: " << x << ", y: " << y << std::endl;
	}

	static void s_print() {
		std::cout << "x: " << x << std::endl;
		// Cannot access non-static members (e.g., y) here
	}
};
```

-   **Static Variables (`x`)**: Shared among all instances. Modifying `x` from one instance affects all instances.
-   **Static Methods (`s_print`)**: Can only access static members. They do not have access to non-static members (`y`).

**Example Usage:**

```cpp
Entity::x = 10; // Set the shared static member

Entity e1, e2;
e1.y = 20; // Instance-specific member
e2.y = 30;

e1.print();  // Output: x: 10, y: 20
e2.print();  // Output: x: 10, y: 30
Entity::s_print(); // Output: x: 10
```


### Static in Singleton Pattern

The `static` keyword is commonly used in implementing the **Singleton Pattern** to ensure only one instance of a class exists.

**Traditional Singleton Implementation:**

```cpp
class Singleton {
private:
	static Singleton* s_instance; // Static global declaration

public:
	static Singleton& get() {
		return *s_instance;
	}

	void hello() {
		std::cout << "Hello from Singleton!" << std::endl;
	}
};

// Define the static instance
Singleton* Singleton::s_instance = nullptr;

int main() {
	Singleton::get().hello();
	return 0;
}
```

**Cleaner Singleton with Static Local Variable:**

A more concise implementation involves declaring the static instance within the scope of the `get` method:

```cpp
class Singleton {
public:
	static Singleton& get() {
		static Singleton instance; // Scoped static instance
		return instance;
	}

	void hello() {
		std::cout << "Hello from Singleton!" << std::endl;
	}
};

int main() {
	Singleton::get().hello();
	return 0;
}
```

-   In this approach, the `static` instance is initialized only once, the first time `get()` is called. This avoids manual memory management (e.g., `new` and `delete`).


### Summary of Static Usage

Context | Behavior
-|-
**Global Scope** | Limits visibility of variables or functions to the translation unit.
**Local Scope** | Persists the variable's value across multiple function calls.
**Class Members** |  Shared across all instances (for static variables and methods).













## Enums

Enums (short for **enumerations**) define a set of named constant integer values. They provide a way to make code more readable by replacing magic numbers with meaningful names.


### Syntax and Basic Usage

```cpp
enum Example /* Optionally specify the underlying type */ : unsigned char {
	A, B, C // A = 0, B = 1, C = 2 (default behavior)
	// A = 4, B, C // A = 4, B = 5, C = 6
	// A = 5, B = 3, C = 7 // Custom values can be assigned
};
```

-   By default, the first enumerator starts at `0`, and subsequent values increment by `1`.
-   You can optionally specify the underlying integer type for the enum (e.g., `unsigned char`, `int`, `unsigned int`, etc.).
-   Values can also be explicitly assigned.

**Example:**

```cpp
enum Color : unsigned int {
	Red = 1, Green = 2, Blue = 4
};

Color myColor = Green;
std::cout << myColor << std::endl; // Output: 2
```


### Enums in Classes

Enums can also be declared inside classes, often to define states, levels, or other related constants.

**Example:**

```cpp
class Log {
public:
	enum Level {
		Error,   // 0
		Warning, // 1
		Info     // 2
	};

private:
	Level m_logLevel = Info; // Default level

public:
	void setLevel(Level level) { m_logLevel = level; }

	void printLevel() const {
		switch (m_logLevel) {
			case Error:
				std::cout << "Error" << std::endl;
				break;
			case Warning:
				std::cout << "Warning" << std::endl;
				break;
			case Info:
				std::cout << "Info" << std::endl;
				break;
		}
	}
};
```


### Example Usage

```cpp
int main() {
	// Using an enum outside of a class
	Example value = B; // Assign enum value B (1) to 'value'
	std::cout << value << std::endl; // Output: 1

	// Using an enum within a class
	Log log;
	log.setLevel(Log::Error); // Set log level to Error
	log.printLevel();         // Output: Error

	return 0;
}
```


### Key Points About Enums:

1.  **Enumerators as Constants**: Enum values are constants, so they can be used anywhere a constant expression is allowed.
2.  **Scope**:
    -   Regular enums are placed in the global namespace, so enumerator names can clash with other identifiers.
    -   Use **scoped enums** (introduced in C++11) to avoid this (e.g., `enum class`).
3.  **Underlying Type**:
    -   By default, enums use `int` as the underlying type.
    -   You can explicitly specify a different type (e.g., `unsigned char` or `unsigned int`).


### Scoped Enums (C++11)

Scoped enums (declared with `enum class`) provide better type safety and scoping compared to regular enums. Enumerators of scoped enums must be prefixed with the enum type name.

**Example:**

```cpp
enum class Fruit : int {
	Apple = 1,
	Orange = 2,
	Banana = 3
};

Fruit f = Fruit::Apple; // Must specify the enum type name (Fruit::)
std::cout << static_cast<int>(f) << std::endl; // Output: 1
```

-   Scoped enums prevent implicit conversion to integers, improving type safety.
-   To use the value as an integer, you must explicitly cast it (e.g., `static_cast<int>`).











## Objects and Classes


### Example of a Simple Class

```cpp
class Entity {
private:
    std::string m_name;
    int m_age;

public:
    Entity() {} // Default constructor

    const std::string& getName() const { return m_name; }
    void setName(const std::string& name) { 
        this->m_name = name; 
    }
};
```

-   `this` is a pointer to the current object.
-   The `->` operator dereferences the pointer and accesses the member method or field.


### Constructor and Destructor

The `Entity` object can be initialized with default values for its fields using a constructor. Here's an example with initialization:

```cpp
class Entity {
private:
    std::string m_name;
    int m_age;

public:
    // Constructor with initializer list (more efficient)
    Entity() 
        : m_name("Unknown"), m_age(0) 
    {
        std::cout << "Entity created" << std::endl;
    }

    // Destructor
    ~Entity() {
        std::cout << "Entity destroyed!" << std::endl;
    }
};
```

-   **Initializer list** is preferred because it avoids redundant default construction followed by reassignment.
-   The destructor `~Entity()` is automatically called when the object goes out of scope or is explicitly deleted.


**`NOTE`**:

-   If the object is created **on the heap** (using `new`), it must be manually deallocated using `delete`.
-   If the object is created **on the stack**, it will automatically be destroyed when the program exits the scope.

**Example:**

```cpp
int main() {
    Entity* e1 = new Entity(); // On the heap
    delete e1; // Manual cleanup

    Entity e2; // On the stack
    // Automatically destroyed when exiting scope
    return 0;
}
```


### Class Inheritance

Inheritance allows one class to derive from another.

```cpp
class Player : public Entity {
private:
    int m_points;

public:
    Player() : m_points(0) {}
};
```

-   The `Player` class inherits all methods and fields from `Entity`.
-   It can also add new functionality or **override** methods from the base class.


### Virtual Functions for Overriding

Virtual functions allow derived classes to override base class methods.

```cpp
class Entity {
public:
    virtual std::string getName() { return "Entity"; }
};

class Player : public Entity {
private:
    std::string m_name;

public:
    Player(const std::string& name) : m_name(name) {}

    std::string getName() override { return m_name; }
};

int main() {
    Entity* entity = new Player("Mike");
    std::cout << entity->getName() << std::endl; // Output: Mike
    delete entity;
}
```

-   If the base class method is not declared `virtual`, the output would be `Entity` (no polymorphism).
-   Always mark overridden methods in derived classes with `override` for clarity and error checking.


### Interfaces (Abstract Classes)

Interfaces are implemented using **pure virtual functions**. These are functions that have no implementation in the base class and must be implemented by derived classes.

```cpp
class Printable {
public:
    virtual std::string getClassName() const = 0; // Pure virtual function
};
```

-   The `= 0` syntax makes the function pure virtual.
-   A class with at least one pure virtual function is an **abstract class** and cannot be instantiated directly.

**Example:**

```cpp
class Player : public Printable {
public:
    std::string getClassName() const override { return "Player"; }
};
```


### Visibility (Access Specifiers)

Access specifiers control the visibility of class members.

```cpp
class Entity {
private:
    int x, y; // Accessible only within the class

protected:
    std::string name; // Accessible in the class and derived classes

public:
    void getCoordinates() {} // Accessible from anywhere
};
```

-   **`public`**: Accessible everywhere.
-   **`protected`**: Accessible within the class and its subclasses.
-   **`private`**: Accessible only within the class.

**Default Visibility:**

-   **Classes**: Members are `private` by default.
-   **Structs**: Members are `public` by default.


### Classes vs. Structs

The only difference between a `class` and a `struct` in C++ is the default visibility of members:

-   **Class**: Private by default.
-   **Struct**: Public by default.

**Example:**

```cpp
class CEntity {
    int a, b; // Private by default

public:
    CEntity(int a, int b) : a(a), b(b) {}
};

struct SEntity {
    int a, b; // Public by default
};
```

**`NOTE`**: struct remain in c++ just to maintain the compatibility with c that doesn't have classes


### Class Headers and Source Files

To maintain code organization, class declarations are typically separated into `.h` (header) and `.cpp` (implementation) files.

**`Human.h`**

```cpp
#pragma once
#include <string>

class Human {
private:
    std::string m_name;
    int m_age;

public:
    Human();
    Human(const std::string& name, int age);
    ~Human();

    void print() const;
    int getAge() const;
};
```

**`Human.cpp`**

```cpp
#include "Human.h"
#include <iostream>

Human::Human() 
    : m_name("unknown"), m_age(0) {}

Human::Human(const std::string& name, int age) 
    : m_name(name), m_age(age) {}

Human::~Human() {
    std::cout << "Human destroyed" << std::endl;
}

void Human::print() const {
    std::cout << "Human: " << m_name << ", age: " << m_age << std::endl;
}

int Human::getAge() const {
    return m_age;
}
```










## Arrays


### Arrays on the Stack Memory

```cpp
int stackArr[4]; // Declare: stackArr is now a pointer to the first element of the array
int stackArr[] = {1, 2, 3, 4}; // Declare and initialize
stackArr[3] = 666; // Modify the fourth element
```

-   The array name (e.g., `stackArr`) is a constant pointer to the first element of the array.
-   You **cannot** use increment (`++`) or decrement (`--`) operators on the array name (e.g., ~~`stackArr++`~~) because it is not an lvalue pointer.

However, you can work with a separate pointer:

```cpp
int* ptr = stackArr; // Pointer to the array
std::cout << *(++ptr) << std::endl; // Output: 2
*(ptr + 2) = 666; // Equivalent to stackArr[3] = 666
```

**`FUN FACT`**:  In **release mode**, accessing out-of-bounds elements in an array does not throw an error (no bounds checking). This can lead to undefined behavior. Always implement safety checks to avoid this!


### Arrays on the Heap Memory

```cpp
int* heapArr = new int[10]; // Allocate an array of 10 integers on the heap
heapArr[0] = 1;             // Assign a value
delete[] heapArr;           // Deallocate the memory
```

**Why use heap arrays?**  
The difference lies in the **lifetime** of the array:

-   Stack memory: Automatically deallocated when the scope ends.
-   Heap memory: Persists until explicitly deallocated using `delete[]`.

**Example**:  
If a function needs to return an array, it must allocate it on the heap:

```cpp
int* createArray(int size) {
    return new int[size];
}
```

In general, prefer stack arrays for better performance and safety, as they avoid pointer indirection.

**Example:**

```cpp
class Entity {
public:
    int stackArr[10]; // Array stored directly in the object
    // If using a heap array:
    // int* heapArr = new int[10]; // Entity will only store a pointer (the data is in another space in memory)

    Entity() {
        for (int i = 0; i < 10; i++)
            stackArr[i] = 0; // Initialize stack array
    }
};
```


### Array Limitations

Raw arrays in C++ **do not** have built-in `.size()` or `.length()` methods. Here are two ways to determine the size:

1.  **For Stack Arrays**:
    
    ```cpp
    int stackArr[4];
    int length = sizeof(stackArr) / sizeof(int); // Calculate the size
    ```
    
2.  **For Heap Arrays**: You must manually track the size:
    
    ```cpp
    static const int numOfElements = 10;
    int* heapArr = new int[numOfElements];
    ```
    
    
### Array Standard Library (`std::array`)

The C++ Standard Library provides a safer and more feature-rich alternative: `std::array`.

```cpp
#include <array>

std::array<int, 10> stdArr; // Declare an array of size 10
stdArr[0] = 1;              // Assign a value
std::cout << stdArr.size() << std::endl; // Output: 10
```

**Advantages**:

-   Built-in size tracking with `.size()`.
-   Bounds checking (with exceptions) when using `.at()`.

**Disadvantage**:

-   Slightly more overhead compared to raw arrays.


### Summary Table

**Code** | **Meaning**
-|-
`T ar[n]` | Declare an array `ar` of `n` elements of type `T`.
`&ar[0]` | Address of the first element of the array `ar`.
`&ar` | Address of the first element of the array `ar`. (Same as `&ar[0]`)
`ar` | Address of the first element of the array `ar`. (Implicit pointer)
`T* p = ar` | Create a pointer `p` that points to the first element of array `ar`.
`*(ar + 1)` | Access the second element of array `ar`.
`ar[1]` | Access the second element of array `ar`. (Equivalent to `*(ar + 1)`)
`T* har = new T[n]` | Declare a heap array `har` of `n` elements of type `T`.
`delete[] har` | Delete the heap array `har`.

















## Strings


### C-Style Strings

C-Style strings, also known as **null-terminated strings**, are simply arrays of characters terminated with a special character: `'\0'`. This null character signals the end of the string.

If you declare the string **manually**, you must include the null terminator explicitly:

```cpp
char str[] = "Hello"; // Null terminator '\0' is automatically added
char myString[5] = {'M', 'i', 'k', 'e', '\0'}; // Manual null terminator
std::cout << myString << std::endl; // Output: Mike
```

### C String Handling Functions

To manipulate C-Style strings, you can use functions provided by the `<cstring>` library.

```cpp
#include <cstring>
```

**Function** | **Description**
-|-
`strcpy(destination, source)` | Copies the source string to the destination. The destination must be large enough to hold the source string, including the null terminator.
`strcat(destination, source)` | Appends the source string to the destination string. The destination must have enough space for the combined string.
`strcmp(str1, str2)` | Compares two strings lexicographically. Returns `0` if they are equal, a negative value if `str1` is less than `str2`, or a positive value if `str1` is greater.
`strlen(str)` | Returns the length of the string (excluding the null terminator).

Additionally, you can use functions from `<cctype>` for character-level checks:

```cpp
#include <cctype>
```

**Function** |  **Description**
-|-
`isalnum(char)` | Checks if the character is alphanumeric.


### Declaring Strings via `char*`

When you declare a string as a **character pointer** (`char*`), it is **immutable** in the sense that you cannot change the length of the string. For this reason, such declarations are often marked as `const`. The `<cstring>` library can also be used to manipulate strings declared in this way.

**Example:**

```cpp
#include <cstring>

const char* name = "Mike";
std::cout << name << ", " << strlen(name) << std::endl; // Output: Mike, 4

char* str1 = "Ciao";
char str2[40];
strcpy(str2, str1); // Copy str1 into str2
std::cout << str2 << std::endl; // Output: Ciao
```

**`NOTE`**: Modifying a string literal (like `"Ciao"`) through a `char*` pointer is undefined behavior.


### Standard Library Strings

C++ provides a safer and more versatile string implementation in the Standard Library: `std::string`.

**Example:**

```cpp
#include <string>

std::string myString = "ciao";
myString += "!"; // Append a character or string
std::cout << myString << std::endl; // Output: ciao!

// Useful methods:
std::cout << myString.size() << std::endl; // Get the length of the string
std::cout << myString.find("ao") << std::endl; // Find the position of a substring
bool contains = myString.find("c") != std::string::npos; // Check if a substring exists
```

**Method** | **Description**
-|-
`size()` or `length()` | Returns the length of the string.
`find(substring)` | Returns the position of the first occurrence of `substring`, or `std::string::npos` if not found.
`substr(pos, len)` | Returns a substring starting at position `pos` with length `len`.
`empty()` | Checks if the string is empty.
`clear()` | Removes all characters from the string.

**Advantages of `std::string`**:

-   Dynamic size.
-   Built-in support for various operations like concatenation, searching, and substring extraction.
-   Safer and less error-prone compared to C-Style strings.












## Const


### Normal Use

```cpp
const int MAX_AGE = 90;
```

The `const` keyword makes a variable constant, meaning its value cannot be modified after initialization. In this example, `MAX_AGE` is a constant.


### With Pointers

**Const BEFORE the asterisk (`*`)**:  
The data the pointer points to **cannot be modified**, but the pointer itself can change to point to another address.

```cpp
const int* a = new int; // or 
int const* a = new int;

*a = 5; // Compile Error!!!
a = &MAX_AGE; // Allowed: Pointer can point to a different address
```

**Const AFTER the asterisk (`*`)**:  
The pointer itself is constant, so its address cannot change, but the data it points to **can be modified**.

```cpp
int* const b = new int;
*b = 5; // Allowed: Can modify the value the pointer points to
b = &MAX_AGE; // Compile Error!
```

**Const BOTH BEFORE and AFTER the asterisk (`*`)**:  
Both the pointer and the value it points to are immutable.

```cpp
const int* const c = new int;
*c = 5; // Compile Error: Cannot modify the value the pointer points to
c = &MAX_AGE; // Compile Error: Cannot modify the pointer's address
```


### With Classes

Declaring a method as `const` ensures that the method **does not modify any member variables** of the class. This distinction is crucial when working with `const` objects or references.

**Rule**:  
_Const objects can only call const methods._ Non-const objects can call both const and non-const methods.

**Example:**

```cpp
class Entity {
private:
    int m_X, m_Y;

public:
    // Non-const method: Can modify member variables
    int getX() {
        m_X = 2; // Allowed
        return m_X;
    }

    // Const method: Cannot modify member variables
    int getX() const {
        // m_X = 2; // Error: Cannot modify m_X in a const method
        return m_X;
    }
};
```

**Why Use `const` Methods?**

If an `Entity` object is passed as a **const reference** to a function, the non-const method `getX()` cannot be called. You need a `const` version of the method (`getX() const`) to handle such cases. This guarantees that the method does not unintentionally modify the object.


### Mutable Keyword

Declaring a class member as `mutable` allows it to be modified even inside a `const` method. This is useful for fields used for debugging or caching, where modification doesn't conceptually change the object's state.

```cpp
class Entity {
private:
    int m_X;
    mutable int m_debugCount = 0;

public:
    int getX() const {
        m_debugCount++; // Allowed because m_debugCount is mutable
        // m_X = 3; // Error: Cannot modify m_X in a const method
        return m_X;
    }
};
```


### Summary of `const` Usage

**Context** | **Effect**
-|-
**`const` variable** | Variable's value cannot be changed after initialization.
**`const` pointer** | Prevents modification of what the pointer points to or the pointer itself, depending on placement of `const`.
**Const method** | Ensures the method cannot modify any non-mutable member variables.
**`mutable` members** | Allows modification of specific variables in a const method.









## The ternary operator

The ternary operator is just a syntactic sugar for `if else`

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










## Memory management

```cpp
#include <iostream>
#include <string>

class Entity 
{
private:
    std::string m_name;
    int m_age;
public:
    // Default constructor
    Entity()
        : m_name("Unknown"), m_age(-1) {}

    // Constructor with name
    Entity(const std::string& name)
        : m_name(name), m_age(-1) {}

    // Constructor with age
    Entity(int age)
        : m_name("Unknown"), m_age(age) {}

    // Getters
    std::string getName() const { return m_name; }
    int getAge() const { return m_age; }

    // Setters
    void setName(const std::string& name) { m_name = name; }
    void setAge(int age) { m_age = age; }
};
```


### Stack and Heap Memory Allocation

**Stack Allocation**

Stack allocation happens automatically. When a variable or object goes out of scope, its memory is automatically freed. Stack memory is **limited** but very **fast** because it uses a contiguous block of memory. The destructor for an object is called automatically when it goes out of scope.

```cpp
int value = 4;               // Primitive variable
int array[] = {1, 2, 3, 4};  // Array allocated on the stack
Entity entity("Mike");       // Entity object on the stack
```

**Heap Allocation**

Heap allocation is done manually using the `new` keyword. Objects on the heap persist until explicitly freed using `delete`. Allocating on the heap is slower than stack allocation because the memory manager must find a suitable block of free memory. Additionally, forgetting to free heap memory can lead to **memory leaks**.

```cpp
int* hvalue = new int;
*hvalue = 4;

int* harray = new int[5]; // Array allocated on the heap
harray[0] = 1;
harray[1] = 2;
harray[2] = 3;

Entity* hentity = new Entity("Mike"); // Entity object on the heap

// Free the allocated memory
delete hvalue;
delete[] harray;
delete hentity;
```

**`NOTE`**: whenever we use the word **new**, we need then to `delete`!


### Differences Between Stack and Heap

| Feature                     | Stack                                 | Heap                                    |
|-----------------------------|---------------------------------------|-----------------------------------------|
| **Memory Allocation**       | Automatic (managed by the compiler)  | Manual (requires `new` and `delete`)    |
| **Lifetime**                | Limited to the scope of the variable | Exists until manually freed             |
| **Speed**                   | Faster                               | Slower                                  |
| **Storage**                 | Contiguous memory blocks             | Randomly available memory blocks        |
| **Size**                    | Limited (typically 1-2 MB)           | Large (dependent on system memory)      |
| **Access**                  | Direct access                        | Indirect (via pointers)                 |
| **Cleanup**                 | Automatic (when scope ends)          | Manual (requires explicit cleanup)      |
| **Use Cases**               | Local variables, small objects       | Long-lived or large objects             |
| **Cost of Allocation**      | Minimal                              | More expensive (complex allocation)     |
| **Error Handling**          | Stack overflow (rare)                | Memory leaks if not properly managed    |

**When to Use Heap Allocation:**

1.  **Objects need to persist beyond their scope** (e.g., returned from a function).
2.  **Objects are too large for the stack** (e.g., large arrays).
3.  **Too many objects** might exhaust stack memory.

**Rule of Thumb**: Use stack allocation whenever possible for simplicity and speed. Use heap allocation only when necessary.


### The `new` Keyword

The `new` keyword allocates memory on the **heap** and automatically calls the constructor for the object.

```cpp
int* a = new int;           // Allocates memory for a single int
int* aArr = new int[50];    // Allocates memory for an array of 50 ints

Entity* e = new Entity();   // Allocates memory and calls the constructor

// Equivalent C-style allocation (without constructor call)
Entity* another_e = (Entity*)malloc(sizeof(Entity));

// Allocate an array of Entity objects
Entity* eArr = new Entity[50];

// Free the memory when done
delete a;
delete e;
delete another_e; // C-style allocation does not call the destructor
delete[] aArr;
delete[] eArr;
```

**Important Notes**:

1.  `delete` should be used to free memory allocated with `new`.
2.  Use `delete[]` to free memory allocated for arrays with `new`.
3.  Forgetting to free heap memory leads to **memory leaks**.















## Implicit Conversion

Implicit conversion in C++ refers to the automatic type conversion performed by the compiler from one type to another. Here are some examples:

```c++
// A cool function to print an Entity object
void PrintEntity(const Entity& entity) {
    // Print logic goes here
}

int main() {
	// Implicit conversion!
	Entity a = std::string("Mike");
    // Equivalent to writing: Entity a("Mike"); 
    
    // Implicit conversion!
    Entity b = 43;
    // Equivalent to writing: Entity b(43); 

    // Implicit conversion!
    PrintEntity(22); 
    // `22` is implicitly converted into an Entity with age 22.

    // Implicit conversion! "Cherno" is first cast from 
    // a const char array to a `std::string` and then implicitly 
    // converted into an Entity with name "Cherno".
    PrintEntity(std::string("Cherno"));

    // It can also be explicitly cast to Entity:
    PrintEntity(Entity("Cherno"));
}
```


### Note on the `explicit` Keyword

Using the `explicit` keyword in front of a constructor disables implicit conversions. For example:

```c++
class Entity {
public:
    explicit Entity(const std::string& name) 
        : m_name(name) {}
};
```

In this case:

```c++
int main() {
    // This will cause a compilation error because implicit conversion is disabled!
    PrintEntity(std::string("Mike")); 

    // You need to explicitly construct the Entity object:
    PrintEntity(Entity(std::string("Mike")));
}
```

The `explicit` keyword ensures constructors are only called when explicitly invoked, which helps prevent unintended conversions that may lead to subtle bugs in your code.









## Operator Overloading

The following operators can be overloaded in C++:

`+  -  *  /  %  ^  &  |  ~  !  =  <  >  +=  -=  *=  /=  %=  ^=  &=  |=  <<  >>  >>=  <<=  ==  !=  <=  >=  <=>  &&  ||  ++  --  ,  ->*  ->  ( )  [ ]`

Operators in C++ are essentially functions! You can overload these operators, which means redefining or changing their behavior for specific types in your program. To overload an operator, we use the keyword `operator` followed by the operator symbol. Then, we define the function like any other normal function with its parameters.


### Example 1: print std::vector

**Overloading the `<<` Operator to Print a `std::vector<T>`**

```cpp
template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
  int size = vec.size();
  
  os << "[";
  for (int i = 0; i < size; i++) {
    i == size - 1 ? os << vec[i] : os << vec[i] << ", ";
  }
  os << "]";
  
  return os;
}
```


### Example 2: print custom vec2

**Overloading the `<<` Operator to Print a Custom `vec2<T>`**

**`vec2.h`** file:

```cpp
#pragma once
#include <iostream>

struct vec2 {
    float x, y;
    vec2(float x = 0, float y = 0) : x(x), y(y) {}
};

// Declare the overloaded operator<< function
std::ostream& operator<<(std::ostream& os, const vec2& vec);
```

**`vec2.cpp`** file:

```cpp
#include "vec2.h"

// Define the operator<< function
std::ostream& operator<<(std::ostream& os, const vec2& vec) {
    os << "vec2(" << vec.x << ", " << vec.y << ")";
    return os;
}
```

**Usage:**

```cpp
#include "vec2.h"

int main() {
    vec2 v(3.0f, 4.0f);
    std::cout << v << std::endl;
}
```


### Example 3: add custom vec2

**Overloading the `+` Operator to Add Two `vec2` Objects**

```cpp
struct vec2 {
    float x, y;

    vec2(float x, float y) : x(x), y(y) {}

    // Overloading the + operator to add two vec2 objects
    vec2 operator+(const vec2& other) const {
        return vec2(x + other.x, y + other.y);
    }
};

int main(int, char**){
	vec2 a(1, 2);
	vec2 b(3, 4);
	vec2 c = a + b;
	std::cout << c.x << ", " << c.y << std::endl;
}
```


### Example 4: track memory allocations

**Overloading the `new` Operator to Track Heap Allocation**

```cpp
static uint32_t s_AllocCount = 0;

void* operator new(size_t size) {
    s_AllocCount++;
    std::cout << "Allocating " << size << " bytes\n";
    return malloc(size);
}

void operator delete(void* memory) {
    s_AllocCount--;
    std::cout << "Deallocating memory (" << s_AllocCount<< ")\n";
    free(memory);
}

Entity* e = new Entity("Mike", 25);
delete e;
std::cout << s_AllocCount << " allocations\n";
```


### Key Notes:

-   When overloading operators, the function signature typically follows this pattern: `operator<operator-symbol>(parameters)`.
-   For most operators, we can overload both the normal and compound assignment versions (e.g., `+` and `+=`).
-   `operator new` is a special case and can be overloaded to define custom behavior when allocating memory on the heap.












## The this keyword

it is just the pointer to the current object instance that the method belongs to.

```c++
class Entity {
private:
	int x, y;
public:	
	Entity(int x, int y) {
		// this is a pointer so using -> we first dereference 
		// then we use the Entity object
		this->x = x; 
		this->y = y;
	}
	// some fancy printing function
	void print() {};
};
```











## Smart Pointers

Smart pointers are **scoped pointers** (created on the stack) that point to objects created on the heap. Once the smart pointer goes out of scope, both the pointer and the object it points to are automatically deleted.


### Unique Pointers

A unique pointer is a simple type of smart pointer where the object it points to cannot have more than one reference. `make_unique` is used to create a new `Entity` object that can only have a single pointer reference. 

**`NOTE`**: _You cannot copy unique pointers_: If you have two unique pointers pointing to the same memory location and one of them is destroyed, the memory will be freed, and the second pointer will point to memory that has been freed, which causes undefined behavior.

```c++
// Create a unique pointer to a new Entity
std::unique_ptr<Entity> u1_ptr = std::make_unique<Entity>(7, 4);
u1_ptr->print(); 

// Create another unique pointer and move u1's ownership to u2
std::unique_ptr<Entity> u2_ptr = std::move(u1_ptr);
u2_ptr->print(); // Let's check u2_ptr

// This will cause a segmentation fault!
/* u1_ptr->print(); */ 
// There can only be one unique pointer to the object at a time!
```


### Shared Pointers

A shared pointer can be copied, and it maintains a reference count. The object is only freed when the last shared pointer referencing it is deleted.

```c++
// Create a shared pointer to a new Entity
std::shared_ptr<Entity> s1_ptr = std::make_shared<Entity>(7, 4);
std::cout << "count: " << s1_ptr.use_count() << std::endl; // Let's check the reference count => 1

{ // An inner scope
    // Create another shared pointer and assign it to s1
    std::shared_ptr<Entity> s2_ptr = s1_ptr;

    // Check the reference count
    std::cout << "count: " << s1_ptr.use_count() << std::endl; // => 2

    // When the inner scope exits, the reference count is decremented
}

// Check again
std::cout << "count: " << s1_ptr.use_count() << std::endl; // => 1
```


### Weak Pointers

A weak pointer **does not increment the reference count** of a shared pointer. In the following example, when the inner scope ends, the memory is freed. However, we can still ask the weak pointer if it is expired or still valid.

```c++
// Create a weak pointer
std::weak_ptr<Entity> w_ptr;

{ // An inner scope
    // Create a shared pointer to a new Entity
    std::shared_ptr<Entity> s_ptr = std::make_shared<Entity>(7, 4);

    // Assign the shared pointer to the weak pointer
    w_ptr = s_ptr; // The reference count remains 1

    // Check if the weak pointer is intact
    std::string state = w_ptr.lock() ? "intact" : "gone";
    std::cout << "state: " << state << std::endl; // => intact

    // When the inner scope exits, the reference count becomes 0, 
    // and the Entity object gets freed
}

// Check again
std::string state = w_ptr.lock() ? "intact" : "gone";
std::cout << "state: " << state << std::endl; // => gone
```







## The Rule of Five in C++

ref. https://en.cppreference.com/w/cpp/language/rule_of_three

The **Rule of Five** states that if a class manages resources (e.g., dynamic memory), you should explicitly define the following five special member functions to ensure proper resource management:

1.  **Destructor**
2.  **Copy Constructor**
3.  **Copy Assignment Operator**
4.  **Move Constructor**
5.  **Move Assignment Operator**

This ensures efficient and safe handling of resource ownership, especially during copying and moving operations.


### 1. Destructor

The destructor is called when an object goes out of scope or is deleted. Its primary purpose is to release resources owned by the object, such as memory or file handles.

```cpp
~ClassName() {
    delete[] m_buffer; // Release dynamically allocated memory
}
```

**`NOTE`**: If your class does not manage any resources, the default destructor is sufficient.


### 2. Copy Constructor

Unnecessary copying is to be avoided, but sometimes copying is essential. When working with copying class objects, we must ensure the class provides a proper **copy constructor** to handle copying safely. 
The copy constructor creates a new object as a copy of an existing one. For resource-managing classes, this typically requires **deep copying** to avoid two objects sharing the same resource.

```cpp
ClassName(const ClassName& other)
    : m_size(other.m_size) {
    m_buffer = new char[m_size + 1]; // Allocate new memory
    memcpy(m_buffer, other.m_buffer, m_size + 1); // Copy contents
}
```

**`NOTE`**: If not defined, the compiler provides a shallow-copy copy constructor by default, which can lead to resource management issues like shared memory or double-deletion.


### 3. Copy Assignment Operator

The **copy assignment operator** is used when you want to copy the contents of one object into another already-existing object. This typically involves allocating new resources and copying data from the source object.
The copy assignment operator is invoked when an existing object is assigned from another object. Like the copy constructor, it must perform a **deep copy** while properly handling existing resources.

```cpp
ClassName& operator=(const ClassName& other) {
    if (this == &other) return *this; // Handle self-assignment

    delete[] m_buffer; // Release existing resources

    m_size = other.m_size;
    m_buffer = new char[m_size + 1];
    memcpy(m_buffer, other.m_buffer, m_size + 1);

    return *this;
}
```

**`NOTE`**: If not defined, the compiler provides a shallow-copy version.


### 4. Move Constructor

The move constructor transfers resources from a temporary (rvalue) object to a new object, avoiding unnecessary deep copying and improving performance.
It is especially useful for temporary objects or when optimizing performance.

```cpp
ClassName(ClassName&& other) noexcept
    : m_buffer(other.m_buffer), m_size(other.m_size) {
    other.m_buffer = nullptr; // Leave source in a valid state
    other.m_size = 0;
}
```

**`NOTE`**: This is particularly useful when returning large objects from functions or inserting them into containers.


### 5. Move Assignment Operator

The move assignment operator transfers resources from a temporary (rvalue) object to an existing object. It must handle cleaning up the current object’s resources before taking ownership of the new ones.

```cpp
ClassName& operator=(ClassName&& other) noexcept {
    if (this == &other) return *this; // Handle self-assignment

    delete[] m_buffer; // Release existing resources

    m_buffer = other.m_buffer;
    m_size = other.m_size;

    other.m_buffer = nullptr; // Leave source in a valid state
    other.m_size = 0;

    return *this;
}
```

**`NOTE`**: If not defined, the compiler falls back to inefficient copying or default behavior.


### Why the Rule of Five Matters

The Rule of Five ensures that:

-   Resources are managed properly without memory leaks.
-   Operations like copying and moving are efficient and safe.
-   Your class integrates seamlessly with modern C++ features like standard containers (`std::vector`, `std::unique_ptr`, etc.) that heavily rely on move semantics.

By following the Rule of Five, your classes will be efficient, safe, and compatible with modern C++ practices.
If your class does not manage any resources, the compiler-generated special functions are typically sufficient.


### Example: A Complete Rule of Five Implementation

Here is a complete implementation of a custom `String` class that adheres to the Rule of Five:

```cpp
#include <iostream>
#include <cstring>

class String {
private:
    char* m_buffer;
    size_t m_size;

public:
    // Constructor
    String(const char* string)
        : m_size(strlen(string)), m_buffer(new char[m_size + 1]) {
        memcpy(m_buffer, string, m_size + 1);
    }

    // Destructor
    ~String() {
        delete[] m_buffer;
    }

    // Copy Constructor
    String(const String& other)
        : m_size(other.m_size), m_buffer(new char[other.m_size + 1]) {
        memcpy(m_buffer, other.m_buffer, other.m_size + 1);
        std::cout << "Copy Constructor\n";
    }

    // Copy Assignment Operator
    String& operator=(const String& other) {
        if (this == &other) return *this; // Handle self-assignment

        delete[] m_buffer; // Clean up current resources

        m_size = other.m_size;
        m_buffer = new char[m_size + 1];
        memcpy(m_buffer, other.m_buffer, m_size + 1);

        std::cout << "Copy Assignment Operator\n";
        return *this;
    }

    // Move Constructor
    String(String&& other) noexcept
        : m_buffer(other.m_buffer), m_size(other.m_size) {
        other.m_buffer = nullptr;
        other.m_size = 0;
        std::cout << "Move Constructor\n";
    }

    // Move Assignment Operator
    String& operator=(String&& other) noexcept {
        if (this == &other) return *this; // Handle self-assignment

        delete[] m_buffer; // Clean up current resources

        m_buffer = other.m_buffer;
        m_size = other.m_size;

        other.m_buffer = nullptr;
        other.m_size = 0;

        std::cout << "Move Assignment Operator\n";
        return *this;
    }

    void Print() const {
        std::cout << m_buffer << std::endl;
    }
};

int main() {
    String s1 = "Hello";
    String s2 = s1;             // Copy Constructor
    String s3 = std::move(s1);  // Move Constructor

    s2 = s3;                    // Copy Assignment Operator
    s3 = std::move(s2);         // Move Assignment Operator

    s3.Print();
    return 0;
}
```













## The Arrow Operator 

The `->` operator is used to access fields or methods of an object through a pointer. It is essentially a shortcut for dereferencing a pointer and then accessing a member of the dereferenced object.


### Stack vs. Heap Access

-   For an object declared on the **stack**, you access its fields or methods using the **dot operator (`.`)**.
-   For an object created on the **heap** (via `new`), you use a **pointer** to the object and access its fields or methods with the **arrow operator (`->`)**.

The arrow operator is equivalent to first dereferencing the pointer and then using the dot operator on the resulting object.


### Example

```cpp
int main() {
    Entity e;        // Create an Entity on the stack
    Entity* ptr = &e; // Pointer to the stack object

    // Access fields/methods via dereferencing
    (*ptr).print();  // Dereference first, then call print()

    // Shortcut using the arrow operator
    ptr->print();    // Equivalent to (*ptr).print()
    ptr->age = 5;    // Modify field through the pointer
}
```

The `->` operator simplifies accessing members of an object through a pointer by combining dereferencing and member access in a single step.


### Using with `this`

Within a class, the `this` pointer refers to the current object. Since `this` is a pointer, you use `this->` to access the object's members or methods. For example:

```cpp
class Entity {
public:
    void print() {
        this->doSomething(); // Access member method using `this->`
    }
private:
    void doSomething() { /* ... */ }
};
```


### Overloading the Arrow Operator 

You can overload the `->` operator for custom classes to define how member access through a pointer behaves. For example, let's create a **Scoped Pointer** class that manages the lifetime of a dynamically allocated object:

**Scoped Pointer Example**

```cpp
class Entity {
public:
    void print() const { std::cout << "Entity::print()" << std::endl; }
};

class ScopedPtr {
private:
    Entity* m_obj; // Pointer to the managed object
public:
    // Constructor: takes ownership of the passed pointer
    ScopedPtr(Entity* entity) : m_obj(entity) {}

    // Destructor: deletes the managed object
    ~ScopedPtr() { delete m_obj; }

    // Overload the arrow operator
    Entity* operator->() const {
        return m_obj; // Return the managed object
    }
};

int main() {
    // Scoped pointer automatically deletes the object when it goes out of scope
    ScopedPtr entity = new Entity();

    // Use overloaded arrow operator to access methods of the managed object
    entity->print(); 
}
```
















## Dynamic Arrays

A **dynamic array** is a resizable array that does not require specifying its size upfront. In C++, the `std::vector` from the Standard Template Library (STL) is commonly used for dynamic arrays.

```c++
#include <vector>
#include <algorithm> // For std::for_each
#include <iostream>  // For std::cout

// Declaring/Initialize a vector
std::vector<int> v {1, 2, 3, 4, 5};       // Version 1: Direct initialization
std::vector<int> v = {1, 2, 3, 4, 5};    // Version 2: Alternative syntax
std::vector<int> v(3);                   // Size 3, all elements initialized to 0
std::vector<int> v(3, 5);                // Size 3, all elements initialized to 5
std::vector<Point> pointArray;           // Empty vector of custom type `Point`

// Iterating with a lambda function
std::for_each(v.begin(), v.end(), [](int i) { std::cout << i << std::endl; });

// Adding elements 
pointArray.push_back(Point(x, y));
```


### Optimizations

Here are some ways to optimize the use of `std::vector`:

1.  **Reserve Memory in Advance**  
If you know the number of elements you will add to the vector, you can use the `reserve` method to allocate memory ahead of time. This avoids the overhead of resizing the vector multiple times as elements are added.
    
    ```c++
    pointArray.reserve(8); // Reserve space for 8 elements
    ```
    
2.  **Use `emplace_back` Instead of `push_back`**  
    While `push_back` copies or moves an already constructed object into the vector, `emplace_back` constructs the object directly in-place, reducing unnecessary copying or moving.
    
    ```c++
    pointArray.emplace_back(x, y); // Efficiently construct a new `Point` in the vector
    ```


### Example: Using a Dynamic Array

```c++
#include <vector>
#include <iostream>
#include <algorithm>

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
    void print() const { std::cout << "(" << x << ", " << y << ")" << std::endl; }
};

int main() {
    // Declare a vector of `Point` objects
    std::vector<Point> pointArray;

    // Reserve memory for optimization
    pointArray.reserve(5);

    // Add elements using emplace_back
    pointArray.emplace_back(1, 2);
    pointArray.emplace_back(3, 4);
    pointArray.emplace_back(5, 6);

    // Iterate and print elements
    std::for_each(pointArray.begin(), pointArray.end(), [](const Point& p) {
        p.print();
    });
}
```














## Static and Dynamic Libraries

In C++, libraries can be linked to your program in two main ways: **static linking** and **dynamic linking**.


### Static Linking

With **static linking**, the library code is compiled and embedded directly into your executable file. This results in a larger executable but improves runtime performance because no additional linking occurs during execution. Static linking is ideal when the library doesn't need to be updated independently of the executable.


**Static Linking in *Visual Studio* (Windows)**

1.  **Organize the Library Files**:  
    Create a `Dependencies` directory in your project, and within it, create a subdirectory named after the dependency (e.g., `GLFW`). Inside the dependency folder, include:
    
    -   An `include` folder containing the header files (e.g., `glfw3.h`).
    -   A `lib` folder containing the static library files (e.g., `glfw3.lib`).
2.  **Set Up Include Directories**:  
    Go to **Project Properties > C/C++ > General > Additional Include Directories**:
    
    -   Set the configuration to _All Configurations_ and _Win32_.
    -   Add the include folder path:
        `$(SolutionDir)Dependencies\GLFW\include`
        
3.  **Set Up Library Directories**:  
    Go to **Project Properties > Linker > General > Additional Library Directories**:
    
    -   Add the library folder path:
        `$(SolutionDir)Dependencies\GLFW\lib`
        
4.  **Specify the Library Files**:  
    Go to **Project Properties > Linker > Input > Additional Dependencies**:
    
    -   Add the static library file: `glfw3.lib`

**Static Linking in *VS Code with CMake* (Linux)**

1.  **Install the Library**:
    
    -   Install the library headers and static library files using your package manager (e.g., `sudo apt install libglfw3-dev` for GLFW).
    -   Alternatively, download and build the library from source.
2.  **Set Up the Project Directory**:
    
    -   Organize your project directory:
        
        ```
        MyProject/
        ├── CMakeLists.txt
        ├── src/
        │   └── main.cpp
        └── include/
        ```
        
3.  **Write the `CMakeLists.txt`**:
    
    -   Create a `CMakeLists.txt` file at the root of your project:
        
        ```cmake
        cmake_minimum_required(VERSION 3.10)
        project(MyProject)
        
        # Add include directories
        include_directories(${CMAKE_SOURCE_DIR}/include)
        
        # Link the static library (e.g., GLFW)
        find_package(glfw3 REQUIRED)
        
        # Add source files
        add_executable(MyProject src/main.cpp)
        
        # Link the library
        target_link_libraries(MyProject glfw)
        ```
        
4.  **Build the Project**:
    
    -   Create a build directory and run CMake to generate the build files:
        
        ```bash
        mkdir build && cd build
        cmake ..
        make
        ```
        
    -   The executable will be generated in the `build` directory.
5.  **Run the Program**: `./MyProject`


### Dynamic Linking

With **dynamic linking**, the library is not embedded into the executable. Instead, the program depends on a separate file (usually a `.dll` on Windows, `.so` on Linux, or `.dylib` on macOS) that is loaded at runtime. This approach keeps the executable smaller and allows the library to be updated independently.

In **Windows**, dynamic linking involves `.dll` (Dynamic Link Library) files. The program will either:

1.  Automatically resolve and load the `.dll` files at application launch.
2.  Manually load the `.dll` during runtime using functions like `LoadLibrary` and `GetProcAddress`.

In **Linux**, dynamic linking involves `.so` (Shared Object) files. The linker looks for the `.so` files in standard library paths (e.g., `/usr/lib`, `/usr/local/lib`) or paths specified in the environment variable `LD_LIBRARY_PATH`.















## Templates

Templates in C++ are a powerful mechanism for creating generic and reusable code. They allow you to define methods, classes, or other constructs that can operate with different data types or parameters. Unlike traditional generic programming in some other languages, templates in C++ are not limited by a generic type system and enable compile-time code generation tailored to specific use cases.

Templates work by specifying a blueprint that the compiler uses to generate concrete implementations when the template is instantiated. This means that the code for the template is compiled **only when it is used**, and the specified types or parameters are substituted at compile time.


### Example: Template Class

Here’s an example of a templated class that defines an array:

```cpp
template<typename T, int N>
class Array {
private:
    T m_array[N]; // Fixed-size array of type T
public:
    // Method to get the size of the array
    int getSize() const { 
        return N; 
    }
};

int main() {
    Array<int, 50> array; // Instantiate Array with int type and size 50
    std::cout << array.getSize() << std::endl; // Output: 50
    return 0;
}
```

- **Lazy Compilation**:  The `Array` class will only be compiled when it is used. The `T` type and the `N` size parameter are replaced by the specified values (e.g., `int` and `50`) **at compile time**.
    
- **Flexible Data Types**:  Templates allow you to create type-agnostic classes and functions. For instance, you can create an `Array<double, 100>` or `Array<std::string, 10>` without rewriting the class.
    
- **Compile-Time Parameters**:  You can pass values like `N` (the size of the array in this example) as **non-type template parameters**, which are resolved during compilation.


### Template Functions

Templates are not limited to classes; you can also create **templated functions**:

```cpp
template<typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << add<int>(3, 5) << std::endl;      // Output: 8
    std::cout << add<double>(2.5, 4.5) << std::endl; // Output: 7.0
    return 0;
}
```

Here, the `add` function works with any type `T` that supports the `+` operator.


### Advantages of Templates

1.  **Type Safety**:  Templates ensure that your code works with the specified types without runtime errors (all checks happen at compile time).
    
2.  **Code Reusability**:  You can write generic and reusable functions or classes without duplicating code for every type.
    
3.  **Compile-Time Optimization**:  Since templates are resolved at compile time, they can result in highly optimized code compared to runtime polymorphism.
    






## Macros

Macros are **preprocessor directives** that perform **pure text replacement** before the code gets compiled. This allows macros to simplify repetitive tasks or control the inclusion of debugging or conditional code.

A simple example:

```cpp
#define WAIT std::cin.get()

int main(){
	WAIT;
}
```

A more useful example, using a parameter and a preprocess definition:
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

**`NOTE`**: You can define the preprocess definition variables, e.g., `PR_DEBUG` at the top of your source file (before any relevant code) using `#define`.
However, it is common practice, especially for larger projects, to define the preprocess definitions using  compiler flag.s This ensures the macros are globally available across all files without requiring repetitive `#define` directives.

For example, if you're using:

-   **GCC/Clang**: Add `-DPR_DEBUG` to the compiler flags: 
`g++ -DPR_DEBUG main.cpp -o main`
or in a Makefile:	
`CXXFLAGS += -DPR_DEBUG` 
    
-   **CMake**: Add it in your `CMakeLists.txt` file:
    `add_compile_definitions(PR_DEBUG)` 
    
-   **MSVC**: Add `/DPR_DEBUG` to the compiler flags: 
`cl /DPR_DEBUG main.cpp` 


Macros are often used to create custom debugging tools or validation checks. Here’s an example of a custom assertion macro:

```c++
#include <iostream>

// Custom assert macro
#define MY_ASSERT(condition) \
    do { \
        if (!(condition)) { \
            std::cerr << "Assertion failed: " << #condition << " in " << __FILE__ << " at line " << __LINE__ << std::endl; \
            std::terminate(); \
        } \
    } while (false)

int main() {
    int x = 5;
    MY_ASSERT(x == 5); // Use the custom assert macro

    std::cout << "Program continues after the assertion check." << std::endl;
}
```

**`NOTE`**: here the macro is wrapped in a `do { ... } while (false)` block to ensure proper scoping/bracketing. 

`do { ... } while (false)` executes once the `do` so doesn't change much the code, however it ensures that all the statements in the `do` block are within a curly bracket block (avoiding `dangling else`)

In the following Example:
```c++
if (x == 5) 
	MY_ASSERT(x > 0); 
else  
	do_something_else();
```

If the `MY_ASSERT` macro is defined like this:

```cpp
#define MY_ASSERT(condition) \ 
	if (!(condition)) { \ 
		std::cerr << "Assertion failed: " << #condition << std::endl; \ 
		std::terminate(); \ 
	}
```

the code expands to

```cpp
if (x == 5) 
	if (!(x > 0)) { 
		std::cerr << "Assertion failed: " << std::endl; 
		std::terminate(); 
	} 
	else 
		do_something_else();
```

that is wrong! The `else` is always associated with the nearest unmatched `if` i.e., the dangling else becomes the else of the inner if.

If we define the macro using the `do ... while(false)`  instead

```cpp
#define MY_ASSERT(condition) \ 
	do { \
		if (!(condition)) { \ 
			std::cerr << "Assertion failed: " << #condition << std::endl; \ 
			std::terminate(); \ 
		} \
	} while(false)
```

the expanded code looks and works fine

```cpp
if (x == 5) 
	do {
		if (!(x > 0)) { 
			std::cerr << "Assertion failed: " << std::endl; 
			std::terminate(); 
		} 
	} while(false)
else 
	do_something_else();
```















## Namespace

The primary purpose of namespaces is to **avoid naming conflicts**. Namespaces allow us to define symbols (such as classes, functions, and variables) with the same name in different contexts, avoiding collisions in larger projects or when using third-party libraries.

**Example**

```cpp
#include <iostream>

namespace apple {
    void print(const char* str) {
        std::cout << "[apple] " << str << std::endl;
    }
}

namespace orange {
    void print(const char* str) {
        std::cout << "[orange] " << str << std::endl;
    }
}

int main() {
    // Call the orange namespace's print function
    orange::print("Ciao a tutti");
}
```

### Key Concepts

1.  **Fully Qualified Names** You can explicitly specify the namespace when calling a function or accessing a variable to avoid ambiguity:
        
	```cpp
	orange::print("Hello from orange!");
	apple::print("Hello from apple!");
	```
        
2.  **`using namespace` Directive** The `using namespace` directive imports all symbols from a namespace into the current scope, allowing you to call functions or access variables without qualifying their namespace:
        
	```cpp
	using namespace apple;
	print("Hello!"); // Equivalent to apple::print
	```
        
    **Caution:** Avoid using `using namespace` in global scope, especially with large or commonly-used namespaces (like `std`), as it can lead to naming conflicts.
3.  **Aliasing with `namespace`** To simplify long or deeply nested namespace names, you can create an alias:
        
	```cpp
	namespace a = apple;
	a::print("Using alias for apple");
	```
        
4.  **Anonymous Namespaces** An **anonymous namespace** is used to limit the scope of symbols to a single file. This is particularly useful for internal linkage:
        
	```cpp
	namespace {
	    void internalFunction() {
	        std::cout << "This function is only accessible in this file." << std::endl;
	    }
	}

	int main() {
	    internalFunction(); // OK
	    return 0;
	}
	```
        
### Namespace Nesting
Namespaces can be nested within other namespaces:
    
```cpp
namespace fruit {
    namespace apple {
        void print() {
            std::cout << "This is fruit::apple!" << std::endl;
        }
    }
}

int main() {
    fruit::apple::print(); // Accessing nested namespace
    return 0;
}
```
    















## Function pointers

In C++, you can assign functions to variables, pass functions as arguments to other functions, and use function pointers to build complex and flexible logic. **Function pointers** are variables that store the memory address of a function, allowing dynamic function invocation.

Here’s how you can assign a function to a pointer and invoke it:

```cpp
// a very simple function
void helloWorld(){
	std::coutn << "hello" << std::endl;
}

int main(){
	// we can assign a function to a pointer 
	// assign myfunc the memory address of helloWorld function
	auto myfunc = &helloWorld; 

	// because of implicit conversion we can also omit the ampersand &
	auto myfunc = helloWorld;
	
	// function pointers are declared using
	// type(*)() 

	// so to explicitly declare myfunc we write
	void(*myfunc)() = helloWorld; 

	// to make it more readable we can use typedef
	typedef void (*HelloWorldFunc)();
	// and then use it
	HelloWorldFunc myfuncWithTypedef = helloWorld;

	// Finally call the function through the pointer
	myfunc(); 
	myfuncWithTypedef();
}
```

Function pointers can also point to functions that take parameters. Here's how:

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

**Example**

A common use case for function pointers is **callbacks**, where you pass a function pointer to another function to customize its behavior. Here's an example:

```cpp
// this is the callback function
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











## Lambdas

..though we can rewrite the previous in a more simple way, avoiding to write the extra function `printValue()`, using **lambda**. 

Lambdas are anonymous functions that can be defined inline. They are particularly useful for short, single-use logic. 

In C++, the general expression form of a **lambda function** is as follows:

```cpp
[capture_list] (parameter_list) -> return_type {
    function_body
};
```

**Example**

Here’s the same example we have seen above, rewritten with a lambda:

```cpp
void foreach(const std::vector<int>& values, void(*func)(int)){
	for (int v : values)
		func(v);
}

int main(){
	std::vector<int> vector = {1, 2, 3};
	foreach(vector, [](int value) -> void {std::cout << value << std::endl;});
}
```


### Components of a Lambda

1.  **Capture List (`[ ]`)**: Specifies which variables from the enclosing scope are captured by the lambda. 
It can be:
       -   Empty (`[]`) if no variables are captured.
       -   `[var]` to capture `var` by value.
       -   `[&var]` to capture `var` by reference.
       -   `[=]` to capture all variables by value.
       -   `[&]` to capture all variables by reference.
       -   `[=, &var]` to capture all variables by value, except `var`, which is captured by reference.
       -   `[&, var]` to capture all variables by reference, except `var`, which is captured by value.
2.  **Parameter List (`( )`)**:
    
    -   Specifies the parameters that the lambda takes, similar to a regular function.
    -   If no parameters are needed, this can be empty: `()`.
    -   Example: `(int a, double b)`.
3.  **Return Type (`-> return_type`)** (optional):
    
    -   Explicitly specifies the return type of the lambda.
    -   If omitted, the compiler deduces the return type from the `function_body`.
    -   Example: `-> int`.
4.  **Function Body (`{ }`)**:
    
    -   Contains the actual code of the lambda.
    -   Similar to the body of a regular function.


### Examples

**Simple Lambda**

```cpp
auto greet = []() {
    std::cout << "Hello, world!" << std::endl;
};
greet();
```

**Lambda with Parameters**

```cpp
auto add = [](int a, int b) {
    return a + b;
};
std::cout << add(3, 5) << std::endl; // Output: 8
```

**Lambda with Explicit Return Type**

```cpp
auto divide = [](int a, int b) -> double {
    if (b != 0) {
        return static_cast<double>(a) / b;
    } else {
        return 0.0;
    }
};
std::cout << divide(5, 2) << std::endl; // Output: 2.5
```

**Capturing Variables by Value**

```cpp
int x = 10;
auto printX = [x]() {
    std::cout << "x = " << x << std::endl;
};
printX(); // Output: x = 10
```

**Capturing Variables by Reference**

```cpp
int x = 10;
auto modifyX = [&x]() {
    x += 5;
};
modifyX();
std::cout << "x = " << x << std::endl; // Output: x = 15
```

**Mixed Captures**

```cpp
int a = 5, b = 10;
auto sum = [a, &b]() {
    b += a;
    return b;
};
std::cout << sum() << std::endl; // Output: 15
std::cout << b << std::endl;     // Output: 15
```

**Lambda as an Argument to a Function**

```cpp
#include <vector>
#include <algorithm>
#include <iostream>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::for_each(numbers.begin(), numbers.end(), [](int n) {
        std::cout << n * 2 << " ";
    });
    // Output: 2 4 6 8 10
    return 0;
}
```

**Lambda with Stateful Captures**

```cpp
auto counter = [count = 0]() mutable {
    return ++count;
};
std::cout << counter() << std::endl; // Output: 1
std::cout << counter() << std::endl; // Output: 2
```

Lambdas are often used in modern C++ for:

-   **Callbacks** (e.g., in `std::for_each` or GUI frameworks).
-   **Functional-style programming** (e.g., map/filter/reduce).
-   **Short-lived functions** (avoiding writing separate named functions).


### Other Examples

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

int const max = 100;
std::vector<int> vec {178, 101, 123, 145, 45, 33};

auto lambda = [max](int i){ return i < max; };
auto it = std::find_if(begin(vec), end(vec), lambda);
(it != end(vec))
? std::cout << "first element <= max is: " << *it <<std::endl
: std::cout << "all element are > max." << std::endl;
```



## Multidimensional Arrays

A **simple (1D) array** in C++ is essentially a contiguous block of memory, and can be accessed using a pointer to its first element:

```cpp
// Stack-allocated array
int a[50];
int* ptr = a; // 'ptr' points to the first element of 'a'

// Heap-allocated array
char* buffer = new char[8];
```


### 2D Arrays (Stack Allocation)

A **2D array** is an array of arrays. You can initialize it directly:

```cpp
int x[3][4] = {
  {0, 1, 2, 3}, 
  {4, 5, 6, 7}, 
  {8, 9, 10, 11}
};

// Equivalent flat initialization
int x2[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
```

### 2D Arrays (Heap Allocation)

A dynamically allocated 2D array is created using pointers. Conceptually, this is an array of pointers, each pointing to a 1D array.

```cpp
int** a2d = new int*[50]; // 50 rows (pointers to int arrays)
// with this we just have allocated memory
// specifically 50 integer pointers, so
// 4bytes * 50 = 200 bytes of memory

// now we need to initialize the 50 arrays
for (int i = 0; i < 50; i++) {
    a2d[i] = new int[50]; // Each row has 50 columns
}
```

#### Cleanup (Deallocation):

```cpp
for (int i = 0; i < 50; i++) {
    delete[] a2d[i]; // Free each row
}
delete[] a2d; // Free the row pointer array
```

### 3D Arrays (Heap Allocation)

A **3D array** is an array of 2D arrays, requiring nested loops for allocation:

```cpp
int*** a3d = new int**[50];
for (int i = 0; i < 50; i++) {
    a3d[i] = new int*[50];
    for (int j = 0; j < 50; j++) {
        a3d[i][j] = new int[50];
    }
}
```

> **Note:** Remember to deallocate all levels in reverse order to prevent memory leaks.

### Efficient Alternative: Flattened Arrays

Dynamically allocated multidimensional arrays are **not contiguous in memory**, which leads to **poor cache performance**. A better approach is to simulate a 2D or 3D array using a single flat array.

```cpp
int* flat2d = new int[3 * 3];

// Simulate 2D access: [row][col]
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        flat2d[i * 3 + j] = 0;
    }
}
```

This layout ensures **contiguous memory**, which improves performance due to better **spatial locality** and **cache usage**.






## Sorting with `std::sort`

Reference: [cppreference.com - std::sort](https://en.cppreference.com/w/cpp/algorithm/sort)

### Sorting a Plain Array

```cpp
#include <algorithm>

int main() {
    int n = 7;
    int a[] = {4, 2, 5, 3, 5, 8, 3};
    std::sort(a, a + n); // Sorts the array in ascending order
}
```


### Sorting a `std::vector`

```cpp
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> values = {3, 5, 1, 4, 2};

    std::sort(values.begin(), values.end());      // Sorts ascending: 1 2 3 4 5
    std::sort(values.rbegin(), values.rend());    // Sorts descending: 5 4 3 2 1
}
```


### Sorting a `std::string`

```cpp
#include <algorithm>
#include <string>
#include <iostream>

int main() {
    std::string s = "monkey";
    std::sort(s.begin(), s.end()); // Result: "ekmnoy"
    std::cout << s << std::endl;
}
```

### Sorting Custom Types with a Comparator

```cpp
#include <algorithm>
#include <vector>

class Man {
public:
    Man(std::string name, int age) : m_name(name), m_age(age) {}
    int age() const { return m_age; }

private:
    std::string m_name;
    int m_age;
};

bool compareByAge(const Man& m1, const Man& m2) {
    return m1.age() < m2.age();
}

int main() {
    std::vector<Man> men = {{"Mike", 30}, {"Alice", 25}, {"Bob", 27}};
    std::sort(men.begin(), men.end(), compareByAge);
}
```


### Using Lambdas for Custom Sorting

```cpp
#include <vector>
#include <algorithm>
#include <functional>

int main() {
    std::vector<int> values = {3, 5, 1, 4, 2};

    std::sort(values.begin(), values.end(), std::greater<int>());       // Descending: 5 4 3 2 1

    std::sort(values.begin(), values.end(), [](int a, int b) {
        return a < b;
    }); // Ascending: 1 2 3 4 5

    std::sort(values.begin(), values.end(), [](int a, int b) {
        return a > b;
    }); // Descending: 5 4 3 2 1
}
```



## Type Punning

**Type punning** refers to treating a block of memory of one type as if it were a different type.

### Implicit Conversion (Not Type Punning)

```cpp
int a = 5;
std::cout << "a: " << a << std::endl;

double value = a; // Implicit conversion from int to double
std::cout << "value: " << value << std::endl; // value: 5
```

In this case, `a` is converted to a new `double` value. The original memory of `a` is **not reused** — a proper type conversion happens, and the memory layout changes accordingly.



### Actual Type Punning

If we want to reinterpret the memory of one type as another (without conversion), we can cast its address:

```cpp
int a = 5;

// Reinterpret the memory of 'a' as a double
double value = *(double*)&a;
// we take memory address of 'a', cast it to double pointer, then dereference to get back the value 


std::cout << "value: " << value << std::endl; // value: some garbage, e.g., 7.75152e+230
```

This is type punning: we're treating the memory of `a` (which holds an `int`) **as if** it were a `double`. This is **dangerous**, as it results in undefined behavior — the value read is likely garbage due to different type sizes and memory layouts.


### Struct Punned into an Array

A more illustrative example is punning a struct into an array:

```cpp
#include <iostream>

struct Entity {
    int a, b;
};

int main() {
    Entity e = {5, 8};

    // Reinterpret the memory of the struct as an array of ints
    int* arr = (int*)&e;

    std::cout << "arr[0]: " << arr[0] << ", arr[1]: " << arr[1] << std::endl;
    // Output: arr[0]: 5, arr[1]: 8
}
```

Here, the struct `Entity` consists of two `int`s. Since the struct’s memory layout is just two consecutive `int`s, reinterpreting it as an array of `int` works correctly — though it still technically relies on compiler behavior and alignment.

---

### Warning

Type punning may lead to **undefined behavior** and should be used with **extreme caution**. In modern C++, safer alternatives include:

- `std::memcpy` (for copying memory between types)
- `std::bit_cast` (C++20)
- `union` (in legacy code)
- `reinterpret_cast` (with care)




## Union

A [**union**](https://en.cppreference.com/w/cpp/language/union) is a special class type that can hold **only one** of its non-static data members at a time. All members share the same memory space. This is useful when you want to reinterpret memory without type conversion — in a safer and more structured way than raw pointer casting (type punning).

### Motivation Example

Suppose we have a `Vector2` and a `Vector4`, and we want to access the `Vector4` as **two** `Vector2` instances — for example, treating it like a pair: `a = (x, y)` and `b = (z, w)`.

First, let’s define a simple `Vector2` struct with an overloaded output operator:

```cpp
struct Vector2 {
    float x, y;
};

// Overload operator<< for Vector2
std::ostream& operator<<(std::ostream& stream, const Vector2& vector) {
    stream << vector.x << ", " << vector.y;
    return stream;
}
```


### Using Type Punning (Unsafe)

We can manually reinterpret the memory using pointer casting — this is **type punning** and is error-prone:

```cpp
struct Vector4 {
    float x, y, z, w;

    Vector2& getA() { return *(Vector2*)&x; } // Treat x and y as Vector2
    Vector2& getB() { return *(Vector2*)&z; } // Treat z and w as Vector2
};

int main() {
    Vector4 v4 = {1, 2, 3, 4};
    std::cout << v4.getA() << std::endl; // Output: 1, 2
}
```

While this works in practice, it relies on assumptions about memory layout and aliasing that could lead to undefined behavior.


### Using a Union (Safer)

We can achieve the same result more safely and cleanly using an anonymous union inside the `Vector4` struct:

```cpp
struct Vector4 {
    union {
        struct { float x, y, z, w; }; // Layout of the full vector
        struct { Vector2 a, b; };     // Alternative access: two Vector2s
		// so now I can access data in two ways: 
		// 1. using x, y, z, w
		// 2. using a and b, where a happens to be x, y 
		// b happens to be z, w
    };
};

int main() {
    Vector4 v4 = {1, 2, 3, 4};
    v4.z = 33; // Modify an individual component

    std::cout << v4.b << std::endl; // Output: 33, 4
}
```

### Key Points:
- Unions allow different views of the **same memory**.
- Anonymous structs/unions let you access fields directly (without `.a.x` syntax).
- You must ensure the members don’t conflict or lead to misaligned access.
- Safer and more readable than pointer casting.





## Virtual Destructors

When working with **inheritance** and **virtual functions**, it’s crucial to understand the importance of virtual destructors.

### Basic Example

```cpp
class Base {
public:
    Base() { std::cout << "B constr, "; }
    ~Base() { std::cout << "B destr, "; }
};

class Derived : public Base {
public:
    Derived() { std::cout << "D constr, "; }
    ~Derived() { std::cout << "D destr, "; }
};

int main() {
    Derived* derived = new Derived();
    delete derived;
}
```

**Output:**

```
B constr, D constr, D destr, B destr,
```

This behaves as expected — both constructors and destructors are called in the proper order.


### Polymorphism Issue

Now let’s see what happens when using polymorphism:

```cpp
int main() {
    Base* poly = new Derived();
    delete poly;
}
```

**Output:**

```
B constr, D constr, B destr,
```

Oops! The **`Derived` destructor is never called**, leading to a potential **memory/resource leak**.


### The Solution: Virtual Destructor

To fix this, declare the **base class destructor as virtual**:

```cpp
class Base {
public:
    Base() { std::cout << "B constr, "; }
    virtual ~Base() { std::cout << "B destr, "; }
};
```

With this change, `delete poly` will properly invoke both destructors:

```
B constr, D constr, D destr, B destr,
```

### Rule of Thumb

> Whenever a class is intended to be **inherited from**, always declare its **destructor as `virtual`**.

This ensures that the **entire object hierarchy is properly destroyed**, even when accessed via a base class pointer.







## Casting in C++

Type casting means converting a value from one type to another. In C++, this can happen either:

- **Implicitly**, when the compiler knows how to do the conversion safely.
- **Explicitly**, when you tell the compiler exactly how to convert a value.

### `static_cast`

Used for standard conversions between related types at compile-time. It's type-safe and preferred over C-style casts.

**C-style cast:**

```cpp
double value = 5.32;
int a = (int)value + 5.4;  // explicit C-style cast
```

**C++-style cast:**

```cpp
double value = 5.32;
int a = static_cast<int>(value) + 5.4;
```

`NOTE`: `static_cast` is better because it's easier to locate in code and allows better compile-time checks.

### `dynamic_cast`

Used for **safe downcasting** in inheritance hierarchies (requires at least one **virtual function** in the base class). It performs **runtime type checking**, returning `nullptr` if the cast fails (when dealing with pointers).

```cpp
class Base {
public:
    virtual ~Base() {}
};

class Derived : public Base {};
class AnotherClass : public Base {};

int main() {
    Base* base = new Derived(); // suppose we don't know that base is specialized to Derived

    AnotherClass* ac1 = static_cast<AnotherClass*>(base); // Unsafe: no runtime check!
    AnotherClass* ac2 = dynamic_cast<AnotherClass*>(base); // Safe: returns nullptr if cast fails

    if (ac2) {
        std::cout << "Cast successful.\n";
    } else {
        std::cout << "Cast failed.\n";
    }

    delete base;
}
```

`NOTE`: Use `dynamic_cast` when you're not sure of the actual type at runtime and need type checking.

### `reinterpret_cast`

Used for **low-level type punning** — interpreting the raw memory of one type as another. It's **dangerous** and should be used with extreme caution.

```cpp
int a = 5;
double* ptr = reinterpret_cast<double*>(&a);
std::cout << *ptr << std::endl; // undefined behavior
```

`NOTE`: This cast tells the compiler: "Trust me, I know what I'm doing." Often used in embedded or performance-critical code, but not type-safe.


### `const_cast`

Used to **add or remove `const`** or `volatile` qualifiers from a variable. Useful in rare cases, e.g., legacy APIs or when you know modifying a const object is safe (e.g., internal caching).

```cpp
const int a = 42;
int& b = const_cast<int&>(a);
b = 10;
std::cout << a << " " << b << std::endl; // undefined behavior!
```

`NOTE`: Modifying a `const` object after casting away its constness leads to **undefined behavior**.






## Singleton

A **singleton** is a design pattern that ensures a class has **only one instance** and provides a **global point of access** to it.

In C++, a singleton acts somewhat like a namespace—it organizes global data and behavior into a single, centralized instance. It’s commonly used for managers, configuration handlers, loggers, etc.

### Example:

```cpp
#include <iostream>

class SingletonExample {
public:
    // The method to retrieve the single instance
    static SingletonExample& get() {
        static SingletonExample instance; // created once, on first use
        return instance;
    }

    void setStatus() { this->status = 1; }
    static int getStatus() { return get().status; }

private:
    int status; // a variable to demonstrate uniqueness

    // Private constructor to prevent external instantiation
    SingletonExample() : status(0) {
        std::cout << "Constructor called" << std::endl;
    }

    // Delete copy constructor and assignment operator
    SingletonExample(const SingletonExample&) = delete;
    SingletonExample& operator=(const SingletonExample&) = delete;
};

int main() {
    std::cout << SingletonExample::getStatus() << std::endl;

    // All references point to the same instance
    SingletonExample& se1 = SingletonExample::get();
    SingletonExample& se2 = SingletonExample::get();
    auto& se3 = SingletonExample::get();

    std::cout << "se1: " << se1.getStatus() << std::endl;
    se1.setStatus();

    std::cout << "se1: " << se1.getStatus() << std::endl;
    std::cout << "se2: " << se2.getStatus() << std::endl;
    std::cout << "se3: " << se3.getStatus() << std::endl;

    std::cout << SingletonExample::getStatus() << std::endl;
}
```

### Notes:
- The instance is created **lazily** and is **thread-safe** (guaranteed by C++11 and later).
- The constructor is private to prevent direct instantiation.
- Copying and assigning the singleton are explicitly disabled.





## lvalues and rvalues

### lvalue

An **lvalue** (locator value) refers to an object that has an identifiable location in memory. In other words, it can appear on the **left-hand side** of an assignment because it has an address.

```cpp
int a;       // 'a' is a variable stored in memory — it is an lvalue
a = 1;       // valid: 'a' appears on the left-hand side
int b = a;   // valid: 'a' is used on the right-hand side, but it is still an lvalue

9 = a;       // Error: '9' is a literal (an rvalue) and cannot appear on the left-hand side
```

### rvalue

An **rvalue** (read value) is a temporary value that does not persist in memory and cannot be assigned to. It can only appear on the **right-hand side** of an assignment.

```cpp
int a = 1, b;
a + 1 = b;       // Error: 'a + 1' is an rvalue and cannot be assigned to

int* p, *q;
*p = 1;          // Valid: '*p' is an lvalue because it refers to a memory location
p + 2 = 18;      // Error: 'p + 2' is the result of pointer arithmetic — it is an rvalue
q = p + 5;       // Valid: 'q' is an lvalue, 'p + 5' is an rvalue

*(p + 2) = 18;   // Valid: dereferencing the result gives an lvalue

p = &b;          // Valid: assigning the address of 'b' to pointer 'p'

int arr[20];     
arr[12] = 5;     // Valid: 'arr[12]' is equivalent to '*(arr + 12)' — an lvalue

&a = p;          // Error: '&a' produces a temporary value (an rvalue)

struct S { int m; };
S obj;           // 'obj' is an lvalue
obj.m = 10;      // 'obj.m' is also an lvalue

S* ptr = &obj;
ptr->m = 20;     // 'ptr->m' is an lvalue, equivalent to '(*ptr).m'
```

### Summary

| Expression Type | Can appear on left of `=` | Has memory address | Examples              |
|-----------------|---------------------------|---------------------|------------------------|
| lvalue          | Yes                       | Yes                 | `a`, `*p`, `arr[5]`    |
| rvalue          | No                        | No (typically)      | `42`, `a + 1`, `p + 2` |





## Logical Operators

Logical operators are used to perform logical operations on boolean expressions. They combine multiple conditions and evaluate the result as either `true` or `false`. Conditions are evaluated from left to right.

- The logical **AND** operator (`&&`) returns `true` if **both** of its operands are `true`.
- The logical **OR** operator (`||`) returns `true` if **at least one** of its operands is `true`.
- The logical **NOT** operator (`!`) is a unary operator that **negates** the value of its operand.

```cpp
bool a = true;
bool b = false;
bool result = a && b;  // result is false (evaluates false immediately if a is false)
result = a || b;       // result is true (evaluates true immediately if a is true)
result = !a;           // result is false (negates the value of a)
```





## Bitwise Operators

Bitwise operators are used to perform operations on individual bits of binary numbers. These operators allow manipulation of the binary representation of integers at a bit level. There are six bitwise operators in C++:

- The bitwise **AND** (`&`) operator compares the corresponding bits of two operands and returns `1` if **both bits** are `1`, otherwise it returns `0`.
- The bitwise **OR** (`|`) operator compares the corresponding bits of two operands and returns `1` if **at least one** of the bits is `1`, otherwise it returns `0`.
- The bitwise **XOR** (`^`) operator compares the corresponding bits of two operands and returns `1` if **the bits are different**, otherwise it returns `0`.
- The bitwise **NOT** (`~`) operator is a unary operator that flips the bits of its operand. It returns the **one's complement** of the operand. For example:

```cpp
int a = 5; // binary representation: 0101
int b = 3; // binary representation: 0011
int result = a & b; // binary result: 0001 (1 in decimal)
int result = a | b; // binary result: 0111 (7 in decimal)
int result = a ^ b; // binary result: 0110 (6 in decimal)
int result = ~a;    // binary result: 1010 (-6 in decimal, two's complement)
```

- The **left shift** (`<<`) operator shifts the bits of the left operand to the left by a specified number of positions. The vacant positions are filled with zeros.  
  **Note**: A left shift multiplies the original number by `2`.

- The **right shift** (`>>`) operator shifts the bits of the left operand to the right by a specified number of positions. The vacant positions are filled with the sign bit (for signed types) or with zeros (for unsigned types).  
  **Note**: A right shift is equivalent to dividing a number by `2`.

```cpp
int a = 5; // binary representation: 0101
int result = a << 2; // binary result: 010100 (20 in decimal)
result = a >> 2;     // binary result: 0001 (1 in decimal)
```







## Threads

A thread is the smallest unit of execution in a process.  
Multithreading involves the execution of multiple threads concurrently within a single program. It allows multiple threads to run independently, sharing the same resources (e.g., memory) but having their own execution contexts (stack and registers).  
Once a thread is created, its function or callable object is executed concurrently with other threads.

```cpp
#include <thread>

void myThreadFunction() {
  // Code to be executed on a separate thread
}

int main() {
  std::thread myThread(myThreadFunction); // myThread starts running immediately in parallel (with the main thread)

  // The main thread can continue working here

  myThread.join(); // Main thread waits for myThread to finish before proceeding

  // Alternatively, myThread can run independently
  // myThread.detach();

  // Do other work here (only after myThreadFunction finishes executing)
}
```

When multiple threads access shared data concurrently, synchronization mechanisms are necessary to avoid data races. Mutexes, condition variables, and atomic operations are commonly used for synchronization.

### Mutex

A **mutex** is a synchronization primitive in C++ used to protect shared resources from concurrent access by multiple threads. It ensures that only one thread can access the protected resource at a time, preventing data races and maintaining data integrity.

```cpp
#include <iostream>
#include <thread>
#include <mutex>

std::mutex myMutex;
int sharedVariable = 0;

void myThreadFunction() {
  std::lock_guard<std::mutex> lock(myMutex); // Safely modify sharedVariable
  sharedVariable++;
}

int main() {
  std::thread myThread1(myThreadFunction);
  std::thread myThread2(myThreadFunction);
  myThread1.join();
  myThread2.join();
  // sharedVariable is now safely modified by both threads
}
```

### Condition Variables

`std::condition_variable` is a synchronization primitive in C++ that allows threads to wait for a particular condition to be satisfied. It is often used in conjunction with a `std::mutex` to protect shared data and coordinate the execution of multiple threads.

#### Example: Producer/Consumer

```cpp
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

std::mutex mutex_;
std::condition_variable condVar;
std::queue<int> dataQueue;

const int MAX_QUEUE_SIZE = 5;

void producer() {
  for (int i = 0; i < 10; ++i) {
    std::unique_lock<std::mutex> lock(mutex_);
    
    // Wait until there is space in the queue
    condVar.wait(lock, [] { return dataQueue.size() < MAX_QUEUE_SIZE; });

    // Produce data and add it to the queue
    dataQueue.push(i);
    std::cout << "Produced: " << i << std::endl;

    // Notify consumers that data is available
    condVar.notify_one();
  }
}

void consumer() {
  for (int i = 0; i < 10; ++i) {
    std::unique_lock<std::mutex> lock(mutex_);
    
    // Wait until there is data in the queue
    condVar.wait(lock, [] { return !dataQueue.empty(); });

    // Consume data from the queue
    int data = dataQueue.front();
    dataQueue.pop();
    std::cout << "Consumed: " << data << std::endl;

    // Notify producer that space is available
    condVar.notify_one();
  }
}

int main() {
  std::thread producerThread(producer);
  std::thread consumerThread(consumer);

  producerThread.join();
  consumerThread.join();
}
```

#### Example: Thread Synchronization

```cpp
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mutex_;
std::condition_variable condVar;
bool dataReady = false;

void producer() {
  std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate work
  {
    std::lock_guard<std::mutex> lock(mutex_);
    dataReady = true;
  }
  condVar.notify_one();
}

void consumer() {
  {
    std::unique_lock<std::mutex> lock(mutex_);
    condVar.wait(lock, [] { return dataReady; });
    // Do something with the data
    std::cout << "Consumed data." << std::endl;
  }
}

int main() {
  std::thread producerThread(producer);
  std::thread consumerThread(consumer);

  producerThread.join();
  consumerThread.join();
}
```

#### `std::lock_guard` vs `std::unique_lock`

- Use **`std::lock_guard`** when you need a simple and concise way to lock and unlock a mutex within a scope, and no manual unlocking is required.
- Use **`std::unique_lock`** when you need more flexibility, such as manual unlocking, deferred locking, or using the lock with condition variables.

The choice between `std::lock_guard` and `std::unique_lock` depends on the specific requirements of your code and the level of control you need over the associated mutex.

### Boost Library Simplification

#### Example: Mutex with Boost

```cpp
#include <boost/thread.hpp>

boost::mutex myMutex;
int sharedVariable = 0;

void myThreadFunction() {
  boost::unique_lock<boost::mutex> lock(myMutex);
  sharedVariable++; // Safely modify sharedVariable
}

int main() {
  boost::thread myThread1(myThreadFunction);
  boost::thread myThread2(myThreadFunction);
  myThread1.join();
  myThread2.join();
}
```

#### Lock-Free Queue (Producer/Consumer)

Boost provides a lock-free queue implementation, removing the need for explicit locking and unlocking when accessing the shared data structure.

```cpp
#include <iostream>
#include <thread>
#include <boost/lockfree/queue.hpp>

const int MAX_QUEUE_SIZE = 5;
boost::lockfree::queue<int> dataQueue(MAX_QUEUE_SIZE);

void producer() {
  for (int i = 0; i < 10; ++i) {
    while (!dataQueue.push(i)) {
      // Queue is full, spin-wait or implement backoff strategy
    }
    std::cout << "Produced: " << i << std::endl;
  }
}

void consumer() {
  int data;
  while (true) {
    while (dataQueue.pop(data)) {
      // Process the consumed data
      std::cout << "Consumed: " << data << std::endl;
    }
    // Queue is empty, spin-wait or implement backoff strategy
  }
}

int main() {
  std::thread producerThread(producer);
  std::thread consumerThread(consumer);

  producerThread.join();
  consumerThread.join();

  return 0;
}
```

#### Atomic Operations with Boost

The `boost::atomic` library provides atomic operations, which can be used to perform operations on variables in a way that is guaranteed to be atomic and avoid data races.  Atomic operations are guaranteed to be executed as a single uninterruptable operation and are often implemented in a lock-free manner, making them suitable for scenarios where lock contention might be a concern. 
Atomic operations are typically used for simple, low-level operations on shared variables without the need for explicit locking.

Example: **Atomic Operation**

```cpp
#include <boost/atomic.hpp>

boost::atomic<int> atomicVariable(0);

void myThreadFunction() {
  atomicVariable.fetch_add(1); // Atomically increment the variable
}
```






## Standard Input

`std::cin.get()` is a member function of the `cin` object, which is an instance of the `istream` class. This function is used to read a single character from the standard input.

```cpp
#include <iostream>
//...
char ch;
std::cout << "Enter a character: "; 

ch = std::cin.get(); // Reads any character (including spaces and new line characters)
std::cin >> std::ws;  // Ignore leading whitespace before reading the character
std::cin >> ch; // Read the character after skipping any whitespace

std::cout << "You entered: " << ch << std::endl;
//...
```

`std::cin` is also used to read words and strings.

```cpp
std::string input; 
std::cout << "Enter a word: "; 

std::cin >> input; // To read a single word (sequence of characters without spaces)
std::getline(std::cin, input); // To read a whole line (until a newline character is encountered. It discards the newline character and stores the entire line)

std::cout << "You entered: " << input << std::endl;
```


## Input File Stream

Use the `<filesystem>` library to work with file and directory paths, including obtaining the current working directory.

```cpp
#include <filesystem>

// Get the current working directory 
std::filesystem::path currentPath = std::filesystem::current_path();
```

Use the `std::ifstream` class from the `<fstream>` header to open and read from a file. Use `std::getline()` to read a line from the file stream.

```cpp
#include <fstream>

// ...
std::string filename = "example.txt";
std::ifstream ifs(filename); // Create an ifstream object

// Check if the file is open, which indicates that it exists
if (ifs.is_open()) {
  std::cout << "File exists." << std::endl;
  
  // You can proceed to read from the file here if needed
  std::string line;
  while (std::getline(ifs, line)) {
    if (line.find("somethingToSearch") != std::string::npos) {
      // "somethingToSearch" has been found
    }
  }  
   
  ifs.close(); // Close the file after using it
} else { 
  std::cout << "File does not exist." << std::endl; 
}
```



## CMake

CMake is a widely-used build system generator that simplifies the process of managing complex software builds. It allows you to define the structure and requirements of your project in a `CMakeLists.txt` file, which CMake then uses to generate platform-specific build files (e.g., Makefiles, Visual Studio project files, Xcode project files). It is especially useful for cross-platform development and large projects with multiple components.

### Key Concepts

When working with CMake, you'll often encounter the following concepts:

- **CMakeLists.txt**: The main configuration file where you define how your project is built. Each directory in your project should contain a `CMakeLists.txt` file.
- **Targets**: Targets represent executables or libraries that are built by CMake. Targets are created using commands like `add_executable()` or `add_library()`.
- **Subdirectories**: Large projects are often divided into subdirectories, and CMake allows you to manage these with `add_subdirectory()`. This is essential for handling multi-component projects.
- **Include Directories**: Directories containing header files that need to be included during compilation. These are added with `target_include_directories()`.
- **Sources**: The actual source files that will be compiled to create the targets. These are specified with `target_sources()` or directly in the `add_executable()`/`add_library()` commands.
- **Variables**: CMake allows you to define variables (e.g., paths, flags) that can be used throughout the `CMakeLists.txt` files.
- **Commands**: CMake has a set of predefined commands (e.g., `cmake_minimum_required()`, `project()`, `set()`, `add_subdirectory()`) used to configure and control the build process.

### Basic Structure of a CMake Project

A typical project structure using CMake might look like this:

```
root/
  CMakeLists.txt
  Graphs/
    CMakeLists.txt
    include/
  include/
```

### `CMakeLists.txt` in the Root Directory

This file is the entry point for your CMake configuration. It typically contains project-wide settings and includes for subdirectories. Here’s an example of what the root `CMakeLists.txt` might look like:

```cmake
cmake_minimum_required(VERSION 3.0.0)
project(thecherno VERSION 0.1.0)

# Set C++17 standard for the project
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

# Add subdirectory for the Graphs component
add_subdirectory(Graphs)
```

- **cmake_minimum_required()**: Specifies the minimum version of CMake required for the project.
- **project()**: Defines the project’s name and version.
- **set()**: Used to define project-wide variables like compiler flags (`CMAKE_CXX_FLAGS`).
- **add_subdirectory()**: Adds subdirectories to the build, in this case, `Graphs`.

### `CMakeLists.txt` in the `Graphs` Subdirectory

This file is specific to the `Graphs` submodule and contains the instructions for how to build the `Graphs` executable or library. Here's an example:

```cmake
cmake_minimum_required(VERSION 3.0.0)
project(Graphs VERSION 0.1.0)

# Add executable target called 'Graphs' using the Graphs.cpp source file
add_executable(Graphs Graphs.cpp)

# Optionally, add additional source files using target_sources()
# target_sources(Graphs PRIVATE log.cpp)

# Set up include directories for the Graphs target
target_include_directories(Graphs PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(Graphs PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
```

- **add_executable()**: Defines an executable target (in this case, `Graphs`), and specifies the source files (`Graphs.cpp`).
- **target_include_directories()**: Specifies directories that contain header files to be included during compilation.

### Handling Multiple Translation Units / Main Entry Points

If you have multiple translation units (source files) or multiple entry points (main functions), you can define separate executables. Here’s an example:

```cmake
cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

project(miketests VERSION 0.1.0)

# Define two executables, each with different source files
add_executable(main1 main.cpp anotherTransUnit.cpp)
add_executable(main2 anotherMain.cpp)
```

In this example:
- **add_executable()**: Defines two separate executables (`main1` and `main2`), each with its own set of source files.

### Useful CMake Features

Here are a few more tools and concepts that you’ll often encounter when writing `CMakeLists.txt` files:

- **`target_sources()`**: Adds sources to an existing target after it’s been created. This is useful when you want to separate different source files into different parts of your project.
  
  ```cmake
  target_sources(Graphs PRIVATE log.cpp)
  ```

- **`target_link_libraries()`**: Links external libraries to your target. This is important for linking third-party libraries or other targets in your project.
  
  ```cmake
  target_link_libraries(Graphs PRIVATE SomeLibrary)
  ```

- **`find_package()`**: Finds and configures external packages or libraries, such as Boost, OpenGL, etc.
  
  ```cmake
  find_package(Boost REQUIRED)
  ```

- **`install()`**: Specifies how to install your built project, including where to place binaries, libraries, and headers.
  
  ```cmake
  install(TARGETS Graphs DESTINATION /usr/local/bin)
  ```

- **Variables and CMake Cache**: You can define variables to control various aspects of your project build process. CMake also caches these values, allowing you to configure and modify them between builds.

