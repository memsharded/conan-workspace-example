#include <iostream>
#include "helloA.h"
#include "helloB.h"

void helloA(){
    helloB();
    #ifdef NDEBUG
    std::cout << "Hello World A Release!" <<std::endl;
    #else
    std::cout << "Hello World A Debug!" <<std::endl;
    #endif
}
