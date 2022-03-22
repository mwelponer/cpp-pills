#include <iostream>

void foo(int param)
{
    param += 1;
}

void foo2(int& param)
{
    param += 1;
}

int main()
{
    int arg = 69;
    
    foo(arg);
    std::cout << arg << std::endl;
    
    foo2(arg);
    std::cout << arg << std::endl;
}