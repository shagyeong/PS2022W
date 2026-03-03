// G3 11779: 최소비용 구하기 2(데이크스트라,역추적)
#include<stdio.h>
#include<stdlib.h>

#define INF 100000001

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
    struct hode* heap;
    struct node* pool;
    int i; // number of heap item
    int p; // pool index
};

void   dijkstra(struct graph* g,int s); // src
int       count(struct graph* g,int d); // dst
void  backtrack(struct graph* g,int d); // dst
void       init(struct graph* g,int n,int e);
void      clean(struct graph* g);
void     insert(struct graph* g,int u,int v,int w);
void       push(struct graph* g,int v,int d);
struct hode pop(struct graph* g);

int main(void){
    int j;
    int n; int e;
    int s; int d;
    int u; int v; int w;
    static struct graph g;
    scanf("%d %d",&n,&e);
    init(&g,n+1,e); // n+1: 1-based 과제
    for(j=0;j<e;j++){scanf("%d %d %d",&u,&v,&w);insert(&g,u,v,w);}
    scanf("%d %d",&s,&d);
    dijkstra(&g,s);
    printf("%d\n",g.dist[d]);
    printf("%d\n",count(&g,d));
    backtrack(&g,d);
    clean(&g);
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
            if(g->dist[h.v]+g->pool[n].w<g->dist[g->pool[n].v]){
                g->dist[g->pool[n].v]=g->dist[h.v]+g->pool[n].w;
                g->pare[g->pool[n].v]=h.v;
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
void  backtrack(struct graph* g,int d){
    if(d==-1){return;}
    backtrack(g,g->pare[d]);
    printf("%d ",d);
}
void       init(struct graph* g,int n,int e){
    int j;
    g->n=n;
    g->i=0;
    g->p=1;
    g->adjs=(int*)malloc(sizeof(int)*n);
    g->dist=(int*)malloc(sizeof(int)*n);
    g->pare=(int*)malloc(sizeof(int)*n);
    g->heap=(struct hode*)malloc(sizeof(struct hode)*(2*e+1));
    g->pool=(struct node*)malloc(sizeof(struct node)*(e+1));
    for(j=0;j<n;j++){
        g->adjs[j]=0;
        g->dist[j]=INF;
        g->pare[j]=-1;
    }
}
void      clean(struct graph* g){
    free(g->adjs);
    free(g->dist);
    free(g->pare);
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