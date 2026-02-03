# 3장 트리
## 3.1 트리 구현및 탐색
### 3.1.1 트리 구현
#### 선형이진트리
|노드|선형 인덱스|
|---|---|
|root|1|
|parent(i)|$\lfloor i/2\rfloor$|
|leftchild(i)|$i\times2$|
|rightchild(i)|$i\times2+1$|

```C
struct tree{
    int  n; // number of item
    int* a; // array: 선형 트리
};
```
#### 연결다진트리
```C
struct tree{
    struct node* r; // root
};
struct node{
    struct node** c; // child
};
```
### 3.2.1 트리 탐색: 선형이진트리
#### DFS: 재귀
```C
#include<stdio.h>
#include<stdlib.h>

struct tree{
    int n;
    int* a;
};

void   dfs(struct tree* t,int r);

int main(void){
    int j;
    int n; scanf("%d",&n);
    int r; scanf("%d",&r);
    int* a=(int*)malloc(sizeof(int)*(n+1)); // n+1: 1부터 시작하는 선형이진트리 인덱스
    struct tree t;
    t.n=n;
    t.a=&a[0];
    for(j=1;j<=n;j++){scanf("%d",&a[j]);}
    printf("dfs: "); dfs(&t,1);
    free(a);
}

void   dfs(struct tree* t,int r){
    if(r>t->n){return;}
    printf("%d ",t->a[r]); // preorder
    dfs(t,2*r);  // lchild
    dfs(t,2*r+1);// rchild
}
```
```
$ ./test
7 # number of node
1 # start
1 2 3 4 5 6 7
dfs: 1 2 4 5 3 6 7 
```
#### DFS: 스택
```C
void   dfs(struct tree* t,int r){
    int d;
    int* s=(int*)malloc(sizeof(int)*(t->n+1)); // stack
    int h=0; // top of stack
    s[h++]=r; // push
    while(h>0){
        d=s[--h]; // pop
        printf("%d ",t->a[d]);
        if(2*d+1<=t->n){s[h++]=2*d+1;} // push rchild
        if(2*d  <=t->n){s[h++]=2*d;}   // push lchild
    }
    free(s);
}
```
#### BFS: 큐
```C
void   bfs(struct tree* t,int r){
    int d;
    int* q=(int*)malloc(sizeof(int)*(t->n+1)); // queue
    int s=0; // front of queue
    int e=0; // rear of queue
    q[e++]=r; // enqueue
    while(s<e){
        d=q[s++]; // dequeue
        printf("%d ",t->a[d]);
        if(2*d  <=t->n){q[e++]=2*d;}   // enqueue lchild
        if(2*d+1<=t->n){q[e++]=2*d+1;} // dequeue rchild
    }
    free(q);
}
```
#### BFS: 배열 출력
루트에서만 동작함  
```
            1
    2               3
4       5       6       7
(...)
```
```C
void   bfs(struct tree* t){
    int j;
    for(j=1;j<=t->n;j++){o=printf("%d ",t->a[j]);}
}
```



## 3.2 포인트 쿼리
### 3.2.1 힙
#### 힙(최대 힙)
최소 힙: heapify 부등호 방향 토글  
```C
#include<stdio.h>
#include<stdlib.h>

struct heap{
    int* a;
    int  n;
};

void push(struct heap* h,int v);
int   pop(struct heap* h);

int main(void){
    int j;
    int n; scanf("%d",&n);
    int v;
    struct heap h;
    h.a=(int*)malloc(sizeof(int)*(n+1));
    h.n=0;
    for(j=0;j<n;j++){scanf("%d",&v); push(&h,v);}
    for(j=0;j<n;j++){printf("%d ",pop(&h));}
    free(h.a);
}

void push(struct heap* h,int v){
    int i=++(h->n); // index of tree
    int t;          // temp variable: swap
    
    h->a[i]=v;      // 마지막 엘리먼트로 삽입 후 heapify up
    while((i>1)&&(h->a[i]>h->a[i/2])){
        t=h->a[i];
        h->a[i]=h->a[i/2];
        h->a[i/2]=t;
        i/=2;
    }
}
int pop(struct heap* h){
    int r=h->a[1]; // return value
    int i=1;       // index of tree
    int t;         // temp variable(swap)
    int c;         // child

    h->a[i]=h->a[(h->n)--]; // 루트 덮어쓰기 후 heapify down
    while(i*2<=h->n){
        if((i*2+1<=h->n)&&(h->a[i*2+1]>h->a[i*2])){c=i*2+1;} // rchild
        else                                      {c=i*2;}   // lchild
        if(h->a[i]>=h->a[c]){break;}
        t=h->a[i];
        h->a[i]=h->a[c];
        h->a[c]=t;
        i=c;
    }
    return r;
}
```
```
$ ./test
9
1 3 2 7 8 9 6 4 5
9 8 7 6 5 4 3 2 1 
```
<!-- ### 3.2.2 이진탐색트리 -->
<!-- #### 기본 BST -->
<!-- #### AVL트리 -->
<!-- #### RB트리 -->



## 3.3 구간 쿼리
### 3.3.1 구간 쿼리
#### 기본 세그먼트트리: 구간합
```C
#include<stdio.h>
#include<stdlib.h>

int*           a; // 원본 배열
long long int* t; // 구간합 트리

void           init(int n,int s,int e);
void         update(int n,int s,int e,int i,int v);
long long int query(int n,int s,int e,int l,int r);

int main(void){
    int j; // loop variable
    int n; int m; scanf("%d %d",&n,&m);
    int o; int b; int c;
    a=(int*)          malloc(sizeof(int)            *(n+1));
    t=(long long int*)malloc(sizeof(long long int)*4*(n+1));

    for(j=0;j<n;j++){scanf("%d",&a[j]);}
    init(1,0,n-1);

    for(j=0;j<m;j++){
        scanf("%d %d %d",&o,&b,&c);
        if(o==1){update(1,0,n-1,b-1,c); a[b-1]=c;}
        else    {printf("%lld\n",query(1,0,n-1,b-1,c-1));}
    }

    free(a);
    free(t);
}

void init(int n,int s,int e){
    int m; // middle
    if(s==e){t[n]=a[s]; return;}
    m=(s+e)/2;
    init(2*n,  s,  m);      // lchild
    init(2*n+1,m+1,e);      // rchild
    t[n]=t[2*n]+t[2*n+1]; // 구간합
}
void update(int n,int s,int e,int i,int v){
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
5 3 # number of node, query
1 2 3 4 5 # [*,1,2,3,4,5]
2 2 4     #      2+3+4
1 3 7     # [*,1,2,7,4,5]
2 2 4     #      2+7+4

$ cat test.txt
9       # 2+3+4
13      # 2+7+4
```
<!-- #### 병합정렬트리 -->
<!-- ### 3.3.2 구간 업데이트 -->
<!-- ### 3.3.3 오프라인 쿼리 -->
