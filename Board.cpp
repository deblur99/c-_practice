//
// Created by 한현민 on 2021-07-20.
//

#include "Board.h"

void Board::add(std::string news) {
    if (size >= MAX)
        return;

    board[size] = news;
    size++;

    return;
}

void Board::print() {
    for (int i = 0; i < 13; i++) std::cout << "*";
    std::cout << " 게시판입니다. ";
    for (int i = 0; i < 13; i++) std::cout << "*";
    std::cout << std::endl;

    for (int i = 0; i < size; i++) {
        std::cout << i << ": " << board[i] << std::endl;
    }

    std::cout << std::endl;
}