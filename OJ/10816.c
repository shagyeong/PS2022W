//10816: 숫자 카드 2(자료 구조, 정렬, 이분 탐색, 해시를 사용한 집합과 맵)
#include<stdio.h>
int searchlb(int arr[], int len, int i);
int searchub(int arr[], int len, int i);
void mergesort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);


int main(void){
    //입력 값 세팅
    int n; scanf("%d", &n);
    int targ[n];
    for(int i = 0; i < n; i++){scanf("%d", &targ[i]);}
    int m; scanf("%d", &m);
    int arg;

    //정답 출력
    mergesort(targ, 0, n - 1);
    for(int i = 0; i < m; i++){
        scanf("%d", &arg);
        printf("%d ", searchub(targ, n, arg) - searchlb(targ, n, arg) + 1);
    }
}
int searchlb(int arr[], int len, int i){
    int l = 0; int r = len - 1;
    int index = (l + r) >> 1;
    int middle;
    while(l <= r){
        middle = arr[index];
        if(i > middle){
            l = index + 1;
            index = (l + r) >> 1;
        }
        else{
            r = index - 1;
            index = (l + r) >> 1;
        }
    }
    return l;
}
int searchub(int arr[], int len, int i){
    int l = 0; int r = len - 1;
    int index = (l + r) >> 1;
    int middle;
    while(l <= r){
        middle = arr[index];
        if(i < middle){
            r = index - 1;
            index = (l + r) >> 1;
        }
        else{
            l = index + 1;
            index = (l + r) >> 1;
        }
    }
    return r;
}
void mergesort(int arr[], int l, int r){
    if(l < r){
        int m = (l + r) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m , r);
    }
}
void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int left = m - l + 1; int L[left];
    for(i = 0; i < left; i++){L[i] = arr[l + i];}
    int right = r - m; int R[right];
    for(i = 0; i < right; i++){R[i] = arr[m + 1 + i];}
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
