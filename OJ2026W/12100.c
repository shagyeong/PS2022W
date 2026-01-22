// G1 12100: 2048(재귀,브루트포스,시뮬레이션,백트래킹)
#include <stdio.h>

#define U 0
#define D 1
#define L 2
#define R 3

int N; // size of map
int M; // max value

void   max(int b[20][20]);
void solve(int b[20][20],int i); // i: 재귀 깊이
void  move(int b[20][20],int d);

int main(void){
    int j;
    int k;
    int b[20][20];
    scanf("%d",&N);
    M=0;
    for(j=0;j<N;j++){for(k=0;k<N;k++){scanf("%d",&b[j][k]);}}
    
    solve(b,0);
    printf("%d",M);
}

void   max(int b[20][20]){
    int j;
    int k;
    for(j=0;j<N;j++){for(k=0;k<N;k++){M=(M>b[j][k])?M:b[j][k];}}
}
void solve(int b[20][20],int i){
    if(i==5){max(b); return;}
    int d; // 재귀 방향
    int j;
    int k;
    int n[20][20]; // 복사본

    for(d=0;d<4;d++){
        for(j=0;j<N;j++){for(k=0;k<N;k++){n[j][k]=b[j][k];}}
        move(n,d);
        solve(n,i+1);
    }
}
void move(int b[20][20],int d){
    int m[20][20]={0}; // 결합 상태 마크
    int j; int k; // loop variable
    int r; int c; // row, column
    
    if(d==U){
        for(k=0;k<N;k++){
        for(j=1;j<N;j++){
            if(b[j][k]==0){continue;}
            r=j;
            while((r>0)&&(b[r-1][k]==0)){
                b[r-1][k]=b[r][k];
                b[r--][k]=0;
            }
            if((r>0)&&(b[r-1][k]==b[r][k])&&(m[r-1][k]==0)){
                b[r-1][k]*=2; m[r-1][k]=1;
                b[r  ][k]=0;
            }
        }}
    }
    else if(d==D){
        for(k=0;  k< N;k++){
        for(j=N-2;j>=0;j--){
            if(b[j][k]==0){continue;}
            r=j;
            while((r<N-1)&&(b[r+1][k]==0)){
                b[r+1][k]=b[r][k];
                b[r++][k]=0;
            }
            if((r<N-1)&&(b[r+1][k]==b[r][k])&&(m[r+1][k]==0)){
                b[r+1][k]*=2; m[r+1][k]=1;
                b[r  ][k]=0;
            }
        }}
    }
    else if(d==L){
        for(j=0;j<N;j++){
        for(k=1;k<N;k++){
            if(b[j][k]==0){continue;}
            c=k;
            while((c>0)&&(b[j][c-1]==0)){
                b[j][c-1]=b[j][c];
                b[j][c--]=0;
            }
            if((c>0)&&(b[j][c-1]==b[j][c])&&(m[j][c-1]==0)){
                b[j][c-1]*=2; m[j][c-1]=1;
                b[j][c  ]=0;
            }
        }}
    }
    else if(d==R){
        for(j=0;  j< N;j++){
        for(k=N-2;k>=0;k--){
            if(b[j][k]==0){continue;}
            c=k;
            while((c<N-1)&&(b[j][c+1]==0)){
                b[j][c+1]=b[j][c];
                b[j][c++]=0;
            }
            if((c<N-1)&&(b[j][c+1]==b[j][c])&&(m[j][c+1]==0)){
                b[j][c+1]*=2; m[j][c+1]=1;
                b[j][c  ]=0;
            }
        }}
    }
}