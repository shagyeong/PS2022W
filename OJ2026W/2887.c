// P5 2887: 행성 터널(MST,정렬)
#include<stdio.h>
#include<stdlib.h>

#define N 100000 // 노드 최대 개수

struct node{
    int v;
    int w;
    struct node* next;
};
struct graph{
    int n;       // 노드 개수
    struct node*  adjs[N]; // 인접리스트
    int vist[N]; // 방문 상태
    int pare[N]; // parent: 분리 집합 루트
};
struct edge{
    int u;
    int v;
    int w;
};

void kruskal(struct graph* g);
int  getroot(struct graph* g,int u);      // 분리 집합 조작: 루트 리턴
void   unify(struct graph* g,int u,int v);// 분리 집합 조작: 합집합
void    init(struct graph* g, int n);
void  insert(struct graph* g,int u,int v,int w); // u->v
int  compare(const void* u,const void* v); // struct edge 정렬

int main(void){
    int j;
    int n; scanf("%d",&n);
    struct edge* x=(struct edge*)malloc(sizeof(struct edge)*n);
    struct edge* y=(struct edge*)malloc(sizeof(struct edge)*n);
    struct edge* z=(struct edge*)malloc(sizeof(struct edge)*n);
    struct graph g;
    init(&g,n);
    for(j=0;j<n;j++){
        scanf("%d %d %d",&x[j].w,&y[j].w,&z[j].w);
        x[j].u=j;
        y[j].u=j;
        z[j].u=j;
    }
    qsort(&x[0],n,sizeof(struct edge),compare);
    qsort(&y[0],n,sizeof(struct edge),compare);
    qsort(&z[0],n,sizeof(struct edge),compare);
    for(j=1;j<n;j++){
        insert((&g),(x[j].u),(x[j-1].u),(x[j].w-x[j-1].w));
        insert((&g),(y[j].u),(y[j-1].u),(y[j].w-y[j-1].w));
        insert((&g),(z[j].u),(z[j-1].u),(z[j].w-z[j-1].w));
        insert((&g),(x[j-1].u),(x[j].u),(x[j].w-x[j-1].w));
        insert((&g),(y[j-1].u),(y[j].u),(y[j].w-y[j-1].w));
        insert((&g),(z[j-1].u),(z[j].u),(z[j].w-z[j-1].w));
    }
    kruskal(&g);
}

void kruskal(struct graph* g){
    int w=0; // 총 가중치
    int j; // loop variable
    struct edge* e=(struct edge*)malloc(sizeof(struct edge)*3*g->n);
    struct node* B;
    int c=0; // number of edge

    // 간선 배열
    for(j=0;j<g->n;j++){
        B=g->adjs[j];
        while((B=B->next)!=NULL){
            if(j<B->v){ // 무향 그래프: u->v, v->u 간선 중 한 개를 취함
                e[c].u=     j;
                e[c].v=  B->v;
                e[c++].w=B->w;
            }
        }
    }
    
    // 간선 배열 정렬(오름차순)
    qsort(&e[0],c,sizeof(struct edge),compare);

    // kruskal: 분리 집합
    for(j=0;j<c;j++){
        if(getroot(g,e[j].u)!=getroot(g,e[j].v)){
            unify(g,e[j].u,e[j].v);
            w+=e[j].w;
        }
    }
    printf("%d",w);
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
void    init(struct graph* g, int n){
    int j;
    g->n=n;
    for(j=0;j<n;j++){
        g->adjs[j]=(struct node*)malloc(sizeof(struct node));
        g->adjs[j]->v=j;
        g->adjs[j]->w=0;
        g->adjs[j]->next=NULL;
        g->vist[j]=0;
        g->pare[j]=j;
    }
}
void  insert(struct graph* g,int u,int v,int w){
    struct node* n=(struct node*)malloc(sizeof(struct node)); // new
    n->v=v;
    n->w=w;
    n->next=g->adjs[u]->next;
    g->adjs[u]->next=n;
}
int  compare(const void* u,const void* v){
    if((((struct edge*)u)->w)<(((struct edge*)v)->w)){return -1;}
    if((((struct edge*)u)->w)>(((struct edge*)v)->w)){return  1;}
    return 0;
}