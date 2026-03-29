// S1 14940: 쉬운 최단거리(격자그래프,BFS)
#include<stdio.h>
#include<stdlib.h>

#define NO -1

struct node{
    int r;
    int c;
};

int r; // 목표 지점
int c; // 목표 지점
int n;
int m;
int** grid;
int* _grid;
struct node* q;
int s;
int e;

void  init(void);
void clean(void);
void   bfs(void);

int main(void){
    int j; int k;
    scanf("%d %d",&n,&m); init();
    for(j=0;j<n;j++){for(k=0;k<m;k++){scanf("%d",&grid[j][k]); grid[j][k]-=2; if(grid[j][k]==0){r=j;c=k;}}} bfs();
    for(j=0;j<n;j++){for(k=0;k<m;k++){printf("%d ",grid[j][k]);}printf("\n");}
    clean();
}

void  init(void){
    int j; int k=0;
    s=0;
    e=0;
    q=(struct node*)malloc(sizeof(struct node)*n*m);
    grid=(int**)malloc(sizeof(int*)*n);
    _grid=(int*)malloc(sizeof(int) *n*m);
    for(j=0;j<n;j++){grid[j]=_grid+k; k+=m;}
}
void clean(void){
    free(q);
    free(_grid);
    free(grid);
}
void   bfs(void){
    int j; int k;
    struct node d[4]={{-1,0},{1,0},{0,-1},{0,1}};
    struct node u;
    struct node v;
    q[e].r=r;
    q[e].c=c; e++;
    grid[r][c]=0;
    while(s<e){
        u.r=q[s].r;
        u.c=q[s].c; s++;
        for(j=0;j<4;j++){
            v.r=u.r+d[j].r;
            v.c=u.c+d[j].c;
            if((0<=v.r)&&(v.r<n)&&(0<=v.c)&&(v.c<m)){
            if(grid[v.r][v.c]==NO){
                grid[v.r][v.c]=grid[u.r][u.c]+1;
                q[e].r=v.r;
                q[e].c=v.c; e++;
            }}
        }
    }
    for(j=0;j<n;j++){for(k=0;k<m;k++){if(grid[j][k]==-2){grid[j][k]=0;}}}
}