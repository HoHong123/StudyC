//버블정렬 예제
#include <stdio.h>
void main() {
    int i, j;
    int temp;
    int arr[5] = {5, 2, 1, 4, 3};

    for(i=0; i<4; i++) {
        for(j=0; j<4-i; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for(i=0; i<5; i++) {
        printf("%d ", arr[i]);
    }
}
    // i=0, j=0, arr={2,5,1,4,3}
    // i=0, j=1, arr={2,1,5,4,3}
    // i=0, j=2, arr={2,1,4,5,3}
    // i=0, j=3, arr={2,1,4,3,5}
    // i=1, j=0, arr={1,2,4,3,5}
    // i=1, j=1, X
    // i=1, j=2, arr={1,2,3,4,5}

// 배열을 매개변수로 받으면 오름차순으로 정렬하는 기능만들기
// 프로토타입 void fn_sort(int *arr)