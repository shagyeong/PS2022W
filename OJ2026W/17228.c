// P2 17228: 아름다운 만영로(DFS,KMP)
// 부분성공 100/140
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define L 500001
#define NO 0
#define OK 1

char* q; // 패턴
int l; // length of pattern
int* f; // KMP 실패함수
int a; // answer
struct sode* s; // dfs stack
int h; // top of stack

struct node{
    int v;
    char w;
    int next;
};
struct sode{ // stack node
    int v;
    int k; // 진접두사 오프셋
};
struct graph{
    int n;
    int e;
    int p;
    int* adjs;
    int* vist;
    struct node* pool;
};

void   fail(void);
void    dfs(struct graph* g,int u);
void   init(struct graph* g,int n,int e);
void  clean(struct graph* g);
void insert(struct graph* g,int u,int v,char w);

int main(void){
    int j;
    int n; scanf("%d",&n);
    int u; int v; char w;
    struct graph g;
    q=(char*)       calloc(L,sizeof(char));
    f=(int*)        calloc(L,sizeof(int));
    s=(struct sode*)calloc(L,sizeof(struct sode));
    init(&g,n+1,2*n-2); // 1-based, undirected, tree
    for(j=0;j<n-1;j++){
        scanf("%d %d %c",&u,&v,&w);
        insert(&g,u,v,w);
        insert(&g,v,u,w);
    }
    scanf("%s",q);
    l=(int)strlen(q); q[l]='\0';

    a=0;
    h=-1;
    fail();
    dfs(&g,1);

    printf("%d",a);
    free(q);
    free(f);
    free(s);
    clean(&g);
}

void   fail(void){
    int j;
    int k;
    k=0;
    for(j=1;j<l;j++){
        while((k>0)&&(q[j]!=q[k])){k=f[k-1];}
        if(q[j]==q[k]){f[j]=++k;}
    }
}
void    dfs(struct graph* g,int u){
    int d; int k;
    int v;
    char w;
    int t; // 임시 진접두사 포인터

    s[++h].v=u;
    s[  h].k=0;
    g->vist[u]=OK;

    while(h>-1){
        d=s[h  ].v; d=g->adjs[d];
        k=s[h--].k;
        while(d!=-1){
            v=g->pool[d].v;
            w=g->pool[d].w;
            if(g->vist[v]==NO){
                g->vist[v]=OK;
                t=k;
                while((t>0)&&(q[t]!=w)){t=f[t-1];}
                if(q[t]==w){
                    if(t==l-1){a++; t=f[t];}
                    else      {t++;}
                }
                s[++h].v=v;
                s[  h].k=t;
            }
            d=g->pool[d].next;
        }
    }
}
void   init(struct graph* g,int n,int e){
    int j;
    g->n=n;
    g->e=e;
    g->p=0;
    g->adjs=(int*)malloc(sizeof(int)*n);
    g->vist=(int*)malloc(sizeof(int)*n);
    g->pool=(struct node*)malloc(sizeof(struct node)*e);
    for(j=0;j<n;j++){
        g->adjs[j]=-1;
        g->vist[j]=NO;
    }
}
void  clean(struct graph* g){
    free(g->adjs);
    free(g->vist);
    free(g->pool);
}
void insert(struct graph* g,int u,int v,char w){
    g->pool[g->p].v=v;
    g->pool[g->p].w=w;
    g->pool[g->p].next=g->adjs[u];
    g->adjs[u]=g->p++;
}