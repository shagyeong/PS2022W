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

int main(int argc,char** argv){
    int j;
    char* a[3];
    for(j=1;j<argc;j++){a[j-1]=argv[j];}
    for(j=1;j<argc;j++){printf("%s\n",a[j-1]);}
}
```
```
$ ./test Kim Lee Park
Kim
Lee
Park
```
#### 문자 포인터 배열을 이용한 가변길이 문자열 처리: 표준입력 및 동적할당
```C
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j=0; // loop variable
    int n=3; // number of item
    char* a[3];
    for(j=0;j<n;j++){
        a[j]=(char*)malloc(sizeof(char)*20);
        scanf("%s",a[j]);
    }
    for(j=0;j<n;j++){
        printf("%s\n",a[j]);
        free(a[j]);
    }
} 
```
```
$ ./test
Kim
Lee
Park
Kim
Lee
Park
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
#### 메모리 초기화: 1바이트 자료형
```C
#include<stdio.h>
#include<string.h>

int main(void){
    int j;
    int n=3; // number of item
    char a[3];
    
    memset(&a[0],0b00000000,sizeof(char)*n);
    for(j=0;j<n;j++){printf("%d ",a[j]);}
}
```
```
$ ./test
0 0 0 
```
#### 메모리 초기화: 1바이트를 초과하는 자료형
int: 4바이트 정수  
$16843009_{10}=0000\ 0001\ 0000\ 0001\ 0000\ 0001\ 0000\ 0001\ 0000\ 0001_2$  
```C
#include<stdio.h>
#include<string.h>

int main(void){
    int j;
    int n=3; // number of item

    int a[3]; memset(&a[0],0b00000000,sizeof(int)*n);
    int b[3]; memset(&b[0],0b00000001,sizeof(int)*n);
    for(j=0;j<n;j++){printf("%d ",a[j]);}printf("\n");
    for(j=0;j<n;j++){printf("%d ",b[j]);}printf("\n");
}
```
```
$ ./test
0 0 0 
16843009 16843009 16843009 
```
### 1.2.3 동적할당
#### 동적 할당 및 해제: malloc(),free()
```C
#include <stdlib.h>
void* malloc(size_t size);
void  free(void *ptr);
```
#### 동적할당의 목적: 가변길이 처리
물리적으로 연속된 공간에 가변길이 데이터 할당시 시프트 소요 발생  
랜덤 지정 할당 후 포인팅  
포인터를 연속된 공간에 저장  
예제: 1.1.3과 같음  
```C
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j=0; // loop variable
    int n=3; // number of item
    char* a[3];
    for(j=0;j<n;j++){
        a[j]=(char*)malloc(sizeof(char)*20);
        scanf("%s",a[j]);
    }
    for(j=0;j<n;j++){
        printf("%s\n",a[j]);
        free(a[j]);
    }
} 
```
```
$ ./test
Kim
Lee
Park
Kim
Lee
Park
```
#### 동적할당의 목적: 힙 영역 활용
함수(main() 외부)가 DS를 조작해도 데이터 유지됨  
```C
#include<stdio.h>
#include<stdlib.h>

struct list{
    int n;          // number of item
    struct node* h; // head
};
struct node{
    int v;
    struct node* next;
};

void insert(struct list* l,int v);
void  clean(struct list* l);

int main(void){
    struct list l;
    l.n=0;
    l.h=(struct node*)malloc(sizeof(struct node));
    l.h->v=-1;
    l.h->next=NULL;
    insert(&l,0);
    insert(&l,1);
    insert(&l,2);
    clean(&l);
    free(l.h);
}

void insert(struct list* l,int v){
    struct node* b=l->h;
    while(b->next!=NULL){b=b->next;}
    b->next=(struct node*)malloc(sizeof(struct node));
    b->next->v=v;
    b->next->next=NULL;
    l->n+=1;
}
void  clean(struct list* l){
    int j;
    struct node* b=l->h->next;
    struct node* f;
    for(j=0;j<l->n;j++){
        f=b; printf("free: %d\n",f->v);
        b=b->next;
        free(f);
    }
    l->h->next=NULL;
    l->n=0;
}
```
```
$ ./test
free: 0
free: 1
free: 2
```
