// P4 11280: 2-SAT - 3(강결합컴포넌트,2-SAT)
#include<stdio.h>
#include<stdlib.h>

#define N 20001

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
    int          sccs[N]; // 노드별 scc ID
 // struct scc*  sccs[N];
};
struct scc{
    int n; // number of node
    int* a; // array of node value
};

int  toggle(int u,int n); // 논리부정 인덱스, n: 노드 개수
void   init(struct graph* g,int n);
void insert(struct graph* g,int u,int v);
void tarjan(struct graph* g,int u);

int main(void){
    int j;
    int n; int e; scanf("%d %d",&n,&e);
    int u; int v;
    struct graph g;
    init(&g,2*n+1); // +1: 1부터 시작하는 과제 환경
    for(j=0;j<e;j++){
        scanf("%d %d",&u,&v);
        u=(u>0)?u:n-u; // 음수 노드 조작
        v=(v>0)?v:n-v; // 음수 노드 조작
        insert(&g,toggle(u,n),v);
        insert(&g,toggle(v,n),u);
    }

    c= 0; // clock 초기화
    t=-1; // top 포인터 초기화
    for(j=1;j<=2*n;j++){d[j]=0;i[j]=0;}
    for(j=1;j<=2*n;j++){if(d[j]==0){tarjan(&g,j);}}

    for(j=1;j<=n;j++){
        if(g.sccs[j]==g.sccs[j+n]){
            printf("0");
            return 0;
        }
    }
    printf("1");
    return 0;
}

int  toggle(int u,int n){
    return (u>n)?(u-n):u+n;
}
void   init(struct graph* g,int n){
    int j;
    g->n=n;
    g->s=0;
    for(j=0;j<n;j++){
        g->sccs[j]=-1;
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
            g->sccs[v]=g->s;
            if(v==u){break;}
        }
        g->s++;
        // g->sccs[g->s++]=n;
    }
}