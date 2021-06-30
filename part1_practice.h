//
// Created by 한현민 on 2021-06-30.
//

#ifndef UNTITLED_PART1_PRACTICE_H
#define UNTITLED_PART1_PRACTICE_H

#endif //UNTITLED_PART1_PRACTICE_H

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cfloat>
#include <functional>
using namespace std;

void myString();
void myVector();
void myArray();
void float_compare();
void referEx();

int factorial(int n);
int fibonacci(int n);
void printUsingRecursive();
int power(int num, int cur, int time);

struct Weapon {
    int price;
    int power;
};

void updateWeapon(Weapon *weapon);
void weaponEx();

void func(int a, int b);
void func(string s);

int sum(int x, int y);

enum struct RequestType {
    Login, Register, Update, Delete
};

bool onLogin(string id, string password);

bool onRegister(string id, string password);

bool onUpdate(string id, string password);

bool onDelete(string id, string password);

void callbacksEx();

struct Character {
    int health;
    void (*diedCallback)();
};

void damaged(Character *character);

void gameOver(int n);

inline int square(int x);

void main_practice1();