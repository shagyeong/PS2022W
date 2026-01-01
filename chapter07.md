# 7장 기타 과제 유형
<!-- ## 7.1 재귀 -->



## 7.2 분할 정복
<!-- ### 7.2.1 병합 정렬 -->
### 7.2.2 거듭제곱 계산
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
### 7.2.3 피보나치 수
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



## 7.3 DP
### 7.3.1 피보나치 수: DP
#### 피보나치 수: DP
연산 횟수: $n$회  
```C
#include<stdio.h>

unsigned int fib(unsigned int n);

int main(void){
    unsigned int n=0;
    for(n=0;n<15;n++){printf("fib(%u)=%u\n",n,fib(n));}
}

unsigned int fib(unsigned int n){
    unsigned int j; // loop variable
    unsigned int t[20];
    t[0]=0;
    t[1]=1;
    if(n==0||n==1){return t[n];}
    for(j=0;j<n-1;j++){t[j+2]=t[j]+t[j+1];}return t[n];
}
```
```
$ ./test
fib(0)=0    fib(1)=1    fib(2)=1    fib(3)=2    fib(4)=3
fib(5)=5    fib(6)=8    fib(7)=13   fib(8)=21   fib(9)=34
fib(10)=55  fib(11)=89  fib(12)=144 fib(13)=233 fib(14)=377
```
### 7.3.2 LCS
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



<!-- ## 7.4 그리디 -->
<!-- ## 7.5 백트래킹 -->
