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
    friend Power& operator ++ (Power & op);
    friend Power& operator ++ (Power & op, int x);
    Power& operator << (int x);
};

void Power::show() {
    cout << "kick : " << kick << ", punch : " << punch << endl;
    return;
}

Power& operator ++ (Power & op) {
    op.punch++;
    op.kick++;
    return op;
}

Power& operator ++ (Power & op, int x) {
    op.punch++;
    op.kick++;
    return op;
}

Power& Power::operator << (int x) {
    kick += x;
    punch += x;
    return *this;
}

int main() {
    Power a(3, 5);

    a.show();

    a << 5 << 8 << 6;

    a.show();

    return 0;
}