#include <iostream>
#include "helloC.h"

void helloC(){
    
    #ifdef NDEBUG
    std::cout << "Bye Moon C Release!" <<std::endl;
    #else
    std::cout << "Bye Moon C Debug!" <<std::endl;
    #endif
}
