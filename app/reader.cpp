//
// Created by skydom on 3/19/2023.
//

#include <iostream>
#include "source_file.h"
#include "headerconfig.h"



int main(int argc, char* argv[] ) {
#ifdef BUGGER
    std::cout << "BUGGER used" << std::endl;
#endif
    std::cout << "Calling Lib" << std::endl;
    std::cout << "VERSION " <<  SimpleCmake_VERSION_MAJOR << "." << SimpleCmake_VERSION_MINOR << std::endl;
    hello();
    return 0;
}
