#include<stdio.h>
void mergesort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);

int main(void){
    int arr[10] = {3, 2, 7, 0, 1, 9, 8, 6, 4, 5};
    mergesort(arr, 0, 9);
    for(int i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }printf("\n");
}
void mergesort(int arr[], int l, int r){
    if(l < r){
        int m = (l + r) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int left = m - l + 1; int L[left];
    for(i = 0; i < left; i++){
        L[i] = arr[l + i];
    }
    int right = r - m; int R[right];
    for(i = 0; i < right; i++){
        R[i] = arr[m + 1 + i];
    }
    i = 0; j = 0; k = l;
    while(i < left && j < right){
        if(L[i] < R[j]){
            arr[k++] = L[i++];
        }
        else{
            arr[k++] = R[j++];
        }
    }
    while(i < left){
        arr[k++] = L[i++];
    }
    while(j < right){
        arr[k++] = R[j++];
    }
}
