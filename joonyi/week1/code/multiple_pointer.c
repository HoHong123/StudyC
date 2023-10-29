#include <unistd.h>
#include <stdio.h>

/*
무슨 값이든 10이 되는 함수
*/
void multiple_pointer_handle(int ****nbr)
{
    ****nbr = 10;
}

int main()
{
    int a = 22123;
    int *ptr1 = &a;
    int **ptr2 = &ptr1;
    int ***ptr3 = &ptr2;
    int ****ptr4 = &ptr3;

    multiple_pointer_handle(ptr4);

    printf("%d\n", a);
}