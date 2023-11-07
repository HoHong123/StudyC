/*
malloc 사용해보는 과제입니다.
strdup을 만들어라
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *fn_strup(char* string);

int main(void) {
    char *test1 = "Copy this";
    char *test2;

   if ((test2 = fn_strup(test1)) != NULL)
      printf("The new string is: %s\n", test2);

    return 0;
}

char *fn_strup(char* string) {
    char* result = (char*)malloc(strlen(string) + 1);
    return strcpy(result, string);
}