#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//add, search, exit 기능이 있는 전화번호부
//전화번호부의 사이즈는 8
//add 함수 : "이름", "전화번호", "기타" 정보를 입력받음
//search 함수 : index를 매개변수로 받아 해당 index에 저장된 값을 반환한다 

#define TEL_SIZE 8

typedef struct  {
    char name[10];
    char num[13];
    char other[30];
}tel_info;

typedef tel_info tel_dict[TEL_SIZE];   //자료형이 tel_info이고 크기가 TEL_SIZE인 배열 선언, 배열 이름은 tel_dict


void add(tel_dict* dict);
void search(tel_dict* dict);

int main(){
    tel_dict dictionary;
    
    //tel_info dict[8];

    for(char input[7] ; ; ){

        printf("원하는 기능을 입력하세요. \n");
        printf("제공되는 기능 : add, search\n");
        printf("만약 종료를 원하면 exit을 입력하세요 : ");
        
        fgets(input, sizeof(input), stdin);

        if(strncmp(input,"add", 3)==0){
            add(&dictionary);

        }

        if(strncmp(input, "search", 6)==0){
            search(&dictionary);
        }


        if(strncmp(input,"exit", 4)==0) {
            printf("종료합니다\n");
            return 0;
        }
    }

}

void add(tel_dict* dict){
    int i = 0;

    printf("이름을 입력하세요: ");
    fgets((*(dict+i))->name, sizeof((*dict)->name), stdin);

    printf("전화번호를 입력하세요: ");
    fgets((*(dict+i))->num, sizeof((*dict)->num), stdin);

    printf("기타 정보를 입력하세요: ");
    fgets((*(dict+i))->other, sizeof((*dict)->other), stdin);



}

void search(tel_dict* dict){
    int i = 0;

    printf("이름: %s\n", (*(dict+i))->name);
    printf("전화번호: %s\n", (*(dict+i))->num);
    printf("기타 정보: %s\n", (*(dict+i))->other);


}

