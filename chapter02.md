# 2장 기본 자료구조
## 2.1 선형리스트
### 2.1.1 선형리스트
#### 선형리스트
```C
#include<stdio.h>

int main(void){
    unsigned char i;
    unsigned char a[3]={1,2,3};
    for(i=0;i<3;i++){printf("%u\n",a[i]);}
}
```
#### 선형리스트 저장 순서
```C
#include<stdio.h>

int main(void){
    unsigned char i;
    unsigned char j;
    unsigned char a[2][3]={
        {1,2,3},
        {4,5,6}
    };
    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            printf("%u: %p\t", a[i][j],&a[i][j]);
        }printf("\n");
    }
}
```
```
$ ./test
1: 0x7ffd0ba2b852       2: 0x7ffd0ba2b853       3: 0x7ffd0ba2b854
4: 0x7ffd0ba2b855       5: 0x7ffd0ba2b856       6: 0x7ffd0ba2b857
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
엘리먼트 추가: append(), delete()  
엘리먼트 삭제: delete()
```C
#include<stdio.h>
#include<stdlib.h>

struct node{
    unsigned char v;
    struct node* next;
};

struct linkedlist{
    unsigned char n; //노드 개수
    struct node* head;
};

void printll(struct linkedlist* ll);
void append(struct linkedlist* ll,                  struct node* new);// append
void insert(struct linkedlist* ll,unsigned char loc,struct node* new);// i번째 인덱스에 삽입
void delete(struct linkedlist* ll,unsigned char loc);                 // i번째 노드 삭제

int main(void){
    unsigned char i;
    struct node* new;
    // 연결리스트 생성
    struct linkedlist* ll=(struct linkedlist*)malloc(sizeof(struct linkedlist));
    ll->n=0;
    ll->head=(struct node*)malloc(sizeof(struct node));
    ll->head->v=255;
    ll->head->next=NULL;

    // 연결리스트 초기화: append()
    for(i=0;i<5;i++){
        new=(struct node*)malloc(sizeof(struct node));
        new->v=i;
        new->next=NULL;
        append(ll,new);
    }
    printll(ll);

    // insert(), delete()
    new=(struct node*)malloc(sizeof(struct node));
    new->v=7;
    new->next=NULL;
    insert(ll,3,new);printll(ll);
    delete(ll,3);    printll(ll);    
}

void printll(struct linkedlist* ll){
    unsigned char i;
    struct node* buf=(struct node*)malloc(sizeof(struct node));
    buf=ll->head->next;
    for(i=0;i<ll->n;i++){
        printf("%hhu ",buf->v);
        buf=buf->next;
    }
    printf("\n");
}
void append(struct linkedlist* ll,struct node* new){
    unsigned char i;
    struct node* buf=(struct node*)malloc(sizeof(struct node));
    buf=ll->head;
    for(i=0;i<ll->n;i++){buf=buf->next;}
    buf->next=new;
    ll->n+=1;
}
void insert(struct linkedlist* ll,unsigned char loc,struct node* new){
    unsigned char i;
    struct node* buf=(struct node*)malloc(sizeof(struct node));
    buf=ll->head;
    for(i=0;i<loc;i++){buf=buf->next;}
    new->next=buf->next;
    buf->next=new;
    ll->n+=1;
}
void delete(struct linkedlist* ll,unsigned char loc){
    unsigned char i;
    struct node* buf=(struct node*)malloc(sizeof(struct node));
    buf=ll->head; 
    for(i=0;i<loc;i++){buf=buf->next;}
    buf->next=buf->next->next;
    ll->n-=1;
}
```
```
$ ./test
0 1 2 3 4       # 초기 연결리스트
0 1 2 7 3 4     # insert()
0 1 2 3 4       # delete()
```
### 2.2.2 원형 연결리스트
#### 원형 연결리스트
```C
#include<stdio.h>
#include<stdlib.h>

struct node{
    unsigned char v;
    struct node* next;
};

struct linkedlist{
    unsigned char n; //노드 개수
    struct node* head;
    struct node* tail;
};

void printll(struct linkedlist* ll);
void append(struct linkedlist* ll,                  struct node* new);// append
void insert(struct linkedlist* ll,unsigned char loc,struct node* new);// i번째 인덱스에 삽입
void delete(struct linkedlist* ll,unsigned char loc);                 // i번째 노드 삭제

int main(void){
    unsigned char i;
    struct node* new;
    // 연결리스트 생성
    struct linkedlist* ll=(struct linkedlist*)malloc(sizeof(struct linkedlist));
    ll->n=0;
    ll->head=(struct node*)malloc(sizeof(struct node));
    ll->head->v=255;
    ll->head->next=NULL; // 헤드: 더미
    ll->tail=ll->head;   // 테일: 포인팅

    // 연결리스트 초기화: append()
    for(i=0;i<5;i++){
        new=(struct node*)malloc(sizeof(struct node));
        new->v=i;
        new->next=NULL;
        append(ll,new);
    }
    printll(ll);

    // insert(), delete()
    new=(struct node*)malloc(sizeof(struct node));
    new->v=7;
    new->next=NULL;
    insert(ll,5,new);printll(ll);
    delete(ll,5);    printll(ll);
    append(ll,new);  printll(ll);
}

void printll(struct linkedlist* ll){
    unsigned char i;
    struct node* buf=(struct node*)malloc(sizeof(struct node));
    buf=ll->head->next;
    for(i=0;i<ll->n;i++){
        printf("%hhu ",buf->v);
        buf=buf->next;
    }
    printf("\n");
}
void append(struct linkedlist* ll,struct node* new){
    struct node* buf=(struct node*)malloc(sizeof(struct node));
    buf=ll->tail;
    buf->next=new;
    ll->tail=new;
    ll->n+=1;
}
void insert(struct linkedlist* ll,unsigned char loc,struct node* new){
    unsigned char i;
    struct node* buf=(struct node*)malloc(sizeof(struct node));
    buf=ll->head;
    for(i=0;i<loc;i++){buf=buf->next;}
    new->next=buf->next;
    buf->next=new;
    ll->n+=1;
}
void delete(struct linkedlist* ll,unsigned char loc){
    unsigned char i;
    struct node* buf=(struct node*)malloc(sizeof(struct node));
    buf=ll->head; 
    for(i=0;i<loc;i++){buf=buf->next;}
    buf->next=buf->next->next;
    ll->n-=1;
}
```
```
$ ./test
0 1 2 3 4       # 초기 연결리스트
0 1 2 3 4 7     # insert
0 1 2 3 4       # delete
0 1 2 3 4 7     # append
```
### 2.2.3 양방향 연결리스트
#### 양방향 연결리스트
```C
#include<stdio.h>
#include<stdlib.h>

struct node{
    unsigned char v;
    struct node* prev;
    struct node* next;
};

struct linkedlist{
    unsigned char n; //노드 개수
    struct node* head;
};

void printll(struct linkedlist* ll);
void append(struct linkedlist* ll,                  struct node* new);// append
void insert(struct linkedlist* ll,unsigned char loc,struct node* new);// i번째 인덱스에 삽입
void delete(struct linkedlist* ll,unsigned char loc);                 // i번째 노드 삭제

int main(void){
    unsigned char i;
    struct node* new;
    // 연결리스트 생성
    struct linkedlist* ll=(struct linkedlist*)malloc(sizeof(struct linkedlist));
    ll->n=0;
    ll->head=(struct node*)malloc(sizeof(struct node));
    ll->head->v=255;
    ll->head->prev=ll->head;
    ll->head->next=ll->head;

    // 연결리스트 초기화: append()
    for(i=0;i<5;i++){
        new=(struct node*)malloc(sizeof(struct node));
        new->v=i;
        new->prev=NULL;
        new->next=NULL;
        append(ll,new);
    }
    printll(ll);

    // insert(), delete()
    new=(struct node*)malloc(sizeof(struct node));
    new->v=7;
    new->next=NULL;
    insert(ll,5,new);printll(ll);
    delete(ll,5);    printll(ll);
    append(ll,new);  printll(ll);
}

void printll(struct linkedlist* ll){
    unsigned char i;
    struct node* buf=(struct node*)malloc(sizeof(struct node));
    buf=ll->head->next;
    for(i=0;i<ll->n;i++){
        printf("%hhu ",buf->v);
        buf=buf->next;
    }
    printf("\n");
}
void append(struct linkedlist* ll,struct node* new){
    struct node* buf=(struct node*)malloc(sizeof(struct node));
    buf=ll->head;
    new->prev=buf->prev;
    new->next=buf;
    buf->prev->next=new;
    buf->prev=new;
    ll->n+=1;
}
void insert(struct linkedlist* ll,unsigned char loc,struct node* new){
    unsigned char i;
    struct node* buf=(struct node*)malloc(sizeof(struct node));
    buf=ll->head;
    for(i=0;i<loc;i++){buf=buf->next;}
    new->next=buf->next;
    new->prev=buf;
    buf->next->prev=new;
    buf->next=new;
    ll->n+=1;
}
void delete(struct linkedlist* ll,unsigned char loc){
    unsigned char i;
    struct node* buf=(struct node*)malloc(sizeof(struct node));
    buf=ll->head; 
    for(i=0;i<loc;i++){buf=buf->next;}
    buf->next->next->prev=buf;
    buf->next=buf->next->next;
    ll->n-=1;
}
```
```
$ ./test
0 1 2 3 4       # 초기 연결리스트
0 1 2 3 4 7     # insert
0 1 2 3 4       # delete
0 1 2 3 4 7     # append
```



## 2.3 스택
### 2.3절 구현체 요약
||구현체|기능|
|---|---|---|
|2.3.1 배열 스택|선형리스트|push()<br>pop()|
|2.3.2 연결 스택|연결리스트|push()<br>pop()|
### 2.3.1 배열 스택
#### 배열 스택
```C
#include<stdio.h>
#include<stdlib.h>

struct stack{
    unsigned char n; // 노드 개수
    unsigned char l[10];    
};

void push(struct stack* s,unsigned char new){s->l[s->n]=new;s->n+=1;}
unsigned char pop(struct stack* s){return s->l[--(s->n)];}
void printstack(struct stack* s){
    unsigned char i;
    for(i=0;i<s->n;i++){printf("%hhu ",s->l[i]);}
    printf("\n");
}

int main(void){
    unsigned char i;
    struct stack* s=(struct stack*)malloc(sizeof(struct stack));
    s->n=0;
    for(i=0;i<5;i++){
        push(s,i);
    }
    printstack(s);
    printf("pop:  %hhu, printstack: ",pop(s)); printstack(s);
    printf("pop:  %hhu, printstack: ",pop(s)); printstack(s);
    printf("pop:  %hhu, printstack: ",pop(s)); printstack(s);
    printf("push: 2, printstack: ");push(s,2); printstack(s);
    printf("push: 3, printstack: ");push(s,3); printstack(s);
    printf("push: 4, printstack: ");push(s,4); printstack(s);
}
```
```
$ ./test
0 1 2 3 4 # 초기 스택
pop:  4, printstack: 0 1 2 3 
pop:  3, printstack: 0 1 2 
pop:  2, printstack: 0 1 
push: 2, printstack: 0 1 2 
push: 3, printstack: 0 1 2 3 
push: 4, printstack: 0 1 2 3 4 
```
### 2.3.2 연결 스택
#### 연결 스택
```C
#include<stdio.h>
#include<stdlib.h>

struct node{
    unsigned char v;
    struct node* next;
};

struct stack{
    unsigned char n; // 노드 개수
    struct node* head;
};
void push(struct stack* s,struct node* new);
struct node* pop(struct stack* s);
void printstack(struct stack* s);

int main(void){
    unsigned char i;
    struct node* new;

    struct stack* s=(struct stack*)malloc(sizeof(struct stack));
    s->n=0;
    s->head=(struct node*)malloc(sizeof(struct node));
    s->head->v=25;
    s->head->next=NULL;

    for(i=0;i<5;i++){
        new=(struct node*)malloc(sizeof(struct node));
        new->v=i;
        new->next=NULL;
        push(s,new);
    }
    printstack(s);
    printf("pop: %hhu, printstack: ",pop(s)->v); printstack(s);
    printf("pop: %hhu, printstack: ",pop(s)->v); printstack(s);
    printf("pop: %hhu, printstack: ",pop(s)->v); printstack(s);
}

void push(struct stack* s,struct node* new){
    new->next=s->head->next;
    s->head->next=new;
    s->n+=1;
}
struct node* pop(struct stack* s){
    struct node* buf=(struct node*)malloc(sizeof(struct node));
    buf=s->head->next;
    s->head->next=s->head->next->next;
    s->n-=1;
    return buf;
}
void printstack(struct stack* s){
    unsigned char i;
    struct node* buf=(struct node*)malloc(sizeof(struct node));
    buf=s->head->next;
    for(i=0;i<s->n;i++){printf("%hhu ",buf->v);buf=buf->next;}
    printf("\n");
}
```
```
$ ./test
4 3 2 1 0 # 초기 스택
pop: 4, printstack: 3 2 1 0 
pop: 3, printstack: 2 1 0 
pop: 2, printstack: 1 0 
```



## 2.4 큐
### 2.4절 구현체 요약
||구현체|기능|
|---|---|---|
|2.4.1 순차 큐|||
|2.4.2 연결 큐|원형 연결리스트|enqueue()<br>dequeue()|
|2.4.3 데크|양방향 연결리스트|enqueue_front()<br>dequeue_front()<br>enqueue_rear()<br>dequeue_rear()|
<!-- ### 2.4.1 순차 큐
#### 순차 큐
```C
``` -->
### 2.4.2 연결 큐
#### 연결 큐
```C
#include<stdio.h>
#include<stdlib.h>

struct node{
    unsigned char v;
    struct node* next;
};

struct queue{
    unsigned char n; //노드 개수
    struct node* head;
    struct node* tail;
};

void enqueue(struct queue* q, struct node* new);
struct node* dequeue(struct queue* q);
void printqueue(struct queue* q);

int main(void){
    unsigned char i;
    struct node* new;
    // 큐 생성
    struct queue* q=(struct queue*)malloc(sizeof(struct queue));
    q->n=0;
    q->head=(struct node*)malloc(sizeof(struct node));
    q->head->v=255;
    q->head->next=NULL;
    q->tail=q->head;

    // 큐 초기화
    for(i=0;i<5;i++){
        new=(struct node*)malloc(sizeof(struct node));
        new->v=i;
        new->next=NULL;
        enqueue(q,new);
    }
    printqueue(q);
    printf("dequeue: %hhu, printqueue: ",dequeue(q)->v); printqueue(q);
    printf("dequeue: %hhu, printqueue: ",dequeue(q)->v); printqueue(q);
    printf("dequeue: %hhu, printqueue: ",dequeue(q)->v); printqueue(q);
}

void enqueue(struct queue* q, struct node* new){
    struct node* buf=(struct node*)malloc(sizeof(struct node));
    buf=q->tail;
    buf->next=new;
    q->tail=new;
    q->n+=1;
}
struct node* dequeue(struct queue* q){
    struct node* buf=(struct node*)malloc(sizeof(struct node));
    buf=q->head->next;
    q->head->next=q->head->next->next;
    q->n-=1;
    return buf;
}
void printqueue(struct queue* q){
    unsigned char i;
    struct node* buf=(struct node*)malloc(sizeof(struct node));
    buf=q->head->next;
    for(i=0;i<q->n;i++){printf("%hhu ",buf->v);buf=buf->next;}
    printf("\n");
}
```
```
$ ./test
0 1 2 3 4 # 초기 큐
dequeue: 0, printquueue: 1 2 3 4 
dequeue: 1, printquueue: 2 3 4 
dequeue: 2, printquueue: 3 4 
```
### 2.4.3 데크
#### 데크
```C
#include<stdio.h>
#include<stdlib.h>

struct node{
    unsigned char v;
    struct node* prev;
    struct node* next;
};

struct deque{
    unsigned char n; //노드 개수
    struct node* head;
};

void enqueue_front(struct deque* d,struct node* new);
void enqueue_rear (struct deque* d,struct node* new);
struct node* dequeue_front(struct deque* d);
struct node* dequeue_rear (struct deque* d);
void printdeque(struct deque* d);

int main(void){
    unsigned char i;
    struct node* new;
    // 데크 생성
    struct deque* d=(struct deque*)malloc(sizeof(struct deque));
    d->n=0;
    d->head=(struct node*)malloc(sizeof(malloc));
    d->head->v=255;
    d->head->prev=d->head;
    d->head->next=d->head;

    // 데크 초기화: enqueue_rear
    for(i=3;i<6;i++){
        new=(struct node*)malloc(sizeof(struct node));
        new->v=i; new->prev=NULL; new->next=NULL;
        enqueue_rear(d,new);
    }
    printdeque(d);
    // 데크 초기화: enqueue_front
    for(i=2;i!=255;i--){ // 부호 없는 자료형: 2, 1, 0 enqueue
        new=(struct node*)malloc(sizeof(struct node));
        new->v=i; new->prev=NULL; new->next=NULL;
        enqueue_front(d,new);
    }
    printdeque(d);
    // dequeue_front(), dequeue_rear()
    printf("dequeue_front: %hhu ,printdeque: ",dequeue_front(d)->v); printdeque(d);
    printf("dequeue_rear:  %hhu ,printdeque: ",dequeue_rear(d)->v);  printdeque(d);
}

void enqueue_front(struct deque* d,struct node* new){
    struct node* buf=(struct node*)malloc(sizeof(struct node));
    buf=d->head;
    new->prev=buf;
    new->next=buf->next;
    buf->next->prev=new;
    buf->next=new;
    d->n+=1;
}
void enqueue_rear (struct deque* d,struct node* new){
    struct node* buf=(struct node*)malloc(sizeof(struct node));
    buf=d->head->prev;
    new->prev=buf;
    new->next=buf->next;
    buf->next->prev=new;
    buf->next=new;
    d->n+=1;
}
struct node* dequeue_front(struct deque* d){
    struct node* buf=(struct node*)malloc(sizeof(struct node));
    buf=d->head->next;
    buf->prev->next=buf->next;
    buf->next->prev=buf->prev;
    d->n-=1;
    return buf;
}
struct node* dequeue_rear (struct deque* d){
    struct node* buf=(struct node*)malloc(sizeof(struct node));
    buf=d->head->prev;
    buf->prev->next=buf->next;
    buf->next->prev=buf->prev;
    d->n-=1;
    return buf;
}
void printdeque(struct deque* d){
    unsigned char i;
    struct node* buf=(struct node*)malloc(sizeof(struct node));
    buf=d->head->next;
    for(i=0;i<d->n;i++){printf("%hhu ",buf->v);buf=buf->next;}
    printf("\n");
}
```
```
$ ./test
3 4 5 
0 1 2 3 4 5 
dequeue_front: 0 ,printdeque: 1 2 3 4 5 
dequeue_rear:  5 ,printdeque: 1 2 3 4 
```