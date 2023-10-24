#include <stdio.h>
#define COUNT 20

void fn_sort(int *arr){

    for(int i=0; i<COUNT-1; i++){
        for(int j=0; j<COUNT-1-i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int data[COUNT] = { 5 , 15 , 7 , 20 , 1 ,
            4 , 10 , 2 , 8  , 11,
            9 ,  6 , 13, 18 ,  3,
            16, 12 , 14, 17 , 19 };

    printf("랜덤한 숫자 배열 : ");
    for(int i=0; i<COUNT; i++ ){
        printf("%d ,", data[i]);
    }
    printf("\n");

    fn_sort(data);

        printf("정렬된 숫자 배열 : ");
    for(int i=0; i<COUNT; i++ ){
        printf("%d ,", data[i]);
    }
}