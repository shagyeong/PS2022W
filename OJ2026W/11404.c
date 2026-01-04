// G4 11404: 플로이드(플로이드-워셜)
#include<stdio.h>

#define N   801     // 노드 최대 개수
#define INF 1000000000001 // 100,000*100,000

struct graph{
    int n; // 노드 개수
    long long int dist[N][N];
};

struct graph g;

void init_graph(int n);
void insert(int u,int v,int w);
void fw(void);

int main(void){
    int j; // loop variable
    int k; // loop variable
    int n; // node
    int e; // edge
    int u; // insert buffer
    int v; // insert buffer
    int w; // insert buffer
    
    scanf("%d",&n);
    scanf("%d",&e);
    init_graph(n+1); // n+1: 1부터 시작하는 과제 환경

    for(j=0;j<e;j++){
        scanf("%d %d %d",&u,&v,&w);
        insert(u,v,w);
    }
    fw();
    
    for(j=1;j<=n;j++){
        for(k=1;k<=n;k++){
            if(g.dist[j][k]==INF){printf("0 ");}
            else                 {printf("%lld ",g.dist[j][k]);}
        }
        printf("\n");
    }
    return 0;    
}

void init_graph(int n){
    int j;
    int k;
    for(j=0;j<n;j++){
        for(k=0;k<n;k++){
            if(j==k){g.dist[j][k]=0;}
            else    {g.dist[j][k]=INF;}
        }
    }
    g.n=n;
}
void insert(int u,int v,int w){
    if(g.dist[u][v]>w){g.dist[u][v]=w;}
}
void fw(){
    int j;
    int k;
    int l;
    for(j=1;j<g.n;j++){
    for(k=1;k<g.n;k++){
    for(l=1;l<g.n;l++){
        if(g.dist[k][l]>g.dist[k][j]+g.dist[j][l]){
           g.dist[k][l]=g.dist[k][j]+g.dist[j][l];
        }
    }}}
}