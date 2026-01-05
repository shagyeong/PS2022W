// S3 1735: 분수 합(유클리드 호제법)
#include<stdio.h>

int lcm(int A,int B);
int gcd(int A,int B);

int main(void){
    unsigned int a; unsigned int c;
    unsigned int b; unsigned int d;
    unsigned int g; // gcd
    unsigned int l; // lcm
    scanf("%d %d",&a,&c);
    scanf("%d %d",&b,&d);
    l=lcm(c,d);
    a=l/c*a+l/d*b;

    g=gcd(a,l);
    a/=g;
    l/=g;
    printf("%d %d",a,l);
}

int lcm(int A,int B){
    unsigned int a;
    unsigned int b;
    unsigned int t; // tmp
    if(A<B){t=A;A=B;B=t;}      //swap: A>b인 상태 유지
    a=A;
    b=B;
    while(a%b!=0){
        t=a;
        a=b;
        b=t%b;
    }
    return A*B/b;
}
int gcd(int A,int B){
    unsigned int a;
    unsigned int b;
    unsigned int t;
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