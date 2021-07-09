//
// Created by 한현민 on 2021-07-09.
//

#include <iostream>
#include "Ram.h"

Ram::Ram() {
    for (int i = 0; i < SIZE; i++) {
        mem[i] = 0;
    }
    size = SIZE;
}

Ram::~Ram() {
    std::cout << "메모리 제거됨" << std::endl;
}

char Ram::read(int address) {
    return mem[address];
}

void Ram::write(int address, char value) {
    mem[address] = value;
}