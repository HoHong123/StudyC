#include <stdio.h>

// strcmp와 유사한 동작을 하는 사용자 정의 함수
int fn_strcmp(const char *str1, const char *str2) {
    while (*str1 == *str2) {
        if (*str1 == '\0') {
            return 0; // 두 문자열이 동일하면 0을 반환하고 함수 종료
        }
        str1++;  // 첫 번째 문자열 포인터를 다음 문자로 이동
        str2++;  // 두 번째 문자열 포인터를 다음 문자로 이동
    }
    return *str1 - *str2; // 문자열이 다를 경우, 해당 문자의 아스키 코드 차이를 반환
}

int main() {
    // 비교할 두 문자열을 정의합니다.
    const char *string1 = "Hello, World!";
    const char *string2 = "Hello, OpenAI!";
    
    // fn_strcmp 함수를 사용하여 두 문자열을 비교하고 결과를 저장합니다.
    int result = fn_strcmp(string1, string2);
    
    if (result == 0) {
        printf("두 문자열은 동일합니다.\n");
    } else if (result < 0) {
        printf("첫 번째 문자열이 두 번째 문자열보다 작습니다.\n");
    } else {
        printf("첫 번째 문자열이 두 번째 문자열보다 큽니다.\n");
    }
    
    return 0;
}