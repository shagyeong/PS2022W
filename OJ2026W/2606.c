// S3 2606: 바이러스(DFS)
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
    struct node* pool;
};

void    dfs(struct graph* g,int u);
void   init(struct graph* g,int n,int e);
void  clean(struct graph* g);
void insert(struct graph* g,int u,int v);

int a; // answer

int main(void){
    int j;
    int n; scanf("%d",&n);
    int e; scanf("%d",&e);
    int u; int v;
    struct graph g;
    init(&g,n+1,2*e); // 1-based, undirected
    for(j=0;j<e;j++){
        scanf("%d %d",&u,&v);
        insert(&g,u,v);
        insert(&g,v,u);
    }
    a=0; dfs(&g,1);
    printf("%d",a-1);
    clean(&g);
}

void    dfs(struct graph* g,int u){
    int d=g->adjs[u];
    int v;
    g->vist[u]=OK; a++;
    while(d!=-1){
        v=g->pool[d].v;
        if(g->vist[v]==NO){dfs(g,v);}
        d=g->pool[d].next;
    }
}
void   init(struct graph* g,int n,int e){
    int j;
    g->n=n;
    g->e=e;
    g->p=0;
    g->adjs=(int*)malloc(sizeof(int)*n);
    g->vist=(int*)malloc(sizeof(int)*n);
    g->pool=(struct node*)malloc(sizeof(struct node)*e);
    for(j=0;j<n;j++){
        g->adjs[j]=-1;
        g->vist[j]=NO;
    }
}
void  clean(struct graph* g){
    free(g->adjs);
    free(g->vist);
    free(g->pool);
}
void insert(struct graph* g,int u,int v){
    g->pool[g->p].v=v;
    g->pool[g->p].next=g->adjs[u];
    g->adjs[u]=g->p++;
}