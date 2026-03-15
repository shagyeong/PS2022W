// P4 11400: 단절선(단절선)
// 간선풀 재채점
#include<stdio.h>
#include<stdlib.h>

struct node{
    int v;
    int next;
};
struct edge{
    int u;
    int v;
};
struct graph{
    int n; // number of node
    int e; // number of edge
    int a; // number of articular point
    int c; // clock
    int p; // pool index
    int* adjs;
    int* vist;
    int* dist;
    struct edge* arti;
    struct node* pool;
};

void   init(struct graph* g,int n,int e);
void  clean(struct graph* g);
void insert(struct graph* g,int u,int v);
void    dfs(struct graph* g,int u,int p); // p: parent
int compare(const void* u,const void* v);

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
    printf("%d\n",g.a);
    qsort(&g.arti[0],g.a,sizeof(struct edge),compare);
    for(j=0;j<g.a;j++){printf("%d %d\n",g.arti[j].u,g.arti[j].v);}
    clean(&g);
}

void   init(struct graph* g,int n,int e){
    int j;
    g->n=n;
    g->e=e;
    g->a=0;
    g->c=0;
    g->p=0;
    g->adjs=(int*)malloc(sizeof(int)*n);
    g->vist=(int*)malloc(sizeof(int)*n);
    g->dist=(int*)malloc(sizeof(int)*n);
    g->arti=(struct edge*)malloc(sizeof(struct edge)*n);
    g->pool=(struct node*)malloc(sizeof(struct node)*e);
    for(j=0;j<n;j++){
        g->adjs[j]=-1;
        g->vist[j]=0;
        g->dist[j]=e+1; // INF: unweighted graph
    }
}
void  clean(struct graph* g){
    free(g->adjs);
    free(g->vist);
    free(g->dist);
    free(g->arti);
    free(g->pool);
}
void insert(struct graph* g,int u,int v){
    g->pool[g->p].v=v;;
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
            if(g->dist[v]<g->dist[u]){g->dist[u]=g->dist[v];}
            if(g->dist[v]>g->vist[u]){
                g->arti[g->a  ].u=(u<v)?u:v;
                g->arti[g->a++].v=(u<v)?v:u;
            }
        }
        else{if(g->dist[u]>g->vist[v]){g->dist[u]=g->vist[v];}}
        d=g->pool[d].next;
    }
}
int compare(const void* u,const void* v){
    if((((struct edge*)u)->u)< (((struct edge*)v)->u)){return -1;}
    if((((struct edge*)u)->u)> (((struct edge*)v)->u)){return  1;}
    if((((struct edge*)u)->u)==(((struct edge*)v)->u)){
        if((((struct edge*)u)->v)< (((struct edge*)v)->v)){return -1;}
        if((((struct edge*)u)->v)> (((struct edge*)v)->v)){return  1;}
    }
    return 0;
}