// P3 1772: 정원 정리(트리DP)
#include<stdio.h>
#include<stdlib.h>

#define NO 0
#define OK 1
#define INF 100000

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
    int* size; // 서브트리 사이즈
    int** dp; // [N][N]
    int* _dp;
    struct node* pool;
};

void    dfs(struct graph* g,int u,int m);
void   init(struct graph* g,int n,int e);
void  clean(struct graph* g);
void insert(struct graph* g,int u,int v);

int main(void){
    int j;
    int n; int m; scanf("%d %d",&n,&m);
    int u; int v;
    int a; // answer
    struct graph g;
    init(&g,n+1,2*n-2); // 1-based, tree
    for(j=0;j<n-1;j++){
        scanf("%d %d",&u,&v);
        insert(&g,u,v);
        insert(&g,v,u);
    }
    dfs(&g,1,m);
    a=g.dp[1][m];
    for(j=2;j<=n;j++){if(a>g.dp[j][m]+1){a=g.dp[j][m]+1;}}
    if(a==INF){printf("-1");}
    else{      printf("%d",a);}
    clean(&g);
}

void    dfs(struct graph* g,int u,int m){
    int j; int k;
    int d=g->adjs[u];
    int v;
    int t[g->n]; // tmp
    g->vist[u]=OK;
    g->size[u]=1;
    g->dp[u][1]=0;
    while(d!=-1){
        v=g->pool[d].v;
        if(g->vist[v]==NO){
            dfs(g,v,m);
            for(j=0;j<=m;j++){t[j]=INF;}
            for(j=1;j<=g->size[u]&&j<=m;j++){
                if(g->dp[u][j]==INF){continue;}
                if(t[j]>g->dp[u][j]+1){
                   t[j]=g->dp[u][j]+1;
                }
                for(k=1;k<=g->size[v]&&j+k<=m;k++){
                    if(g->dp[v][k]==INF){continue;}
                    if(t[j+k]>g->dp[u][j]+g->dp[v][k]){
                       t[j+k]=g->dp[u][j]+g->dp[v][k];
                    }
                }
            }
            g->size[u]+=g->size[v];
            for(j=1;j<=m;j++){g->dp[u][j]=t[j];}
        }
        d = g->pool[d].next;
    }
}
void   init(struct graph* g,int n,int e){
    int j; int k=0;
    g->n=n;
    g->e=e;
    g->p=0;
    g->adjs=(int*)malloc(sizeof(int)*n);
    g->vist=(int*)malloc(sizeof(int)*n);
    g->size=(int*)malloc(sizeof(int)*n);
    g->dp=(int**)malloc(sizeof(int*)*n);
    g->_dp=(int*)malloc(sizeof(int) *n*n);
    g->pool=(struct node*)malloc(sizeof(struct node)*e);
    for(j=0;j<n;j++){
        g->adjs[j]=-1;
        g->vist[j]=NO;
        g->size[j]=0;
        g->dp[j]=g->_dp+k; k+=n;
    }
    for(j=0;j<n;j++){for(k=0;k<n;k++){g->dp[j][k]=INF;}}
}
void  clean(struct graph* g){
    free(g->adjs);
    free(g->vist);
    free(g->size);
    free(g->_dp);
    free(g->dp);
    free(g->pool);
}
void insert(struct graph* g,int u,int v){
    g->pool[g->p].v=v;
    g->pool[g->p].next=g->adjs[u];
    g->adjs[u]=g->p++;
}