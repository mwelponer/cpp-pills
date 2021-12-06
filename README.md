# README #

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

Inside a function for exmaple, but could be inside a for loop or whatever other type of scope
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
