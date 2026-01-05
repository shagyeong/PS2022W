// G4 1647: 도시 분할 계획(MST)
// Kruskal II
// 가장 큰 간선을 제거해 forest
#include<stdio.h>
#include<stdlib.h>

#define N 100001    // 노드 최대 개수
#define E 1000001   // 간선 최대 개수

struct graph{
    int n; // 노드 개수
    int e; // 간선 개수
    int p[N]; // parent: 분리 집합 루트
};
struct edge{
    int u;
    int v;
    int w;
};

int compare(const void* u,const void* v); // qsort
void init_graph(struct graph* g,int n,int e);
int getroot(struct graph* g,int u);
void unify(struct graph* g,int u,int v);
void kruskal(struct graph* g,struct edge* a);

int main(void){
    int j; // loop variable
    int n; // number of node
    int e; // number of edge
    struct graph* g=(struct graph*)malloc(sizeof(struct graph));
    struct edge*  a=(struct edge*)malloc(sizeof(struct edge)*E);
    scanf("%d %d",&n,&e);
    init_graph(g,n,e);
    for(j=0;j<e;j++){
        scanf("%d %d %d",&a[j].u,&a[j].v,&a[j].w);
    }
    kruskal(g,a);
    free(g);
    free(a);
    return 0;
}
int compare(const void* u,const void* v){
    if((((struct edge*)u)->w)<(((struct edge*)v)->w)){return -1;}
    if((((struct edge*)u)->w)>(((struct edge*)v)->w)){return 1;}
    return 0;
}
void init_graph(struct graph* g,int n,int e){
    int j;
    for(j=0;j<=n;j++){g->p[j]=j;} // <=n: 1부터 시작하는 과제 환경
    g->n=n;
    g->e=e;
}
int getroot(struct graph* g,int u){
    if(g->p[u]==u){return u;}
    else          {return g->p[u]=getroot(g,g->p[u]);}
}
void unify(struct graph* g,int u,int v){
    int a=getroot(g,u);
    int b=getroot(g,v);
    if(a!=b){g->p[a]=b;}
}
void kruskal(struct graph* g,struct edge* a){
    int w=0; // 전체 가중치, 문제 조건: 가중치 전체 합 <= 1,000,000,000
    int m=0; // max
    int j; // loop variable
    qsort(a,g->e,sizeof(struct edge),compare);

    for(j=0;j<g->e;j++){
        if(getroot(g,a[j].u)!=getroot(g,a[j].v)){
            unify(g,a[j].u,a[j].v);
            w+=a[j].w;
            m =a[j].w;
        }
    }
    printf("%d",w-m);
}