#include <stdio.h>

// 사용자 정의 strcpy 함수 선언
void fn_strcpy(char* destination, const char* source);

int main() {
    char destination[80];// 복사된 문자열을 저장할 대상 문자열 배열
    const char* source = "Hello, World!";// 복사할 원본 문자열

// 사용자 정의 fn_strcpy 함수를 사용하여 문자열 복사
    fn_strcpy(destination, source);

// 복사된 문자열 출력    
    printf("Copied string: %s\n", destination);

    return 0;
}

// 사용자 정의 fn_strcpy 함수 정의
void fn_strcpy(char* destination, const char* source) {
    while (*source != '\0') {
        *destination = *source;// 원본에서 문자를 대상에 복사
        source++;
        destination++;
    }
    *destination = '\0'; // Null-terminate the destination string
// 대상 문자열을 올바른 C 문자열로 만들기 위해 널 종료 문자 추가
}