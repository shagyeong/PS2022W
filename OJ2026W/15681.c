// G5 15681: 트리와 쿼리(재귀,트리DP,DFS)
#include<stdio.h>
#include<stdlib.h>

#define N 100001
#define NOTVIST 0
#define PROCESS 1
#define ALLDONE 2

struct node{
    int v; // value: 0 ~ N-1, 인접리스트 인덱스 겸용
    struct node* next;
};
struct graph{
    int n; // number of node
    struct node* adjs[N];
    int          vist[N];
    int          subs[N]; // dp table: number of nodes(subtree)
};

struct graph g;

int     dfs(int s);
void   init(int n);
void insert(int u,int v); // u->v

int main(void){
    int j;
    int n; int r; int q; scanf("%d %d %d",&n,&r,&q);
    int u; int v;
    init(n+1); // n+1: 1부터 시작하는 과제 환경
    for(j=0;j<n-1;j++){
        scanf("%d %d",&u,&v);
        insert(u,v);
        insert(v,u);
    }
    dfs(r);
    for(j=0;j<q;j++){
        scanf("%d",&u);
        printf("%d\n",g.subs[u]);
    }
}

int  dfs(int s){
    struct node* b;
    g.subs[s]=1; // memo
    b=g.adjs[s];
    g.vist[s]=PROCESS;
    while((b=b->next)!=NULL){if(g.vist[b->v]==NOTVIST){
        g.subs[s]+=dfs(b->v);
    }}
    g.vist[s]=ALLDONE;
    return g.subs[s];
}
void   init(int n){
    int j;
    g.n=n;
    for(j=0;j<n;j++){
        g.adjs[j]=(struct node*)malloc(sizeof(struct node));
        g.adjs[j]->v   =j;
        g.adjs[j]->next=NULL;
        g.vist[j]      =NOTVIST;
        g.subs[j]      =0;
    }
}
void insert(int u,int v){
    struct node* n=(struct node*)malloc(sizeof(struct node)); // new
    n->v=v;
    n->next=g.adjs[u]->next;
    g.adjs[u]->next=n;
}