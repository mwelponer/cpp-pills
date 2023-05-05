#include <iostream>

template <typename T, int N>
class Array
{
private:
    // T is the array type known and set at compile time
    T m_array[N]; // N is the size known and set at compile time

public:
    int getSize() const { return N; }
};

int main()
{
    Array<float, 50> array;
    // a version of Array with type float and size 50 will be created 
    // at compile time
    
    std::cout << array.getSize() << std::endl;
}