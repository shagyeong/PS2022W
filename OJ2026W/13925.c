// D5 13925: 수열과 쿼리 13(느리게갱신되는세그먼트트리)
#include<stdio.h>
#include<stdlib.h>

long long int* A; // 원본 배열
long long int* T; // 구간합 트리
long long int* LPS; // lazy propagtion: sum
long long int* LPM; // lazy propagtion: multiply

#define D 1000000007 // divisor

void               init(int n,int s,int e);
void               lazy(int n,int s,int e);
void         update_add(int n,int s,int e,int l,int r,long long int v);
void         update_mul(int n,int s,int e,int l,int r,long long int v);
void         update_ovr(int n,int s,int e,int l,int r,long long int v); // 덮어쓰기
long long int     query(int n,int s,int e,int l,int r);

int main(void){
    int j; // loop variable
    int n; int m;
    int o; int x; int y; long long int v;

    scanf("%d",&n);
    A  =(long long int*)malloc(sizeof(long long int)*(n+1));
    T  =(long long int*)malloc(sizeof(long long int)*(n+1)*4);
    LPS=(long long int*)malloc(sizeof(long long int)*(n+1)*4);
    LPM=(long long int*)malloc(sizeof(long long int)*(n+1)*4);
    for(j=0;j<n;j++){scanf("%lld",&A[j]);}
    for(j=0;j<(n+1)*4;j++){LPM[j]=1;}
    init(1,0,n-1);

    scanf("%d",&m);
    for(j=0;j<m;j++){
        scanf("%d %d %d",&o,&x,&y);
        if(o==1){scanf("%lld",&v); update_add(1,0,n-1,x-1,y-1,v);}
        if(o==2){scanf("%lld",&v); update_mul(1,0,n-1,x-1,y-1,v);}
        if(o==3){scanf("%lld",&v); update_ovr(1,0,n-1,x-1,y-1,v);}
        if(o==4){printf("%lld\n",query(1,0,n-1,x-1,y-1)%D);}
    }
}

void init(int n,int s,int e){
    int m; // middle
    if(s==e){T[n]=A[s]; return;}
    m=(s+e)/2;
    init(2*n,  s,  m);      // lchild
    init(2*n+1,m+1,e);      // rchild
    T[n]=(T[2*n]+T[2*n+1])%D; // 구간합
}
void lazy(int n, int s, int e) {
    if((LPM[n]==1)&&(LPS[n]==0)){return;}
    T[n]=(T[n]*LPM[n])%D;
    T[n]=(T[n]+(long long int)(e-s+1)*LPS[n])%D;
    if(s!=e){
        LPM[2*n]=  (LPM[2*n]*  LPM[n])%D;
        LPM[2*n+1]=(LPM[2*n+1]*LPM[n])%D;
        LPS[2*n]=  (LPS[2*n]*  LPM[n]+LPS[n])%D;
        LPS[2*n+1]=(LPS[2*n+1]*LPM[n]+LPS[n])%D;
    }
    LPM[n] = 1;
    LPS[n] = 0;
}
void update_add(int n,int s,int e,int l,int r,long long int v){
    int m; // middle
    lazy(n,s,e);
    if((l>e)||(r<s)){return;}
    if((l<=s)&&(e<=r)){
        LPS[n]+=v; LPS[n]+=D; LPS[n]%=D; // LPS[n]+=D: 음수 v 나머지 연산 방지
        lazy(n,s,e);
        return;
    }
    m=(s+e)/2;
    update_add(2*n,  s,  m,l,r,v);
    update_add(2*n+1,m+1,e,l,r,v);
    T[n]=(T[2*n]+T[2*n+1])%D;
}
void update_mul(int n,int s,int e,int l,int r,long long int v){
    int m;
    lazy(n,s,e);
    if((l>e)||(r<s)){return;}
    if((l<=s)&&(e<=r)){
        LPM[n]*=v; LPM[n]%=D;
        LPS[n]*=v; LPS[n]%=D;
        lazy(n,s,e);
        return;
    }
    m=(s+e)/2;
    update_mul(2*n,  s,  m,l,r,v);
    update_mul(2*n+1,m+1,e,l,r,v);
    T[n]=(T[2*n]+T[2*n+1])%D;
}
void update_ovr(int n,int s,int e,int l,int r,long long int v){
    int m;
    lazy(n,s,e);
    if((l>e)||(r<s)){return;}
    if((l<=s)&&(e<=r)){
        LPM[n]=0;
        LPS[n]=v%D;
        lazy(n,s,e);
        return;
    }
    m=(s+e)/2;
    update_ovr(2*n,  s,  m,l,r,v);
    update_ovr(2*n+1,m+1,e,l,r,v);
    T[n]=(T[2*n]+T[2*n+1])%D;
}
long long int query(int n,int s,int e,int l,int r){
    int m; // middle
    lazy(n,s,e);
    if((l>e)||(r<s))  {return 0;}
    if((l<=s)&&(e<=r)){return T[n];}
    m=(s+e)/2;
    return (query(2*n,s,m,l,r)+query(2*n+1,m+1,e,l,r))%D;
}