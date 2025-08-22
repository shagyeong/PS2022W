#include<stdio.h>
void quicksort(int arr[], int l, int r);
int partition(int arr[], int l, int r, int x);

int main(void){
    int arr[10] = {3, 2, 7, 0, 1, 9, 8, 6, 4, 5};
    quicksort(arr, 0, 9);
    for(int i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }printf("\n");
}
void quicksort(int arr[], int l, int r){
    if(l < r){
        int pivot = arr[r];   //랜덤
        int pos = partition(arr, l, r, pivot);
        quicksort(arr, l, pos - 1);
        quicksort(arr, pos + 1, r);
    }
}
int partition(int arr[], int l, int r, int x){
    int i, j; int buf;
    //피벗 인덱스
    for(i = l; i < r; i++){
        if(arr[i] == x){break;}
    }
    buf = arr[i]; arr[i] = arr[r]; arr[r] = buf; //swap

    i = l;
    for(j= l; j < r; j++){
        if(arr[j] <= x){
            buf = arr[i]; arr[i] = arr[j]; arr[j] = buf; //swap
            i++;
        }
    }
    buf = arr[i]; arr[i] = arr[r]; arr[r] = buf;    //swap
    return i;
}
