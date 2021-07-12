//
// Created by 한현민 on 2021-06-30.
//

#include <iostream>
#include <string>
#include "MorseCode.h"

int main() {
    std::string myText = "";
    std::string myMorse = "";
    MorseCode myCode;

    std::cout << "아래에 영문 텍스트를 입력하세요. 모스 부호로 바꿉니다." << std::endl;
    std::getline(std::cin, myText);

    myCode.text2Morse(myText, myMorse);
    std::cout << myMorse << std::endl;

    std::cout << "모스 부호를 다시 영문 텍스트로 바꿉니다." << std::endl;

    myCode.morse2Text(myMorse, myText);
    std::cout << myText << std::endl;

    return 0;
}