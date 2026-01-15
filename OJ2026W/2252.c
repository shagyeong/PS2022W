// G3 2252: 줄 세우기(DAG,위상정렬)
#include<stdio.h>
#include<stdlib.h>

#define N 32001

struct node{
    int v;
    struct node* next;
};
struct graph{
    int n; // number of node
    struct node* adjs[N];
    int          ideg[N]; // indegree: 진입 차수
};

void  tsort(struct graph* g); // topological sort
void   init(struct graph* g,int n);
void insert(struct graph* g,int u,int v);

int main(void){
    int j;
    int n; int e; scanf("%d %d",&n,&e);
    int u; int v;
    struct graph g;
    init(&g,n+1);

    for(j=0;j<e;j++){
        scanf("%d %d",&u,&v);
        insert(&g,u,v);
    }
    tsort(&g);
}

void tsort(struct graph* g){
    int j;          // loop variable
    int q[g->n];    // queue
    int f=0;        // front
    int r=0;        // rear
    int d;          // node(dequeue)
    struct node* c; // node(인접리스트 포인터)
    
    for(j=1;j<g->n;j++){
        if(g->ideg[j]==0){
            q[r++]=j; // enqueue
        }
    }

    while(f<r){
        d=q[f++]; // dequeue
        printf("%d ",d);
        c=g->adjs[d];
        while((c=c->next)!=NULL){
            g->ideg[c->v]-=1; // 진입 차수 갱신
            if(g->ideg[c->v]==0){q[r++]=c->v;} // enqueue
        }
    }
}
void   init(struct graph* g,int n){
    int j;
    g->n=n;
    for(j=0;j<n;j++){
        g->adjs[j]=(struct node*)malloc(sizeof(struct node));
        g->adjs[j]->v=j;
        g->adjs[j]->next=NULL;
        g->ideg[j]=0;
    }
}
void insert(struct graph* g,int u,int v){
    // 인접리스트 조작
    struct node* n=(struct node*)malloc(sizeof(struct node));
    n->v=v;
    n->next=g->adjs[u]->next;
    g->adjs[u]->next=n;

    // 진입차수 갱신
    g->ideg[v]+=1;
}