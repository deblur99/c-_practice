//
// Created by 한현민 on 2021-06-30.
//

#include <iostream>
#include <string>
using namespace std;

class Person {
    string name;
    int id;
public:
    Person(int id, const string name);
    Person(const Person& person);
    void changeName(const string name);
    void show();
};

Person::Person(int id, const string name) {
    this->id = id;
    this->name = name;
}

Person::Person(const Person &person) {
    this->id = person.id;
    this->name = person.name;
    cout << "복사 생성자 실행, 원본 객체의 이름 : " << this->name << endl;
}

void Person::changeName(const string name) {
    this->name = name;
}

void Person::show() {
    cout << id << ", " << name << endl;
}

int main() {
    Person yum(20, "yum");
    Person jack(yum);

    cout << "jack 객체 생성 직후 ----" << endl;
    yum.show();
    jack.show();

    jack.changeName("hyejin");
    cout << "이름 변경한 후 ----" << endl;
    yum.show();
    jack.show();

    return 0;
}