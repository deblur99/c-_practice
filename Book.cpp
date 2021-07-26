//
// Created by 한현민 on 2021-07-26.
//

#include "Book.h"

Book::Book(string title, int price, int pages):
    title(title), price(price), pages(pages) {};

void Book::show() {
    cout << title << " " << price << "원 " << pages << " 페이지" << endl;
}

string Book::getTitle() {
    return title;
}

Book& operator += (Book &op1, int cost) {
    op1.price = op1.price + cost;
    return op1;
};

Book& operator -= (Book &op1, int cost) {
    op1.price = op1.price - cost;
    return op1;
};

// Remark : 멤버 함수로써 연산자 오버로딩 시, 두 번째 피연산자만 명시한다.
bool Book::operator == (int op2) {
    return price == op2;
}

bool Book::operator == (string op2) {
    return title == op2;
}

bool Book::operator == (Book op2) {
    return Book::operator==(op2.price)
        && Book::operator==(op2.title)
        && pages == op2.pages;
}