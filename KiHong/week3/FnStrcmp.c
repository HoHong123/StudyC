#include "FnStrcmp.h"

// <summary> compare two char array
// <parameter=*string1> first string
// <parameter=*string2> second string
int fn_ustrcmp(const unsigned char *string1, const unsigned char *string2) {
    // Force to convert char* to unsigned char*
    // This is a important task since input value can be a negative char value.
    // Negative char can cause serious issues, such as stackoverflow. Which can lead to security issues.

    while (*string1 && *string2 && *string1 == *string2) {
        string1++;
        string2++;
    }
    // Calculate in ASKII code
    return *string1 - *string2;
}

// <summary> compare two char array
// <parameter=*string1> first string
// <parameter=*string2> second string
int fn_strcmp(const char *string1, const char *string2) {
    // Force to convert char* to unsigned char*
    // This is a important task since input value can be a negative char value.
    // Negative char can cause serious issues, such as stackoverflow. Which can lead to security issues.
    unsigned char *s1 = (unsigned char*)string1;
    unsigned char *s2 = (unsigned char*)string2;

    while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }
    // Calculate in ASKII code
    return *s1 - *s2;
}

// int main(void) {
//     char *string1 = "compare";
//     char *string2 = "compares";

//     int result = fn_strcmp(string1, string2);
//     printf("%d\n", result);

//     if (result == 0) {
//         printf("Equal\n");
//     } else if (result < 0) {
//         printf("The second string has a larger ASKII code value.\n");
//     } else {
//         printf("The first string has a larger ASKII code value.\n");
//     }
    
//     return 0;
// }
