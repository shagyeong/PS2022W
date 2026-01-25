// P4 16978: 수열과 쿼리 22(세그먼트트리,오프라인쿼리)
#include<stdio.h>
#include<stdlib.h>

struct unode{ // update request
    int       i;
    long long v;
};
struct qnode{ // query
    int i; // 원본 순서
    int k; // 적용된 쿼리 개수(정렬 기준)
    int l;
    int r;
    long long int q; // 쿼리 결과
};

long long int* A; // 원본 배열
long long int* T; // 구간합 트리
struct unode* U; // 업데이트 배열
struct qnode* Q; // 쿼리 배열

void           init(int n,int s,int e);
void         update(int n,int s,int e,int i,long long int v);
long long int query(int n,int s,int e,int l,int r);
int compare_i(const void* x,const void* y); // qsort: 쿼리 순서 오름차순
int compare_k(const void* x,const void* y); // qsort: 쿼리 개수 오름차순

int main(void){
    int j; int p; // loop variable
    int n; int m;
    int o; // operation type
    int u=0; // length of update array
    int q=0; // length of query array

    // 세그먼트 트리 초기화
    scanf("%d",&n);
    A=(long long int*)malloc(sizeof(long long int)*(n+1));
    T=(long long int*)malloc(sizeof(long long int)*(4*(n+1)));
    for(j=0;j<n;j++){scanf("%lld",&A[j]);}
    init(1,0,n-1);

    // 쿼리 배열 초기화
    scanf("%d",&m);
    U=(struct unode*)malloc(sizeof(struct unode)*m);
    Q=(struct qnode*)malloc(sizeof(struct qnode)*m);
    for(j=0;j<m;j++){
        scanf("%d",&o);
        if(o==1){scanf("%d %lld", &U[u].i,&U[u].v);                   u++;}
        else    {scanf("%d %d %d",&Q[q].k,&Q[q].l,&Q[q].r); Q[q].i=q; q++;}
    }
    qsort(&Q[0],q,sizeof(struct qnode),compare_k);

    // 쿼리 수행
    p=0;
    for(j=0;j<q;j++){
        while(p<Q[j].k){update(1,0,n-1,U[p].i-1,U[p].v); A[U[p].i-1]=U[p].v; p++;}
        Q[j].q=query(1,0,n-1,Q[j].l-1,Q[j].r-1);
    }

    // 쿼리 결과 출력
    qsort(&Q[0],q,sizeof(struct qnode),compare_i); // 쿼리 순서 복원
    for(j=0;j<q;j++){printf("%lld\n",Q[j].q);}
}

void init(int n,int s,int e){
    int m; // middle
    if(s==e){T[n]=A[s]; return;}
    m=(s+e)/2;
    init(2*n,  s,  m);      // lchild
    init(2*n+1,m+1,e);      // rchild
    T[n]=T[n*2]+T[n*2+1]; // 구간합
}
void update(int n,int s,int e,int i,long long v){
    int m; // middle
    if((i<s)||(i>e)){return;}
    if(s==e){T[n]=v; return;}
    m=(s+e)/2;
    update(2*n,  s,  m,i,v); // lchild
    update(2*n+1,m+1,e,i,v); // rchild
    T[n]=T[n*2]+T[n*2+1];    // 구간합
}
long long query(int n,int s,int e,int l,int r){
    int m; // middle
    if((l>e)||(r<s))    {return 0;}
    if(((l<=s)&&(e<=r))){return T[n];}
    m=(s+e)/2;
    return query(2*n,s,m,l,r)+query(2*n+1,m+1,e,l,r);
}
int compare_i(const void* x,const void* y){
    if((((struct qnode*)x)->i)<(((struct qnode*)y)->i)){return -1;}
    if((((struct qnode*)x)->i)>(((struct qnode*)y)->i)){return  1;}
    return 0;
}
int compare_k(const void* x,const void* y){
    if((((struct qnode*)x)->k)<(((struct qnode*)y)->k)){return -1;}
    if((((struct qnode*)x)->k)>(((struct qnode*)y)->k)){return  1;}
    return 0;
}