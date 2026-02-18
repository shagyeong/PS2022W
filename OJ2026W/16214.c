// D5 16214: N과 M(정수론,분할정복거듭제곱,재귀,오일러피함수)
#include<stdio.h>
#include<math.h>

long long int d; // 전역 divisor
long long int solve(long long int n,long long int m);
long long int power(long long int b,long long int e);
long long int   phi(long long int n);

int main(void){
    long long int j;
    long long int t; scanf("%lld",&t);
    long long int n; // long long int d;
    for(j=0;j<t;j++){
        scanf("%lld %lld",&n,&d);
        printf("%lld\n",solve(n,d)%d);
    }
}

long long int solve(long long int n,long long int m){
    if(m==1){return 1;}
    long long int p=phi(m);
    long long int e=solve(n,p);
    d=m;
    return power(n,e);
}
long long int power(long long int b,long long int e){
    if(e==0){return (1>=d)?(1%d+d):1;} // b^0
    if(e==1){return (b>=d)?(b%d+d):b;} // b^1
    long long int t=power(b,e/2);
    t*=t;
    if(t>=d){t=(t%d)+d;}
    if(e%2==0){return t;}
    else      {t*=(b%d); if(t>=d){t=(t%d)+d;} return t;}
}
long long int phi(long long int n){
    long long int j;
    long long int q=n; // quotient
    long long int r=n; // result: phi(n)
    for(j=2;j*j<=q;j++){
        if(q%j==0){
            r-=r/j;
            while(q%j==0){q/=j;}
        }
    }
    if(q>1){r-=(r/q);}
    return r;
}