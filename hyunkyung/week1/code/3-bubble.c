#include <stdio.h>
#define MAX_SIZE 5

//버블 정렬
void fn_sort(int arr[], int n)
{
	int i, j, temp;

	for(i=n-1;i>0;i--){
	//0 ~ (i-1)까지 반복
	    for(j=0;j<i;j++){
	     //j번째와 j+1번째의 요소가 크기 순이 아니면 교환
	       if(arr[j]<arr[j+1]){
		temp = arr[j];
		arr[j] = arr[j+1];
		arr[j+1] = temp;
		}
	    }
	}
}

void main(){
	int i;
	int n = MAX_SIZE;
	int arr[n] = {7, 4, 5, 1, 3};

	//버블 정렬 수행
	fn_sort(arr, n);

	//정렬 결과 출력
	for(i=0; i<n; arr[i]){
		printf("%d\n", arr[i]);
	}

    return 0;
}