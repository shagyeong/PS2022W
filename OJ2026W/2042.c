// G1 2042: 구간 합 구하기(세그먼트트리)
// 비재귀 재채점
#include<stdio.h>
#include<stdlib.h>

long long int* a;
long long int* t;
int n;
int k;

void           init(void);
void          clean(void);
void          build(void);
void         update(int i,long long int v);
long long int query(int l,int r);

int main(void){
    int j;
    int q;
    int o; int u; long long int v;
    scanf("%d",&n); init();
    scanf("%d %d",&q,&o); q+=o;
    for(j=1;j<=n;j++){scanf("%lld",&a[j]);} build();
    for(j=0;j< q;j++){
        scanf("%d %d %lld",&o,&u,&v);
        if(o==1){update(u,v);}
        else    {printf("%lld\n",query(u,(int)v));}
    }
    clean();
}

void           init(void){
    k=1; while(k<n){k*=2;}
    a=(long long int*)malloc(sizeof(long long int)*(n+1));
    t=(long long int*)malloc(sizeof(long long int)*(k*2));
}
void          clean(void){
    free(a);
    free(t);
}
void          build(void){
    int j;
    for(j=1;  j<=n;j++){t[k+(j-1)]=a[j];}
    for(j=n+1;j<=k;j++){t[k+(j-1)]=0;}
    for(j=k-1;j> 0;j--){t[j]=t[2*j]+t[2*j+1];}
}
void         update(int i,long long int v){
    i=k+(i-1);
    t[i]=v;
    while(i>1){
        i/=2;
        t[i]=t[2*i]+t[2*i+1];
    }
}
long long int query(int l,int r){
    long long int s=0;
    l+=(k-1);
    r+=(k-1);
    while(l<=r){
        if(l%2==1){s+=t[l++];}
        if(r%2==0){s+=t[r--];}
        l/=2;
        r/=2;
    }
    return s;
}