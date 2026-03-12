// P5 1506: 경찰서(SCC)
#include<stdio.h>
#include<stdlib.h>

struct node{
    int v;
    int next;
};
struct scc{
    int  n; // number of node
    int* a; // array of node number
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
int*         cost; // 문제 조건: 노드별 건설 비용
struct node* pool;
struct scc*  sccs;

void   init(void);
void  clean(void);
void insert(int u,int v);
void tarjan(int u);

int main(void){
    int j; int k=0;
    scanf("%d",&n);
    int u;
    int a=0; // answer: 각 scc 최소값 합
    int m; // 각 scc 최소값
    
    n+=1; e=n*n; init();  // 1-based
    n-=1;
    
    for(j=1;j<=n;j++){scanf("%d",&cost[j]);}
    for(j=1;j<=n;j++){for(k=1;k<=n;k++){
        scanf("%1d",&u);
        if(u==1){insert(j,k);}
    }}

    for(j=1;j<=n;j++){if(dfns[j]==0){tarjan(j);}}
    for(j=0;j< s;j++){
        m=cost[sccs[j].a[0]];
        for(k=1;k<sccs[j].n;k++){if(m>cost[sccs[j].a[k]]){m=cost[sccs[j].a[k]];}}
        a+=m;
    }

    printf("%d",a);
    clean();
}

void   init(void){
    int j;
    p=0;
    s=0;
    c=0;
    t=0;
    adjs=(int*)malloc(sizeof(int)*n);
    dfns=(int*)malloc(sizeof(int)*n);
    lows=(int*)malloc(sizeof(int)*n);
    isin=(int*)malloc(sizeof(int)*n);
    stck=(int*)malloc(sizeof(int)*n);
    cost=(int*)malloc(sizeof(int)*n);
    pool=(struct node*)malloc(sizeof(struct node)*e);
    sccs=(struct scc*) malloc(sizeof(struct scc) *n);
    for(j=0;j<n;j++){
        adjs[j]=-1;
        dfns[j]=0;
        lows[j]=0;
        isin[j]=0;
    }
}
void  clean(void){
    int j;
    for(j=0;j<s;j++){free(sccs[j].a);}
    free(adjs);
    free(dfns);
    free(lows);
    free(isin);
    free(stck);
    free(cost);
    free(pool);
    free(sccs);
}
void insert(int u,int v){
    pool[p].v=v;
    pool[p].next=adjs[u];
    adjs[u]=p++;
}
void tarjan(int u){
    int j; int k=0;
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
        j=t; while(1){k++; if(stck[--j]==u){break;}}
        sccs[s].n=0;
        sccs[s].a=(int*)malloc(sizeof(int)*k);
        while(1){
            v=stck[--t]; isin[v]=0;
            sccs[s].a[sccs[s].n++]=v;
            if(v==u){break;}
        }
        s++;
    }
}