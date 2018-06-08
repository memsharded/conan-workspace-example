#include <iostream>
#include "helloB.h"
#include "helloC.h"

void helloB(){
    helloC();
    #ifdef NDEBUG
    std::cout << "Hello World B Release!" <<std::endl;
    #else
    std::cout << "Hello World B Debug!" <<std::endl;
    #endif
}
