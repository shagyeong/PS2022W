//1461: 도서관(그리디 알고리즘, 정렬)
#include<stdio.h>
void mergesort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);

int main(void){
    int ans = 0;
    int i, j;
    int n, m; scanf("%d %d", &n, &m);
    int book[n];
    for(i = 0; i < n; i++){scanf("%d", &book[i]);}
    mergesort(book, 0, n - 1);

    i = 0;
    while(book[i] < 0 && i < n){
        ans += 2 * (-book[i]);
        i += m;
    }
    i = n - 1;
    while(book[i] > 0 && i >= 0){
        ans += 2 * book[i];
        i -= m;
    }
    
    i = (book[0] > 0)?(book[0]):(-book[0]);
    j = (book[n-1] > 0)?(book[n-1]):(-book[n-1]);
    ans = (i > j)?(ans - i):(ans - j);

    printf("%d", ans);
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
