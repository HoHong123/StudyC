#include <stdio.h>

//문자열 destination 끝에 문자열 source를 추가하는 함수
char* fn_strcat(char* dest, const char* src);

int main(){
    char dest[30] = "Hello";
    char *src = "world";

    printf("%s\n", fn_strcat(dest, src));

}

char* fn_strcat(char* dest, const char* src){
    char* return_ptr = dest;    //반환용 포인터. dest배열의 첫번째 인덱스 주소를 저장하고 있다. 
    
    for(; *dest!='\0'; dest++);  //dest에 저장된 문자열의 끝을 만날때까지 포인터 이동

    for(; *src!='\0'; dest++, src++){   //dest 문자열의 끝부터 src문자열을 붙여넣음
        *dest = *src;
    }
    *dest = '\0'; //문자열을 다 입력하여 for문을 빠져나왔으므로 널문자 삽입

    return return_ptr;
}