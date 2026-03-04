// G4 1922: 네트워크 연결(MST)
#include<stdio.h>
#include<stdlib.h>

struct edge{
    int u;
    int v;
    int w;
};
struct graph{
    int n;
    int e;
    int* p;
    struct edge* edgs;
};

int compare(const void* u,const void* v);
void kruskal(struct graph* g);
int  getroot(struct graph* g,int u);
void   unify(struct graph* g,int u,int v);
void    init(struct graph* g,int n,int e);
void   clean(struct graph* g);

int main(void){
    int j;
    int n; int e; scanf("%d %d",&n,&e);
    int u; int v; int w;
    struct graph g;
    init(&g,n+1,e); // n+1: 1-based 과제
    for(j=0;j<e;j++){
        scanf("%d %d %d",&u,&v,&w);
        g.edgs[j].u=u;
        g.edgs[j].v=v;
        g.edgs[j].w=w;
    }
    kruskal(&g);
    clean(&g);
}

int compare(const void* u,const void* v){
    return ((struct edge*)u)->w-((struct edge*)v)->w; // 가중치 오름차순
}
void kruskal(struct graph* g){
    int j;
    int a=0;
    qsort(g->edgs,g->e,sizeof(struct edge),compare);
    for(j=0;j<g->e;j++){
        if(getroot(g,g->edgs[j].u)!=getroot(g,g->edgs[j].v)){
            a+=g->edgs[j].w;
            unify(g,g->edgs[j].u,g->edgs[j].v);
        }
    }
    printf("%d",a);
}
int  getroot(struct graph* g,int u){
    if(g->p[u]==u){return u;}
    else             {return g->p[u]=getroot(g,g->p[u]);}
}
void   unify(struct graph* g,int u,int v){
    g->p[getroot(g,u)]=getroot(g,v);
}
void    init(struct graph* g,int n,int e){
    int j;
    g->n=n; g->p=(int*)malloc(sizeof(int)*n);
    g->e=e; g->edgs=(struct edge*)malloc(sizeof(struct edge)*e);
    for(j=0;j<n;j++){g->p[j]=j;}
}
void   clean(struct graph* g){
    free(g->p);
    free(g->edgs);
}