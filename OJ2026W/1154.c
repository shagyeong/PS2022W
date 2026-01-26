// P5 1154: 팀 편성(이분그래프)
#include<stdio.h>
#include<stdlib.h>

#define N 1001
#define NOT 0 // NOT
#define RED 1 // node group 1
#define BLU 2 // node group 2

struct node{
    int v;
    struct node* next;
};
struct graph{
    int n;
    struct node* adjs[N];
    int          vist[N];
    int f; // flag: 이분그래프
};

void    bfs(struct graph* g,int s);
void   init(struct graph* g,int n);
void insert(struct graph* g,int u,int v);

int main(void){
    int j; int k;
    int n; scanf("%d",&n);
    int u; int v;
    struct graph g; init(&g,n+1);
    int adjs[n+1][n+1];
    for(j=1;j<=n;j++){for(k=1;k<=n;k++){adjs[j][k]=0;}}
    for(j=1;j<=n;j++){adjs[j][j]=1;}

    while(1){
        scanf("%d %d",&u,&v);
        if((u==-1)&&(v==-1)){break;}
        else{adjs[u][v]=1; adjs[v][u]=1;}
    }
    for(j=1;j<=n;j++){for(k=1;k<=n;k++){if(adjs[j][k]==0){insert(&g,j,k);}}}

    for(j=1;j<=n;j++){if(g.vist[j]==NOT){bfs(&g,j);}}
    if(g.f==0){printf("-1");}
    else{
        printf("1\n");
        if(g.vist[1]==RED){ // 문제 조건: 1번 학생이 포함된 팀을 먼저 출력
            for(j=1;j<=n;j++){if(g.vist[j]==RED){printf("%d ",j);}}printf("-1\n");
            for(j=1;j<=n;j++){if(g.vist[j]==BLU){printf("%d ",j);}}printf("-1\n");
        }
        else{
            for(j=1;j<=n;j++){if(g.vist[j]==BLU){printf("%d ",j);}}printf("-1\n");
            for(j=1;j<=n;j++){if(g.vist[j]==RED){printf("%d ",j);}}printf("-1\n");
        }
    }
}

void    bfs(struct graph* g,int s){
    struct node* b; // current node: struct node
    int d;          // current node: number of node
    int* q=(int*)malloc(sizeof(int)*g->n);
    int f=0; // front of queue
    int r=0; // rear  of queue
    
    // enqueue
    g->vist[s]=RED;
    q[r++]=s;

    while(f<r){
        d=q[f++]; // dequeue
        b=g->adjs[d];
        while((b=b->next)!=NULL){
            if(g->vist[b->v]==NOT){
                g->vist[b->v]=(g->vist[d]==RED)?BLU:RED; // 인접 노드: 반대 색 마크
                q[r++]=b->v; // enqueue
            }
            else if(g->vist[b->v]==g->vist[d]){
                g->f=0; // 이분그래프 아님
                free(q);
                return;
            }
        }
    }
    free(q);
}
void   init(struct graph* g,int n){
    int j;
    g->n=n;
    g->f=1; // 이분그래프 마크
    for(j=0;j<n;j++){
        g->vist[j]=NOT;
        g->adjs[j]=(struct node*)malloc(sizeof(struct node));
        g->adjs[j]->v=j;
        g->adjs[j]->next=NULL;
    }
}
void insert(struct graph* g,int u,int v){
    struct node* n=(struct node*)malloc(sizeof(struct node)); // new
    n->v=v;
    n->next=g->adjs[u]->next;
    g->adjs[u]->next=n;
}