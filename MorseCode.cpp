//
// Created by 한현민 on 2021-07-12.
//

/*
 * 모스 부호 프로그램
 * 영문 텍스트, 숫자, 몇 개의 특수 문자로 구성되는 텍스트를 모스 부호로 변환한다.
 * 각 모스 코드들은 하나의 빈칸으로 분리되고, 영문 워드 하나가 모스 워드로 변환되면
 * 워드들은 3개의 빈칸으로 분리된다.
 * */

#include "MorseCode.h"

#define WORD_LENGTH 26
#define DIGIT_LENGTH 10
#define MISC_LENGTH 6

MorseCode::MorseCode() {
    // init
    std::string alphabetList[WORD_LENGTH] = {
            ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
            "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
            "..-", "...-", ".--", "-..-", "-.--", "--.."
    };

    for (int i = 0; i < WORD_LENGTH; i++) {
        *(this->alphabet + i) = alphabetList[i];
    }

    std::string digitList[DIGIT_LENGTH] = {
            "-----", ".----", "..---", "...--", "....-",
            ".....", "-....", "--...", "----..", "----."
    };

    for (int i = 0; i < DIGIT_LENGTH; i++) {
        *(this->digit + i) = digitList[i];
    }

    this->slash = "-..-.", this->question = "..--..", this->comma = "--..--",
    this->period = ".-.-.-", this->plus = ".-.-.", this->equal = "-...-";

}

void MorseCode::text2Morse(std::string text, std::string& morse) {
    // list
    char item;

    char miscLetter[MISC_LENGTH] = {
            '/', '?', ',', '.', '+', '='
    };

    for (int i = 0; i < text.length(); i++) {
        // 현재 인덱스의 문자가 알파벳일 경우, 알파벳에 대응하는 모스 부호 리스트에서 탐색
        if (isalpha(text[i])) {
            for (int j = 0; j < WORD_LENGTH; j++) {
                if (text[i] == ('a' + j)) { // 일치하는 문자를 찾으면 그에 해당하는 모스 부호를 문자열에 추가
                    morse += alphabet[j];
                    break;
                }
            }
        }

        // 현재 인덱스의 문자가 숫자일 경우, 알파벳에 대응하는 모스 부호 리스트에서 탐색
        else if (isdigit(text[i])) {
            for (int j = 0; j < DIGIT_LENGTH; j++) {
                if (text[i] == ('0' + j)) { // 일치하는 문자를 찾으면 그에 해당하는 모스 부호를 문자열에 추가
                    morse += digit[j];
                    break;
                }
            }
        }

        else if (isspace(text[i])) {
            morse += "  "; // 원본에서 공백 문제는 모스 부호에서 공백 3칸 추가를 의미
        }

        // 그 외 문자일 경우, 그에 대응하는 모스 부호를 추가
        else {
            // 현재 인덱스에 해당하는 특수문자와 일치하면 item 변수에 문자열을 저장하고 반복문 탈출
            for (int j = 0; j < MISC_LENGTH; j++) {
                if (text[i] == miscLetter[j]) {
                    item = miscLetter[j];
                    break;
                }
            }

            // 각 문자에 해당하는 모스부호를 추가
            switch (item) {
                // "slash", "question", "comma", "period", "plus", "equal"
                case '/':
                    morse += this->slash;
                    break;
                case '?':
                    morse += this->question;
                    break;
                case ',':
                    morse += this->comma;
                    break;
                case '.':
                    morse += this->period;
                    break;
                case '+':
                    morse += this->plus;
                    break;
                case '=':
                    morse += this->equal;
                    break;
            }
        }

        morse += " ";
    }
}

bool MorseCode::morse2Text(std::string morse, std::string& text) {
    // 변수 선언
    int count = 0;
    std::string buffer = "";

    std::string miscList[MISC_LENGTH] = {
            slash, question, comma, period, plus, equal
    };

    char miscLetter[MISC_LENGTH] = {
            '/', '?', ',', '.', '+', '='
    };

    // morse의 앞부분부터 순차적으로 검사
    for (int i = 0; i < morse.length(); i++) {

        if (morse[i] != '-' && morse[i] != '.' && morse[i] != ' ') {
            break;
        }

        // 공백이 이어져 있는지 확인
        if (isspace(morse[i])) {
            count++;

            // 공백이 연속으로 3개 있으면 텍스트에서 공백을 의미하므로 공백을 쓰고 count 초기화
            if (count == 3) {
                count = 0;
                text += " ";
            }
        }

        // 공백을 발견하기 전까지 문자를 buffer 변수에 저장
        else {
            buffer += morse[i];
        }

        // while 문을 벗어나면 공백을 발견한 것이므로
        // 공백이 하나만 존재하면 배열들의 요소들 중 일치하는 요소를 찾고, text 변수에 요소에 해당하는 문자를 추가
        for (int j = 0; j < WORD_LENGTH; j++) {
            if (buffer == alphabet[j]) {
                text += 'a' + j;
                break;
            }
        }

        for (int j = 0; j < DIGIT_LENGTH; j++) {
            if (buffer == digit[j]) {
                text += '0' + j;
                break;
            }
        }

        // 기타 특수문자들과 비교
        for (int j = 0; j < MISC_LENGTH; j++) {
            if (buffer == miscList[j]) {
                text += miscLetter[j];
                break;
            }
        }

        // 텍스트에 문자를 추가했다면 공백 카운트 초기화
        count = 0;
    }

    return true;
}