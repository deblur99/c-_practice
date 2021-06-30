//
// Created by 한현민 on 2021-06-30.
//
#include <iostream>
#include <string>
#include <cstring>
#include "part1_practice.h"
#include "Player.h"

using namespace std;

int main() {
    //main_practice1();

    // 객체지향 프로그래밍의 가장 큰 장점은 추상화
    // 은닉: 구체적으로 확인하려면 깊게 들어가야하나 기능을 간편하게 사용할 수 있음
    Player player3; // 객체를 만드는 상황. 생성자 호출이 아님
    player3.print();

    return 0;
}