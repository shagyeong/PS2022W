// G4 14938: 서강그라운드(데이크스트라)
#include<stdio.h>
#include<stdlib.h>

#define N 101 // 노드 최대 개수
#define INF 65535
#define NOTVIST 0
#define ALLDONE 1

struct node{
    unsigned short v; // value
    unsigned short w; // weight
    struct node* next;
};
struct graph{
    unsigned short n; // 노드 개수
    struct node*  adjs[N];
    unsigned short dist[N];
    unsigned short vist[N];
};

void dijkstra(struct graph* g,unsigned short s);
void init_graph(struct graph* g,unsigned short n);
void init_dist(struct graph* g); // INF로 초기화
void init_vist(struct graph* g);
void insert(struct graph* g,unsigned short u,unsigned short v,unsigned short w);

int main(void){
    unsigned int a=0; // answer
    unsigned int b=0; // 노드별 획득량 더미
    unsigned short j; // loop variable
    unsigned short k; // loop variable
    unsigned short u; // node dummy
    unsigned short v; // node dummy
    unsigned short w; // value dummy
    unsigned short n;
    unsigned short m;
    unsigned short e;
    scanf("%hu %hu %hu",&n,&m,&e);
    struct graph* g=(struct graph*)malloc(sizeof(struct graph));
    init_graph(g,n+1);
    for(j=1;j<=n;j++){scanf("%hu",&v);g->adjs[j]->v=v;}
    for(j=0;j< e;j++){
        scanf("%hu %hu %hu",&u,&v,&w);
        insert(g,u,v,w);
        insert(g,v,u,w);
    }

    for(j=1;j<=n;j++){
        dijkstra(g,j);
        b=0;
        for(k=1;k<=n;k++){if(g->dist[k]<=m){b+=g->adjs[k]->v;}}
        if(a<b){a=b;}
    }
    printf("%u",a);
}

void dijkstra(struct graph* g,unsigned short s){
    unsigned short i=s;    // min distance index buffer
    unsigned short d;      // min distance buffer
    unsigned short j;    // loop variable
    unsigned short k;    // loop variable
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
void init_graph(struct graph* g,unsigned short n){
    unsigned short j;
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
    unsigned short j;
    for(j=0;j<g->n;j++){
        g->dist[j]=INF;
    }
}
void init_vist(struct graph* g){
    unsigned short j;
    for(j=0;j<g->n;j++){
        g->vist[j]=NOTVIST;
    }
}
void insert(struct graph* g,unsigned short u,unsigned short v,unsigned short w){
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