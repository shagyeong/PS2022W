// G4 1197: 최소 스패닝 트리(MST,분리 집합)
#include<stdio.h>
#include<stdlib.h>

#define N 10001 // 노드 최대 개수
#define E 100001// 에지 최대 개수

struct node{
    int v;
    int w;
    struct node* next;
};

struct graph{
    int n; // 노드 개수
    int e; // 간선 개수
    int pare[N]; // parent: 분리 집합 루트
};

struct edge{
    int u;
    int v;
    int w;
};

int compare(const void* u,const void* v); // qsort
void init_graph(struct graph* g, int n,int e);
int getroot(struct graph* g,int u);     // 분리 집합 조작: 루트 리턴
void unify(struct graph* g,int u,int v);// 분리 집합 조작: 합집합
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
    for(j=0;j<=n;j++){g->pare[j]=j;}
    g->n=n;
    g->e=e;
}
int getroot(struct graph* g,int u){
    if(g->pare[u]==u){return u;}
    else             {return g->pare[u]=getroot(g,g->pare[u]);}
}
void unify(struct graph* g,int u,int v){
    int a=getroot(g,u); // root of u
    int b=getroot(g,v); // root of v
    if(a!=b){g->pare[a]=b;}
}
void kruskal(struct graph* g,struct edge* a){
    long long int w=0; // lst 전체 가중치
    int j; // loop variable
    qsort(a,g->e,sizeof(struct edge),compare);

    // kruskal: 분리 집합
    for(j=0;j<g->e;j++){
        if(getroot(g,a[j].u)!=getroot(g,a[j].v)){
            unify(g,a[j].u,a[j].v);
            w+=a[j].w;
        }
    }
    printf("%lld",w);
}