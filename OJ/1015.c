//1015: 수열 정렬(정렬)
#include<stdio.h>
void mergesort(int arr[][2], int l, int r);
void merge(int arr[][2], int l, int m, int r);

int main(void){
    int n; scanf("%d", &n);
    int ans[n];
    int arr[n][2];
    for(int i = 0; i < n; i++){
        arr[i][0] = i;
        scanf("%d", &arr[i][1]);
    }
    mergesort(arr, 0, n - 1);
    for(int i = 0; i < n; i++){
        ans[arr[i][0]] = i;
    }
    for(int i = 0; i < n; i++){
        printf("%d ", ans[i]);
    }
}
void mergesort(int arr[][2], int l, int r){
    if(l < r){
        int m = (l + r) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void merge(int arr[][2], int l, int m, int r){
    int i, j ,k;
    int left = m - l + 1; int L[left][2];
    for(i = 0; i < left; i++){
        L[i][0] = arr[l + i][0];
        L[i][1] = arr[l + i][1];
    }
    int right = r - m; int R[right][2];
    for(i = 0; i < right; i++){
        R[i][0] = arr[m + 1 + i][0];
        R[i][1] = arr[m + 1 + i][1];
    }
    i = 0; j = 0; k = l;
    while(i < left && j < right){
        if(L[i][1] == R[j][1]){
            if(L[i][0] < R[j][0]){
                arr[k][0] = L[i][0];
                arr[k][1] = L[i][1];
                k++; i++;
            }
            else{
                arr[k][0] = R[j][0];
                arr[k][1] = R[j][1];
                k++; j++;
            }
        }
        else if(L[i][1] < R[j][1]){
            arr[k][0] = L[i][0];
            arr[k][1] = L[i][1];
            k++; i++;
        }
        else{
            arr[k][0] = R[j][0];
            arr[k][1] = R[j][1];
            k++; j++;
        }
    }
    while(i < left){
        arr[k][0] = L[i][0];
        arr[k][1] = L[i][1];
        k++; i++;
    }
    while(j < right){
        arr[k][0] = R[j][0];
        arr[k][1] = R[j][1];
        k++; j++;
    }
}
