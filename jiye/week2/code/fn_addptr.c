#include <stdio.h>

//포인터를 매개변수로 받을때 매개변수로 받은 포인터를 바로 바꾸면 원본 포인터도 변경되는지 확인하기 위한 함수
//변경되지 않는다. 여전히 같은 주소를 가리킨다. 
void fn_addptr(int* ptr);

int main(){
    int a[] = {2,3,4};
    int* ptr = a;
    printf("a[0]의주소 : %p\n", &a[0]);
    printf("ptr가 가리키는 주소 : %p\n", ptr);

    fn_addptr(ptr);
    printf("\nfn_addptr을 실행한 후 ptr가 가리키는 주소 : %p\n", ptr);

}

void fn_addptr(int* ptr){
    printf("포인터가 배열을 잘 순회하는지 확인 :");
    for(int i=0; i<3; ptr++,i++){
        printf("a[%d] = %d ",i,*ptr);
    }
}