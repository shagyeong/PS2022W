# 5장 트리
## 5.1 트리
### 5.1.1 이진 트리
|노드|선형 인덱스|
|---|---|
|root|1|
|parent(i)|$\lfloor i/2\rfloor$|
|leftchild(i)|$i\times2$|
|rightchild(i)|$i\times2+1$|

```
            1
    2               3
4       5       6       7
...
```
#### 이진 트리: 연결
```C
#include<stdio.h>
#include<stdlib.h>

struct node{
    char v;
    struct node* l;
    struct node* r;
};

struct tree{
    struct node* root;
};

int main(void){
    struct node* a=(struct node*)malloc(sizeof(struct node));
    struct node* b=(struct node*)malloc(sizeof(struct node));
    struct node* c=(struct node*)malloc(sizeof(struct node));
    struct node* d=(struct node*)malloc(sizeof(struct node));
    struct node* e=(struct node*)malloc(sizeof(struct node));
    struct node* f=(struct node*)malloc(sizeof(struct node));
    struct node* g=(struct node*)malloc(sizeof(struct node));
    a->v='a'; a->l=b;    a->r=c;
    b->v='b'; b->l=d;    b->r=e;
    c->v='c'; c->l=f;    c->r=g;
    d->v='d'; d->l=NULL; d->r=NULL; // leaf
    e->v='e'; e->l=NULL; e->r=NULL; // leaf
    f->v='f'; f->l=NULL; f->r=NULL; // leaf
    g->v='g'; g->l=NULL; g->r=NULL; // leaf

    struct tree* t=(struct tree*)malloc(sizeof(struct tree));
    t->root=a;

    printf("%c\n",t->root->v);
    printf("%c\t",t->root->l->v);
    printf("%c\n",t->root->r->v);
    printf("%c\t",t->root->l->l->v);
    printf("%c\t",t->root->l->r->v);
    printf("%c\t",t->root->r->l->v);
    printf("%c\n",t->root->r->r->v);
}
```
```
$ ./test
a
b       c
d       e       f       g
```
<!-- ### 5.1.2 스레드 이진 트리 -->



## 5.2 트리 탐색
### 5.2.1 DFS
#### 전위 순회, 중위 순회, 후위 순회
```C
#include<stdio.h>
#include<stdlib.h>

struct node{
    char v;
    struct node* l;
    struct node* r;
};

struct tree{
    struct node* root;
};

// r: (서브)트리 루트
void preorder (struct node* r);
void inorder  (struct node* r);
void postorder(struct node* r);

int main(void){
    struct node* a=(struct node*)malloc(sizeof(struct node));
    struct node* b=(struct node*)malloc(sizeof(struct node));
    struct node* c=(struct node*)malloc(sizeof(struct node));
    struct node* d=(struct node*)malloc(sizeof(struct node));
    struct node* e=(struct node*)malloc(sizeof(struct node));
    struct node* f=(struct node*)malloc(sizeof(struct node));
    struct node* g=(struct node*)malloc(sizeof(struct node));
    a->v='a'; a->l=b;    a->r=c;
    b->v='b'; b->l=d;    b->r=e;
    c->v='c'; c->l=f;    c->r=g;
    d->v='d'; d->l=NULL; d->r=NULL; // leaf
    e->v='e'; e->l=NULL; e->r=NULL; // leaf
    f->v='f'; f->l=NULL; f->r=NULL; // leaf
    g->v='g'; g->l=NULL; g->r=NULL; // leaf

    struct tree* t=(struct tree*)malloc(sizeof(struct tree));
    t->root=a;

    printf("preorder: ");preorder(t->root);  printf("\n");
    printf("inorder:  ");inorder(t->root);   printf("\n");
    printf("postorder:");postorder(t->root); printf("\n");
}

void preorder (struct node* r){
    if(r!=NULL){
        printf("%c ",r->v);
        preorder(r->l);
        preorder(r->r);
    }
}
void inorder  (struct node* r){
    if(r!=NULL){
        inorder(r->l);
        printf("%c ",r->v);
        inorder(r->r);
    }
}
void postorder(struct node* r){
    if(r!=NULL){
        postorder(r->l);
        postorder(r->r);
        printf("%c ",r->v);
    }
}
```
```
$ ./test
preorder: a b d e c f g 
inorder:  d b e a f c g 
postorder:d e b f g c a 
```
### 5.2.2 BFS
#### BFS
```C
#include<stdio.h>
#include<stdlib.h>

struct node{
    char v;
    struct node* l;
    struct node* r;
};

struct tree{
    struct node* root;
};

void bfs(struct tree* t);

int main(void){
    struct node* a=(struct node*)malloc(sizeof(struct node));
    struct node* b=(struct node*)malloc(sizeof(struct node));
    struct node* c=(struct node*)malloc(sizeof(struct node));
    struct node* d=(struct node*)malloc(sizeof(struct node));
    struct node* e=(struct node*)malloc(sizeof(struct node));
    struct node* f=(struct node*)malloc(sizeof(struct node));
    struct node* g=(struct node*)malloc(sizeof(struct node));
    a->v='a'; a->l=b;    a->r=c;
    b->v='b'; b->l=d;    b->r=e;
    c->v='c'; c->l=f;    c->r=g;
    d->v='d'; d->l=NULL; d->r=NULL; // leaf
    e->v='e'; e->l=NULL; e->r=NULL; // leaf
    f->v='f'; f->l=NULL; f->r=NULL; // leaf
    g->v='g'; g->l=NULL; g->r=NULL; // leaf

    struct tree* t=(struct tree*)malloc(sizeof(struct tree));
    t->root=a;

    printf("bfs: "); bfs(t); printf("\n");
}

void bfs(struct tree* t){
    struct node* b;      // buffer
    struct node* q[256]; // 선형 큐
    unsigned char f=0;   // front
    unsigned char r=0;   // rear
    q[r++]=t->root;
    while(f<r){
        b=q[f++];
        printf("%c ",b->v);
        if(b->l!=NULL){q[r++]=b->l;}
        if(b->r!=NULL){q[r++]=b->r;}
    }
}
```
```
$ ./test
bfs: a b c d e f g 
```



## 5.3 이진 탐색 트리
### 5.3.1 이진 탐색 트리
#### 이진 탐색 트리
좌측 서브트리의 모든 원소는 루트보다 작다  
우측 서브트리의 모든 원소는 루트보다 크다  
서브트리도 위 성질을 만족한다  
```
            8
    3               10
2       5               14
                    11      16
```
```C
#include<stdio.h>
#include<stdlib.h>

struct node{
    char v;
    struct node* l;
    struct node* r;
};

struct tree{
    struct node* root;
};

struct node* search(struct tree* t,char v); // 성공: 노드 주소, 실패: NULL
char         insert(struct tree* t,char v); // 실패: -1(중복 노드 삽입 시도)
char         delete(struct tree* t,char v); // 실패: -1

int main(void){
    struct node* a=(struct node*)malloc(sizeof(struct node));
    struct node* b=(struct node*)malloc(sizeof(struct node));
    struct node* c=(struct node*)malloc(sizeof(struct node));
    struct node* d=(struct node*)malloc(sizeof(struct node));
    struct node* e=(struct node*)malloc(sizeof(struct node));
    struct node* f=(struct node*)malloc(sizeof(struct node));
    struct node* g=(struct node*)malloc(sizeof(struct node));
    struct node* h=(struct node*)malloc(sizeof(struct node));
    a->v=8;  a->l=b;    a->r=c;
    b->v=3;  b->l=d;    b->r=e;
    c->v=10; c->l=NULL; c->r=f;
    d->v=2;  d->l=NULL; d->r=NULL;
    e->v=5;  e->l=NULL; e->r=NULL;
    f->v=14; f->l=g;    f->r=h;
    g->v=11; g->l=NULL; g->r=NULL;
    h->v=16; h->l=NULL; h->r=NULL;
    struct tree* t=(struct tree*)malloc(sizeof(struct tree));
    t->root=a;

    printf(" search()\n");
    if(search(t,11)==NULL){printf("11: not found\n");}else{printf("11: found\n");}
    if(search(t,12)==NULL){printf("12: not found\n");}else{printf("12: found\n");}

    printf("\n insert()\n");
    if(insert(t,11)==-1){printf("11: insertion failed\n");}else{printf("11: inserted\n");}
    if(insert(t,12)==-1){printf("12: insertion failed\n");}else{printf("12: inserted\n");}
    if(search(t,12)==NULL){printf("12: not found\n");}else{printf("12: found\n");}

    printf("\n delete()\n");
    if(delete(t,12)==-1){printf("12: deletion failed\n");}else{printf("12: deleted\n");}
    if(delete(t,12)==-1){printf("12: deletion failed\n");}else{printf("12: deleted\n");}
    if(search(t,12)==NULL){printf("12: not found\n");}else{printf("12: found\n");}
}

struct node* search(struct tree* t,char v){
    struct node* b=t->root;
    while(b!=NULL){
        if(v<b->v){b=b->l;}
        else if(v==b->v){return b;}
        else{b=b->r;}
    }
    return b; // NULL
}
char insert(struct tree* t,char v){
    struct node* b=t->root;
    struct node* p=b; // parent
    while(b!=NULL){
        if(v<b->v){p=b; b=b->l;}
        else if(v==b->v){return -1;} // 중복 엘리먼트 삽입
        else{p=b; b=b->r;}
    }
    struct node* n=(struct node*)malloc(sizeof(struct node)); // new
    n->v=v;
    n->l=NULL;
    n->r=NULL;
    if(v<p->v){p->l=n;}
    else      {p->r=n;}
    return 0; // 성공
}
char delete(struct tree* t,char v){
    struct node* b=t->root;
    struct node* p=b; // parent
    while(b!=NULL){
        if(v<b->v){p=b; b=b->l;}
        else if(v==b->v){break;}
        else{p=b; b=b->r;}
    }
    if(b==NULL){return -1;} // 실패(노드 없음)
    if((b->l==NULL)&&(b->r==NULL)){ // 터미널
        if((p->l!=NULL)&&(p->l==b)){p->l=NULL;}
        else                       {p->r=NULL;}
    }
    else if((b->l==NULL)||(b->r==NULL)){ // 서브 트리 1개
        if((p->l!=NULL)&&(p->l==b)){p->l=(b->l!=NULL)?b->l:b->r;}
        else                       {p->r=(b->l!=NULL)?b->l:b->r;}
    }
    else{   //서브트리 2개: 좌측 서브 트리 최소값 또는 우측 서브 트리 최대값를 루트(후임)로
        struct node* f=b;    // parent of successor
        struct node* s=b->r; // successor
        while(s->l!=NULL){f=s; s=s->l;}
        b->v=s->v; // 덮어씀
        if(b==f){f->r=s->r;} // 서브트리 루트가 후임
        else    {f->l=s->r;} // 일반적인 경우(후임 노드 우측 서브트리 편입)
    }
    return 0;
}
```
```
$ ./test
 search()
11: found
12: not found

 insert()
11: insertion failed
12: inserted
12: found

 delete()
12: deleted
12: deletion failed
12: not found
```
<!-- ### 5.3.2 AVL 트리 -->
<!-- ### 5.3.3 RB트리 -->
<!-- ## 5.4 힙 -->
<!-- ### 5.4.1 -->
