// G2 1949: 우수 마을(트리DP)
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
    int* cost;
    int** dp; // [N][2]
    int* _dp;
    struct node* pool;
};

void    dfs(struct graph* g,int u);
void   init(struct graph* g,int n,int e);
void  clean(struct graph* g);
void insert(struct graph* g,int u,int v);

int main(void){
    int j;
    int n; scanf("%d",&n);
    int u; int v;
    struct graph g;
    init(&g,n+1,2*n-2); // 1-based, tree
    for(j=1;j<=n; j++){scanf("%d",&g.cost[j]);}
    for(j=0;j<n-1;j++){scanf("%d %d",&u,&v); insert(&g,u,v); insert(&g,v,u);}

    dfs(&g,1);
    printf("%d",(g.dp[1][0]>g.dp[1][1])?g.dp[1][0]:g.dp[1][1]);

    clean(&g);
}

void    dfs(struct graph* g,int u){
    int d=g->adjs[u];
    int v;
    g->vist[u]=OK;
    g->dp[u][0]=0;
    g->dp[u][1]=g->cost[u];
    while(d!=-1){
        v=g->pool[d].v;
        if(g->vist[v]==NO){
            dfs(g,v);
            g->dp[u][0]+=(g->dp[v][0]>g->dp[v][1])?(g->dp[v][0]):(g->dp[v][1]);
            g->dp[u][1]+=g->dp[v][0];
        }
        d=g->pool[d].next;
    }
}
void   init(struct graph* g,int n,int e){
    int j; int k=0;
    g->n=n;
    g->e=e;
    g->p=0;
    g->adjs=(int*)malloc(sizeof(int)*n);
    g->vist=(int*)malloc(sizeof(int)*n);
    g->cost=(int*)malloc(sizeof(int)*n);
    g->dp=(int**)malloc(sizeof(int*)*n);
    g->_dp=(int*)malloc(sizeof(int) *n*2);
    g->pool=(struct node*)malloc(sizeof(struct node)*e);
    for(j=0;j<n;j++){
        g->adjs[j]=-1;
        g->vist[j]=NO;
        g->dp[j]=g->_dp+k; k+=2;
    }
}
void  clean(struct graph* g){
    free(g->adjs);
    free(g->vist);
    free(g->cost);
    free(g->_dp);
    free(g->dp);
    free(g->pool);
}
void insert(struct graph* g,int u,int v){
    g->pool[g->p].v=v;
    g->pool[g->p].next=g->adjs[u];
    g->adjs[u]=g->p++;   
}