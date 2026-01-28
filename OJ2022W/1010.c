// S5 1010: 다리 놓기(DP,조합론)
#include<stdio.h>

int main(void){
    int j; int k;
    int o; scanf("%d",&o);
    int n; int m;
    long long int t[31][31];

    // 테이블 초기화: combination(j,0),combination(j,j)
    for(j=0;j<=30;j++){t[j][0]=1; t[j][j]=1;}

    // 점화식
    for(j=1;j<=30;j++){
    for(k=1;k<  j;k++){
        t[j][k]=t[j-1][k-1]+t[j-1][k];
    }}

    // 결과 출력
    for(j=0;j<o;j++){
        scanf("%d %d",&n,&m);
        printf("%lld\n",t[m][n]); // combination(m,n)
    }
}