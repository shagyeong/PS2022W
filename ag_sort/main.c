#include<stdio.h>
#include "sort.h"

int main(void){
    int arr1[10] = {3, 2, 7, 0, 1, 9, 8, 6, 4, 5};
    int arr2[10] = {3, 2, 7, 0, 1, 9, 8, 6, 4, 5};

    printf("mergesort\n");
    mergesort(arr1, 0, 9);
    for(int i = 0; i < 10; i++){
        printf("%d ", arr1[i]);
    }printf("\n");

    printf("quicksort\n");
    quicksort(arr2, 0, 9);
    for(int i = 0; i < 10; i++){
        printf("%d ", arr2[i]);
    }printf("\n");
}
