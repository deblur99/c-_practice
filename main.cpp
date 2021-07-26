//
// Created by 한현민 on 2021-06-30.
//

#include <iostream>
using namespace std;

class Power {
    int kick;
    int punch;
public:
    Power(int kick = 0, int punch = 0)
        : kick(kick), punch(punch) {};
    void show();
    friend Power operator + (int op1, Power op2); // 외부 함수를 friend 함수로써 초대
    Power operator + (int n);
    Power& operator ++ ();
    bool operator ! ();
    Power& operator -- (int x);
};

void Power::show() {
    cout << "kick : " << kick << ", punch : " << punch << endl;
    return;
}

Power operator + (int op1, Power op2) {
    Power ret;
    ret.kick = op1 + op2.kick;
    ret.punch = op1 + op2.punch;
    return ret;
}

Power Power::operator+(int n) {
    Power ret;
    ret.kick = kick + n;
    ret.punch = punch + n;
    return ret;
}

Power& Power::operator ++ () {
    kick++; punch++;
    return *this; // 객체의 this 포인터의 역참조를 반환
}

bool Power::operator ! () {
    return kick == 0 && punch == 0;
}

Power& Power::operator -- (int x) {
    kick--;
    punch--;
    return *this;
}

int main() {
    Power a(3, 5);
    Power b = 2 + a;
    b.show();

    return 0;
}