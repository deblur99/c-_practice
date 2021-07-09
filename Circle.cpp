//
// Created by 한현민 on 2021-07-09.
//

#include <iostream>
#include "Circle.h"

Circle::Circle() : Circle(10) {}

Circle::Circle(int radius) {
    this->radius = radius;
}

Circle::~Circle() {
    std::cout << radius << "Instance deleted" << std::endl;
}