#include <stdio.h>
#include <ctype.h>

char *strcapitalize(char *str);

int main(){
    char arr[]="salut, comment tu vas ? 42mots quaRANTe-deux; cinquante+et+un";

    printf("%s\n", strcapitalize(arr));
}

char *strcapitalize(char *str){
    if(isalpha(*str)) *str=toupper(*str);    //첫번째 글자가 문자이면 대문자로

    for(char* ptr=str+1; *ptr != '\0'; ptr++){      //모든 알파벳을 소문자로 바꿀 예정이라
                                                    //이미 대문자인 첫글자를 소문자로 바꾸면 안되므로 다음 인덱스부터 반복문 시작
        if(isalpha(*ptr)) {
            *ptr = tolower(*ptr);     //모든 알파벳을 소문자로 바꿈

            if(!isalnum(*(ptr-1))){    //현재 인덱스의 값이 알파벳인데, 직전 인덱스의 값이 (단어의 기준으로 삼은)알파벳이나 숫자가 아닌 것이라면
            *ptr = toupper(*ptr);       //단어의 첫글자라는 뜻이므로 대문자로 바꿔준다
            }
        }
        
    }
    return str;
}