// G4 14500: 테트로미노(격자그래프,DFS,브루트포스)
#include<stdio.h>
#include<stdlib.h>

#define NO 0
#define OK 1

int MAX;
int n; int m; // size of grid
int** grid;
int** vist;
int*  data;
int*  zero; // data of vist

void dfs(int r,int c,int d,int a); // row, column, 깊이, 누적

int main(void){
    int j; int k;
    int a; // 'ㅗ' 누적합
    scanf("%d %d",&n,&m);
    grid=(int**)malloc(sizeof(int*)*n);
    vist=(int**)malloc(sizeof(int*)*n);
    data=(int*) malloc(sizeof(int) *n*m);
    zero=(int*) calloc(n*m,sizeof(int));
    k=0;
    for(j=0;j<n;j++){
        grid[j]=data+k;
        vist[j]=zero+k;
        k+=m;
    }
    for(j=0;j<n;j++){for(k=0;k<m;k++){scanf("%d",&grid[j][k]);}}

    MAX=0;
    for(j=0;j<n;j++){for(k=0;k<m;k++){dfs(j,k,0,0);}}
    for(j=0;j<=n-3;j++){for(k=0;k<=m-2;k++){ // 'ㅏ'
        a= grid[j][k];
        a+=grid[j+1][k]; a+=grid[j+1][k+1];
        a+=grid[j+2][k];
        MAX=(MAX>a)?MAX:a;
    }}
    for(j=0;j<=n-3;j++){for(k=1;k<m;k++){ // 'ㅓ'
                           a= grid[j][k];
        a+=grid[j+1][k-1]; a+=grid[j+1][k];
                           a+=grid[j+2][k];
        MAX=(MAX>a)?MAX:a;
    }}
    for(j=0;j<=n-2;j++){for(k=0;k<=m-3;k++){ // 'ㅜ'
        a=grid[j][k]; a+=grid[j  ][k+1]; a+=grid[j][k+2];
                      a+=grid[j+1][k+1];
        MAX=(MAX>a)?MAX:a;
    }}
    for(j=1;j<n;j++){for(k=0;k<=m-3;k++){ // 'ㅗ'
                       a= grid[j-1][k+1];
        a+=grid[j][k]; a+=grid[j  ][k+1]; a+=grid[j][k+2];
        MAX=(MAX>a)?MAX:a;
    }}

    printf("%d",MAX);

    free(data); free(zero);
    free(grid); free(vist);
}

void dfs(int r,int c,int d,int a){
    if(d==3){MAX=(grid[r][c]+a>MAX)?(grid[r][c]+a):MAX;}
    else{
        vist[r][c]=OK;
        if((r-1>=0)&&(vist[r-1][c]==NO)){dfs(r-1,c,d+1,a+grid[r][c]);}
        if((r+1< n)&&(vist[r+1][c]==NO)){dfs(r+1,c,d+1,a+grid[r][c]);}
        if((c-1>=0)&&(vist[r][c-1]==NO)){dfs(r,c-1,d+1,a+grid[r][c]);}
        if((c+1< m)&&(vist[r][c+1]==NO)){dfs(r,c+1,d+1,a+grid[r][c]);}
        vist[r][c]=NO;
    }
}