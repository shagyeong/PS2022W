// P5 1761: 정점들의 거리(희소배열,LCA,트리DP)
// DFS: 트리 파악
// 희소배열(DP테이블 역할) 작성
// LCA: DP 테이블 쿼리(인자: 두 노드)하여 거리 리턴

#include<stdio.h>
#include<stdlib.h>

#define N 40001
#define L 16 // log_2 400001 + 1
#define NOTVIST 0
#define ALLDONE 1

struct node{
    int v;
    int w;
    struct node* next;
};
struct graph{
    int n; // number of node
    struct node* adjs[N];
    int          pare[N][L]; // parent
    int          dept[N];    // depth
    int          dist[N];    // distance
    int          vist[N];    // 방문상태
};

struct graph g;
int q[N]; // queue

void    dfs(struct graph* g,int u);
void sparse(struct graph* g);
int     lca(struct graph* g,int u,int v);
void   init(struct graph* g,int n);
void insert(struct graph* g,int u,int v,int w);

int main(void){
    int j;
    int n; int m;
    int u; int v; int w;
    scanf("%d",&n);
    init(&g,n+1);
    for(j=0;j<n-1;j++){
        scanf("%d %d %d",&u,&v,&w);
        insert(&g,u,v,w);
        insert(&g,v,u,w);
    }
    
    dfs(&g,1);
    sparse(&g);

    scanf("%d",&m);
    for(j=0;j<m;j++){
        scanf("%d %d",&u,&v);
        printf("%d\n",lca(&g,u,v));
    }
}

void    dfs(struct graph* g,int u){
    int f=0;     // front of queue
    int r=0;     // rear of queue
    int d;       // node(dequeue)
    struct node* c; // node(adjs)

    g->vist[u]=ALLDONE;
    q[r++]=u;    // enqueue
    while(f<r){
        d=q[f++]; // dequeue
        c=g->adjs[d];
        while((c=c->next)!=NULL){
            if(g->vist[c->v]==NOTVIST){
                g->dept[c->v]=g->dept[d]+1;
                g->dist[c->v]=g->dist[d]+c->w;
                g->pare[c->v][0]=d;
                q[r++]=c->v;
                g->vist[c->v]=ALLDONE;
            }
        }
    }
}
void sparse(struct graph* g){
    int j;
    int k;
    for(j=1;j<L;j++){
    for(k=1;k<g->n;k++){
        g->pare[k][j]=g->pare[g->pare[k][j-1]][j-1];
    }}
}
int lca(struct graph* g,int u,int v){
    int j; // loop variable
    int s=u;
    int e=v;
    int d; // depth 차분
    int t; // tmp(swap)
    int l; // LCA

    if(g->dept[u]<g->dept[v]){t=u;u=v;v=t;}

    d=g->dept[u]-g->dept[v];
    for(j=0;j<L;j++){
        if((d>>j)&1){
            u=g->pare[u][j];
        }
    }

    l=u;
    if(u!=v){
        for(j=L-1;j>=0;j--){
            if(g->pare[u][j]!=g->pare[v][j]){
                u=g->pare[u][j];
                v=g->pare[v][j];
            }
        }
        l=g->pare[u][0];
    }
    return g->dist[s]+g->dist[e]-2*g->dist[l];
}
void init(struct graph* g,int n){
    int j;
    int k;
    g->n=n;
    for(j=0;j<n;j++){
        g->adjs[j]=(struct node*)malloc(sizeof(struct node));
        g->adjs[j]->v=j;
        g->adjs[j]->w=0;
        g->adjs[j]->next=NULL;
        for(k=0;k<L;k++){g->pare[j][k]=0;}
        g->dept[j]=0;
        g->dist[j]=0;
        g->vist[j]=NOTVIST;
    }
}
void insert(struct graph* g,int u,int v,int w){
    struct node* n=(struct node*)malloc(sizeof(struct node)); // new
    n->v=v;
    n->w=w;
    n->next=g->adjs[u]->next;
    g->adjs[u]->next=n;
}