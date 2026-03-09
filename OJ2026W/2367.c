// P4 2367: 파티(유량)
#include<stdio.h>
#include<stdlib.h>

#define INF 1001 // 200*5

struct node{
    int v;
    int f; // flow
    int c; // capacity
    int next;
};
struct graph{
    int n;
    int e;
    int p;
    int* adjs;
    int* dept;
    int* curr;
    struct node* pool;
};

void   init(struct graph* g,int n,int e);
void  clean(struct graph* g);
void insert(struct graph* g,int u,int v,int c);
void    bfs(struct graph* g,int s,int e);
int     dfs(struct graph* g,int s,int e,int f);
int    flow(struct graph* g,int s,int e);

int main(void){
    int j; int k;
    int n; scanf("%d",&n); // 사람
    int l; scanf("%d",&l); // 접시 제한
    int m; scanf("%d",&m); // 음식
    int e=n+m+n*m; // number of edge
    int s=0;     // src
    int d=n+m+1; // dst
    int c; int z; int v; // input dummy
    struct graph g;
    init(&g,n+m+2,2*e);

    // 음식 - dst 용량 설정
    for(j=1;j<=m;j++){
        scanf("%d",&c);
        insert(&g,n+j,d,c);
    }

    // 사람 - 음식 용량 설정
    for(j=1;j<=n;j++){
        insert(&g,s,j,l);
        scanf("%d",&z);
        for(k=0;k<z;k++){
            scanf("%d",&v);
            insert(&g,j,n+v,1);
        }
    }

    printf("%d",flow(&g,s,d));
    clean(&g);
}

void   init(struct graph* g,int n,int e){
    int j;
    g->n=n;
    g->e=e;
    g->p=0;
    g->adjs=(int*)malloc(sizeof(int)*n);
    g->dept=(int*)malloc(sizeof(int)*n);
    g->curr=(int*)malloc(sizeof(int)*n);
    g->pool=(struct node*)malloc(sizeof(struct node)*e);
    for(j=0;j<n;j++){
        g->adjs[j]=-1;
        g->dept[j]=-1;
        g->curr[j]=-1;
    }
}
void  clean(struct graph* g){
    free(g->adjs);
    free(g->dept);
    free(g->curr);
    free(g->pool);
}
void insert(struct graph* g,int u,int v,int c){
    g->pool[g->p].v=v;
    g->pool[g->p].f=0;
    g->pool[g->p].c=c;
    g->pool[g->p].next=g->adjs[u];
    g->adjs[u]=g->p++;

    g->pool[g->p].v=u;
    g->pool[g->p].f=0;
    g->pool[g->p].c=0;
    g->pool[g->p].next=g->adjs[v];
    g->adjs[v]=g->p++;
}
void    bfs(struct graph* g,int s,int e){
    int* q=(int*)malloc(sizeof(int)*g->n);
    int f=0; // front of queue
    int r=0; // rear  of queue
    int d; // pool index dummy
    int u; int v;
    g->dept[s]=0;
    q[r++]=s; // enqueue
    while(f<r){
        u=q[f++]; // dequeue
        d=g->adjs[u]; // dequeue
        while(d!=-1){
            v=g->pool[d].v;
            if((g->dept[v]==-1)&&(g->pool[d].c-g->pool[d].f>0)){
                g->dept[v]=g->dept[u]+1;
                q[r++]=v; // enqueue
                if(v==e){free(q); return;} // 조기종료
            }
            d=g->pool[d].next;
        }
    }
    free(q);
}
int     dfs(struct graph* g,int s,int e,int f){
    if(s==e){return f;}
    int v;
    int c; // capacity
    int p;
    int* d=&g->curr[s];
    while(*d!=-1){
        v=g->pool[*d].v;
        c=g->pool[*d].c-g->pool[*d].f;
        if((g->dept[v]==g->dept[s]+1)&&(c>0)){
            p=dfs(g,v,e,(f<c)?f:c);
            if(p>0){
                g->pool[*d  ].f+=p;
                g->pool[*d^1].f-=p;
                return p;
            }
        }
        *d=g->pool[*d].next;
    }
    return 0;
}
int    flow(struct graph* g,int s,int e){
    int j;
    int p;
    int f=0;
    while(1){
        for(j=0;j<g->n;j++){
            g->dept[j]=-1;
            g->curr[j]=g->adjs[j];
        }
        bfs(g,s,e);
        if(g->dept[e]==-1){break;}
        while(1){
            p=dfs(g,s,e,INF);
            if(p==0){break;}
            f+=p;
        }
    }
    return f;
}