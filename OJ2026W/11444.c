// G2 11444: 피보나치 수 6(분할 정복 거듭제곱)
#include<stdio.h>
#include<stdlib.h>
#define Q 1000000007

struct matrix{
    long long int m[2][2];
};

struct matrix fib(long long int n);

int main(void){
    long long int n;
    scanf("%lld",&n);
    struct matrix m;
    m=fib(n-1);
    printf("%lld",m.m[0][0]%Q);
}

struct matrix fib(long long int n){
    if(n==-1){struct matrix m; m.m[0][0]=0; return m;}
    if(n==0 ){struct matrix m; m.m[0][0]=1; return m;}
    if(n==1 ){
        struct matrix m;
        m.m[0][0]=1; m.m[0][1]=1;
        m.m[1][0]=1; m.m[1][1]=0;
        return m;        
    }
    if(n%2==0){
        struct matrix t=fib(n/2);
        long long int a=t.m[0][0]; long long int b=t.m[0][1];
        long long int c=t.m[1][0]; long long int d=t.m[1][1];
        // t*t
        t.m[0][0]=a*a+b*c; t.m[0][1]=a*b+b*d;
        t.m[1][0]=c*a+d*c; t.m[1][1]=c*b+d*d;

        t.m[0][0]%=Q; t.m[0][1]%=Q;
        t.m[1][0]%=Q; t.m[1][1]%=Q;
        return t;
    }
    else{
        struct matrix t=fib((n-1)/2);
        long long int a=t.m[0][0]; long long int b=t.m[0][1];
        long long int c=t.m[1][0]; long long int d=t.m[1][1];
        // t*t
        t.m[0][0]=a*a+b*c; t.m[0][1]=a*b+b*d;
        t.m[1][0]=c*a+d*c; t.m[1][1]=c*b+d*d;
        t.m[0][0]%=Q; t.m[0][1]%=Q;
        t.m[1][0]%=Q; t.m[1][1]%=Q;
        // t*t*d
        a=t.m[0][0]; b=t.m[0][1];
        c=t.m[1][0]; d=t.m[1][1];
        t.m[0][0]=a+b; t.m[0][1]=a;
        t.m[1][0]=c+d; t.m[1][1]=c;
        t.m[0][0]%=Q; t.m[0][1]%=Q;
        t.m[1][0]%=Q; t.m[1][1]%=Q;
        return t;
    }
}