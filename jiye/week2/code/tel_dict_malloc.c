#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//add, search, exit 기능이 있는 전화번호부
//전화번호부의 사이즈는 8
//add 함수 : "이름", "전화번호", "기타" 정보를 입력받음
//search 함수 : index를 매개변수로 받아 해당 index에 저장된 값을 반환한다 

#define TEL_SIZE 8
#define NAME_SIZE 10
#define NUM_SIZE 13
#define OTHER_SIZE 30

typedef struct  {
    char name[NAME_SIZE];
    char num[NUM_SIZE];
    char other[OTHER_SIZE];
}tel_info;

//구조체의 배열을 만들어 사용하려 했으나 안됨..
//typedef tel_info tel_dict[TEL_SIZE];   //자료형이 tel_info이고 크기가 TEL_SIZE인 배열 선언, 배열 이름은 tel_dict


void add(tel_info* dict, int index);
void search(tel_info* dict, int index);
int search_index(tel_info* dict, int dictindex, int flag);
void delete(tel_info* dict, int index);


void print(tel_info *dict, int dictindex);

int main(){

    tel_info* dictionary;
    dictionary = (tel_info *)malloc(sizeof(tel_info) * TEL_SIZE);
    int dictindex = 0;
    
    for(char input[8] ; ; ){

        printf("\n원하는 기능을 입력하세요. \n");
        printf("제공되는 기능 : add, search, delete, print\n");
        printf("만약 종료를 원하면 exit을 입력하세요 : ");
        
        fgets(input, sizeof(input), stdin); // fgets() 함수는 개행 문자(\n)가 나올때까지 
                    //또는 읽은 문자 수가 n-1과 같을 때까지의 문자열을 읽고
                // 결과를 string에 저장하고 스트링 끝에 널(null) 문자(\0)를 추가한다. 
                // 이때 \n까지 문자열에 포함시켜 저장한다. 

        for (char* ptr = input; *ptr!='\0'; ptr++){
            if(*(ptr+1) == '\0')    //널문자 직전에 개행문자가 들어 있을 것이므로
                *ptr = '\0';  //개행문자 제거
        }
        

        if(strncmp(input,"add", 3)==0){
            add(dictionary, dictindex++);

        }

        if(strncmp(input, "search", 6)==0){
            int i = search_index(dictionary, dictindex, 0);
            search(dictionary, i);
        }

        if(strcmp(input, "delete")==0){
            int i = search_index(dictionary, dictindex, 1);
            delete(dictionary, i);
        }

        if(strcmp(input,"print")==0){
            print(dictionary, dictindex);
        }

        if(strncmp(input,"exit", 4)==0) {
            printf("종료합니다\n");
            break;    
        }

        memset(input, '\0', sizeof(input));
    }
    
    free(dictionary);

}

void add(tel_info* dict, int index){
    if (index>=8) {
        printf("전화번호부가 다 찼습니다\n");
        return;
    }


    printf("\n이름을 입력하세요: ");
    fgets((dict+index)->name, sizeof(dict->name), stdin);
    for (char* ptr = (dict+index)->name; *ptr!='\0'; ptr++){
        if(*ptr == '\n') {  //개행문자를 만나면 널문자로 바꿔주고 반복종료
            *ptr='\0';
            break;
        }
    }

    printf("전화번호를 입력하세요: ");
    fgets((dict+index)->num, sizeof(dict->num), stdin);
    for (char* ptr = (dict+index)->num; *ptr!='\0'; ptr++){
        if(*ptr == '\n') {  //개행문자를 만나면 널문자로 바꿔주고 반복종료
            *ptr='\0';
            break;
        }
    }

    printf("기타 정보를 입력하세요: ");
    fgets((dict+index)->other, sizeof(dict->other), stdin);
    for (char* ptr = (dict+index)->other; *ptr!='\0'; ptr++){
        if(*ptr == '\n') {  //개행문자를 만나면 널문자로 바꿔주고 반복종료
            *ptr='\0';
            break;
        }
    }

    printf("\n");

}

void search(tel_info* dict, int index){
    if(index==-1) {
        printf("\n해당되는 정보가 없습니다. \n");
        return;
    }
    printf("\n<검색된 정보>\n");
    printf("이름: %s\n", (dict+index)->name);
    printf("전화번호: %s\n", (dict+index)->num);
    printf("기타 정보: %s\n", (dict+index)->other);

}

int search_index(tel_info* dict, int dictindex, int flag){
    char string[10];

    if(flag == 0) printf("\n검색할 이름 : ");
    else printf("\n삭제할 이름 : ");

    fgets(string, sizeof(string), stdin);
    for (char* ptr = string; *ptr!='\0'; ptr++){
        if(*(ptr+1) == '\0')
            *ptr = '\0';  //입력받은 문자열의 개행문자 제거
    }
    
    for(int index = 0; index < dictindex; index++){     //현재 전화번호부에 저장된 인덱스까지만 검사하기 위해 
                                                        //add함수에서 사용한 dictindex값 받아옴
        if(strcmp(string, (dict+index)->name) == 0){//입력받은 이름과 dict의 이름에 저장된 이름이 같다면
            return index;   //인덱스를 반환한다. 
        }
    }

    //만약 dict 안에 해당하는 이름이 없다면 -1 리턴
    return -1;
}

void delete(tel_info* dict, int index){
    if(index==-1) {
        printf("\n해당되는 정보가 없습니다. \n");
        return;
    }

    memset((dict+index)->name, '\0', sizeof(dict->name));
    memset((dict+index)->num, '\0', sizeof(dict->num));
    memset((dict+index)->other, '\0', sizeof(dict->other));

    printf("삭제되었습니다. \n");
}



void print(tel_info *dict, int dictindex){

    for(int i = 0; i<dictindex; i++){
        if(*((dict+i)->name) != '\0'){
            printf("\n[%d]번\n", i+1);
            printf("이름: %s\n", (dict+i)->name);
            printf("전화번호: %s\n", (dict+i)->num);
            printf("기타 정보: %s\n", (dict+i)->other);
        }
        else{
            printf("\n[%d]번은 비어 있습니다. \n", i+1);
        }
    }

}

