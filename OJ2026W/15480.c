// P2 15480: LCA와 쿼리(희소배열,LCA)
#include<stdio.h>
#include<stdlib.h>

#define L 18
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
    int* dept;
    int** spar;
    int* _spar;
    struct node* pool;
};

void    bfs(struct graph* g,int u);
void sparse(struct graph* g);
int     lca(struct graph* g,int u,int v);
void   init(struct graph* g,int n,int e);
void  clean(struct graph* g);
void insert(struct graph* g,int u,int v);

int main(void){
    int j;
    int n; int m; scanf("%d",&n);
    int u; int v; int w;
    int d; int l; // depth, LCA
    struct graph g;
    init(&g,n+1,2*n-2); // 1-bases, undirected, tree
    for(j=0;j<n-1;j++){
        scanf("%d %d",&u,&v);
        insert(&g,u,v);
        insert(&g,v,u);
    }
    bfs(&g,1); sparse(&g);
    
    scanf("%d",&m);
    for(j=0;j<m;j++){
        scanf("%d %d %d",&u,&v,&w);
        l=lca(&g,u,v); d=l;
        l=lca(&g,u,w); d=(g.dept[d]>g.dept[l])?d:l;
        l=lca(&g,v,w); d=(g.dept[d]>g.dept[l])?d:l;
        printf("%d\n",d);
    }
    clean(&g);
}

void    bfs(struct graph* g,int u){
    int* q=(int*)malloc(sizeof(int)*g->n);
    int f=0;
    int r=0;
    int c;
    int d; int v;
    g->vist[u]=OK;
    q[r++]=u;
    while(f<r){
        c=q[f++];
        d=g->adjs[c];
        while(d!=-1){
            v=g->pool[d].v;
            if(g->vist[v]==NO){
                g->vist[v]=OK;
                g->dept[v]=g->dept[c]+1;
                g->spar[v][0]=c;
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
        g->spar[k][j]=g->spar[g->spar[k][j-1]][j-1];
    }}
}
int     lca(struct graph* g,int u,int v){
    int j;
    int t; if(g->dept[u]<g->dept[v]){t=u;u=v;v=t;}
    int d=g->dept[u]-g->dept[v];
    int l; // LCA
    for(j=0;j<L;j++){if(((d>>j)&1)==1){u=g->spar[u][j];}}
    if(u==v){l=u;}
    else{
        for(j=L-1;j>=0;j--){
            if(g->spar[u][j]!=g->spar[v][j]){
                u=g->spar[u][j];
                v=g->spar[v][j];
            }
        }
        l=g->spar[u][0];
    }
    return l;
}
void   init(struct graph* g,int n,int e){
    int j; int k=0;
    g->n=n;
    g->e=e;
    g->p=0;
    g->adjs=(int*)malloc(sizeof(int)*n);
    g->vist=(int*)malloc(sizeof(int)*n);
    g->dept=(int*)malloc(sizeof(int)*n);
    g->spar=(int**)malloc(sizeof(int*)*n);
    g->_spar=(int*)malloc(sizeof(int)* n*L);
    g->pool=(struct node*)malloc(sizeof(struct node)*e);
    for(j=0;j<n;j++){g->spar[j]=g->_spar+k; k+=L;}
    for(j=0;j<n;j++){
        g->adjs[j]=-1;
        g->vist[j]=NO;
        g->dept[j]=0;
        for(k=0;k<L;k++){g->spar[j][k]=0;}
    }
}
void  clean(struct graph* g){
    free(g->adjs);
    free(g->vist);
    free(g->dept);
    free(g->_spar);
    free(g->spar);
    free(g->pool);
}
void insert(struct graph* g,int u,int v){
    g->pool[g->p].v=v;
    g->pool[g->p].next=g->adjs[u];
    g->adjs[u]=g->p++;
}