// G4 1976: 여행 가자(분리집합)
#include<stdio.h>
#include<stdlib.h>

#define NO 0
#define OK 1

struct node{
    int v;
    int next;
};
struct graph{
    int n;
    int e;
    int p;
    int* adjs;
    int* vist;
    int* pare; // 분리집합
    struct node* pool;
};

int getroot(struct graph* g,int q);
void  unify(struct graph* g,int u,int v);

void    dfs(struct graph* g,int s);
void   init(struct graph* g,int n,int e);
void  clean(struct graph* g);
void insert(struct graph* g,int u,int v);

int main(void){
    int j; int k;
    int n; scanf("%d",&n);
    int m; scanf("%d",&m);
    int u;
    int r; // root of src
    int* a=(int*)malloc(sizeof(int)*m); // 여행 계획
    struct graph g;
    init(&g,n+1,n*n); // 문제 조건: 1-based, 에지 입력 n*n개

    for(j=1;j<=n;j++){
    for(k=1;k<=n;k++){
        scanf("%d",&u);
        if(u==1){insert(&g,j,k);}
    }}
    for(j=0;j<m;j++){scanf("%d",&a[j]);}

    dfs(&g,a[0]);
    r=getroot(&g,a[0]);
    for(j=1;j<m;j++){
        if(r!=getroot(&g,a[j])){
            clean(&g);
            free(a);
            printf("NO");
            return 0;
        }
    }

    printf("YES");
    clean(&g);
    free(a);
    return 0;
}

int getroot(struct graph* g,int q){
    if(g->pare[q]==q){return q;}
    else             {return g->pare[q]=getroot(g,g->pare[q]);}
}
void  unify(struct graph* g,int u,int v){
    g->pare[getroot(g,u)]=getroot(g,v);
}
void    dfs(struct graph* g,int s){
    int  d;
    int* a=(int*)malloc(sizeof(int)*(g->n));
    int  t=0;
    a[t++]=s;
    g->vist[s]=OK;
    while(t>0){
        d=g->adjs[a[--t]]; // pop
        while(d!=-1){
            unify(g,s,g->pool[d].v);
            if(g->vist[g->pool[d].v]==NO){
                g->vist[g->pool[d].v]=OK;
                a[t++]=g->pool[d].v;
            }
            d=g->pool[d].next;
        }
    }
    free(a);
}
void   init(struct graph* g,int n,int e){
    int j;
    g->n=n;
    g->e=e;
    g->p=0;
    g->adjs=(int*)malloc(sizeof(int)*n);
    g->vist=(int*)malloc(sizeof(int)*n);
    g->pare=(int*)malloc(sizeof(int)*n);
    g->pool=(struct node*)malloc(sizeof(struct node)*e);
    for(j=0;j<n;j++){
        g->adjs[j]=-1;
        g->vist[j]=NO;
        g->pare[j]=j;
    }
}
void  clean(struct graph* g){
    free(g->adjs);
    free(g->vist);
    free(g->pare);
    free(g->pool);
}
void insert(struct graph* g,int u,int v){
    g->pool[g->p].v=v;
    g->pool[g->p].next=g->adjs[u];
    g->adjs[u]=g->p++;
}