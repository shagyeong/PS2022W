// P3 1533: 길의 개수(그래프,분할정복거듭제곱)
// weight graph 인접행렬 거듭제곱
#include<stdio.h>
#define Q 1000003

struct matrix{
    unsigned long long int m[50][50];
};

struct matrix multiply(struct matrix A,struct matrix B,unsigned char n);
struct matrix power(struct matrix m,unsigned char n,long long int e);

int main(void){
    unsigned char j; // loop variable
    unsigned char k; // loop variable
    unsigned char n; // matrix size: n x n
    unsigned char w; // weight
    int e;           // exponential
    struct matrix m;
    struct matrix a; // answer
    unsigned char s; // start
    unsigned char d; // destination

    scanf("%hhd %hhd %hhd %d",&n,&s,&d,&e);

    s-=1; // 1부터 시작하는 과제 환경
    d-=1; // 1부터 시작하는 과제 환경

    for(j=0;j<50;j++){for(k=0;k<50;k++){m.m[j][k]=0;}}
    for(j=0;j<n;j++){for(k=1;k<5;k++){m.m[5*j+k][5*j+k-1]=1;}}
    for(j=0;j<n;j++){
        for(k=0;k<n;k++){
            scanf("%1hhd",&w);
            if(w>0){m.m[5*j][5*k+w-1]=1;}
        }
    }

    s*=5; d*=5; n*=5;
    a=power(m,n,e);
    printf("%llu",a.m[s][d]);
}
struct matrix multiply(struct matrix A,struct matrix B,unsigned char n){
    unsigned char j; // loop variable
    unsigned char k; // loop variable
    unsigned char l; // loop variable
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
struct matrix power(struct matrix m,unsigned char n,long long int e){
    if(e==1){
        unsigned char j;
        unsigned char k;
        for(j=0;j<n;j++){for(k=0;k<n;k++){m.m[j][k]%=Q;}}
        return m;
    }
    if(e%2==0){
        unsigned char j;
        unsigned char k;
        struct matrix t=power(m,n,e/2);
        t=multiply(t,t,n);
        for(j=0;j<n;j++){for(k=0;k<n;k++){t.m[j][k]%=Q;}}
        return t;
    }
    else{
        unsigned char j;
        unsigned char k;
        struct matrix t=power(m,n,(e-1)/2);
        t=multiply(t,t,n);
        for(j=0;j<n;j++){for(k=0;k<n;k++){t.m[j][k]%=Q;}}
        t=multiply(t,m,n);
        for(j=0;j<n;j++){for(k=0;k<n;k++){t.m[j][k]%=Q;}}
        return t;
    }
}