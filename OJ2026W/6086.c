// G3 6086: 최대 유량(최대 유량)
#include <stdio.h>
#include <stdlib.h>

#define N   58 // A-Z: 65~90, a-z: 97~122
#define INF 2147483647

struct node{
    int v;
    int f; // flow
    int c; // capacity
    struct node* prev;
    struct node* next;
};
struct graph{
    int n; // number of node
    int          prev[N]; // 경로 추적: 이전 정점
    struct node* path[N]; // 경로 추적: 간선
    struct node* adjs[N]; // 인접리스트
};

void   init(struct graph* g,int n);
void insert(struct graph* g,int u,int v,int c);
int    flow(struct graph* g,int s,int e);

int main(void){
    int j;
    int e; scanf("%d",&e);// number of edge
    char u;
    char v;
    int  c; // capacity
    struct graph g; init(&g,N);
    for(j=0;j<e;j++){
        scanf("%c",&u); // 개행 처리
        scanf("%c %c %d",&u,&v,&c);
        insert(&g,u-65,v-65,c);
    }
    printf("%d",flow(&g,0,25));
}

void init(struct graph* g,int n){
    int j;
    g->n=n;
    for(j=0;j<n;j++){
        g->prev[j]=-1;
        g->adjs[j]=(struct node*)malloc(sizeof(struct node));
        g->adjs[j]->v   =j;
        g->adjs[j]->f   =0;
        g->adjs[j]->c   =0;
        g->adjs[j]->prev=NULL;
        g->adjs[j]->next=NULL;
    }
}
void insert(struct graph* g,int u,int v,int c){
    // 중복 간선: 용량 누적
    struct node* d;
    d=g->adjs[u];
    while((d=d->next)!=NULL){
        if(d->v==v){
            d->c      +=c;
            d->prev->c+=c;
            return;
        }
    }
    struct node* U=(struct node*)malloc(sizeof(struct node));
    struct node* V=(struct node*)malloc(sizeof(struct node));

    // 인접리스트 삽입
    V->v=v; U->v=u;
    V->f=0; U->f=0;
    V->c=c; U->c=c;
    V->next=g->adjs[u]->next;
    U->next=g->adjs[v]->next;
    g->adjs[u]->next=V;
    g->adjs[v]->next=U;

    // 역방향 노드 포인팅
    V->prev=U;
    U->prev=V;
}
int flow(struct graph* g,int s,int e){
    int j;     // loop variable
    int f=0;   // total flow
    int c;     // current flow
    int q[N];  // linear queue
    int h;     // head of queue
    int t;     // tail of queue
    int          u; // node dummy: number of node
    struct node* d; // node dummy

    while(1){
        // 경로 추적 필드 초기화
        for(j=0;j<g->n;j++){
            g->prev[j]=-1;
            g->path[j]=NULL;
        }

        // enqueue: starting point
        h=0; t=0;
        q[t++]=s;
        g->prev[s]=s;

        // 경로 찾기
        while((h<t)&&(g->prev[e]==-1)){
            u=q[h++]; // dequeue
            d=g->adjs[u];
            while((d=d->next)!=NULL){
                if(((d->c-d->f)>0)&&(g->prev[d->v]==-1)){
                    g->prev[d->v]=u;
                    g->path[d->v]=d;
                    q[t++]=d->v; // enqueue
                }
            }
        }

        // 탐색할 경로 없음
        if(g->prev[e]==-1){break;}

        // 경로 역추적: 잔여 용량(residual) 갱신
        c=INF;
        for(j=e;j!=s;j=g->prev[j]){
            if(c>g->path[j]->c-g->path[j]->f){
                c=g->path[j]->c-g->path[j]->f;
            }
        }

        // 경로 역추적: 유량 갱신
        for(j=e;j!=s;j=g->prev[j]){
            g->path[j]->f      +=c;
            g->path[j]->prev->f-=c; // 역방향 유량 상쇄
        }
        
        // 최대 유량 갱신
        f+=c;
    }
    return f;
}