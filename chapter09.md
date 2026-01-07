# 9장 기타 과제 유형
<!-- ## 9.1 재귀 -->
<!-- ## 9.2 백트래킹 -->
<!-- ## 9.3 문자열 조작 -->



## 9.4 P-NP 문제
### 9.4.1 TSP
#### TSP
TSP: traveling salesman problem  
순회 세일즈맨(또는 외판원) 문제  
#### 부르트포스 TSP
```C
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

    // 그래프 초기화
    struct graph g;
    g.n=4;
    g.m=INF;
    for(j=0;j<g.n;j++){g.vist[j]=0;}
    g.adjs[0][0]=0; g.adjs[0][1]=10; g.adjs[0][2]=15;g.adjs[0][3]=20;
    g.adjs[1][0]=5; g.adjs[1][1]=0;  g.adjs[1][2]=9; g.adjs[1][3]=10;
    g.adjs[2][0]=6; g.adjs[2][1]=13; g.adjs[2][2]=0; g.adjs[2][3]=12;
    g.adjs[3][0]=8; g.adjs[3][1]=8;  g.adjs[3][2]=9; g.adjs[3][3]=0;

    // TSP
    g.vist[0]=1;
    tsp(&g,0,1,0);
    
    // 결과 출력
    if(g.m==INF){printf("-1\n");}
    else        {printf("%d\n",g.m);}
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
```
```
$ ./test
35
```
<!-- #### DP TSP -->
