//11650: 좌표 정렬하기(정렬)
#include<stdio.h>
void mergesort(int points[][2], int l, int r);
void merge(int points[][2], int l, int m, int r);

int main(void){
    int n; scanf("%d", &n);
    int points[n][2];
    for(int i = 0; i < n; i++){
        scanf("%d %d", &points[i][0], &points[i][1]);
    }
    mergesort(points, 0, n - 1);
    for(int i = 0; i < n; i++){
        printf("%d %d\n", points[i][0], points[i][1]);
    }
}
void mergesort(int points[][2], int l, int r){
    if(l < r){
        int m = (l + r) / 2;
        mergesort(points, l, m);
        mergesort(points, m + 1, r);
        merge(points, l, m, r);
    }
}
void merge(int points[][2], int l, int m, int r){
    int i, j, k;
    int left = m - l + 1; int L[left][2];
    for(i = 0; i < left; i++){
        L[i][0] = points[l + i][0];
        L[i][1] = points[l + i][1];
    }
    int right = r - m; int R[right][2];
    for(i = 0; i < right; i++){
        R[i][0] = points[m + 1 + i][0];
        R[i][1] = points[m + 1 + i][1];
    }
    i = 0; j = 0; k = l;
    while(i < left && j < right){
        if(L[i][0] == R[j][0]){
            if(L[i][1] < R[j][1]){
                points[k][0] = L[i][0];
                points[k][1] = L[i][1];
                k++; i++;
            }
            else{
                points[k][0] = R[j][0];
                points[k][1] = R[j][1];
                k++; j++;
            }
        }
        else if(L[i][0] < R[j][0]){
            points[k][0] = L[i][0];
            points[k][1] = L[i][1];
            k++; i++;
        }
        else{
            points[k][0] = R[j][0];
            points[k][1] = R[j][1];
            k++; j++;
        }
    }
    while(i < left){
        points[k][0] = L[i][0];
        points[k][1] = L[i][1];
        k++; i++;
    }
    while(j < right){
        points[k][0] = R[j][0];
        points[k][1] = R[j][1];
        k++; j++;
    }
}
