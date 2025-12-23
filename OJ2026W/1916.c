// 1916: 최소비용 구하기(그래프, 데이크스트라)
#include<stdio.h>
#include<stdlib.h>

#define N 1001 // 노드 최대 개수
#define INF 2147483647
#define NOTVIST 0
#define ALLDONE 1

struct node{
    int v; // value
    int w; // weight
    struct node* next;
};
struct graph{
    int n; // 노드 개수
    struct node*  adjs[N];
    int dist[N];
    int vist[N];
};

void dijkstra(struct graph* g,int s);
void init_graph(struct graph* g,int n);
void init_dist(struct graph* g); // INF로 초기화
void init_vist(struct graph* g);
void insert(struct graph* g,int u,int v,int w);

int main(void){
    int j; // loop variable
    int n; int m;
    int u; int v; int w;
    int s; int e;
    struct graph* g=(struct graph*)malloc(sizeof(struct graph));
    
    scanf("%d",&n); scanf("%d",&m);
    init_graph(g,n+1);
    for(j=0;j<m;j++){
        scanf("%d %d %d",&u,&v,&w);
        insert(g,u,v,w);
    }
    scanf("%d %d",&s,&e);
    dijkstra(g,s);
    printf("%d",g->dist[e]);
}

void dijkstra(struct graph* g,int s){
    int i=s;    // min distance index buffer
    int d;      // min distance buffer
    int j;    // loop variable
    int k;    // loop variable
    init_dist(g); g->dist[s]=0;
    init_vist(g);
    struct node* b;

    for(j=0;j<g->n;j++){
        // 방문되지 않은 노드 중 가장 가까운 노드 찾기
        d=INF;
        for(k=0;k<g->n;k++){
            if((g->dist[k]<d)&&(g->vist[k]==NOTVIST)){
                i=k;
                d=g->dist[k];
            }
        }
        b=g->adjs[i];
        d=g->dist[i];
        g->vist[i]=ALLDONE;
        
        // dist[]<-min(dist[],dist[]+dist[][])
        while((b=b->next)!=NULL){
            if(d+b->w<g->dist[b->v]){
                g->dist[b->v]=d+b->w;
            }
        }
    }
}
void init_graph(struct graph* g,int n){
    int j;
    struct node* new;
    for(j=0;j<n;j++){
        new=(struct node*)malloc(sizeof(struct node));
        new->v=j;
        new->w=0;
        new->next=NULL;
        g->adjs[j]=new;
        g->dist[j]=INF;
        g->vist[j]=NOTVIST;
    }
    g->n=n;
}
void init_dist(struct graph* g){
    int j;
    for(j=0;j<g->n;j++){
        g->dist[j]=INF;
    }
}
void init_vist(struct graph* g){
    int j;
    for(j=0;j<g->n;j++){
        g->vist[j]=NOTVIST;
    }
}
void insert(struct graph* g,int u,int v,int w){
    struct node* B;
    struct node* V=(struct node*)malloc(sizeof(struct node));
    V->v=v;
    V->w=w;
    V->next=NULL;
    B=g->adjs[u];
    while((B->next!=NULL)&&(v>B->next->v)){B=B->next;}
    V->next=B->next;
    B->next=V;
}