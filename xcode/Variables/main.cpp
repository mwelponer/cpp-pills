//
//  main.cpp
//  Variables
//
//  Created by Mike on 06/09/2020.
//  Copyright © 2020 Mike. All rights reserved.
//

#include <iostream>

int main(int argc, char **argv)
{
    // the only difference between all types of data
    // is how much memery will be allocated
    
    // char            1 byte
    // short        2 bytes
    // int            4 bytes
    // long            4 bytes
    // long long    8 bytes
    
    // unsigned {short, int, long}
    
    int a = 8;
    std::cout << a << std::endl;
    
    // float        4 bytes
    // double        8 bytes
    
    float f = 5.5f;
    std::cout << f << std::endl;
    double d = 5.5;
    std::cout << d << std::endl;
    
    // bool            1 byte
    bool var = true;
    std::cout << var << std::endl;
    
    // how to check a variable the size
    std::cout << sizeof(var) << std::endl;
    
    // pointer
    int* p;
    
    // references
    int& r = a;
    
    //return 0;
}
