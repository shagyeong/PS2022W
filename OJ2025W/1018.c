// S3 1018: 체스판 다시 칠하기(브루트포스)
#include<stdio.h>
#include<stdlib.h>

int main(void){
    char l; // 개행
    int j; int k;
    int n; int m; scanf("%d %d",&n,&m); scanf("%c",&l);
    int r; int c;
    int t; // toggle
    int a=32; // answer
    char** grid=(char**)malloc(sizeof(char*)*n);
    char*  data=(char*) malloc(sizeof(char) *n*m);
    for(j=0;j<n;j++){grid[j]=data+(m*j);}
    for(j=0;j<n;j++){for(k=0;k<m;k++){scanf("%1c",&grid[j][k]);}scanf("%c",&l);}

    for(j=0;j<=n-8;j++){for(k=0;k<=m-8;k++){
        t=0;
    for(r=j;r< j+8;r++){for(c=k;c< k+8;c++){
        if(r%2==0){t+=(c%2==0)?((grid[r][c]=='B')?0:1):((grid[r][c]=='W')?0:1);}
        else      {t+=(c%2==0)?((grid[r][c]=='B')?1:0):((grid[r][c]=='W')?1:0);}
        }}
        t=(t>32)?(64-t):t;
        a=(a<t)?a:t;
    }}
    printf("%d",a);
    free(data);
    free(grid);
}