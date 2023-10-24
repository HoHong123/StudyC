/*다음 기능을 하는 함수를 만드시오
배열을 매개변수로 받으면 오름차순으로 정렬하는 기능
프로토타입 void fn_sort(int *arr)
힌트 : 버블정렬을 찾아보세요*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <io.h>


void fn_sort(int* arr, int count);
void fn_sortted(int* arr, int count);

char BUFFER[30];

int main()
{
	int n = 0; 
	printf("배열 갯수 : ");
	scanf_s("%d", &n);

	int* arr = (int*)malloc(n * sizeof(int));

	printf("배열에 들어갈 값 : ");
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}

	fn_sort(arr, n);

	_write(1, "오름차순 :", strlen("오름차순 :"));
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");


	fn_sortted(arr, n);
	_write(1, "내림차순 :", strlen("내림차순 :"));
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	return 0;

	free(arr);

}


//오름차순
void fn_sort(int* arr, int count)
{
	int temp = 0;
	for (int i = 0; i < count - 1; i++) {
		for (int j = 0; j < count - i - 1; j++) {
			if (arr[j] > arr[j + 1]) { 
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//내림차순
void fn_sortted(int* arr, int count)
{
	int temp = 0;
	for (int i = 0; i < count - 1; i++) {
		for (int j = 0; j < count - i - 1; j++) {
			if (arr[j] < arr[j + 1]) { // 수정: 부등호 수정
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
