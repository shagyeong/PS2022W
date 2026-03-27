// G3 2638: 치즈(시뮬레이션,BFS,격자그래프)
// 가장자리 치즈 없음: (0,0) 격자그래프 탐색으로 '외부 공기'를 마크할 수 있다
#include<stdio.h>
#include<stdlib.h>

#define NO 0 // 빈칸
#define OK 1 // 치즈
#define MK 2 // 외부 공기

struct node{
    int r;
    int c;
};

int n;
int m;
int s;
int e;
struct node* q;
int** grid;
int** vist;
int* _grid;
int* _vist;

void   bfs(void);
void reset(void); // 방문 상태 초기화
void  melt(void); // 마크(2)해둔 치즈 녹이기(0)
void  init(void);
void clean(void);

int main(void){
    int j; int k;
    int t=0; // timer
    int f=0; // 치즈 플래그
    int a;   // 인접 빈칸 개수
    scanf("%d %d",&n,&m); init();
    for(j=0;j<n;j++){for(k=0;k<m;k++){scanf("%d",&grid[j][k]);}}
    while(1){
        f=0;
        reset();
        bfs();
        for(j=0;j<n;j++){
        for(k=0;k<m;k++){
            if(grid[j][k]==NO){continue;}
            f=1;
            a=0;
            a+=(vist[j-1][k]==MK)?1:0;
            a+=(vist[j+1][k]==MK)?1:0;
            a+=(vist[j][k-1]==MK)?1:0;
            a+=(vist[j][k+1]==MK)?1:0;
            if(a>=2){grid[j][k]=NO;} // 녹음
        }}
        if(f==0){break;}
        t++;
    }
    printf("%d",t);
    clean();
}

void   bfs(void){
    int j;
    struct node d[4]={{-1,0,},{1,0},{0,-1},{0,1}};
    struct node u;
    struct node v;
    s=0;
    e=0;
    q[e].r=0;
    q[e].c=0; e++;
    vist[0][0]=MK;
    while(s<e){
        u.r=q[s].r;
        u.c=q[s].c; s++;
        for(j=0;j<4;j++){
            v.r=u.r+d[j].r;
            v.c=u.c+d[j].c;
            if((0<=v.r)&&(v.r<n)&&(0<=v.c)&&(v.c<m)){
            if((grid[v.r][v.c]==NO)&&(vist[v.r][v.c]==NO)){
                vist[v.r][v.c]=MK;
                q[e].r=v.r;
                q[e].c=v.c; e++;
            }}
        }
    }
}
void reset(void){
    int j;
    int k;
    for(j=0;j<n;j++){for(k=0;k<m;k++){vist[j][k]=grid[j][k];}}
}
void  init(void){
    int j; int k=0;
    q=(struct node*)malloc(sizeof(struct node)*n*m);
    grid=(int**)malloc(sizeof(int*)*n);
    vist=(int**)malloc(sizeof(int*)*n);
    _grid=(int*)malloc(sizeof(int) *n*m);
    _vist=(int*)malloc(sizeof(int) *n*m);
    for(j=0;j<n;j++){
        grid[j]=_grid+k;
        vist[j]=_vist+k;
        k+=m;
    }
}
void clean(void){
    free(q);
    free(_grid);
    free(_vist);
    free(grid);
    free(vist);
}