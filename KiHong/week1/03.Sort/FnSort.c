#include <stdio.h>


void BubbleSort(int array[], int size);
void PrintOutArray(int array[], int size);

int main(void) {
    int array[6] = { 7, 5, 1, 4, 3, 6 };
    int size = sizeof(array)/sizeof(array[0]);

    BubbleSort(array, size);
    PrintOutArray(array, size);
    
    return 0;
}

// <Summary> Bubble sort algorithm
// <Parameter=*a> Target array
// <Parameter=*b> Size of the array
void BubbleSort(int array[], int size) {
    for (int k = 0; k < size; k++) {
        for (int j = k + 1; j < size; j++) {
            if (array[k] > array[j]) {
                int temp = array[k];
                array[k] = array[j];
                array[j] = temp;
            }
        }
    }
}

// <Summary> Print out input array value
// <Parameter=*a> Target array
// <Parameter=*b> Size of the array
void PrintOutArray(int array[], int size) {
    for (int k = 0; k < size; k++) {
        printf("%d ", array[k]);
    }
    printf("\n");
}