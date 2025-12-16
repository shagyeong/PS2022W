//11497: 통나무 건너뛰기(그리디 알고리즘, 정렬)
#include<stdio.h>
void mergesort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);

int main(void){
    int i, j;
    int t; scanf("%d", &t);
    int n;
    for(i = 0; i < t; i++){
        scanf("%d", &n);
        int a[n]; int b[n];
        for(j = 0; j < n; j++){scanf("%d", &a[j]);}
        mergesort(a, 0, n - 1);
        for(j = 0; j < (n + 1)/2; j++){
            b[n - 1 - j] = a[2 * j + 1];
            b[j] = a[2*j];
        }
        j = 0;
        for(j = 0; j < n - 1; j++){
            a[j] = (b[j + 1] > b[j])?(b[j + 1] - b[j]):(b[j]- b[j + 1]);
        }a[j] = b[j] - b[0];
        mergesort(a, 0, n - 1);
        printf("%d\n", a[n - 1]);
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
    int left = m - l + 1;
    int right = r - m;
    int L[left];for(i = 0; i < left; i++){L[i] = arr[l + i];}
    int R[right]; for(i = 0; i < right; i++){R[i] = arr[m + 1 + i];}
    i = 0; j = 0; k = l;
    while(i < left && j < right){
        if(L[i] < R[j]){arr[k++] = L[i++];}
        else{arr[k++] = R[j++];}
    }
    while(i < left){arr[k++] = L[i++];}
    while(j < right){arr[k++] = R[j++];}
}
