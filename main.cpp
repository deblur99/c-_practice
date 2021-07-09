//
// Created by 한현민 on 2021-06-30.
//
#include <iostream>
#include <functional>
#include "eng_histogram.h"

using namespace std;

class Person {
public:
    static void print(int i) {
        cout << i << endl;
    }
};

int main() {
    // typedef void (Person::*FuncType)(int);
    /*
    using FuncType = void (Person:: *)(int);
    FuncType fn = &Person::print;
    */

    // function<void(Person*, int)> func = &Person::print;

    histogram();
    return 0;
}