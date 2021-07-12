//
// Created by 한현민 on 2021-06-30.
//

#include <iostream>
using namespace std;

class Circle {
    int radius;
public:
    Circle() {}
    Circle(int r) { radius = r; }
    Circle(const Circle &c);
    double getArea();
};

Circle::Circle(const Circle &c) {
    this->radius = c.radius;
    cout << "복사 생성자 실행 radius = " << radius << endl;
}

inline double Circle::getArea() {
    return 3.14*radius*radius;
}

int main() {
    Circle src(30);
    Circle desc(src);

    cout << "원본 면적 : " << src.getArea() << endl;
    cout << "사본 면적 : " << desc.getArea() << endl;
}