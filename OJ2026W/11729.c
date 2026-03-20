// G5 11729: 하노이 탑 이동 순서(재귀)
#include<stdio.h>

void solve(int n,int a,int b,int c);

int main(void){
    int n; scanf("%d",&n);
    printf("%d\n",(1<<n)-1);
    solve(n,1,2,3);
}

void solve(int n,int a,int b,int c){
    if(n==1){printf("%d %d\n",a,c);}
    else{
        solve(n-1,a,c,b);
        solve(1,  a,b,c);
        solve(n-1,b,a,c);
    }
}