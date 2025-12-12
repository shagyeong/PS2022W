//2751: 수 정렬하기 2(정렬)
#include<stdio.h>
void mergesort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);

int main(void){
    int n; scanf("%d", &n); int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    mergesort(arr, 0, n - 1);
    for(int i = 0; i < n; i++){
        printf("%d\n", arr[i]);
    }
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
    int left = m - l + 1;   int L[left];
    int right = r - m;      int R[right];

    for(i = 0; i < left;  i++){L[i] = arr[l + i];}
    for(j = 0; j < right; j++){R[j] = arr[m + 1 + j];}

    i = 0; j = 0; k = l;

    while(i < left && j < right){
        if(L[i] <= R[j]){
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
