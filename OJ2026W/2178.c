// S1 2178: 미로 탐색(격자그래프,BFS)
#include<stdio.h>
#include<stdlib.h>

struct node{
    int r;
    int c;
};
struct graph{
    int n;
    int m;
    int** grid;
    int** dist;
    int*  data;
    int*  zero;
};

void   bfs(struct graph* g,int r,int c);
void  init(struct graph* g,int n,int m);
void clean(struct graph* g);

int main(void){
    int j; int k;
    int n; int m; scanf("%d %d",&n,&m);
    struct graph g;

    init(&g,n,m);
    for(j=0;j<n;j++){for(k=0;k<m;k++){
        scanf("%1d",&g.grid[j][k]);
        g.dist[j][k]=0;
    }}

    bfs(&g,0,0);
    printf("%d",g.dist[n-1][m-1]);
}

void   bfs(struct graph* g,int r,int c){
    int j;
    struct node d[4]={{-1,0},{1,0},{0,-1},{0,1}};
    struct node* q=(struct node*)malloc(sizeof(struct node)*g->n*g->m);
    int s=0;
    int e=0;
    struct node u;
    struct node v;

    q[e].r=r;
    q[e].c=c; e++;
    g->dist[r][c]=1;
    while(s<e){
        u.r=q[s].r;
        u.c=q[s].c; s++;
        for(j=0;j<4;j++){
            v.r=u.r+d[j].r;
            v.c=u.c+d[j].c;
            if(((0<=v.r)&&(v.r<g->n))&&((0<=v.c)&&(v.c<g->m))){
            if((g->grid[v.r][v.c]==1)&&(g->dist[v.r][v.c]==0)){
                g->dist[v.r][v.c]=g->dist[u.r][u.c]+1;
                q[e].r=v.r;
                q[e].c=v.c; e++;
            }}
        }
    }
}
void  init(struct graph* g,int n,int m){
    int j; int k=0;
    g->n=n;
    g->m=m;
    g->grid=(int**)malloc(sizeof(int*)*n);
    g->dist=(int**)malloc(sizeof(int*)*n);
    g->data=(int*) malloc(sizeof(int)* n*m);
    g->zero=(int*) malloc(sizeof(int)* n*m);
    for(j=0;j<n;j++){
        g->grid[j]=g->data+k;
        g->dist[j]=g->zero+k;
        k+=m;
    }
}
void clean(struct graph* g){
    free(g->data);
    free(g->zero);
    free(g->grid);
    free(g->dist);
}