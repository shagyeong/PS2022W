# 5장 트리
## 5.1 트리
### 5.1.1 이진 트리
#### 이진 트리
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
<!-- ### 5.1.3 힙 -->



<!-- ## 5.2 트리 탐색
### 5.2.1 DFS
#### 전위 순회
```C
```
```
```
#### 중위 순회
```C
```
```
```
#### 후위 순회
```C
```
```
```
### 5.2.2 BFS -->



<!-- ## 5.3 이진 탐색 트리 -->
<!-- ### 5.3.1 이진 탐색 트리 -->
<!-- ### 5.3.2 AVL 트리 -->
<!-- ### 5.3.3 RB트리 -->
