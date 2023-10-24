#include <stdio.h>
#include <ctype.h>

char *strcapitalize(char *str);

int main(){
    char arr[]="salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";

    printf("%s\n", strcapitalize(arr));
}

char *strcapitalize(char *str){
    if(isalpha(*str)) *str=toupper(*str);    //첫번째 글자가 문자이면 대문자로
    for(char* ptr=str; *ptr != '\0'; ptr++){
        while(!isalpha(*ptr)){
            ptr++;                               //만약 ptr에 담긴 값이 문자가 아니면 toupper를 하지 않고 다음 주소로 이동
            if(isalpha(*ptr)) *ptr=toupper(*ptr); //ptr를 증가시킨 직후 isalpha이면 대문자로 바꿈
        }           //*ptr이 isalpha가 되면 반복문 종료
    }
    return str;
}