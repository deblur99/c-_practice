//
// Created by 한현민 on 2021-07-09.
//

#ifndef UNTITLED_COFFEEMACHINE_H
#define UNTITLED_COFFEEMACHINE_H


class CoffeeMachine {
private:
    int coffee;
    int water;
    int sugar;
public:
    CoffeeMachine(int c, int w, int s);
    void drinkEspresso();
    void drinkAmericano();
    void drinkSugarCoffee();
    void fill();
    void show();
};

#endif //UNTITLED_COFFEEMACHINE_H
