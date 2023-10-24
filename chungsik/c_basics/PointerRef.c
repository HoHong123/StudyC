/*
다음 기능을 하는 함수를 만드시오
주소가 매개변수로 들어온 두개의 정수의 값을 바꾸는 기능
프로토타입 void fn_swap(int *a, int *b)*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void fn_swap(int *a, int *b);

int main()
{
    int n, m;
    write(1, "a입력 :", strlen("a입력 :"));
    scanf("%d", &n);

    write(1, "b입력 :", strlen("b입력 :"));
    scanf("%d", &m);

    fn_swap(&n, &m);

    char output[10];
    snprintf(output, sizeof(output), "a = %d\n", n); // (저장될 버퍼포인터에 , 받은 문자열 길이, 받을 형식 지정자 포인터 문자열, 받을 값)
    write(1, output, strlen(output)); // 저장 된 포인터 버퍼에 있는 것을 출력

    snprintf(output, sizeof(output), "b = %d\n", m);
    write(1, output, strlen(output));
    
    return 0;
}

void fn_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}