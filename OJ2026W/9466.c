// G3 9466: 팀 프로젝트(DFS)
#include<stdio.h>

#define N 100001

int edge[N];
int vist[N];
int a; // answer

void dfs(int u);

int main(void){
    int j;
    int k;
    int t; scanf("%d",&t);
    int n;
    for(j=0;j<t;j++){
        scanf("%d",&n);
        a=0;
        for(k=1;k<=n;k++){scanf("%d",&edge[k]);vist[k]=0;}
        for(k=1;k<=n;k++){if(vist[k]==0){dfs(k);}}
        printf("%d\n",n-a);
    }
}

void dfs(int u){
    int j;
    int d=edge[u];
    vist[u]=1;
    if(vist[d]==0){dfs(d);}
    else if(vist[d]==1){
        for(j=d;j!=u;j=edge[j]){
            a+=1;
        }
        a+=1;
    }
    vist[u]=2;
}