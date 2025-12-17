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

int main(void){
    unsigned char j; unsigned char k; // 반복문 제어
    unsigned char v; // 최소값 버퍼
    unsigned char i; // 최소값 인덱스 버퍼
    unsigned char N=10;
    unsigned char a[10]={32,21,14,10,22,45,53,42,16,24};
    for(j=0;j<N;j++){printf("%u ",a[j]);}printf("\n");
    // 선택 정렬
    for(j=0;j<N;j++){
        i=j;
        v=a[j];
        for(k=j+1;k<N;k++){
            if(a[k]<v){
                i=k;
                v=a[k];
            }
        }
        a[i]=a[j];
        a[j]=v;
    }
    for(j=0;j<N;j++){printf("%u ",a[j]);}printf("\n");
}
```
```
$ ./test
32 21 14 10 22 45 53 42 16 24 
10 14 16 21 22 24 32 42 45 53 
```
### 4.1.2 버블 정렬
#### 버블 정렬
```C
#include<stdio.h>

int main(void){
    unsigned char j; unsigned char k;
    unsigned char b; // 스와핑 버퍼
    unsigned char N=10;
    unsigned char a[10]={32,21,14,10,22,45,53,42,16,24};
    for(j=0;j<N;j++){printf("%u ",a[j]);}printf("\n");
    //버블 정렬
    for(j=0;j<N;j++){
        for(k=0;k<N-j-1;k++){
            if(a[k]>a[k+1]){
                b=a[k];
                a[k]=a[k+1];
                a[k+1]=b;
            }
        }
    }
    for(j=0;j<N;j++){printf("%u ",a[j]);}printf("\n");
}
```
```
$ ./test
32 21 14 10 22 45 53 42 16 24 
10 14 16 21 22 24 32 42 45 53 
```
### 4.1.3 삽입 정렬
#### 삽입 정렬
```C
#include<stdio.h>

int main(void){
    unsigned char j; unsigned char k;
    unsigned char b; // 스와핑 버퍼
    unsigned char N=10;
    unsigned char a[10]={32,21,14,10,22,45,53,42,16,24};
    for(j=0;j<N;j++){printf("%u ",a[j]);}printf("\n");
    // 삽입 정렬
    for(j=1;j<N;j++){
        for(k=j;k>0;k--){
            if(a[k]<a[k-1]){
                b=a[k];
                a[k]=a[k-1];
                a[k-1]=b;
            }
        }
    }
    for(j=0;j<N;j++){printf("%u ",a[j]);}printf("\n");
}
```
```
$ ./test
32 21 14 10 22 45 53 42 16 24 
10 14 16 21 22 24 32 42 45 53 
```
### 4.1.4 셸 정렬
#### 셸 정렬
```C
#include<stdio.h>

// g: gap, n: 배열 사이즈
void gapsort(unsigned char a[],unsigned char s,unsigned char e,unsigned char g);
void shellsort(unsigned char a[],unsigned char n);

int main(void){
    unsigned char j;
    unsigned char N=10;
    unsigned char a[10]={32,21,14,10,22,45,53,42,16,24};
    for(j=0;j<N;j++){printf("%u ",a[j]);}printf("\n");
    shellsort(a,N);
    for(j=0;j<N;j++){printf("%u ",a[j]);}printf("\n");
}

void gapsort(unsigned char a[],unsigned char s,unsigned char e,unsigned char g){
    unsigned char j;
    unsigned char k;
    unsigned char b; // 스와핑 버퍼

    for(j=s+g;j<=e;j+=g){
        for(k=j;k>=g;k-=g){
            if(a[k]<a[k-g]){
                b=a[k];
                a[k]=a[k-g];
                a[k-g]=b;
            }
        }
    }
}
void shellsort(unsigned char a[],unsigned char n){
    unsigned char j;
    unsigned char g; // gap
    g=n/2;
    while(g>=1){
        for(j=0;j<g;j++){gapsort(a,j,n-1,g);}
        g/=2;
    }
}
```
```
$ ./test
32 21 14 10 22 45 53 42 16 24 
10 14 16 21 22 24 32 42 45 53 
```



## 4.2 선형 로그 시간 정렬
### 4.2절 구현체 요약
||정렬 방향|
|---|---|
|4.2.1 퀵 정렬|오름차순|
|4.2.2 병합 정렬|오름차순|
<!-- |4.2.3 힙 정렬|오름차순| -->
<!-- |4.2.4 트리 정렬|오름차순| -->
### 4.2.1 퀵 정렬
#### 퀵 정렬
```C
#include<stdio.h>

void          quicksort(unsigned char a[],unsigned char s,unsigned char e);
unsigned char partition(unsigned char a[],unsigned char s,unsigned char e);

int main(void){
    unsigned char j;
    unsigned char N=10;
    unsigned char a[10]={32,21,14,10,22,45,53,42,16,24};
    for(j=0;j<N;j++){printf("%u ",a[j]);}printf("\n");
    quicksort(a,0,N-1);
    for(j=0;j<N;j++){printf("%u ",a[j]);}printf("\n");
}

void          quicksort(unsigned char a[],unsigned char s,unsigned char e){
    unsigned char p;
    if(s<e){
        p=partition(a,s,e);
        quicksort(a,s,p-1);
        quicksort(a,p+1,e);
    }
}
unsigned char partition(unsigned char a[],unsigned char s,unsigned char e){
    unsigned char p=(unsigned char)((s+e)/2); // 피벗 인덱스 랜덤 선택(중앙)
    unsigned char L=s;
    unsigned char R=e;
    unsigned char b; // 스와핑 버퍼

    while(L<R){
        while((a[L]< a[p])&&(L<R)){L++;} // 피벗 좌측: 피벗보다 큰 원소 찾기
        while((a[R]>=a[p])&&(L<R)){R--;} // 피벗 우측: 피벗보다 작은 원소 찾기
        if(L<R){
            b=a[L];
            a[L]=a[R];
            a[R]=b;
            if(L==p){
                p=R;
            }
        }
    }
    b=a[p];
    a[p]=a[R];
    a[R]=b;
    return p;
}
```
```
$ ./test
32 21 14 10 22 45 53 42 16 24 
10 16 14 21 22 24 32 42 45 53 
```
### 4.2.2 병합 정렬
#### 병합 정렬
```C
#include<stdio.h>

void mergesort(unsigned char a[],unsigned char s,                unsigned char e);
void merge    (unsigned char a[],unsigned char s,unsigned char m,unsigned char e);

int main(void){
    unsigned char j;
    unsigned char N=10;
    unsigned char a[10]={32,21,14,10,22,45,53,42,16,24};
    for(j=0;j<N;j++){printf("%u ",a[j]);}printf("\n");
    mergesort(a,0,N-1);
    for(j=0;j<N;j++){printf("%u ",a[j]);}printf("\n");
}

void mergesort(unsigned char a[],unsigned char s,                unsigned char e){
    if(s<e){
        unsigned char m=(s+e)/2;
        mergesort(a,s,  m);
        mergesort(a,m+1,e);
        merge(a,s,m,e);
    }
}
void merge    (unsigned char a[],unsigned char s,unsigned char m,unsigned char e){
    unsigned char i;
    unsigned char j;
    unsigned char k;
    unsigned char L=m-s+1;unsigned char l[L];
    unsigned char R=e-m;  unsigned char r[R];
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
```
$ ./test
32 21 14 10 22 45 53 42 16 24 
10 14 16 21 22 24 32 42 45 53
```
<!-- ### 4.2.3 힙 정렬
#### 힙 정렬
```C
```
```
```
### 4.2.4 트리 정렬
#### 트리 정렬
```C
```
```
``` -->



<!-- ## 4.3 선형 시간 정렬 -->
<!-- ### 4.3.1 기수 정렬 -->
