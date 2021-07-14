//
// Created by 한현민 on 2021-06-30.
//

#include "MorseCode.h"

int main() {
    MorseCode app;

    int flagException = KeepException; // 예외 처리를 위한 플래그 변수

    while (flagException) {
        flagException = app.controller();

        // 예외가 발생하면 오류 메시지를 출력하고 다시 NotException으로 플래그를 변경
        if (flagException == TypeException || flagException == IntegerException) {
            std::cout << std::endl << "잘못된 선택지를 입력하였습니다." << std::endl;
            std::cout << "다시 시도하세요." << std::endl << std::endl;
            flagException = KeepException;
        }

        // 예외 없이 프로그램을 종료하면 그에 해당하는 메시지를 출력하고 반복문을 탈출
        else if (flagException == ExitException) {
            std::cout << "프로그램을 종료합니다." << std::endl;
            flagException = ExitException;
        }

        else {
            std::cout << std::endl;
        }
    }

    return 0;
}