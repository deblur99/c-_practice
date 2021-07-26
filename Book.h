//
// Created by 한현민 on 2021-07-26.
//

#ifndef UNTITLED_BOOK_H
#define UNTITLED_BOOK_H

#include <iostream>
#include <string>
using namespace std;

class Book {
    string title;
    int price, pages;
public:
    Book(string title = "", int price = 0, int pages = 0);
    void show();
    string getTitle();
    friend Book& operator += (Book &op1, int cost);
    friend Book& operator -= (Book &op1, int cost);
    bool operator == (int op2);
    bool operator == (string op2);
    bool operator == (Book op2);
};

Book& operator += (Book &op1, int cost);
Book& operator -= (Book &op1, int cost);

#endif //UNTITLED_BOOK_H
