// G1 11401: 이항 계수 3(모듈로곱셈역원,페르마소정리,분할정복거듭제곱)
#include<stdio.h>
#include<stdlib.h>

#define D 1000000007

long long int power(long long int b,long long int e);

int main(void){
    long long int j;
    long long int n; long long int r; scanf("%lld %lld",&n,&r);
    long long int i; // inverse
    long long int* f=(long long int*)malloc(sizeof(long long int)*(n+1)); // factorial
    f[0]=1; f[1]=1;
    for(j=2;j<=n;j++){
        f[j]=f[j-1]*j;
        f[j]%=D;
    }
    i=power((f[r]*f[n-r])%D,D-2);
    printf("%lld",(f[n]*i)%D);
}

long long int power(long long int b,long long int e){
    if(e==0){return 1;}
    if(e==1){return b%D;}
    long long int t;
    if(e%2==0){t=power(b,e/2);     return (t*t)%D;}
    else      {t=power(b,(e-1)/2); return (((t*t)%D)*b)%D;}
}