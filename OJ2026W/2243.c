// P5 2243: 사탕상자(이분탐색,세그먼트트리)
#include<stdio.h>
#include<stdlib.h>

#define N 1000000

int* a;
int* t;

void   init(void);
void  clean(void);
// void  build(int n,int s,int e); // 문제 조건: 빈 상자에서 시작
void update(int n,int s,int e,int i,int v);
int   query(int n,int s,int e,int b);

int main(void){
    int j;
    int q; scanf("%d",&q);
    int o; int b; int c;
    init();
    for(j=0;j<q;j++){
        scanf("%d",&o);
        if(o==1){scanf("%d",&b); printf("%d\n",query(1,1,N,b));}
        if(o==2){scanf("%d %d",&b,&c); update(1,1,N,b,a[b]+c); a[b]+=c;}
    }
    clean();
}

void   init(void){
    a=(int*)calloc(N+1,    sizeof(int));
    t=(int*)calloc((N+1)*4,sizeof(int));
}
void  clean(void){
    free(a);
    free(t);
}
void update(int n,int s,int e,int i,int v){
    if((i<s)||(e<i)){return;}
    if(s==e){t[n]=v; return;}
    int m=(s+e)/2;
    update(2*n,  s,  m,i,v);
    update(2*n+1,m+1,e,i,v);
    t[n]=t[2*n]+t[2*n+1];
}
int   query(int n,int s,int e,int b){
    if(s==e){
        t[n]-=1;
        a[s]-=1;
        return s;
    }
    int m=(s+e)/2;
    int r;
    if(t[2*n]>=b){r=query(2*n,  s,  m,b);}
    else         {r=query(2*n+1,m+1,e,b-t[2*n]);}
    t[n]=t[2*n]+t[2*n+1];
    return r;
}