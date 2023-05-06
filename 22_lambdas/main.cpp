#include <iostream>
#include <vector>    
#include <algorithm>
#include <iterator>

int main(){
    std::vector<int> v {1, 2, 3, 4};

    // defining my lambda: check if i is even or odd
    auto is_even = [](int i) { return i % 2 == 0; };

    // result is an iterator that points to the first match 
    // or to end() if no match are found
    auto result = std::find_if(begin(v), end(v), is_even);
 
    // if something is found dereference iterator to print the first match
    (result != std::end(v))
        ? std::cout << "v contains an even number: " << *result << '\n'
        : std::cout << "v does not contain even numbers\n";

    // another example 
    // inside [] I put captures, I can use:
    // = captures everything by value 
    // & captures everything by reference 
    // zero to n variables/classes by reference or by value
    // e.g. [a] to pass variable a by value
    // [&a] to passa variable a by reference
    int const max = 100;
    std::vector<int> vec {178, 101, 123, 145, 45, 33};
    auto lambda = [max](int i){ return i < max; };
    auto it = std::find_if(begin(vec), end(vec), lambda);
    (it != end(vec))
        ? std::cout << "first element <= then max is: " << *it << std::endl
        : std::cout << "all element are greater then max." << std::endl;

}