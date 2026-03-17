// P2 1693: 트리 색칠하기(트리DP)
#include<stdio.h>
#include<stdlib.h>

#define NO 0
#define OK 1
#define L 20 // 색상 수 log_2 100000 + 1
#define INF 1000000000

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
    int* pare;
    int** dp; // [N][L]
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
    int m; // min
    struct graph g;
    init(&g,n+1,2*n-2); // 1-based, tree
    for(j=0;j<n-1;j++){scanf("%d %d",&u,&v); insert(&g,u,v); insert(&g,v,u);}
    dfs(&g,1);
    m=g.dp[1][1];
    for(j=2;j<L;j++){if(m>g.dp[1][j]){m=g.dp[1][j];}}
    printf("%d",m);
    clean(&g);
}

void    dfs(struct graph* g,int u){
    int j; int k;
    int d=g->adjs[u];
    int v;
    int m; // min
    g->vist[u]=OK;
    while(d!=-1){
        v=g->pool[d].v;
        if(g->vist[v]==NO){
            g->pare[v]=u;
            dfs(g,v);
        }
        d=g->pool[d].next;
    }
    for(j=1;j<L;j++){
        g->dp[u][j]=j;
        d=g->adjs[u];
        while(d!=-1){
            v=g->pool[d].v;
            if(g->pare[u]!=v){
                m=INF;
                for(k=1;k<L;k++){
                    if(j==k){continue;} // 같은 색
                    if(m>g->dp[v][k]){m=g->dp[v][k];}
                }
                g->dp[u][j]+=m;
            }
            d=g->pool[d].next;
        }
    }
}
void   init(struct graph* g,int n,int e){
    int j; int k=0;
    g->n=n;
    g->e=e;
    g->p=0;
    g->adjs=(int*)malloc(sizeof(int)*n);
    g->vist=(int*)malloc(sizeof(int)*n);
    g->pare=(int*)malloc(sizeof(int)*n);
    g->dp=(int**)malloc(sizeof(int*)*n);
    g->_dp=(int*)malloc(sizeof(int) *n*L);
    g->pool=(struct node*)malloc(sizeof(struct node)*e);
    for(j=0;j<n;j++){
        g->adjs[j]=-1;
        g->vist[j]=NO;
        g->pare[j]=-1;
        g->dp[j]=g->_dp+k; k+=L;
    }
}
void  clean(struct graph* g){
    free(g->adjs);
    free(g->vist);
    free(g->pare);
    free(g->_dp);
    free(g->dp);
    free(g->pool);
}
void insert(struct graph* g,int u,int v){
    g->pool[g->p].v=v;
    g->pool[g->p].next=g->adjs[u];
    g->adjs[u]=g->p++;
}