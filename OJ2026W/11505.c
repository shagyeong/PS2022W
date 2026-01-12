// G1 11505: 구간 곱 구하기(세그먼트 트리)
#include<stdio.h>

#define Q 1000000007

long long int a[1000001]; // 원본 배열
long long int t[4000004]; // 구간곱 트리

void           init(int n,int s,int e);
void         update(int n,int s,int e,int i,long long int v);
long long int query(int n,int s,int e,int l,int r);

int main(void){
    int j; // loop variable
    int n; int m; int k;
    int o; int b; long long int c;

    scanf("%d %d %d",&n,&m,&k);
    for(j=0;j<n;j++){scanf("%lld",&a[j]);}
    init(1,0,n-1);

    for(j=0;j<m+k;j++){
        scanf("%d %d %lld",&o,&b,&c);
        if(o==1){update(1,0,n-1,b-1,c); a[b-1]=c;}
        else    {printf("%lld\n",query(1,0,n-1,b-1,(int)c-1));}
    }
}

void init(int n,int s,int e){
    int m; // middle
    if(s==e){t[n]=a[s]; return;}
    m=(s+e)/2;
    init(2*n,  s,  m);      // lchild
    init(2*n+1,m+1,e);      // rchild
    t[n]=(t[n*2]*t[n*2+1])%Q;
}
void update(int n,int s,int e,int i,long long v){
    int m; // middle
    if((i<s)||(i>e)){return;}
    if(s==e){t[n]=v; return;}
    m=(s+e)/2;
    update(2*n,  s,  m,i,v); // lchild
    update(2*n+1,m+1,e,i,v); // rchild
    t[n]=(t[n*2]*t[n*2+1])%Q;
}
long long query(int n,int s,int e,int l,int r){
    int m; // middle
    if((l>e)||(r<s))    {return 1;}
    if(((l<=s)&&(e<=r))){return t[n];}
    m=(s+e)/2;
    return (query(2*n,s,m,l,r)*query(2*n+1,m+1,e,l,r))%Q;
}