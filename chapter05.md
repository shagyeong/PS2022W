# 5장 트리
## 5.1 트리
### 5.1.1 이진 트리
#### 선형 이진 트리
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
#### 선형 이진 트리
```C
struct tree{
    int  n; // number of item
    int* a; // array: 선형 트리
};
```
#### 연결 이진 트리
```C
struct node{
    int v;          // value
    struct node* l; // lchild
    struct node* r; // rchild
}
struct tree{
    int n;          // number of item
    struct node* r; // root
}
```
<!-- 5.1.2 스레드 이진 트리 -->



## 5.2 트리 탐색
### 5.2.1 선형 이진 트리 탐색
#### 선형 이진 트리 탐색
DFS: 재귀, 스택  
BFS: 큐, 배열 출력  
#### 선형 이진 트리 탐색
```C
#include<stdio.h>
#include<stdlib.h>

struct tree{
    int  n; // number of item
    int* a; // array: 선형 트리
};

void dfs_r(struct tree* t,int r); // 재귀 DFS
void dfs_s(struct tree* t,int r); // 스택 DFS
void bfs_q(struct tree* t,int r); // 큐 BFS
void bfs_a(struct tree* t);       // 배열 출력 BFS(루트에서만 동작)

int main(void){
    int n=7;
    int a[8]={0,1,2,3,4,5,6,7}; // 8=7+1: 1부터 시작하는 선형 트리 인덱스
    struct tree t;
    t.n=n;
    t.a=&a[0];
    printf("DFS(recursion): "); dfs_r(&t,1); printf("\n");
    printf("DFS(stack):     "); dfs_s(&t,1); printf("\n");
    printf("BFS(queue):     "); bfs_q(&t,1); printf("\n");
    printf("BFS(array):     "); bfs_a(&t);   printf("\n");
}

void dfs_r(struct tree* t,int r){
    if(r>t->n){return;}
    printf("%d ",t->a[r]); // preorder
    dfs_r(t,r*2);   // lchild
    dfs_r(t,r*2+1); // rchild
}
void dfs_s(struct tree* t,int r){
    int b;
    int s[t->n+1]; // stack
    int h=0;       // head
    s[h++]=r; // push
    while(h>0){
        b=s[--h]; // pop
            printf("%d ",t->a[b]);
            if(2*b+1<=t->n){s[h++]=2*b+1;} // push rchild
            if(2*b  <=t->n){s[h++]=2*b;}   // push lchild
    }
}
void bfs_q(struct tree* t,int r){
    int b;
    int q[t->n+1]; // queue
    int s=0;       // start
    int e=0;       // end
    q[e++]=r; //enqueue
    while(s<e){
        b=q[s++]; // dequeue
        printf("%d ",t->a[b]); 
        if(2*b  <=t->n){q[e++]=2*b;}   // enqueue lchild
        if(2*b+1<=t->n){q[e++]=2*b+1;} // dequeue rchild
    }
}
void bfs_a(struct tree* t){
    int j;
    for(j=1;j<=t->n;j++){printf("%d ",t->a[j]);}
}
```
```
$ ./test
DFS(recursion): 1 2 4 5 3 6 7 
DFS(stack):     1 2 4 5 3 6 7 
BFS(queue):     1 2 3 4 5 6 7 
BFS(array):     1 2 3 4 5 6 7 
```
### 5.2.2 연결 이진 트리 탐색
#### 연결 이진 트리 탐색
DFS: 재귀, 스택  
BFS: 큐  
<!-- #### 연결 이진 트리 탐색
```C
```
```
``` -->



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
    struct tree* t=(struct tree*)malloc(sizeof(struct tree));
    t->root=(struct node*)malloc(sizeof(struct node));
    t->root->v=8;
    t->root->l=NULL;
    t->root->r=NULL;
    insert(t,3);  insert(t,10);
    insert(t,2);  insert(t,5);  insert(t,14);
    insert(t,11); insert(t,16);

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
        if(v==b->v){return b;}
        if(v>b->v){b=b->r;}
    }
    return b; // NULL
}
char insert(struct tree* t,char v){
    struct node* b=t->root;
    struct node* p=b; // parent
    while(b!=NULL){
        if     (v< b->v){p=b; b=b->l;}
        else if(v==b->v){return -1;} // 중복 엘리먼트 삽입
        else            {p=b; b=b->r;}
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
        if     (v< b->v){p=b; b=b->l;}
        else if(v==b->v){break;}
        else            {p=b; b=b->r;}
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



## 5.4 힙
### 5.4.1 힙
#### 힙(최대 힙)
```C
#include<stdio.h>
#include<stdlib.h>

struct heap{
    int* a; // array: 선형 트리
    int  i; // item: 엘리먼트 개수
};

void push(struct heap* h,int v);
int   pop(struct heap* h);

int main(void){
    int a[10];
    struct heap h;
    h.a=&a[0];
    h.i=0;
    push(&h,1);
    push(&h,4);
    push(&h,2);
    push(&h,3);
    printf("pop: %d\n",pop(&h));
    printf("pop: %d\n",pop(&h));
    printf("pop: %d\n",pop(&h));
    printf("pop: %d\n",pop(&h));
}

void push(struct heap* h,int v){
    int j; // loop variable
    int t; // temp variable(swap)
    h->a[++(h->i)]=v; // 선형 트리 마지막 엘리먼트로 삽입
    j=h->i;

    // heapify
 // while((j>1)&&(h->a[j]<h->a[j/2])){ 최소 힙 부등호 방향
    while((j>1)&&(h->a[j]>h->a[j/2])){ // 부모: floor(j/2)
        t=h->a[j];
        h->a[j]=h->a[j/2];
        h->a[j/2]=t;
        j/=2;
    }
}
int pop(struct heap* h){
    int r; // root: 리턴값
    int j; // loop variable
    int t; // temp variable(swap)
    int c; // child

    r=h->a[1]; // 루트
    h->a[1]=h->a[(h->i)--]; // 선형 트리 마지막 엘리먼트를 루트로
    j=1;

    // heapify
    while(j*2<=h->i){
        c=j*2; // lchild
     // if((c+1<=h->i)&&(h->a[c+1]<h->a[c])){ 최소 힙 부등호 방향
        if((c+1<=h->i)&&(h->a[c+1]>h->a[c])){
            c+=1; // rchild: j*2+1
        }
     // if(h->a[j]>=h->a[c]) 최소 힙 부등호 방향
        if(h->a[j]<=h->a[c]){
            break;
        }
        t=h->a[j];
        h->a[j]=h->a[c];
        h->a[c]=t;
        j=c;
    }
    return r;
}
```
```
$ ./test
pop: 4
pop: 3
pop: 2
pop: 1
```



## 5.5 세그먼트 트리
### 5.5.1 세그먼트 트리
#### 세그먼트 트리
leaf 노드: 원본 배열  
non-leaf 노드: 구간합  
#### 구간합
```C
#include<stdio.h>
long long int a[1000001]; // 원본 배열
long long int t[4000004]; // 구간합 트리

void           init(int n,int s,int e);
void         update(int n,int s,int e,int i,long long int v);
long long int query(int n,int s,int e,int l,int r);

int main(void){
    int j; // loop variable
    int n; int m; int k;
    int o; int b; long long int c;

    scanf("%d %d %d",&n,&m,&k);
    for(j=0;j<n;j++){scanf("%lld",&a[j]);}
    init(1,0,n-1);

    for(j=0;j<m+k;j++){
        scanf("%d %d %lld",&o,&b,&c);
        if(o==1){update(1,0,n-1,b-1,c); a[b-1]=c;}
        else    {printf("%lld\n",query(1,0,n-1,b-1,(int)c-1));}
    }
}

void init(int n,int s,int e){
    int m; // middle
    if(s==e){t[n]=a[s]; return;}
    m=(s+e)/2;
    init(2*n,  s,  m);      // lchild
    init(2*n+1,m+1,e);      // rchild
    t[n]=t[2*n]+t[2*n+1]; // 구간합
}
void update(int n,int s,int e,int i,long long int v){
    int m; // middle
    if((i<s)||(i>e)){return;}
    if(s==e){t[n]=v; return;}
    m=(s+e)/2;
    update(2*n,  s,  m,i,v); // lchild
    update(2*n+1,m+1,e,i,v); // rchild
    t[n]=t[2*n]+t[2*n+1];    // 구간합
}
long long int query(int n,int s,int e,int l,int r){
    int m; // middle
    if((l>e)||(r<s))    {return 0;}
    if(((l<=s)&&(e<=r))){return t[n];}
    m=(s+e)/2;
    return query(2*n,s,m,l,r)+query(2*n+1,m+1,e,l,r);
}
```
```
$ ./test > test.txt
5 1 2
1 2 3 4 5 # [*,1,2,3,4,5]
2 2 4     #      2+3+4
1 3 7     # [*,1,2,7,4,5]
2 2 4     #      2+7+4

$ cat test.txt
9       # 2+3+4
13      # 2+7+4
```
#### 구간곱
```C
#include<stdio.h>

#define Q 1000000007

long long int a[1000001]; // 원본 배열
long long int t[4000004]; // 구간곱 트리

void           init(int n,int s,int e);
void         update(int n,int s,int e,int i,long long int v);
long long int query(int n,int s,int e,int l,int r);

int main(void){
    int j; // loop variable
    int n; int m; int k;
    int o; int b; long long int c;

    scanf("%d %d %d",&n,&m,&k);
    for(j=0;j<n;j++){scanf("%lld",&a[j]);}
    init(1,0,n-1);

    for(j=0;j<m+k;j++){
        scanf("%d %d %lld",&o,&b,&c);
        if(o==1){update(1,0,n-1,b-1,c); a[b-1]=c;}
        else    {printf("%lld\n",query(1,0,n-1,b-1,(int)c-1));}
    }
}

void init(int n,int s,int e){
    int m; // middle
    if(s==e){t[n]=a[s]; return;}
    m=(s+e)/2;
    init(2*n,  s,  m);      // lchild
    init(2*n+1,m+1,e);      // rchild
    t[n]=(t[2*n]*t[2*n+1])%Q;
}
void update(int n,int s,int e,int i,long long int v){
    int m; // middle
    if((i<s)||(i>e)){return;}
    if(s==e){t[n]=v; return;}
    m=(s+e)/2;
    update(2*n,  s,  m,i,v); // lchild
    update(2*n+1,m+1,e,i,v); // rchild
    t[n]=(t[2*n]*t[2*n+1])%Q;
}
long long int query(int n,int s,int e,int l,int r){
    int m; // middle
    if((l>e)||(r<s))    {return 1;}
    if(((l<=s)&&(e<=r))){return t[n];}
    m=(s+e)/2;
    return (query(2*n,s,m,l,r)*query(2*n+1,m+1,e,l,r))%Q;
}
```
```
$ ./test > test.txt
5 1 2
1 2 3 4 5   # [*,1,2,3,4,5]
2 2 4       #      2*3*4
1 3 7       # [*,1,2,7,4,5]
2 2 4       #      2*7*4

$ cat test.txt
24          # 2*3*4
56          # 2*7*4
```
