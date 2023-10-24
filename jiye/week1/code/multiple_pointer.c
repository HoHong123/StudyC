#include <stdio.h>

void multiple_pointer_handle(int ****nbr);

int main(){
    int a=1;
    int *pa = &a;
    int **ppa = &pa;
    int ***pppa = &ppa;

    multiple_pointer_handle(&pppa);
    printf("%d", a);

}

void multiple_pointer_handle(int ****nbr){
    ****nbr = 10;

}
