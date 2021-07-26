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
    Power operator + (Power op);
    Power operator + (int n);
    Power& operator ++ ();
    bool operator ! ();
};

void Power::show() {
    cout << "kick : " << kick << ", punch : " << punch << endl;
    return;
}

Power Power::operator+(Power op) {
    Power ret;
    ret.kick = kick + op.kick;
    ret.punch = punch + op.punch;
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

int main() {
    Power a(3, 5), b(0, 0), c(4, 9);
    ++a;
    a.show();

    if (!b) cout << "power of b is 0" << endl;
    else cout << "power of b is not 0" << endl;

    if (!c) cout << "power of c is 0" << endl;
    else cout << "power of c is not 0" << endl;

    return 0;
}