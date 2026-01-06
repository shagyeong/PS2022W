// P4 1185: 유럽여행(그래프,MST)
// MST 간선: 두 번 방문
// MST 노드: 차수만큼 방문
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
long long int kruskal(struct graph* g,struct edge* a);

int main(void){
    int j; // loop variable
    int n; // number of node
    int e; // number of edge
    int u; // input dummy
    int v; // input dummy
    int w; // input dummy
    int m=1001; // minimum node variable(문제 조건: 시작 나라로 돌아와야 한다)
    struct graph* g=(struct graph*)malloc(sizeof(struct graph));
    struct edge*  a=(struct edge*)malloc(sizeof(struct edge)*E);
    int c[N]; // node cost
    scanf("%d %d",&n,&e);
    init_graph(g,n,e);
    for(j=1;j<=n;j++){
        scanf("%d",&c[j]);
        if(m>c[j]){m=c[j];}
    }
    for(j=0;j<e;j++){
        scanf("%d %d %d",&u,&v,&w);
        a[j].u=u;
        a[j].v=v;
        a[j].w=2*w+c[u]+c[v];
    }
    printf("%lld",kruskal(g,a)+m); // m: 시작 나라 재방문
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
long long int kruskal(struct graph* g,struct edge* a){
    long long int w=0; // 전체 가중치, 문제 조건: 가중치 전체 합 <= 1,000,000,000
    int j; // loop variable
    qsort(a,g->e,sizeof(struct edge),compare);

    for(j=0;j<g->e;j++){
        if(getroot(g,a[j].u)!=getroot(g,a[j].v)){
            unify(g,a[j].u,a[j].v);
            w+=a[j].w;
        }
    }
    return w;
}