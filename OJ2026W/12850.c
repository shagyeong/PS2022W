// P5 12850: 본대 산책 2(그래프,분할 정복 거듭제곱)
#include<stdio.h>
#define Q 1000000007

struct matrix{
    unsigned long long int m[8][8];
};

struct matrix multiply(struct matrix A,struct matrix B,unsigned char n);
struct matrix power(struct matrix m,unsigned char n,long long int e);

int main(void){
    unsigned char j; // loop variable
    unsigned char k; // loop variable
    unsigned char n; // matrix size: n x n
    long long int e; // exponential
    struct matrix m;
    struct matrix a; // answer

    n=8;
    scanf("%lld",&e);
    for(j=0;j<n;j++){for(k=0;k<n;k++){m.m[j][k]=0;}}
    m.m[0][1]=1;    m.m[1][0]=1;
    m.m[0][7]=1;    m.m[7][0]=1;
    m.m[1][7]=1;    m.m[7][1]=1;
    m.m[1][2]=1;    m.m[2][1]=1;
    m.m[2][7]=1;    m.m[7][2]=1;
    m.m[2][3]=1;    m.m[3][2]=1;
    m.m[2][6]=1;    m.m[6][2]=1;
    m.m[3][6]=1;    m.m[6][3]=1;
    m.m[3][4]=1;    m.m[4][3]=1;
    m.m[4][5]=1;    m.m[5][4]=1;
    m.m[5][6]=1;    m.m[6][5]=1;
    m.m[6][7]=1;    m.m[7][6]=1;

    a=power(m,n,e);
    printf("%llu",a.m[0][0]);
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