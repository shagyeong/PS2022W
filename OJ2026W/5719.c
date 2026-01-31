// P5 5719: 거의 최단 경로(데이크스트라,힙,정적간선풀,역추적)
#include<stdio.h>
#include<stdlib.h>

#define N 500
#define E 10001
#define INF 10000001

struct hode{
    int v;
    int d;
};
struct node{
    int v;
    int w;
    int f; // flag: 간선 제거시 1로 마크
    int next;
};
struct graph{
    int n;
    int         adjs[N];
    int         reve[N]; // 역방향 인접리스트
    int         dist[N];
    int         vist[N];
    struct hode heap[E*3];
    struct node pool[E*2];
    int i; // number of heap item
    int p; // pool index
};

void   dijkstra(struct graph* g,int s);
void        cut(struct graph* g,int s,int d); // 역추적: 최단거리 제거
void       init(struct graph* g,int n);
void     insert(struct graph* g,int u,int v,int w);
void       push(struct graph* g,int v,int d);
struct hode pop(struct graph* g);

int main(void){
    int j;
    int n; int e;
    int s; int d;
    int u; int v; int w;
    static struct graph g;
    while(1){
        scanf("%d %d",&n,&e); if((n==0)&&(e==0)){break;};
        init(&g,n);
        scanf("%d %d",&s,&d);
        for(j=0;j<e;j++){scanf("%d %d %d",&u,&v,&w);insert(&g,u,v,w);}
        dijkstra(&g,s);
        cut(&g,s,d);
        for(j=0;j<n;j++){g.dist[j]=INF;}
        g.i=0;
        dijkstra(&g,s);
        printf("%d\n",(g.dist[d]==INF)?(-1):(g.dist[d]));
    }
}

void   dijkstra(struct graph* g,int s){
    struct hode h;
    int n;
    g->dist[s]=0;
    push(g,s,0);
    while(g->i>0){
        h=pop(g);
        if(g->dist[h.v]<h.d){continue;} // push 이후 갱신: continue
        n=g->adjs[h.v];
        while(n!=0){
            if((g->pool[n].f==0)&&(g->dist[h.v]+g->pool[n].w<g->dist[g->pool[n].v])){
                g->dist[g->pool[n].v]=g->dist[h.v]+g->pool[n].w;
                push(g,g->pool[n].v,g->dist[g->pool[n].v]);
            }
            n=g->pool[n].next;
        }
    }
}
void        cut(struct graph* g,int s,int d){
    int* q=(int*)malloc(sizeof(int)*g->n);
    int f=0; // front of queue
    int r=0; // rear  of queue
    int b;
    int n;
    int v;

    q[r++]=d; // enqueue
    g->vist[d]=1;
    while(f<r){
        b=q[f++]; // dequeue
        if(b==s){continue;}
        n=g->reve[b];
        while(n!=0){
            v=g->pool[n].v;
            if(g->dist[v]+g->pool[n].w==g->dist[b]){
                g->pool[n-1].f=1;
                if(g->vist[v]==0){
                    g->vist[v]=1;
                    q[r++]=v;
                }
            }
            n=g->pool[n].next;
        }
    }
    free(q);
}

void       init(struct graph* g,int n){
    int j;
    g->n=n;
    g->i=0;
    g->p=1;
    for(j=0;j<n;j++){
        g->adjs[j]=0;
        g->reve[j]=0;
        g->dist[j]=INF;
        g->vist[j]=0;
    }
}
void     insert(struct graph* g,int u,int v,int w){
    // adjs: 순방향
    g->pool[g->p].v=v;
    g->pool[g->p].w=w;
    g->pool[g->p].f=0;
    g->pool[g->p].next=g->adjs[u];
    g->adjs[u]=(g->p)++;

    // reve: 역방향
    g->pool[g->p].v=u;
    g->pool[g->p].w=w;
    g->pool[g->p].f=0;
    g->pool[g->p].next=g->reve[v];
    g->reve[v]=(g->p)++;
}
void       push(struct graph* g,int v,int d){
    int j=++(g->i);
    struct hode t;
    g->heap[j].v=v;
    g->heap[j].d=d;

    while((j>1)&&(g->heap[j].d<g->heap[j/2].d)){
        t=g->heap[j];
        g->heap[j]=g->heap[j/2];
        g->heap[j/2]=t;
        j/=2;
    }
}
struct hode pop(struct graph* g){
    int j=1;
    int c;
    struct hode r=g->heap[j];
    struct hode t;
    g->heap[j]=g->heap[(g->i)--];

    while(2*j<=g->i){
        if(2*j+1<=g->i){c=(g->heap[2*j].d<g->heap[2*j+1].d)?(2*j):(2*j+1);}
        else           {c=2*j;}
        if(g->heap[j].d<=g->heap[c].d){break;}
        t=g->heap[j];
        g->heap[j]=g->heap[c];
        g->heap[c]=t;
        j=c;
    }
    return r;
}