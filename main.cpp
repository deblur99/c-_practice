//
// Created by 한현민 on 2021-06-30.
//

#include <iostream>
using namespace std;

class Foo {
private:
    int n;
public:
    Foo() {
        n = 1;
        cout << "생성자 실행 n = " << n << endl;
    }
    Foo(int n) {
        this->n = n;
        cout << "생성자 실행 n = " << n << endl;
    }
    ~Foo() {
        cout << "소멸자 실행 n = " << n << endl;
    }
    inline void setNumber(int n) {
        this->n += n;
    }
    inline int getNumber() {
        return this->n;
    }
};

Foo getCircle() {
    Foo temp(30);
    return temp;
}

int main() {
    Foo ins(10);
    Foo tmp = getCircle();
    Foo &ref = tmp;
    cout << tmp.getNumber() << endl;
    tmp.setNumber(10);

    if (tmp.getNumber() == ref.getNumber())
        cout << "Equal" << endl;

    return 0;
}