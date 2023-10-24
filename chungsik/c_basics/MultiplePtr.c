/*void multiple_pointer_handle(int ****nbr);
이 함수를 들어갔다 나오면 a 값이 10으로 바뀐다.*/




#include <stdio.h>
#include <unistd.h>

void multiple_pointer(int ****nbr);


int main()
{
    int a = 0;
    int *b = &a;
    int **c = &b;
    int ***d = &c;

    write(1, "입력 : ", sizeof(5));
    scanf("%d", &a);

    multiple_pointer(&d);
    a = ***d;

    printf("%d\n", a);
    return 0;
}

void multiple_pointer(int ****nbr)
{
    ****nbr = 10;
}