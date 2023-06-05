#include <iostream>
#include <string>

class Entity {

private:
	std::string m_name;

public:
	Entity() :
		m_name("unknown") {}
	Entity(const std::string& name) :
		m_name(name) {}

	void print(const int index) const { std::cout << index << ". Hi! I am " << m_name << std::endl;}
};

// let's write a scoped entity pointer
// so that I can use it like so ScopedPtr entity = new Entity();
// and the pointer mem gets released automatically
class ScopedPtr {
private:
	Entity* m_obj;
public:
	ScopedPtr(Entity* entity) :
		m_obj(entity){}

	~ScopedPtr(){ delete m_obj; }

	Entity* getObj(){ return m_obj; }

	// overloading of the -> operator !!!
	Entity* operator->() { return m_obj; }
	// in case we need const then we also add 
	const Entity* operator->() const { return m_obj; }	
};

struct Vector3 {
	float x, y, z;
};

int main() {
	// 1. understand -> meaning
	Entity e("mike");
	// let's create a pointer
	Entity* ptr = &e;
	// to use object's method we need to dereference the pointer
	Entity& de_e = *ptr;
	de_e.print(2);
	// or more simplier 
	(*ptr).print(3);
	// and here it is where the arrow operator comes handy
	// we can simply do
	ptr->print(4);
	// so the arrow -> just dereference the pointer and then calls the method


	// 2. let's imagine we have a scoped Entity pointer 
	ScopedPtr entity = new Entity("scoped");
	// NB: we can also write ScopedPtr entity(new Entity());
	// and we want to access the internal Entity pointer obj
	// we can use getObj() but this is not so nice to see
	entity.getObj()->print(5);
	// so we can add overloading of the arrow operator to the scopedPtr and write
	entity->print(6);
	// const version 
	const ScopedPtr entity2 = new Entity("scoped const");
	entity2->print(0);


	// 3. let's use the arrow to access the get the offset of a certain member 
	// variable in memory
	// cast 0 to Vector3 ptr to get x
	// add & to get the memory address of x
	&((Vector3*)0)->x;
	// if I then cast it to integer
	int offset = (int)&((Vector3*)0)->y;
	std::cout << "offset:" << offset << std::endl;
}
