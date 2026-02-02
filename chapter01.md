# 1장 C for Problem Solving
## 1.1 표준입출력
### 1.1.1 정수
#### 정수
```C
#include<stdio.h>

int main(void){
    char          c;  unsigned char          uc;
    short         s;  unsigned short         us;
    int           i;  unsigned int           ui;
    long int      l;  unsigned long int      ul;
    long long int ll; unsigned long long int ull;
    scanf("%hhd",&c);    scanf("%hhu",&uc);
    scanf("%hd", &s);    scanf("%hu", &us);
    scanf("%d",  &i);    scanf("%u",  &ui);
    scanf("%ld", &l);    scanf("%lu", &ul);
    scanf("%lld",&ll);   scanf("%llu",&ull);
}
```
### 1.1.2 문자
#### 문자
```C
#include<stdio.h>

int main(void){
    char c;
    scanf("%c",&c); printf("%c",c);
}
```
### 1.1.3 문자열
#### 단일 문자열 조작: 문자 배열
```C
#include<stdio.h>

int main(void){
    char s[20];
    scanf("%s",s); printf("%s",s);
}
```
#### 단일 문자열 조작: 문자 포인터
```C
#include<stdio.h>
#include<stdlib.h>

int main(void){
    char s[20];
    char* p=&s[0];
    scanf("%s",p); printf("%s",s);
}
```
#### 문자 포인터 배열을 이용한 가변길이 문자열 처리: 명령행 인자
```C
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char** argv){
    int j;
    char** a=(char**)malloc(sizeof(char*)*(argc-1));
    for(j=0;j<argc-1;j++){a[j]=argv[j+1];}
    for(j=0;j<argc-1;j++){printf("%s ",a[j]);}
    free(a);
}
```
```
$ ./test Kim Lee Park
Kim Lee Park 
```
#### 문자 포인터 배열을 이용한 가변길이 문자열 처리: 표준입력 및 동적할당
```C
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j;
    int n; scanf("%d",&n);
    int l; scanf("%d",&l);// 문자열 최대 길이
    char** a=(char**)malloc(sizeof(char*)*n);
    char*  d=(char*) malloc(sizeof(char) *n*l);
    for(j=0;j<n;j++){a[j]=d+(j*l);} // 포인팅

    for(j=0;j<n;j++){scanf("%s",a[j]);}
    for(j=0;j<n;j++){printf("%s ",a[j]);}

    free(d);
    free(a);
}
```
```
$ ./test
3 20
Kim Lee Park
Kim Lee Park 
```



## 1.2 메모리
### 1.2.1 포인터
#### 단일 변수 역참조
```C
#include<stdio.h>

int main(void){
    int   i=0;
    int* p=&i;
    printf("%d\n",*p);
}
```
#### 배열 역참조
```C
#include<stdio.h>

int main(void){
    int  a[3]={0,1,2};
    int* p=&a[0];
    printf("%d\n",*p);
    printf("%d\n",*(p+1));
    printf("%d\n",*(p+2));
}
```
### 1.2.2 메모리 초기화: memset()
#### memset()
```C
#include<string.h>
void* memset(void* s,int c,size_t n);
```
#### 메모리 초기화: 1바이트를 초과하는 자료형
```C
#include<stdio.h>
#include<string.h>

int main(void){
    char a[1];
    int  b[1];
    memset(&a[0],0b00000001,sizeof(char)*1);
    memset(&b[0],0b00000001,sizeof(int) *1);
    printf("%d\n",a[0]);
    printf("%d\n",b[0]);
}
```
```
$ ./test
1
16843009
```
char(1바이트): $ 1_{10}=0000\ 0001$  
int(4바이트): $16843009_{10}=0000\ 0001\ 0000\ 0001\ 0000\ 0001\ 0000\ 0001\ 0000\ 0001_2$  
### 1.2.3 동적할당
#### 동적 할당 및 해제: malloc(),free()
```C
#include <stdlib.h>
void* malloc(size_t size);
void  free(void *ptr);
```
#### 이차원 배열 동적할당
```C
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j; int k;
    int r; int c; scanf("%d %d",&r,&c);
    int** a=(int**)malloc(sizeof(int*)*r);
    int*  d=(int*) malloc(sizeof(int) *r*c);
    for(j=0;j<r;j++){a[j]=d+(j*c);} // 포인팅

    for(j=0;j<r;j++){for(k=0;k<c;k++){scanf("%d",&a[j][k]);}}
    for(j=0;j<r;j++){for(k=0;k<c;k++){printf("%d ",a[j][k]);}printf("\n");}

    free(d);
    free(a);
}
```
```
$ ./test
2 3
1 2 3
4 5 6
1 2 3 
4 5 6 
```
#### 동적 할당 활용 목적
가변길이 대응: 문자열 포인터 배열등
힙 영역 활용: 함수 리턴과 독립적인 전역 데이터 유지 - 인접리스트, 세그먼트 트리, ...  
힙 영역 활용: 큰 문제 공간으로 인한 스택 오버플로우 방지  
