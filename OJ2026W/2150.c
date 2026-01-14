// P5 2150: Strongly Connected Component(강결합컴포넌트)
#include<stdio.h>
#include<stdlib.h>

#define N 10001

int d[N]; // dfn
int l[N]; // low
int i[N]; // isin: j번째 노드가 스택에 있는가
int c; // clock

int s[N];
int t; // top of stack

struct node{
    int v; // value: 0 ~ N-1, 인접리스트 인덱스 겸용
    struct node* next;
};
struct graph{
    int n; // number of node
    int s; // number of sccs
    struct node* adjs[N];
    struct scc*  sccs[N];
};
struct scc{
    int n; // number of node
    int* a; // array of node value
};

void   init(struct graph* g,int n);
void insert(struct graph* g,int u,int v);
void tarjan(struct graph* g,int u);
int compare_scc(const void* u,const void* v);
int compare_int(const void* u,const void* v);

int main(void){
    int j;
    int k;
    int n; int e; scanf("%d %d",&n,&e);
    int u; int v;
    struct graph g;
    init(&g,n+1); // n+1: 1부터 시작하는 과제 환경
    for(j=0;j<e;j++){scanf("%d %d",&u,&v);insert(&g,u,v);}

    c= 0; // clock 초기화
    t=-1; // top 포인터 초기화
    for(j=1;j<=n;j++){d[j]=0;i[j]=0;}
    for(j=1;j<=n;j++){if(d[j]==0){tarjan(&g,j);}}

    // 출력조건: 정렬
    for(j=0;j<g.s;j++){
        qsort(&(g.sccs[j]->a[0]),g.sccs[j]->n,sizeof(int),compare_int);
    }
    qsort(&(g.sccs[0]),g.s,sizeof(struct scc*),compare_scc);

    printf("%d\n",g.s);
    for(j=0;j<g.s;j++){
        for(k=0;k<g.sccs[j]->n;k++){
            printf("%d ",g.sccs[j]->a[k]);
        }
        printf("-1\n");
    }
}

void   init(struct graph* g,int n){
    int j;
    g->n=n;
    g->s=0;
    for(j=0;j<n;j++){
        g->sccs[j]=NULL;
        g->adjs[j]=(struct node*)malloc(sizeof(struct node));
        g->adjs[j]->v   =j;
        g->adjs[j]->next=NULL;
    }
}
void insert(struct graph* g,int u,int v){
    struct node* n=(struct node*)malloc(sizeof(struct node)); // new
    n->v=v;
    n->next=g->adjs[u]->next;
    g->adjs[u]->next=n;
}
void tarjan(struct graph* g,int u){
    struct node* b;
    struct scc* n; // new
    int v;
    int j; // tmp index
    int k=0; // count
    
    d[u]=++c;
    l[u]=  c;
    s[++t]=u; i[u]=1; // push

    b=g->adjs[u];
    while((b=b->next)!=NULL){
        v=b->v;
        if(d[v]==0){
            tarjan(g,v);
            if(l[v]<l[u]){l[u]=l[v];}
        }
        else if(i[v]!=0){
            if(d[v]<l[u]){l[u]=d[v];}
        }
    }
    if(l[u]==d[u]){
        n=(struct scc*)malloc(sizeof(struct scc));
        j=t; while(1){k++;if(s[j--]==u){break;}}
        n->n=0;
        n->a=(int*)malloc(sizeof(int)*k);
        while(1){
            v=s[t--]; i[v]=0; // pop
            n->a[n->n++]=v;
            if(v==u){break;}
        }
        g->sccs[g->s++]=n;
    }
}
int compare_scc(const void* u,const void* v){
    if((*((struct scc**)u))->a[0]<(*((struct scc**)v))->a[0]){return -1;}
    if((*((struct scc**)u))->a[0]>(*((struct scc**)v))->a[0]){return 1;}
    return 0;
}
int compare_int(const void* u,const void* v){
    if((*((int*)u))<(*((int*)v))){return -1;}
    if((*((int*)u))>(*((int*)v))){return 1;}
    return 0;
}