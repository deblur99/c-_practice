//
// Created by 한현민 on 2021-07-09.
//

#include <iostream>
#include "CoffeeMachine.h"

CoffeeMachine::CoffeeMachine(int c, int w, int s) :
    coffee(c), water(w), sugar(s) {

}

void CoffeeMachine::drinkEspresso() {
    coffee--; water--;
}

void CoffeeMachine::drinkAmericano() {
    coffee--; water -= 2;
}

void CoffeeMachine::drinkSugarCoffee() {
    coffee--; water -= 2; sugar--;
}

void CoffeeMachine::fill() {
    coffee = water = sugar = 10;
}

void CoffeeMachine::show() {
    std::cout << "커피 머신 상태, 커피:" << coffee << "\t물:" << water << "\t설탕:" << sugar << std::endl;
}