// P5 1572: 중앙값(이분탐색,세그먼트트리)
#include<stdio.h>
#include<stdlib.h>

#define N 65537 // 0 등장 - 보정: 0,1,...,65536 -> 1,2,...,65537

int* t;
// int n; // N
int k;

void   init(void);
void  clean(void);
// void  build(void); // 순서 쿼리 문제: 빈 트리에서 시작
void update(int i,int d);
int   query(int n,int s,int e,int b);

int main(void){
    int j;
    long long int s=0; // answer
    int n; int m; scanf("%d %d",&n,&m); init();
    int* d=(int*)malloc(sizeof(int)*n);
    for(j=0;j<n;j++){scanf("%d",&d[j]); d[j]+=1;} // d[j]+=1: 보정
    for(j=0;j<m-1;j++){
        update(d[j],1);
    }
    for(j=m-1;j<n;j++){
        update(d[j],1);
        s+=query(1,1,k,(m+1)/2);
        s-=1;
        update(d[j-m+1],-1);
    }
    printf("%lld",s);
    clean();
}

void   init(void){
    k=1; while(k<N){k*=2;}
    t=(int*)calloc(k*2,sizeof(int));
}
void  clean(void){
    free(t);
}
void update(int i,int d){
    i=k+(i-1);
    t[i]+=d;
    while(i>1){
        i/=2;
        t[i]=t[2*i]+t[2*i+1];
    }
}
int   query(int n,int s,int e,int b){
    if(s==e){return s;}
    int m=(s+e)/2;
    if(t[2*n]>=b){return query(2*n,  s,  m,b);}
    else         {return query(2*n+1,m+1,e,b-t[2*n]);}
}