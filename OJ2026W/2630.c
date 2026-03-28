// S2 2630: 색종이 만들기(분할정복,재귀)
#include<stdio.h>
#include<stdlib.h>

int grid[128][128];
int w;
int b;

void solve(int r,int c,int n);

int main(void){
    int j; int k;
    int n; scanf("%d",&n);
    for(j=0;j<n;j++){for(k=0;k<n;k++){scanf("%d",&grid[j][k]);}}

    w=0;
    b=0;
    solve(0,0,n);
    printf("%d\n",w);
    printf("%d",  b);
}

void solve(int r,int c,int n){
    if(n==1){
        if(grid[r][c]==0){w+=1; return;}
        if(grid[r][c]==1){b+=1; return;}
    }
    int j; int k;
    int s=0;
    for(j=r;j<(r+n);j++){
    for(k=c;k<(c+n);k++){
        s+=grid[j][k];
    }}
    if(s==0)  {w+=1; return;}
    if(s==n*n){b+=1; return;}
    solve(r,    c,    n/2);
    solve(r+n/2,c,    n/2);
    solve(r,    c+n/2,n/2);
    solve(r+n/2,c+n/2,n/2);
}