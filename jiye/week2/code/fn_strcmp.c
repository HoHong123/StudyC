#include <stdio.h>
#include <ctype.h>
#include <string.h>

//string1과 string2를 비교하는 함수.
//string1 == string2 인 경우에는 0을 반환
//string1 < string2 인 경우에는 음수 반환
//string1 > string2 인 경우에는 양수 반환
int fn_strcmp(const char *string1, const char *string2);


int main(){
    char str1[] = "HelloWorld!"; //W=87
    char str2[] = "HelloAscii!"; //A=65
    char str3[] = "Hello";    //'\0'=0
    char str4[] = "HelloWorld!";

    printf("fn_strcmp(str1, str2)의 결과 : %d\n", fn_strcmp(str1, str2));
    printf("fn_strcmp(str2, str3)의 결과 : %d\n", fn_strcmp(str2, str3));
    printf("fn_strcmp(str3, str1)의 결과 : %d\n", fn_strcmp(str3, str1));
    printf("fn_strcmp(str1, str4)의 결과 : %d\n", fn_strcmp(str1, str4));

}



int fn_strcmp(const char *string1, const char *string2){
    for (const char *ptr1 = string1, *ptr2=string2; *ptr1!='\0' || *ptr2!='\0'; ptr1++, ptr2++){
        //string1과 string2의 문자의 아스키코드 값을 비교해 string1이 작으면 -1리턴, string1이 크면 1리턴
        //문자열 둘 중 하나가 널을 만나면 곧바로 종료가 아닌 아래의 조건문을 수행한 후에 함수 종료됨
        if(__toascii(*ptr1) == __toascii(*ptr2)) continue;
        else if(__toascii(*ptr1) < __toascii(*ptr2)) return -1;
        else if(__toascii(*ptr1) > __toascii(*ptr2)) return 1;

    }
    //문자열이 전부 같아 for문을 빠져나오면 0리턴
    return 0;

}
