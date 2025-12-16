//1684: 같은 나머지(수학, 정수론, 유클리드 호제법)
#include<stdio.h>
int gcd(int a, int b);
void mergesort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);

int main(void){
    int n; scanf("%d", &n);
    if(n == 1){
        int ans; scanf("%d", &ans);
        ans = (ans > 0)?(ans):(-ans);
        printf("%d", ans);
    }
    else if(n == 2){
        int ans;
        int a, b; scanf("%d %d", &a, &b);
        if(a > b){ans = a - b; printf("%d", ans);}
        else if(a < b){ans = b - a; printf("%d", ans);}
        else{printf("%d", a);}
    }
    else{
        int i; int j = 0;
        int arr[n]; int diff[n - 1];
        for(i = 0; i < n; i++){scanf("%d", &arr[i]);}
        mergesort(arr, 0, n - 1);
        for(i = 0; i < n - 1; i++){diff[i] = arr[i + 1] - arr[i];}
        for(i = 0; i < n - 2; i++){
            diff[i + 1] = gcd(diff[i], diff[i + 1]);
        }
        for(i = 0; i < n - 1; i++){j += diff[i];}
        if(j == 0){
            printf("%d", arr[0]);   //모든 숫자가 같음
        }
        else{
            printf("%d", diff[n - 2]);
        }
    }
}
int gcd(int a, int b){
    if(a == 0){return b;}
    else if(b == 0){return a;}
    else{
        int e;
        int c = a;
        int d = b;
        while(d%c != 0){
            e = d; d = c; c = e%c;
        }
        return c;
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
