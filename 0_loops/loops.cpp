#include <iostream>

int main()
{
    for(int i=0; i<5; i++)
        std::cout << i << std::endl;

    bool condition = false;

    // it will run only if condition is true
    while(condition)
        std::cout << "while" << std::endl;

    // it will run at least once, then it will evaluate condition
    do{
        std::cout << "do while" << std::endl;
    }while(condition);
}