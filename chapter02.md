# 2장 기본 자료구조
## 2.1 선형리스트
### 2.1.1 선형리스트
#### 선형리스트
```C
#include<stdio.h>

int main(void){
    int j; 
    int a[3];
    for(j=0;j<3;j++){a[j]=j;}
    for(j=0;j<3;j++){printf("%d ",a[j]);}
}
```
```
$ ./test
0 1 2 
```
#### 선형리스트 저장 순서
```C
#include<stdio.h>

int main(void){
    int j;
    int k;
    int a[2][3]={{1,2,3},{4,5,6}};
    for(j=0;j<2;j++){for(k=0;k<3;k++){printf("%d: %p\t",a[j][k],&a[j][k]);}printf("\n");}
}
```
```
$ ./test
1: 0x7ffe36f15ca0       2: 0x7ffe36f15ca4       3: 0x7ffe36f15ca8
4: 0x7ffe36f15cac       5: 0x7ffe36f15cb0       6: 0x7ffe36f15cb4
```



## 2.2 연결리스트
### 2.2절 구현체 요약
||연결리스트|노드|기능|
|---|---|---|---|
|2.2.1 기본|head|next|append()<br>insert()<br>delete()|
|2.2.2 원형|head<br>tail|next|append()<br>insert()<br>delete()|
|2.2.3 양방향|head|prev<br>next|append()<br>insert()<br>delete()|
### 2.2.1 연결리스트
#### 기본 연결리스트
```C
#include<stdio.h>
#include<stdlib.h>

struct node{
    int v; // value
    struct node* next;
};

struct list{
    int n;          // number of item
    struct node* h; // head
};

void printl(struct list* l);
void append(struct list* l,int v);
void insert(struct list* l,int v,int i);
void delete(struct list* l,      int i);

int main(void){
    struct list l;
    l.n=0;
    l.h=(struct node*)malloc(sizeof(struct node));
    l.h->v=-1;
    l.h->next=NULL;

    // append(), insert()
    append(&l,3);   append(&l,2);   append(&l,1);
    insert(&l,4,3); insert(&l,5,0); insert(&l,6,3);
    printl(&l);
    
    // delete
    delete(&l,5);
    delete(&l,0);
    printl(&l);
}

void printl(struct list* l){
    struct node* b=l->h;
    while((b=b->next)!=NULL){printf("%d ",b->v);}printf("\n");
}
void append(struct list* l,int v){
    int j;
    struct node* n=(struct node*)malloc(sizeof(struct node)); // new
    struct node* b;
    b=l->h; for(j=0;j<l->n;j++){b=b->next;}
    n->v=v; n->next=NULL;
    b->next=n;
    l->n+=1;
}
void insert(struct list* l,int v,int i){
    int j;
    struct node* n=(struct node*)malloc(sizeof(struct node)); // new
    struct node* b;
    b=l->h; for(j=0;j<i;j++){b=b->next;}
    n->v=v; n->next=b->next;
    b->next=n;
    l->n+=1;
}
void delete(struct list* l,      int i){
    int j;
    struct node* b;
    struct node* f; // free
    b=l->h; for(j=0;j<i;j++){b=b->next;}
    f=b->next;
    b->next=b->next->next;
    free(f);
    l->n-=1;
}
```
```
$ ./test
5 3 2 6 1 4 
3 2 6 1 
```
### 2.2.2 원형 연결리스트
#### 원형 연결리스트
```C
#include<stdio.h>
#include<stdlib.h>

struct node{
    int v; // value
    struct node* next;
};

struct list{
    int n;          // number of item
    struct node* h; // head
    struct node* t; // tail
};

void printl(struct list* l);
void append(struct list* l,int v);
void insert(struct list* l,int v,int i);
void delete(struct list* l,      int i);

int main(void){
    struct list l;
    l.n=0;
    l.h=(struct node*)malloc(sizeof(struct node)); // head: dummy
    l.t=l.h;                                       // tail: pointing
    l.h->v=-1;
    l.h->next=NULL;

    // append(), insert()
    append(&l,3);   append(&l,2);   append(&l,1);
    insert(&l,4,3); insert(&l,5,0); insert(&l,6,3);
    printl(&l);
    
    // delete
    delete(&l,5);
    delete(&l,0);
    printl(&l);
}

void printl(struct list* l){
    struct node* b=l->h;
    while((b=b->next)!=NULL){printf("%d ",b->v);}printf("\n");
}
void append(struct list* l,int v){
    struct node* n=(struct node*)malloc(sizeof(struct node)); // new
    struct node* b;
    n->v=v; n->next=NULL;
    b=l->t; b->next=n;
    l->t=n; l->n+=1;
}
void insert(struct list* l,int v,int i){
    int j;
    struct node* n=(struct node*)malloc(sizeof(struct node)); // new
    struct node* b;
    b=l->h; for(j=0;j<i;j++){b=b->next;}
    n->v=v; n->next=b->next;
    b->next=n;
    l->n+=1;
}
void delete(struct list* l,      int i){
    int j;
    struct node* b;
    struct node* f; // free
    b=l->h; for(j=0;j<i;j++){b=b->next;}
    f=b->next;
    b->next=b->next->next;
    free(f);
}
```
```
$ ./test
5 3 2 6 1 4 
3 2 6 1 
```
### 2.2.3 양방향 연결리스트
#### 양방향 연결리스트
```C
#include<stdio.h>
#include<stdlib.h>

struct node{
    int v; // value
    struct node* prev;
    struct node* next;
};

struct list{
    int n;          // number of item
    struct node* h; // head
};

void printl(struct list* l);
void append(struct list* l,int v);
void insert(struct list* l,int v,int i);
void delete(struct list* l,      int i);

int main(void){
    struct list l;
    l.n=0;
    l.h=(struct node*)malloc(sizeof(struct node));
    l.h->v=-1;
    l.h->prev=l.h;
    l.h->next=l.h;

    // append(), insert()
    append(&l,3);   append(&l,2);   append(&l,1);
    insert(&l,4,3); insert(&l,5,0); insert(&l,6,3);
    printl(&l);
    
    // delete
    delete(&l,5);
    delete(&l,0);
    printl(&l);
}

void printl(struct list* l){
    int j;
    struct node* b=l->h->next;
    for(j=0;j<l->n;j++){printf("%d ",b->v);b=b->next;}printf("\n");
}
void append(struct list* l,int v){
    struct node* n=(struct node*)malloc(sizeof(struct node)); // new
    n->v=v;
    n->prev         =l->h->prev;
    n->next         =l->h;
    l->h->prev->next=n;
    l->h->prev      =n;
    l->n+=1;
}
void insert(struct list* l,int v,int i){
    int j;
    struct node* n=(struct node*)malloc(sizeof(struct node)); // new
    struct node* b;
    b=l->h; for(j=0;j<i;j++){b=b->next;}
    n->v=v;
    n->prev      =b;
    n->next      =b->next;
    b->next->prev=n;
    b->next      =n;
    l->n+=1;
}
void delete(struct list* l,      int i){
    int j;
    struct node* b;
    struct node* f; // free
    b=l->h; for(j=0;j<i;j++){b=b->next;}
    f=b->next;
    b->next->next->prev=b;
    b->next            =b->next->next;
    free(f);
    l->n-=1;
}
```
```
$ ./test
5 3 2 6 1 4 
3 2 6 1 
```



## 2.3 스택
### 2.3절 구현체 요약
||구현체|기능|
|---|---|---|
|2.3.1 선형 스택|배열|push()<br>pop()|
|2.3.2 연결 스택|연결리스트|push()<br>pop()|
### 2.3.1 선형 스택
#### 선형 스택
```C
#include<stdio.h>
#include<stdlib.h>

# define N 10

struct stack{
    int n;    // number of item
    int a[N]; // linear stack
};

void prints(struct stack* s);
void   push(struct stack* s,int v);
int     pop(struct stack* s);

int main(void){
    struct stack s;
    s.n=0;

    // push()
    printf("push(1), stack: "); push(&s,1); prints(&s);
    printf("push(2), stack: "); push(&s,2); prints(&s);
    printf("push(3), stack: "); push(&s,3); prints(&s);

    // pop()
    printf("pop: %d, stack: ",pop(&s)); prints(&s);
    printf("pop: %d, stack: ",pop(&s)); prints(&s);
    printf("pop: %d, stack: ",pop(&s)); prints(&s);
}

void prints(struct stack* s){
    int j;
    for(j=0;j<s->n;j++){printf("%d ",s->a[j]);}printf("\n");
}
void   push(struct stack* s,int v){
    s->a[(s->n)++]=v;
}
int     pop(struct stack* s){
    return s->a[--(s->n)];
}
```
```
$ ./test
push(1), stack: 1 
push(2), stack: 1 2 
push(3), stack: 1 2 3 
pop: 3, stack: 1 2 
pop: 2, stack: 1 
pop: 1, stack: 
```
### 2.3.2 연결 스택
#### 연결 스택
```C
#include<stdio.h>
#include<stdlib.h>

struct node{
    int v; // value
    struct node* next;
};

struct stack{
    int n;          // number of item
    struct node* h; // head
};

void prints(struct stack* s);
void   push(struct stack* s,int v);
int     pop(struct stack* s);

int main(void){
    struct stack s;
    s.n=0;
    s.h=(struct node*)malloc(sizeof(struct node));
    s.h->v=-1;
    s.h->next=NULL;

    // push()
    printf("push(1), stack: "); push(&s,1); prints(&s);
    printf("push(2), stack: "); push(&s,2); prints(&s);
    printf("push(3), stack: "); push(&s,3); prints(&s);

    // pop()
    printf("pop: %d, stack: ",pop(&s)); prints(&s);
    printf("pop: %d, stack: ",pop(&s)); prints(&s);
    printf("pop: %d, stack: ",pop(&s)); prints(&s);
}

void prints(struct stack* s){
    struct node* b=s->h;
    while((b=b->next)!=NULL){printf("%d ",b->v);}printf("\n");
}
void   push(struct stack* s,int v){
    struct node* n=(struct node*)malloc(sizeof(struct node)); // new
    n->v=v; n->next=s->h->next;
    s->h->next=n;
    s->n+=1;
}
int     pop(struct stack* s){
    int p;          // pop
    struct node* f; // free
    f=s->h->next; p=f->v;
    s->h->next=s->h->next->next;
    free(f);
    s->n-=1;
    return p;
}
```
```
$ ./test
push(1), stack: 1 
push(2), stack: 2 1 
push(3), stack: 3 2 1 
pop: 3, stack: 2 1 
pop: 2, stack: 1 
pop: 1, stack: 
```



## 2.4 큐
### 2.4절 구현체 요약
||구현체|기능|
|---|---|---|
|2.4.1 선형 큐|배열|enqueue()<br>dequeue()|
|2.4.2 연결 큐|원형 연결리스트|enqueue()<br>dequeue()|
|2.4.3 데크|선형: 배열<br>연결: 양방향 연결리스트|enqueue_front()<br>dequeue_front()<br>enqueue_rear()<br>dequeue_rear()|
### 2.4.1 선형 큐
#### 선형 큐
```C
#include<stdio.h>
#include<stdlib.h>

# define N 10

struct queue{
    int n;      // number of item
    int f;      // front
    int r;      // rear
    int a[N*N]; // linear queue
};

void printq(struct queue* q);
void enqueue(struct queue* q,int v);
int  dequeue(struct queue* q);

int main(void){
    struct queue q;
    q.n=0;
    q.f=0;
    q.r=0;

    // enqueue()
    printf("enqueue(1), queue: "); enqueue(&q,1); printq(&q);
    printf("enqueue(2), queue: "); enqueue(&q,2); printq(&q);
    printf("enqueue(3), queue: "); enqueue(&q,3); printq(&q);

    // dequeue()
    printf("dequeue: %d, queue: ",dequeue(&q)); printq(&q);
    printf("dequeue: %d, queue: ",dequeue(&q)); printq(&q);
    printf("dequeue: %d, queue: ",dequeue(&q)); printq(&q);
}

void printq(struct queue* q){
    int j;
    for(j=q->f;j<q->r;j++){printf("%d ",q->a[j]);}printf("\n");
}
void enqueue(struct queue* q,int v){
    q->a[q->r++]=v;
    q->n++;
}
int  dequeue(struct queue* q){
    q->n--;
    return q->a[q->f++];
}
```
```
$ ./test
enqueue(1), queue: 1 
enqueue(2), queue: 1 2 
enqueue(3), queue: 1 2 3 
dequeue: 1, queue: 2 3 
dequeue: 2, queue: 3 
dequeue: 3, queue: 
```
### 2.4.2 연결 큐
#### 연결 큐
```C
#include<stdio.h>
#include<stdlib.h>

struct node{
    int v; // value
    struct node* next;
};

struct queue{
    int n;          // number of item
    struct node* h; // head
    struct node* t; // tail
};

void printq(struct queue* q);
void enqueue(struct queue* q,int v);
int  dequeue(struct queue* q);

int main(void){
    struct queue q;
    q.n=0;
    q.h=(struct node*)malloc(sizeof(struct node)); // head: dummy
    q.t=q.h;                                       // tail: pointing
    q.h->v=-1;
    q.h->next=NULL;

    // enqueue()
    printf("enqueue(1), queue: "); enqueue(&q,1); printq(&q);
    printf("enqueue(2), queue: "); enqueue(&q,2); printq(&q);
    printf("enqueue(3), queue: "); enqueue(&q,3); printq(&q);

    // dequeue()
    printf("dequeue: %d, queue: ",dequeue(&q)); printq(&q);
    printf("dequeue: %d, queue: ",dequeue(&q)); printq(&q);
    printf("dequeue: %d, queue: ",dequeue(&q)); printq(&q);
}

void printq(struct queue* q){
    struct node* b=q->h;
    while((b=b->next)!=NULL){printf("%d ",b->v);}printf("\n");
}
void enqueue(struct queue* q,int v){
    struct node* n=(struct node*)malloc(sizeof(struct node)); // new
    struct node* b;
    n->v=v; n->next=NULL;
    b=q->t; b->next=n;
    q->t=n; q->n+=1;
}
int  dequeue(struct queue* q){
    int d; // dequeue
    struct node* f; // free
    f=q->h->next; d=f->v;
    q->h->next=q->h->next->next;
    free(f);
    q->n-=1;
    return d;
}
```
```
$ ./test
enqueue(1), queue: 1 
enqueue(2), queue: 1 2 
enqueue(3), queue: 1 2 3 
dequeue: 1, queue: 2 3 
dequeue: 2, queue: 3 
dequeue: 3, queue: 
```
### 2.4.3 데크
#### 데크
```C
#include<stdio.h>
#include<stdlib.h>

struct node{
    int v; // value
    struct node* prev;
    struct node* next;
};

struct queue{
    int n;          // number of item
    struct node* h; // head
};

void printq(struct queue* q);
void fenqueue(struct queue* q,int v);
void renqueue(struct queue* q,int v);
int  fdequeue(struct queue* q);
int  rdequeue(struct queue* q);

int main(void){
    struct queue q;
    q.n=0;
    q.h=(struct node*)malloc(sizeof(struct node));
    q.h->v=-1;
    q.h->prev=q.h;
    q.h->next=q.h;

    printf("front\n");
    printf("enqueue(1), queue: "); fenqueue(&q,1); printq(&q);
    printf("enqueue(2), queue: "); fenqueue(&q,2); printq(&q);
    printf("enqueue(3), queue: "); fenqueue(&q,3); printq(&q);
    printf("dequeue: %d, queue: ",fdequeue(&q)); printq(&q);
    printf("dequeue: %d, queue: ",fdequeue(&q)); printq(&q);
    printf("dequeue: %d, queue: ",fdequeue(&q)); printq(&q);

    printf("\nrear\n");
    printf("enqueue(1), queue: "); renqueue(&q,1); printq(&q);
    printf("enqueue(2), queue: "); renqueue(&q,2); printq(&q);
    printf("enqueue(3), queue: "); renqueue(&q,3); printq(&q);
    printf("dequeue: %d, queue: ",rdequeue(&q)); printq(&q);
    printf("dequeue: %d, queue: ",rdequeue(&q)); printq(&q);
    printf("dequeue: %d, queue: ",rdequeue(&q)); printq(&q);
}

void printq(struct queue* q){
    int j;
    struct node* b=q->h->next;
    for(j=0;j<q->n;j++){printf("%d ",b->v);b=b->next;}printf("\n");
}
void fenqueue(struct queue* q,int v){
    struct node* n=(struct node*)malloc(sizeof(struct node)); // new
    n->v=v;
    n->prev         =q->h;
    n->next         =q->h->next;
    q->h->next->prev=n;
    q->h->next      =n;
    q->n+=1;
}
void renqueue(struct queue* q,int v){
    struct node* n=(struct node*)malloc(sizeof(struct node)); // new
    n->v=v;
    n->prev         =q->h->prev;
    n->next         =q->h;
    q->h->prev->next=n;
    q->h->prev      =n;
    q->n+=1;
}
int  fdequeue(struct queue* q){
    int d; // dequeue
    struct node* f; // free
    f=q->h->prev; d=f->v;
    q->h->prev->prev->next=q->h;
    q->h->prev            =q->h->prev->prev;
    q->n-=1; free(f);
    return d;
}
int rdequeue(struct queue* q){
    int d; // dequeue
    struct node* f; // free
    f=q->h->next; d=f->v;
    q->h->next->next->prev=q->h;
    q->h->next            =q->h->next->next;
    q->n-=1; free(f);
    return d;
}
```
```
$ ./test
front
enqueue(1), queue: 1 
enqueue(2), queue: 2 1 
enqueue(3), queue: 3 2 1 
dequeue: 1, queue: 3 2 
dequeue: 2, queue: 3 
dequeue: 3, queue: 

rear
enqueue(1), queue: 1 
enqueue(2), queue: 1 2 
enqueue(3), queue: 1 2 3 
dequeue: 1, queue: 2 3 
dequeue: 2, queue: 3 
dequeue: 3, queue: 
```
