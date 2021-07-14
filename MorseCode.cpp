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

MorseCode::MorseCode() {
    // init
    std::string alphabetList[WORD_LENGTH] = {
            ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
            "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
            "..-", "...-", ".--", "-..-", "-.--", "--.."
    };

    std::string digitList[DIGIT_LENGTH] = {
            "-----", ".----", "..---", "...--", "....-",
            ".....", "-....", "--...", "----..", "----."
    };

    std::string miscList[MISC_LENGTH] = {
            "-..-.", "..--..", "--..--", ".-.-.-", ".-.-.", "-...-"
    };

    // 위에서 정의된 값들을 클래스의 속성들에 모두 저장하여 초기화한다.
    for (int i = 0; i < WORD_LENGTH; i++) {
        *(this->alphabet + i) = alphabetList[i];
    }

    for (int i = 0; i < DIGIT_LENGTH; i++) {
        *(this->digit + i) = digitList[i];
    }

    for (int i = 0; i < MISC_LENGTH; i++) {
        *(this->misc + i) = miscList[i];
    }
}

void MorseCode::printSelection() {
    std::cout << "다음을 선택하세요" << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "1. 영어를 모스 부호로 변환하기" << std::endl;
    std::cout << "2. 모스 부호를 영어로 변환하기" << std::endl;
    std::cout << "3. 둘 다 하기" << std::endl;
    std::cout << "4. 종료하기" << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "선택 : ";
    return;
}

int MorseCode::getDecision() {
    std::string receiver;
    int decision;

    std::cin >> receiver;
    std::cin.ignore(1000, '\n');

    // 입력받은 문자열의 길이가 1보다 긴 경우 예외 발생
    if (receiver.length() > 1)
        return TypeError;

    // 문자열의 첫째 자리가 숫자가 아니면 예외 발생
    if (!isdigit(receiver[0]))
        return TypeError;

        // 문자열의 첫째 자리가 숫자이므로 int 형 변환 후 decision에 저장
    else {
        decision = (int)(receiver[0] - '0');

        // decision이 1에서 4 사이가 아니면 예외 발생
        if (decision < 1 || decision > 4)
            return IntegerError;
    }

    return decision;
}

int MorseCode::controller() {
    int decision = 0;
    std::string myText, myMorse;

    myText = "";
    myMorse = ""; // 초기화

    printSelection();

    decision = getDecision();

    // 정수가 아닌 값을 입력한 경우, false 값 반환
    if (decision == TypeError) return TypeError;

    // 정수값이 1에서 4를 제외한 값이 입력된 경우, false 값 반환
    if (decision == IntegerError) return IntegerError;

    // decision이 4인 경우일 때 함수 종료
    if (decision == 4) return NotException;

    switch (decision) {
        case 1:
            std::cout << "아래에 영문 텍스트를 입력하세요. 모스 부호로 바꿉니다." << std::endl;
            std::getline(std::cin, myText);
            //std::cin.ignore(1000, '\n');

            text2Morse(myText, myMorse);
            std::cout << myMorse << std::endl;
            break;

        case 2:
            std::cout << "아래에 모스 부호를 입력하세요. 영문 텍스트로 바꿉니다." << std::endl;

            MorseCode::morse2Text(myMorse, myText);
            std::cout << myText << std::endl;
            break;

        case 3:
            std::cout << "아래에 영문 텍스트를 입력하세요. 모스 부호로 바꿉니다." << std::endl;
            std::getline(std::cin, myText);

            text2Morse(myText, myMorse);
            std::cout << myMorse << std::endl;

            std::cout << std::endl << "모스 부호를 다시 영문 텍스트로 바꿉니다." << std::endl;

            morse2Text(myMorse, myText);
            std::cout << myText << std::endl;
            break;
    }

    return NotException;
}

void MorseCode::text2Morse(std::string text, std::string &morse) {
    // 변수 및 배열 초기화
    char item;

    for (int i = 0; i < text.length(); i++) {
        // 현재 인덱스의 문자가 알파벳일 경우, 알파벳에 대응하는 모스 부호 리스트에서 탐색
        if (isalpha(text[i])) {
            text[i] = tolower(text[i]);
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
                            // 단, 공백을 포함한 모든 문자를 추가 시 공백 1칸을 추가하기에, 여기서는 2칸만 추가함
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
                case SLASH:
                    morse += this->misc[0];
                    break;
                case QUESTION:
                    morse += this->misc[1];
                    break;
                case COMMA:
                    morse += this->misc[2];
                    break;
                case PERIOD:
                    morse += this->misc[3];
                    break;
                case PLUS:
                    morse += this->misc[4];
                    break;
                case EQUAL:
                    morse += this->misc[5];
                    break;
            }
        }

        morse += " ";
    }
}

bool MorseCode::morse2Text(std::string morse, std::string& text) {
    // 변수 선언
    int count = 0;  // 공백 개수를 나타냄
    std::string buffer = ""; // 공백 앞까지 공백이 아닌 문자들을 저장

    // morse의 앞부분부터 순차적으로 검사
    for (int i = 0; i < morse.length(); i++) {

        // 공백 유무 확인
        if (!isspace(morse[i])) {
            buffer += morse[i]; // 공백이 없으면 buffer 문자열에 현재 위치의 문자를 추가
            continue;
        }

        else {
            // 공백을 발견하면 count 1 증가
            count++;

            // 공백이 연속으로 3개 있으면 텍스트에서 공백을 의미하므로 공백을 쓰고 count 초기화
            if (count == 3) {
                text += " ";
                count = 0;
                continue;
            }
        }

        // 위의 조건문을 통과하면 문자 추가를 의미
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
            if (buffer == misc[j]) {
                text += miscLetter[j];
                break;
            }
        }

        // 텍스트에 문자를 추가했다면 count 및 buffer 초기화
        count = 0;
        buffer = "";
    }

    // 변환에 성공하면 true 반환
    return true;
}