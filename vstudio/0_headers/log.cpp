#include "log.h"
#include <iostream>

void log(const char* message)
{
	std::cout << message << std::endl;
}

void initLog()
{
	log("init log");
}