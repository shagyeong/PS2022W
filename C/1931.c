//1931: 회의실 배정(그리디 알고리즘, 정렬)
#include<stdio.h>
struct meeting{
    int start;
    int end;
};
void mergesort(struct meeting arr[], int l, int r);
void merge(struct meeting arr[], int l, int m, int r);

int main(void){
    //입력값 세팅
    int n; scanf("%d", &n);
    struct meeting meetings[n];
    for(int i = 0; i < n; i++){
        scanf("%d %d", &meetings[i].start, &meetings[i].end);
    }
    //회의 종료 시간 기준 정렬
    mergesort(meetings, 0, n - 1);
    //그리디
    int count = 1;
    int end = meetings[0].end;
    for(int i = 1; i < n; i++){
        if(meetings[i].start >= end){
            end = meetings[i].end;
            count++;
        }
    }
    printf("%d", count);
    
}
void mergesort(struct meeting arr[], int l, int r){
    if(l < r){
        int m = (l + r) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void merge(struct meeting arr[], int l, int m, int r){
    int i, j, k;
    int left = m - l + 1;
    int right = r - m;
    struct meeting L[left]; for(i = 0; i < left;  i++){L[i] = arr[l + i];}
    struct meeting R[right];for(j = 0; j < right; j++){R[j] = arr[m + 1 + j];}
    i = 0; j = 0; k = l;
    while(i < left && j < right){
        if(L[i].end == R[j].end){
            if(L[i].start < R[j].start){arr[k++] = L[i++];}
            else{arr[k++] = R[j++];}
        }
        else if(L[i].end < R[j].end){
            arr[k++] = L[i++];
        }
        else{
            arr[k++] = R[j++];
        }
    }
    while(i < left){arr[k++] = L[i++];}
    while(j < right){arr[k++] = R[j++];}
}
