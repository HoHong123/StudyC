#include <stdio.h>
#include <string.h>
//add, search, exit 기능이 있는 전화번호부
//전화번호부의 사이즈는 8
//add 함수 : 
//search 함수 : index를 매개변수로 받아 해당 index에 저장된 값을 반환한다 

typedef struct tel_dictionary{
    int num;

};

int main(){
    
    for(char input[7] ; ; ){
        printf("원하는 기능을 입력하세요. \n");
        printf("제공되는 기능 : add, search\n");
        printf("만약 종료를 원하면 exit을 입력하세요 : ");
        fgets(input, sizeof(input), stdin);

        


        if(strcmp(input,"exit")) {
            printf("종료합니다\n");
            return 0;
        }
    }

}