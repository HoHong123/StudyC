#include <stdio.h>
#include <string.h>
    char phone_number[9][50];
    char phone_name[9][50];
    char phone_other[9][50];

    int registration;
    
void add(){
    printf("::: 이름을 입력해 주세요!! ::: \n");
    scanf("%s", phone_name[registration]);
    printf("::: 번호를 입력해 주세요!! ::: \n");
    scanf("%s", phone_number[registration]);
    printf("::: 기타 사항을 입력해 주세요!! ::: \n");
    scanf("%s", phone_other[registration]);
    registration++;
}

void search(){
    printf("이름 :::: %s\n", phone_name[0]);
    printf("번호 :::: %s\n", phone_number[0]);
    printf("기타 :::: %s\n", phone_other[0]);
    int i;
    printf("::: 인덱스 번호를 입력해 주세요!! ::: \n");
    scanf("%d", &i);
    printf("이름 :::: %s\n", phone_name[i]);
    printf("번호 :::: %s\n", phone_number[i]);
    printf("기타 :::: %s\n", phone_other[i]);
}

void main(){

    while (1)
    {
        printf("***********************************************\n");
        printf("*                                              \n");
        printf("*   1. add 입력으로 전화번호 등록                    \n");
        printf("*   2. search 인덱스 번호로 전화번호 찾기             \n");
        printf("*   3. exit 기능으로 종료                          \n");
        printf("*                                               \n");
        printf("***********************************************\n");
        char order[10]; 
        scanf("%s", order);
        if(strcmp(order, "add") == 0){
            add();
        }else if (strcmp(order, "search")==0)
        {
            search();
        }else if (strcmp(order, "exit")==0)
        {
                      printf("종료합니다. \n");
                      break;
        }else{
            printf("----------!!!!올바른 명령을 입력해주세요!!!!--------------\n");
        }
    }
}