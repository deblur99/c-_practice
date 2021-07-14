//
// Created by 한현민 on 2021-07-12.
//

#ifndef UNTITLED_MORSECODE_H
#define UNTITLED_MORSECODE_H

#include <iostream>
#include <string>

// 알파벳, 숫자, 특수 문자의 개수를 상수로 정의
#define WORD_LENGTH 26
#define DIGIT_LENGTH 10
#define MISC_LENGTH 6

// 모스 부호에 사용되는 문자 3개를 상수로 정의
#define DOT '.'
#define DASH '-'
#define SPACE ' '

// 각 특수 문자에 대한 상수 정의
#define SLASH '/'
#define QUESTION '?'
#define COMMA ','
#define PERIOD '.'
#define PLUS '+'
#define EQUAL '='

enum _Exception {
    TypeException = -2, IntegerException, ExitException, KeepException
};

class MorseCode {
private:
    std::string alphabet[WORD_LENGTH];
    std::string digit[DIGIT_LENGTH];
    std::string misc[MISC_LENGTH];
    char miscLetter[MISC_LENGTH] =
            { SLASH, QUESTION, COMMA, PERIOD, PLUS, EQUAL };

public:
    MorseCode();
    void printSelection();
    int getDecision();
    int controller();
    void text2Morse(std::string text, std::string& morse);
    bool morse2Text(std::string morse, std::string& text);
};

#endif //UNTITLED_MORSECODE_H
