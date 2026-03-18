// P5 13977: 이항 계수와 쿼리(모듈로곱셈역원,페르마소정리,분할정복거듭제곱)
#include<stdio.h>
#include<stdlib.h>

#define N 4000000
#define D 1000000007

long long int* f;

void factorial(void);
long long int power(long long int b,long long int e);

int main(void){
    int j;
    int m; scanf("%d",&m);
    long long int n; long long int r;
    long long int i; // inverse

    factorial();
    for(j=0;j<m;j++){
        scanf("%lld %lld",&n,&r);
        i=power((f[r]*f[n-r])%D,D-2);
        printf("%lld\n",(f[n]*i)%D);
    }
}

void factorial(void){
    int j;
    f=(long long int*)malloc(sizeof(long long int)*(N+1));
    f[0]=1; f[1]=1;
    for(j=2;j<=N;j++){
        f[j]=f[j-1]*j;
        f[j]%=D;
    }
}
long long int power(long long int b,long long int e){
    long long int r=1;
    b%=D;
    while(e>0){
        if(e%2==1){r*=b; r%=D;}
        b*=b;
        b%=D;
        e/=2;
    }
    return r;
}