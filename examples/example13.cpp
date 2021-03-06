#include <stdexcept>
#include <iostream>

#include "../include/safe_integer.hpp"

int main(int argc, const char * argv[]){
    // problem: checking of externally produced value can be overlooked
    std::cout << "example 7: ";
    std::cout << "cannot recover From arithmetic errors" << std::endl;
    std::cout << "Not using safe numerics" << std::endl;

    try{
        int x = 1;
        int y = 0;
        // can't do this as it will crash the program with no
        // opportunity for recovery - comment out for example
        //std::cout << x / y;
        std::cout << " error NOT detectable!" << std::endl;
    }
    catch(std::exception){
        std::cout << "error detected!" << std::endl;
    }

    // solution: assign externally retrieved values to safe equivalents
    std::cout << "Using safe numerics" << std::endl;
    try{
        using namespace boost::numeric;
        safe<int> x = 1;
        safe<int> y = 0;
        std::cout << x / y;
        std::cout << " error detected!" << std::endl;
    }
    catch(std::exception & e){
        std::cout << e.what() << std::endl;
        std::cout << "error detected!" << std::endl;
    }
    return 0;
}
