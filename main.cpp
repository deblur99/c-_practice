//
// Created by 한현민 on 2021-06-30.
//

#include <iostream>
#include "Ram.h"

int main() {
    Ram ram;
    ram.write(100, 20);
    ram.write(101, 30);
    char res = ram.read(100) + ram.read(101);
    ram.write(102, res);
    std::cout << "102 번지의 값 = " << (int)ram.read(102) << std::endl;

    return 0;
}