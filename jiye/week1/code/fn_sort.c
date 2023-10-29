#include <stdio.h>

//배열을 매개변수로 받으면 오름차순으로 정렬하는 기능, 정렬은 버블정렬로
void fn_sort(int *arr);

int main(){
    int arr[] = {5,2,1,4,3};
    
    fn_sort(arr);

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

void fn_sort(int *arr){
    int temp = 0;

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4 - i; j++)
        {
            if (*(arr + j) > *(arr + j +1))
            {
                temp = *(arr + j);
                *(arr + j) = *(arr + j +1);
                *(arr + j +1) = temp;
            }
        }
    }
}

