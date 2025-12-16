//1374: 강의실(자료 구조, 그리디 알고리즘, 정렬, 우선순위 큐)
#include<stdio.h>
struct lecture{
    int num;    //과목 번호
    int start;
    int end;
};
void mergesort(struct lecture arr[], int l, int r);
void merge(struct lecture arr[], int l, int m, int r);

int main(void){
    int n; scanf("%d", &n);
    struct lecture lectures[n];
    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &lectures[i].num, &lectures[i].start, &lectures[i].end);
    }
    mergesort(lectures, 0, n - 1);
    for(int i = 0; i < n; i++){
        printf("%d %d %d\n", lectures[i].num, lectures[i].start, lectures[i].end);
    }
}
void mergesort(struct lecture arr[], int l, int r){
    if(l < r){
        int m = (l + r) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void merge(struct lecture arr[], int l, int m, int r){
    int i, j, k;
    int left = m - l + 1;
    int right = r - m;
    struct lecture L[left]; for(i = 0; i < left;  i++){L[i] = arr[l + i];}
    struct lecture R[right];for(j = 0; j < right; j++){R[j] = arr[m + 1 + j];}
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
