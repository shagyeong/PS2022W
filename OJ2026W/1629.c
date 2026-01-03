// S1 1629: 곱셈(분할정복거듭제곱)
#include<stdio.h>

long long int power(long long int b,int e,int q);

int main(void){
    long long int b; int e; int q;
    scanf("%lld %d %d",&b,&e,&q);
    b%=q;
    printf("%lld",power(b,e,q)%q);
}

long long int power(long long int b,int e,int q){
    if(e==0)  {return 1;}
    if(e==1)  {return b;}
    if(e%2==0){long long t=power(b,e/2,    q);return (t*t)%q;}
    else      {long long t=power(b,(e-1)/2,q);return (((t*t)%q)*b)%q;}
}