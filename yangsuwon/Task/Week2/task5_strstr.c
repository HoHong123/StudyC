#include <stdio.h>
#include <string.h>
/**
 * strstr의 경우 문자열 2개를 인자로 받아 첫번째 문자열에서 두번째 문자열이 처음으로 나타나는
 * 위치를 가르키는 포인터를 반환합니다. 만약 첫번째 문자열에 두번째 문자열이 존자하지 않다면 
 * NULL 포인터를 반환 합니다. 
 * 
 * 구현을 해볼려고 노력을 해봤는데 방법이 떠오르지 않아서 chatGPT에 도움을 받아 구현했습니다.
*/


// my_strstr 함수: 주어진 문자열에서 부분 문자열을 찾는 함수입니다.
char *my_strstr(const char *haystack, const char *needle) {
    if (!*needle) { // 만약 needle이 빈 문자열이라면 haystack을 반환합니다.
        return (char *)haystack;
    }

    /**
     * haystack의 문자열을 반복돌리면서 
     * 내부에서 두개의 문자열을 비교합니다. 
     * 비교하다가  needle이 끝나는 위치에 도달하게 되면 외부에있는 haystack의 needle이
     * 일치하는 시작부분을 알게되고 반환합니다. 
    */
    while (*haystack) { 
        const char *h = haystack;
        const char *n = needle;
        while (*h && *n && *h == *n) {
            h++;
            n++;
        }
        if (!*n) { // 만약 needle의 끝에 도달하면 일치하는 위치를 찾았습니다.
            return (char *)haystack; // const 이기때문에 변환가능한 char *로 타입 캐스팅
        }
        haystack++;
    }
    
    return NULL; // haystack에서 needle을 찾지 못했다면 NULL을 반환합니다.
}

int main() {
const char *haystack = "Hello, World!";
const char *needle = "World";
char *result = strstr(haystack, needle);
printf("%s \n", result);

    return 0;
}