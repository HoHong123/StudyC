#include <stdio.h>

void fn_swap(int *a, int *b){
     int temp = *a;
        *a = *b;
        *b = temp;
}

int main(){
    int a,b;
    scanf("%d %d",&a , &b );
    printf("a : %d\n", a);
    printf("b : %d\n", b);

    fn_swap(&a, &b);

    printf("변경된 a : %d\n", a);
    printf("변경된 b : %d\n", b);
    return 0;
}