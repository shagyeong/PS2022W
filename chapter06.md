# 6장 수학
## 6.1 정수론
### 6.1.1 소수판정
#### 로그시간 정수제곱근
```C
#include<stdio.h>

int square(int n);

int main(void){
    int n; scanf("%d",&n);
    printf("sqrt(%d): %d",n,square(n));
}

int square(int n){
    if(n==1){return 1;}
    int a=0; // answer
    int l=1; // left
    int m;
    int r=n; // right
    while(l<=r){
        m=l+(r-l)/2;
        if((m*m)<=n){l=m+1; a=m;} // 오버플로우 발생시 m<=n/m
        else        {r=m-1;}
    }
    return a;
}
```
```
$ ./test
10
sqrt(10): 3

$ ./test
16
sqrt(16): 4
```
#### 소수 판정
```C
#include<stdio.h>

void sieve(int n);
int square(int n);

int main(void){
    int n; scanf("%d",&n);
    sieve(n);
}

void sieve(int n){
    int j;
    int s=square(n)+1;
    for(j=2;j<=s;j++){if(n%j==0){printf("%d: NO",n); return;}}
    printf("%d: YES",n); return;
}
int square(int n){
    if(n==1){return 1;}
    int a=0; // answer
    int l=1; // left
    int m;
    int r=n; // right
    while(l<=r){
        m=l+(r-l)/2;
        if((m*m)<=n){l=m+1; a=m;}
        else        {r=m-1;}
    }
    return a;
}
```
```
$ ./test
23
23: YES

$ ./test
49
49: NO
```
#### 에라토스테네스의 체
```C
#include<stdio.h>
#include<stdlib.h>

void sieve(int n);
int square(int n);

int main(void){
    int n; scanf("%d",&n);
    sieve(n);
}

void sieve(int n){
    int j;
    int p;
    int s=square(n)+1;
    int* a=(int*)malloc(sizeof(int)*(n+1));
    for(j=0;j<=n;j++){a[j]=1;}

    // sieve
    for(p=2;p<=s;p++){
        if(a[p]==0){continue;}
        else{for(j=p*p;j<=n;j+=p){a[j]=0;}}
    }

    // 결과 출력
    for(j=2;j<=n;j++){if(a[j]==1){printf("%d ",j);}}
}
int square(int n){
    if(n==1){return 1;}
    int a=0; // answer
    int l=1; // left
    int m;
    int r=n; // right
    while(l<=r){
        m=l+(r-l)/2;
        if((m*m)<=n){l=m+1; a=m;}
        else        {r=m-1;}
    }
    return a;
}
```
```
$ ./test
23
2 3 5 7 11 13 17 19 23 
```
#### 큰 수 소수 판정: 밀러-라빈
부호없는 64비트 정수 소수 판정  
```C
#include<stdio.h>

unsigned long long int power(
    unsigned long long int b,
    unsigned long long int e,
    unsigned long long int q
);
int mr( // Miller-Rabin
    unsigned long long int n
);

int main(void){
    unsigned long long int n=1;
    printf("mr(%lld): %d\n",n,mr(n));
}

unsigned long long int power(unsigned long long int b,unsigned long long int e,unsigned long long int q){
    unsigned long long int r = 1; // return value
    b%=q;
    while(e>0){
        if(e%2==1){r=(unsigned long long int)(((__int128)r*b)%q);}
        b=           (unsigned long long int)(((__int128)b*b)%q);
        e/=2;
    }
    return r;
}
int mr(unsigned long long int n){
    if(n==2||n==3)  {return 1;}
    if(n==1||n%2==0){return 0;}
    unsigned long long int a[12]={2,3,5,7,11,13,17,19,23,29,31,37};
    unsigned long long int d=n-1;
    unsigned long long int x;
    int                    s=0;
    int                    j; // loop variable
    int                    k; // loop variable
    int                    f; // prime flag

    while(d%2==0){d/=2;s++;} 
    for(j=0;j<12;j++){
        if(n<=a[j]){break;}
        x=power(a[j],d,n);
        if((x==1)||(x==n-1)){continue;}
        f=0;
        for(k=1;k<s;k++){
            x=(unsigned long long int)(((__int128)x*x)%n);
            if(x==n-1){f=1;break;}
        }
        if(f==0){return 0;}
    }
    return 1;
}
```
```
 ./test
mr(1): 0
```
### 6.1.2 유클리드호제법
#### 유클리드 호제법
GCD: greates common divisor - 최대공약수  
$A>B$인 두 수에 대하여  
$\mathrm{GCD}(A,B)$: $A=Bq+r$  
$r\neq0$  
$A'\leftarrow B$  
$B'\leftarrow r$  
$\mathrm{GCD}(A',B')$    
$r=0$  
$\mathrm{GCD}(A,B)=B$  
#### LCM
LCM: least common multiple - 최소공배수  
$\mathrm{LCM}=A\times B\div \mathrm{GCD}(A,B)$  
#### 유클리드 호제법
```C
#include<stdio.h>

void euclid(int u,int v);

int main(void){
    int u; int v; scanf("%d %d",&u,&v);
    euclid(u,v);
}

void euclid(int u,int v){
    int a=u;
    int b=v;
    int t;
    while(a%b!=0){t=a;a=b;b=t%b;}
    printf("GCD: %d\n",b);
    printf("LCM: %d\n",u*v/b);
}
```
```
$ ./test
24 18
GCD: 6
LCM: 72
```
### 6.1.3 소인수분해
#### 소인수분해
```C
#include<stdio.h>
#include<stdlib.h>

void factorize(int n);

int main(void){
    int n; scanf("%d",&n);
    factorize(n);
}

void factorize(int n){
    int j;
    int s=1; while(s*s<=n){s++;}
    int d=n; // dummy
    int e; // 소인수 차수
    for(j=2;j<=s;j++){
        e=0;
        while(d%j==0){d/=j; e+=1;}
        if(e!=0){printf("(%d^%d)",j,e);}
    }
    if(d>1){printf("(%d^1)",d);}
}
```
```
$ ./test
120
(2^3)(3^1)(5^1)

$ ./test
23
(23^1)
```
#### 오일러 Φ 함수
오일러피함수: $n$에대해 $1$~$n$의 자연수 중 서로소 개수 리턴  
$\phi(n)=|\{k\in\mathbb{Z}|1\leq k\leq n,\gcd(n,k)=1\}|$  
$\phi(n)=n\times\displaystyle\prod_{i=1}^m(1-{{1}\over{p_i}})$  
$p_i$: $n$의 $i$번째 소인수  
```C
#include<stdio.h>
#include<math.h>

int main(void){
    long long int r; // result: phi(n)
    long long int j; // loop variable
    long long int p; // prime number
    long long int n;
    long long int q; // quotient
    long long int s=0; // sqrt(n)+1

    scanf("%lld",&n);
    while(s*s<=n){s++;}

    long long int a[s+1];
    for(j=0;j<=s;j++){a[j]=j;}
    for(p=2;p<=s;p++){
        if(a[p]!=p)              {continue;}
        else{for(j=p*p;j<=s;j+=p){a[j]=0;}} // 합성수 마크
    }

    r=n; q=n;
    for(j=2;j<=s;j++){
        if((a[j]!=0)&&(q%a[j]==0)){
            r-=r/a[j];
            while(q%a[j]==0){q/=a[j];}
        }
    }
    if(q>1){r-=(r/q);}
    printf("%lld",r);
}
```
```
$ ./test
100
40
```
#### 큰 수 소인수분해: 폴라드 로
```C
#include<stdio.h>
#include<stdlib.h> // rand(),qsort()

unsigned long long int p[64]; // 소인수
int t;

unsigned long long int power(
    unsigned long long int b,
    unsigned long long int e,
    unsigned long long int q
);
unsigned long long int gcd(
    unsigned long long int a,
    unsigned long long int b
);
int mr( // Miller-Rabin
    unsigned long long int n
);
void pr( // Phollard's rho
    unsigned long long int n
);

int main(void){
    int j;
    unsigned long long int n; scanf("%lld",&n);
    t=0; pr(n);
    for(j=0;j<t;j++){printf("%lld ",p[j]);}
}

unsigned long long int power(unsigned long long int b,unsigned long long int e,unsigned long long int q){
    unsigned long long int r = 1; // return value
    b%=q;
    while(e>0){
        if(e%2==1){r=(unsigned long long int)(((__int128)r*b)%q);}
        b=           (unsigned long long int)(((__int128)b*b)%q);
        e/=2;
    }
    return r;
}
unsigned long long int gcd(unsigned long long int a,unsigned long long int b){
    unsigned long long int t; // tmp
    while(b!=0){a%=b;t=a;a=b;b=t;}
    return a;
}
int mr(unsigned long long int n){
    if(n==2||n==3)  {return 1;}
    if(n==1||n%2==0){return 0;}
    unsigned long long int a[12]={2,3,5,7,11,13,17,19,23,29,31,37};
    unsigned long long int d=n-1;
    unsigned long long int x;
    int                    s=0;
    int                    j; // loop variable
    int                    k; // loop variable
    int                    f; // prime flag

    while(d%2==0){d/=2;s++;} 
    for(j=0;j<12;j++){
        if(n<=a[j]){break;}
        x=power(a[j],d,n);
        if((x==1)||(x==n-1)){continue;}
        f=0;
        for(k=1;k<s;k++){
            x=(unsigned long long int)(((__int128)x*x)%n);
            if(x==n-1){f=1;break;}
        }
        if(f==0){return 0;}
    }
    return 1;
}
void pr(unsigned long long int n){
    if(n==1) {return;}
    if(mr(n)){p[t++]=n; return;}
    if(n%2==0){
        p[t++]=2;
        pr(n/2);
        return;
    }

    unsigned long long int x;
    unsigned long long int y;
    unsigned long long int c;
    unsigned long long int g;
    unsigned long long int d;

    x=rand()%(n-2)+2;
    y=x;
    c=rand()%(n-1)+1;
    g=1;
    
    while(g==1){
        x=(unsigned long long int)(((__int128)x*x+c)%n);
        y=(unsigned long long int)(((__int128)y*y+c)%n);
        y=(unsigned long long int)(((__int128)y*y+c)%n);
        d=(x>y)?x-y:y-x;
        g=gcd(d,n);
        if(g==n){
            pr(n);
            return;
        }
    }

    pr(g);
    pr(n/g);
}
```
```
$ ./test
24
2 2 2 3 
```
#### 오일러 Φ 함수: 큰 수
폴라드 로 확장  
main()  
```C
int main(void){
    unsigned long long int n; scanf("%llu",&n);
    t=0; pr(n);
    phi(n);
}
```
phi(): 전역 소인수 배열(p) 조작  
```
void phi(unsigned long long int n){
    int j; // loop variable
    unsigned long long int r; // rsult: phi(n)
    unsigned long long int q; /// quotient
    r=n; q=n;
    for(j=0;j<t;j++){
        if(q%p[j]==0){
            r-=r/p[j];
            while(q%p[j]==0){q/=p[j];}
        }
    }
    if(q>1){r-=(r/q);}
    printf("%llu",r);
}
```
```
$ ./test
100
40
```
### 6.1.4 모듈로 곱셈 역원
#### 모듈로 곱셈 역원
$\mod(n\times i,d)\equiv 1$  
$n$: 피제수  
$d$: 제수  
$i$: 모듈로 곱셈 역원  
$\gcd(n,d)=1$(서로소)일 때 역원이 존재한다  
#### 예제: 모듈로 곱셈 역원
$\mod(2\times4,7)\equiv1$  
$\mod((100\div2),7)\equiv\mod(100\times4,7)$  
#### 페르마 소정리
제수$d$가 소수인 경우만 사용 가능  
$i=\mod(n^{d-2},d)$  
분할정복거듭제곱 등으로 최적화 가능  
```C
int inverse(int n,int d){
    int j;
    int i=1; // inverse
    for(j=0;j<d-2;j++){
        i*=(n%d);
        i%=d;
    }
    return i;
}
```
#### 확장 유클리드 호제법
```C
int inverse(int n,int d){
    int a=d;
    int b=n;
    int h=0; // 이전 단계
    int i=1;
    int t;
    while(a%b!=0){
        t=h-(a/b)*i;
        h=i;
        i=t;
        t=a; a=b; b=t%b; // 유클리드 호제법
    }
    if(i<0){i+=d;}
    return i;
}
```



## 6.2 선형대수
### 6.2.2 선형시스템 해 구성
#### 가우스 소거법
```C
#include <stdio.h>

int main(void){
    long long int j; // loop variable
    long long int k; // loop variable
    long long int l; // loop variable
    long long int n;
    long long int r; // 행 교환 인덱스
    long long int t; // 행 교환 tmp
    long long int p=1; // 피벗: 오버플로우 방지
    scanf("%lld",&n);
    long long int m[n][n+1];
    long long int s[n]; // solution 열벡터
    for(j=0;j<n;j++){
        for(k=0;k<n+1;k++){
            scanf("%lld",&m[j][k]);
        }
    }

    // 전향소거법: 실수 연산 불확실성 제거
    for(j=0;j<n;j++){
        r=j;
        if(m[j][j]==0){ // 대각선 성분 확인: 행 교환 위치 설정
            r=j+1;
            for(k=j+1;k<n;k++){
                if(m[k][j]!=0){break;}
                else          {r++;}
            }
        }
        if(r!=j){    // 행교환
            for(l=0;l<=n;l++){
                t=m[j][l];
                m[j][l]=m[r][l];
                m[r][l]=t;
            }
        }
        for(k=j+1;k<n;k++){
            for(l=n;l>=j;l--){
                m[k][l]=(m[k][l]*m[j][j])-(m[j][l]*m[k][j]);
                m[k][l]/=p;
            }
        }
        p=m[j][j];
    }

    // 후방대입법
    for(j=n-1;j>=0;j--){
        s[j]=m[j][n];
        for(k=j+1;k<n;k++){s[j]-=m[j][k]*s[k];}
        s[j]=s[j]/m[j][j];
    }
    
    // 해 출력
    for(j=0;j<n;j++){printf("%lld ",s[j]);}
}
```
```
$ ./test
6
6 5 4 2 5 3 244
4 1 2 6 9 4 253
6 1 8 6 1 8 305
4 5 4 7 3 2 263
1 10 4 7 4 4 312
1 7 10 1 4 6 230
14 12 2 14 5 13 # solution
```



## 6.3 기하
### 6.3.1 선분 교차
#### CCW
CCW: counter-clockwise  
선분 - 점의 위치 판별
#### 선분 교차 판정
```C
#include <stdio.h>

struct dot{
    int x;
    int y;
};
int ccw(struct dot A,struct dot B,struct dot C);
int intersect(struct dot A,struct dot B,struct dot C,struct dot D);

int main() {
    struct dot A={1, 1};  struct dot B={5, 5};
    struct dot C={1, 5};  struct dot D={5, 1};
    struct dot E={10,10}; struct dot F={15,15};

    printf("AB-CD: %d\n",intersect(A,B,C,D));
    printf("AB-EF: %d\n",intersect(A,B,E,F));
}

int ccw(struct dot A,struct dot B,struct dot C){
    long long int op=0; // outer product: 외적
    op=op+(long long int)A.x*B.y-A.y*B.x;
    op=op+(long long int)B.x*C.y-B.y*C.x;
    op=op+(long long int)C.x*A.y-C.y*A.x;
    if(op>0){return 1;}  // counter-clockwise
    if(op<0){return -1;} // clockwise
             return 0;   // 일직선
}
int intersect(struct dot A,struct dot B,struct dot C,struct dot D){
    int ABC=ccw(A,B,C);
    int ABD=ccw(A,B,D);
    int CDA=ccw(C,D,A);
    int CDB=ccw(C,D,B);

    if((ABC*ABD>0)||(CDA*CDB>0)){
        return 0;
    }
    else{
        if((ABC*ABD!=0)||(CDA*CDB!=0)){
            return 1;
        }
        else{
            int ABX_MIN=(A.x<B.x)?A.x:B.x;
            int ABX_MAX=(A.x>B.x)?A.x:B.x;
            int CDX_MIN=(C.x<D.x)?C.x:D.x;
            int CDX_MAX=(C.x>D.x)?C.x:D.x;
            int ABY_MIN=(A.y<B.y)?A.y:B.y;
            int ABY_MAX=(A.y>B.y)?A.y:B.y;
            int CDY_MIN=(C.y<D.y)?C.y:D.y;
            int CDY_MAX=(C.y>D.y)?C.y:D.y;
            return (ABX_MIN<=CDX_MAX)&&(CDX_MIN<=ABX_MAX)&&(ABY_MIN<=CDY_MAX)&&(CDY_MIN<=ABY_MAX);
        }
    }
}
```
```
$ ./test
AB-CD: 1 # 교차함
AB-EF: 0 # 교차하지 않음
```
### 6.3.2 면적
#### 면적: convex hull
```C
#include<stdio.h>
#include<stdlib.h>

struct polygon{
    int d; // number of dot(polygon)
    int h; // number of dot(hull)
    struct dot* dots;
    struct dot* hull;
};
struct dot{
    int x;
    int y;
};

int compare(const void* u,const void* v);
int ccw(struct dot A,struct dot B,struct dot C); // counter-clockwise
void   mc(struct polygon* p); // monotone chain
void area(struct  polygon*p); // area of polygon

int main(void){
    int d=7; // number of dot
    struct dot dots[7]={{0,3},{2,2},{1,1},{2,1},{3,0},{0,0},{3,3}};
    struct polygon p;
    p.d=d;
    p.h=0;
    p.dots=&dots[0];
    p.hull=NULL;
    mc(&p);
    area(&p);
}

int compare(const void* u,const void* v){
    if((((struct dot*)u)->x)< (((struct dot*)v)->x)){return -1;}
    if((((struct dot*)u)->x)> (((struct dot*)v)->x)){return  1;}
    if((((struct dot*)u)->x)==(((struct dot*)v)->x)){
        if((((struct dot*)u)->y)< (((struct dot*)v)->y)){return -1;}
        if((((struct dot*)u)->y)> (((struct dot*)v)->y)){return  1;}
    }
    return 0;
}
int ccw(struct dot A,struct dot B,struct dot C){
    long long int op=0;
    op=op+(long long int)A.x*B.y-A.y*B.x;
    op=op+(long long int)B.x*C.y-B.y*C.x;
    op=op+(long long int)C.x*A.y-C.y*A.x;
    if(op>0)return 1;
    if(op<0)return -1;
    return 0;
}
void mc(struct polygon* p){
    int j; // loop variable
    int k; // loop variable
    p->h=0;
    p->hull=(struct dot*)malloc(sizeof(struct dot)*2*(p->d));
    qsort(p->dots,p->d,sizeof(struct dot),compare);    
    
    // lower hull
    for(j=0;j<p->d;j++){
        while(p->h>=2&&ccw(p->hull[p->h-2],p->hull[p->h-1],p->dots[j])<=0){p->h--;}
        p->hull[p->h++]=p->dots[j];
    }
    
    // upper hull
    k=p->h+1;
    for(j=p->d-2;j>=0;j--){
        while(p->h>=k&&ccw(p->hull[p->h-2],p->hull[p->h-1],p->dots[j])<=0){p->h--;}
        p->hull[p->h++]=p->dots[j];
    }
    p->h--;
}
void area(struct  polygon* p){
    int a=0; // area
    int j;
    for(j=0;j<p->h-1;j++){
        a+=(p->hull[j].x*p->hull[j+1].y);
        a-=(p->hull[j].y*p->hull[j+1].x);
    }
    a+=(p->hull[j].x*p->hull[0].y);
    a-=(p->hull[j].y*p->hull[0].x);
    a=(a>0)?a:-a;
    printf("%.1f",((double)a)/2);
}
```
```
$ ./test
9.0
```
```
5
4
3 * - - *
2 |   * |
1 | * * |
0 * - - *
  0 1 2 3 4 5
```
