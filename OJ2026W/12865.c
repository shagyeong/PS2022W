// G5 12865: 평범한 배낭(DP, knapsack)
#include<stdio.h>

int w[101];
int v[101];
int t[101][100001];

int knapsack(int w[],int v[],int n,int m){
    int j;  // loop variable
    int k;  // loop variable
    for(j=0;j<=n;j++){
        for(k=0;k<=m;k++){
            if((j==0)||(k==0)){
                t[j][k]=0;
            }
            else if(w[j-1]<=k){
                t[j][k]=(v[j-1]+t[j-1][k-w[j-1]]>t[j-1][k])?v[j-1]+t[j-1][k-w[j-1]]:t[j-1][k];
            }
            else{
                t[j][k]=t[j-1][k];
            }
        }
    }
    return t[n][m];
}
int main(void){
    int j; //loop variable
    int n;
    int m;
    scanf("%d %d",&n,&m);
    for(j=0;j<n;j++){
        scanf("%d %d",&w[j],&v[j]);
    }
    printf("%d",knapsack(w,v,n,m));
}