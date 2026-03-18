// G4 14267: 회사 문화 1(트리DP)
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
    int* cost; // [N]
    struct node* pool;
};

void    dfs(struct graph* g,int u);
void   init(struct graph* g,int n,int e);
void  clean(struct graph* g);
void insert(struct graph* g,int u,int v);

int main(void){
    int j;
    int n; int m; scanf("%d %d",&n,&m);
    int u; int v;
    struct graph g;
    init(&g,n+1,n-1); // 1-based, directed, tree
    scanf("%d",&u); // 입력(-1) 버림: 1번 노드 상사 없음
    for(j=2;j<=n;j++){scanf("%d",&u); insert(&g,u,j);}
    for(j=0;j< m;j++){scanf("%d %d",&u,&v); g.cost[u]+=v;}
    dfs(&g,1);
    for(j=1;j<=n;j++){printf("%d ",g.cost[j]);}
}

void    dfs(struct graph* g,int u){
    int d=g->adjs[u];
    int v;
    g->vist[u]=OK;
    while(d!=-1){
        v=g->pool[d].v;
        g->cost[v]+=g->cost[u];
        if(g->vist[v]==NO){
            dfs(g,v);
        }
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
    g->cost=(int*)malloc(sizeof(int)*n);
    g->pool=(struct node*)malloc(sizeof(struct node)*e);
    for(j=0;j<n;j++){
        g->adjs[j]=-1;
        g->vist[j]=NO;
        g->cost[j]=0;
    }
}
void  clean(struct graph* g){
    free(g->adjs);
    free(g->vist);
    free(g->cost);
    free(g->pool);
}
void insert(struct graph* g,int u,int v){
    g->pool[g->p].v=v;
    g->pool[g->p].next=g->adjs[u];
    g->adjs[u]=g->p++;
}