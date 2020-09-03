#include "log.h"
#include <iostream>

void initLog() {
	log("init log");
}

void log(const char* message){
	std::cout << message << std::endl;
}