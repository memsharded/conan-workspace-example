#include <iostream>
#include "helloB.h"
#include "helloC.h"
void helloB(){
    helloC();
    #ifdef NDEBUG
    std::cout << "Bye Moon B Release!" <<std::endl;
    #else
    std::cout << "Bye Moon B Debug!" <<std::endl;
    #endif
}
