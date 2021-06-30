
#include "part1_practice.h"

#define SQUARE(x) x * x

void myString() {
    string str("Hello string");
    cout << str << endl;
    return;
}

void myVector() {
    // vector는 array와 달리 크기를 따로 정하지 않아도 된다. 크기를 인자로 전달할 수 있다.
    vector<int> v(5, 2); // 2번째 인자는 초기값을 의미
    v.resize(10, 9); // 뒷 부분은 짤린다.

    // push_back()은 뒤에 값 추가하는 함수
    v.push_back(20);
    cout << v.size() << endl;

    // pop_back()은 뒤에 값 삭제하는 함수이며 삭제한 값을 반환하지 않음
    v.pop_back();
    cout << v.size() << endl;

    cout << v.front() << " " << v.back() << endl;

    // 그 외에도 swap() 함수나 비교 연산자 사용 가능
}

void myArray() {
    array<int, 10> arr = {50, };
    for (int e: arr) {
        cout << e << " ";
    }
    cout << endl;
}

void float_compare() {
    double f1 = 0.1L;
    float f2 = 0.1f;

    cout.precision(64);
    cout << f1 << endl << f2 << endl;

    if (f1 == f2) {
        cout << "Equal 1" << endl;
    }

    if (labs(f1 - f2) <= FLT_EPSILON) {
        cout << "Equal 2" << endl;
    }

    return;
}

void referEx() {
    vector<int> vec0;
    vector<int> &vec1 = vec0;
    vector<int> *vec2 = &vec0;

    vec0.push_back(10);
    vec1.push_back(20);
    vec2->push_back(30);

    for (int num: vec0) {
        cout << num << " ";
    }

    cout << endl;

    int *num0 = new int(12);
    int &num1 = *num0;

    cout << *num0 << endl;
    cout << num1 << endl;

    delete num0;

    return;
}

int factorial(int n) {
    if (n <= 1) return 1;
    else return n * factorial(n - 1);
}

int fibonacci(int n) {
    if (n < 1) return 0;
    else if (n <= 2) {
        return 1;
    }
    else return fibonacci(n - 2) + fibonacci(n - 1);
}

void printUsingRecursive() {
    array<int, 25> fibArray;

    for (int i = 1; i <= fibArray.size(); i++) {
        fibArray[i - 1] = fibonacci(i);
    }

    for (int res: fibArray) {
        cout << res << " ";
    }

    cout << endl;

    return;
}

int power(int num, int cur, int time) {
    if (cur > time) return 1;
    else return num * power(num, cur + 1, time);
}

void updateWeapon(Weapon *weapon) {
    weapon->price += 10;
    weapon->power += 10;
}

void weaponEx() {
    Weapon myWeapon{10, 20};

    cout << "Price : " << myWeapon.price << endl;
    cout << "Price : " << myWeapon.power << endl;

    updateWeapon(&myWeapon);

    cout << "Price : " << myWeapon.price << endl;
    cout << "Price : " << myWeapon.power << endl;
}

// overloading
void func(int a, int b) {
    cout << a + b << endl;
}

void func(string s) {
    cout << s << endl;
}

// function pointer
int sum(int x, int y) {
    return x + y;
}

bool onLogin(string id, string password) {
    cout << "onLogin" << endl;
    cout << "ID" << endl;
    cout << "Password" << endl;
    return true;
}

bool onRegister(string id, string password) {
    cout << "onRegister" << endl;
    cout << "ID" << endl;
    cout << "Password" << endl;
    return true;
}

bool onUpdate(string id, string password) {
    cout << "onUpdate" << endl;
    cout << "ID" << endl;
    cout << "Password" << endl;
    return true;
}

bool onDelete(string id, string password) {
    cout << "onDelete" << endl;
    cout << "ID" << endl;
    cout << "Password" << endl;
    return true;
}

void callbacksEx() {
    // 함수 포인터 배열 선언
    bool (*callbacks[])(string, string) {
            onLogin, onRegister, onUpdate, onDelete
    };

    // 각 함수들에 인덱싱 후 함수 호출
    callbacks[(int)RequestType::Login]("david", "1234");
    callbacks[(int)RequestType::Register]("david", "1234");
    callbacks[(int)RequestType::Update]("david", "1234");
    callbacks[(int)RequestType::Delete]("david", "1234");

    if (callbacks[(int)RequestType::Login]("david", "1234")) {
        cout << "Login successful" << endl;
    }
}

void damaged(Character *character) {
    character->health -= 100;
    if (character->health <= 0) {
        cout << "died" << endl;
        if (character->diedCallback)
            character->diedCallback();
    }
}

void gameOver(int n) {
    cout << "gameOver" << endl;
}

inline int square(int x) {
    return x * x; // 함수 호출한 자리를 inline 함수의 코드로 대체한다.
}

void main_practice1() {
    int a = 10;
    int &b = a;
    int *c = &a;

    cout << &a << " " << &b << endl;

    return;
}