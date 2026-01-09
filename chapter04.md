# 4장 정렬
## 4.1 2차 시간 정렬
### 4.1절 구현체 요약
||정렬 방향|정렬되지 않은 부분집합|정렬된 부분집합|
|---|---|---|---|
|4.1.1 선택정렬|오름차순|최소값 획득|부분집합의 마지막 원소로|
|4.1.2 버블정렬|오름차순|최대값 획득(비교 및 자리 교환)|부분집합의 첫 번째 원소로|
|4.1.3 삽입정렬|오름차순|첫 번째 원소 획득|부분집합의 *알맞은 위치*로|
|4.1.4 셸 정렬|오름차순|||
### 4.1.1 선택 정렬
#### 선택 정렬
```C
#include<stdio.h>

void sort(int a[],int n);

int main(void){
    int j;    // loop variable
    int n=10; // number of item
    int a[10]={32,21,14,10,22,45,53,42,16,24};
    sort(a,n);
    for(j=0;j<n;j++){printf("%d ",a[j]);}
}

void sort(int a[],int n){
    int j; // loop variable
    int k; // loop variable
    int v; // min value
    int i; // index of min value
    for(j=0;j<n;j++){
        i=j;
        v=a[j];
        for(k=j+1;k<n;k++){
            if(a[k]<v){
                i=k;
                v=a[k];
            }
        }
        a[i]=a[j];
        a[j]=v;
    }
}
```
```
$ ./test
10 14 16 21 22 24 32 42 45 53
```
### 4.1.2 버블 정렬
#### 버블 정렬
```C
#include<stdio.h>

void sort(int a[],int n);

int main(void){
    int j;    // loop variable
    int n=10; // number of item
    int a[10]={32,21,14,10,22,45,53,42,16,24};
    sort(a,n);
    for(j=0;j<n;j++){printf("%d ",a[j]);}
}

void sort(int a[],int n){
    int j; // loop variable
    int k; // loop variable
    int t; // tmp(swap)
    for(j=0;j<n;j++){
        for(k=0;k<n-j-1;k++){
            if(a[k]>a[k+1]){
                t=a[k];
                a[k]=a[k+1];
                a[k+1]=t;
            }
        }
    }
}
```
```
$ ./test
10 14 16 21 22 24 32 42 45 53
```
### 4.1.3 삽입 정렬
#### 삽입 정렬
```C
#include<stdio.h>

void sort(int a[],int n);

int main(void){
    int j;    // loop variable
    int n=10; // number of item
    int a[10]={32,21,14,10,22,45,53,42,16,24};
    sort(a,n);
    for(j=0;j<n;j++){printf("%d ",a[j]);}
}

void sort(int a[],int n){
    int j; // loop variable
    int k; // loop variable
    int t; // tmp(swap)
    for(j=1;j<n;j++){
        for(k=j;k>0;k--){
            if(a[k]<a[k-1]){
                t=a[k];
                a[k]=a[k-1];
                a[k-1]=t;
            }
        }
    }
}
```
```
$ ./test
10 14 16 21 22 24 32 42 45 53
```
### 4.1.4 셸 정렬
#### 셸 정렬
```C
#include<stdio.h>

void shellsort(int a[],int n);
void gapsort(int a[],int s,int e,int g);

int main(void){
    int j;    // loop variable
    int n=10; // number of item
    int a[10]={32,21,14,10,22,45,53,42,16,24};
    shellsort(a,n);
    for(j=0;j<n;j++){printf("%d ",a[j]);}
}

void shellsort(int a[],int n){
    int j;
    int g; // gap
    g=n/2;
    while(g>=1){
        for(j=0;j<g;j++){gapsort(a,j,n-1,g);}
        g/=2;
    }
}
void gapsort(int a[],int s,int e,int g){
    int j;
    int k;
    int t; // tmp(swap)
    for(j=s+g;j<=e;j+=g){
        for(k=j;k>=g;k-=g){
            if(a[k]<a[k-g]){
                t=a[k];
                a[k]=a[k-g];
                a[k-g]=t;
            }
        }
    }
}
```
```
$ ./test
10 14 16 21 22 24 32 42 45 53
```



## 4.2 선형 로그 시간 정렬
### 4.2절 구현체 요약
||정렬 방향|
|---|---|
|4.2.2 퀵 정렬|오름차순|
|4.2.3 병합 정렬|오름차순|
<!-- |4.2.4 힙 정렬|오름차순| -->
<!-- |4.2.5 트리 정렬|오름차순| -->
### 4.2.1 qsort()
#### qsort()
```C
#include<stdlib.h>
void qsort(void* base,size_t nmemb,size_t size,int(*compar)(const void*,const void*));
```
#### qsort()
```C
#include<stdio.h>
#include<stdlib.h>

int compare(const void* u,const void* v);

int main(void){
    int j;    // loop variable
    int n=10; // number of item
    int a[10]={32,21,14,10,22,45,53,42,16,24};
    qsort(a,n,sizeof(int),compare);
    for(j=0;j<n;j++){printf("%d ",a[j]);}
}

int compare(const void* u,const void* v){
    if((*((int*)u))<(*((int*)v))){return -1;}
    if((*((int*)u))>(*((int*)v))){return 1;}
    return 0;
}
```
```
$ ./test
10 14 16 21 22 24 32 42 45 53
```
#### qsort(): tie breaking rule
```C
#include<stdio.h>
#include<stdlib.h>

struct node{
    int v; // value
    int i; // id: tie breaking rule
};

int compare(const void* u,const void* v);

int main(void){
    int j;    // loop variable
    int n=10; // number of item
    struct node a[10]={
        {22,0},{21,1},{14,2},{10,3},{22,4},
        {45,5},{22,6},{42,7},{22,8},{24,9}
    };
    qsort(&a[0],n,sizeof(struct node),compare);
    for(j=0;j<n;j++){printf("%d ",a[j].v);} printf("\n");
    for(j=0;j<n;j++){printf("%d  ",a[j].i);}
}

int compare(const void* u,const void* v){
    if((((struct node*)u)->v)< (((struct node*)v)->v)){return -1;}
    if((((struct node*)u)->v)> (((struct node*)v)->v)){return 1;}
    if((((struct node*)u)->v)==(((struct node*)v)->v)){
        if((((struct node*)u)->i)< (((struct node*)v)->i)){return -1;}
        if((((struct node*)u)->i)> (((struct node*)v)->i)){return 1;}
    }
    return 0;
}
```
중복 데이터(22)에서 tie breaking rule 적용 확인  
```
$ ./test
10 14 21 22 22 22 22 24 42 45 
3  2  1  0  4  6  8  9  7  5 
```
### 4.2.2 퀵 정렬
#### 퀵 정렬
```C
#include<stdio.h>

void quicksort(int a[],int s,int e);
int  partition(int a[],int s,int e);

int main(void){
    int j;    // loop variable
    int n=10; // number of item
    int a[10]={32,21,14,10,22,45,53,42,16,24};
    quicksort(a,0,n-1);
    for(j=0;j<n;j++){printf("%d ",a[j]);}
}


void quicksort(int a[],int s,int e){
    int p;
    if(s<e){
        p=partition(a,s,e);
        quicksort(a,s,p);
        quicksort(a,p+1,e);
    }
}

int  partition(int a[],int s,int e){
    int t; // tmp(swap)
    int p=a[s+(e-s)/2];
    int l=s-1;
    int r=e+1;

    while(1){
        do{l++;}while(a[l]<p);
        do{r--;}while(a[r]>p);
        if (l >= r) return r;
        t=a[l];
        a[l]=a[r];
        a[r]=t;
    }
}
```
```
$ ./test
10 14 16 21 22 24 32 42 45 53 
```
### 4.2.3 병합 정렬
#### 병합 정렬
```C
#include<stdio.h>

void mergesort(int a[],int s,      int e);
void     merge(int a[],int s,int m,int e);

int main(void){
    int j;    // loop variable
    int n=10; // number of item
    int a[10]={32,21,14,10,22,45,53,42,16,24};
    mergesort(a,0,n-1);
    for(j=0;j<n;j++){printf("%d ",a[j]);}
}

void mergesort(int a[],int s,      int e){
    if(s<e){
        int m=(s+e)/2;
        mergesort(a,s,  m);
        mergesort(a,m+1,e);
        merge(a,s,m,e);
    }
}
void     merge(int a[],int s,int m,int e){
    int i;
    int j;
    int k;
    int L=m-s+1;int l[L];
    int R=e-m;  int r[R];
    for(i=0;i<L;i++){l[i]=a[s+i];}
    for(i=0;i<R;i++){r[i]=a[m+1+i];}
    i=0;j=0;k=s;
    while(i<L&&j<R){
        if(l[i]<r[j]){a[k++]=l[i++];}
        else{         a[k++]=r[j++];}
    }
    while(i<L){a[k++]=l[i++];}
    while(j<R){a[k++]=r[j++];}
}
```
```$ ./test
10 14 16 21 22 24 32 42 45 53
```
<!-- ### 4.2.4 힙 정렬 -->
<!-- ### 4.2.5 트리 정렬 -->



<!-- ## 4.3 선형 시간 정렬 -->
<!-- ### 4.3.1 기수 정렬 -->
