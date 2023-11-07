#include <stdio.h>

// 사용자 정의 함수 fn_strcat
// 이 함수는 문자열 destination 끝에 문자열 source를 연결합니다.
// destination은 충분한 공간이 확보되어 있어야 합니다.
char* fn_strcat(char* destination, const char* source) {
    char* dest = destination;  // destination 문자열의 시작 주소를 가리키는 포인터

    // destination 문자열 끝을 찾기 위해 반복문 실행
    while (*dest != '\0') {
        dest++;
    }

    // source 문자열의 내용을 destination 뒤에 복사
    while (*source != '\0') {
        *dest = *source;  // 현재 source 문자를 destination에 복사
        dest++;           // destination 포인터를 다음 위치로 이동
        source++;         // source 포인터를 다음 위치로 이동
    }

    *dest = '\0'; // destination 문자열의 끝에 널 문자('\0')를 추가하여 새로운 문자열 완성

    return destination;  // destination 문자열의 시작 주소를 반환
}

int main() {
    char str1[100] = "Hello, ";
    char str2[] = "world!";
    
    fn_strcat(str1, str2); // str1에 str2를 연결

    printf("Concatenated string: %s\n", str1);

    return 0;
}