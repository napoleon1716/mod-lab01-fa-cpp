// Copyright 2022 UNN-IASR
#include "fun.h"
#include <iostream>
#include <string>

int main() {
    std::string str;
    std::cout << "Enter a string: ";
    std::getline(std::cin, str);
    const char* cstr = str.c_str();

    std::cout << "faStr1: " << faStr1(cstr) << std::endl;
    std::cout << "faStr2: " << faStr2(cstr) << std::endl;
    std::cout << "faStr3: " << faStr3(cstr) << std::endl;
    return 0;
}
