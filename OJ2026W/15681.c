// G5 15681: 트리와 쿼리(트리DP,DFS)
// 간선풀 재채점
#include<stdio.h>
#include<stdlib.h>

#define NO 0
#define OK 1

struct node{
    int v;
    int next;
};
struct graph{
    int n;
    int e;
    int p;
    int* adjs;
    int* vist;
    int* subs;
    struct node* pool;
};

int     dfs(struct graph* g,int s);
void   init(struct graph* g,int n,int e);
void  clean(struct graph* g);
void insert(struct graph* g,int u,int v);

int main(void){
    int j;
    int n; int r; int q; scanf("%d %d %d",&n,&r,&q);
    int u; int v;
    struct graph g;
    init(&g,n+1,2*n-2); // 1-based, tree
    for(j=0;j<n-1;j++){
        scanf("%d %d",&u,&v);
        insert(&g,u,v);
        insert(&g,v,u);
    }
    dfs(&g,r);
    for(j=0;j<q;j++){
        scanf("%d",&u);
        printf("%d\n",g.subs[u]);
    }
    clean(&g);
}

int     dfs(struct graph* g,int s){
    int d=g->adjs[s];
    g->subs[s]=1;
    g->vist[s]=OK;
    while(d!=-1){
        if(g->vist[g->pool[d].v]==NO){g->subs[s]+=dfs(g,g->pool[d].v);}
        d=g->pool[d].next;
    }
    return g->subs[s];
}
void   init(struct graph* g,int n,int e){
    int j;
    g->n=n;
    g->e=e;
    g->p=0;
    g->adjs=(int*)malloc(sizeof(int)*n);
    g->vist=(int*)malloc(sizeof(int)*n);
    g->subs=(int*)malloc(sizeof(int)*n);
    g->pool=(struct node*)malloc(sizeof(struct node)*e);
    for(j=0;j<n;j++){
        g->adjs[j]=-1;
        g->vist[j]=NO;
        g->subs[j]=0;
    }
}
void  clean(struct graph* g){
    free(g->adjs);
    free(g->vist);
    free(g->subs);
    free(g->pool);
}
void insert(struct graph* g,int u,int v){
    g->pool[g->p].v=v;
    g->pool[g->p].next=g->adjs[u];
    g->adjs[u]=g->p++;
}