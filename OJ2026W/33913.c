// S1 33913: even하게 익은 SCON(조합론,분할정복거듭제곱)
#include<stdio.h>
#include<stdlib.h>

# define D 1000000007 // divisor
# define I 500000004 // 모듈로역원

long long int power(long long int b,long long int e);

int main(void){
    long long int n; scanf("%lld",&n);
    printf("%lld",((power(26,n)+power(22,n))*I%D)); // \sum_{k=0,2,4,...} C(n,k) \times 2^k \times 24^k=(26^n+22^n)/2
}

long long int power(long long int b,long long int e){
    if(e==0){return 1;}
    if(e==1){return b%D;}
    long long int t;
    if(e%2==0){t=power(b,e/2);     return (t*t)%D;}
    else      {t=power(b,(e-1)/2); return (((t*t)%D)*(b%D)%D);}
}
