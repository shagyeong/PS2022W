// G1 1562: 계단 수(비트필드DP)
#include <stdio.h>

#define Q 1000000000
int t[101][10][1024];

int main(void){
    int j; int k; int l;
    int n; scanf("%d",&n);
    int m; // mask
    long long int a=0; // answer
    for(j=1;j<=9;j++){t[1][j][1<<j]=1;}
    

    for(j=2;j<=n;j++){
        for(k=0;k<=9;k++){
            for(l=0;l<1024;l++){
                m=l|(1<<k);
                if(k>0){t[j][k][m]=(t[j][k][m]+t[j-1][k-1][l])%Q;}
                if(k<9){t[j][k][m]=(t[j][k][m]+t[j-1][k+1][l])%Q;}
            }
        }
    }

    for(j=0;j<=9;j++){a=(a+t[n][j][1023])%Q;}
    printf("%lld",a);
}
