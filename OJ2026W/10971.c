// S2 10971: 외판원 순회 2(TSP,부르트포스)
#include <stdio.h>

#define N 10 // 노드 최대 개수
#define INF 2147483647

struct graph{
    int n;          // 노드 개수
    int adjs[N][N]; // 인접행렬
    int vist[N];    // 방문 상태: 0(NO),1(YES)
    int m;          // 최소비용
};

void tsp(struct graph* g,int cur,int num,int acc);

int main(void){
    int j; // loop variable
    int k; // loop variable
    int n;

    // 그래프 초기화
    struct graph g;
    scanf("%d",&n);
    for(j=0;j<n;j++){
        g.vist[j]=0;
        for(k=0;k<n;k++){scanf("%d",&g.adjs[j][k]);}
    }
    g.n=n;
    g.m=INF;

    // TSP
    g.vist[0]=1;
    tsp(&g,0,1,0);
    
    // 결과 출력
    printf("%d",g.m);
}

void tsp(struct graph* g,int cur,int num,int acc){
    int j; // loop variable
    if(num==g->n){
        if(g->adjs[cur][0]!=0){
            if(g->m>acc+g->adjs[cur][0]){
               g->m=acc+g->adjs[cur][0];
            }
        }
        return;
    }
    for(j=0;j<g->n;j++){
        if((g->vist[j]==0)&&(g->adjs[cur][j]!=0)){
            g->vist[j]=1;
            tsp(g,j,num+1,acc+g->adjs[cur][j]);
            g->vist[j]=0;
        }
    }
}