// P3 14286: 간선 끊어가기 2(유량,최대유량최소컷정리)
// 단순 최소컷 비용(최대유량)출력하는 과제
// 정적간선풀로 재채점
#include<stdio.h>
#include<stdlib.h>

#define INF 1000001

struct node{
    int v;
    int f; // flow
    int c; // capacity
    int next;
};
struct graph{
    int n;
    int e;
    int p;
    int* adjs;
    int* prev; // 역추적: 정점
    int* path; // 역추적: 간선
    struct node* pool;
};

void   init(struct graph* g,int n,int e);
void  clean(struct graph* g);
void insert(struct graph* g,int u,int v,int c);
int    flow(struct graph* g,int s,int e);

int main(void){
    int j;
    int n; int e; scanf("%d %d",&n,&e);
    int s; int d; // src, dst
    int u; int v; int c;
    struct graph g;
    init(&g,n+1,2*e); // 1-based
    for(j=0;j<e;j++){
        scanf("%d %d %d",&u,&v,&c);
        insert(&g,u,v,c);
    }
    scanf("%d %d",&s,&d);
    printf("%d",flow(&g,s,d));
    clean(&g);
}

void   init(struct graph* g,int n,int e){
    int j;
    g->n=n;
    g->e=e;
    g->p=0;
    g->adjs=(int*)malloc(sizeof(int)*n);
    g->prev=(int*)malloc(sizeof(int)*n);
    g->path=(int*)malloc(sizeof(int)*n);
    g->pool=(struct node*)malloc(sizeof(struct node)*e);
    for(j=0;j<n;j++){
        g->adjs[j]=-1;
        g->prev[j]=-1;
        g->path[j]=-1;
    }
}
void  clean(struct graph* g){
    free(g->adjs);
    free(g->prev);
    free(g->path);
    free(g->pool);
}
void insert(struct graph* g,int u,int v,int c){
    g->pool[g->p].v=v;
    g->pool[g->p].f=0;
    g->pool[g->p].c=c;
    g->pool[g->p].next=g->adjs[u];
    g->adjs[u]=g->p++;

    g->pool[g->p].v=u;
    g->pool[g->p].f=0;
    g->pool[g->p].c=c;
    g->pool[g->p].next=g->adjs[v];
    g->adjs[v]=g->p++;
}
int    flow(struct graph* g,int s,int e){
    int  j; // loop variable
    int  f=0; // total flow
    int  c;   // current flow
    int* q=(int*)malloc(sizeof(int)*g->n); // queue
    int  h; // front of queue
    int  t; // rear of queue
    int  u; // node dummy
    int  d; // edge pool dummy

    while(1){
        // 초기화: 역추적 필드 초기화, 시작점 enqueue
        for(j=0;j<g->n;j++){
            g->prev[j]=-1;
            g->path[j]=-1;
        }
        h=0; t=0; q[t++]=s; // enqueue
        g->prev[s]=s;

        // BFS
        while((h<t)&&(g->prev[e]==-1)){
            u=q[h++]; // dequeue
            d=g->adjs[u];
            while(d!=-1){
                if(((g->pool[d].c-g->pool[d].f)>0)&&(g->prev[g->pool[d].v]==-1)){
                    g->prev[g->pool[d].v]=u;
                    g->path[g->pool[d].v]=d;
                    q[t++]=g->pool[d].v;
                }
                d=g->pool[d].next;
            }
        }

        // 탐색할 경로 없음
        if(g->prev[e]==-1){break;}

        // 경로 역추적: 잔여 용량 갱신
        c=INF;
        for(j=e;j!=s;j=g->prev[j]){
            d=g->path[j];
            if(c>g->pool[d].c-g->pool[d].f){c=g->pool[d].c-g->pool[d].f;}
        }

        // 경로 역추적: 유량 갱신
        for(j=e;j!=s;j=g->prev[j]){
            d=g->path[j];
            g->pool[d  ].f+=c;
            g->pool[d^1].f-=c;
        }

        // 최대 유량 갱신
        f+=c;
    }

    free(q);
    return f;
}