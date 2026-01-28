// B1 2748: 피보나치 수 2(DP)
#include<stdio.h>

int main(void){
    long long int j;
    long long int t[91];
    long long int n; scanf("%lld",&n);

    t[0]=0;
    t[1]=1;
    for(j=2;j<=90;j++){t[j]=t[j-2]+t[j-1];}

    printf("%lld",t[n]);
}