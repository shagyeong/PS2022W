// P4 11266: 단절점(단절점)
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
    int p; // pool index
    int* adjs;
    int* arti;
    int* vist;
    int* dist;
    struct node* pool;
};

void   init(struct graph* g,int n,int e);
void  clean(struct graph* g);
void insert(struct graph* g,int u,int v);
void    dfs(struct graph* g,int u,int f); // f: isroot flag

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
    for(j=1;j<=n;j++){if(g.vist[j]==0){dfs(&g,j,1);}}
    printf("%d\n",g.a);
    for(j=1;j<=n;j++){if(g.arti[j]==1){printf("%d ",j);}}
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
    g->arti=(int*)malloc(sizeof(int)*n);
    g->vist=(int*)malloc(sizeof(int)*n);
    g->dist=(int*)malloc(sizeof(int)*n);
    g->pool=(struct node*)malloc(sizeof(struct node)*e);
    for(j=0;j<n;j++){
        g->adjs[j]=-1;
        g->arti[j]=0;
        g->vist[j]=0;
        g->dist[j]=e+1; // INF: unweighted graph
    }
}
void  clean(struct graph* g){
    free(g->adjs);
    free(g->arti);
    free(g->vist);
    free(g->dist);
    free(g->pool);
}
void insert(struct graph* g,int u,int v){
    g->pool[g->p].v=v;;
    g->pool[g->p].next=g->adjs[u];
    g->adjs[u]=g->p++;
}
void    dfs(struct graph* g,int u,int f){
    int k=0; // number of child node
    int d=g->adjs[u];
    int v;
    g->vist[u]=++g->c;
    g->dist[u]=  g->c;
    while(d!=-1){
        v=g->pool[d].v;
        if(g->vist[v]==0){
            k+=1;
            dfs(g,v,0);
            if(g->dist[u]>g->dist[v]){g->dist[u]=g->dist[v];}
            if((f==0)&&(g->dist[v]>=g->vist[u])&&(g->arti[u]==0)){
                g->arti[u]=1;
                g->a+=1;
            }
        }
        else{if(g->dist[u]>g->vist[v]){g->dist[u]=g->vist[v];}}
        d=g->pool[d].next;
    }
    if((f==1)&&(k>=2)&&(g->arti[u]==0)){
        g->arti[u]=1;
        g->a+=1;
    }
}