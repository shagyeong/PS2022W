// P2 13547: 수열과 쿼리 5(오프라인쿼리,mo's)
#include<stdio.h>
#include<stdlib.h>

struct query{
    int i; // 순서 원본
    int l;
    int r;
};

int B;
int A[1000001]; // 원본 배열
int C[1000001]; // count
int R[1000001]; // result
int I = 0;
struct query Q[100001];

int compare(const void* a, const void* b);

int main(void){
    int j;
    int n;   int m;
    int l=1; int r=0;
    int s;   int e;

    scanf("%d",&n);
    B=1; while(B*B<=n){B++;} B--; // sqrt(n)
    for(j=1;j<=n;j++){scanf("%d",&A[j]);}

    scanf("%d",&m);
    for(j=0;j<m;j++){Q[j].i=j;scanf("%d %d",&Q[j].l,&Q[j].r);}
    qsort(&Q[0],m,sizeof(struct query),compare);
    
    for(j=0;j<m;j++){
        s=Q[j].l;
        e=Q[j].r;
        while(l>s){if((  C[A[--l]]++)==0){I++;}}
        while(r<e){if((  C[A[++r]]++)==0){I++;}}
        while(l<s){if((--C[A[l++]]  )==0){I--;}}
        while(r>e){if((--C[A[r--]]  )==0){I--;}}
        R[Q[j].i]=I;
    }
    
    for(j=0;j<m;j++){printf("%d\n",R[j]);}
}

int compare(const void* a,const void* b){
    if((((struct query*)a)->l/B)!=(((struct query*)b)->l/B)){
    return (((struct query*)a)->l/B)-(((struct query*)b)->l/B);}
    if((((struct query*)a)->l/B)%2==0){
    return (((struct query*)a)->r)-  (((struct query*)b)->r);}
    return (((struct query*)b)->r)-  (((struct query*)a)->r);
}