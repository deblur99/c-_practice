//
// Created by 한현민 on 2021-07-20.
//

#ifndef UNTITLED_BOARD_H
#define UNTITLED_BOARD_H

#include <iostream>
#include <string>
#include <vector>

#define MAX 10

class Board {
private:
    inline static std::string board[MAX];
    inline static int size; // 정적 변수는 기본적으로 0으로 초기화됨
public:
    static void add(std::string news);
    static void print();
};

#endif //UNTITLED_BOARD_H
