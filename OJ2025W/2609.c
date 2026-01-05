// B1 2069: 최대공약수와 최소공배수(정수론,유클리드 호제법)
#include<stdio.h>

int main(void){
    unsigned int A;
    unsigned int B;
    unsigned int a;
    unsigned int b;
    unsigned int t; // tmp
    scanf("%d %d",&A,&B);
    if(A<B){t=A;A=B;B=t;}      //swap: A>b인 상태 유지

    a=A;
    b=B;
    while(a%b!=0){
        t=a;
        a=b;
        b=t%b;
    }

    printf("%d\n",b);
    printf("%d\n",A*B/b);
}
