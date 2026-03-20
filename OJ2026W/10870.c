// B2 10870: 피보나치 수 5(재귀)
#include<stdio.h>
#include<stdlib.h>

int* a;

int fib(int n);

int main(void){
    int j;
    int n; scanf("%d",&n);
    a=(int*)malloc(sizeof(int)*(n+1));
    a[0]=0;
    a[1]=1;
    for(j=2;j<=n;j++){a[j]=-1;}
    printf("%d",fib(n));
    free(a);
}

int fib(int n){
    if(a[n]!=-1){return a[n];}
    else        {return a[n]=fib(n-2)+fib(n-1);}
}