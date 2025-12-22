# 6장 그래프
## 6.1 그래프
### 6.1.1 인접행렬
#### 그래프 구현: 인접행렬
```C
#include<stdio.h>
#include<stdlib.h>

# define N 10 // 노드 최대 개수

struct graph{
    unsigned char adjs[N][N];
};

void printgraph(struct graph* g);
void insert(struct graph* g,unsigned char u,unsigned char v,unsigned char w); // u->v

int main(void){
    struct graph* g=(struct graph*)malloc(sizeof(struct graph));
    insert(g,0,4,255);insert(g,4,0,255);
    insert(g,0,1,255);insert(g,1,0,255);
    insert(g,0,2,255);insert(g,2,0,255);
    printgraph(g);
}
void printgraph(struct graph* g){
    unsigned char j;
    unsigned char k;
    for(j=0;j<N;j++){
        printf("node %u's adjs: ",j);
        for(k=0;k<N;k++){if(g->adjs[j][k]!=0){printf("%u ",k);}}
        printf("\n");
    }
}
void insert(struct graph* g,unsigned char u,unsigned char v,unsigned char w){
    g->adjs[u][v]=w;
}
```
```
$ ./test
node 0's adjs: 1 2 4 
node 1's adjs: 0 
node 2's adjs: 0 
node 3's adjs: 
node 4's adjs: 0 
node 5's adjs: 
node 6's adjs: 
node 7's adjs: 
node 8's adjs: 
node 9's adjs: 
```
### 6.1.2 인접리스트
#### 그래프 구현: 인접리스트
```C
#include<stdio.h>
#include<stdlib.h>

#define N 10 // 노드 최대 개수

struct node{
    unsigned char v; // value: 0 ~ N-1, 인접리스트 인덱스 겸용
    unsigned char w; // weight
    struct node* next;
};

struct graph{
    unsigned char n; // 노드 개수
    struct node* adjs[N];
};

void printgraph(struct graph* g);
void init_graph(struct graph* g, unsigned char n);
void insert(struct graph* g,unsigned char u,unsigned char v,unsigned char w); // u->v

int main(void){
    struct graph* g=(struct graph*)malloc(sizeof(struct graph));
    init_graph(g,N);
    insert(g,0,4,255);insert(g,4,0,255);
    insert(g,0,1,255);insert(g,1,0,255);
    insert(g,0,2,255);insert(g,2,0,255);
    printgraph(g);
}
void printgraph(struct graph* g){
    unsigned char j;
    struct node* B=(struct node*)malloc(sizeof(struct node));
    for(j=0;j<g->n;j++){
        B=g->adjs[j]; printf("node %u's adjs: ",B->v);
        B=B->next;
        while(B!=NULL){
            printf("%u ",B->v);
            B=B->next;
        }
        printf("\n");
    }
}
void init_graph(struct graph* g,unsigned char n){
    unsigned char j;
    struct node* new;
    for(j=0;j<n;j++){
        new=(struct node*)malloc(sizeof(struct node));
        new->v=j;
        new->w=0;
        new->next=NULL;
        g->adjs[j]=new;
    }
    g->n=n;
}
void insert(struct graph* g,unsigned char u,unsigned char v,unsigned char w){
    struct node* B=(struct node*)malloc(sizeof(struct node)); // 버퍼
    struct node* V=(struct node*)malloc(sizeof(struct node));
    V->v=v;
    V->w=w;
    V->next=NULL;
    B=g->adjs[u];
    while((B->next!=NULL)&&(v>B->next->v)){B=B->next;}
    V->next=B->next;
    B->next=V;
}
```
```
$ ./test
node 0's adjs: 1 2 4 
node 1's adjs: 0 
node 2's adjs: 0 
node 3's adjs: 
node 4's adjs: 0 
node 5's adjs: 
node 6's adjs: 
node 7's adjs: 
node 8's adjs: 
node 9's adjs: 
```



## 6.2 그래프 탐색
### 6.2.1 DFS
#### DFS
```C
#include<stdio.h>
#include<stdlib.h>

#define N 10 // 노드 최대 개수
#define NOTVIST 0 //
#define PROCESS 1
#define ALLDONE 2 //

struct node{
    unsigned char v; // value: 0 ~ N-1, 인접리스트 인덱스 겸용
    unsigned char w; // weight
    struct node* next;
};

struct graph{
    unsigned char n; // 노드 개수
    struct node*  adjs[N];
    unsigned char vist[N]; // 방문 상태 관리
};

void dfs(struct graph* g,unsigned char s); // s: 시작 노드
void printgraph(struct graph* g);
void init_graph(struct graph* g, unsigned char n);
void insert(struct graph* g,unsigned char u,unsigned char v,unsigned char w); // u->v

int main(void){
    struct graph* g=(struct graph*)malloc(sizeof(struct graph));
    init_graph(g,N);

    insert(g,0,1,255);insert(g,1,0,255);
    insert(g,0,2,255);insert(g,2,0,255);
    insert(g,1,3,255);insert(g,3,1,255);
    insert(g,1,4,255);insert(g,4,1,255);
    insert(g,2,4,255);insert(g,4,2,255);
    insert(g,3,6,255);insert(g,6,3,255);
    insert(g,4,6,255);insert(g,6,4,255);
    insert(g,5,6,255);insert(g,6,5,255);
    printgraph(g);
    printf("dfs: "); dfs(g,0); printf("\n");
}

void dfs(struct graph* g,unsigned char s){
    unsigned char j;
    struct node* b=(struct node*)malloc(sizeof(struct node));
    printf("%u ",s);
    b=g->adjs[s];
    g->vist[s]=PROCESS;
    while((b=b->next)!=NULL){
        j=b->v;
        if(g->vist[j]==NOTVIST){dfs(g,j);}
    }
    g->vist[s]=ALLDONE;
}
void printgraph(struct graph* g){
    unsigned char j;
    struct node* B=(struct node*)malloc(sizeof(struct node));
    for(j=0;j<g->n;j++){
        B=g->adjs[j]; printf("node %u's adjs: ",B->v);
        B=B->next;
        while(B!=NULL){
            printf("%u ",B->v);
            B=B->next;
        }
        printf("\n");
    }
}
void init_graph(struct graph* g,unsigned char n){
    unsigned char j;
    struct node* new;
    for(j=0;j<n;j++){
        new=(struct node*)malloc(sizeof(struct node));
        new->v=j;
        new->w=0;
        new->next=NULL;
        g->adjs[j]=new;
        g->vist[j]=NOTVIST;
    }
    g->n=n;
}
void insert(struct graph* g,unsigned char u,unsigned char v,unsigned char w){
    struct node* B=(struct node*)malloc(sizeof(struct node)); // 버퍼
    struct node* V=(struct node*)malloc(sizeof(struct node));
    V->v=v;
    V->w=w;
    V->next=NULL;
    B=g->adjs[u];
    while((B->next!=NULL)&&(v>B->next->v)){B=B->next;}
    V->next=B->next;
    B->next=V;
}
```
```
$ ./test
node 0's adjs: 1 2 
node 1's adjs: 0 3 4 
node 2's adjs: 0 4 
node 3's adjs: 1 6 
node 4's adjs: 1 2 6 
node 5's adjs: 6 
node 6's adjs: 3 4 5 
node 7's adjs: 
node 8's adjs: 
node 9's adjs: 
dfs: 0 1 3 6 4 2 5
```
#### DFS: 스택
```C
void dfs(struct graph* g,unsigned char s){
    unsigned char i=0; // stack index variable
    unsigned char v;   // value buffer
    struct node* b;
    struct node* stack[N*N];
    stack[i++]=g->adjs[s];
    while(i!=0){ // while stack is not empty
        // pop: current node
        b=stack[--i];
        v=b->v;
        if(g->vist[v]==ALLDONE){continue;}
        
        g->vist[v]=ALLDONE;
        printf("%u ",v);
        
        // 인접 노드 확인
        while((b=b->next)!=NULL){
            v=b->v;
            if(g->vist[v]==NOTVIST){
                stack[i++]=g->adjs[v]; // push
            }
        }

    }
}
```
### 6.2.2 BFS
#### BFS: 큐
```C
void bfs(struct graph* g,unsigned char s){
    struct node* b;
    struct node* queue[N*N];
    unsigned char f=0; // queue index variable: front
    unsigned char r=0; // queue index variable: rear
    unsigned char v;   // value buffer

    queue[r++]=g->adjs[s];
    while(f<r){
        b=queue[f++];
        v=b->v;
        if(g->vist[v]==ALLDONE){continue;}
        g->vist[v]=ALLDONE;
        printf("%u ",v);
        while((b=b->next)!=NULL){
            v=b->v;
            if(g->vist[v]==NOTVIST){
                queue[r++]=g->adjs[v];
            }
        }
    }
}
```
```
$ ./test
node 0's adjs: 1 2 
node 1's adjs: 0 3 4 
node 2's adjs: 0 4 
node 3's adjs: 1 6 
node 4's adjs: 1 2 6 
node 5's adjs: 6 
node 6's adjs: 3 4 5 
node 7's adjs: 
node 8's adjs: 
node 9's adjs: 
bfs: 0 1 2 3 4 6 5 
```



<!-- ## 6.3 최단 경로 -->
<!-- ### 6.3.3 다이크스트라 -->
<!-- ### 6.3.4 플로이드-워셜 -->
