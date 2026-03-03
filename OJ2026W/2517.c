// P4 2517: 달리기(세그먼트트리,정렬,좌표압축)
#include<stdio.h>
#include<stdlib.h>

int* a; // 원본 배열
int* t; // 구간합 트리

// void   init(int n,int s,int e);
void update(int n,int s,int e,int i,int v);
int   query(int n,int s,int e,int l,int r);

struct node{
    int i; // 입력 순서
    int p; // 입력값
    int c; // 압축된 좌표
};

int asc_i(const void* u,const void* v){return ((struct node*)u)->i-((struct node*)v)->i;}
int asc_p(const void* u,const void* v){return ((struct node*)u)->p-((struct node*)v)->p;}

int main(void){
    int j;
    int n; scanf("%d",&n);
    struct node* nodes=(struct node*)malloc(sizeof(struct node)*n);
    a=(int*)calloc(n,  sizeof(int));
    t=(int*)calloc(4*n,sizeof(int));
    // init(1,0,n-1);

    // 좌표 압축
    for(j=0;j<n;j++){nodes[j].i=j;scanf("%d",&nodes[j].p);}
    qsort(nodes,n,sizeof(struct node),asc_p);
    for(j=0;j<n;j++){nodes[j].c=j;}
    qsort(nodes,n,sizeof(struct node),asc_i);

    // 구간합 쿼리
    for(j=0;j<n;j++){
        update(1,0,n-1,nodes[j].c,1);
        printf("%d\n",j+2-query(1,0,n-1,0,nodes[j].c)); // (j+1)-(query()-1) (0-based->1-based)
    }
}

void update(int n,int s,int e,int i,int v){
    if((i<s)||(e<i)){return;}
    if(s==e){t[n]=v; return;}
    int m=(s+e)/2;
    update(2*n,  s,  m,i,v);
    update(2*n+1,m+1,e,i,v);
    t[n]=t[2*n]+t[2*n+1];
}
int   query(int n,int s,int e,int l,int r){
    if((r<s)||(e<l))  {return 0;}
    if((l<=s)&&(e<=r)){return t[n];}
    int m=(s+e)/2;
    return query(2*n,s,m,l,r)+query(2*n+1,m+1,e,l,r);
}