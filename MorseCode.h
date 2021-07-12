//
// Created by 한현민 on 2021-07-12.
//

#ifndef UNTITLED_MORSECODE_H
#define UNTITLED_MORSECODE_H

#include <iostream>
#include <string>

class MorseCode {
private:
    std::string alphabet[26];
    std::string digit[10];
    std::string slash, question, comma, period, plus, equal;

public:
    MorseCode();
    void text2Morse(std::string text, std::string& morse);
    bool morse2Text(std::string morse, std::string& text);
};


#endif //UNTITLED_MORSECODE_H
