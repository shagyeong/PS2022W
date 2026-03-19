// G3 11437: LCA(희소배열,LCA,트리DP)
#include<stdio.h>
#include<stdlib.h>

#define L 18 // log2 N
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
    int*  adjs;
    int*  dist;
    int*  vist;
    int*  dept;
    int** pare; // [N][L]
    int* _pare;
    struct node* pool;
};

void    bfs(struct graph* g,int u);
void sparse(struct graph* g);
int     lca(struct graph* g,int u,int v);
void   init(struct graph* g,int n,int e);
void  clean(struct graph* g);
void insert(struct graph* g,int u,int v,int w);

int main(void){
    int j;
    int n; int m;
    int u; int v;
    struct graph g;
    scanf("%d",&n);
    init(&g,n+1,2*n-2); // 1-based, undirected, tree
    for(j=0;j<n-1;j++){
        scanf("%d %d",&u,&v);
        insert(&g,u,v,1);
        insert(&g,v,u,1);
    }
    bfs(&g,1); sparse(&g);
    scanf("%d",&m);
    for(j=0;j<m;j++){
        scanf("%d %d",&u,&v);
        printf("%d\n",lca(&g,u,v));
    }
    clean(&g);
}

void    bfs(struct graph* g,int u){
    int* q=(int*)malloc(sizeof(int)*g->n);
    int f; int r;
    int c; // current(dequeued) node
    int d; int v; int w; // adjs

    f=0; r=0;
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
void sparse(struct graph* g){
    int j; int k;
    for(j=1;j<L;j++){
    for(k=1;k<g->n;k++){
        g->pare[k][j]=g->pare[g->pare[k][j-1]][j-1];
    }}
}
int     lca(struct graph* g,int u,int v){
    int j;
    int t; if(g->dept[u]<g->dept[v]){t=u;u=v;v=t;}
    int d=g->dept[u]-g->dept[v];
    int l; // LCA
    for(j=0;j<L;j++){
        if(((d>>j)&1)==1){u=g->pare[u][j];}
    }
    if(u==v){l=u;}
    else{
        for(j=L-1;j>=0;j--){
            if(g->pare[u][j]!=g->pare[v][j]){
                u=g->pare[u][j];
                v=g->pare[v][j];
            }
        }
        l=g->pare[u][0];
    }
    return l;
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
    g->pare=(int**)malloc(sizeof(int*)*n);
    g->_pare=(int*)malloc(sizeof(int)* n*L);
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