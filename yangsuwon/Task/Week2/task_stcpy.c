#include <stdio.h>
#include <string.h>

void fn_strcpy(char*s1, char*s2){
    while(*s2){
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
}

void main(){
    char sen1[30] = "hello";
    char sen2[30] = "word";
    fn_strcpy(sen1,sen2);

    printf("%s\n", sen1);
}
