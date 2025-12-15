# 1장 C for Problem Solving
## 1.1 배열
### 1.1.1 배열
#### 메모리 할당량 확인(sizeof())
sizeof(): 변수에 할당된 바이트 수(long unsgiend int(%ld)) 리턴  
```C
#include<stdio.h>

int main(void){
    unsigned char c=0;
    unsigned char a[3]={0,1,2};
    printf("size of char:      %ld bytes\n",sizeof(c));
    printf("size of char array:%ld bytes\n",sizeof(a));
}
```
```
$ ./test
size of char:      1 bytes
size of char array:3 bytes
```
#### 문자 배열
```C
#include<stdio.h>

int main(void){
    char a[4]="abc\0";
    char b[4]={'d','e','f','\0'};
    printf("char array a: %s\t",a); printf("size: %ld\n",sizeof(a));
    printf("char array b: %s\t",b); printf("size: %ld\n",sizeof(b));
}
```
```
$ ./test
char array a: abc   size: 4
char array b: def   size: 4
```
#### 배열 초기화: 표준 입력
```C
#include<stdio.h>

int main(void){
    // 변수 초기화
    unsigned char c;
    scanf("%hhu",&c);
    printf("c: %u\n",c);

    // 숫자 배열 초기화
    unsigned char i;
    unsigned char N=3;
    unsigned char a[N];
    for(i=0;i<N;i++){scanf("%hhu",&a[i]);}
    for(i=0;i<N;i++){printf("a[%u]: %u\n",i,a[i]);}

    // 문자 배열 초기화
    char s[3];
    scanf("%s",s);
    printf("s: %s\n",s);
}
```
```
$ ./test
# 변수 초기화
1
c: 1
# 숫자 배열 초기화
1
2
3
a[0]: 1
a[1]: 2
a[2]: 3
# 문자 배열 초기화
abc
s: abc
```
### 1.1.2 문자 배열과 포인터
#### 문자 배열과 포인터
```C
#include<stdio.h>

int main(void){
    char s[4]="abc\0";
    char* p;
    p=s; // 동치 문장: p=&s[0];
    printf("%c\n",*p);
    printf("%c\n",*(++p));
    printf("%c\n",*(++p));
}
```
```
$ ./test
a
b
c
```
#### 포인터 배열
포인터 배열  
```C
#include<stdio.h>

int main(void){
    unsigned char i;
    char s1[4]="Joe\0";     char* p1=s1;
    char s2[7]="Oliver\0";  char* p2=s2;
    char s3[5]="Liam\0";    char* p3=s3;
    char s4[9]="Benjamin\0";char* p4=s4;
    char* p[4]={p1,p2,p3,p4};
    for(i=0;i<4;i++){printf("%s\n",p[i]);}
}
```
```
$ ./test
Joe
Oliver
Liam
Benjamin
```
이중 포인터: 명령행 인자  
```C
#include<stdio.h>

int main(int argc, char** argv){
    unsigned char i;
    for(i=1;i<argc;i++){printf("%s\n",argv[i]);}
}
```
```
$ ./test Joe Oliver Liam Benjamin
Joe
Oliver
Liam
Benjamin
```



## 1.2 구조체
### 1.2.1 구조체
#### 구조체 포인터
```C
#include<stdio.h>
#include<string.h>

struct student{
    char name[20];
    unsigned char id;
};

int main(void){
    struct student K; struct student* Kim=&K;
    struct student L; struct student* Lee=&L;
    strcpy(Kim->name,"Kim"); Kim->id=222;
    strcpy(Lee->name,"Lee"); Lee->id=223;
    printf("%s: %u\n",Kim->name,Kim->id);
    printf("%s: %u\n",Lee->name,Lee->id);
}
```
```
$ ./test
Kim: 222
Lee: 223
```
#### 익명 객체 생성: malloc()
```C
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    char name[20];
    unsigned char id;
};

int main(void){
    int i;
    int n; scanf("%d",&n);
    struct student* class[n];
    
    char          buffer_name[20];
    unsigned char buffer_id;

    for(i=0;i<n;i++){
        class[i]=(struct student*)malloc(sizeof(struct student));
        scanf("%s %hhu",buffer_name,&buffer_id);
        strcpy(class[i]->name,buffer_name);
        class[i]->id=buffer_id;
    }

    printf("name\tid\n");
    for(i=0;i<n;i++){
        printf("%s\t%u\n",class[i]->name,class[i]->id);
    }
}
```
```
$ ./test
3
Kim 232
Lee 210
Park 10

name    id
Kim     232
Lee     210
Park    10
```


## 1.3 기타 C 문법
### 1.3.1 서식 지정자
#### 숫자 입출력
```C
#include<stdio.h>

int main(void){
    char  c; unsigned char  uc;
    short s; unsigned short us;
    int   i; unsigned int   ui;
    scanf("%hhd %hhu",&c,&uc);
    scanf("%hd %hu",  &s,&us);
    scanf("%d %u",    &i,&ui);
    printf("char : %d, unsigned char : %u\n",c,uc);
    printf("short: %d, unsigned short: %u\n",s,us);
    printf("int  : %d, unsigned int  : %u\n",i,ui);
}
```
#### 문자 입출력
```C
#include<stdio.h>
int main(void){
    char c;
    scanf("%c",&c);
    printf("char: %c\n",c);
}
```
#### 문자열 입출력
```C
#include<stdio.h>
int main(void){
    char s[10];
    scanf("%s",s);
    printf("%s\n",s);
}
```
#### 문자열 입출력: 포인터 배열
```C
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    unsigned char i;
    unsigned char N=3;
    char b[20]; // 문자열 버퍼
    char* p[N];
    for(i=0;i<N;i++){
        scanf("%s",b);
        p[i]=(char*)malloc(strlen(b)+1);
        strcpy(p[i],b);
    }
    for(i=0;i<N;i++){
        printf("student %d: %s\n",i,p[i]);
    }
}
```
```
$ ./test
Kim
Lee
Park
student 0: Kim
student 1: Lee
student 2: Park
```
### 1.3.2 enumerate
#### enumerate
```C
#include<stdio.h>

typedef enum{
    SUM,
    SUB
}mode_calc;

void calc(int a,int b,mode_calc mode){
    if     (mode==SUM){printf("%d+%d=%d\n",a,b,a+b);}
    else if(mode==SUB){printf("%d-%d=%d\n",a,b,a-b);}
}

int main(void){
    printf("value of SUM: %d\n",SUM);
    printf("value of SUB: %d\n",SUB);
    int a=1;
    int b=1;
    calc(a,b,SUM);
    calc(a,b,SUB);
}
```
```
$ ./test
value of SUM: 0
value of SUB: 1
1+1=2
1-1=0
```
<!-- ### 1.3.3 함수 -->
<!-- #### static -->
<!-- #### const -->
