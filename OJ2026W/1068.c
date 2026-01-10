// G5 1068: 트리(그래프,DFS)
#include<stdio.h>
#include<stdlib.h>

int l; // number of leaf(재귀로 인한 전역 변수 사용)

#define N 50
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
};

void    dfs(struct graph* g,int s);
void   init(struct graph* g,int n);
void insert(struct graph* g,int u,int v); // u->v

int main(void){
    int j; // loop variable
    int r; // root
    int n=10; scanf("%d",&n);
    int p; // parent
    struct graph g;
    init(&g,n);
    for(j=0;j<n;j++){
        scanf("%d",&p);
        if(p==-1){r=j;}
        else{insert(&g,p,j);}
    }
    scanf("%d",&n);
    if(n==r){printf("0");}
    else{
        g.vist[n]=ALLDONE;
        l=0;
        dfs(&g,r);
        printf("%d",l);
    }
}

void dfs(struct graph* g,int s){
    int f=1; // flag: 리프 노드 마크
    struct node* b;
    b=g->adjs[s];
    g->vist[s]=PROCESS;
    while((b=b->next)!=NULL){
        if(g->vist[b->v]==NOTVIST){
            f=0;
            dfs(g,b->v);
        }
    }
    g->vist[s]=ALLDONE;
    l+=f;
}
void   init(struct graph* g,int n){
    int j;
    g->n=n;
    for(j=0;j<n;j++){
        g->adjs[j]=(struct node*)malloc(sizeof(struct node));
        g->adjs[j]->v   =j;
        g->adjs[j]->next=NULL;
        g->vist[j]=NOTVIST;
    }
}
void insert(struct graph* g,int u,int v){
    struct node* b;
    struct node* n=(struct node*)malloc(sizeof(struct node)); // new
    b=g->adjs[u];
    while((b->next!=NULL)&&(v>(b->next->v))){b=b->next;} // 그래프 탐색: 사전순 이웃 노드
    n->v=v;
    n->next=b->next;
    b->next=n;
}