// 1240: 노드사이의 거리(그래프 탐색, 트리, BFS)
#include<stdio.h>
#include<stdlib.h>

#define N 1001
#define NOTVIST 0
#define PROCESS 1
#define ALLDONE 2

struct node{
    unsigned short v;
    unsigned short w;
    struct node* next;
};
struct graph{
    unsigned short n;
    struct node*   adjs[N];
    unsigned short vist[N];
    unsigned int   dist[N];  // 누적 거리
};
void printgraph(struct graph* g){
    unsigned short j;
    struct node* B;
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
unsigned int bfs(struct graph* g,unsigned short s,unsigned short e);
void init_graph(struct graph* g,unsigned short n);
void init_vist(struct graph* g);
void init_dist(struct graph* g);
void insert(struct graph* g,unsigned short u,unsigned short v,unsigned short w);

int main(void){
    unsigned short j; // loop variable
    unsigned short u; unsigned short v; unsigned short w;
    unsigned short n;
    unsigned short m;
    struct graph* g=(struct graph*)malloc(sizeof(struct graph));
    scanf("%hu %hu",&n,&m);
    init_graph(g,n+1); // n+1: 1부터 시작하는 과제 인덱스
    for(j=0;j<n-1;j++){
        scanf("%hu %hu %hu",&u,&v,&w);
        insert(g,u,v,w);insert(g,v,u,w);
    }
    // printgraph(g);
    for(j=0;j<m;j++){
        init_vist(g);
        init_dist(g);
        scanf("%hu %hu",&u,&v);
        printf("%u\n",(bfs(g,u,v)));
    }
}
unsigned int bfs(struct graph* g,unsigned short s,unsigned short e){
    struct node* b;
    struct node* queue[(g->n)*(g->n)];
    unsigned short f=0; // queue index variable: front
    unsigned short r=0; // queue index variable: rear
    unsigned short v;   // value buffer
    unsigned short w;   // weight buffer
    unsigned short p;   // parent: vist[v]==부모 노드까지의 누적 거리

    queue[r++]=g->adjs[s];
    // g->vist[s]=ALLDONE;

    while(f<r){
        b=queue[f++];
        v=b->v;
        if(v==e){return g->dist[v];}
        if(g->vist[v]==ALLDONE){continue;}
        g->vist[v]=ALLDONE;

        p=b->v;
        while((b=b->next)!=NULL){
            v=b->v;
            w=b->w;
            if(g->vist[v]==NOTVIST){
                g->dist[v]=g->dist[p]+w;
                queue[r++]=g->adjs[v];
            }
        }
    }
    return -1;
}
void init_graph(struct graph* g,unsigned short n){
    unsigned short j;
    struct node* new;
    for(j=0;j<n;j++){
        new=(struct node*)malloc(sizeof(struct node));
        new->v=j;
        new->w=0;
        new->next=NULL;
        g->adjs[j]=new;
        g->vist[j]=NOTVIST;
        g->dist[j]=0;
    }
    g->n=n;
}
void init_vist(struct graph* g){
    unsigned short j;
    for(j=0;j<g->n;j++){
        g->vist[j]=NOTVIST;
    }
}
void init_dist(struct graph* g){
    unsigned short j;
    for(j=0;j<g->n;j++){
        g->dist[j]=0;
    }
}
void insert(struct graph* g,unsigned short u,unsigned short v,unsigned short w){
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