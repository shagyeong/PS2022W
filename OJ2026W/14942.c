// P5 14942: 개미(LCA)
#include<stdio.h>
#include<stdlib.h>

#define L 18
#define NO 0
#define OK 1

struct node{
    int v;
    int w;
    int next;
};
struct graph{
    int n;
    int e;
    int p;
    int* adjs;
    int* dist;
    int* vist;
    int* dept;
    int* cost; // 노드 가중치(문제 조건: '체력')    
    int** pare; // [N][L]
    int* _pare;
    struct node* pool;
};

int     lca(struct graph* g,int u,int v);
void    bfs(struct graph* g,int u);
void sparse(struct graph* g);
void   init(struct graph* g,int n,int e);
void  clean(struct graph* g);
void insert(struct graph* g,int u,int v,int w);

int main(void){
    int j;
    int n; scanf("%d",&n);
    int u; int v; int w;
    struct graph g;
    init(&g,n+1,2*n-2); // 1-based, undirected, tree
    for(j=1;j<=n; j++){scanf("%d",&g.cost[j]);}
    for(j=0;j<n-1;j++){scanf("%d %d %d",&u,&v,&w); insert(&g,u,v,w); insert(&g,v,u,w);}
    bfs(&g,1); sparse(&g);
    for(j=1;j<=n; j++){printf("%d\n",lca(&g,j,1));}
}

int     lca(struct graph* g,int u,int v){
    if(g->dist[u]<=g->cost[u]){return v;} // 루트 도달 가능(v: 루트(1)고정되어 전달됨)
    int j;
    int c=u;
    int d;
    for(j=L-1;j>=0;j--){
        d=g->pare[c][j];
        if((d!=0)&&(g->dist[u]-g->dist[d]<=g->cost[u])){c=d;} // 점프하며 조상-루트간 거리, 체력 비교
    }
    return c;
}
void    bfs(struct graph* g,int u){
    int* q=(int*)malloc(sizeof(int)*g->n);
    int f=0;
    int r=0;
    int c;
    int d; int v; int w;
    g->vist[u]=OK;
    q[r++]=u;
    while(f<r){
        c=q[f++];
        d=g->adjs[c];
        while(d!=-1){
            v=g->pool[d].v;
            w=g->pool[d].w;
            if(g->vist[v]==NO){
                g->vist[v]=OK;
                g->dept[v]=g->dept[c]+1;
                g->dist[v]=g->dist[c]+w;
                g->pare[v][0]=c;
                q[r++]=v;
            }
            d=g->pool[d].next;
        }
    }
    free(q);
}
void  sparse(struct graph* g){
    int j; int k;
    for(j=1;j<L;j++){for(k=1;k<g->n;k++){
        g->pare[k][j]=g->pare[g->pare[k][j-1]][j-1];
    }}
}
void   init(struct graph* g,int n,int e){
    int j; int k=0;
    g->n=n;
    g->e=e;
    g->p=0;
    g->adjs=(int*)malloc(sizeof(int)*n);
    g->dist=(int*)malloc(sizeof(int)*n);
    g->vist=(int*)malloc(sizeof(int)*n);
    g->dept=(int*)malloc(sizeof(int)*n);
    g->cost=(int*)malloc(sizeof(int)*n);
    g->pare=(int**)malloc(sizeof(int*)*n);
    g->_pare=(int*)malloc(sizeof(int) *n*L);
    g->pool=(struct node*)malloc(sizeof(struct node)*e);
    for(j=0;j<n;j++){g->pare[j]=g->_pare+k; k+=L;}
    for(j=0;j<n;j++){
        g->adjs[j]=-1;
        g->dist[j]=0;
        g->vist[j]=NO;
        g->dept[j]=0;
        for(k=0;k<L;k++){g->pare[j][k]=0;}
    }
}
void  clean(struct graph* g){
    free(g->adjs);
    free(g->dist);
    free(g->vist);
    free(g->dept);
    free(g->cost);
    free(g->_pare);
    free(g->pare);
    free(g->pool);
}
void insert(struct graph* g,int u,int v,int w){
    g->pool[g->p].v=v;
    g->pool[g->p].w=w;
    g->pool[g->p].next=g->adjs[u];
    g->adjs[u]=g->p++;
}