// S2 1535: 안녕(DP,배낭)
#include<stdio.h>
#include<stdlib.h>

int* w;
int* v;
int** dp;
int* _dp;

int main(void){
    int j; int k=0;
    int n; scanf("%d",&n);
    int m=99; // 100-1
    w=(int*)malloc(sizeof(int)*(n+1));
    v=(int*)malloc(sizeof(int)*(n+1));
    dp=(int**)malloc(sizeof(int*)*(n+1));
    _dp=(int*)malloc(sizeof(int) *(n+1)*(m+1));
    w[0]=0; for(j=1;j<=n;j++){scanf("%d",&w[j]);}
    v[0]=0; for(j=1;j<=n;j++){scanf("%d",&v[j]);}
    for(j=0;j<=n;j++){dp[j]=_dp+k; k+=(m+1);}
    for(j=0;j<=n;j++){dp[j][0]=0;}
    for(j=0;j<=m;j++){dp[0][j]=0;}
    for(j=1;j<=n;j++){for(k=0;k<=m;k++){
        if(w[j]>k){dp[j][k]=dp[j-1][k];}
        else      {dp[j][k]=((dp[j-1][k])>(dp[j-1][k-w[j]]+v[j]))?(dp[j-1][k]):(dp[j-1][k-w[j]]+v[j]);}
    }}
    printf("%d",dp[n][m]);
    free(w);
    free(v);
    free(_dp);
    free(dp);
}