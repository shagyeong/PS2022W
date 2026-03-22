// G4 3190: 뱀(구현,시뮬레이션,큐)
#include<stdio.h>

#define NO 0 // 빈칸
#define SN 1 // 뱀
#define AP 2 // 사과

struct node{
    int r;
    int c;
};

int t; // 타이머
int n; int m;
struct node q[10000];
int tail; // 현위치: 꼬리 포인터
int head; // 현위치: 머리 포인터
int u; int v; // 다음 머리 위치
int d; // 현 방향
int grid[100][100];
struct node dirs[4]={{-1,0},{0,1},{1,0},{0,-1}}; // 시계방향
int x; char _e; int e; // 방향 변환 정보

int main(void){
    int j; int k;
    int _;
    scanf("%d",&n); m=n; // 문제 조건: nxn 격자
    for(j=0;j<n;j++){for(k=0;k<m;k++){grid[j][k]=0;}}

    // 사과 입력
    scanf("%d",&_);
    while(_-->0){
        scanf("%d %d",&u,&v);
        grid[u-1][v-1]=AP;
    }

    // 방향 변환 정보
    scanf("%d",&_);
    scanf("%d %c",&x,&_e); _--;
    if(_e=='L'){e=-1;} // 반시계 90
    if(_e=='D'){e= 1;} // 시계 90

    // 초기화
    t=0;
    d=1; // {0,1}(오른쪽)
    tail=0;
    head=0;
    q[head  ].r=0;
    q[head++].c=0;
    grid[0][0]=SN;
    while(1){
        t++;
        u=q[head-1].r+dirs[d].r; if((u<0)||(n<=u)){break;}
        v=q[head-1].c+dirs[d].c; if((v<0)||(m<=v)){break;}
        if(grid[u][v]==SN){break;}
        if(grid[u][v]==NO){
            grid[u][v]=SN;
            grid[q[tail].r][q[tail].c]=NO;
            q[head].r=u;
            q[head].c=v;
            tail++;
            head++;
        }
        else if(grid[u][v]==AP){
            grid[u][v]=SN;
            q[head].r=u;
            q[head].c=v;
            head++;
        }

        if(t==x){
            d+=e;
            if(d>=4){d%=4;}
            if(d< 0){d=3;}

            if(_>0){
                scanf("%d %c",&x,&_e); _--;
                if(_e=='L'){e=-1;} // 반시계 90
                if(_e=='D'){e= 1;} // 시계 90
            }
        }
    }
    printf("%d",t);    
}