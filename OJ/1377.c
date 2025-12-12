//1377: 버블 소트(정렬)
#include<stdio.h>
void mergesort(int arr[][2], int l, int r);
void merge(int arr[][2], int l, int m, int r);

int main(void){
    //입력값 세팅
    int n; scanf("%d", &n);
    int arr[n][2];                  //index-value
    for(int i = 0; i < n; i++){
        arr[i][0] = i;
        scanf("%d", &arr[i][1]);
    }
    //정렬(병합 정렬)
    mergesort(arr, 0, n - 1);
    //버블 정렬 수행 횟수 찾기
    int max = 1;    //최소 1회 버블 정렬이 수행됨
    int buf;
    for(int i = 0; i < n; i++){
        buf = arr[i][0] - i + 1;
        if(max < buf){
            max = buf;
        }
    }
    printf("%d", max);   
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
    int i, j, k;
    int left = m - l + 1;
    int L[left][2];  for(i = 0; i < left; i++){
        L[i][0] = arr[l + i][0];
        L[i][1] = arr[l + i][1];
    }
    int right = r - m;
    int R[right][2]; for(j = 0; j < right; j++){
        R[j][0] = arr[m + 1 + j][0];
        R[j][1] = arr[m + 1 + j][1];
    }
    i = 0; j = 0; k = l;
    while(i < left && j < right){
        if(L[i][1] < R[j][1]){
            arr[k][0] = L[i][0];
            arr[k][1] = L[i][1];
            k++; i++;
        }
        else if(L[i][1] > R[j][1]){
            arr[k][0] = R[j][0];
            arr[k][1] = R[j][1];
            k++; j++;
        }
        else{   //안정 정렬
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
