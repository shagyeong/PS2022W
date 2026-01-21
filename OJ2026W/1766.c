// G2 1766: 문제집(DAG,위상정렬,힙)
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
struct heap{
    int* a; // array: 선형 트리
    int  i; // item: 엘리먼트 개수
};

void  tsort(struct graph* g); // topological sort
void   init(struct graph* g,int n);
void insert(struct graph* g,int u,int v);
void push(struct heap* h,int v);
int   pop(struct heap* h);

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
    struct heap h;
    h.a=(int*)malloc(sizeof(int)*g->n);
    h.i=0;
    int d;          // node(dequeue)
    struct node* c; // node(인접리스트 포인터)
    
    for(j=1;j<g->n;j++){
        if(g->ideg[j]==0){
            push(&h,j);
        }
    }

    while(h.i>0){
        d=pop(&h);
        printf("%d ",d);
        c=g->adjs[d];
        while((c=c->next)!=NULL){
            g->ideg[c->v]-=1; // 진입 차수 갱신
            if(g->ideg[c->v]==0){push(&h,c->v);} // enqueue
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
void push(struct heap* h,int v){
    int j; // loop variable
    int t; // temp variable(swap)
    h->a[++(h->i)]=v; // 선형 트리 마지막 엘리먼트로 삽입
    j=h->i;

    // heapify
    while((j>1)&&(h->a[j]<h->a[j/2])){
        t=h->a[j];
        h->a[j]=h->a[j/2];
        h->a[j/2]=t;
        j/=2;
    }
}
int pop(struct heap* h){
    int r; // root: 리턴값
    int j; // loop variable
    int t; // temp variable(swap)
    int c; // child

    r=h->a[1]; // 루트
    h->a[1]=h->a[(h->i)--]; // 선형 트리 마지막 엘리먼트를 루트로
    j=1;

    // heapify
    while(j*2<=h->i){
        c=j*2; // lchild
        if((c+1<=h->i)&&(h->a[c+1]<h->a[c])){
            c+=1; // rchild: j*2+1
        }
        if(h->a[j]<=h->a[c]){
            break;
        }
        t=h->a[j];
        h->a[j]=h->a[c];
        h->a[c]=t;
        j=c;
    }
    return r;
}