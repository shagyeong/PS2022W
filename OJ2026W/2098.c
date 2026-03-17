// G1 2098: 외판원 순회(TSP,비트필드DP)
#include<stdio.h>
#include<stdlib.h>

#define INF 1000000000

struct graph{
    int n;
    int** adjs;
    int* _adjs;
    int** vist; // [N][2^N]
    int* _vist;
};

int    tsp(struct graph* g,int u,int f);
void  init(struct graph* g,int n);
void clean(struct graph* g);

int main(void){
    int n; scanf("%d",&n);
    struct graph g;
    init(&g,n);
    printf("%d",tsp(&g,0,1));
    clean(&g);
}

int    tsp(struct graph* g,int u,int f){
    if(f==(1<<g->n)-1){ // (1<<g->n)-1: 0b1111..11(모든 도시 방문)
        if(g->adjs[u][0]!=0){return g->adjs[u][0];}
        else                {return INF;}
    }
    if(g->vist[u][f]!=-1){return g->vist[u][f];}
    int j;
    int t;
    g->vist[u][f]=INF;
    for(j=0;j<g->n;j++){
        if(((f&(1<<j))==0)&&(g->adjs[u][j]!=0)){
            t=tsp(g,j,f|(1<<j));
            if((t!=INF)&&(g->vist[u][f]>g->adjs[u][j]+t)){g->vist[u][f]=g->adjs[u][j]+t;}
        }
    }
    return g->vist[u][f];
}
void  init(struct graph* g,int n){
    int j; int k;
    g->n=n;
    g->adjs=(int**)malloc(sizeof(int*)*n);
    g->vist=(int**)malloc(sizeof(int*)*n);
    g->_adjs=(int*)malloc(sizeof(int) *n*n);
    g->_vist=(int*)malloc(sizeof(int) *n*(1<<n));
    k=0; for(j=0;j<n;j++){g->adjs[j]=g->_adjs+k; k+=n;}
    k=0; for(j=0;j<n;j++){g->vist[j]=g->_vist+k; k+=(1<<n);}
    for(j=0;j<n;j++){for(k=0;k<n;     k++){scanf("%d",&g->adjs[j][k]);}}
    for(j=0;j<n;j++){for(k=0;k<(1<<n);k++){g->vist[j][k]=-1;}}
}
void clean(struct graph* g){
    free(g->_adjs);
    free(g->_vist);
    free(g->adjs);
    free(g->vist);
}