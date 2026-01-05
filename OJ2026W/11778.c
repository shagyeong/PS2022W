// P5 11778: 피보나치 수와 최대공약수(분할정복거듭제곱,유클리드 호제법)
// gcd(F(a),F(b))=F(gcd(a,b))
#include<stdio.h>
#include<stdlib.h>
#define Q 1000000007
struct matrix{
    unsigned long long int m[2][2];
};
struct matrix fib(unsigned long long int n);
unsigned long long int gcd(unsigned long long int A,unsigned long long int B);

int main(void){
    unsigned long long int a;
    unsigned long long int b;
    unsigned long long int g; // gcd
    scanf("%llu %llu",&a,&b);
    g=gcd(a,b);
    struct matrix m;
    m=fib(g-1);
    printf("%llu",m.m[0][0]%Q);
}

unsigned long long int gcd(unsigned long long int A,unsigned long long int B){
    unsigned long long int a;
    unsigned long long int b;
    unsigned long long int t;
    if(A<B){t=A;A=B;B=t;}
    a=A;
    b=B;
    while(a%b!=0){
        t=a;
        a=b;
        b=t%b;
    }
    return b;
}
struct matrix fib(unsigned long long int n){
    if(n>1000000000000000001){struct matrix m; m.m[0][0]=0; return m;} // n-=-1 -> 언더플로우 활용
    if(n==0 ){struct matrix m; m.m[0][0]=1; return m;}
    if(n==1 ){
        struct matrix m;
        m.m[0][0]=1; m.m[0][1]=1;
        m.m[1][0]=1; m.m[1][1]=0;
        return m;        
    }
    if(n%2==0){
        struct matrix t=fib(n/2);
        unsigned long long int a=t.m[0][0]; unsigned long long int b=t.m[0][1];
        unsigned long long int c=t.m[1][0]; unsigned long long int d=t.m[1][1];
        // t*t
        t.m[0][0]=a*a+b*c; t.m[0][1]=a*b+b*d;
        t.m[1][0]=c*a+d*c; t.m[1][1]=c*b+d*d;

        t.m[0][0]%=Q; t.m[0][1]%=Q;
        t.m[1][0]%=Q; t.m[1][1]%=Q;
        return t;
    }
    else{
        struct matrix t=fib((n-1)/2);
        unsigned long long int a=t.m[0][0]; unsigned long long int b=t.m[0][1];
        unsigned long long int c=t.m[1][0]; unsigned long long int d=t.m[1][1];
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