// P3 10891: Cactus? Not cactus?(단절점,선인장)
// 간선풀 재채점
#include<stdio.h>
#include<stdlib.h>

struct node{
    int v;
    int next;
};
struct graph{
    int n; // number of node
    int e; // number of edge
    int a; // number of articular point
    int c; // clock
    int f; // flag: iscactus
    int p; // pool index
    int* adjs;
    int* vist;
    int* dist;
    int* arti;
    int* cycl;
    struct node* pool;
};

void   init(struct graph* g,int n,int e);
void  clean(struct graph* g);
void insert(struct graph* g,int u,int v);
void    dfs(struct graph* g,int u,int p); // p: parent

int main(void){
    int j;
    int n; int e; scanf("%d %d",&n,&e);
    int u; int v;
    struct graph g;
    init(&g,n+1,2*e); // 1-based, undirected
    for(j=0;j<e;j++){
        scanf("%d %d",&u,&v);
        insert(&g,u,v);
        insert(&g,v,u);
    }
    for(j=1;j<=n;j++){if(g.vist[j]==0){dfs(&g,j,0);}}
    if(g.f==1){printf("Cactus");}
    else      {printf("Not cactus");}
    clean(&g);
}

void   init(struct graph* g,int n,int e){
    int j;
    g->n=n;
    g->e=e;
    g->a=0;
    g->c=0;
    g->f=1;
    g->p=0;
    g->adjs=(int*)malloc(sizeof(int)*n);
    g->vist=(int*)malloc(sizeof(int)*n);
    g->dist=(int*)malloc(sizeof(int)*n);
    g->arti=(int*)malloc(sizeof(int)*n);
    g->cycl=(int*)malloc(sizeof(int)*n);
    g->pool=(struct node*)malloc(sizeof(struct node)*e);
    for(j=0;j<n;j++){
        g->adjs[j]=-1;
        g->vist[j]=0;
        g->dist[j]=e+1; // INF: unweighted graph
        g->arti[j]=0;
        g->cycl[j]=0;
    }
}
void  clean(struct graph* g){
    free(g->adjs);
    free(g->vist);
    free(g->dist);
    free(g->arti);
    free(g->cycl);
    free(g->pool);
}
void insert(struct graph* g,int u,int v){
    g->pool[g->p].v=v;
    g->pool[g->p].next=g->adjs[u];
    g->adjs[u]=g->p++;
}
void    dfs(struct graph* g,int u,int p){
    int d=g->adjs[u];
    int v;
    g->vist[u]=++g->c;
    g->dist[u]=  g->c;
    while(d!=-1){
        v=g->pool[d].v;
        if(v==p){d=g->pool[d].next; continue;}
        if(g->vist[v]==0){
            dfs(g,v,u);
            if(g->cycl[v]>0){
                if(g->arti[u]>0){g->f=0;}
                g->arti[u]=1;
            }
            g->dist[u]=((g->dist[u])<(g->dist[v]))?(g->dist[u]):(g->dist[v]);
            g->cycl[u]+=g->cycl[v];
        }
        else if(g->vist[v]<g->vist[u]){
            if(g->arti[u]>0){g->f=0;}
            g->arti[u]=1;
            g->dist[u]=((g->dist[u])<(g->vist[v]))?g->dist[u]:g->vist[v];
            g->cycl[u]++;
            g->cycl[v]--;
        }
        d=g->pool[d].next;
    }
    if(g->cycl[u]>=2){g->f=0;}
}