// G4 14502: 연구소(격자그래프,BFS,브루트포스)
#include<stdio.h>
#include<stdlib.h>

struct node{
    int r;
    int c;
};

int n; int m;
int h; int e;
struct node* q;
int** grid;
int* _grid;
int** vist;
int* _vist;

void   bfs(struct node u);
void  init(void);
void reset(void);
void clean(void);

int main(void){
    int j; int k;
    int u; int v; int w;
    int s; // 단계별 누적값
    int a=0; // 최대값
    struct node d;
    scanf("%d %d",&n,&m);
    init(); for(j=0;j<n;j++){for(k=0;k<m;k++){scanf("%d",&grid[j][k]);}}

    for(u=0;  u<n*m-2;u++){
    for(v=u+1;v<n*m-1;v++){
    for(w=v+1;w<n*m;  w++){
    if((grid[u/m][u%m]==0)&&(grid[v/m][v%m]==0)&&(grid[w/m][w%m]==0)){
        s=0;
        reset();
        vist[u/m][u%m]=1;
        vist[v/m][v%m]=1;
        vist[w/m][w%m]=1;
        for(j=0;j<n;j++){for(k=0;k<m;k++){if(vist[j][k]==2){d.r=j;d.c=k;bfs(d);}}}
        for(j=0;j<n;j++){for(k=0;k<m;k++){if(vist[j][k]==0){s+=1;}}}
        if(a<s){a=s;}
    }}}}
    printf("%d",a);
}

void   bfs(struct node u){
    int j;
    struct node c; // current
    struct node d; // next
    struct node a[4]={{-1,0},{1,0},{0,-1},{0,1}};
    h=0;
    e=0;
    q[e  ].r=u.r;
    q[e++].c=u.c;
    vist[u.r][u.c]=2;
    while(h<e){
        c.r=q[h  ].r;
        c.c=q[h++].c;
        for(j=0;j<4;j++){
            d.r=c.r+a[j].r;
            d.c=c.c+a[j].c;
            if(((0<=d.r)&&(d.r<n))&&((0<=d.c)&&(d.c<m))){
            if(vist[d.r][d.c]==0){
                vist[d.r][d.c]=2;
                q[e  ].r=d.r;
                q[e++].c=d.c;
            }}
        }
    }
}
void  init(void){
    int j; int k=0;
    q=(struct node*)malloc(sizeof(struct node)*n*m);
    grid=(int**)malloc(sizeof(int*)*n);
    _grid=(int*)malloc(sizeof(int) *n*m);
    vist=(int**)malloc(sizeof(int*)*n);
    _vist=(int*)malloc(sizeof(int) *n*m);
    for(j=0;j<n;j++){
        grid[j]=_grid+k;
        vist[j]=_vist+k; k+=m;
    }
}
void reset(void){
    int j; int k;
    for(j=0;j<n;j++){for(k=0;k<m;k++){vist[j][k]=grid[j][k];}}
}
void clean(void){
    free(q);
    free(_grid); free(grid);
    free(_vist); free(vist);
}