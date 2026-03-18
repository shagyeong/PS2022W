// G5 33915: a=b xor c(조합론,DP,분할정복거듭제곱)
#include<stdio.h>
#include<stdlib.h>

#define D 1000000007 // divisor

int comb(int n,int r);
long long int power(long long int b,long long int e);

int main(void){
    int x; int y; scanf("%d %d",&y,&x); // 1의 개수를 먼저줘서 바꿈
    if(x==0)                {printf("0"); return 0;}
    if(y%2!=0)              {printf("0"); return 0;}
    if((y<2*(x%3))||(2*x<y)){printf("0"); return 0;}
    y/=2;       // 010 101 110
    x-=y; x/=3; // 000
    printf("%lld",((long long int)comb(x+y,x)*power(3,y))%D); // combination(x'+y',x')*3^y
    return 0;
}

int comb(int n,int r){
    int j; int k=0;
    int** dp=(int**)malloc(sizeof(int*)*(n+1));
    int* _dp=(int*) malloc(sizeof(int) *(n+1)*(n+1));
    for(j=0;j<=n;j++){
        dp[j]=_dp+k; k+=(n+1);
        dp[j][0]=1;
        dp[j][j]=1;
    }
    for(j=1;j<=n;j++){
    for(k=1;k<=n;k++){
        dp[j][k]=dp[j-1][k-1]+dp[j-1][k];
        dp[j][k]%=D;
    }}
    return dp[n][r];
}
long long int power(long long int b,long long int e){
    if(e==0){return 1;}
    if(e==1){return b%D;}
    long long int t;
    if(e%2==0){t=power(b,e/2);     return (t*t)%D;}
    else      {t=power(b,(e-1)/2); return (((t*t)%D)*(b%D)%D);}
}