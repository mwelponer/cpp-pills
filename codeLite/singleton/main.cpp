#include <iostream>


class Singleton
{
private:
	static Singleton* s_instance;
public: 
	static Singleton& get() { return *s_instance;}
	
	void hello() { std::cout << "hello" << std::endl; }
};

class BetterSingleton
{
public:
	static BetterSingleton& get()
	{
		static BetterSingleton instance;
		return instance;
	}

	void hello() { std::cout << "hello" << std::endl; }	
};


Singleton* Singleton::s_instance = nullptr;


int main()
{
	Singleton::get().hello();
	BetterSingleton::get().hello();
	
	std::cin.get();
}
