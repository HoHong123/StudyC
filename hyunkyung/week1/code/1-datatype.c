#include <stdio.h>
#include <unistd.h>
void is_negative(int n);

int main() {
    int p;

    printf("Enter an integer: ");
    scanf("%d", &p);

    if (p > 0) {
        printf("%d is positive.\n", p);
    } else if (p < 0) {
        is_negative(p);
    } else {
        printf("0 is neither positive nor negative.\n");
    }

    return 0;
}

void is_negative(int n) {
    printf("%d is negative.\n", n);
}