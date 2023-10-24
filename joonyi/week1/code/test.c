#include <stdio.h>
#include <unistd.h>

int main()
{
    int i;
    int a[5] = {5, 3, 1, 2, 4};
    int *ptr = a;

    printf("a의 주소 &a[0] = %p, a = %p \n", &a[0], a);
    printf("a의 값 : %d\n", *a);
    for (i = 0; i < 5; i++)
    {
        printf("\t 주소 %p  a[%d] : %d, *(a+%d) : %d\n", (a+i), i, a[i], i, *(a+i));
    }
    printf("\n");

    printf("ptr이 가리키는 주소 : %p\n", ptr);
    for (i = 0; i < 5; i++)
    {
        printf("\t 주소 %p  p[%d] : %d, *(p+%d) : %d\n", (ptr+i), i, ptr[i], i, *(ptr+i));
    }

    return 0;
}