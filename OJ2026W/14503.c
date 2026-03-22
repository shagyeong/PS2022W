// G5 14503: 로봇 청소기(구현,시뮬레이션)
#include<stdio.h>
#include<stdlib.h>

#define OB -1 // 벽
#define NO 0 // 청소되지 않은 빈 칸
#define OK 1 // 청소된 빈칸

struct direction{
    int r;
    int c;
};

int a; // answer
int n; int m;
int r; int c; // 현 위치
int u; int v; // 다음 위치
int f; // 인접 셀 플래그: 0 - 청소되지 않은 빈 칸 없음
int d; // 현 방향
int grid[50][50];
struct direction dirs[4]={{-1,0},{0,1},{1,0},{0,-1}};

int main(void){
    int j; int k;
    scanf("%d %d",&n,&m);
    scanf("%d %d",&r,&c);
    scanf("%d",&d);
    for(j=0;j<n;j++){for(k=0;k<m;k++){
        scanf("%d",&grid[j][k]);
        if(grid[j][k]==1){grid[j][k]=OB;} // -1로 변경
    }}

    a=0;
    while(1){
        // 1. 현재 칸 청소
        if(grid[r][c]==NO){
            grid[r][c]=OK;
            a+=1;
        }
        // 인접 셀 확인
        f=0;
        for(j=0;j<4;j++){
            u=r+dirs[j].r; if((u<0)||(u>=n)){continue;}
            v=c+dirs[j].c; if((v<0)||(v>=m)){continue;}
            if(grid[u][v]==NO){f=1; break;}
        }
        if(f==1){
            d-=1; if(d<0){d=3;}
            u=r+dirs[d].r; if((u<0)||(u>=n)){continue;}
            v=c+dirs[d].c; if((v<0)||(v>=m)){continue;}
            if(grid[u][v]==NO){
                r=u;
                c=v;
            }
        }
        if(f==0){
            u=r-dirs[d].r; if((u<0)||(u>=n)){break;}
            v=c-dirs[d].c; if((v<0)||(v>=m)){break;}
            if(grid[u][v]==OB){break;}
            else{
                r=u;
                c=v;
            }
        }
    }
    printf("%d",a);
}