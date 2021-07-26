//
// Created by 한현민 on 2021-06-30.
//

#include "Book.h"

int main() {
    Book a("명품 C++", 30000, 500), b("고품 C++", 30000, 500);
    if (a == 30000) cout << "정가 30000원" << endl;
    if (a == "명품 C++") cout << "명품 C++입니다." << endl;
    if (a == b) cout << "두 책이 같은 책입니다." << endl;

    return 0;
}