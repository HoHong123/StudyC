#include <stdio.h>

char *fn_strcat (char *string1, const char *string2) {
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

// int main(void) {
//     char string1[20] = "cat1";
//     char *string2 = "cat2 cat3";
//     char *string3 = fn_strcat(string1, string2);

//     printf("%s\n", string3);
    
//     return 0;
// }
