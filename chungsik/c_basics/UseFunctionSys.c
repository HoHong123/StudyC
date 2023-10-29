/*배열을 매개변수로 받으면 오름차순으로 정렬하는 기능
프로토타입 void fn_sort(int *arr)
(is_negative.c, fn_swap.c, fn_sort.c)*/


#include <stdio.h>
#include <unistd.h>
#include <string.h>

void fn_sort(int *arr[], int n);
void fn_sorted(int *arr[], int n);

int main()
{
    int n; //입력될 값
    write(1, "입력 : ", strlen("입력 : "));
    scanf("%d", &n);


    int arr[n];
    int *ptrArr[n];

    char BUFFER[30];
    snprintf(BUFFER, sizeof(BUFFER), "%d개의 정수 입력 : ", n);
    write(1, BUFFER, strlen(BUFFER));
    
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        ptrArr[i] = &arr[i]; //포인터 배열 각 원소에 주소 저장
    }
    
    //오름차순
    fn_sort(ptrArr, n);

    write(1, "오름차순 정렬 : ", strlen("오름차순 정렬 : "));
    for(int i = 0; i < n; i++) {
        snprintf(BUFFER, sizeof(BUFFER), "%d", *ptrArr[i]);
        write(1, BUFFER, sizeof(BUFFER));
    }
    write(1, "\n", 1);

    fn_sorted(ptrArr, n);

    write(1, "내림차순 정렬 : ", strlen("내림차순 정렬 : "));
    for(int i = 0; i < n; i++) {
        snprintf(BUFFER, sizeof(BUFFER), "%d", *ptrArr[i]);
        write(1, BUFFER, sizeof(BUFFER));
    }
    write(1, "\n", 1);

    return 0;
}

//올림
void fn_sort(int *arr[], int n)
{
    int *temp;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(*arr[j] > *arr[j + 1]) 
            {
                //TwoPointer
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

}

//내림
void fn_sorted(int *arr[], int n)
{
    int *temp;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(*arr[j] < *arr[j + 1])  // 부등호 
            {
                //TwoPointer
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

}