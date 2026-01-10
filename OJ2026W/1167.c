// G2 1167: 트리의 지름(그래프,트리,DFS)
#include<stdio.h>
#include<stdlib.h>

#define N 100001
#define NOTVIST 0
#define ALLDONE 2

struct node{
    int v; // value: 0 ~ N-1, 인접리스트 인덱스 겸용
    int w;
    struct node* next;
};
struct graph{
    int n; // number of node
    struct node* adjs[N];
    int          vist[N];
    int          dist[N];
};

struct graph g;

void    dfs(struct graph* g,int s,int a); // acc: 누적
void   init(struct graph* g,int n);
void insert(struct graph* g,int u,int v,int w); // u->v

int main(void){
    int j; // loop variable
    int n; scanf("%d",&n);
    int u; int v; int w;
    int m; // max
    int i; // index of max
    init(&g,n+1); // n+1: 1부터 시작하는 과제 환경

    for(j=1;j<=n;j++){
        scanf("%d",&u);
        while(1){
            scanf("%d",&v); if(v==-1){break;}
            scanf("%d",&w);
            insert(&g,u,v,w);
            insert(&g,v,u,w);
        }
    }

    dfs(&g,1,0);
    m=0; i=1;
    for(j=1;j<=n;j++){
        if(m<g.dist[j]){
            m=g.dist[j];
            i=j;
        }
        g.dist[j]=0;
        g.vist[j]=NOTVIST;
    }
    
    dfs(&g,i,0);
    m=0;
    for(j=1;j<=n;j++){
        if(m<g.dist[j]){
            m=g.dist[j];
        }
    }
    printf("%d",m);
}

void dfs(struct graph* g,int s,int a){
    struct node* b;
    b=g->adjs[s];
    g->vist[s]=ALLDONE;
    g->dist[s]=a;
    while((b=b->next)!=NULL){
        if(g->vist[b->v]==NOTVIST){
            dfs(g,b->v,a+b->w);
        }
    }
    g->vist[s]=ALLDONE;
}
void   init(struct graph* g,int n){
    int j;
    g->n=n;
    for(j=0;j<n;j++){
        g->adjs[j]=(struct node*)malloc(sizeof(struct node));
        g->adjs[j]->v   =j;
        g->adjs[j]->w   =0;
        g->adjs[j]->next=NULL;
        g->vist[j]=NOTVIST;
        g->dist[j]=0;
    }
}
void insert(struct graph* g,int u,int v,int w){
    struct node* n=(struct node*)malloc(sizeof(struct node)); // new
    n->v=v;
    n->w=w;
    n->next=g->adjs[u]->next;
    g->adjs[u]->next=n;
}