// P3 3648: 아이돌(SCC,2-SAT)
#include<stdio.h>
#include<stdlib.h>

struct node{
    int v;
    int next;
};

int n; // number of node
int e; // number of edge
int p; // pool index
int s; // number of scc
int c; // clock
int t; // top of stack
int*         adjs;
int*         dfns;
int*         lows;
int*         isin;
int*         stck;
int*         sccs; // 노드별 scc id
struct node* pool;

void   init(void);
void  reset(void);
void  clean(void);
void insert(int u,int v);
void tarjan(int u);

int main(void){
    int j;
    int x; int u; // x, not x
    int y; int v; // y, not y
    int f; // flag
    init();
    while(scanf("%d %d",&n,&e)==2){
        reset();
        insert(n+1,1);
        for(j=0;j<e;j++){
            scanf("%d %d",&x,&y);
            if(x>0){u=n+x;}else{u=-x; x=n-x;}
            if(y>0){v=n+y;}else{v=-y; y=n-y;}
            insert(u,y); // not x -> y
            insert(v,x); // not y -> x
        }
        for(j=1;j<=2*n;j++){if(dfns[j]==0){tarjan(j);}}
        f=1;
        for(j=1;j<=n;  j++){if(sccs[j]==sccs[j+n]){printf("no\n"); f=0; break;}}
        if(f==1){printf("yes\n");}
    }
    clean();
}

void   init(void){
    adjs=(int*)malloc(sizeof(int)*2001);
    dfns=(int*)malloc(sizeof(int)*2001);
    lows=(int*)malloc(sizeof(int)*2001);
    isin=(int*)malloc(sizeof(int)*2001);
    stck=(int*)malloc(sizeof(int)*2001);
    sccs=(int*)malloc(sizeof(int)*2001);
    pool=(struct node*)malloc(sizeof(struct node)*4001);
}
void  reset(void){
    int j;
    p=0;
    s=0;
    c=0;
    t=0;
    for(j=1;j<=2*n;j++){
        adjs[j]=-1;
        dfns[j]=0;
        lows[j]=0;
        isin[j]=0;
        sccs[j]=-1;
    }
}
void  clean(void){
    free(adjs);
    free(dfns);
    free(lows);
    free(isin);
    free(stck);
    free(sccs);
    free(pool);
}
void insert(int u,int v){
    pool[p].v=v;
    pool[p].next=adjs[u];
    adjs[u]=p++;
}
void tarjan(int u){
    int b; int v;

    dfns[u]=++c;
    lows[u]=  c;
    stck[t++]=u;
    isin[u]=  1;

    b=adjs[u];
    while(b!=-1){
        v=pool[b].v;
        if(dfns[v]==0){
            tarjan(v);
            if(lows[v]<lows[u]){lows[u]=lows[v];}
        }
        else if(isin[v]!=0){
            if(dfns[v]<lows[u]){lows[u]=dfns[v];}
        }
        b=pool[b].next;
    }
    if(lows[u]==dfns[u]){
        while(1){
            v=stck[--t];
            isin[v]=0;
            sccs[v]=s;
            if(v==u){break;}
        }
        s++;
    }
}