//주소가 매개변수로 들어온 두개의 정수의 값을 바꾸는 기능
//프로토타입 void fn_swap(int *a, int *b)

#include <stdio.h>

int main(){
int num1, num2; //num1=7, num2=36
    printf("정수 두 개를 입력하세요: \n");
    scanf("%d %d", &num1, &num2);
    printf("\n");

    printf("입력한 값 : %d, %d\n", num1, num2); 
    printf("포인터 주소 : %p, %p\n", &num1, &num2);
    printf("\n");
    
    fn_swap(&num1, &num2);
    printf("바뀐 값 : %d, %d\n", num1, num2);
    printf("바뀐 후 포인터 주소 : %p, %p", &num1, &num2);
}

void fn_swap(int *a, int *b){ //*a는 num1의 주소값, *b는 num2의 주소값
    int temp;
    temp = *a; //temp=7
    *a = *b; //*a=36
    *b = temp; //*b=7
}