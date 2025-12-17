# 6장 그래프
## 6.1 그래프
<!-- ### 6.1.1 인접행렬
#### 그래프 구현: 인접행렬
```C
```
```
``` -->
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



<!-- ## 6.2 그래프 탐색 -->
<!-- ### 6.2.1 DFS -->
<!-- ### 6.2.2 BFS -->
<!-- ### 6.2.3 다이크스트라 -->
<!-- ### 6.2.4 플로이드-워셜 -->
