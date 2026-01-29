// P4 3176: 도로네트워크(LCA)
#include<stdio.h>
#include<stdlib.h>

#define N 100001
#define W 1000001
#define L 17 // log_2 100001 + 1
#define NOTVIST 0
#define ALLDONE 1

struct node{
    int v;
    int w;
    struct node* next;
};
struct graph{
    int n; // number of node
    struct node* adjs[N];
    int          pare[N][L]; // parent
    int          dept[N];    // depth
    int          dist[N];    // distance
    int          vist[N];    // 방문상태
    int          mins[N][L]; int min;
    int          maxs[N][L]; int max;
};

struct graph g;
int q[N]; // queue

void    dfs(struct graph* g,int u);
void sparse(struct graph* g);
void    lca(struct graph* g,int u,int v);
void   init(struct graph* g,int n);
void insert(struct graph* g,int u,int v,int w);

int main(void){
    int j;
    int n; int m;
    int u; int v; int w;
    scanf("%d",&n);
    init(&g,n+1);
    for(j=0;j<n-1;j++){
        scanf("%d %d %d",&u,&v,&w);
        insert(&g,u,v,w);
        insert(&g,v,u,w);
    }
    
    dfs(&g,1);
    sparse(&g);

    scanf("%d",&m);
    for(j=0;j<m;j++){
        scanf("%d %d",&u,&v);
        lca(&g,u,v);
        printf("%d %d\n",g.min,g.max);
    }
}

void    dfs(struct graph* g,int u){
    int f=0;     // front of queue
    int r=0;     // rear of queue
    int d;       // node(dequeue)
    struct node* c; // node(adjs)

    g->vist[u]=ALLDONE;
    q[r++]=u;    // enqueue
    while(f<r){
        d=q[f++]; // dequeue
        c=g->adjs[d];
        while((c=c->next)!=NULL){
            if(g->vist[c->v]==NOTVIST){
                g->dept[c->v]=g->dept[d]+1;
                g->dist[c->v]=g->dist[d]+c->w;
                g->pare[c->v][0]=d;
                g->mins[c->v][0]=c->w;
                g->maxs[c->v][0]=c->w;
                q[r++]=c->v;
                g->vist[c->v]=ALLDONE;
            }
        }
    }
}
void sparse(struct graph* g){
    int j; int k;
    int m; // middle
    for(j=1;j<L;j++){
    for(k=1;k<g->n;k++){
        m=g->pare[k][j-1];
        g->pare[k][j]=g->pare[m][j-1];
        if(m!=0){
            g->mins[k][j]=(g->mins[k][j-1]<g->mins[m][j-1])?g->mins[k][j-1]:g->mins[m][j-1];
            g->maxs[k][j]=(g->maxs[k][j-1]>g->maxs[m][j-1])?g->maxs[k][j-1]:g->maxs[m][j-1];
        }
    }}
}
void lca(struct graph* g,int u,int v){
    int j; // loop variable
    int d; // depth 차분
    int t; // tmp(swap)
    g->min=W;
    g->max=0;

    if(g->dept[u]<g->dept[v]){t=u;u=v;v=t;}

    d=g->dept[u]-g->dept[v];
    for(j=0;j<L;j++){
        if((d>>j)&1){
            g->min=(g->min<g->mins[u][j])?g->min:g->mins[u][j];
            g->max=(g->max>g->maxs[u][j])?g->max:g->maxs[u][j];
            u=g->pare[u][j];
        }
    }

    if(u!=v){
        for(j=L-1;j>=0;j--){
            if(g->pare[u][j]!=g->pare[v][j]){
                g->min=(g->min<g->mins[u][j])?g->min:g->mins[u][j];
                g->max=(g->max>g->maxs[u][j])?g->max:g->maxs[u][j];
                g->min=(g->min<g->mins[v][j])?g->min:g->mins[v][j];
                g->max=(g->max>g->maxs[v][j])?g->max:g->maxs[v][j];
                u=g->pare[u][j];
                v=g->pare[v][j];
            }
        }
        g->min=(g->min<g->mins[u][0])?g->min:g->mins[u][0];
        g->max=(g->max>g->maxs[u][0])?g->max:g->maxs[u][0];
        g->min=(g->min<g->mins[v][0])?g->min:g->mins[v][0];
        g->max=(g->max>g->maxs[v][0])?g->max:g->maxs[v][0];
    }
}
void init(struct graph* g,int n){
    int j;
    int k;
    g->n=n;
    g->min=W;
    g->max=0;
    for(j=0;j<n;j++){
        g->adjs[j]=(struct node*)malloc(sizeof(struct node));
        g->adjs[j]->v=j;
        g->adjs[j]->w=0;
        g->adjs[j]->next=NULL;
        for(k=0;k<L;k++){
            g->pare[j][k]=0;
            g->mins[j][k]=W;
            g->maxs[j][k]=0;
        }
        g->dept[j]=0;
        g->dist[j]=0;
        g->vist[j]=NOTVIST;
    }
}
void insert(struct graph* g,int u,int v,int w){
    struct node* n=(struct node*)malloc(sizeof(struct node)); // new
    n->v=v;
    n->w=w;
    n->next=g->adjs[u]->next;
    g->adjs[u]->next=n;
}