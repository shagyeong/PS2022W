// P5 11400: 단절선(단절선,BFS)
#include<stdio.h>
#include<stdlib.h>

#define N 100001
int c; // clock

struct node{
    int v;
    struct node* next;
};
struct edge{
    int u;
    int v;
};
struct graph{
    int n; // number of node
    int a; // number of articular
    struct node* adjs[N];
    struct edge  arti[N]; // articualr points: 0/1 toggle
    int          vist[N];
    int          dist[N];
};

void   init(struct graph* g,int n);
void insert(struct graph* g,int u,int v);
void    dfs(struct graph* g,int u,int p); // p: parent
int compare(const void* u,const void* v);

int main(void){
    int j;
    int n; int e; scanf("%d %d",&n,&e);
    int u; int v;
    struct graph g;
    init(&g,n+1); // n+1: 1부터 시작하는 과제 환경
    for(j=0;j<e;j++){
        scanf("%d %d",&u,&v);
        insert(&g,u,v);
        insert(&g,v,u);
    }
    c=0; // clock 초기화
    for(j=1;j<=n;j++){if(g.vist[j]==0){dfs(&g,j,0);}} // p=0: 부모 없음(존재하지 않는 노드)
    printf("%d\n",g.a);
    qsort(&g.arti[0],g.a,sizeof(struct edge),compare);
    for(j=0;j<g.a;j++){printf("%d %d\n",g.arti[j].u,g.arti[j].v);}
}

void   init(struct graph* g,int n){
    int j;
    g->n=n;
    g->a=0;
    for(j=0;j<n;j++){
        // g->arti[j]=0;
        g->vist[j]=0;
        // g->dist[j]=INF;
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
void dfs(struct graph* g, int u, int p) {
    int v;
    struct node* b=g->adjs[u];
    g->vist[u]=++c;
    g->dist[u]=  c;
    while((b=b->next)!=NULL){
        v=b->v;
        if(v==p){continue;}
        if(g->vist[v]==0){
            dfs(g,v,u);
            if(g->dist[v]<g->dist[u]){g->dist[u]=g->dist[v];}
            if(g->dist[v]>g->vist[u]){
                g->arti[g->a  ].u=(u<v)?u:v;
                g->arti[g->a++].v=(u<v)?v:u;
            }
        }
        else{g->dist[u]=((g->dist[u])<(g->vist[v]))?g->dist[u]:g->vist[v];}
    }
}
int compare(const void* u,const void* v){
    if((((struct edge*)u)->u)< (((struct edge*)v)->u)){return -1;}
    if((((struct edge*)u)->u)> (((struct edge*)v)->u)){return  1;}
    if((((struct edge*)u)->u)==(((struct edge*)v)->u)){
        if((((struct edge*)u)->v)< (((struct edge*)v)->v)){return -1;}
        if((((struct edge*)u)->v)> (((struct edge*)v)->v)){return  1;}
    }
    return 0;
}