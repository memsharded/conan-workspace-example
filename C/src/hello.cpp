#include <iostream>
#include "helloC.h"

void helloC(){
    
    #ifdef NDEBUG
    std::cout << "Hello World C Release!" <<std::endl;
    #else
    std::cout << "Hello World C Debug!" <<std::endl;
    #endif
}
