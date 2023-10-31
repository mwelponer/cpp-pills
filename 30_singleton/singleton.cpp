#include <iostream>


class Singleton
{
private:
	static Singleton* s_instance;
public: 
	static Singleton& get() { return *s_instance;}
	
	void hello() { std::cout << "hello " << std::endl; }
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


class SingletonExample
{

public:
	static SingletonExample& get()
	{
		static SingletonExample instance;
		return instance;
	}

	void setStatus() { this->status = 1; }
	static int getStatus() { return get().status; }

private:
	int status;
	SingletonExample() : status(0) {
		std::cout << "constr" << std::endl;
	}
};


// before being able to use to use Singleton::get() I need somewhere 
// to instantiate the instance 
Singleton* Singleton::s_instance = nullptr;


int main()
{
	Singleton::get().hello();
	BetterSingleton::get().hello();


	// multiple references retrieve the very same instance 
	std::cout << SingletonExample::getStatus() << std::endl;

	SingletonExample& se1 = SingletonExample::get();
	SingletonExample& se2 = SingletonExample::get();
	auto& se3 = SingletonExample::get();

	std::cout << "s1 " << se1.getStatus() << std::endl;
	se1.setStatus();

	std::cout << "s1 " << se1.getStatus() << std::endl;
	std::cout << "s2 " << se2.getStatus() << std::endl;
	std::cout << "s3 " << se3.getStatus() << std::endl;

	std::cout << SingletonExample::getStatus() << std::endl;
}