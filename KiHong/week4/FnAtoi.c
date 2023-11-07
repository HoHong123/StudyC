/*
오늘의 과제입니다
atoi와 똑같이 동작하는 fn_atoi함수를 만드시오
3. (bonus) 인수를 받으면 정렬하여 출력하는 함수를 만드시오 (편집됨) 
*/

#include <stdio.h>
#include <string.h>

#define LIMIT 10
#define START_OF_SPACE_ASCII 9
#define END_OF_SPACE_ASCII 13
#define SPACE_ASCII 32

int fn_atoi(char* input);

int main(void) {
    while (1) {
        char letters[11];
        
        printf("Enter integer (Max 10) : ");
        
        if (scanf("%s", letters) == EOF || strcmp(letters, "exit") == 0) break;
        
        if (strlen(letters) > LIMIT) {
            printf("Out of max digit.\n");
            continue;
        }
        
        printf("Output : %d\n", fn_atoi(letters));
    }
    
    return 0;
}

int fn_atoi(char* input) {
    int iterator = 0;
    int result = 0;
    int positive = 1;
    
    while ((input[iterator] >= START_OF_SPACE_ASCII && input[iterator] <= END_OF_SPACE_ASCII) ||
     input[iterator] == SPACE_ASCII ||
     input[iterator] == '+') {
        iterator++;
    }
    
    if (input[iterator] == '-') {
        iterator++;
        positive = -1;
    }
    
    while (input[iterator] >= '0' && input[iterator] <= '9') {
        result *= 10;
        result += (input[iterator] - '0');
        iterator++;
    }

    result *= -positive;
    
    return result;
}