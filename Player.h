//
// Created by 한현민 on 2021-06-30.
//

#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H

#include <string>

using namespace std;

class Test {
public:
    int num;
    Test() {
        num = 10;
    }
};

class Player {

private:
    int _health=100;
    int _power=50;
    Test _test;
    const string _name="noname";

    // constructor
public:
    Player() = delete;
    Player(int health, int power, string name)
    // 멤버 변수 초기화
    : _health(health), _power(power), _name(name) {
        _health = health;
        _power = power;
        // _name = name -> error (상수에 대입 연산)
        cout << "Player " << _health << ", " << _power << endl;
    }

    void print() {
        cout << _health << ":" << _power << ":" << _name << endl;
    }
};


#endif //UNTITLED_PLAYER_H
