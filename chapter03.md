# 3장 탐색
<!-- ## 3.1 탐색 -->



## 3.2 순차 탐색
### 3.2.1 정렬되어있지 않은 자료 탐색
#### 순차 탐색
```C
#include<stdio.h>

#define SUCCESS  0
#define NOTFOUND 1
unsigned char search(unsigned char a[],unsigned char n,unsigned char q);

int main(void){
    unsigned char N=10;
    unsigned char a[10]={32,21,14,10,22,45,53,42,16,24};
    if(search(a,N,32)==SUCCESS){printf("32: SUCCESS\n");}else{printf("32: NOTFOUND\n");}
    if(search(a,N,22)==SUCCESS){printf("22: SUCCESS\n");}else{printf("22: NOTFOUND\n");}
    if(search(a,N,24)==SUCCESS){printf("24: SUCCESS\n");}else{printf("24: NOTFOUND\n");}
    if(search(a,N,99)==SUCCESS){printf("99: SUCCESS\n");}else{printf("99: NOTFOUND\n");}
}
unsigned char search(unsigned char a[],unsigned char n,unsigned char q){
    unsigned char j;
    for(j=0;j<n;j++){if(a[j]==q){return SUCCESS;}}
    return NOTFOUND;
}
```
```
$ ./test
32: SUCCESS
22: SUCCESS
24: SUCCESS
99: NOTFOUND
```
### 3.2.2 정렬된 자료 탐색
#### 순차 탐색
```C
#include<stdio.h>

#define SUCCESS  0
#define NOTFOUND 1
unsigned char search(unsigned char a[],unsigned char n,unsigned char q);

int main(void){
    unsigned char N=10;
    unsigned char a[10]={10,14,16,21,22,24,32,42,45,53};
    if(search(a,N,32)==SUCCESS){printf("32: SUCCESS\n");}else{printf("32: NOTFOUND\n");}
    if(search(a,N,18)==SUCCESS){printf("18: SUCCESS\n");}else{printf("18: NOTFOUND\n");}
    if(search(a,N,99)==SUCCESS){printf("99: SUCCESS\n");}else{printf("99: NOTFOUND\n");}
}
unsigned char search(unsigned char a[],unsigned char n,unsigned char q){
    unsigned char j=0;
    unsigned char b;
    while(((b=a[j++])<=q)&&(j<n)){if(b==q){printf("iteration: %u\t",j);return SUCCESS;}}
    printf("iteration: %u\t",j);
    return NOTFOUND;
}
```
```
$ ./test
iteration: 7    32: SUCCESS
iteration: 4    18: NOTFOUND
iteration: 10   99: NOTFOUND
```
#### 색인 순차 탐색
```C
#include<stdio.h>
#include<stdlib.h>

#define SIZE     3 // size of index table
#define SUCCESS  0
#define NOTFOUND 1

struct data{
    unsigned char n;
    unsigned char* a; // 선형 리스트 주소
    unsigned char i[SIZE]; // table of index
    unsigned char k[SIZE]; // table of key
};

unsigned char search(struct data* d,unsigned char q);
void settable(struct data* d);
void printtable(struct data* d);

int main(void){
    unsigned char N=10;
    unsigned char a[10]={10,14,16,21,22,24,32,42,45,53};
    struct data* d=(struct data*)malloc(sizeof(struct data));
    d->n=N;
    d->a=&a[0];
    settable(d);
    printtable(d);
    search(d,15);
    search(d,22);
    search(d,53);
}

unsigned char search(struct data* d,unsigned char q){
    unsigned char j=0; // loop variable
    unsigned char s;   // start
    unsigned char e;   // end
    s=d->i[SIZE-1];
    e=(d->n)-1;
    for(j=0;j<SIZE-1;j++){
        if((d->k[j]<=q)&&(q<d->k[j+1])){
            s=d->i[j];
            e=d->i[j+1];
            break;
        }
    }
    printf("search %u, [%u,%u]\t%u~%u\t",q,s,e,d->a[s],d->a[e]);
    for(j=s;j<=e;j++){if(d->a[j]==q){printf("SUCCESS\n"); return SUCCESS;}}
    printf("NOTFOUND\n"); return NOTFOUND;
}
void settable(struct data* d){
    unsigned char j=0; // loop variable
    unsigned char g=d->n/SIZE; // gap
    printf("gap: %u\n",g);
    while(j++<SIZE){
        d->i[j]=j*g;
        d->k[j]=*((d->a)+j*g);
    }
}
void printtable(struct data* d){
    unsigned char j=0; // loop variable
    for(j=0;j<SIZE;j++){
        printf("index: %u, key: %u\n",d->i[j],d->k[j]);
    }
}
```
```
$ ./test
gap: 3
index: 0, key: 9
index: 3, key: 21
index: 6, key: 32
search 15, [0,3]        10~21   NOTFOUND
search 22, [3,6]        21~32   SUCCESS
search 53, [6,9]        32~53   SUCCESS
```



<!-- ## 3.3 이진 탐색 -->
<!-- ## 3.4 이진 트리 탐색 -->
<!-- ## 3.5 해싱 -->
