# 7장 최적화: D&C, DP and Greedy
## 7.1 Devid and Conquer(분할 정복)
<!-- ### 7.1.1 병합 정렬 -->
### 7.1.2 거듭제곱 계산
#### 거듭제곱 계산
선형 거듭제곱: $C^{16}=C\times C\times C\times\cdots\times C$  
로그 거듭제곱: $C^{16}=(((C^2)^2)^2)^2$  
짝수 지수: $C^{2n}=C^n\times C^n$  
홀수 지수: $C^{2n+1}=C^n\times C^n\times C$  
#### 거듭제곱 계산
b(base): 밑  
e(exponent): 지수  
```C
#include<stdio.h>

unsigned int power(unsigned int b,unsigned int e);

int main(void){
    unsigned int b=2;
    unsigned int e=13;
    printf("%u^%u=%u\n",b,e,power(b,e));
}

unsigned int power(unsigned int b,unsigned int e){
    if(b==0){return 1;}
    if(e==1){return b;} // b^1
    if(e%2==0){
        unsigned int t=power(b,e/2); // t: temp
        return t*t;
    }
    else{
        unsigned int t=power(b,(e-1)/2);
        return t*t*b;
    }
}
```
```
$ ./test
2^13=8192
```
### 7.1.3 피보나치 수
#### 피보나치 수
피보나치 수열: $F_n=F_{n-2}+F_{n-1}$  
$\begin{bmatrix}F_2&F_1\\F_1&F_0\end{bmatrix}=\begin{bmatrix}1&1\\1&0\end{bmatrix}$  
$\begin{bmatrix}F_2&F_1\\F_1&F_0\end{bmatrix}\begin{bmatrix}1&1\\1&0\end{bmatrix}=\begin{bmatrix}F_1+F_2&F_2\\F_0+F_1&F_1\end{bmatrix}=\begin{bmatrix}F_3&F_2\\F_2&F_1\end{bmatrix}$  
$\begin{bmatrix}F_3&F_2\\F_2&F_1\end{bmatrix}\begin{bmatrix}1&1\\1&0\end{bmatrix}=\begin{bmatrix}F_2+F_3&F_3\\F_1+F_2&F_2\end{bmatrix}=\begin{bmatrix}F_4&F_3\\F_3&F_2\end{bmatrix}$  
$\vdots$  
$\begin{bmatrix}F_{n-1}&F_{n-2}\\F_{n-2}&F_{n-3}\end{bmatrix}\begin{bmatrix}1&1\\1&0\end{bmatrix}=\begin{bmatrix}F_{n-1}+F_{n-2}&F_{n-1}\\F_{n-3}+F_{n-2}&F_{n-2}\end{bmatrix}=\begin{bmatrix}F_n&F_{n-1}\\F_{n-1}&F_{n-2}\end{bmatrix}$  
$\therefore \begin{bmatrix}F_n&F_{n-1}\\F_{n-1}&F_{n-2}\end{bmatrix}=\begin{bmatrix}1&1\\1&0\end{bmatrix}^{n-1}$  
행렬 계산 횟수: $\log_2 n$회(분할 정복 거듭제곱 적용)  
#### 구간합
$F_a+\cdots+F_b=F_{b+2}-F_{a+1}$  
#### 피보나치 수
```C
#include<stdio.h>
#include<stdlib.h>

struct matrix{
    unsigned int m[2][2];
};

struct matrix fib(unsigned int n);

int main(void){
    unsigned int n=0;
    struct matrix m;
    for(n=0;n<15;n++){
        m=fib(n-1);
        printf("fib(%u)=%u\n",n,m.m[0][0]);
    }
}

struct matrix fib(unsigned int n){
    if(n==0xFFFFFFFF){struct matrix m;m.m[0][0]=0; return m;} // F_0: fib(-1)->오버플로우(부호 없음)
    if(n==0 ){        struct matrix m;m.m[0][0]=1; return m;}
    if(n==1){
        struct matrix m;
        m.m[0][0]=1; m.m[0][1]=1;
        m.m[1][0]=1; m.m[1][1]=0;
        return m;
    }
    if(n%2==0){
        struct matrix t=fib(n/2);
        unsigned int a=t.m[0][0]; unsigned int b=t.m[0][1]; // a,b,c,d: 행렬 엘리먼트 tmp
        unsigned int c=t.m[1][0]; unsigned int d=t.m[1][1];
        // t*t
        t.m[0][0]=a*a+b*c; t.m[0][1]=a*b+b*d;
        t.m[1][0]=c*a+d*c; t.m[1][1]=c*b+d*d;
        return t;
    }
    else{
        struct matrix t=fib((n-1)/2);
        unsigned int a=t.m[0][0]; unsigned int b=t.m[0][1];
        unsigned int c=t.m[1][0]; unsigned int d=t.m[1][1];
        // t*t
        t.m[0][0]=a*a+b*c; t.m[0][1]=a*b+b*d;
        t.m[1][0]=c*a+d*c; t.m[1][1]=c*b+d*d;
        // t*t*d
        a=t.m[0][0]; b=t.m[0][1];
        c=t.m[1][0]; d=t.m[1][1];
        t.m[0][0]=a+b; t.m[0][1]=a;
        t.m[1][0]=c+d; t.m[1][1]=c;
        return t;
    }
}
```
```
$ ./test
fib(0)=0    fib(1)=1    fib(2)=1    fib(3)=2    fib(4)=3
fib(5)=5    fib(6)=8    fib(7)=13   fib(8)=21   fib(9)=34
fib(10)=55  fib(11)=89  fib(12)=144 fib(13)=233 fib(14)=377
```



## 7.2 DP
### 7.2.1 점화식 작성
#### 선형시간 피보나치수
재귀: $\mathbf{O}(2^n)$  
DP: $\mathbf{O}(n)$  
분할정복 행렬거듭제곱: $\mathbf{O}(\log n)$  
```C
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j;
    int n; scanf("%d",&n);
    int* t=(int*)malloc(sizeof(int)*(n+1));

    // 테이블 초기화
    t[0]=0;
    t[1]=1;

    // 점화식
    for(j=2;j<=n;j++){t[j]=t[j-2]+t[j-1];}

    // 결과 출력
    printf("%d",t[n]);
}
```
```
$ ./test
10
55
```
#### 동전 개수
그리디(모듈로 기반) 접근이 유효하지 않은 경우 DP로 접근  
단, 아래 과제는 그리디로도 해결 가능함  
```C
#include<stdio.h>
#include<stdlib.h>

#define INF 100001

int main(void){
    int j;
    int n; scanf("%d",&n);
    if(n<=5){
        if(n==1){printf("-1");}
        if(n==2){printf( "1");}
        if(n==3){printf("-1");}
        if(n==4){printf( "2");}
        if(n==5){printf( "1");}
    }
    else{
        // 테이블 초기화
        int* t=(int*)malloc(sizeof(int)*(n+1));
        for(j=0;j<=n;j++){t[j]=INF;}
        t[0]=0;
     // t[1]=INF;
        t[2]=1;
     // t[3]=INF;
        t[4]=2;
        t[5]=1;

        // 점화식
        for(j=6;j<=n;j++){t[j]=(t[j-2]<t[j-5])?(t[j-2]+1):(t[j-5]+1);}

        // 결과 출력
        printf("%d",t[n]);
    }
}
```
```
$ ./test
13
5
```
```
$ ./test
14
4
```
### 7.2.2 LCS
#### LCS
LCS: longest common subsequence  
$X=x_1,x_2,\cdots,x_m$  
$Y=y_1,y_2,\cdots,y_n$  
$\mathbf{M}_{ij}=\begin{cases}\mathbf{M}_{i-1,j-1}+1\qquad\qquad\cdots x_i=y_j\\\max(\mathbf{M}_{i,j-1},\mathbf{M}_{i-1,j})\quad\cdots x_i\neq y_j\end{cases}$  
|||A|B|C|D|
|---|---|---|---|---|---|
| |0|0|0|0|0|
|B|0|0|**1**|1|1|
|D|0|0|1|1|**2**|
|E|0|0|1|1|2|

X: "BDE"  
Y: "ABCD"  
LCS: "BD"  
#### LCS
```C
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// lcs 길이 리턴, lcs 역추적 결과 char* p 저장
int lcs(char* x,char* y,char* p,int m,int n);

int main(void){
    char* x="GOOD_MORNING."; int m=strlen(x);
    char* y="GUTEN_MORGEN."; int n=strlen(y);
    char a[50]; // 최대 길이: 50
    char* p=&a[0];
    int   l; // length

    l=lcs(x,y,p,m,n);
    printf("lcs: %s\n",p);
    printf("length: %d\n",l);
}

int lcs(char* x,char* y,char* p,int m,int n){
    int j; // loop variable
    int k; // loop variable
    int d; // table value dummy
    int t[m+1][n+1];
    for(j=0;j<=m;j++){t[j][0]=0;}
    for(j=0;j<=n;j++){t[0][j]=0;}

    // 테이블 작성
    for(j=1;j<=m;j++){
        for(k=1;k<=n;k++){
            if(x[j-1]==y[k-1]){
                t[j][k]=t[j-1][k-1]+1;
            }
            else{
                if(t[j][k-1]>t[j-1][k]){t[j][k]=t[j][k-1];}
                else{                   t[j][k]=t[j-1][k];}
            }
        }
    }

    // 역추적 결과 저장: char* p
    for(j=0;j<t[m][n];j++){p++;}
    *p='\0'; p--;
    
    j=m; k=n;
    while((j>=1)&&(k>=1)){
        d=t[j][k];
        if((d>t[j-1][k-1])&&(d>t[j-1][k])&&(d>t[j][k-1])){*p=x[j-1]; p--; j--; k--;}
        else if((d==t[j][k-1])&&(d>t[j-1][k])){                                k--;}
        else{                                                             j--;     }
    }

    // lcs 길이 리턴
    return t[m][n];
}
```
```
$ ./test
lcs: G_MORN.
length: 7
```
### 7.2.3 LIS
#### LIS
LIS: longest increasing subsequence  
#### 이분 탐색 LIS
LIS 길이 작성 루프  
|a[j]|i|p|
|---|---|---|
|2|**-1**|{0}|
|1|0|{0,0}|
|4|**-1**|{0,0,1}|
|5|**-1**|{0,0,1,2}|
|3|1|{0,0,1,2,1}|

역추적 루프  
|p[j]|e|a[j]|q[j]|
|---|---|---|---|
|p[4]=1|2|a[4]=3||
|p[3]=2|2--|a[3]=5|**q[2]=5**|
|p[2]=1|1--|a[2]=4|**q[1]=4**|
|p[1]=0|0--|a[1]=1|**q[0]=1**|
|p[0]=0|-1 |a[0]=2||

```C
#include<stdio.h>

int main(void){
    int j; // loop variable
    int n=5;
    int a[5]={2,1,4,5,3};
    int t[5]; // tmp: LIS 길이 작성
    int p[5]; // position: 역추적
    int q[5]; // 역추적 결과 저장
    int s=0; // length
    int l;   // left
    int m;   // middle
    int r;   // right
    int i;   // location
    int e;   // end: 역추적
    
    // LIS 길이 작성
    for(j=0;j<n;j++){
        l=0;
        r=s-1;
        i=-1;
        while(l<=r){
            m=(l+r)/2;
            if(t[m]<a[j]){l=m+1;}
            else         {i=m; r=m-1;}
        }
        if(i==-1){p[j]=s; t[s++]=a[j];}
        else     {p[j]=i; t[i  ]=a[j];}
    }
    
    // 역추적
    e=s-1;
    for(j=n-1;j>=0;j--){
        if(p[j]==e){q[e--]=a[j];}
    }

    // 결과 출력
    printf("length: %d\nLIS: ",s);
    for(j=0;j<s;j++){printf("%d ",q[j]);}printf("\n");
}
```
```
$ ./test
length: 3
LIS: 1 4 5 
```
### 7.2.4 배낭(knapsack)
#### 0/1
```C
#include<stdio.h>

int knapsack(int* w,int* v,int n,int m);

int main(void){
    int n=5; // 물건 개수
    int m=7; // 최대 무게
    int w[6]={0,4,6,4,3,5};
    int v[6]={0,7,13,8,6,12};
    printf("%d",knapsack(&w[0],&v[0],n,m));
}

int knapsack(int* w,int* v,int n,int m){
    int j; int k; // loop variable
    int t[++n][++m];
    printf("weight\tvalue\n");
    for(j=0;j<n;j++){
        printf("%d\t%d\t",w[j],v[j]);
        for(k=0;k<m;k++){
            if(j==0||k==0){t[j][k]=0;} // 0행 및 0열 초기화
            else if(w[j]<=k){          // 물건이 배낭 용량 이하인 경우
                if((t[j-1][k])>(v[j]+t[j-1][k-w[j]])){t[j][k]=t[j-1][k];}
                else                                 {t[j][k]=v[j]+t[j-1][k-w[j]];}
            } 
            else                                     {t[j][k]=t[j-1][k];}
            printf("%d ", t[j][k]);
        }
        printf("\n");
    }
    return t[n-1][m-1];
}
```
```
$ ./test
weight  value
0       0       0 0 0 0 0 0 0 0 
4       7       0 0 0 0 7 7 7 7 
6       13      0 0 0 0 7 7 13 13 
4       8       0 0 0 0 8 8 13 13 
3       6       0 0 0 6 8 8 13 14 
5       12      0 0 0 6 8 12 13 14 
14
```
<!-- #### fracional -->
<!-- #### unbounded -->
<!-- #### bounded -->


## 7.3 Greedy
### 7.3.1 acitivity selection
#### activity selection
|ID/time|0|1|2|3|4|5|6|7|8|9|
|---|---|---|---|---|---|---|---|---|---|---|
|0      |o|o|o|o|-|-|-|-|-|-|
|**1**  |-|-|o|o|o|-|-|-|-|-|
|**2**  |-|o|o|-|-|-|-|-|-|-|
|**3**  |-|-|-|-|-|-|-|o|o|o|
|4      |-|-|-|o|o|o|o|-|-|-|
|**5**  |-|-|-|-|-|o|o|o|-|-|

```
$ ./test
activity id: 2  start: 1        end: 2
activity id: 1  start: 2        end: 4
activity id: 5  start: 5        end: 7
activity id: 3  start: 7        end: 9
```
```C
#include <stdio.h>
#include <stdlib.h>

struct activity{
    int i; // id
    int s; // start: 시작 시간
    int e; // end: 종료 시간
};

int compare(const void *u,const void *v); // qsort: 종료 시간 오름차순 정렬
void as(struct activity a[],int n); // as: activity selection

int main(void){
    int n=6;
    struct activity a[6];
    a[0].i=0; a[0].s=0; a[0].e=3;
    a[1].i=1; a[1].s=2; a[1].e=4;
    a[2].i=2; a[2].s=1; a[2].e=2;
    a[3].i=3; a[3].s=7; a[3].e=9;
    a[4].i=4; a[4].s=3; a[4].e=6;
    a[5].i=5; a[5].s=5; a[5].e=7;

    qsort(a,n,sizeof(struct activity),compare);
    as(a,n);
}

int compare(const void* u,const void* v){
    if((((struct activity*)u)->e)<(((struct activity*)v)->e)){return -1;}
    if((((struct activity*)u)->e)>(((struct activity*)v)->e)){return 1;}
    return 0;
}
void as(struct activity a[],int n){
    int j=0; // current activity
    int k; // loop variable
    
    printf("activity id: %d\tstart: %d\tend: %d\n",a[j].i,a[j].s,a[j].e);
    
    for(k=1;k<n;k++){
        if(a[k].s>=a[j].e){
            j=k;
            printf("activity id: %d\tstart: %d\tend: %d\n",a[j].i,a[j].s,a[j].e);
        }
    }
}
```
### 7.3.2 동전 개수
#### 동전 개수 최소화: 그리디
```C
#include<stdio.h>

#define N 8 // number of element
int c[8]={5000,1000,500,100,50,10,5,1};

int coins(int v);

int main(void){
    int v=4790;
    printf("value: %d\n",v);
    printf("number of coins: %d\n",coins(v));
}

int coins(int v){
    int j;   // loop variable 
    int a=0; // answer: number of coins
    for(j=0;j<N;j++){
        if(v==0){break;}
        if(c[j]<=v){
            a+=(v/c[j]);
            v%=c[j];
        }
    }
    return a;
}
```
```
$ ./test
value: 4790
number of coins: 12
# 1000*4
# 500 *1
# 100 *2
# 50  *1
# 10  *4
```
#### 동전 개수 최소화: DP
배수 관계가 아님: 부르트포스 또는 DP 접근  
