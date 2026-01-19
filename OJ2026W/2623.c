// G3 2623: 음악프로그램(DAG,위상정렬)
#include<stdio.h>
#include<stdlib.h>

#define N 1001

struct node{
    int v;
    struct node* next;
};
struct graph{
    int n;
    struct node* adjs[N];
    int          ideg[N];
};

void  tsort(struct graph* g);
void   init(struct graph* g,int n);
void insert(struct graph* g,int u,int v);

int main(void){
    int j; int k;
    int n; int m; int l; scanf("%d %d",&n,&m);
    int u; int v;
    struct graph g;
    init(&g,n+1); // n+1: 1부터 시작하는 과제 환경
    for(j=0;j<m;j++){
        scanf("%d",&l);
        if(l==0){continue;}
        if(l==1){scanf("%d",&u); continue;}
        scanf("%d",&v);
        for(k=1;k<l;k++){
            u=v;
            scanf("%d",&v);
            insert(&g,u,v);
        }
    }
    tsort(&g);
}

void  tsort(struct graph* g){
    int j;
    int q[g->n]; // queue
    int f=0;     // front of queue
    int r=0;     // rear of queue
    int a[g->n]; // result
    int i=0;     // index of result array
    int d;
    struct node* c;

    for(j=1;j<g->n;j++){if(g->ideg[j]==0){q[r++]=j;}} // enqueue

    while(f<r){
        d=q[f++]; // dequeue
        a[i++]=d;
        c=g->adjs[d];
        while((c=c->next)!=NULL){
            g->ideg[c->v]-=1;
            if(g->ideg[c->v]==0){q[r++]=c->v;}
        }
    }
    if(i==g->n-1){for(j=0;j<i;j++){printf("%d\n",a[j]);}}
    else                          {printf("0\n");}
}
void   init(struct graph* g,int n){
    int j;
    g->n=n;
    for(j=0;j<n;j++){
        g->ideg[j]=0;
        g->adjs[j]=(struct node*)malloc(sizeof(struct node));
        g->adjs[j]->v=j;
        g->adjs[j]->next=NULL;
    }
}
void insert(struct graph* g,int u,int v){
    struct node* n=(struct node*)malloc(sizeof(struct node)); // new
    n->v=v;
    n->next=g->adjs[u]->next;
    g->adjs[u]->next=n;
    g->ideg[v]+=1;
}