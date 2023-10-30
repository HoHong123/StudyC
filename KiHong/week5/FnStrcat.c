#include <stdio.h>

char * strcat ( char * destination, const char * source );

int main(void) {
    char string[30];
    char string0[20] = "cat1";
    char string1[20] = { '\0', };
    char *string2 = "cat2 cat3";
    char *string3 = strcat(string0, string2);
    char *string4 = strcat(string1, string2);
    
    printf("1 : %s\n", string);
    printf("2 : %s\n", strcat(string, string2));
    printf("3 : %s\n", string);
    printf("4 : %s\n", string0);
    printf("5 : %s\n", string1);
    printf("6 : %s\n", string2);
    printf("7 : %s\n", string3);
    printf("8 : %s\n", string4);
    
    return 0;
}

char *strcat (char *string1, const char *string2) {
    int k = 0;
    while (*string1) {
        string1++;
        k++;
    }

    while (*string2) {
        *string1 = *string2;
        string1++;
        string2++;
        k++;
    }

    *string1 = '\0';
    string1 -= k;

    return string1;
}
