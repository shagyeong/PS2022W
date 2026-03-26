// G1 10868: 최소값(희소배열)
// RMQ 재채점
#include<stdio.h>
#include<stdlib.h>

#define L 18 // log2 N

int n;
int q;
int** pare; // [N][L]
int* _pare;

void sparse(void);
int   query(int l,int r);
void   init(void);
void  clean(void);

int main(void){
    int j;
    int l; int r;
    scanf("%d %d",&n,&q); init();
    for(j=1;j<=n;j++){scanf("%d",&pare[j][0]);} sparse();
    for(j=0;j< q;j++){scanf("%d %d",&l,&r); printf("%d\n",query(l,r));}
    clean();
}

void sparse(void){
    int j; int k;
    for(j=1;j< L;j++){
    for(k=1;k<=n;k++){
        if((k+(1<<(j-1)))>n){continue;}
        if(pare[k][j-1]<pare[k+(1<<(j-1))][j-1]){pare[k][j]=pare[k][j-1];}
        else                                    {pare[k][j]=pare[k+(1<<(j-1))][j-1];}
    }}
}
int   query(int l,int r){
    int e=0; // 구간 길이보다 짧거나 같은 2의 거듭제곱
    while((1<<(e+1))<=(r-l+1)){e++;}
    if(pare[l][e]<pare[r-(1<<e)+1][e]){return pare[l         ][e];}
    else                              {return pare[r-(1<<e)+1][e];}
}
void   init(void){
    int j; int k=0;
    pare=(int**)malloc(sizeof(int*)*(n+1));
    _pare=(int*)malloc(sizeof(int) *(n+1)*L);
    for(j=0;j<=n;j++){pare[j]=_pare+k; k+=L;}
}
void  clean(void){
    free(_pare);
    free(pare);
}