#include <stdio.h>

//문자열 src를 dest로 복사하는 함수
char* fn_strcpy(char* dest, char* src);

int main(){
    char s1[] = "hello world!!";
    char s2[20];

    fn_strcpy(s2, s1);

    printf("s1: ");
    for(char* ptr_s1 = s1; *ptr_s1!='\0' ; ptr_s1++){
        printf("%c", *ptr_s1);
    }
    printf("\n");

    //원본 주솟값 출력해보기
    for(char* ptr_s1 = s1; *ptr_s1!='\0' ; ptr_s1++){
        printf("%p ", ptr_s1);
    }
    printf("\n");

    printf("s2: ");
    for(char* ptr_s2 = s2; *ptr_s2 !='\0' ; ptr_s2++){
        printf("%c", *ptr_s2);
    }
    printf("\n");

    //복사본 주솟값 출력해보기
    for(char* ptr_s2 = s2; *ptr_s2!='\0' ; ptr_s2++){
        printf("%p ", ptr_s2);
    }
    printf("\n");

}

char* fn_strcpy(char* dest, char* src){
    for(int i=0; *(src+i) !='\0' ; i++){
        *(dest+i) = *(src+i);
    }
    
    return dest; 
}
