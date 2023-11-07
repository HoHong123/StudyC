/*
두 배열을 합치는 함수인 fn_strjoin을 만들어라
char *fn_strjoin(const char *s1, const  char *s2)
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *fn_strjoin(const char *s1, const  char *s2);

int main(void) {
    char *test1 = "Copy this";
    char *test2 = ", And this";
    char *test3;

   if ((test3 = fn_strjoin(test1, test2)) != NULL)
      printf("The new string is: %s\n", test3);

    return 0;
}

char *fn_strjoin(const char *s1, const  char *s2) {
    char* result = (char*)malloc(strlen(s1) + strlen(s2) + 1);

    strcat(result, s1);
    strcat(result, s2);

    return result;
}