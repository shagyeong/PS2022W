// S1 2667: 단지번호붙이기(격자그래프,BFS)
#include<stdio.h>
#include<stdlib.h>

#define NOT 0 // 집이 아님
#define YES 1 // 집
#define OKI 2 // 단지 마크

struct node{
    int r;
    int c;
};
struct graph{
    int n;
    int m;
    int  i; // 단지 개수
    int* a; // 단지 내 집 개수
    int** grid;
    int** dist;
    int*  data;
    int*  zero;
};

int asc(const void* u,const void* v){return *((int*)u)-*((int*)v);}
void   bfs(struct graph* g,int r,int c);
void  init(struct graph* g,int n,int m);
void clean(struct graph* g);

int main(void){
    int j; int k;
    int n; scanf("%d",&n);
    int m=n; // 문제 조건: nxn 격자
    struct graph g;

    init(&g,n,m);
    for(j=0;j<n*m;j++){g.a[j]=n*m+1;} // qsort() 오염 방지
    for(j=0;j<n;j++){for(k=0;k<m;k++){
        scanf("%1d",&g.grid[j][k]);
        g.dist[j][k]=0;
    }}


    for(j=0;j<n;j++){for(k=0;k<m;k++){
        if(g.grid[j][k]==YES){
            bfs(&g,j,k);
        }
    }}
    qsort(g.a,g.i,sizeof(int),asc);
    printf("%d\n",g.i);
    for(j=0;j<g.i;j++){printf("%d\n",g.a[j]);}
    clean(&g);
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
    g->grid[r][c]=OKI; g->a[g->i]=1;
    while(s<e){
        u.r=q[s].r;
        u.c=q[s].c; s++;
        for(j=0;j<4;j++){
            v.r=u.r+d[j].r;
            v.c=u.c+d[j].c;
            if(((0<=v.r)&&(v.r<g->n))&&((0<=v.c)&&(v.c<g->m))){
            if((g->grid[v.r][v.c]==1)&&(g->dist[v.r][v.c]==0)){
                g->grid[v.r][v.c]=OKI; g->a[g->i]++;
                g->dist[v.r][v.c]=g->dist[u.r][u.c]+1;
                q[e].r=v.r;
                q[e].c=v.c; e++;
            }}
        }
    }
    g->i++;
}
void  init(struct graph* g,int n,int m){
    int j; int k=0;
    g->n=n;
    g->m=m;
    g->i=0;
    g->a=(int*)malloc(sizeof(int)*n*m);
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