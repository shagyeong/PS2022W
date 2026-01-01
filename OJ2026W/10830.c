// G4 10830: 행렬 제곱(DP, 분할 정복 거듭제곱)
#include<stdio.h>
#define Q 1000

struct matrix{
    unsigned int m[5][5];
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
    scanf("%hhu %lld",&n,&e);
    for(j=0;j<n;j++){for(k=0;k<n;k++){scanf("%d",&(m.m[j][k]));}}
    a=power(m,n,e);
    for(j=0;j<n;j++){for(k=0;k<n;k++){printf("%d ",a.m[j][k]);}printf("\n");}
}

struct matrix multiply(struct matrix A,struct matrix B,unsigned char n){
    unsigned char j; // loop variable
    unsigned char k; // loop variable
    unsigned char l; // loop variable
    struct matrix C;
    for(j=0;j<n;j++){
        for(k=0;k<n;k++){
            C.m[j][k]=0;
            for(l=0;l<n;l++){C.m[j][k]+=A.m[j][l]*B.m[l][k];}
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
