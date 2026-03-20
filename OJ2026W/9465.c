// S1 9465: 스티커(DP)
#include<stdio.h>

int n;
int a[2][100000];
int dp[2][100000];

int main(void){
    int j;
    int _; scanf("%d",&_);
    while(_-->0){
        scanf("%d",&n);
        for(j=0;j<n;j++){scanf("%d",&a[0][j]);}
        for(j=0;j<n;j++){scanf("%d",&a[1][j]);}
        dp[0][0]=a[0][0]; if(n>1){dp[0][1]=a[1][0]+a[0][1];}
        dp[1][0]=a[1][0]; if(n>1){dp[1][1]=a[0][0]+a[1][1];}
        for(j=2;j<n;j++){
            dp[0][j]=((dp[1][j-1])>(dp[1][j-2]))?(dp[1][j-1]+a[0][j]):(dp[1][j-2]+a[0][j]);
            dp[1][j]=((dp[0][j-1])>(dp[0][j-2]))?(dp[0][j-1]+a[1][j]):(dp[0][j-2]+a[1][j]);
        }
        printf("%d\n",((dp[0][n-1])>(dp[1][n-1]))?(dp[0][n-1]):(dp[1][n-1]));
    }
}