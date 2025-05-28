// Complete Guide to C++ Programming Foundations
// Exercise 08_02
// Template Functions, by Eduardo Corpeño 

#include <iostream>
#include <string>

// Template function to calculate the size in bits of a given data type
template <typename T>
int size_in_bits(T a) {
    return sizeof(a) * 8;
}

int main(){
    std::cout << size_in_bits(21) << std::endl;    // Integer
    std::cout << size_in_bits('f') << std::endl;   // Character
    std::cout << size_in_bits(32.1f) << std::endl; // Float
    std::cout << size_in_bits(32.1) << std::endl;  // Double
    
    std::cout << "==========" << std::endl;
    std::cout << size_in_bits((short)42) << std::endl;  // Short
    std::cout << size_in_bits(123456789L) << std::endl; // Long
    std::cout << size_in_bits(std::string("Hello")) << std::endl;       // String
    std::cout << size_in_bits(true) << std::endl;

    std::cout << std::endl << std::endl;                // Bool
    return 0;
}
