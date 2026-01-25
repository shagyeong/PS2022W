# 2장 스택/큐
## 1 같은 숫자는 싫어
```C
#include<stdio.h>
#include<stdlib.h>

void solve(int n,int* a);

int main(void){
    int j;
    int n; scanf("%d",&n);
    int* a=(int*)malloc(sizeof(int)*n);
    for(j=0;j<n;j++){scanf("%d",&a[j]);}
    solve(n,a);
    free(a);
}

void solve(int n,int* a){
    int  j;
    int* q=(int*)malloc(sizeof(int)*n);
    int  r=0; // rear of queue
    q[r++]=a[0]; // enqueue

    for(j=1;j<n;j++){
        if(a[j]==q[r-1]){continue;}
        else            {q[r++]=a[j];}
    }

    for(j=0;j<r;j++){printf("%d ",q[j]);}
    free(q);
    return ;
}
```
```
$ ./test
7 
1 1 3 3 0 1 1
1 3 0 1 
```
```
$ ./test
5  
4 4 4 3 3
4 3 
```
## 2 기능개발
```C
#include<stdio.h>
#include<stdlib.h>

void solve(int n,int* a);

int main(void){
    int j;
    int n; scanf("%d",&n);
    int* a=(int*)malloc(sizeof(int)*n);
    int q; // quotient: 작업 속도
    for(j=0;j<n;j++){scanf("%d",&a[j]);}
    for(j=0;j<n;j++){
        scanf("%d",&q);
        a[j]=100-a[j];
        a[j]=(a[j]%q==0)?(a[j]/q):(a[j]/q+1);
    }
    solve(n,a);
    free(a);
}

void solve(int n,int* a){
    int j;
    int* q=(int*)malloc(sizeof(int)*n); // queue
    int r=0; // rear  of queue
    q[r++]=a[0]; // enqueue

    for(j=1;j<n;j++){
        if(a[j]<=q[0]){
            q[r++]=a[j];
        }
        else{
            printf("%d ",r);
            r=0;
            q[r++]=a[j];
        }
    }
    printf("%d",r);

    free(q);
    return;
}
```
```
$ ./test
3
93 30 55
1 30 5
2 1
```
```
$ ./test
6
95 90 99 99 80 99
1 1 1 1 1 1
1 3 2
```
## 3 올바른 괄호
```C
```
```
```
```
```
## 4 프로세스
```C
```
```
```
```
```
## 5 다리를 지나는 트럭
```C
```
```
```
```
```
## 6 주식가격
```C
```
```
```
```
```
