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



<!-- ## 7.3 DP -->
<!-- ## 7.4 그리디 -->
<!-- ## 7.5 백트래킹 -->
