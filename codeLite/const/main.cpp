#include <iostream>

class Entity 
{
private: 
	int m_X, m_Y;
	int* m_age;
	mutable int m_lenght;
public:
	/* this will be used by a non-const Entity or Entity reference/pointer */
	int getX()
	{
		std::cout << "into getX()" << std::endl;
		m_X = 2; // this is allowed now because the method is not marked as const
		return m_X;
	}
	
	/* This method will be used by a const Entity reference.
	 * const after the method name means that 
	 * I cannot modify the filed inside the method */ 
	int getX() const 
	{
		std::cout << "into getX() const" << std::endl;
		//m_X = 2; // this is not allowed
		return m_X;
	}	

	/* here I can modify the variable m_lenght because it is declared
	 * mutable! */ 
	int getLenght() const 
	{
		m_lenght = 3; // allowed because the variable is declared as mutable!
		return m_lenght;
	}	

	/* we return 
	 * 1. a pointer that cannot be modified
	 * 2. the content of the pointer cannot be modified
	 * 3. and this method promises not to modify the actual Entity class */
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
	 * what the pointer points at remains constant */
	const int* a = new int; // this can be written also as int const* a
	// *a = 5; // cannot do this because of const
	std::cout << *a << std::endl;
	delete a;
	
	/* another use of const: const AFTER the asterix
	 * the pointer address remains constant */	
	int* const b = new int;
	*b = 5; // I still can modify what the pointer points at
	//b = &MAX_AGE; // but I cannot modify the pointer address
	std::cout << *b << std::endl;
	delete b;
	
	/* and of course: const BEFORE & AFTER the asterix
	 * the pointer address and what it points at remain constant */	
	const int* const c = new int;
	//*b = 5; // I cannot modify what the pointer points at
	//b = &MAX_AGE; // but I cannot modify the pointer address
	std::cout << *c << std::endl;
	delete c;	

	
	
	Entity en1, en2;
	
	/* Let's use the direct Entity. This will use the normal getX() */
	std::cout << "en1:" << en1.getX() << std::endl;
	
	/* let's create a const Entity reference */
	const Entity& ref = en2;
	/* this will use the getX() const 
	 * because the Entity ref is declared const 
	 * so the normal getX() cannot be used */
	std::cout << "en2:" << ref.getX() << std::endl;
	std::cout << "en2:" << ref.getLenght() << std::endl;
}
