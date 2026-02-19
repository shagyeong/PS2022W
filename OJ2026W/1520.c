// G3 1520: 내리막길(DP,격자그래프)
#include<stdio.h>
#include<stdlib.h>

int n;
int m;
int** grid;
int** vist;
int*  data;
int*  zero;

int dfs(int r,int c);

int main(void){
    int j; int k=0;
    scanf("%d %d",&n,&m);
    grid=(int**)malloc(sizeof(int*)*n);
    vist=(int**)malloc(sizeof(int*)*n);
    data=(int*) malloc(sizeof(int) *n*m);
    zero=(int*) malloc(sizeof(int) *n*m);
    for(j=0;j<n;j++){
        grid[j]=data+k;
        vist[j]=zero+k;
        k+=m;
    }
    for(j=0;j<n;j++){for(k=0;k<m;k++){
        scanf("%d",&grid[j][k]);
        vist[j][k]=-1;
    }}
    printf("%d",dfs(0,0));
    free(data);
    free(zero);
    free(grid);
    free(vist);
}

int dfs(int r,int c){
    if((r==n-1)&&(c==m-1)){return 1;}
    if(vist[r][c]!=-1)    {return vist[r][c];}
    vist[r][c]=0;
    if((r-1>=0)&&(grid[r-1][c]<grid[r][c])){vist[r][c]+=dfs(r-1,c);}
    if((r+1< n)&&(grid[r+1][c]<grid[r][c])){vist[r][c]+=dfs(r+1,c);}
    if((c-1>=0)&&(grid[r][c-1]<grid[r][c])){vist[r][c]+=dfs(r,c-1);}
    if((c+1< m)&&(grid[r][c+1]<grid[r][c])){vist[r][c]+=dfs(r,c+1);}
    return vist[r][c];
}