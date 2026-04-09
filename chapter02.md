# 2장 기본 자료구조 및 알고리즘
## 2.1 기본 자료구조
### 2.2.1 리스트
#### 선형리스트: 배열
```C
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j;
    int n; scanf("%d",&n);
    int* a=(int*)malloc(sizeof(int*)*n);
    for(j=0;j<n;j++){scanf("%d",&a[j]);}
    for(j=0;j<n;j++){printf("%d: %p\t",a[j],&a[j]);}
    free(a);
}
```
```
$ ./test
3
1 2 3
1: 0x5950e83e06b0       2: 0x5950e83e06b4       3: 0x5950e83e06b8       
```
#### 선형리스트: 배열(2차)
```C
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j; int k;
    int r; int c; scanf("%d %d",&r,&c);
    int** a=(int**)malloc(sizeof(int*)*r);
    int*  d=(int*) malloc(sizeof(int)* r*c);
    for(j=0;j<r;j++){a[j]=d+(j*c);} // 포인팅
    for(j=0;j<r;j++){for(k=0;k<c;k++){scanf("%d",&a[j][k]);}}
    for(j=0;j<r;j++){for(k=0;k<c;k++){printf("%d: %p\t",a[j][k],&a[j][k]);}printf("\n");}
    free(d);
    free(a);
}
```
```
$ ./test
2 3
1 2 3
4 5 6
1: 0x6342cdb5e6d0       2: 0x6342cdb5e6d4       3: 0x6342cdb5e6d8
4: 0x6342cdb5e6dc       5: 0x6342cdb5e6e0       6: 0x6342cdb5e6e4
```
#### 연결리스트
```C
struct node{
    int v;
    struct node* next;
};
struct list{
    int n;          // number of item
    struct node* h; // head
}
```
#### 연결리스트: 원형
```C
struct node{
    int v;
    struct node* next;
};
struct list{
    int n;          // number of item
    struct node* h; // head
    struct node* t; // tail
}
```
#### 연결리스트: 양방향
```C
struct node{
    int v;
    struct node* prev
    struct node* next;
};
struct list{
    int n;          // number of item
    struct node* h; // head
}
```
### 2.2.2 스택
#### 선형 스택
```C
#include<stdio.h>
#include<stdlib.h>

struct stack{
    int  t; // top of stack
    int* s; // stack
};

void push(struct stack* s,int v);
int   pop(struct stack* s);

int main(void){
    int j;
    int n; scanf("%d",&n);
    int v;
    struct stack s;
    s.t=0;
    s.s=(int*)malloc(sizeof(int)*n);
    for(j=0;j<n;j++){scanf("%d",&v); push(&s,v);}
    for(j=0;j<n;j++){printf("%d ",pop(&s));}
    free(s.s);
}

void push(struct stack* s,int v){
    s->s[s->t++]=v;
}
int   pop(struct stack* s){
    return s->s[--(s->t)];
}
```
```
 ./test
3
1 2 3
3 2 1 
```
<!-- #### 연결 스택 -->
### 2.2.3 큐
#### 선형 큐
```C
#include<stdio.h>
#include<stdlib.h>

struct queue{
    int  f; // front of queue
    int  r; // rear  of queue
    int* q; // queue
};

void enqueue(struct queue* q,int v);
int  dequeue(struct queue* q);

int main(void){
    int j;
    int n; scanf("%d",&n);
    int v;
    struct queue q;
    q.f=0;
    q.r=0;
    q.q=(int*)malloc(sizeof(int)*n);
    for(j=0;j<n;j++){scanf("%d",&v); enqueue(&q,v);}
    for(j=0;j<n;j++){printf("%d ",dequeue(&q));}
    free(q.q);
}
void enqueue(struct queue* q,int v){
    q->q[q->r++]=v;
}
int  dequeue(struct queue* q){
    return q->q[q->f++];
}
```
```
$ ./test
3
1 2 3
1 2 3 
```
<!-- #### 연결 큐 -->
#### 선형 데크
```C
#include<stdio.h>
#include<stdlib.h>

struct queue{
    int  f; // front of queue
    int  r; // rear  of queue
    int* q; // queue
    int  c; // number of element
    int  n; // number of max element
};

void fenqueue(struct queue* q,int v);
void renqueue(struct queue* q,int v);
int  fdequeue(struct queue* q);
int  rdequeue(struct queue* q);


int main(void){
    int j;
    int n; scanf("%d",&n);
    int v;
    struct queue q;
    q.f=0;
    q.r=0;
    q.c=0;
    q.n=n;
    q.q=(int*)malloc(sizeof(int)*n);
    for(j=0;j<n;j++){scanf("%d",&v); fenqueue(&q,v);}
    for(j=0;j<n;j++){printf("%d ",rdequeue(&q));}
    free(q.q);
}
void fenqueue(struct queue* q,int v){
    q->f+=q->n; q->f--;
    q->f%=q->n;
    q->q[q->f]=v;
    q->c++;
}
void renqueue(struct queue* q,int v){
    q->q[q->r++]=v;
    q->r%=q->n;
    q->c++;
}
int  fdequeue(struct queue* q){
    q->r+=q->n; q->r--;
    q->r%=q->n;
    q->c--;
    return q->q[q->r];
}
int  rdequeue(struct queue* q){
    int v=q->q[q->f++];
    q->f%=q->n;
    q->c--;
    return v;
}
```
```
$ ./test
3
1 2 3
3 2 1 
```
<!-- #### 연결 데크 -->



## 2.2 탐색
### 2.2.1 선형시간 탐색
#### 순차탐색
```C
#include<stdio.h>
#include<stdlib.h>

int search(int* a,int n,int q);

int main(void){
    int j;
    int n; int q; scanf("%d %d",&n,&q);
    int* a=(int*)malloc(sizeof(int)*n);
    for(j=0;j<n;j++){scanf("%d",&a[j]);}
    printf("%d",search(a,n,q));
    free(a);
}

int search(int* a,int n,int q){
    int j;
    for(j=0;j<n;j++){if(a[j]==q){return j;}}
    return -1;
}
```
```
$ ./test
10 21 # number of node, query
10 14 16 21 22 24 32 42 45 53
3

$ ./test
10 23
10 14 16 21 22 24 32 42 45 53
-1
```
### 2.2.2 로그시간 탐색
#### 이분탐색
```C
#include<stdio.h>
#include<stdlib.h>

int search(int* a,int n,int q);

int main(void){
    int j;
    int n; int q; scanf("%d %d",&n,&q);
    int* a=(int*)malloc(sizeof(int)*n);
    for(j=0;j<n;j++){scanf("%d",&a[j]);}
    printf("%d",search(a,n,q));
    free(a);
}

int search(int* a,int n,int q){
    int s=0;   // start
    int m;     // middle
    int e=n-1; // end
    while(s<=e){
        m=s+(e-s)/2;
        if(a[m]==q){return m;}
        if(a[m]> q){e=m-1;}
        if(a[m]< q){s=m+1;}
    }
    return -1;
}
```
```
$ ./test
10 21 # number of node, query
10 14 16 21 22 24 32 42 45 53
3

$ ./test
10 23
10 14 16 21 22 24 32 42 45 53
-1
```
### 2.2.3 상수시간 탐색
#### 해시
선형시간 문자 배열 ID 조회  
```C
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define D 50009 // divisor
#define L 101 // 문자열 최대 길이

struct node{
    char s[L];
    int next;
};
struct hash{
    int n; // number of words
    int p; // pool pointer
    int* adjs;
    struct node* pool;
};

int    hash(char* s);
void   init(struct hash* h,int n);
void  clean(struct hash* h);
void insert(struct hash* h,char* s);
int   query(struct hash* h,char* s);

int main(void){
    int j;
    int n; int m; scanf("%d %d",&n,&m);
    char q[L];
    struct hash h;
    init(&h,n);
    for(j=0;j<n;j++){scanf("%s",q);insert(&h,q);}
    for(j=0;j<m;j++){scanf("%s",q);printf("%d ",query(&h,q));}
    clean(&h);
}

int    hash(char* s){
    int h=5381;
    while(*s!='\0'){h=((h<<5)+h)+*s++;}
    return h&0x7FFFFFFF;
}
void   init(struct hash* h,int n){
    h->n=n;
    h->p=0;
    h->adjs=(int*)malloc(sizeof(int)*D);
    h->pool=(struct node*)malloc(sizeof(struct node)*n);
    memset(h->adjs,-1,sizeof(int)*D);
}
void  clean(struct hash* h){
    free(h->adjs);
    free(h->pool);
}
void insert(struct hash* h,char* s){
    int i=hash(s)%D;
    strcpy(h->pool[h->p].s,s);
    h->pool[h->p].next=h->adjs[i]; // chaining
    h->adjs[i]=h->p++;
}
int   query(struct hash* h,char* s){
    int i=hash(s)%D;
    int d=h->adjs[i];
    while(d!=-1){
        if(strcmp(h->pool[d].s,s)==0){return 1;}
        d=h->pool[d].next;
    }
    return -1;
}
```
```
$ ./test
3 3 # number of nodes, queries
abc def ghi
abc def xxx
1 1 -1 
```



## 2.3 정렬
### 2.3.1 이차시간 정렬
#### 선택정렬
```C
#include<stdio.h>
#include<stdlib.h>

void sort(int* a,int n);

int main(void){
    int j;
    int n; scanf("%d",&n);
    int* a=(int*)malloc(sizeof(int)*n);
    for(j=0;j<n;j++){scanf("%d",&a[j]);}
    sort(a,n);
    for(j=0;j<n;j++){printf("%d ",a[j]);}
    free(a);
}

void sort(int* a,int n){
    int j; int k;
    int v; int i; // value, index of min
    for(j=0;j<n;j++){
        i=j; v=a[j];
        for(k=j+1;k<n;k++){if(a[k]<v){i=k; v=a[k];}}
        a[i]=a[j];
        a[j]=v;
    }
}
```
```
$ ./test
10
32 21 14 10 22 45 53 42 16 24
10 14 16 21 22 24 32 42 45 53 
```
#### 버블정렬
```C
void sort(int* a,int n){
    int j; int k;
    int t; // tmp: swap
    for(j=0;j<n;    j++){
    for(k=0;k<n-j-1;k++){
        if(a[k]>a[k+1]){t=a[k];a[k]=a[k+1];a[k+1]=t;}
    }}
}
```
#### 삽입정렬
```C
void sort(int a[],int n){
    int j; int k;
    int t; // tmp: swap
    for(j=1;j<n;j++){
    for(k=j;k>0;k--){
        if(a[k]<a[k-1]){t=a[k];a[k]=a[k-1];a[k-1]=t;}
    }}
}
```
#### 셸정렬
```C
void shellsort(int* a,int n){
    int j;
    int g; // gap
    g=n/2;
    while(g>=1){
        for(j=0;j<g;j++){gapsort(a,j,n-1,g);}
        g/=2;
    }
}
void gapsort(int* a,int s,int e,int g){
    int j; int k;
    int t; // tmp: swap
    for(j=s+g;j<=e;j+=g){
    for(k=j;  k>=g;k-=g){
        if(a[k]<a[k-g]){t=a[k];a[k]=a[k-g];a[k-g]=t;}
    }}
}
```
### 2.3.2 선형로그시간 정렬
#### qsort()
```C
#include<stdlib.h>
void qsort(void* base,size_t nmemb,size_t size,int(*compar)(const void*,const void*));
```
compar: 음수, 0, 양수 리턴 함수 포인터  
#### qsort(): 기본 문법
명시적 대소 비교 결과 리턴  
```C
#include<stdio.h>
#include<stdlib.h>

int compare(const void* u,const void* v);

int main(void){
    int j;
    int n; scanf("%d",&n);
    int* a=(int*)malloc(sizeof(int)*n);
    for(j=0;j<n;j++){scanf("%d",&a[j]);}
    qsort(&a[0],n,sizeof(int),compare);
    for(j=0;j<n;j++){printf("%d ",a[j]);}
    free(a);
}

int compare(const void* u,const void* v){
    if((*((int*)u))<(*((int*)v))){return -1;}
    if((*((int*)u))>(*((int*)v))){return  1;}
    return 0;
}
```
```
$ ./test
10
32 21 14 10 22 45 53 42 16 24
10 14 16 21 22 24 32 42 45 53 
```
#### qsort(): 오름차순 및 내림차순
```C
#include<stdio.h>
#include<stdlib.h>

int asc(const void* u,const void* v){return *((int*)u)-*((int*)v);}
int dsc(const void* u,const void* v){return *((int*)v)-*((int*)u);}

int main(void){
    int j;
    int n; scanf("%d",&n);
    int* a=(int*)malloc(sizeof(int)*n);
    for(j=0;j<n;j++){scanf("%d",&a[j]);}

    qsort(&a[0],n,sizeof(int),asc); for(j=0;j<n;j++){printf("%d ",a[j]);} printf("\n");
    qsort(&a[0],n,sizeof(int),dsc); for(j=0;j<n;j++){printf("%d ",a[j]);} printf("\n");
    free(a);
}
```
```
$ ./test
10
32 21 14 10 22 45 53 42 16 24
10 14 16 21 22 24 32 42 45 53 
53 45 42 32 24 22 21 16 14 10 
```
#### qsort(): tie breaking rule
```C
#include<stdio.h>
#include<stdlib.h>

struct node{
    int v; // value
    int i; // id: tie breaking
};

int compare(const void* u,const void* v);

int main(void){
    int j;
    int n; scanf("%d",&n);
    struct node* a=(struct node*)malloc(sizeof(struct node)*n);
    for(j=0;j<n;j++){scanf("%d",&a[j].v); a[j].i=j;}
    qsort(&a[0],n,sizeof(struct node),compare);
    for(j=0;j<n;j++){printf("%d ",a[j].v);} printf("\n");
    for(j=0;j<n;j++){printf("%d  ",a[j].i);}
    free(a);
}

int compare(const void* u,const void* v){
    if((((struct node*)u)->v)< (((struct node*)v)->v)){return -1;}
    if((((struct node*)u)->v)> (((struct node*)v)->v)){return 1;}
    if((((struct node*)u)->v)==(((struct node*)v)->v)){
        if((((struct node*)u)->i)< (((struct node*)v)->i)){return -1;}
        if((((struct node*)u)->i)> (((struct node*)v)->i)){return 1;}
    }
    return 0;
}
```
중복 데이터(22)에서 tie breaking rule 적용 확인(i 오름차순: 0-4-6-8)  
```
$ ./test
10
22 21 14 10 22 45 22 42 22 24
10 14 21 22 22 22 22 24 42 45 
3  2  1  0  4  6  8  9  7  5  
```
#### 퀵정렬
```C
#include<stdio.h>
#include<stdlib.h>

void quicksort(int* a,int s,int e);
int  partition(int* a,int s,int e);

int main(void){
    int j;
    int n; scanf("%d",&n);
    int* a=(int*)malloc(sizeof(int)*n);
    for(j=0;j<n;j++){scanf("%d",&a[j]);}
    quicksort(a,0,n-1);
    for(j=0;j<n;j++){printf("%d ",a[j]);}
    free(a);
}

void quicksort(int* a,int s,int e){
    int p;
    if(s<e){
        p=partition(a,s,  e);
        quicksort(  a,s,  p);
        quicksort(  a,p+1,e);
    }
}
int  partition(int* a,int s,int e){
    int t; // tmp: swap
    int p=a[s+(e-s)/2];
    int l=s-1;
    int r=e+1;

    while(1){
        do{l++;}while(a[l]<p);
        do{r--;}while(a[r]>p);
        if(l>=r){return r;}
        else{t=a[l];a[l]=a[r];a[r]=t;}
    }
}
```
```
$ ./test
10
32 21 14 10 22 45 53 42 16 24
10 14 16 21 22 24 32 42 45 53 
```
#### 병합정렬
```C
#include<stdio.h>
#include<stdlib.h>

void mergesort(int* a,int s,      int e);
void     merge(int* a,int s,int m,int e);

int main(void){
    int j;
    int n; scanf("%d",&n);
    int* a=(int*)malloc(sizeof(int)*n);
    for(j=0;j<n;j++){scanf("%d",&a[j]);}
    mergesort(a,0,n-1);
    for(j=0;j<n;j++){printf("%d ",a[j]);}
    free(a);
}

void mergesort(int* a,int s,      int e){
    if(s<e){
        int m=(s+e)/2;
        mergesort(a,s,  m);
        mergesort(a,m+1,e);
        merge(a,s,m,e);
    }
}
void     merge(int* a,int s,int m,int e){
    int i; int j; int k;
    int L=m-s+1;int* l=(int*)malloc(sizeof(int)*L);
    int R=e-m;  int* r=(int*)malloc(sizeof(int)*R);
    for(i=0;i<L;i++){l[i]=a[s+i];}
    for(i=0;i<R;i++){r[i]=a[m+1+i];}
    i=0;j=0;k=s;
    while(i<L&&j<R){
        if(l[i]<r[j]){a[k++]=l[i++];}
        else         {a[k++]=r[j++];}
    }
    while(i<L){a[k++]=l[i++];}
    while(j<R){a[k++]=r[j++];}
}
```
```
$ ./test
10
32 21 14 10 22 45 53 42 16 24
10 14 16 21 22 24 32 42 45 53 
```
<!-- ### 2.3.3 선형시간 정렬 -->
<!-- #### 기수정렬 -->
