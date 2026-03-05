// G1 2307: 도로검문(데이크스트라,역추적)
#include<stdio.h>
#include<stdlib.h>

#define INF 50000001

struct hode{
    int v;
    int d;
};
struct node{
    int v;
    int w;
    int next;
};
struct graph{
    int n;
    int*         adjs;
    int*         dist;
    int*         pare; // 역추적
    int*         edgs; // 역추적: pool index
    struct hode* heap;
    struct node* pool;
    int i; // number of heap item
    int p; // pool index
};

void   dijkstra(struct graph* g,int s,int skip); // src
int       count(struct graph* g,int d); // dst
int*  backtrack(struct graph* g,int d); // dst
void       init(struct graph* g,int n,int e);
void      clean(struct graph* g);
void     insert(struct graph* g,int u,int v,int w);
void       push(struct graph* g,int v,int d);
struct hode pop(struct graph* g);

int main(void){
    int j; int k;
    int n; int e; scanf("%d %d",&n,&e);
    int s; int d; s=1; d=n;
    int u; int v; int w;
    static struct graph g;

    int* edgs; // 검문할 에지
    int   esp; // 최단경로상 에지 개수
    int   min;    // 검문 전 최단거리
    int   max=-1; // 검문 후 최단거리 최대값

    init(&g,n+1,e); // n+1: 1-based 과제
    for(j=0;j<e;j++){
        scanf("%d %d %d",&u,&v,&w);
        insert(&g,u,v,w);
        insert(&g,v,u,w);
    }
    
    dijkstra(&g,s,-1);
    min=g.dist[d];
    esp=count(&g,d)-1;
    edgs=backtrack(&g,d);

    for(j=0;j<esp;j++){
        g.i=0;
        for(k=0;k<=n;k++){g.dist[k]=INF;}
        dijkstra(&g,s,edgs[j]);
        if(max<g.dist[d]){max=g.dist[d];}
    }

    if(max==INF){printf("-1");}
    else        {printf("%d",max-min);}
    clean(&g);
    free(edgs);
}

void   dijkstra(struct graph* g,int s,int skip){
    struct hode h;
    int n;
    g->dist[s]=0;
    push(g,s,0);
    while(g->i>0){
        h=pop(g);
        if(g->dist[h.v]<h.d){continue;} // push 이후 갱신: continue
        n=g->adjs[h.v];
        while(n!=0){
            if((n==skip)||(n==(skip^1))){
                n=g->pool[n].next;
                continue;
            }
            if(g->dist[h.v]+g->pool[n].w<g->dist[g->pool[n].v]){
                g->dist[g->pool[n].v]=g->dist[h.v]+g->pool[n].w;
                g->pare[g->pool[n].v]=h.v;
                g->edgs[g->pool[n].v]=n;
                push(g,g->pool[n].v,g->dist[g->pool[n].v]);
            }
            n=g->pool[n].next;
        }
    }
}
int       count(struct graph* g,int d){
    int c=0;
    int b=d;
    while(b!=-1){
        b=g->pare[b];
        c++;
    }
    return c;
}
int*  backtrack(struct graph* g,int d){
    int b=d;
    int i=0;
    int* edgs=(int*)malloc(sizeof(int)*(count(g,d)-1));
    while(g->edgs[b]!=-1){
        edgs[i++]=g->edgs[b];
        b=g->pare[b];
    }
    return edgs;
}
void       init(struct graph* g,int n,int e){
    int j;
    g->n=n;
    g->i=0;
    g->p=2; // skip^1
    g->adjs=(int*)malloc(sizeof(int)*n);
    g->dist=(int*)malloc(sizeof(int)*n);
    g->pare=(int*)malloc(sizeof(int)*n);
    g->edgs=(int*)malloc(sizeof(int)*n);
    g->heap=(struct hode*)malloc(sizeof(struct hode)*(2*e+2));
    g->pool=(struct node*)malloc(sizeof(struct node)*(2*e+2));
    for(j=0;j<n;j++){
        g->adjs[j]=0;
        g->dist[j]=INF;
        g->pare[j]=-1;
        g->edgs[j]=-1;
    }
}
void      clean(struct graph* g){
    free(g->adjs);
    free(g->dist);
    free(g->pare);
    free(g->edgs);
    free(g->heap);
    free(g->pool);
}
void     insert(struct graph* g,int u,int v,int w){
    g->pool[g->p].v=v;
    g->pool[g->p].w=w;
    g->pool[g->p].next=g->adjs[u];
    g->adjs[u]=(g->p)++;
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