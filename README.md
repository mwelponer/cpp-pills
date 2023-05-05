C++ in pills
==
Copyright (C) 2021 Michele Welponer

## Pointers
Pointers hold an integer that is a memory address! We say then a pointer points to a location in memory: that location is the starting location of a memory space (whose lenght is defined by the type)

```cpp
int a = 3 // declare a variable
int* ptr //declare a pointer
&a // dereference a variable -> mem address of a
ptr = &a // set a pointer to point at variable a

*ptr // dereference a pointer -> 3, data of the variable ptr points to
++*p // get data, then increment it -> a is 4
*++p // move pointer, then get data
*p++ // read data (dereference) then move pointer
```

## References
References are like Pointers but less powerful. Reference are just syntax sugar, whatever you can do with references you can also do it using pointers.

```cpp
int a = 3
int a = *ptr 
int& ref = a // ref is now an alias of a
```

references are often used passed as arguments in functions. 

```cpp
void  incrementUsingRef(int& value){
  value++;
  std::cout <<  "value:"  << value << std::endl;  
}

incrementUsingRef(&a)
```
**NB**: the external variable we pass by reference will actually be incremented. If we don't use a reference but simply a variable, a new variable will be created, incremented inside the function, then destroyed as soon as the program goes out of the function scope.

## Classes

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
// free the allcated memory on the heap!
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

## Logical operators

operator | meaning
-|-
&& | and
\|\| | or
! |  not

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

## Strings

### manual declaration
A string is just an array of characters. If we want to declare it completely *manually* we need to add the string termination char (``0`` or ``'\0'``) that tells the pointer that the string is terminated.

```cpp
char mystring[5] = {'M', 'i', 'k', 'e', 0};
std::cout << mystring << std::endl;
```
we can aslo do 

```cpp
char str[] = "John is from USA.";
```

We can get the length of the string using ``strlen()``
We can concatenate string using ``strcat(str1, str2);`` where ``str1`` e ``str2`` are arrays i.e. char pointers

```cpp
void log(const char* ptr){
	std::cout << ptr << std::endl;
}
log(str);
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
C style  ``size_t find(const char* s, size_t pos = 0)``
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
std::stringstream  ss;
for (auto e : vec)
	ss << e;
ss.str()
```

Here it is the way to split a string using ``getline(string, token, delimiter)``
```cpp
#include <sstream>

std::string s = "I love to read articles.";
stringstream ss(s); 

while (getline(ss, str, ' ')) 
   cout << str << endl;
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
int stackArr[4] // declare now stackArr is already a pointer!
int stackArr[] = {1, 2, 3, 4} // declare and set 
stackArr[3] = 666
```
an array is just a pointer to the first element of the array so we can write
```cpp
int* ptr = stackArr;
*(ptr+3) = 666 // this equals to stackArr[3] = 666
```

***NB***: the raw arrays do not have any *.size* or *.lenght* operators so: 

1. if you declare the array in the stack use this trick:
```cpp
int size = sizeof(stackArr) / sizeof(int);
```
2. if you declare the array in the heap just do:
```cpp
static const int numOfElements = 10;
int* heapArr = new[numOfElements];
```

***arrays on the heap memory***

```cpp
int* heapArr = new int[10];
delete[] heapArr; // free the memeory allocated for the array
```

### multidimensional arrays

```cpp
int x[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11}
// OR
int x[3][4] = {{0,1,2,3}, {4,5,6,7}, {8,9,10,11}}
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

void print(std::vector<int>& v){
	for (auto x : v)
		std::cout << x << " ";
	}
}

std::vector<int> v; // declaration
std::vector<int> v = {3, 6, 5}; // init v.1
std::vector<int> v{3, 6, 5}; // init v.2
v.assign(5, 10) // fill with 10 five times
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
v.resize(n) 
v.empty()
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

### sorting

```cpp
#include <algorithm>

std::vector<int> v{ 1, 5, 8, 9, 6, 7, 3, 4};
sort(v.begin(), v.end()); // in ascending order
sort(v.begin(), v.end(), greater<int>()); // descending

// sorting classes based on some kind of comparison
bool compare(Man& m1, Man& m2){
    return m1.age() < m2.age();
}

std::vector<Man> v = {mike, alice, bob};
sort(v.begin(), v.end(), compare);
```

## Function pointers

You can actually assign functions to variables. Starting from that, you can also pass a function into another function as paramenter.. there's a whole bunch of things that we can actually do with functions and function pointers that do create intresting and complex logic. 

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
so here I use foreach function to which I pass a vector of elements and a function pointer: the function the pointer points to defines what I want to do with each element of the vector.
Though we can rewrite this is a more simple way, avoiding to write an extra function, using lambda. Lambda is just a normal function except that it is not declared as a normal function.

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




## Stack std stack
i.e. ``std::stack``

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
s.swap(stack2)
```

## Queue  std queue
i.e. ``std::queue``

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

## Hashset std set
i.e. ``std::unordered_set``

https://www.geeksforgeeks.org/unordered_set-in-cpp-stl/

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
std::unordered_set<int>::iterator it // set iterator
hs.insert(key); // insert
hs.find(key) == hs.end() // boolean key is not in
hs.count(key) == 1 // boolean key is in
hs.erase(key)
hs.clear()
hs.size()
hs.empty() // boolean check if it is empty
```

## Hashmap std map
i.e. ``std::unordered_map``

https://www.geeksforgeeks.org/unordered_map-in-cpp-stl/?ref=gcse

```cpp
#include <unordered_map>

void print(std::unordered_map<std::string, int>& hm){
    std::cout << "{";
    int size = hm.size(), i = 0;
    for(auto it = hm.begin(); it != hm.end(); ++it, i++){
        std::cout << "(" << it->first << ", " << it->second << ")";
        if (i != size - 1)
            std::cout << ", ";
        else
            std::cout << "}\n";
    }
}

std::unordered_map<std::string, int> hm // declare map
std::unordered_map<std::string, int>::iterator it // map iterator
hm["one"] = 1 // insert keys:values
hm["two"] // returns the value at key "two"
hm.begin()
hm.end()
hm.erase(key)
hm.find(key) == hm.end() // boolean key is not it
hm.count(key) == 1 // boolean key is in
hm.clear()
hm.size()
hm.empty() // check if it is empty
```

## Priority queue or maxHeap std queue
i.e. priority queue, ``std::queue`` by default is a maxheap. 

``NB``: For the minheap push() negative values and negate top().

https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/?ref=lbp

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

``NB``: nice way to initialize a heap, given an array/vector in $O(n)$ using *heapify*. This is the trick:

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

## Linkedlists std list
i.e. ``std::list``
https://www.geeksforgeeks.org/list-cpp-stl/?ref=lbp

## Pairs std pair
i.e. ``std::pair``
https://www.geeksforgeeks.org/pair-in-cpp-stl/?ref=lbp

## Equal
https://www.geeksforgeeks.org/stdequal-in-cpp/?ref=gcse

## Binarytree
https://www.geeksforgeeks.org/binary-search-algorithms-the-c-standard-template-library-stl/?ref=rp

A tree with max 2 children. 

```java
// java code
public class TreeNode<T> {  
    public T val;  
	public TreeNode left, right;  
	public TreeNode(T val) { this.val = val; }  
    public TreeNode(T val, TreeNode left, TreeNode right) {  
		this.val = val;  
		this.left = left;
		this.right = right;  
  }  
};
```

**depth**: tree root with no children has depth 1
**height**: tree root with no children has height 0
**balanced**: 
	- height of left subt and height of right subt do not differ more then 1
     - left subt is balanced and right subt is balanced
**Binary Search Tree**:
	- the left subt contains only nodes with keys  *less than*  the node's key
	- the right subt contains only nodes with keys  *greater than* the node's key.
	- both the left and right subt must also be BST

### BFS
visiting in BFS / levelorder

```java
// java code
Queue<TreeNode<Integer>> qu = new LinkedList<>();  
qu.offer(root);  
int level = 0;  
while (!qu.isEmpty()) {
	int qusize = qu.size();   
	for (int i = 0; i < qusize; i++) {  
        TreeNode t = qu.poll();  
		System.out.println(t.val);  
		if (t.left != null) qu.offer(t.left);  
		if (t.right != null) qu.offer(t.right);  
	}  
    level++;  
}  
System.out.println("number of levels: " + level);
```

### stackDFS
visiting in DFS using a stack gives **pre-order**

```java
// java code
Deque<TreeNode<Integer>> st = new ArrayDeque<>();  
st.add(root);  
while (!st.isEmpty()){  
	TreeNode t = st.pop();  
	System.out.println(t.val);  
 if (t.left != null) st.add(t.left);  
 if (t.right != null) st.add(t.right);  
}
```

### recursiveDFS
visiting in DFS using recursion can give **(pre/in/post)-order**

```java
// java code
public  class  TreeNode<T>  {
	//... see binary tree definition

	public void preOrder(){ preOrder(this); }
	public void preOrder(TreeNode<T> root){  
		if (root == null) return;  
		System.out.println(root.val);  
		preOrder(root.left);  
		preOrder(root.right);  
	}

	public void inOrder(){ inOrder(this); }	
	public void inOrder(TreeNode<T> root){  
		if (root == null) return;  
		System.out.println(root.val);  
		inOrder(root.left);  
		inOrder(root.right);  
	}
		
	public void postOrder(){ postOrder(this); }
	public void postOrder(TreeNode<T> root){  
		if (root == null) return;  
		System.out.println(root.val);  
		postOrder(root.left);  
		postOrder(root.right);  
	}
}
```

## Trie
i.e. prefix tree
```java
// java code
public class TrieNode {  
	public TrieNode[] children;  
	public boolean endOfWord;  
	public TrieNode(){
		children = new TrieNode[26];  
		endOfWord = false;  
	}
}  

public static class Trie {  
    public TrieNode root;  
	public Trie() { root = new TrieNode(); }  
  
    public void insert(String word) {
    	//System.out.println("insert " + word);
		TrieNode curr = root;
		for (int i=0; i < word.length(); i++){  
			int c = (int)(word.charAt(i) - 'a');  
			//System.out.println("  letter: " + word.charAt(i) + " (" + c + ")");  
			
			if (curr.children[c] == null) {  
				//System.out.println("    not in, creating..");  
				curr.children[c] = new TrieNode(); 
				curr = curr.children[c];  
				continue;  
			}
			//System.out.println("    found!");  
			curr = curr.children[c];  
		}  
        curr.endOfWord = true;  
	}  
  
	public boolean search(String word) {  
		//System.out.println("search " + word);  	
		TrieNode curr = root;  
		for (int i=0; i < word.length(); i++){  
			int c = (int)(word.charAt(i) - 'a');  
			//System.out.println("  letter: " + word.charAt(i) + " (" + c + ")");  
			if (curr.children[c] == null) {  
				//System.out.println("    not found! exiting");  
				return false;  
			}  
			//System.out.println("    found!");  
			curr = curr.children[c];  
		}  
		return curr.endOfWord;  
	}  
  
	public boolean startWith(String prefix) {  
		TrieNode curr = root;  
		for (int i=0; i < prefix.length(); i++){  
			int c = (int)(prefix.charAt(i) - 'a');  
			if (curr.children[c] == null) return false;  
			curr = curr.children[c];  
		}  
		return true;  
	}  
}
```