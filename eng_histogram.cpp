//
// Created by 한현민 on 2021-07-09.
//

#include "eng_histogram.h"
using namespace std;

bool histogram() {
    ifstream input("C:\\Users\\deblu\\CLionProjects\\c++_practice\\passage.txt"); // input file stream from passage.txt
    int total = 0; array<int, 26> countArr{0, }; // initialization
    string line; char letter; bool isEnd = false;

    if (input.fail()) { // check whether the file is opened well or not
        cout << "failed to open the file" << endl;
        return false;
    }

    while (!input.eof() && !isEnd) {
        getline(input, line);
        cout << line << endl; // print each line from txt

        // find 함수는 탐색에 실패하면 -1을 반환하고, string::npos는 -1인 상수를 의미
        // 따라서 찾았을 때 true가 되려면 두 개를 비교하여 다른 값이 나올 때 true가 나오게 하면 된다.
        if (line.find(';') != string::npos) { // passage.txt 파일에서 세미콜론이 있는 부분까지 처리
            isEnd = true;
        }

        // count alphabets in each letter of the line
        for (int i = 0; i < line.length(); i++) {
            if (isalpha(line[i])) {
                letter = tolower(line[i]);
                countArr[(int)(letter - 'a')] += 1;
                total++;
            }
        }
    }

    // print results
    cout << "총 알파벳 수 " << total << endl << endl;

    for (int i = 0; i < 26; i++) {
        cout << (char)('a'+i) << " (" << countArr[i] << ")\t: ";
        for (int j = 0; j < countArr[i]; j++) {
            cout << "*";
        }
        cout << endl;
    }

    input.close();
    return true;
}