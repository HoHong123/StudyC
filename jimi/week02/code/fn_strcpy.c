//string.h의 strcpy과똑같이 동작하는 fn_strcpy를 만드시오.

//문자열 복사하는 함수 만들기
#include <stdio.h>

char *fn_strcpy(char *dest, const char *src);
int main(void)
{
    char source[100] = "Hello World";
    char dest[100];

    printf("원본 문자열:%s\n", source);
    fn_strcpy(dest, source);
    printf("복사 결과 문자열: %s\n", dest);
    return 0;
}

char *fn_strcpy(char *dest, const char *src)
{
    char *origin;
    for (origin = dest; *dest = *src; dest++, src++);//복사한 문자가 참이면 반복
    return origin;
}

