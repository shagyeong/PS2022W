// G3 1865: 웜홀(벨만-포드)
#include<stdio.h>
#include<stdlib.h>

#define N   501
#define E   5201

struct edge{
    int u;
    int v;
    int w;
};
struct graph{
    int n; // number of node
    int e; // number of edge
    int         dist[N];
    struct edge adjs[E]; // array of edge
};

void   init(struct graph* g,int n);
void insert(struct graph* g,int u,int v,int w);
void     bf(struct graph* g);

int main(void){
    int j; int k; // loop variable
    int t; scanf("%d",&t); // test case
    int n; int e; int h; // number of node, edge, hole
    int u; int v; int w; // u, v, weight
    struct graph g;

    for(j=0;j<t;j++){
        scanf("%d %d %d",&n,&e,&h);
        init(&g,n+1);
        for(k=0;k<e;k++){scanf("%d %d %d",&u,&v,&w);insert(&g,u,v,w);insert(&g,v,u,w);}
        for(k=0;k<h;k++){scanf("%d %d %d",&u,&v,&w);insert(&g,u,v,-w);}
        bf(&g);
    }
}

void   init(struct graph* g,int n){
    int j;
    g->n=n;
    g->e=0;
    for(j=0;j<n;j++){g->dist[j]=0;}
}
void insert(struct graph* g,int u,int v,int w){
    g->adjs[g->e  ].u=u;
    g->adjs[g->e  ].v=v;
    g->adjs[g->e++].w=w;
}
void     bf(struct graph* g){
    int j; int k; // loop variable
    int u; int v; int w;
    int f; // flag

    for(j=1;j<g->n;j++){
        f=0;
        for(k=0;k<g->e;k++){
            u=g->adjs[k].u;
            v=g->adjs[k].v;
            w=g->adjs[k].w;
            if(g->dist[v]>g->dist[u]+w){
                g->dist[v]=g->dist[u]+w;
                f=1;
            }
        }
        if(f==0){break;} // 조기종료: 갱신 없음
    }
    f=0;
    for(k=0;k<g->e;k++){
        u=g->adjs[k].u;
        v=g->adjs[k].v;
        w=g->adjs[k].w;
        if(g->dist[v]>g->dist[u]+w){f=1;break;}
    }
    if(f==1){printf("YES\n");}
    else    {printf("NO\n");}
}
