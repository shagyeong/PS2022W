// P5 14289: 본대 산책 3(그래프,분할정복거듭제곱)
#include<stdio.h>
#define Q 1000000007

struct matrix{
    unsigned long long int m[50][50];
};

struct matrix multiply(struct matrix A,struct matrix B,int n);
struct matrix power(struct matrix m,int n,long long int e);

int main(void){
    int j; // loop variable
    int n; // matrix size: n x n
    int r; // number of road
    int u; // input dummy
    int v; // input dummy
    long long int e; // exponential
    struct matrix m;
    struct matrix a; // answer

    scanf("%d %d",&n,&r);
    for(j=0;j<r;j++){
        scanf("%d %d",&u,&v);
        m.m[u-1][v-1]=1;
        m.m[v-1][u-1]=1;
    }
    scanf("%lld",&e);
    a=power(m,n,e);
    printf("%llu",a.m[0][0]);
}
struct matrix multiply(struct matrix A,struct matrix B,int n){
    int j; // loop variable
    int k; // loop variable
    int l; // loop variable
    struct matrix C;
    for(j=0;j<n;j++){
        for(k=0;k<n;k++){
            C.m[j][k]=0;
            for(l=0;l<n;l++){
                C.m[j][k]+=(A.m[j][l]*B.m[l][k])%Q;
                C.m[j][k]%=Q;
            }
        }
    }
    return C;
}
struct matrix power(struct matrix m,int n,long long int e){
    if(e==1){
        int j;
        int k;
        for(j=0;j<n;j++){for(k=0;k<n;k++){m.m[j][k]%=Q;}}
        return m;
    }
    if(e%2==0){
        int j;
        int k;
        struct matrix t=power(m,n,e/2);
        t=multiply(t,t,n);
        for(j=0;j<n;j++){for(k=0;k<n;k++){t.m[j][k]%=Q;}}
        return t;
    }
    else{
        int j;
        int k;
        struct matrix t=power(m,n,(e-1)/2);
        t=multiply(t,t,n);
        for(j=0;j<n;j++){for(k=0;k<n;k++){t.m[j][k]%=Q;}}
        t=multiply(t,m,n);
        for(j=0;j<n;j++){for(k=0;k<n;k++){t.m[j][k]%=Q;}}
        return t;
    }
}