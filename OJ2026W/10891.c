// P3 10891: Cactus? Not cactus?(단절점,BFS,선인장)
#include<stdio.h>
#include<stdlib.h>

#define N 100001
int c; // clock

struct node{
    int v;
    struct node* next;
};
struct graph{
    int n; // number of node
    int a; // number of articular
    int f; // flag: is cactus
    struct node* adjs[N];
    int          arti[N]; // articualr points: 0/1 toggle
    int          vist[N];
    int          dist[N];
    int          cycl[N];
};

void   init(struct graph* g,int n);
void insert(struct graph* g,int u,int v);
void    dfs(struct graph* g,int u,int p); // p: parent

int main(void){
    int j;
    int n; int e; scanf("%d %d",&n,&e);
    int u; int v;
    struct graph g;
    init(&g,n+1); // n_1: 1부터 시작하는 과제 환경
    for(j=0;j<e;j++){
        scanf("%d %d",&u,&v);
        insert(&g,u,v);
        insert(&g,v,u);
    }

    c=0; // clock 초기화
    for(j=1;j<=n;j++){if(g.vist[j]==0){dfs(&g,j,0);}}

    if(g.f==1){printf("Cactus");}
    else      {printf("Not cactus");}
}

void   init(struct graph* g,int n){
    int j;
    g->n=n;
    g->a=0;
    g->f=1;
    for(j=0;j<n;j++){
        g->arti[j]=0;
        g->vist[j]=0;
        g->cycl[j]=0;
        g->adjs[j]=(struct node*)malloc(sizeof(struct node));
        g->adjs[j]->v   =j;
        g->adjs[j]->next=NULL;
    }   
}
void insert(struct graph* g,int u,int v){
    struct node* n=(struct node*)malloc(sizeof(struct node)); // new
    n->v=v;
    n->next=g->adjs[u]->next;
    g->adjs[u]->next=n;
}
void    dfs(struct graph* g,int u,int p){
    int v;   
    struct node* b=g->adjs[u];
    g->vist[u]=++c;
    g->dist[u]=  c;
    
    while((b=b->next)!=NULL){
        v=b->v;
        if(v==p){continue;}
        if(g->vist[v]==0){
            dfs(g,v,u);
            if(g->cycl[v]>0){
                if(g->arti[u]>0){g->f=0;}
                g->arti[u]=1;
            }
            g->dist[u]=((g->dist[u])<(g->dist[v]))?(g->dist[u]):(g->dist[v]);
            g->cycl[u]+=g->cycl[v];
        }
        else if(g->vist[v]<g->vist[u]){
            if(g->arti[u]>0){g->f=0;}
            g->arti[u]=1;
            g->dist[u]=((g->dist[u])<(g->vist[v]))?g->dist[u]:g->vist[v];
            g->cycl[u]++;
            g->cycl[v]--;
        }
    }
    if(g->cycl[u]>=2){g->f=0;}
}
