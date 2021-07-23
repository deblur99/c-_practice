//
// Created by 한현민 on 2021-06-30.
//

#include <iostream>
#include <cstring>
using namespace std;

class Money; // 전방선언

class overloadingEx {
    string s1;
public:
    overloadingEx(string myString) {
        s1 = myString;
    }

    int operator + (string s2) {
        return s1.length() + s2.length();
    }
};

Money operator + (Money m1, Money m2);

class Money {
    int amount;
public:
    Money(int amount) {
        this->amount = amount;
    }
    friend Money operator + (Money m1, Money m2) {
        Money res(m1.amount + m2.amount);
        return res;
    }
    void showMoney() {
        cout << amount << endl;
    }
};

int main() {
    overloadingEx myString("Hello ");
    int result = myString + "World!";
    cout << result << endl;

    Money m1(10), m2(20);
    Money m3 = m1 + m2;
    m3.showMoney();

    return 0;
}