// S1 1992: 쿼드트리(분할정복,재귀)
#include<stdio.h>
#include<stdlib.h>

int grid[64][64];

void solve(int r,int c,int n);

int main(void){
    int j; int k;
    int n; scanf("%d",&n);
    for(j=0;j<n;j++){for(k=0;k<n;k++){scanf("%1d",&grid[j][k]);}}
    solve(0,0,n);
}

void solve(int r,int c,int n){
    int j; int k;
    int s=0;
    for(j=r;j<(r+n);j++){
    for(k=c;k<(c+n);k++){
        s+=grid[j][k];
    }}
    if(s==0)  {printf("0"); return;}
    if(s==n*n){printf("1"); return;}

    printf("(");
    solve(r,    c,    n/2);
    solve(r,    c+n/2,n/2);
    solve(r+n/2,c,    n/2);
    solve(r+n/2,c+n/2,n/2);
    printf(")");
}