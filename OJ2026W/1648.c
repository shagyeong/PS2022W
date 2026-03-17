// P3 1648: 격자판 채우기(비트필드DP)
#include<stdio.h>
#include<stdlib.h>

#define D 9901

int** grid; // [n*m][1<<m]
int* _grid;

int main(void){
    int j; int k=0;
    int n; int m; scanf("%d %d",&n,&m); if((n*m)%2!=0){printf("0"); return 0;}
    grid=(int**)malloc(sizeof(int*)*(n*m+1));
    _grid=(int*)calloc((n*m+1)*(1<<m),sizeof(int));
    for(j=0;j<=n*m;j++){grid[j]=_grid+k; k+=(1<<m);}

    grid[0][0]=1;
    for(j=0;j<n*m;j++){
        for(k=0;k<(1<<m);k++){
            if((k&1)==1){
                grid[j+1][k>>1]+=grid[j][k];
                grid[j+1][k>>1]%=D;
            }
            else{
                grid[j+1][(k>>1)|(1<<(m-1))]+=grid[j][k];
                grid[j+1][(k>>1)|(1<<(m-1))]%=D;
                if(((j%m)!=(m-1))&&(k&2)==0){
                    grid[j+2][k>>2]+=grid[j][k];
                    grid[j+2][k>>2]%=D;
                }
            }
        }
    }
    printf("%d",grid[n*m][0]);
    free(_grid);
    free(grid);
    return 0;
}