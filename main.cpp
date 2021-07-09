//
// Created by 한현민 on 2021-06-30.
//

#include <iostream>
using namespace std;

int main() {
    cout << "Enter the number of integers to input";
    int n;
    cin >> n;
    if (n <= 0) return 0;
    int *p = new int[n]; // 동적 배열 생성
    if (!p) {
        cout << "Unable to allocate memory";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << i+1 << "번째 정수: ";
        cin >> p[i]; // 배열에 요소 입력
    }

    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += p[i];
    }

    cout << "평균: " << sum / n << endl;

    delete [] p; // 동적 배열 해제할 때는 delete []를 사용한다.

    return 0;
}