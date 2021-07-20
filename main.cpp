//
// Created by 한현민 on 2021-06-30.
//

#include <iostream>
using namespace std;

// 전방선언
class Rect;

class RectManager {
public:
    bool equals(Rect r, Rect s);
};

class Rect {
    int width, height;
public:
    Rect() { Rect(10, 20); } // 위임생성자
    Rect(int width, int height) : width(width), height(height) {}
    friend RectManager;
};

bool RectManager::equals(Rect r, Rect s) {
    if (r.width == s.width && r.height == s.height) return true;
    else return false;
}

int main() {
    Rect a(3, 4), b(3, 4);
    RectManager manager;
    if (manager.equals(a, b)) cout << "equal" << endl;
    else cout << "not equal" << endl;
}