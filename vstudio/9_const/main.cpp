#include <iostream>

class Entity 
{
private: 
	int m_X, m_Y;
	int* m_age;
	mutable int m_debugCount = 0; // mutable in the context of const: 
	// something that is kind of const but actually can change
	// so mutable allows method that are signed const to actually modify 
	// the mutable variable
	
public:
	/* this will be used by a non-const Entity or by a non-const Entity reference/pointer */
	int getX()
	{
		std::cout << "\n  into getX()" << std::endl;
		m_X = 2;
		return m_X;
	}
	
	/* This method will be used by a const Entity reference.
	 * const after the method name means that 
	 * I cannot modify the class member variables inside this method 
	 * So this method here is just kinda read-only method */ 
	int getX() const 
	{
		std::cout << "\n  into getX() const" << std::endl;
		//m_X = 2; // this is not allowed because the method is const!
		m_debugCount++; // allowed because the variable is declared as mutable!
		std::cout << "  m_debugCount: " << m_debugCount << std::endl;
		return m_X;
	}	

	/* we return a pointer
	 * 1. which we cannot modify what it points to (const after *)
	 * 2. which we cannot modify the value of what it points to (const before *)
	 * 3. and this method promises not to modify the actual Entity class (const after the method name)
	 * */
	const int* const getAge() const
	{
		return this->m_age;
	}
};


int main()
{
	/* normal use of const: the 'variable' MAX_AGE becomes a constant */
	const int MAX_AGE = 90;
	
	
	/* another use of const: const BEFORE the asterix
	 * the value of what the pointer points to can't be changed */
	const int* entity_a = new int; // this can be written also as 'int const* entity_a'
	//*entity_a = 5; // cannot do this because of const
	//std::cout << *entity_a << std::endl;
	delete entity_a;
	
	/* another use of const: const AFTER the asterix
	 * what the pointer points to can't be changed  */	
	int* const entity_b = new int;
	*entity_b = 5; // I still can modify the value of the variable the pointer points to
	//entity_b = &MAX_AGE; // but I cannot modify what the pointer points to
	//std::cout << *entity_b << std::endl;
	delete entity_b;
	
	/* and of course: const BEFORE & AFTER the asterix
	 * the pointer address and what it points at remain constant */	
	const int* const entity_c = new int;
	//*b = 5; // I cannot modify neither the value 
	//b = &MAX_AGE; // nor what the pointer points to
	//std::cout << *entity_c << std::endl;
	delete entity_c;	

	
	
	Entity ent;
	
	/* Let's use the direct Entity. This will use the normal getX() */
	std::cout << "\nent.getX:" << ent.getX() << std::endl;
	
	/* let's create a const Entity reference */
	const Entity& ref = ent;
	/* this will use the getX() const 
	 * because the Entity ref is declared const 
	 * so the normal getX() cannot be used */
	std::cout << "\nref.getX:" << ref.getX() << std::endl;
	std::cout << "\nref.getX:" << ref.getX() << std::endl;
}
