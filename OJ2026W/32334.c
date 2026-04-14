// S1 32334: 자석 체스(브루트포스,누적합)
#include<stdio.h>
#include<stdlib.h>

int** grid;
int** hsum; // horizontal sum: 가로방향 누적합
int** vsum; // vertical sum: 세로방향 누적합
int* _grid;
int* _hsum;
int* _vsum;

int n; // size of row
int m; // size of col
int d; // distance

void  init(void);
void clean(void);

int main(void){
    int j; int k;
    int r; // answer: row, column
    int c; // answer: row, column
    int g; // number of magnets
    int h; // min of g
    int u; int v; // range of row
    int w; int x; // range of col
    scanf("%d %d",&n,&d);
    m=n;
    h=(2*d+1)*(2*d+1);
    init();

    for(j=1;j<=n;j++){for(k=1;k<=m;k++){scanf("%d",&grid[j][k]);}}
    for(j=1;j<=n;j++){for(k=1;k<=m;k++){hsum[j][k]=hsum[j][k-1]+grid[j][k];}}
    for(k=1;k<=n;k++){for(j=1;j<=n;j++){vsum[j][k]=vsum[j-1][k]+hsum[j][k];}}
    
    for(j=1;j<=n;j++){for(k=1;k<=m;k++){
        if(grid[j][k]==1){continue;}

        // (u,w)~(v,x)
        u=j-d; if(u<1){u=1;}
        w=k-d; if(w<1){w=1;}
        v=j+d; if(v>n){v=n;}
        x=k+d; if(x>m){x=m;}
        
        g=0;
        g+=vsum[v][x];
        g-=vsum[u-1][x];
        g-=vsum[v][w-1];
        g+=vsum[u-1][w-1];
        
        if     (g==0){h=0; r=j; c=k; goto  escape;} // 조기탈출: 행-열 번호 순 tie break
        else if(g< h){h=g; r=j; c=k;} // 등호 방향: 같을 때(늦게 등장했을 때) 갱신 없음(행-열 번호 순 tie break)
    }}
    escape:
    if(h==0){printf("%d %d",r,c);}
    else    {printf("%d %d\n%d",r,c,h);}
    clean();
}

void  init(void){
    int j;
    int k=0;
    grid=(int**)calloc((n+1),sizeof(int*));
    hsum=(int**)calloc((n+1),sizeof(int*));
    vsum=(int**)calloc((n+1),sizeof(int*));
    _grid=(int*)calloc((n+1)*(m+1),sizeof(int));
    _hsum=(int*)calloc((n+1)*(m+1),sizeof(int));
    _vsum=(int*)calloc((n+1)*(m+1),sizeof(int));
    for(j=0;j<=n;j++){
        grid[j]=_grid+k;
        hsum[j]=_hsum+k;
        vsum[j]=_vsum+k;
        k+=(m+1);
    }
}
void clean(void){
    free(_grid);
    free(_hsum);
    free(_vsum);
    free(grid);
    free(hsum);
    free(vsum);
}