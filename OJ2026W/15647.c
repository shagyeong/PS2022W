// P5 15647: 엠마도 바리스타(트리DP,리루팅)
#include<stdio.h>
#include<stdlib.h>

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
    int* vist;
    int* pare; // 부모
    int* size; // 서브트리 사이즈
    long long int* dp1;
    long long int* dp2;
    struct node* pool;
};

void    dfs(struct graph* g,int u);
void reroot(struct graph* g,int u);
void   init(struct graph* g,int n,int e);
void  reset(struct graph* g);
void  clean(struct graph* g);
void insert(struct graph* g,int u,int v,int w);

int main(void){
    int j;
    int n; scanf("%d",&n);
    int u; int v; int w;
    struct graph g;
    init(&g,n+1,2*n-2); // 1-based, tree
    for(j=0;j<n-1;j++){
        scanf("%d %d %d",&u,&v,&w);
        insert(&g,u,v,w);
        insert(&g,v,u,w);
    }
    dfs(&g,1); reset(&g);
    reroot(&g,1);
    for(j=1;j<=n;j++){printf("%lld\n",g.dp1[j]+g.dp2[j]);}
    clean(&g);
}

void    dfs(struct graph* g,int u){
    int d=g->adjs[u];
    int v;
    g->vist[u]=OK;
    g->size[u]=1;
    g->dp1[u]=0;
    while(d!=-1){
        v=g->pool[d].v;
        if(g->vist[v]==NO){
            g->pare[v]=u;
            dfs(g,v);
            g->size[u]+=g->size[v];
            g->dp1[u] +=(g->dp1[v]+(long long int)g->size[v]*g->pool[d].w);
        }
        d=g->pool[d].next;
    }
}
void reroot(struct graph* g,int u){
    int d=g->adjs[u];
    int v;
    g->vist[u]=OK;
    while(d!=-1){
        v=g->pool[d].v;
        if(g->vist[v]==NO){
            g->dp2[v]= (g->dp1[u]+g->dp2[u])-(g->dp1[v]+(long long int)g->size[v]*g->pool[d].w);
            g->dp2[v]+=(long long int)((g->n-1)-g->size[v])*g->pool[d].w;
            reroot(g,v);
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
    g->pare=(int*)malloc(sizeof(int)*n);
    g->size=(int*)malloc(sizeof(int)*n);
    g->dp1 =(long long int*)malloc(sizeof(long long int)*n);
    g->dp2 =(long long int*)malloc(sizeof(long long int)*n);
    g->pool=(struct node*)malloc(sizeof(struct node)*e);
    for(j=0;j<n;j++){
        g->adjs[j]=-1;
        g->vist[j]=NO;
        g->pare[j]=-1;
        g->size[j]=0;
    }
}
void  reset(struct graph* g){
    int j;
    for(j=0;j<g->n;j++){
        g->vist[j]=NO;
    }
}
void  clean(struct graph* g){
    free(g->adjs);
    free(g->vist);
    free(g->pare);
    free(g->size);
    free(g->dp1);
    free(g->dp2);
    free(g->pool);
}
void insert(struct graph* g,int u,int v,int w){
    g->pool[g->p].v=v;
    g->pool[g->p].w=w;
    g->pool[g->p].next=g->adjs[u];
    g->adjs[u]=g->p++;
}