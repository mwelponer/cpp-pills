//
//  log.cpp
//  HeaderFiles
//
//  Created by Mike on 27/11/2021.
//
#include "log.h"
#include <iostream>

void initLog() {
    log("init log");
}

void log(const char* message){
    std::cout << message << std::endl;
}

