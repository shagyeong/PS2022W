// P4 11266: 단절점(단절점,BFS)
#include<stdio.h>
#include<stdlib.h>

#define N 10001
int c; // clock

struct node{
    int v;
    struct node* next;
};
struct graph{
    int n; // number of node
    int a; // number of articular
    struct node* adjs[N];
    int          arti[N]; // articualr points: 0/1 toggle
    int          vist[N];
    int          dist[N];
};

void   init(struct graph* g,int n);
void insert(struct graph* g,int u,int v);
void    dfs(struct graph* g,int u,int f); // f: flag(isroot)

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
    for(j=1;j<=n;j++){if(g.vist[j]==0){dfs(&g,j,1);}}

    printf("%d\n",g.a);
    for(j=1;j<=n;j++){if(g.arti[j]==1){printf("%d ",j);}}
}

void   init(struct graph* g,int n){
    int j;
    g->n=n;
    g->a=0;
    for(j=0;j<n;j++){
        g->arti[j]=0;
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
void dfs(struct graph* g,int u,int f){
    int v;   // node number
    int k=0; // number of child node
    struct node* b=g->adjs[u];
    g->vist[u]=++c;
    g->dist[u]=  c;
    while((b=b->next)!=NULL){
        v=b->v;
        if(g->vist[v]==0){
            k++;
            dfs(g,v,0);
            g->dist[u]=((g->dist[u])<(g->dist[v]))?(g->dist[u]):(g->dist[v]);
            if((f==0)&&(g->dist[v]>=g->vist[u])&&(g->arti[u]==0)){
                g->arti[u]=1;
                g->a+=1;
            }
        }
        else{g->dist[u]=((g->dist[u])<(g->vist[v]))?g->dist[u]:g->vist[v];}
    }
    if((f==1)&&(k>=2)&&(g->arti[u]==0)){
        g->arti[u]=1;
        g->a+=1;
    }
}