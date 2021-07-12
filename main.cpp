//
// Created by 한현민 on 2021-06-30.
//

#include <iostream>
using namespace std;

int arr[5] = {0,1,3,5,7};

int& f(int n) {
    return arr[n];
}

void print() {
    for (int e : arr) cout << e << " ";
    cout << endl;
}

int main() {
    f(0) = 100; // 1
    print();

    int sum = 0; // 2
    for (int i = 1; i < 5; i++) {
        sum += f(i);
    }
    f(0) = sum;
    print();

    int &v = f(2); v++; // 3
    print();

    // 결과: 참조로 연산하면 연산은 모든 범위에서 반영된다
}