// G3 2533: SNS(트리DP,역추적)
#include<stdio.h>
#include<stdlib.h>

#define N 1000001

struct node{
    int v;
    struct node* next;
};
struct graph{
    int n;
    struct node* adjs[N];
    int          vist[N];
    int          pare[N]; // 스택 dfs 역추적
    int          dist[N][2];
};

struct graph g;

void    dfs(struct graph* g,int s);
void   init(struct graph* g,int n);
void insert(struct graph* g,int u,int v);

int main(void){
    int j;
    int n; scanf("%d",&n);
    int u; int v;
    init(&g,n+1);
    for(j=1;j<n;j++){
        scanf("%d %d",&u,&v);
        insert(&g,u,v);
        insert(&g,v,u);
    }

    dfs(&g,1);
    printf("%d",(g.dist[1][0]<g.dist[1][1])?g.dist[1][0]:g.dist[1][1]);
}

void    dfs(struct graph* g,int s){
    struct node* b;
    int* a=(int*)malloc(sizeof(int)*g->n); // stack
    int* o=(int*)malloc(sizeof(int)*g->n); // order: dfs 역추적
    int i=0;                               // index of order
    int p;      // parent
    int c;      // child
    int t=0;    // top of stack

    a[t++]=s;   // push
    g->vist[s]=1; // ALLDONE
    while(t>0){
        p=a[--t];
        o[i++]=p;
        b=g->adjs[p];
        while((b=b->next)!=NULL){
            if(g->vist[b->v]==0){
                g->vist[b->v]=1;
                g->pare[b->v]=p; // 부모 노드 마크
                a[t++]=b->v; // push
            }
        }
    }

    // 점화식
    while(i>1){
        c=o[--i];
        p=g->pare[c];
        g->dist[p][0]+=g->dist[c][1];
        g->dist[p][1]+=(g->dist[c][0]<g->dist[c][1])?g->dist[c][0]:g->dist[c][1];
    }
    free(a);
    free(o);
}
void   init(struct graph* g,int n){
    int j;
    g->n=n;
    for(j=0;j<n;j++){
        g->adjs[j]=(struct node*)malloc(sizeof(struct node));
        g->adjs[j]->v=j;
        g->adjs[j]->next=NULL;
        g->vist[j]=0; // NOTVIST
        g->pare[j]=-1;
        g->dist[j][0]=0;
        g->dist[j][1]=1;
    }
}
void insert(struct graph* g,int u,int v){
    struct node* n=(struct node*)malloc(sizeof(struct node)); // new
    n->v=v;
    n->next=g->adjs[u]->next;
    g->adjs[u]->next=n;
}