//1920: 수 찾기(자료 구조, 정렬, 이분 탐색, 해시를 사용한 집합과 맵)
#include<stdio.h>
int search(int arr[], int len, int i);
void mergesort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);

int main(void){
    int i;
    int n; scanf("%d", &n); int targ[n];
    for(i = 0; i < n; i++){
        scanf("%d", &targ[i]);
    }
    int m; scanf("%d", &m);int args[m];
    for(i = 0; i < m; i++){
        scanf("%d", &args[i]);
    }
    mergesort(targ, 0, n - 1);
    for(i= 0; i < m; i++){
        printf("%d\n", search(targ, n, args[i]));
    }
}
int search(int arr[], int len, int i){
    int l = 0, r = len - 1;
    if(i > arr[r] || i < arr[l]){
        return 0;
    }
    int index = len / 2;
    while(index - l > 0 && r - index > 0){
        if(i == arr[index]){
            return 1;
        }
        else if(i < arr[index]){
            r = index;
            index = (l + index) / 2;
        }
        else{
            l = index;
            index = (index + r) / 2;
        }
    }
    for(int j = l; j <= r; j++){
        if(i == arr[j]){
            return 1;
        }
    }
    return 0;    
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
