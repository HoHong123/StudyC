#include <stdio.h>

/**
 * stcmp(string compare)함수는 길이가 같은 문자열 두개를 아스키코드 기준으로 비교해 같다면 0
 * 첫번째 인자의 문자열이 길다면 양수로 두문자 사이의 차이를, 
 * 두번째 인자의 문자열이 길다면 음수로을 두문자 사이의 차이를 리턴하는 함수 이다. 
 * 
 * 참고 문서: 
 * https://learn.microsoft.com/ko-kr/cpp/c-runtime-library/reference/strcmp-wcscmp-mbscmp?view=msvc-170
*/
int stcmp_fn(char *s1, char *s2){
    while (*s1 != '\n' || *s2 != '\n')
    {
        if(*s1 < *s2){
            return *s1 - *s2;
        }else if (*s1 > *s2)
        {
            return *s1 - *s2;
        }
        s1++;
        s2++;
    }
    return 0;
}

int main()
{
    char s1[10] = "aaz";
    char s2[10] = "aaf";

    int ret = stcmp_fn(s1, s2);    

    printf("%d\n", ret);         

    return 0;
}
