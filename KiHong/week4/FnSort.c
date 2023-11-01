/*
3. (bonus) 인수를 받으면 정렬하여 출력하는 함수를 만드시오 (편집됨) 
*/

#include <stdio.h>


#define MAX 10

int* middle(int *left, int *middle, int *right);
void swap(int *a, int *b);
void QuickSort(int A[], int begin, int end);


int main(void) {
    int array[MAX];
    int array2[10]; // 예를 들어 10개의 정수를 저장할 배열

    int k = 0;
    while (k < MAX) {
        int scanResult = scanf("%d", &array[k]);

        if (scanResult == EOF || scanResult != 1 || array[k] == '\n')
            break;
        
        k++;
    }
    
    QuickSort(array, 0, k);

    for (int j = 0; j < k; j++) {
        printf("%d ", array[j]);
    }
    printf("\n");

    return 0;
}


/// 정렬되어야하는 배열의 첫 값, 중앙 값, 끝 값 중에서 중간 값 구하는 함수
/// <data1 : int *left>   가장 왼쪽 배열 원소
/// <data2 : int *middle> 중앙 배열 원소
/// <data3 : int *right>  가장 오른쪽 배열 원소
/// <return : int> 주어진 세개의 원소 중에서 중간 값을 반환
int* middle(int *left, int *middle, int *right)
{
	// 중앙 원소가 중간 값이면 반환
	if ((*left >= *middle && *middle >= *right) || (*right >= *middle && *middle >= *left))
		return middle;
	
	// 왼쪽 원소가 중간 값이면 반환
	if ((*middle >= *left && *left >= *right) || (*right >= *left && *left >= *middle))
		return left;
	
	// 오른쪽 원소가 중간 값이면 반환
	if ((*left >= *right && *right >= *middle) || (*middle >= *right && *right >= *left))
		return right;
	
	// 예외 처리
	return left;
}

/// 두 정수를 바꾸는 함수
/// <data1 : int *a> b와 바뀔 수
/// <data2 : int *b> a와 바뀔 수
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

/// 퀵 정렬 함수
/// <data1 : int A[]>   정렬해야하는 배열
/// <data2 : int begin> 배열의 시작점
/// <data3 : int end>   배열의 끝점
void QuickSort(int A[], int begin, int end) {
	// 시작점이 끝점보다 크거나 같으면 더이상 비교할 배열이 없는 것으로 함수를 나간다.
	if (begin >= end) return;

	////////////////////////////////
	//피봇 정의 시작
	//중간 값을 가지는 pivot을 구하는 함수
	int *pivot = middle(&A[begin], &A[(end/2)], &A[end]); // 처음, 중간, 끝의 배열을 비교하여 피봇 생성

	// 피봇이 첫 배열이 아니라면 첫 배열로 이동시키며 첫 배열 값을 피봇과 교환한다.
	if (pivot != &A[begin]) {
		swap(&A[begin], pivot); // 첫 배열과 피봇의 값을 교환
	}

	pivot = &A[begin]; // 피봇을 맨 왼편 배열로 선언

	/////////////////////////////////
	int b = begin;
	int e = end;

	// 앞에서부터 큰 수를 찾는 b와 뒤에서부터 작은 수를 찾는 e가 서로 같은 위치가 아니라면 반복
	while (1) {
		// 피봇보다 큰 값을 찾는 반복자
		// b의 원소가 피봇보다 작고 b가 e보다 작을때 계속 다음 원소를 찾는다.
		while (A[b] <= *pivot && b < e) 
		{
			b++; // 큰 값이 아니면 다음 값을 봄
		}
		// 피봇보다 작은 값을 찾는 반복자
		// e의 원소가 피봇보다 크고 b가 e보다 작을때 계속 다음 원소를 찾는다.
		while (A[e] > *pivot && b < e) 
		{
			e--; // 작거나 같은 값이 아니면 다음 값을 봄
		}
		
		// b와 e가 같으면 원소 위치를 바꾸거나 탐사를 할 이유가 없기에 반복문을 나간다.
		if(b == e) break;

		// 위 두 조건을 만족하면 왼편에서 더 큰수가 오른편에서 더 작은 수가 발견된 것으로 둘을 바꾸어야한다.
		// 위의 두 반복문이 완료되면 e와 b는 같은 자리의 수를 가르킨다.
		swap(&A[b], &A[e]);
	}

	// 이제 피봇을 e의 자리와 변경하여 두 배열의 중앙에 위치하게 한다
	swap(pivot, &A[e-1]);

	// 재귀함수로 좌우의 배열을 퀵정렬을 반복한다
	QuickSort(A, begin, e - 2);
	QuickSort(A, e, end);
}
