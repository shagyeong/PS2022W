// P3 1395: 스위치(느리게 갱신되는 세그먼트 트리)
#include<stdio.h>
#include<string.h> // memset
int a[100001]; // 원본 배열
int t[400004]; // 구간합 트리
int p[400004]; // lazy propagtion

void   init(int n);
void   lazy(int n,int s,int e);
void update(int n,int s,int e,int l,int r); // toggle
int   query(int n,int s,int e,int l,int r);

int main(void){
    int j; // loop variable
    int n; int m;
    int o; int u; int v;

    scanf("%d %d",&n,&m);
    init(n);

    for(j=0;j<m;j++){
        scanf("%d %d %d",&o,&u,&v);
        if(o==0){update(1,0,n-1,u-1,v-1);}
        else    {printf("%d\n",query(1,0,n-1,u-1,v-1));}
    }
}

// 문제 조건: 초기에 모든 스위치가 꺼져있음
void init(int n){
    memset(&a[0],0,sizeof(int)*(n+1));
    memset(&t[0],0,sizeof(int)*(n+1)*4);
    memset(&p[0],0,sizeof(int)*(n+1)*4);
}
void lazy(int n,int s,int e){
    if((p[n]%2)!=0){
        t[n]=(e-s+1)-t[n];
        if(s!=e){
            p[2*n]  +=p[n];
            p[2*n+1]+=p[n];
        }
        p[n]=0;
    }
}
void update(int n,int s,int e,int l,int r){
    int m; // middle
    lazy(n,s,e);
    if((l>e)||(r<s)){return;}
    if((l<=s)&&(e<=r)){
        p[n]+=1;
        lazy(n,s,e);
        return;
    }
    m=(s+e)/2;
    update(2*n,  s,  m,l,r);
    update(2*n+1,m+1,e,l,r);
    t[n]=t[2*n]+t[2*n+1];
}
int query(int n,int s,int e,int l,int r){
    int m; // middle
    lazy(n,s,e);
    if((l>e)||(r<s))  {return 0;}
    if((l<=s)&&(e<=r)){return t[n];}
    m=(s+e)/2;
    return query(2*n,s,m,l,r)+query(2*n+1,m+1,e,l,r);
}