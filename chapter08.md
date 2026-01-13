# 8장 수학
## 8.1 정수론
### 8.1.1 소수 판정
#### 소수 판정
```C
#include<stdio.h>

void sieve(int n,int s);

int main(void){
    sieve(23,5);
    sieve(49,8);
}

void sieve(int n,int s){
    int j;
    for(j=2;j<=s;j++){
        if(n%j==0){
            printf("%d: not a prime number\n",n);
            return;
        }
    }
    printf("%d: prime number\n",n);
}
```
```
$ ./test
23: prime number
49: not a prime number
```
#### 에라토스테네스의 체
```C
#include<stdio.h>

int main(void){
    unsigned char j; // loop variable
    unsigned char n=100;
    unsigned char s=11; // sqrt(100)+1
    unsigned char p;  // prime number
    unsigned char a[101];
    for(j=0;j<=100;j++){a[j]=j;}
    for(p=2;p<=s;p++){
        if(a[p]!=p)              {continue;}
        else{for(j=p*p;j<=n;j+=p){a[j]=0;}}
    }
    for(j=2;j<=100;j++){if(a[j]!=0){printf("%d ",a[j]);}}
    printf("\n");
}
```
```
$ ./test
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97
```
<!-- #### 소인수분해 -->
<!-- #### 큰 수 소인수분해: 폴라드 로 -->
### 8.1.2 유클리드 호제법
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

int main(void){
    unsigned int A;
    unsigned int B;
    unsigned int a;
    unsigned int b;
    unsigned int t; // tmp
    A=24; B=18;
    a=A;
    b=B;
    while(a%b!=0){
        t=a;
        a=b;
        b=t%b;
    }
    printf("GCD: %u\n",b);
    printf("LCM: %u\n",A*B/b);
}
```
```
$ ./test
GCD: 6
LCM: 72
```



## 8.2 선형대수
<!-- ### 8.2.1 행렬 연산 -->
### 8.2.2 선형시스템 해 구성
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
<!-- #### LU분해 -->



## 8.3 기하
### 8.3.1 선분 교차 판정
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
### 8.3.2 면적
<!-- #### 면적: 다각형 -->
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
