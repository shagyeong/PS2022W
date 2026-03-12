// P4 4196: 도미노(SCC,DAG,위상정렬)
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

int* ideg; // DAG

void   init(void);
void  reset(void); // nested testcase
void  clean(void);
void insert(int u,int v);
void tarjan(int u);

int main(void){
    int j;
    int _; scanf("%d",&_);
    int u; int v;
    int a; // answer
    int b;
    init(); // 문제공간 최대 크기 확보
    while(_-->0){
        scanf("%d %d",&n,&e);
        reset();
        for(j=0;j<e;j++){scanf("%d %d",&u,&v); insert(u,v);}
        for(j=1;j<=n;j++){if(dfns[j]==0){tarjan(j);}}

        for(j=1;j<=n;j++){
            b=adjs[j];
            while(b!=-1){
                v=pool[b].v;
                if(sccs[v]!=sccs[j]){ideg[sccs[v]]+=1;}
                b=pool[b].next;
            }
        }
        a=0;
        for(j=0;j<s;j++){if(ideg[j]==0){a+=1;}}
        printf("%d\n",a);
    }
    clean();
}

void   init(void){
    adjs=(int*)malloc(sizeof(int)*100001);
    dfns=(int*)malloc(sizeof(int)*100001);
    lows=(int*)malloc(sizeof(int)*100001);
    isin=(int*)malloc(sizeof(int)*100001);
    stck=(int*)malloc(sizeof(int)*100001);
    sccs=(int*)malloc(sizeof(int)*100001);
    pool=(struct node*)malloc(sizeof(struct node)*100001);

    ideg=(int*)malloc(sizeof(int)*100001);
}
void  reset(void){
    int j;
    p=0;
    s=0;
    c=0;
    t=0;
    for(j=0;j<=n;j++){
        adjs[j]=-1;
        dfns[j]=0;
        lows[j]=0;
        isin[j]=0;
        sccs[j]=-1;

        ideg[j]=0;
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

    free(ideg);
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