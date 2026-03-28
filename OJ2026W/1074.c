// G5 1074: Z(분할정복,재귀)
#include<stdio.h>
#include<stdlib.h>

int u;
int v;

void solve(int r,int c,int s,int n);

int main(void){
    int n; scanf("%d",&n); n=(1<<n);
    scanf("%d %d",&u,&v);
    solve(0,0,0,n);
}

void solve(int r,int c,int s,int n){
    if((r>u)||(r+n<u)){return;}
    if((c>v)||(c+n<v)){return;}
    if(n==2){
        if     ((r  ==u)&&(c  ==v)){printf("%d",s); return;}
        else if((r  ==u)&&(c+1==v)){printf("%d",s+1); return;}
        else if((r+1==u)&&(c  ==v)){printf("%d",s+2); return;}
        else if((r+1==u)&&(c+1==v)){printf("%d",s+3); return;}
    }
    solve(r,    c,    s,          n/2);
    solve(r,    c+n/2,s+  (n*n/4),n/2);
    solve(r+n/2,c,    s+2*(n*n/4),n/2);
    solve(r+n/2,c+n/2,s+3*(n*n/4),n/2);
}