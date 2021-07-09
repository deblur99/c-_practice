//
// Created by 한현민 on 2021-07-09.
//

#ifndef UNTITLED_CIRCLE_H
#define UNTITLED_CIRCLE_H

class Circle {
public:
    int radius;
    inline double getArea() {
        return 3.14 * radius * radius;
    }
    inline double getDiameter() {
        return 2 * 3.14 * radius;
    }
    Circle();
    Circle(int radius);
    ~Circle();
};


#endif //UNTITLED_CIRCLE_H
