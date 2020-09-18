#include <iostream>

enum Level /* if you add : unsigned char you can also specify the type */
{
	/* by default it starts from 0 
	 * but you can assign them a value like this
	 * Error = 7, Warning, Info 
	 * so Warning will be 8 and Info 9 */
	Error, Warning, Info
};

enum Letter : unsigned char
{
	first = 'a', second, third
};


int main(int argc, char **argv)
{
	Level l = Level::Error;
	std::cout << "level is: " << l << std::endl;

	l = Level::Info;
	std::cout << "level is: " << l << std::endl;	
	
	Letter le = Letter::third;
	std::cout << "letter is: " << (char)le << std::endl;
	
	//return 0;
}
